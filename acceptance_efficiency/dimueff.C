#define dimueff_cxx
#include "dimueff.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>

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

const double ptbins_2S[NPT2S+1] = {0,5,12,40};
const double rapbins_2S[NRAP2S+1] = {0,1.2,2.4};
const int centbins_2S[NCENT2S+1] = {0,10./2.5,30./2.5,50./2.5,100./2.5};

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
      hden_pt_NS[ibin] = new TH1F(Form("hden_pt_NS_%i",ibin),Form("hden_pt_NS_%i",ibin),700,5,12);
      hnum_pt_NS[ibin] = new TH1F(Form("hnum_pt_NS_%i",ibin),Form("hnum_pt_NS_%i",ibin),700,5,12);
      hnum_tp_pt_NS[ibin] = new TH1F(Form("hnum_tp_pt_NS_%i",ibin),Form("hnum_tp_pt_NS_%i",ibin),700,5,12);
   }
   for (int ibin=0; ibin<NRAP1S+1; ibin++)
   {
      hden_rap_NS[ibin] = new TH1F(Form("hden_rap_NS_%i",ibin),Form("hden_rap_NS_%i",ibin),700,5,12);
      hnum_rap_NS[ibin] = new TH1F(Form("hnum_rap_NS_%i",ibin),Form("hnum_rap_NS_%i",ibin),700,5,12);
      hnum_tp_rap_NS[ibin] = new TH1F(Form("hnum_tp_rap_NS_%i",ibin),Form("hnum_tp_rap_NS_%i",ibin),700,5,12);
   }
   for (int ibin=0; ibin<NCENT1S+1; ibin++)
   {
      hden_cent_NS[ibin] = new TH1F(Form("hden_cent_NS_%i",ibin),Form("hden_cent_NS_%i",ibin),700,5,12);
      hnum_cent_NS[ibin] = new TH1F(Form("hnum_cent_NS_%i",ibin),Form("hnum_cent_NS_%i",ibin),700,5,12);
      hnum_tp_cent_NS[ibin] = new TH1F(Form("hnum_tp_cent_NS_%i",ibin),Form("hnum_tp_cent_NS_%i",ibin),700,5,12);
   }

   const unsigned int NPTNS = !ispbpb || YS==1 ? NPT1S : NPT2S;
   const unsigned int NRAPNS = !ispbpb || YS==1 ? NRAP1S : NRAP2S;
   const unsigned int NCENTNS = YS==1 ? NCENT1S : NCENT2S;

   const double *ptbins_NS = !ispbpb || YS==1 ? ptbins_1S : ptbins_2S;
   const double *rapbins_NS = !ispbpb || YS==1 ? rapbins_1S : rapbins_2S;
   const int *centbins_NS = YS==1 ? centbins_1S : centbins_2S;

   const double massmin = YS==1 ? 9.0 : (YS==2 ? 9.5 : 9.8);
   const double massmax = YS==1 ? 10.0 : (YS==2 ? 10.5 : 10.8);

   TH1F *hdrmin = new TH1F("hdrmin","hdrmin",100,0,0.5);
   TH2F *hdrmindpt = new TH2F("hdrmindpt","hdrmindpt",100,0,0.5,100,0,1);
   TH1F *hgenpt2 = new TH1F("hgenpt2","hgenpt2",100,0,50);
   TH1F *hgenrap2 = new TH1F("hgenrap2","hgenrap2",100,-2.5,2.5);
   TH1F *hgenpt = new TH1F("hgenpt","hgenpt",NPTNS,ptbins_NS);
   TH1F *hgenrap = new TH1F("hgenrap","hgenrap",NRAPNS,rapbins_NS);
   TH1F *hrecopt = new TH1F("hrecopt","hrecopt",NPTNS,ptbins_NS);
   TH1F *hrecorap = new TH1F("hrecorap","hrecorap",NRAPNS,rapbins_NS);
   TH1F *hrecocent = new TH1F("hrecocent","hrecocent",NCENTNS,(float*) centbins_NS);
   TH1F *hrecopt2 = new TH1F("hrecopt2","hrecopt2",100,0,50);
   TH1F *hrecorap2 = new TH1F("hrecorap2","hrecorap2",100,-2.5,2.5);
   TH1F *hrecocent2 = new TH1F("hrecocent2","hrecocent2",40,0,40);
   
   TH1F *heffpt = new TH1F("heffpt","heffpt",NPTNS,ptbins_NS);
   TH1F *heffrap = new TH1F("heffrap","heffrap",NRAPNS,rapbins_NS);
   TH1F *heffcent = new TH1F("heffcent","heffcent",NCENTNS,(float*) centbins_NS);
   TH1F *hefftppt = new TH1F("hefftppt","hefftppt",NPTNS,ptbins_NS);
   TH1F *hefftprap = new TH1F("hefftprap","hefftprap",NRAPNS,rapbins_NS);
   TH1F *hefftpcent = new TH1F("hefftpcent","hefftpcent",NCENTNS,(float*) centbins_NS);

   // don't read useless branches
   fChain->SetBranchStatus("Reco_mu*",0);  
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
      double val = num_tp_rap_NS[ibin]/den_rap_NS[ibin];
      double err = RError(num_tp_rap_NS[ibin],numerr_tp_rap_NS[ibin],den_rap_NS[ibin],denerr_rap_NS[ibin]);
      cout << "[" << binmin << "," << binmax << "]: " << val << " +/- " << err << endl;
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
         double val = num_tp_cent_NS[ibin]/den_cent_NS[ibin];
         double err = RError(num_tp_cent_NS[ibin],numerr_tp_cent_NS[ibin],den_cent_NS[ibin],denerr_cent_NS[ibin]);
         cout << "[" << binmin << "," << binmax << "]: " << val << " +/- " << err << endl;
         if (ibin>0) 
         {
            heffcent->SetBinContent(ibin,val);
            heffcent->SetBinError(ibin,err);
         }
      }
   }

   f->Write(); f->Close();
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
      scale[6] =  0.032069;
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
   RooRealVar *nsig1f   = new RooRealVar("N_{#Upsilon(1S)}","nsig1S",nt,0.5*nt,1.5*nt);
   RooRealVar  *mean = new RooRealVar("mass1S","#Upsilon mean",M1S,M1S-0.1,M1S+0.1);
   // scale mean and resolution by mass ratio
   RooFormulaVar *mean1S = new RooFormulaVar("mean1S","@0",RooArgList(*mean));

   //detector resolution ?? where is this coming from?
   RooRealVar    *sigma1  = new RooRealVar("#sigma_{CB1}","#sigma_{CB1}",1e-1,0,10); // 
   RooFormulaVar *sigma1S = new RooFormulaVar("sigma1S","@0"   ,RooArgList(*sigma1));
   RooRealVar *alpha  = new RooRealVar("#alpha_{CB}","tail shift",1.7,0,10);    // MC 5tev 1S pol2 
   RooRealVar *npow   = new RooRealVar("npow","power order",0.5,0,10);    // MC 5tev 1S pol2 
   RooRealVar *sigmaFraction = new RooRealVar("sigmaFraction","Sigma Fraction",0.8,0.,1.);
   // scale the sigmaGaus with sigma1S*scale=sigmaGaus now.
   RooRealVar    *scaleWidth = new RooRealVar("#sigma_{CB2}/#sigma_{CB1}","scaleWidth",2.3,1.,2.7);
   RooFormulaVar *sigmaGaus = new RooFormulaVar("sigmaGaus","@0*@1", RooArgList(*sigma1,*scaleWidth));
   RooCBShape  *cb1S_1    = new RooCBShape ("cb1S_1", "FSR cb 1s",
         *mass,*mean1S,*sigma1,*alpha,*npow);

   RooCBShape  *cb1S_2    = new RooCBShape ("cb1S_2", "FSR cb 1s",
         *mass,*mean1S,*sigmaGaus,*alpha,*npow);
   RooAddPdf      *sig1S  = new RooAddPdf  ("cbcb","1S mass pdf",
         RooArgList(*cb1S_1,*cb1S_2),*sigmaFraction);
   // bkg Chebychev
   RooRealVar *nbkgd   = new RooRealVar("n_{Bkgd}","nbkgd",0.01*nt,0,.1*nt);
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
         RooArgList(*pdf_combinedbkgd,*sig1S),
         RooArgList(*nbkgd,*nsig1f));
   RooAbsReal* nll = pdf->createNLL(binnedData,NumCPU(20)) ;
   RooMinuit(*nll).migrad();
   RooMinuit(*nll).hesse();
   // fit_2nd = pdf->fitTo(binnedData,Extended(1),Minos(0),Save(0),SumW2Error(kTRUE),NumCPU(20),PrintLevel(-1));


   double val = nsig1f->getVal();
   err = nsig1f->getError();

   TCanvas *c1 = new TCanvas(Form("canv_%s",hist->GetName()));
   RooPlot* xframe = mass->frame();
   binnedData.plotOn(xframe);
   pdf->plotOn(xframe);
   xframe->Draw();

   // clean begind us
   delete mass; delete nsig1f; delete mean; delete mean1S;
   delete sigma1; delete sigma1S; delete alpha; delete npow;
   delete sigmaFraction; delete scaleWidth; delete sigmaGaus; delete cb1S_1; delete cb1S_2;
   delete sig1S; delete nbkgd; delete bkg_a1; delete bkg_a2; delete pdf_combinedbkgd; delete pdf;
   delete nll;
   
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
