#define acceptance_cxx
#include "acceptance.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>

#define NPT1S 5
#define NRAP1S 6
#define NCENT1S 8

#define NPT2S 3
#define NRAP2S 2
#define NCENT2S 4

#define DRCUT 0.5

using namespace std;

const double ptbins_1S[NPT1S+1] = {0,2.5,5,8,12,20};
const double rapbins_1S[NRAP1S+1] = {0,0.4,0.8,1.2,1.6,2,2.4};

const double ptbins_2S[NPT2S+1] = {0,5,12,20};
const double rapbins_2S[NRAP2S+1] = {0,1.2,2.4};

void acceptance::Loop(int YS, bool ispbpb)
{
//   In a ROOT session, you can do:
//      Root > .L acceptance.C
//      Root > acceptance t
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

   double den_pt_NS[NPT1S+1] = {0};
   double den_rap_NS[NRAP1S+1] = {0};
   double denerr_pt_NS[NPT1S+1] = {0};
   double denerr_rap_NS[NRAP1S+1] = {0};

   double num_pt_NS[NPT1S+1] = {0};
   double num_rap_NS[NRAP1S+1] = {0};
   double numerr_pt_NS[NPT1S+1] = {0};
   double numerr_rap_NS[NRAP1S+1] = {0};

   const unsigned int NPTNS = !ispbpb || YS==1 ? NPT1S : NPT2S;
   const unsigned int NRAPNS = !ispbpb || YS==1 ? NRAP1S : NRAP2S;

   const double *ptbins_NS = !ispbpb || YS==1 ? ptbins_1S : ptbins_2S;
   const double *rapbins_NS = !ispbpb || YS==1 ? rapbins_1S : rapbins_2S;

   TFile *f = new TFile("acc_output.root","RECREATE");
   TH1F *haccpt = new TH1F("haccpt","haccpt",NPTNS,ptbins_NS);
   TH1F *haccrap = new TH1F("haccrap","haccrap",NRAPNS,rapbins_NS);

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      double weight = weight_shape(GenJpsiPtP,YS);

      if (GenJpsiPtP<ptbins_NS[0] || GenJpsiPtP>ptbins_NS[NPTNS]) continue;
      if (GenJpsiRapP<rapbins_NS[0] || GenJpsiRapP>rapbins_NS[NRAPNS]) continue;

      for (unsigned int ibin=0; ibin<NPTNS+1; ibin++)
      {
         if (ibin!=0 && (GenJpsiPtP<ptbins_NS[ibin-1] || GenJpsiPtP>ptbins_NS[ibin])) continue;
         den_pt_NS[ibin] += weight;
         denerr_pt_NS[ibin] += weight*weight;
         if ((YS==1 && smuacc_loose(sqrt(pow(GenmuPosPx,2)+pow(GenmuPosPy,2)),GenmuPosEta,sqrt(pow(GenmuNegPx,2)+pow(GenmuNegPy,2)),GenmuNegEta)) || 
               (YS!=1 && smuacc_tight(sqrt(pow(GenmuPosPx,2)+pow(GenmuPosPy,2)),GenmuPosEta,sqrt(pow(GenmuNegPx,2)+pow(GenmuNegPy,2)),GenmuNegEta)))
         {
            num_pt_NS[ibin] += weight;
            numerr_pt_NS[ibin] += weight*weight;
         }
      }
      for (unsigned int ibin=0; ibin<NRAPNS+1; ibin++)
      {
         if (ibin!=0 && (GenJpsiRapP<rapbins_NS[ibin-1] || GenJpsiRapP>rapbins_NS[ibin])) continue;
         den_rap_NS[ibin] += weight;
         denerr_rap_NS[ibin] += weight*weight;
         if ((YS==1 && smuacc_loose(sqrt(pow(GenmuPosPx,2)+pow(GenmuPosPy,2)),GenmuPosEta,sqrt(pow(GenmuNegPx,2)+pow(GenmuNegPy,2)),GenmuNegEta)) || 
               (YS!=1 && smuacc_tight(sqrt(pow(GenmuPosPx,2)+pow(GenmuPosPy,2)),GenmuPosEta,sqrt(pow(GenmuNegPx,2)+pow(GenmuNegPy,2)),GenmuNegEta)))
         {
            num_rap_NS[ibin] += weight;
            numerr_rap_NS[ibin] += weight*weight;
         }
      }


   }

   // update errors
   for (unsigned int ibin=0; ibin<NPTNS+1; ibin++) 
   {
      numerr_pt_NS[ibin] = sqrt(numerr_pt_NS[ibin]);
      denerr_pt_NS[ibin] = sqrt(denerr_pt_NS[ibin]);
   }
   for (unsigned int ibin=0; ibin<NRAPNS+1; ibin++) 
   {
      numerr_rap_NS[ibin] = sqrt(numerr_rap_NS[ibin]);
      denerr_rap_NS[ibin] = sqrt(denerr_rap_NS[ibin]);
   }


   // print results
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
         haccpt->SetBinContent(ibin,val);
         haccpt->SetBinError(ibin,err);
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
         haccrap->SetBinContent(ibin,val);
         haccrap->SetBinError(ibin,err);
      }
   }

   f->Write(); f->Close();
}

bool acceptance::smuacc_loose(double pt1, double eta1, double pt2, double eta2)
{
   if (fabs(eta1)>2.4 || fabs(eta2)>2.4) return false;
   if (pt1>3.5 && pt2>4) return true;
   if (pt2>3.5 && pt1>4) return true;
   return false;
}

bool acceptance::smuacc_tight(double pt1, double eta1, double pt2, double eta2)
{
   if (fabs(eta1)>2.4 || fabs(eta2)>2.4) return false;
   if (pt1>4 && pt2>4) return true;
   return false;
}

double acceptance::weight_shape(double pt, int YS)
{
   double shapeweight=1.;
   if(YS==1) shapeweight = 0.766 + 0.053*pt;
   if(YS==2) shapeweight = 0.377 + 0.148*pt;
   if(YS==3) shapeweight = 0.932 + 0.00745*pt;
   return shapeweight;
}

//Ratio Error
double acceptance::RError(double A, double eA, double B, double eB){
   double f=A/B;
   double fA=eA/A;
   double fB=eB/B;
   double eR=  f*sqrt( (fA*fA + fB*fB )) ;
   return eR;
}


//Product Error
double acceptance::PError(double A, double eA, double B, double eB){
   double f=A*B;
   double fA=eA/A;
   double fB=eB/B;
   double eR=  f*sqrt( (fA*fA + fB*fB )) ;
   return eR;
}
