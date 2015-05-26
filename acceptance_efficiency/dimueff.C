#define dimueff_cxx
#include "dimueff.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLatex.h>
#include <TPad.h>
#include <iostream>
#include <algorithm>
#include <fstream>

#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif

#include "RooAbsPdf.h"
#include "RooAddPdf.h"
#include "RooCBShape.h"
#include "RooChebychev.h"
#include "RooConstVar.h"
#include "RooDataSet.h"
#include "RooFitResult.h"
#include "RooGaussian.h"
#include "RooGenericPdf.h"
#include "RooHist.h"
#include "RooHistPdf.h"
#include "RooDataHist.h"
#include "RooKeysPdf.h"
#include "RooProdPdf.h"
#include "RooMCStudy.h"
#include "RooPolynomial.h"
#include "RooRealVar.h"
#include "RooPlot.h"
#include "RooWorkspace.h"
#include "RooChi2Var.h"
#include "RooMinuit.h"

#define NPT1S 6
#define NRAP1S 6
#define NCENT1S 8

#define NPT2S 3
#define NRAP2S 2
#define NCENT2S 4

#define DRCUT 1e99

using namespace std;
using namespace RooFit;

const double ptbins_1S[NPT1S+1] = {0,2.5,5,8,12,20,40};
const double rapbins_1S[NRAP1S+1] = {0,0.4,0.8,1.2,1.6,2,2.4};
const int centbins_1S[NCENT1S+1] = {0,5./2.5,10./2.5,20./2.5,30./2.5,40./2.5,50./2.5,70./2.5,100./2.5};
const float fcentbins_1S[NCENT1S+1] = {0,5./2.5,10./2.5,20./2.5,30./2.5,40./2.5,50./2.5,70./2.5,100./2.5};

const double ptbins_2S[NPT2S+1] = {0,7,14,40};
const double rapbins_2S[NRAP2S+1] = {0,1.2,2.4};
const int centbins_2S[NCENT2S+1] = {0,10./2.5,30./2.5,50./2.5,100./2.5};
const float fcentbins_2S[NCENT2S+1] = {0,10./2.5,30./2.5,50./2.5,100./2.5};

void dimueff::Loop(int YS, bool ispbpb, int strategy)
   // YS = N for NS
   // ispbpb = true for PbPb, false for pp
   // strategy = 0 for fit + reco quantities
   //            1 for fit + truth quantities
   //            2 for count + reco quantities
   //            3 for count + reco quantities
{
//   In a ROOT session, you can do:
//      Root > .L dimueff.C
//      Root > dimueff t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   TFile *f = new TFile("eff_output.root","RECREATE");

   double den_pt_NS[NPT1S+1] = {0};
   double den_rap_NS[NRAP1S+1] = {0};
   double den_cent_NS[NCENT1S+1] = {0};
   double denerr_pt_NS[NPT1S+1] = {0};
   double denerr_rap_NS[NRAP1S+1] = {0};
   double denerr_cent_NS[NCENT1S+1] = {0};
   TH1F *hden_pt_NS[NPT1S+1] = {NULL};
   TH1F *hden_rap_NS[NRAP1S+1] = {NULL};
   TH1F *hden_cent_NS[NCENT1S+1] = {NULL};

   double num_pt_NS[NPT1S+1] = {0};
   double num_rap_NS[NRAP1S+1] = {0};
   double num_cent_NS[NCENT1S+1] = {0};
   double numerr_pt_NS[NPT1S+1] = {0};
   double numerr_rap_NS[NRAP1S+1] = {0};
   double numerr_cent_NS[NCENT1S+1] = {0};
   TH1F *hnum_pt_NS[NPT1S+1] = {NULL};
   TH1F *hnum_rap_NS[NRAP1S+1] = {NULL};
   TH1F *hnum_cent_NS[NCENT1S+1] = {NULL};

   double num_tp_pt_NS[NPT1S+1] = {0};
   double num_tp_rap_NS[NRAP1S+1] = {0};
   double num_tp_cent_NS[NCENT1S+1] = {0};
   double numerr_tp_pt_NS[NPT1S+1] = {0};
   double numerr_tp_rap_NS[NRAP1S+1] = {0};
   double numerr_tp_cent_NS[NCENT1S+1] = {0};
   TH1F *hnum_tp_pt_NS[NPT1S+1] = {NULL};
   TH1F *hnum_tp_rap_NS[NRAP1S+1] = {NULL};
   TH1F *hnum_tp_cent_NS[NCENT1S+1] = {NULL};

   for (int ibin=0; ibin<NPT1S+1; ibin++)
   {
      hden_pt_NS[ibin] = new TH1F(Form("hden_pt_NS_%i",ibin),Form("hden_pt_NS_%i",ibin),250,7,12);
      hnum_pt_NS[ibin] = new TH1F(Form("hnum_pt_NS_%i",ibin),Form("hnum_pt_NS_%i",ibin),250,7,12);
      hnum_tp_pt_NS[ibin] = new TH1F(Form("hnum_tp_pt_NS_%i",ibin),Form("hnum_tp_pt_NS_%i",ibin),250,7,12);
   }
   for (int ibin=0; ibin<NRAP1S+1; ibin++)
   {
      hden_rap_NS[ibin] = new TH1F(Form("hden_rap_NS_%i",ibin),Form("hden_rap_NS_%i",ibin),250,7,12);
      hnum_rap_NS[ibin] = new TH1F(Form("hnum_rap_NS_%i",ibin),Form("hnum_rap_NS_%i",ibin),250,7,12);
      hnum_tp_rap_NS[ibin] = new TH1F(Form("hnum_tp_rap_NS_%i",ibin),Form("hnum_tp_rap_NS_%i",ibin),250,7,12);
   }
   for (int ibin=0; ibin<NCENT1S+1; ibin++)
   {
      hden_cent_NS[ibin] = new TH1F(Form("hden_cent_NS_%i",ibin),Form("hden_cent_NS_%i",ibin),250,7,12);
      hnum_cent_NS[ibin] = new TH1F(Form("hnum_cent_NS_%i",ibin),Form("hnum_cent_NS_%i",ibin),250,7,12);
      hnum_tp_cent_NS[ibin] = new TH1F(Form("hnum_tp_cent_NS_%i",ibin),Form("hnum_tp_cent_NS_%i",ibin),250,7,12);
   }

   const unsigned int NPTNS = !ispbpb || YS==1 ? NPT1S : NPT2S;
   const unsigned int NRAPNS = !ispbpb || YS==1 ? NRAP1S : NRAP2S;
   const unsigned int NCENTNS = YS==1 ? NCENT1S : NCENT2S;

   const double *ptbins_NS = !ispbpb || YS==1 ? ptbins_1S : ptbins_2S;
   const double *rapbins_NS = !ispbpb || YS==1 ? rapbins_1S : rapbins_2S;
   const int *centbins_NS = YS==1 ? centbins_1S : centbins_2S;
   const float *fcentbins_NS = YS==1 ? fcentbins_1S : fcentbins_2S;

   const double massmin = YS==1 ? 8.0 : (YS==2 ? 8.5 : 8.8);
   const double massmax = YS==1 ? 10.5 : (YS==2 ? 11 : 11.3);

   TH1F *hdrmin = new TH1F("hdrmin","hdrmin",100,0,0.5);
   TH2F *hdrmindpt = new TH2F("hdrmindpt","hdrmindpt",100,0,0.5,100,0,1);
   TH1F *hgenpt2 = new TH1F("hgenpt2","hgenpt2",100,0,50);
   TH1F *hgenrap2 = new TH1F("hgenrap2","hgenrap2",100,-2.5,2.5);
   TH1F *hgenpt = new TH1F("hgenpt","hgenpt",NPTNS,ptbins_NS);
   TH1F *hgenrap = new TH1F("hgenrap","hgenrap",NRAPNS,rapbins_NS);
   TH1F *hrecopt = new TH1F("hrecopt","hrecopt",NPTNS,ptbins_NS);
   TH1F *hrecorap = new TH1F("hrecorap","hrecorap",NRAPNS,rapbins_NS);
   TH1F *hrecocent = new TH1F("hrecocent","hrecocent",NCENTNS,fcentbins_NS);
   TH1F *hrecopt2 = new TH1F("hrecopt2","hrecopt2",100,0,50);
   TH1F *hrecorap2 = new TH1F("hrecorap2","hrecorap2",100,-2.5,2.5);
   TH1F *hrecocent2 = new TH1F("hrecocent2","hrecocent2",40,0,40);
   
   TH1F *heffpt = new TH1F("heffpt","heffpt",NPTNS,ptbins_NS);
   TH1F *heffrap = new TH1F("heffrap","heffrap",NRAPNS,rapbins_NS);
   TH1F *heffcent = new TH1F("heffcent","heffcent",NCENTNS,fcentbins_NS);
   TH1F *hefftppt = new TH1F("hefftppt","hefftppt",NPTNS,ptbins_NS);
   TH1F *hefftprap = new TH1F("hefftprap","hefftprap",NRAPNS,rapbins_NS);
   TH1F *hefftpcent = new TH1F("hefftpcent","hefftpcent",NCENTNS,fcentbins_NS);

   // don't read useless branches
   fChain->SetBranchStatus("Reco_mu*",0);  
   fChain->SetBranchStatus("Reco_trk*",0);  
   fChain->SetBranchStatus("Gen_mu*",0);  

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      double weight=1.;

      for (int igen=0; igen<Gen_QQ_size; igen++)
      {
         TLorentzVector *tlvgenmup = (TLorentzVector*) Gen_QQ_mupl_4mom->At(igen);
         TLorentzVector *tlvgenmum = (TLorentzVector*) Gen_QQ_mumi_4mom->At(igen);
         TLorentzVector *tlvgen = (TLorentzVector*) Gen_QQ_4mom->At(igen);
         // // let's consider the dimuon instead of the upsilon, to take into account FSR
         // TLorentzVector *tlvgen = new TLorentzVector(); *tlvgen = (*tlvgenmup) + (*tlvgenmum);

         double genupspt = tlvgen->Pt();
         double genupsrap = tlvgen->Rapidity();
         if (ispbpb) weight = weight_shape(genupspt,YS);
         if (ispbpb) weight *= weightpt(genupspt,YS)*FindCenWeight(Centrality,YS);
         hgenpt->Fill(genupspt,weight);
         hgenpt2->Fill(genupspt,weight);
         hgenrap->Fill(genupsrap,weight);
         hgenrap2->Fill(genupsrap,weight);

         // if (tlvgen->M()<massmin || tlvgen->M()>massmax) continue;
         if (YS==1 && !smuacc_loose(tlvgenmup,tlvgenmum)) continue;
         if (YS!=1 && !smuacc_tight(tlvgenmup,tlvgenmum)) continue;
         if (genupspt>ptbins_NS[NPTNS]) continue;
         if (fabs(genupsrap)>rapbins_NS[NRAPNS]) continue;

         // reco-truth matching
         double drmin=1e99,dptmin=1e99;
         unsigned int irecmin=0;
         TLorentzVector *tlvrecmin=NULL;
         for (int irec=0; irec<Reco_QQ_size; irec++)
         {
            if (Reco_QQ_sign[irec]!=0) continue;
            TLorentzVector *tlvrec = (TLorentzVector*) Reco_QQ_4mom->At(irec);
            // if (tlvrec->M()<massmin || tlvrec->M()>massmax) continue;
            double dr=tlvrec->DeltaR(*tlvgen);
            if (dr<drmin)
            {
               drmin=dr;
               tlvrecmin=tlvrec;
               irecmin=irec;
               dptmin=fabs(tlvrec->Pt()-genupspt)/genupspt;
            }
         }
         bool found = (drmin<DRCUT);
         hdrmin->Fill(drmin);
         hdrmindpt->Fill(drmin,dptmin);

         // cuts
         bool idok=false;
         double weighttp=1.;
         double recupspt=-1e99;
         double recupsrap=-1e99;
         if (found)
         {
            idok = idcuts(irecmin);
            if (ispbpb) idok = idok 
               // && (HLTriggers&1)==1 
                  && (Reco_QQ_trig[irecmin]&1)==1;
            else idok = idok 
               // && (HLTriggers&2)==2
                  && (Reco_QQ_trig[irecmin]&2)==2;
            TLorentzVector *tlvmup = (TLorentzVector*) Reco_QQ_mupl_4mom->At(irecmin);
            TLorentzVector *tlvmum = (TLorentzVector*) Reco_QQ_mumi_4mom->At(irecmin);
            weighttp=weight_tp(tlvmup->Pt(),tlvmup->Eta(),ispbpb)*weight_tp(tlvmum->Pt(),tlvmum->Eta(),ispbpb);
            recupspt = tlvrecmin->Pt();
            recupsrap = tlvrecmin->Rapidity();
         }

         if (idok)
         {
            hrecopt->Fill(recupspt,weight);
            hrecorap->Fill(recupsrap,weight);
            hrecocent->Fill(Centrality,weight);
            hrecopt2->Fill(recupspt,weight);
            hrecorap2->Fill(recupsrap,weight);
            hrecocent2->Fill(Centrality,weight);
         }

         for (unsigned int ibin=0; ibin<NPTNS+1; ibin++)
         {
            // if (ibin==0 && genupspt>ptbins_NS[NPTNS]) continue;
            if (ibin==0 || (genupspt>=ptbins_NS[ibin-1] && genupspt<ptbins_NS[ibin]))
               // den_pt_NS[ibin]+=weight;
               hden_pt_NS[ibin]->Fill(tlvgen->M(),weight);

            double ptnum = (strategy==1 || strategy==3) ? genupspt : recupspt;
            if (ibin==0 || (ptnum>=ptbins_NS[ibin-1] && ptnum<ptbins_NS[ibin]))
               if (idok)
               {
                  // num_pt_NS[ibin]+=weight;
                  // num_tp_pt_NS[ibin]+=weight*weighttp;
                  hnum_pt_NS[ibin]->Fill(tlvrecmin->M(),weight);
                  hnum_tp_pt_NS[ibin]->Fill(tlvrecmin->M(),weight*weighttp);
               }
         }
         for (unsigned int ibin=0; ibin<NRAPNS+1; ibin++)
         {
            // if (ibin==0 && fabs(genupsrap)>rapbins_NS[NRAPNS]) continue;
            if (ibin==0 || (genupsrap>=rapbins_NS[ibin-1] && genupsrap<rapbins_NS[ibin]))
               // den_rap_NS[ibin]+=weight;
               hden_rap_NS[ibin]->Fill(tlvgen->M(),weight);

            double rapnum = (strategy==1 || strategy==3) ? genupsrap : recupsrap;
            if (ibin==0 || (rapnum>=rapbins_NS[ibin-1] && rapnum<rapbins_NS[ibin]))
               if (idok)
               {
                  // num_rap_NS[ibin]+=weight;
                  // num_tp_rap_NS[ibin]+=weight*weighttp;
                  hnum_rap_NS[ibin]->Fill(tlvrecmin->M(),weight);
                  hnum_tp_rap_NS[ibin]->Fill(tlvrecmin->M(),weight*weighttp);
               }
         }
         if (ispbpb)
            for (unsigned int ibin=0; ibin<NCENTNS+1; ibin++)
            {
               if (ibin!=0 && (Centrality<centbins_NS[ibin-1] || Centrality>=centbins_NS[ibin])) continue;
               // den_cent_NS[ibin]+=weight;
               hden_cent_NS[ibin]->Fill(tlvgen->M(),weight);

               if (idok)
               {
                  // num_cent_NS[ibin]+=weight;
                  // num_tp_cent_NS[ibin]+=weight*weighttp;
                  hnum_cent_NS[ibin]->Fill(tlvrecmin->M(),weight);
                  hnum_tp_cent_NS[ibin]->Fill(tlvrecmin->M(),weight*weighttp);
               }
            }

      }
   }

   // compute numerators
   for (unsigned int ibin=0; ibin<NPTNS+1; ibin++)
   {
      den_pt_NS[ibin] = countNS(hden_pt_NS[ibin],massmin,massmax,denerr_pt_NS[ibin]);
      num_pt_NS[ibin] = (strategy<2) ? fitNS(hnum_pt_NS[ibin],numerr_pt_NS[ibin],YS) : countNS(hnum_pt_NS[ibin],massmin,massmax,numerr_pt_NS[ibin]);
      num_tp_pt_NS[ibin] = (strategy<2) ? fitNS(hnum_tp_pt_NS[ibin],numerr_tp_pt_NS[ibin],YS) : countNS(hnum_tp_pt_NS[ibin],massmin,massmax,numerr_tp_pt_NS[ibin]);
   }
   for (unsigned int ibin=0; ibin<NRAPNS+1; ibin++)
   {
      den_rap_NS[ibin] = countNS(hden_rap_NS[ibin],massmin,massmax,denerr_rap_NS[ibin]);
      num_rap_NS[ibin] = (strategy<2) ? fitNS(hnum_rap_NS[ibin],numerr_rap_NS[ibin],YS) : countNS(hnum_rap_NS[ibin],massmin,massmax,numerr_rap_NS[ibin]);
      num_tp_rap_NS[ibin] = (strategy<2) ? fitNS(hnum_tp_rap_NS[ibin],numerr_tp_rap_NS[ibin],YS) : countNS(hnum_tp_rap_NS[ibin],massmin,massmax,numerr_tp_rap_NS[ibin]);
   }
   if (ispbpb)
   {
      for (unsigned int ibin=0; ibin<NCENTNS+1; ibin++)
      {
         den_cent_NS[ibin] = countNS(hden_cent_NS[ibin],massmin,massmax,denerr_cent_NS[ibin]);
         num_cent_NS[ibin] = (strategy<2) ? fitNS(hnum_cent_NS[ibin],numerr_cent_NS[ibin],YS) : countNS(hnum_cent_NS[ibin],massmin,massmax,numerr_cent_NS[ibin]);
         num_tp_cent_NS[ibin] = (strategy<2) ? fitNS(hnum_tp_cent_NS[ibin],numerr_tp_cent_NS[ibin],YS) : countNS(hnum_tp_cent_NS[ibin],massmin,massmax,numerr_tp_cent_NS[ibin]);
      }
   }

   // print results
   ofstream textfile("results.txt");
   cout << "===========================" << endl;
   cout << "No tag and probe corrections" << endl;
   cout << "===========================" << endl;
   cout << endl << "pt" << endl;
   for (unsigned int ibin=0; ibin<NPTNS+1; ibin++)
   {
      double binmin = (ibin==0) ? ptbins_NS[0] : ptbins_NS[ibin-1];
      double binmax = (ibin==0) ? ptbins_NS[NPTNS] : ptbins_NS[ibin];
      double val = num_pt_NS[ibin]/den_pt_NS[ibin];
      double err = RError(num_pt_NS[ibin],numerr_pt_NS[ibin],den_pt_NS[ibin],denerr_pt_NS[ibin]);
      cout << "[" << binmin << "," << binmax << "]: " << val << " +/- " << err << endl;
      textfile << "pt " << binmin << " " << binmax << " " << val << " " << err << endl;
      if (ibin>0) 
      {
         heffpt->SetBinContent(ibin,val);
         heffpt->SetBinError(ibin,err);
      }
   }
   cout << endl << "rapidity" << endl;
   for (unsigned int ibin=0; ibin<NRAPNS+1; ibin++)
   {
      double binmin = (ibin==0) ? rapbins_NS[0] : rapbins_NS[ibin-1];
      double binmax = (ibin==0) ? rapbins_NS[NRAPNS] : rapbins_NS[ibin];
      double val = num_rap_NS[ibin]/den_rap_NS[ibin];
      double err = RError(num_rap_NS[ibin],numerr_rap_NS[ibin],den_rap_NS[ibin],denerr_rap_NS[ibin]);
      cout << "[" << binmin << "," << binmax << "]: " << val << " +/- " << err << endl;
      textfile << "rapidity " << binmin << " " << binmax << " " << val << " " << err << endl;
      if (ibin>0) 
      {
         heffrap->SetBinContent(ibin,val);
         heffrap->SetBinError(ibin,err);
      }
   }
   if (ispbpb)
   {
      cout << endl << "centrality" << endl;
      for (unsigned int ibin=0; ibin<NCENTNS+1; ibin++)
      {
         double binmin = (ibin==0) ? 2.5*centbins_NS[0] : 2.5*centbins_NS[ibin-1];
         double binmax = (ibin==0) ? 2.5*centbins_NS[NCENTNS] : 2.5*centbins_NS[ibin];
         double val = num_cent_NS[ibin]/den_cent_NS[ibin];
         double err = RError(num_cent_NS[ibin],numerr_cent_NS[ibin],den_cent_NS[ibin],denerr_cent_NS[ibin]);
         cout << "[" << binmin << "," << binmax << "]: " << val << " +/- " << err << endl;
         textfile << "centrality " << binmin << " " << binmax << " " << val << " " << err << endl;
         if (ibin>0) 
         {
            heffcent->SetBinContent(ibin,val);
            heffcent->SetBinError(ibin,err);
         }
      }
   }

   cout << endl;
   cout << "==============================" << endl;
   cout << "With tag and probe corrections" << endl;
   cout << "==============================" << endl;
   for (unsigned int ibin=0; ibin<NPTNS+1; ibin++)
   {
      double binmin = (ibin==0) ? ptbins_NS[0] : ptbins_NS[ibin-1];
      double binmax = (ibin==0) ? ptbins_NS[NPTNS] : ptbins_NS[ibin];
      double val = num_tp_pt_NS[ibin]/den_pt_NS[ibin];
      double err = RError(num_tp_pt_NS[ibin],numerr_tp_pt_NS[ibin],den_pt_NS[ibin],denerr_pt_NS[ibin]);
      cout << "[" << binmin << "," << binmax << "]: " << val << " +/- " << err << endl;
      textfile << "pt_TnP " << binmin << " " << binmax << " " << val << " " << err << endl;
      if (ibin>0) 
      {
         hefftppt->SetBinContent(ibin,val);
         hefftppt->SetBinError(ibin,err);
      }
   }
   cout << endl << "rapidity" << endl;
   for (unsigned int ibin=0; ibin<NRAPNS+1; ibin++)
   {
      double binmin = (ibin==0) ? rapbins_NS[0] : rapbins_NS[ibin-1];
      double binmax = (ibin==0) ? rapbins_NS[NRAPNS] : rapbins_NS[ibin];
      double val = num_tp_rap_NS[ibin]/den_rap_NS[ibin];
      double err = RError(num_tp_rap_NS[ibin],numerr_tp_rap_NS[ibin],den_rap_NS[ibin],denerr_rap_NS[ibin]);
      cout << "[" << binmin << "," << binmax << "]: " << val << " +/- " << err << endl;
      textfile << "rapidity_TnP " << binmin << " " << binmax << " " << val << " " << err << endl;
      if (ibin>0) 
      {
         hefftprap->SetBinContent(ibin,val);
         hefftprap->SetBinError(ibin,err);
      }
   }
   if (ispbpb)
   {
      cout << endl << "centrality" << endl;
      for (unsigned int ibin=0; ibin<NCENTNS+1; ibin++)
      {
         double binmin = (ibin==0) ? 2.5*centbins_NS[0] : 2.5*centbins_NS[ibin-1];
         double binmax = (ibin==0) ? 2.5*centbins_NS[NCENTNS] : 2.5*centbins_NS[ibin];
         double val = num_tp_cent_NS[ibin]/den_cent_NS[ibin];
         double err = RError(num_tp_cent_NS[ibin],numerr_tp_cent_NS[ibin],den_cent_NS[ibin],denerr_cent_NS[ibin]);
         cout << "[" << binmin << "," << binmax << "]: " << val << " +/- " << err << endl;
         textfile << "centrality_TnP " << binmin << " " << binmax << " " << val << " " << err << endl;
         if (ibin>0) 
         {
            hefftpcent->SetBinContent(ibin,val);
            hefftpcent->SetBinError(ibin,err);
         }
      }
   }

   f->Write(); f->Close();
   textfile.close();
}

bool dimueff::smuacc_loose(TLorentzVector *tlv1, TLorentzVector *tlv2)
{
   if (fabs(tlv1->Eta())>2.4 || fabs(tlv2->Eta())>2.4) return false;
   if (tlv1->Pt()>3.5 && tlv2->Pt()>4) return true;
   if (tlv2->Pt()>3.5 && tlv1->Pt()>4) return true;
   return false;
}

bool dimueff::smuacc_tight(TLorentzVector *tlv1, TLorentzVector *tlv2)
{
   if (fabs(tlv1->Eta())>2.4 || fabs(tlv2->Eta())>2.4) return false;
   if (tlv1->Pt()>4 && tlv2->Pt()>4) return true;
   return false;
}

bool dimueff::idcuts(int irec)
{
   if (irec>Reco_QQ_size) return false;

   // /* if(muPos_found > 10 && */
   // /*             muPos_pixeLayers > 0 && */
   // /*             muPos_nchi2In < 4.0 && */
   // /*             TMath::Abs(muPos_dxy) < 3 && */
   // /*             TMath::Abs(muPos_dz) < 15 && muPos_nchi2Gl < 20 && */
   // /*             muPos_arbitrated==1 && */
   // /*             muPos_tracker==1){ */
   // /*           PosPass=1; */

   bool PosPass=false,NegPass=false;
   if (Reco_QQ_mupl_nTrkHits[irec]>10 &&
         Reco_QQ_mupl_nPixWMea[irec]>0 &&
         Reco_QQ_mupl_normChi2_inner[irec]<4.0 &&
         fabs(Reco_QQ_mupl_dxy[irec])<3 &&
         fabs(Reco_QQ_mupl_dz[irec])<15 &&
         Reco_QQ_mupl_normChi2_global[irec]<20.0 &&
         Reco_QQ_mupl_TrkMuArb[irec]==1)
      PosPass=true;

   if (Reco_QQ_mumi_nTrkHits[irec]>10 &&
         Reco_QQ_mumi_nPixWMea[irec]>0 &&
         Reco_QQ_mumi_normChi2_inner[irec]<4.0 &&
         fabs(Reco_QQ_mumi_dxy[irec])<3 &&
         fabs(Reco_QQ_mumi_dz[irec])<15 &&
         Reco_QQ_mumi_normChi2_global[irec]<20.0 &&
         Reco_QQ_mumi_TrkMuArb[irec]==1)
      NegPass=true;

   if (PosPass&&NegPass&&Reco_QQ_VtxProb[irec]>0.01) return true;
   else return false;
}

double dimueff::weightpt(double pt, int YS)
{
   double scale[7];
   if (YS==1)
   {
      scale[0] = 1.0;
      scale[1] = 1.112919104;
      scale[2] = 0.430737304;
      scale[3] = 0.169418472;
      scale[4] = 0.097706729;
      scale[5] = 0.087703928;
      scale[6] = 0.004902708;
   }
   else if (YS==2)
   {
      scale[0] =  1.0;
      scale[1] =  1.17201;
      scale[2] =  0.40233;
      scale[3] =  0.13702;
      scale[4] =  0.043731;
      scale[5] =  0.032069;
      scale[6] =  0.032069/18.93;
   }
   else 
      for (int i=0; i<7; i++) 
         scale[i]=1.;

   if (pt<3) return scale[0];
   else if (pt<6) return scale[1];
   else if (pt<9) return scale[2];
   else if (pt<12) return scale[3];
   else if (pt<15) return scale[4];
   else if (pt<30) return scale[5];
   else return scale[6];
}

double dimueff::weight_tp(double pt, double eta, bool ispbpb)
{
   if (!ispbpb)
   {
      if (fabs(eta)<1.6)
         return (0.9588*TMath::Erf((pt-2.0009)/1.8998))/(0.9604*TMath::Erf((pt-2.0586)/2.1567));
      else
         return (0.7897*TMath::Erf((pt-0.7162)/2.6261))/(0.7364*TMath::Erf((pt-1.2149)/2.3352));
   }
   else
   {
      if (fabs(eta)<1.6)
         return (0.9555*TMath::Erf((pt-1.3240)/2.5683))/(0.9576*TMath::Erf((pt-1.7883)/2.6583));
      else
         return (0.8335*TMath::Erf((pt-1.2470)/1.9782))/(0.7948*TMath::Erf((pt-1.3091)/2.2783));
   }
}

double dimueff::weight_shape(double pt, int YS)
{
   double shapeweight=1.;
   if(YS==1) shapeweight = 0.766 + 0.053*pt;
   if(YS==2) shapeweight = 0.377 + 0.148*pt;
   if(YS==3) shapeweight = 0.932 + 0.00745*pt;
   return shapeweight;
}

double dimueff::FindCenWeight(int Bin, int NS)
{
  float NCollArray[40]=
  {1747.49,1566.92,1393.97,1237.02,1095.03
   ,979.836,863.228,765.968,677.894,594.481
   ,522.453,456.049,399.178,347.174,299.925
   ,258.411,221.374,188.676,158.896,135.117
   ,112.481,93.5697,77.9192,63.2538,52.0938
   ,42.3553,33.7461,27.3213,21.8348,17.1722
   ,13.5661,10.6604,8.31383,6.37662,5.12347
   ,3.73576,3.07268,2.41358,2.10707,1.76851};
   /*double NCollArray[50]={1563.03, 1370.41, 1204.05, 1063.45, 943.5,
                         834.12, 736.223, 654.913, 576.466, 507.757, 443.05, 386.802, 334.48,
                         290.097, 247.779, 211.762, 179.834, 153.509, 127.75, 106.59, 88.1189,
                         72.3836, 59.1049, 47.3574, 37.7951, 30.1705, 23.6861, 18.6918, 14.2287,
                         10.9705, 8.76148, 6.57459, 5.01557, 3.78525, 2.9123, 2.12377, 1.5,
                         0.922951, 0.581967, 0.503279,};*/
   double raa1S[40]={  0.35 , 0.35 ,  0.43,  0.43,  0.46,
      0.46,  0.46,  0.46,  0.51,  0.51,
      0.51, 0.51,  0.57, 0.57, 0.57,
      0.57, 0.63, 0.63, 0.63, 0.63,
      0.88, 0.88, 0.88, 0.88, 0.88,
      0.88, 0.88, 0.88, 1.2, 1.2,
      1.2, 1.2, 1.2, 1.2, 1.2,
      1.2, 1.2, 1.2, 1.2, 1.2};

   double raa2S[40]={  0.053 , 0.053 , 0.053, 0.053, 0.086,
      0.086, 0.086, 0.086, 0.086, 0.086,
      0.086, 0.086, 0.29, 0.29, 0.29, 0.29,
      0.29, 0.29, 0.29, 0.29, 0.198, 0.198,
      0.198, 0.198, 0.198, 0.198, 0.198, 0.198,
      0.198, 0.198, 0.198, 0.198, 0.198, 0.198,
      0.198, 0.198, 0.198, 0.198, 0.198, 0.198};
  return(NCollArray[Bin]*(NS==1 ? raa1S[Bin] : raa2S[Bin]));
}

double dimueff::countNS(TH1F *hist, double xmin, double xmax, double &err)
{
   return hist->IntegralAndError(hist->FindBin(xmin),hist->FindBin(xmax),err);
}

double dimueff::fitNS(TH1F *hist, double &err, int YS)
{
   // shhhhh
   gErrorIgnoreLevel=kError;
   RooMsgService::instance().setGlobalKillBelow(RooFit::ERROR);


   double masslow = hist->GetXaxis()->GetXmin();
   double masshigh = hist->GetXaxis()->GetXmax();
   RooRealVar* mass       = new RooRealVar("RecoUpsM","#mu#mu mass",masslow,masshigh,"GeV/c^{2}");
   const double M1S = YS==1 ? 9.46 : (YS==2 ? 10.023 : 10.355);   //upsilon 1S pgd mass value

   // *************************************************** free param in the fit
   int nt = hist->Integral();
   RooRealVar *nsig1f   = new RooRealVar("N_{#Upsilon(1S)}","nsig1S",0.99,0.95,1.05);
   RooRealVar  *mean = new RooRealVar("mass1S","#Upsilon mean",M1S,M1S-0.1,M1S+0.1);
   // scale mean and resolution by mass ratio
   RooFormulaVar *mean1S = new RooFormulaVar("mean1S","@0",RooArgList(*mean));

   //detector resolution ?? where is this coming from?
   RooRealVar    *sigma1  = new RooRealVar("#sigma_{CB1}","#sigma_{CB1}",7e-2,0,0.5); // 
   RooFormulaVar *sigma1S = new RooFormulaVar("sigma1S","@0"   ,RooArgList(*sigma1));
   RooRealVar *alpha  = new RooRealVar("#alpha_{CB}","tail shift",1.5,0,10);    // MC 5tev 1S pol2 
   RooRealVar *npow   = new RooRealVar("npow","power order",1.5,0,50);    // MC 5tev 1S pol2 
   RooRealVar *sigmaFraction = new RooRealVar("sigmaFraction","Sigma Fraction",0.8,0.,1.);
   // scale the sigmaGaus with sigma1S*scale=sigmaGaus now.
   RooRealVar    *scaleWidth = new RooRealVar("#sigma_{CB2}/#sigma_{CB1}","scaleWidth",1.8,1.,3);
   RooFormulaVar *sigmaGaus = new RooFormulaVar("sigmaGaus","@0*@1", RooArgList(*sigma1,*scaleWidth));
   RooCBShape  *cb1S_1    = new RooCBShape ("cb1S_1", "FSR cb 1s",
         *mass,*mean1S,*sigma1,*alpha,*npow);

   RooCBShape  *cb1S_2    = new RooCBShape ("cb1S_2", "FSR cb 1s",
         *mass,*mean1S,*sigmaGaus,*alpha,*npow);
   RooAddPdf      *sig1S  = new RooAddPdf  ("cbcb","1S mass pdf",
         RooArgList(*cb1S_1,*cb1S_2),*sigmaFraction);
   // bkg Chebychev
   RooRealVar *bkgdFraction   = new RooRealVar("BkgdFrac","bkgdFraction",0.01,0,1);
   RooRealVar *bkg_a1  = new RooRealVar("a1_bkg", "bkg_{a1}", 0.5, -50, 50);
   RooRealVar *bkg_a2  = new RooRealVar("a2_Bkg", "bkg_{a2}", -0.5, -50, 50);
   RooAbsPdf  *pdf_combinedbkgd  = new RooChebychev("bkgPdf","bkgPdf",
         *mass, RooArgList(*bkg_a1,*bkg_a2));
   // bkg_a2->setVal(0);
   // bkg_a2->setConstant();
   //fitted histo
   RooDataHist binnedData ("binnedData","binnedData",*mass,Import(*hist));
   // binnedData.Print("v");  
   RooFitResult *fit_2nd; 
   RooAbsPdf  *pdf             = new RooAddPdf ("pdf","total p.d.f.",
         RooArgList(*sig1S,*pdf_combinedbkgd),
         RooArgList(*nsig1f));
   // RooAbsReal* nll = pdf->createNLL(binnedData,NumCPU(20)) ;
   // RooMinuit(*nll).migrad();
   // RooMinuit(*nll).hesse();

   fit_2nd = pdf->fitTo(binnedData,Extended(0),Hesse(1),Minos(1),Save(1),SumW2Error(kTRUE),NumCPU(20),PrintLevel(-1));
   // fit_2nd = pdf->fitTo(binnedData,Extended(0),Hesse(1),Save(1),SumW2Error(kTRUE),NumCPU(20),PrintLevel(-1));
   double val = nsig1f->getVal()*nt;
   err = sqrt(pow(nsig1f->getError()*nt,2)+pow(val/nt,2)*nt);

   RooPlot* frame = mass->frame(Name(Form("rooplot_%s",hist->GetName())),Bins(hist->GetNbinsX()),Range(hist->GetXaxis()->GetXmin(),hist->GetXaxis()->GetXmax()));
   binnedData.plotOn(frame,DataError(RooAbsData::SumW2),Name("theData"),MarkerSize(0.8));
   pdf->plotOn(frame,Components("cb1S_1"),Name("TheFirstCB"),LineColor(kTeal)); 
   pdf->plotOn(frame,Components("cb1S_2"),Name("TheSecondCB"),LineColor(kOrange)); 
   pdf->plotOn(frame,Components("bkgPdf"),Name("TheBackground"),LineColor(kDashed)); 
   pdf->plotOn(frame,Name("thePdf"),LineColor(kBlue)); 

   // RooArgSet * pars = pdf->getParameters(binnedData);


   //plot data
   TCanvas c(Form("canv_%s",hist->GetName())); c.cd();
   binnedData.plotOn(frame,Name("theData"),MarkerSize(0.8)); 
   pdf->plotOn(frame,Components("cb1S_1"),Name("TheFirstCB"),LineColor(kTeal)); 
   pdf->plotOn(frame,Components("cb1S_2"),Name("TheSecondCB"),LineColor(kOrange)); 
   pdf->plotOn(frame,Components("bkgPdf"),Name("TheBackground"),LineColor(kDashed)); 
   pdf->plotOn(frame,Name("thePdf"),LineColor(kBlue)); 
   frame->SetTitle("");
   frame->GetXaxis()->SetTitle("m_{#mu^{+}#mu^{-}} (GeV/c^{2})");
   frame->GetXaxis()->CenterTitle(kTRUE);
   frame->GetYaxis()->SetTitleOffset(1.3);
   frame->Draw();
   c.Draw();
   c.SaveAs(Form("%s.pdf",hist->GetName()));
   c.SaveAs(Form("%s.png",hist->GetName()));
   // fit_2nd->Print("v");
   TCanvas cm(Form("cm_%s",hist->GetName()),"cm");
   cm.cd();
   TLatex latex1;
   latex1.SetNDC();
   TPad pPad1(Form("pPad1_%s",hist->GetName()),"pPad1",0.01,0.3-0.03,0.96,0.92);
   pPad1.SetBottomMargin(0.03);
   TPad pPad2(Form("pPad2_%s",hist->GetName()),"pPad2",0.05,0.05,1,0.3);
   pPad2.SetTopMargin(0.0);
   pPad2.SetBottomMargin(-0.1);
   frame->SetMinimum(1);
   pPad1.SetLogy();
   // pPad2->SetBottomMargin(gStyle->GetPadBottomMargin()/0.3);
   // pPad1->SetTopMargin(gStyle->GetPadTopMargin()/0.7);
   pPad1.Draw();
   pPad1.cd();
   //  sig1S->paramOn(frame,Layout(0.12,0.5,0.38));
   pPad1.Update();
   frame->Draw();
   latex1.SetTextSize(0.032);
   // latex1.DrawLatex(0.15,1.-0.05*1.8,Form("%s",choseSampleLegend[choseSample]));
   // latex1.DrawLatex(0.15,1.-0.05*4.5,Form("%.2f < |y| < %.2f",dimuYMin,dimuYMax)); 
   // latex1.DrawLatex(0.15,1.-0.05*5.5,Form("%.1f < p_{T}^{#Upsilon} < %.1f",dimuPtMin,dimuPtMax));
   // latex1.DrawLatex(0.15,1.-0.05*6.5,Form("p_{T}^{#mu1} > %.1f GeV/c",muonPtCut_min1));
   // latex1.DrawLatex(0.15,1.-0.05*7.5,Form("p_{T}^{#mu2} > %.1f GeV/c",muonPtCut_min2));

   latex1.DrawLatex(0.78,1.-0.05*3.5,Form("n_{CB} = %.2f",npow->getVal()));
   latex1.DrawLatex(0.78,1.-0.05*4.5,Form("#alpha_{CB} = %.2f",alpha->getVal()));
   latex1.DrawLatex(0.78,1.-0.05*5.5,Form("#sigma_{CB1} = %.2f",sigma1->getVal()));
   latex1.DrawLatex(0.78,1.-0.05*6.5,Form("#sigma_{CB2}/#sigma_{CB1} = %.2f",scaleWidth->getVal()));
   latex1.DrawLatex(0.72,1.-0.05*7.5,Form("normalisation = %.2f",sigmaFraction->getVal()));
   latex1.DrawLatex(0.78,1.-0.05*8.5,Form("m_{0} = %.3f",mean1S->getVal()));
   latex1.DrawLatex(0.78,1.-0.05*9.5,Form("Sig_{frac} = %.3f",nsig1f->getVal()));
   cm.cd(0);
   // TPad *pPad2 = new TPad("pPad2","pPad2",0.01,0.05,0.96,0.29);
   pPad2.SetTopMargin(0.0);
   pPad2.SetBottomMargin(-0.1);
   pPad2.Draw();
   pPad2.cd();
   double chi2FromRoo = frame->chiSquare(fit_2nd->floatParsFinal().getSize());
   cout<<"!!!!!!!! chi2 from simple pull= "<<frame->chiSquare()<<"\t chi2 from RooFit= "<<chi2FromRoo <<endl;
   RooHist *phPullm = frame->pullHist(0,0,true); // this calcualtes the pulls taking the integral of the fit in each bin, instead of the value in the middle of the bid
   phPullm->SetName("phPullm");
   double *ypull     = phPullm->GetY();
   double Chi2       = 0;
   int nFullBinsPull = 0;
   for (int i=0; i < hist->GetNbinsX(); i++) 
   {
      if (hist->GetBinContent(i) == 0) continue;
      nFullBinsPull++;
      Chi2 = Chi2 + pow(ypull[i],2);
   }
   // for writing on canvas
   int nFitParam     = fit_2nd->floatParsFinal().getSize();
   int Dof           = nFullBinsPull - nFitParam;
   double UnNormChi2 = Chi2;
   Chi2             /= (nFullBinsPull - nFitParam);

   cout<<"!!!!! nFullBinsPull="<<nFullBinsPull<<"\tnFitParam="<<nFitParam<<endl;
   // draw pulls
   pPad2.cd();
   double mFrameMax = 0;


   RooPlot* prpFramePull = mass->frame(Name(Form("Pull_%s",hist->GetName())),Bins(hist->GetNbinsX()),Range(hist->GetXaxis()->GetXmin(),hist->GetXaxis()->GetXmax()));

   prpFramePull->GetXaxis()->SetTitle("m_{#mu#mu} (GeV/c^{2})");
   prpFramePull->GetXaxis()->CenterTitle(kTRUE);
   prpFramePull->GetXaxis()->SetTitleSize(0.06);
   prpFramePull->GetXaxis()->SetLabelSize(0.1);
   prpFramePull->GetYaxis()->CenterTitle(kTRUE);
   prpFramePull->GetYaxis()->SetTitleSize(0.08);
   prpFramePull->GetYaxis()->SetLabelSize(0.1);
   prpFramePull->GetYaxis()->SetTitleOffset(0.4);
   prpFramePull->GetXaxis()->SetTitleOffset(0.6);

   prpFramePull->GetYaxis()->SetTitle("Pull");
   prpFramePull->addPlotable(phPullm,"PX");

   if (prpFramePull->GetMinimum()*-1 > prpFramePull->GetMaximum()) mFrameMax = prpFramePull->GetMinimum()*-1;
   else mFrameMax = prpFramePull->GetMaximum();
   mFrameMax = min(5.,mFrameMax);
   prpFramePull->SetMaximum(mFrameMax); 
   prpFramePull->SetMinimum(-1*mFrameMax); 
   prpFramePull->Draw();

   latex1.SetTextSize(0.085);
   double myChi2 = chi2FromRoo*Dof;
   latex1.DrawLatex(0.7,1.-0.05*3.5,Form("#chi^{2}/ndf = %2.1f/%d",myChi2,Dof));
   cm.SaveAs(Form("%s_pulls.pdf",hist->GetName()));
   cm.SaveAs(Form("%s_pulls.png",hist->GetName()));

   // clean begind us
   delete nsig1f;
   delete mass; delete mean; delete mean1S;
   delete sigma1; delete sigma1S; delete alpha; delete npow;
   delete sigmaFraction; delete scaleWidth; delete sigmaGaus; delete cb1S_1; delete cb1S_2;
   delete sig1S; delete bkgdFraction; delete bkg_a1; delete bkg_a2; delete pdf_combinedbkgd; delete pdf;
   // delete nll;

   return val;
}

//Ratio Error
double dimueff::RError(double A, double eA, double B, double eB){
   double f=A/B;
   double fA=eA/A;
   double fB=eB/B;
   double eR=  f*sqrt( (fA*fA + fB*fB )) ;
   return eR;
}


//Product Error
double dimueff::PError(double A, double eA, double B, double eB){
   double f=A*B;
   double fA=eA/A;
   double fB=eB/B;
   double eR=  f*sqrt( (fA*fA + fB*fB )) ;
   return eR;
}
