#include "dimueff.C"
#include "TTree.h"
#include "TFile.h"
#include "TProfile.h"
#include "TString.h"
#include <math.h>
#include <cstring>

double firsteff(TTree *tr, const char* name, double binlow, double binhigh);

void read_tpvar(const char* file, int YS=1)
{
   TFile *f = new TFile("tpvar.root","RECREATE");
   TTree *tr = new TTree("tree","tree");
   tr->ReadFile(file,"name/C:binlow/F:binhigh/F:eff/F:stat/F:syst/F");

   const unsigned int NPTNS = YS==1 ? NPT1S : NPT2S;
   const unsigned int NRAPNS = YS==1 ? NRAP1S : NRAP2S;
   const unsigned int NCENTNS = YS==1 ? NCENT1S : NCENT2S;

   const double *ptbins_NS = YS==1 ? ptbins_1S : ptbins_2S;
   const double *rapbins_NS = YS==1 ? rapbins_1S : rapbins_2S;
   const int *centbins_NS = YS==1 ? centbins_1S : centbins_2S;

   TString var("pt_SF");
   tr->Draw("eff:1>>htemp(1,0,2)",Form("name==\"%s\"&&abs(binlow-%f)<.1&&abs(binhigh-%f)<.1",var.Data(),ptbins_NS[0],ptbins_NS[NPTNS]),"PROFs");
   TProfile *htemp = (TProfile*) gDirectory->Get("htemp");
   cout << var << " " << ptbins_NS[0] << " " << ptbins_NS[NPTNS] << " " << firsteff(tr,var.Data(),ptbins_NS[0],ptbins_NS[NPTNS]) << " " <<
      htemp->GetBinError(1) << " " << htemp->GetBinContent(1) << endl;
   delete htemp;
   for (int i=0; i<NPTNS; i++)
   {
      // cout << Form("name==\"%s\"&&binlow==%f&&binhigh==%f",var.Data(),ptbins_NS[i],ptbins_NS[i+1]) << endl;
      tr->Draw("eff:1>>htemp(1,0,2)",Form("name==\"%s\"&&abs(binlow-%f)<.1&&abs(binhigh-%f)<.1",var.Data(),ptbins_NS[i],ptbins_NS[i+1]),"PROFs");
      htemp = (TProfile*) gDirectory->Get("htemp");
      cout << var << " " << ptbins_NS[i] << " " << ptbins_NS[i+1] << " " << firsteff(tr,var.Data(),ptbins_NS[i],ptbins_NS[i+1]) << " " <<
         htemp->GetBinError(1) << " " << htemp->GetBinContent(1) << endl;
      delete htemp;
   }

   var = TString("rapidity_SF");
   tr->Draw("eff:1>>htemp(1,0,2)",Form("name==\"%s\"&&abs(binlow-%f)<.1&&abs(binhigh-%f)<.1",var.Data(),rapbins_NS[0],rapbins_NS[NRAPNS]),"PROFs");
   htemp = (TProfile*) gDirectory->Get("htemp");
   cout << var << " " << rapbins_NS[0] << " " << rapbins_NS[NRAPNS] << " " << firsteff(tr,var.Data(),rapbins_NS[0],rapbins_NS[NRAPNS]) << " "
      << htemp->GetBinError(1) << " " << htemp->GetBinContent(1) << endl;
   delete htemp;
   for (int i=0; i<NRAPNS; i++)
   {
      // cout << Form("name==\"%s\"&&binlow==%f&&binhigh==%f",var.Data(),rapbins_NS[i],rapbins_NS[i+1]) << endl;
      tr->Draw("eff:1>>htemp(1,0,2)",Form("name==\"%s\"&&abs(binlow-%f)<.1&&abs(binhigh-%f)<.1",var.Data(),rapbins_NS[i],rapbins_NS[i+1]),"PROFs");
      htemp = (TProfile*) gDirectory->Get("htemp");
      cout << var << " " << rapbins_NS[i] << " " << rapbins_NS[i+1] << " " << firsteff(tr,var.Data(),rapbins_NS[i],rapbins_NS[i+1]) << " "
         << htemp->GetBinError(1) << " " << htemp->GetBinContent(1) << endl;
      delete htemp;
   }

   var = TString("centrality_SF");
   tr->Draw("eff:1>>htemp(1,0,2)",Form("name==\"%s\"&&abs(binlow-%f)<.1&&abs(binhigh-%f)<.1",var.Data(),centbins_NS[0]*2.5,centbins_NS[NCENTNS]*2.5),"PROFs");
   htemp = (TProfile*) gDirectory->Get("htemp");
   cout << var << " " << centbins_NS[0] << " " << centbins_NS[NCENTNS] << " " << firsteff(tr,var.Data(),centbins_NS[0]*2.5,centbins_NS[NCENTNS]*2.5) << " "
      << htemp->GetBinError(1) << " " << htemp->GetBinContent(1) << endl;
   delete htemp;
   for (int i=0; i<NCENTNS; i++)
   {
      // cout << Form("name==\"%s\"&&binlow==%f&&binhigh==%f",var.Data(),centbins_NS[i],centbins_NS[i+1]) << endl;
      tr->Draw("eff:1>>htemp(1,0,2)",Form("name==\"%s\"&&abs(binlow-%f)<.1&&abs(binhigh-%f)<.1",var.Data(),centbins_NS[i]*2.5,centbins_NS[i+1]*2.5),"PROFs");
      htemp = (TProfile*) gDirectory->Get("htemp");
      cout << var << " " << centbins_NS[i] << " " << centbins_NS[i+1] << " " << firsteff(tr,var.Data(),centbins_NS[i]*2.5,centbins_NS[i+1]*2.5) << " "
         << htemp->GetBinError(1) << " " << htemp->GetBinContent(1) << endl;
      delete htemp;
   }

   f->Write();
   f->Close();
}

double firsteff(TTree *tr, const char* name, double binlow, double binhigh)
{
   char namevar[1000];
   float binlowvar, binhighvar, eff;
   TTree *tr2 = tr->CloneTree();
   tr2->SetBranchAddress("name",&namevar);
   tr2->SetBranchAddress("binlow",&binlowvar);
   tr2->SetBranchAddress("binhigh",&binhighvar);
   tr2->SetBranchAddress("eff",&eff);

   for (int i=0; i<tr2->GetEntries(); i++)
   {
      tr2->GetEntry(i);
      if (!strcmp(name,namevar) && fabs(binlow-binlowvar)<.1&&fabs(binhigh-binhighvar)<.1) {delete tr2; return eff;}
   }
}
