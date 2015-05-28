//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Apr 2322 13:5322:02 2015 by ROOT version 5.34/25
// from TTree myTree/My TTree of dimuons
// found on file: trees/Upsi_Histos_Pyquen1SPbPbMC_Pt03.root
//////////////////////////////////////////////////////////

#ifndef dimueff_h
#define dimueff_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TLorentzVector.h>
#include <TH2.h>

// Header file for the classes stored in the TTree if any.
#include <TClonesArray.h>

// Fixed size dimensions of array or collections stored in the TTree if any.

class dimueff {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   UInt_t          eventNb;
   UInt_t          runNb;
   UInt_t          LS;
   Float_t         zVtx;
   Int_t           HLTriggers;
   Int_t           Centrality;
   Int_t           Npix;
   Int_t           NpixelTracks;
   Int_t           Ntracks;
   Float_t         SumET_HF;
   Float_t         SumET_HFplus;
   Float_t         SumET_HFminus;
   Float_t         SumET_HFplusEta4;
   Float_t         SumET_HFminusEta4;
   Float_t         SumET_ET;
   Float_t         SumET_EE;
   Float_t         SumET_EB;
   Float_t         SumET_EEplus;
   Float_t         SumET_EEminus;
   Float_t         SumET_ZDC;
   Float_t         SumET_ZDCplus;
   Float_t         SumET_ZDCminus;
   Int_t           nEP;
   Int_t           nNfEP;
   Float_t         rpAng[1];   //[nEP]
   Float_t         rpSin[1];   //[nEP]
   Float_t         rpCos[1];   //[nEP]
   Float_t         NfRpAng[1];   //[nNfEP]
   Float_t         NfRpSin[1];   //[nNfEP]
   Float_t         NfRpCos[1];   //[nNfEP]
   Int_t           Reco_QQ_size;
   Int_t           Reco_QQ_type[78];   //[Reco_QQ_size]
   Int_t           Reco_QQ_sign[78];   //[Reco_QQ_size]
   TClonesArray    *Reco_QQ_4mom;
   TClonesArray    *Reco_QQ_mupl_4mom;
   TClonesArray    *Reco_QQ_mumi_4mom;
   Int_t           Reco_QQ_trig[78];   //[Reco_QQ_size]
   Float_t         Reco_QQ_ctau[78];   //[Reco_QQ_size]
   Float_t         Reco_QQ_ctauErr[78];   //[Reco_QQ_size]
   Float_t         Reco_QQ_ctauTrue[78];   //[Reco_QQ_size]
   Float_t         Reco_QQ_VtxProb[78];   //[Reco_QQ_size]
   Float_t         Reco_QQ_dca[78];   //[Reco_QQ_size]
   Float_t         Reco_QQ_MassErr[78];   //[Reco_QQ_size]
   TClonesArray    *Reco_QQ_vtx;
   Int_t           Reco_QQ_NtrkPt02[78];   //[Reco_QQ_size]
   Int_t           Reco_QQ_NtrkPt03[78];   //[Reco_QQ_size]
   Int_t           Reco_QQ_NtrkPt04[78];   //[Reco_QQ_size]
   Int_t           Reco_QQ_NtrkDeltaR03[78];   //[Reco_QQ_size]
   Int_t           Reco_QQ_NtrkDeltaR04[78];   //[Reco_QQ_size]
   Int_t           Reco_QQ_NtrkDeltaR05[78];   //[Reco_QQ_size]
   Bool_t          Reco_QQ_mupl_TrkMuArb[78];   //[Reco_QQ_size]
   Bool_t          Reco_QQ_mumi_TrkMuArb[78];   //[Reco_QQ_size]
   Bool_t          Reco_QQ_mupl_TMOneStaTight[78];   //[Reco_QQ_size]
   Bool_t          Reco_QQ_mumi_TMOneStaTight[78];   //[Reco_QQ_size]
   Int_t           Reco_QQ_mupl_nMuValHits[78];   //[Reco_QQ_size]
   Int_t           Reco_QQ_mumi_nMuValHits[78];   //[Reco_QQ_size]
   Int_t           Reco_QQ_mupl_nTrkHits[78];   //[Reco_QQ_size]
   Int_t           Reco_QQ_mumi_nTrkHits[78];   //[Reco_QQ_size]
   Float_t         Reco_QQ_mupl_normChi2_inner[78];   //[Reco_QQ_size]
   Float_t         Reco_QQ_mumi_normChi2_inner[78];   //[Reco_QQ_size]
   Float_t         Reco_QQ_mupl_normChi2_global[78];   //[Reco_QQ_size]
   Float_t         Reco_QQ_mumi_normChi2_global[78];   //[Reco_QQ_size]
   Int_t           Reco_QQ_mupl_nPixWMea[78];   //[Reco_QQ_size]
   Int_t           Reco_QQ_mumi_nPixWMea[78];   //[Reco_QQ_size]
   Int_t           Reco_QQ_mupl_nTrkWMea[78];   //[Reco_QQ_size]
   Int_t           Reco_QQ_mumi_nTrkWMea[78];   //[Reco_QQ_size]
   Int_t           Reco_QQ_mupl_StationsMatched[78];   //[Reco_QQ_size]
   Int_t           Reco_QQ_mumi_StationsMatched[78];   //[Reco_QQ_size]
   Float_t         Reco_QQ_mupl_dxy[78];   //[Reco_QQ_size]
   Float_t         Reco_QQ_mumi_dxy[78];   //[Reco_QQ_size]
   Float_t         Reco_QQ_mupl_dxyErr[78];   //[Reco_QQ_size]
   Float_t         Reco_QQ_mumi_dxyErr[78];   //[Reco_QQ_size]
   Float_t         Reco_QQ_mupl_dz[78];   //[Reco_QQ_size]
   Float_t         Reco_QQ_mumi_dz[78];   //[Reco_QQ_size]
   Float_t         Reco_QQ_mupl_dzErr[78];   //[Reco_QQ_size]
   Float_t         Reco_QQ_mumi_dzErr[78];   //[Reco_QQ_size]
   Float_t         Reco_QQ_mupl_pt_inner[78];   //[Reco_QQ_size]
   Float_t         Reco_QQ_mumi_pt_inner[78];   //[Reco_QQ_size]
   Float_t         Reco_QQ_mupl_pt_global[78];   //[Reco_QQ_size]
   Float_t         Reco_QQ_mumi_pt_global[78];   //[Reco_QQ_size]
   Float_t         Reco_QQ_mupl_ptErr_inner[78];   //[Reco_QQ_size]
   Float_t         Reco_QQ_mumi_ptErr_inner[78];   //[Reco_QQ_size]
   Float_t         Reco_QQ_mupl_ptErr_global[78];   //[Reco_QQ_size]
   Float_t         Reco_QQ_mumi_ptErr_global[78];   //[Reco_QQ_size]
   Int_t           Reco_mu_size;
   Int_t           Reco_mu_type[322];   //[Reco_mu_size]
   Int_t           Reco_mu_charge[322];   //[Reco_mu_size]
   TClonesArray    *Reco_mu_4mom;
   Int_t           Reco_mu_trig[322];   //[Reco_mu_size]
   Int_t           Reco_trk_size;
   Int_t           Reco_trk_charge[1];   //[Reco_trk_size]
   TClonesArray    *Reco_trk_4mom;
   TClonesArray    *Reco_trk_vtx;
   Float_t         Reco_trk_dxyError[1];   //[Reco_trk_size]
   Float_t         Reco_trk_dzError[1];   //[Reco_trk_size]
   Bool_t          Reco_mu_TrkMuArb[322];   //[Reco_mu_size]
   Bool_t          Reco_mu_TMOneStaTight[322];   //[Reco_mu_size]
   Int_t           Reco_mu_nMuValHits[322];   //[Reco_mu_size]
   Int_t           Reco_mu_nTrkHits[322];   //[Reco_mu_size]
   Float_t         Reco_mu_normChi2_inner[322];   //[Reco_mu_size]
   Float_t         Reco_mu_normChi2_global[322];   //[Reco_mu_size]
   Int_t           Reco_mu_nPixWMea[322];   //[Reco_mu_size]
   Int_t           Reco_mu_nTrkWMea[322];   //[Reco_mu_size]
   Int_t           Reco_mu_StationsMatched[322];   //[Reco_mu_size]
   Float_t         Reco_mu_dxy[322];   //[Reco_mu_size]
   Float_t         Reco_mu_dxyErr[322];   //[Reco_mu_size]
   Float_t         Reco_mu_dz[322];   //[Reco_mu_size]
   Float_t         Reco_mu_dzErr[322];   //[Reco_mu_size]
   Float_t         Reco_mu_pt_inner[322];   //[Reco_mu_size]
   Float_t         Reco_mu_pt_global[322];   //[Reco_mu_size]
   Float_t         Reco_mu_ptErr_inner[322];   //[Reco_mu_size]
   Float_t         Reco_mu_ptErr_global[322];   //[Reco_mu_size]
   Int_t           Gen_QQ_size;
   Int_t           Gen_QQ_type[2];   //[Gen_QQ_size]
   TClonesArray    *Gen_QQ_4mom;
   Int_t           Gen_QQ_momId[2];   //[Gen_QQ_size]
   Float_t         Gen_QQ_ctau[2];   //[Gen_QQ_size]
   TClonesArray    *Gen_QQ_mupl_4mom;
   TClonesArray    *Gen_QQ_mumi_4mom;
   Int_t           Gen_mu_size;
   Int_t           Gen_mu_type[19];   //[Gen_mu_size]
   Int_t           Gen_mu_charge[19];   //[Gen_mu_size]
   TClonesArray    *Gen_mu_4mom;

   // List of branches
   TBranch        *b_eventNb;   //!
   TBranch        *b_runNb;   //!
   TBranch        *b_LS;   //!
   TBranch        *b_zVtx;   //!
   TBranch        *b_HLTriggers;   //!
   TBranch        *b_Centrality;   //!
   TBranch        *b_Npix;   //!
   TBranch        *b_NpixelTracks;   //!
   TBranch        *b_Ntracks;   //!
   TBranch        *b_SumET_HF;   //!
   TBranch        *b_SumET_HFplus;   //!
   TBranch        *b_SumET_HFminus;   //!
   TBranch        *b_SumET_HFplusEta4;   //!
   TBranch        *b_SumET_HFminusEta4;   //!
   TBranch        *b_SumET_ET;   //!
   TBranch        *b_SumET_EE;   //!
   TBranch        *b_SumET_EB;   //!
   TBranch        *b_SumET_EEplus;   //!
   TBranch        *b_SumET_EEminus;   //!
   TBranch        *b_SumET_ZDC;   //!
   TBranch        *b_SumET_ZDCplus;   //!
   TBranch        *b_SumET_ZDCminus;   //!
   TBranch        *b_nEP;   //!
   TBranch        *b_nNfEP;   //!
   TBranch        *b_rpAng;   //!
   TBranch        *b_rpSin;   //!
   TBranch        *b_rpCos;   //!
   TBranch        *b_NfRpAng;   //!
   TBranch        *b_NfRpSin;   //!
   TBranch        *b_NfRpCos;   //!
   TBranch        *b_Reco_QQ_size;   //!
   TBranch        *b_Reco_QQ_type;   //!
   TBranch        *b_Reco_QQ_sign;   //!
   TBranch        *b_Reco_QQ_4mom;   //!
   TBranch        *b_Reco_QQ_mupl_4mom;   //!
   TBranch        *b_Reco_QQ_mumi_4mom;   //!
   TBranch        *b_Reco_QQ_trig;   //!
   TBranch        *b_Reco_QQ_ctau;   //!
   TBranch        *b_Reco_QQ_ctauErr;   //!
   TBranch        *b_Reco_QQ_ctauTrue;   //!
   TBranch        *b_Reco_QQ_VtxProb;   //!
   TBranch        *b_Reco_QQ_dca;   //!
   TBranch        *b_Reco_QQ_MassErr;   //!
   TBranch        *b_Reco_QQ_vtx;   //!
   TBranch        *b_Reco_QQ_NtrkPt02;   //!
   TBranch        *b_Reco_QQ_NtrkPt03;   //!
   TBranch        *b_Reco_QQ_NtrkPt04;   //!
   TBranch        *b_Reco_QQ_NtrkDeltaR03;   //!
   TBranch        *b_Reco_QQ_NtrkDeltaR04;   //!
   TBranch        *b_Reco_QQ_NtrkDeltaR05;   //!
   TBranch        *b_Reco_QQ_mupl_TrkMuArb;   //!
   TBranch        *b_Reco_QQ_mumi_TrkMuArb;   //!
   TBranch        *b_Reco_QQ_mupl_TMOneStaTight;   //!
   TBranch        *b_Reco_QQ_mumi_TMOneStaTight;   //!
   TBranch        *b_Reco_QQ_mupl_nMuValHits;   //!
   TBranch        *b_Reco_QQ_mumi_nMuValHits;   //!
   TBranch        *b_Reco_QQ_mupl_nTrkHits;   //!
   TBranch        *b_Reco_QQ_mumi_nTrkHits;   //!
   TBranch        *b_Reco_QQ_mupl_normChi2_inner;   //!
   TBranch        *b_Reco_QQ_mumi_normChi2_inner;   //!
   TBranch        *b_Reco_QQ_mupl_normChi2_global;   //!
   TBranch        *b_Reco_QQ_mumi_normChi2_global;   //!
   TBranch        *b_Reco_QQ_mupl_nPixWMea;   //!
   TBranch        *b_Reco_QQ_mumi_nPixWMea;   //!
   TBranch        *b_Reco_QQ_mupl_nTrkWMea;   //!
   TBranch        *b_Reco_QQ_mumi_nTrkWMea;   //!
   TBranch        *b_Reco_QQ_mupl_StationsMatched;   //!
   TBranch        *b_Reco_QQ_mumi_StationsMatched;   //!
   TBranch        *b_Reco_QQ_mupl_dxy;   //!
   TBranch        *b_Reco_QQ_mumi_dxy;   //!
   TBranch        *b_Reco_QQ_mupl_dxyErr;   //!
   TBranch        *b_Reco_QQ_mumi_dxyErr;   //!
   TBranch        *b_Reco_QQ_mupl_dz;   //!
   TBranch        *b_Reco_QQ_mumi_dz;   //!
   TBranch        *b_Reco_QQ_mupl_dzErr;   //!
   TBranch        *b_Reco_QQ_mumi_dzErr;   //!
   TBranch        *b_Reco_QQ_mupl_pt_inner;   //!
   TBranch        *b_Reco_QQ_mumi_pt_inner;   //!
   TBranch        *b_Reco_QQ_mupl_pt_global;   //!
   TBranch        *b_Reco_QQ_mumi_pt_global;   //!
   TBranch        *b_Reco_QQ_mupl_ptErr_inner;   //!
   TBranch        *b_Reco_QQ_mumi_ptErr_inner;   //!
   TBranch        *b_Reco_QQ_mupl_ptErr_global;   //!
   TBranch        *b_Reco_QQ_mumi_ptErr_global;   //!
   TBranch        *b_Reco_mu_size;   //!
   TBranch        *b_Reco_mu_type;   //!
   TBranch        *b_Reco_mu_charge;   //!
   TBranch        *b_Reco_mu_4mom;   //!
   TBranch        *b_Reco_mu_trig;   //!
   TBranch        *b_Reco_trk_size;   //!
   TBranch        *b_Reco_trk_charge;   //!
   TBranch        *b_Reco_trk_4mom;   //!
   TBranch        *b_Reco_trk_vtx;   //!
   TBranch        *b_Reco_trk_dxyError;   //!
   TBranch        *b_Reco_trk_dzError;   //!
   TBranch        *b_Reco_mu_TrkMuArb;   //!
   TBranch        *b_Reco_mu_TMOneStaTight;   //!
   TBranch        *b_Reco_mu_nMuValHits;   //!
   TBranch        *b_Reco_mu_nTrkHits;   //!
   TBranch        *b_Reco_mu_normChi2_inner;   //!
   TBranch        *b_Reco_mu_normChi2_global;   //!
   TBranch        *b_Reco_mu_nPixWMea;   //!
   TBranch        *b_Reco_mu_nTrkWMea;   //!
   TBranch        *b_Reco_mu_StationsMatched;   //!
   TBranch        *b_Reco_mu_dxy;   //!
   TBranch        *b_Reco_mu_dxyErr;   //!
   TBranch        *b_Reco_mu_dz;   //!
   TBranch        *b_Reco_mu_dzErr;   //!
   TBranch        *b_Reco_mu_pt_inner;   //!
   TBranch        *b_Reco_mu_pt_global;   //!
   TBranch        *b_Reco_mu_ptErr_inner;   //!
   TBranch        *b_Reco_mu_ptErr_global;   //!
   TBranch        *b_Gen_QQ_size;   //!
   TBranch        *b_Gen_QQ_type;   //!
   TBranch        *b_Gen_QQ_4mom;   //!
   TBranch        *b_Gen_QQ_momId;   //!
   TBranch        *b_Gen_QQ_ctau;   //!
   TBranch        *b_Gen_QQ_mupl_4mom;   //!
   TBranch        *b_Gen_QQ_mumi_4mom;   //!
   TBranch        *b_Gen_mu_size;   //!
   TBranch        *b_Gen_mu_type;   //!
   TBranch        *b_Gen_mu_charge;   //!
   TBranch        *b_Gen_mu_4mom;   //!

   dimueff(TTree *tree=0);
   virtual ~dimueff();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(int YS=1, bool ispbpb=true, int strategy=0, int var_tp=0);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);

   bool smuacc_loose(TLorentzVector* tlv1, TLorentzVector *tlv2);
   bool smuacc_tight(TLorentzVector* tlv1, TLorentzVector *tlv2);
   bool idcuts(int irec);
   static double weightpt(double pt, int YS);
   static double weightpt_syst(double pt, int dosyst=0);
   static double weightrap(double rap, int dosyst=0);
   static double weight_tp(double pt, double eta, bool ispbpb, int idx_variation=0);
   static double weight_shape(double pt, int YS);
   static double FindCenWeight(int Bin, int YS, bool dosyst=false);
   static double fitNS(TH1F *hist, double &err, int YS);
   static double countNS(TH1F *hist, double xmin, double xmax, double &err);
   static double RError(double A, double eA, double B, double eB);
   static double PError(double A, double eA, double B, double eB);
   static double systerr(double e0, double e1, double e2, double e3, double e4, double e5);
};

#endif

#ifdef dimueff_cxx
dimueff::dimueff(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("trees/Upsi_Histos_Pyquen1SPbPbMC_Pt03.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("trees/Upsi_Histos_Pyquen1SPbPbMC_Pt03.root");
      }
      f->GetObject("myTree",tree);

   }
   Init(tree);
}

dimueff::~dimueff()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t dimueff::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t dimueff::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void dimueff::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   Reco_QQ_4mom = 0;
   Reco_QQ_mupl_4mom = 0;
   Reco_QQ_mumi_4mom = 0;
   Reco_QQ_vtx = 0;
   Reco_mu_4mom = 0;
   Reco_trk_4mom = 0;
   Reco_trk_vtx = 0;
   Gen_QQ_4mom = 0;
   Gen_QQ_mupl_4mom = 0;
   Gen_QQ_mumi_4mom = 0;
   Gen_mu_4mom = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("eventNb", &eventNb, &b_eventNb);
   fChain->SetBranchAddress("runNb", &runNb, &b_runNb);
   fChain->SetBranchAddress("LS", &LS, &b_LS);
   fChain->SetBranchAddress("zVtx", &zVtx, &b_zVtx);
   fChain->SetBranchAddress("HLTriggers", &HLTriggers, &b_HLTriggers);
   fChain->SetBranchAddress("Centrality", &Centrality, &b_Centrality);
   fChain->SetBranchAddress("Npix", &Npix, &b_Npix);
   fChain->SetBranchAddress("NpixelTracks", &NpixelTracks, &b_NpixelTracks);
   fChain->SetBranchAddress("Ntracks", &Ntracks, &b_Ntracks);
   fChain->SetBranchAddress("SumET_HF", &SumET_HF, &b_SumET_HF);
   fChain->SetBranchAddress("SumET_HFplus", &SumET_HFplus, &b_SumET_HFplus);
   fChain->SetBranchAddress("SumET_HFminus", &SumET_HFminus, &b_SumET_HFminus);
   fChain->SetBranchAddress("SumET_HFplusEta4", &SumET_HFplusEta4, &b_SumET_HFplusEta4);
   fChain->SetBranchAddress("SumET_HFminusEta4", &SumET_HFminusEta4, &b_SumET_HFminusEta4);
   fChain->SetBranchAddress("SumET_ET", &SumET_ET, &b_SumET_ET);
   fChain->SetBranchAddress("SumET_EE", &SumET_EE, &b_SumET_EE);
   fChain->SetBranchAddress("SumET_EB", &SumET_EB, &b_SumET_EB);
   fChain->SetBranchAddress("SumET_EEplus", &SumET_EEplus, &b_SumET_EEplus);
   fChain->SetBranchAddress("SumET_EEminus", &SumET_EEminus, &b_SumET_EEminus);
   fChain->SetBranchAddress("SumET_ZDC", &SumET_ZDC, &b_SumET_ZDC);
   fChain->SetBranchAddress("SumET_ZDCplus", &SumET_ZDCplus, &b_SumET_ZDCplus);
   fChain->SetBranchAddress("SumET_ZDCminus", &SumET_ZDCminus, &b_SumET_ZDCminus);
   fChain->SetBranchAddress("nEP", &nEP, &b_nEP);
   fChain->SetBranchAddress("nNfEP", &nNfEP, &b_nNfEP);
   fChain->SetBranchAddress("rpAng", &rpAng, &b_rpAng);
   fChain->SetBranchAddress("rpSin", &rpSin, &b_rpSin);
   fChain->SetBranchAddress("rpCos", &rpCos, &b_rpCos);
   fChain->SetBranchAddress("NfRpAng", &NfRpAng, &b_NfRpAng);
   fChain->SetBranchAddress("NfRpSin", &NfRpSin, &b_NfRpSin);
   fChain->SetBranchAddress("NfRpCos", &NfRpCos, &b_NfRpCos);
   fChain->SetBranchAddress("Reco_QQ_size", &Reco_QQ_size, &b_Reco_QQ_size);
   fChain->SetBranchAddress("Reco_QQ_type", Reco_QQ_type, &b_Reco_QQ_type);
   fChain->SetBranchAddress("Reco_QQ_sign", Reco_QQ_sign, &b_Reco_QQ_sign);
   fChain->SetBranchAddress("Reco_QQ_4mom", &Reco_QQ_4mom, &b_Reco_QQ_4mom);
   fChain->SetBranchAddress("Reco_QQ_mupl_4mom", &Reco_QQ_mupl_4mom, &b_Reco_QQ_mupl_4mom);
   fChain->SetBranchAddress("Reco_QQ_mumi_4mom", &Reco_QQ_mumi_4mom, &b_Reco_QQ_mumi_4mom);
   fChain->SetBranchAddress("Reco_QQ_trig", Reco_QQ_trig, &b_Reco_QQ_trig);
   fChain->SetBranchAddress("Reco_QQ_ctau", Reco_QQ_ctau, &b_Reco_QQ_ctau);
   fChain->SetBranchAddress("Reco_QQ_ctauErr", Reco_QQ_ctauErr, &b_Reco_QQ_ctauErr);
   fChain->SetBranchAddress("Reco_QQ_ctauTrue", Reco_QQ_ctauTrue, &b_Reco_QQ_ctauTrue);
   fChain->SetBranchAddress("Reco_QQ_VtxProb", Reco_QQ_VtxProb, &b_Reco_QQ_VtxProb);
   fChain->SetBranchAddress("Reco_QQ_dca", Reco_QQ_dca, &b_Reco_QQ_dca);
   fChain->SetBranchAddress("Reco_QQ_MassErr", Reco_QQ_MassErr, &b_Reco_QQ_MassErr);
   fChain->SetBranchAddress("Reco_QQ_vtx", &Reco_QQ_vtx, &b_Reco_QQ_vtx);
   fChain->SetBranchAddress("Reco_QQ_NtrkPt02", Reco_QQ_NtrkPt02, &b_Reco_QQ_NtrkPt02);
   fChain->SetBranchAddress("Reco_QQ_NtrkPt03", Reco_QQ_NtrkPt03, &b_Reco_QQ_NtrkPt03);
   fChain->SetBranchAddress("Reco_QQ_NtrkPt04", Reco_QQ_NtrkPt04, &b_Reco_QQ_NtrkPt04);
   fChain->SetBranchAddress("Reco_QQ_NtrkDeltaR03", Reco_QQ_NtrkDeltaR03, &b_Reco_QQ_NtrkDeltaR03);
   fChain->SetBranchAddress("Reco_QQ_NtrkDeltaR04", Reco_QQ_NtrkDeltaR04, &b_Reco_QQ_NtrkDeltaR04);
   fChain->SetBranchAddress("Reco_QQ_NtrkDeltaR05", Reco_QQ_NtrkDeltaR05, &b_Reco_QQ_NtrkDeltaR05);
   fChain->SetBranchAddress("Reco_QQ_mupl_TrkMuArb", Reco_QQ_mupl_TrkMuArb, &b_Reco_QQ_mupl_TrkMuArb);
   fChain->SetBranchAddress("Reco_QQ_mumi_TrkMuArb", Reco_QQ_mumi_TrkMuArb, &b_Reco_QQ_mumi_TrkMuArb);
   fChain->SetBranchAddress("Reco_QQ_mupl_TMOneStaTight", Reco_QQ_mupl_TMOneStaTight, &b_Reco_QQ_mupl_TMOneStaTight);
   fChain->SetBranchAddress("Reco_QQ_mumi_TMOneStaTight", Reco_QQ_mumi_TMOneStaTight, &b_Reco_QQ_mumi_TMOneStaTight);
   fChain->SetBranchAddress("Reco_QQ_mupl_nMuValHits", Reco_QQ_mupl_nMuValHits, &b_Reco_QQ_mupl_nMuValHits);
   fChain->SetBranchAddress("Reco_QQ_mumi_nMuValHits", Reco_QQ_mumi_nMuValHits, &b_Reco_QQ_mumi_nMuValHits);
   fChain->SetBranchAddress("Reco_QQ_mupl_nTrkHits", Reco_QQ_mupl_nTrkHits, &b_Reco_QQ_mupl_nTrkHits);
   fChain->SetBranchAddress("Reco_QQ_mumi_nTrkHits", Reco_QQ_mumi_nTrkHits, &b_Reco_QQ_mumi_nTrkHits);
   fChain->SetBranchAddress("Reco_QQ_mupl_normChi2_inner", Reco_QQ_mupl_normChi2_inner, &b_Reco_QQ_mupl_normChi2_inner);
   fChain->SetBranchAddress("Reco_QQ_mumi_normChi2_inner", Reco_QQ_mumi_normChi2_inner, &b_Reco_QQ_mumi_normChi2_inner);
   fChain->SetBranchAddress("Reco_QQ_mupl_normChi2_global", Reco_QQ_mupl_normChi2_global, &b_Reco_QQ_mupl_normChi2_global);
   fChain->SetBranchAddress("Reco_QQ_mumi_normChi2_global", Reco_QQ_mumi_normChi2_global, &b_Reco_QQ_mumi_normChi2_global);
   fChain->SetBranchAddress("Reco_QQ_mupl_nPixWMea", Reco_QQ_mupl_nPixWMea, &b_Reco_QQ_mupl_nPixWMea);
   fChain->SetBranchAddress("Reco_QQ_mumi_nPixWMea", Reco_QQ_mumi_nPixWMea, &b_Reco_QQ_mumi_nPixWMea);
   fChain->SetBranchAddress("Reco_QQ_mupl_nTrkWMea", Reco_QQ_mupl_nTrkWMea, &b_Reco_QQ_mupl_nTrkWMea);
   fChain->SetBranchAddress("Reco_QQ_mumi_nTrkWMea", Reco_QQ_mumi_nTrkWMea, &b_Reco_QQ_mumi_nTrkWMea);
   fChain->SetBranchAddress("Reco_QQ_mupl_StationsMatched", Reco_QQ_mupl_StationsMatched, &b_Reco_QQ_mupl_StationsMatched);
   fChain->SetBranchAddress("Reco_QQ_mumi_StationsMatched", Reco_QQ_mumi_StationsMatched, &b_Reco_QQ_mumi_StationsMatched);
   fChain->SetBranchAddress("Reco_QQ_mupl_dxy", Reco_QQ_mupl_dxy, &b_Reco_QQ_mupl_dxy);
   fChain->SetBranchAddress("Reco_QQ_mumi_dxy", Reco_QQ_mumi_dxy, &b_Reco_QQ_mumi_dxy);
   fChain->SetBranchAddress("Reco_QQ_mupl_dxyErr", Reco_QQ_mupl_dxyErr, &b_Reco_QQ_mupl_dxyErr);
   fChain->SetBranchAddress("Reco_QQ_mumi_dxyErr", Reco_QQ_mumi_dxyErr, &b_Reco_QQ_mumi_dxyErr);
   fChain->SetBranchAddress("Reco_QQ_mupl_dz", Reco_QQ_mupl_dz, &b_Reco_QQ_mupl_dz);
   fChain->SetBranchAddress("Reco_QQ_mumi_dz", Reco_QQ_mumi_dz, &b_Reco_QQ_mumi_dz);
   fChain->SetBranchAddress("Reco_QQ_mupl_dzErr", Reco_QQ_mupl_dzErr, &b_Reco_QQ_mupl_dzErr);
   fChain->SetBranchAddress("Reco_QQ_mumi_dzErr", Reco_QQ_mumi_dzErr, &b_Reco_QQ_mumi_dzErr);
   fChain->SetBranchAddress("Reco_QQ_mupl_pt_inner", Reco_QQ_mupl_pt_inner, &b_Reco_QQ_mupl_pt_inner);
   fChain->SetBranchAddress("Reco_QQ_mumi_pt_inner", Reco_QQ_mumi_pt_inner, &b_Reco_QQ_mumi_pt_inner);
   fChain->SetBranchAddress("Reco_QQ_mupl_pt_global", Reco_QQ_mupl_pt_global, &b_Reco_QQ_mupl_pt_global);
   fChain->SetBranchAddress("Reco_QQ_mumi_pt_global", Reco_QQ_mumi_pt_global, &b_Reco_QQ_mumi_pt_global);
   fChain->SetBranchAddress("Reco_QQ_mupl_ptErr_inner", Reco_QQ_mupl_ptErr_inner, &b_Reco_QQ_mupl_ptErr_inner);
   fChain->SetBranchAddress("Reco_QQ_mumi_ptErr_inner", Reco_QQ_mumi_ptErr_inner, &b_Reco_QQ_mumi_ptErr_inner);
   fChain->SetBranchAddress("Reco_QQ_mupl_ptErr_global", Reco_QQ_mupl_ptErr_global, &b_Reco_QQ_mupl_ptErr_global);
   fChain->SetBranchAddress("Reco_QQ_mumi_ptErr_global", Reco_QQ_mumi_ptErr_global, &b_Reco_QQ_mumi_ptErr_global);
   fChain->SetBranchAddress("Reco_mu_size", &Reco_mu_size, &b_Reco_mu_size);
   fChain->SetBranchAddress("Reco_mu_type", Reco_mu_type, &b_Reco_mu_type);
   fChain->SetBranchAddress("Reco_mu_charge", Reco_mu_charge, &b_Reco_mu_charge);
   fChain->SetBranchAddress("Reco_mu_4mom", &Reco_mu_4mom, &b_Reco_mu_4mom);
   fChain->SetBranchAddress("Reco_mu_trig", Reco_mu_trig, &b_Reco_mu_trig);
   fChain->SetBranchAddress("Reco_trk_size", &Reco_trk_size, &b_Reco_trk_size);
   fChain->SetBranchAddress("Reco_trk_charge", &Reco_trk_charge, &b_Reco_trk_charge);
   fChain->SetBranchAddress("Reco_trk_4mom", &Reco_trk_4mom, &b_Reco_trk_4mom);
   fChain->SetBranchAddress("Reco_trk_vtx", &Reco_trk_vtx, &b_Reco_trk_vtx);
   fChain->SetBranchAddress("Reco_trk_dxyError", &Reco_trk_dxyError, &b_Reco_trk_dxyError);
   fChain->SetBranchAddress("Reco_trk_dzError", &Reco_trk_dzError, &b_Reco_trk_dzError);
   fChain->SetBranchAddress("Reco_mu_TrkMuArb", Reco_mu_TrkMuArb, &b_Reco_mu_TrkMuArb);
   fChain->SetBranchAddress("Reco_mu_TMOneStaTight", Reco_mu_TMOneStaTight, &b_Reco_mu_TMOneStaTight);
   fChain->SetBranchAddress("Reco_mu_nMuValHits", Reco_mu_nMuValHits, &b_Reco_mu_nMuValHits);
   fChain->SetBranchAddress("Reco_mu_nTrkHits", Reco_mu_nTrkHits, &b_Reco_mu_nTrkHits);
   fChain->SetBranchAddress("Reco_mu_normChi2_inner", Reco_mu_normChi2_inner, &b_Reco_mu_normChi2_inner);
   fChain->SetBranchAddress("Reco_mu_normChi2_global", Reco_mu_normChi2_global, &b_Reco_mu_normChi2_global);
   fChain->SetBranchAddress("Reco_mu_nPixWMea", Reco_mu_nPixWMea, &b_Reco_mu_nPixWMea);
   fChain->SetBranchAddress("Reco_mu_nTrkWMea", Reco_mu_nTrkWMea, &b_Reco_mu_nTrkWMea);
   fChain->SetBranchAddress("Reco_mu_StationsMatched", Reco_mu_StationsMatched, &b_Reco_mu_StationsMatched);
   fChain->SetBranchAddress("Reco_mu_dxy", Reco_mu_dxy, &b_Reco_mu_dxy);
   fChain->SetBranchAddress("Reco_mu_dxyErr", Reco_mu_dxyErr, &b_Reco_mu_dxyErr);
   fChain->SetBranchAddress("Reco_mu_dz", Reco_mu_dz, &b_Reco_mu_dz);
   fChain->SetBranchAddress("Reco_mu_dzErr", Reco_mu_dzErr, &b_Reco_mu_dzErr);
   fChain->SetBranchAddress("Reco_mu_pt_inner", Reco_mu_pt_inner, &b_Reco_mu_pt_inner);
   fChain->SetBranchAddress("Reco_mu_pt_global", Reco_mu_pt_global, &b_Reco_mu_pt_global);
   fChain->SetBranchAddress("Reco_mu_ptErr_inner", Reco_mu_ptErr_inner, &b_Reco_mu_ptErr_inner);
   fChain->SetBranchAddress("Reco_mu_ptErr_global", Reco_mu_ptErr_global, &b_Reco_mu_ptErr_global);
   fChain->SetBranchAddress("Gen_QQ_size", &Gen_QQ_size, &b_Gen_QQ_size);
   fChain->SetBranchAddress("Gen_QQ_type", Gen_QQ_type, &b_Gen_QQ_type);
   fChain->SetBranchAddress("Gen_QQ_4mom", &Gen_QQ_4mom, &b_Gen_QQ_4mom);
   fChain->SetBranchAddress("Gen_QQ_momId", Gen_QQ_momId, &b_Gen_QQ_momId);
   fChain->SetBranchAddress("Gen_QQ_ctau", Gen_QQ_ctau, &b_Gen_QQ_ctau);
   fChain->SetBranchAddress("Gen_QQ_mupl_4mom", &Gen_QQ_mupl_4mom, &b_Gen_QQ_mupl_4mom);
   fChain->SetBranchAddress("Gen_QQ_mumi_4mom", &Gen_QQ_mumi_4mom, &b_Gen_QQ_mumi_4mom);
   fChain->SetBranchAddress("Gen_mu_size", &Gen_mu_size, &b_Gen_mu_size);
   fChain->SetBranchAddress("Gen_mu_type", Gen_mu_type, &b_Gen_mu_type);
   fChain->SetBranchAddress("Gen_mu_charge", Gen_mu_charge, &b_Gen_mu_charge);
   fChain->SetBranchAddress("Gen_mu_4mom", &Gen_mu_4mom, &b_Gen_mu_4mom);
   Notify();
}

Bool_t dimueff::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void dimueff::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t dimueff::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef dimueff_cxx
