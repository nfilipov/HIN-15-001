//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Apr 28 13:49:14 2015 by ROOT version 5.34/17
// from TTree SingleGenMuonTree/SingleGenMuonTree
// found on file: UpsiAccEff/ForAcc/DimuonOnia2Dplots_Y1SGen_PP.root
//////////////////////////////////////////////////////////

#ifndef acceptance_h
#define acceptance_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class acceptance {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           GeventNb;
   Int_t           GrunNb;
   Int_t           GlumiBlock;
   Double_t        GenvertexX;
   Double_t        GenvertexY;
   Double_t        GenvertexZ;
   Double_t        GenJpsiMassP;
   Double_t        GenJpsiPtP;
   Double_t        GenJpsiRapP;
   Double_t        GenJpsiPxP;
   Double_t        GenJpsiPyP;
   Double_t        GenJpsiPzP;
   Int_t           GMid;
   Float_t         CtauTrue;
   Double_t        GenJpsiMass;
   Double_t        GenJpsiPt;
   Double_t        GenJpsiRap;
   Double_t        GenJpsiPx;
   Double_t        GenJpsiPy;
   Double_t        GenJpsiPz;
   Int_t           gbin;
   Double_t        GenmuPosPx;
   Double_t        GenmuPosPy;
   Double_t        GenmuPosPz;
   Double_t        GenmuPosEta;
   Double_t        GenmuPosPhi;
   Double_t        GenmuNegPx;
   Double_t        GenmuNegPy;
   Double_t        GenmuNegPz;
   Double_t        GenmuNegEta;
   Double_t        GenmuNegPhi;

   // List of branches
   TBranch        *b_GeventNb;   //!
   TBranch        *b_GrunNb;   //!
   TBranch        *b_GlumiBlock;   //!
   TBranch        *b_GenvertexX;   //!
   TBranch        *b_GenvertexY;   //!
   TBranch        *b_GenvertexZ;   //!
   TBranch        *b_GenJpsiMassP;   //!
   TBranch        *b_GenJpsiPtP;   //!
   TBranch        *b_GenJpsiRapP;   //!
   TBranch        *b_GenJpsiPxP;   //!
   TBranch        *b_GenJpsiPyP;   //!
   TBranch        *b_GenJpsiPzP;   //!
   TBranch        *b_GMid;   //!
   TBranch        *b_CtauTrue;   //!
   TBranch        *b_GenJpsiMass;   //!
   TBranch        *b_GenJpsiPt;   //!
   TBranch        *b_GenJpsiRap;   //!
   TBranch        *b_GenJpsiPx;   //!
   TBranch        *b_GenJpsiPy;   //!
   TBranch        *b_GenJpsiPz;   //!
   TBranch        *b_gbin;   //!
   TBranch        *b_GenmuPosPx;   //!
   TBranch        *b_GenmuPosPy;   //!
   TBranch        *b_GenmuPosPz;   //!
   TBranch        *b_GenmuPosEta;   //!
   TBranch        *b_GenmuPosPhi;   //!
   TBranch        *b_GenmuNegPx;   //!
   TBranch        *b_GenmuNegPy;   //!
   TBranch        *b_GenmuNegPz;   //!
   TBranch        *b_GenmuNegEta;   //!
   TBranch        *b_GenmuNegPhi;   //!

   acceptance(TTree *tree=0);
   virtual ~acceptance();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(int YS=1, bool ispbpb=true);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   static bool smuacc_loose(double pt1, double eta1, double pt2, double eta2);
   static bool smuacc_tight(double pt1, double eta1, double pt2, double eta2);
   static double weight_shape(double pt, int YS);
   static double RError(double A, double eA, double B, double eB);
   static double PError(double A, double eA, double B, double eB);
};

#endif

#ifdef acceptance_cxx
acceptance::acceptance(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("UpsiAccEff/ForAcc/DimuonOnia2Dplots_Y1SGen_PP.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("UpsiAccEff/ForAcc/DimuonOnia2Dplots_Y1SGen_PP.root");
      }
      f->GetObject("SingleGenMuonTree",tree);

   }
   Init(tree);
}

acceptance::~acceptance()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t acceptance::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t acceptance::LoadTree(Long64_t entry)
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

void acceptance::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("GeventNb", &GeventNb, &b_GeventNb);
   fChain->SetBranchAddress("GrunNb", &GrunNb, &b_GrunNb);
   fChain->SetBranchAddress("GlumiBlock", &GlumiBlock, &b_GlumiBlock);
   fChain->SetBranchAddress("GenvertexX", &GenvertexX, &b_GenvertexX);
   fChain->SetBranchAddress("GenvertexY", &GenvertexY, &b_GenvertexY);
   fChain->SetBranchAddress("GenvertexZ", &GenvertexZ, &b_GenvertexZ);
   fChain->SetBranchAddress("GenJpsiMassP", &GenJpsiMassP, &b_GenJpsiMassP);
   fChain->SetBranchAddress("GenJpsiPtP", &GenJpsiPtP, &b_GenJpsiPtP);
   fChain->SetBranchAddress("GenJpsiRapP", &GenJpsiRapP, &b_GenJpsiRapP);
   fChain->SetBranchAddress("GenJpsiPxP", &GenJpsiPxP, &b_GenJpsiPxP);
   fChain->SetBranchAddress("GenJpsiPyP", &GenJpsiPyP, &b_GenJpsiPyP);
   fChain->SetBranchAddress("GenJpsiPzP", &GenJpsiPzP, &b_GenJpsiPzP);
   fChain->SetBranchAddress("GMid", &GMid, &b_GMid);
   fChain->SetBranchAddress("CtauTrue", &CtauTrue, &b_CtauTrue);
   fChain->SetBranchAddress("GenJpsiMass", &GenJpsiMass, &b_GenJpsiMass);
   fChain->SetBranchAddress("GenJpsiPt", &GenJpsiPt, &b_GenJpsiPt);
   fChain->SetBranchAddress("GenJpsiRap", &GenJpsiRap, &b_GenJpsiRap);
   fChain->SetBranchAddress("GenJpsiPx", &GenJpsiPx, &b_GenJpsiPx);
   fChain->SetBranchAddress("GenJpsiPy", &GenJpsiPy, &b_GenJpsiPy);
   fChain->SetBranchAddress("GenJpsiPz", &GenJpsiPz, &b_GenJpsiPz);
   fChain->SetBranchAddress("gbin", &gbin, &b_gbin);
   fChain->SetBranchAddress("GenmuPosPx", &GenmuPosPx, &b_GenmuPosPx);
   fChain->SetBranchAddress("GenmuPosPy", &GenmuPosPy, &b_GenmuPosPy);
   fChain->SetBranchAddress("GenmuPosPz", &GenmuPosPz, &b_GenmuPosPz);
   fChain->SetBranchAddress("GenmuPosEta", &GenmuPosEta, &b_GenmuPosEta);
   fChain->SetBranchAddress("GenmuPosPhi", &GenmuPosPhi, &b_GenmuPosPhi);
   fChain->SetBranchAddress("GenmuNegPx", &GenmuNegPx, &b_GenmuNegPx);
   fChain->SetBranchAddress("GenmuNegPy", &GenmuNegPy, &b_GenmuNegPy);
   fChain->SetBranchAddress("GenmuNegPz", &GenmuNegPz, &b_GenmuNegPz);
   fChain->SetBranchAddress("GenmuNegEta", &GenmuNegEta, &b_GenmuNegEta);
   fChain->SetBranchAddress("GenmuNegPhi", &GenmuNegPhi, &b_GenmuNegPhi);
   Notify();
}

Bool_t acceptance::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void acceptance::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t acceptance::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef acceptance_cxx
