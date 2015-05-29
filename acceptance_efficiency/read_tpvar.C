#include "dimueff.C"
#include "TTree.h"
#include "TFile.h"
#include "TProfile.h"
#include "TString.h"
#include <math.h>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

double firsteff(TTree *tr, const char* name, double binlow, double binhigh);
void print(ifstream &intable, ofstream &outtable, double binmin, double binmax, double eff0, double efferr);

void read_tpvar(const char* file, int YS, const char* inputtable, const char* outputtable)
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

   ifstream intable(inputtable);
   ofstream outtable(outputtable);
   double binmin, binmax, eff0, efferr, effmean;

   TString var("pt_SF");
   tr->Draw("eff:1>>htemp(1,0,2)",Form("name==\"%s\"&&abs(binlow-%f)<.1&&abs(binhigh-%f)<.1",var.Data(),ptbins_NS[0],ptbins_NS[NPTNS]),"PROFs");
   TProfile *htemp = (TProfile*) gDirectory->Get("htemp");
   binmin=ptbins_NS[0];
   binmax=ptbins_NS[NPTNS];
   eff0=firsteff(tr,var.Data(),ptbins_NS[0],ptbins_NS[NPTNS]);
   efferr=htemp->GetBinError(1);
   effmean=htemp->GetBinContent(1);
   cout << setprecision(3)<<fixed << var << " " << binmin << " " << binmax << " " << eff0 << " " << efferr << " " << effmean << endl;
   print(intable,outtable,binmin,binmax,eff0,efferr);
   delete htemp;

   string dummy;
   intable >> dummy; // \hline

   for (unsigned int i=0; i<NPTNS; i++)
   {
      // cout << setprecision(3)<<fixed << Form("name==\"%s\"&&binlow==%f&&binhigh==%f",var.Data(),ptbins_NS[i],ptbins_NS[i+1]) << endl;
      tr->Draw("eff:1>>htemp(1,0,2)",Form("name==\"%s\"&&abs(binlow-%f)<.1&&abs(binhigh-%f)<.1",var.Data(),ptbins_NS[i],ptbins_NS[i+1]),"PROFs");
      htemp = (TProfile*) gDirectory->Get("htemp");
      binmin=ptbins_NS[i];
      binmax=ptbins_NS[i+1];
      eff0=firsteff(tr,var.Data(),ptbins_NS[i],ptbins_NS[i+1]);
      efferr=htemp->GetBinError(1);
      effmean=htemp->GetBinContent(1);
      cout << setprecision(3)<<fixed << var << " " << binmin << " " << binmax << " " << eff0 << " " << efferr << " " << effmean << endl;
      print(intable,outtable,binmin,binmax,eff0,efferr);
      delete htemp;
   }

   intable >> dummy; // \hline
   outtable << "\\hline" << endl;

   var = TString("rapidity_SF");
   tr->Draw("eff:1>>htemp(1,0,2)",Form("name==\"%s\"&&abs(binlow-%f)<.1&&abs(binhigh-%f)<.1",var.Data(),rapbins_NS[0],rapbins_NS[NRAPNS]),"PROFs");
   htemp = (TProfile*) gDirectory->Get("htemp");
   binmin=rapbins_NS[0];
   binmax=rapbins_NS[NRAPNS];
   eff0=firsteff(tr,var.Data(),rapbins_NS[0],rapbins_NS[NRAPNS]);
   efferr=htemp->GetBinError(1);
   effmean=htemp->GetBinContent(1);
   cout << setprecision(3)<<fixed << var << " " << binmin << " " << binmax << " " << eff0 << " " << efferr << " " << effmean << endl;
   // print(intable,outtable,binmin,binmax,eff0,efferr);
   delete htemp;

   for (unsigned int i=0; i<NRAPNS; i++)
   {
      // cout << setprecision(3)<<fixed << Form("name==\"%s\"&&binlow==%f&&binhigh==%f",var.Data(),rapbins_NS[i],rapbins_NS[i+1]) << endl;
      tr->Draw("eff:1>>htemp(1,0,2)",Form("name==\"%s\"&&abs(binlow-%f)<.1&&abs(binhigh-%f)<.1",var.Data(),rapbins_NS[i],rapbins_NS[i+1]),"PROFs");
      htemp = (TProfile*) gDirectory->Get("htemp");
      binmin=rapbins_NS[i];
      binmax=rapbins_NS[i+1];
      eff0=firsteff(tr,var.Data(),rapbins_NS[i],rapbins_NS[i+1]);
      efferr=htemp->GetBinError(1);
      effmean=htemp->GetBinContent(1);
      cout << setprecision(3)<<fixed << var << " " << binmin << " " << binmax << " " << eff0 << " " << efferr << " " << effmean << endl;
      print(intable,outtable,binmin,binmax,eff0,efferr);
      delete htemp;
   }

   intable >> dummy; // \hline
   outtable << "\\hline" << endl;

   var = TString("centrality_SF");
   tr->Draw("eff:1>>htemp(1,0,2)",Form("name==\"%s\"&&abs(binlow-%f)<.1&&abs(binhigh-%f)<.1",var.Data(),centbins_NS[0]*2.5,centbins_NS[NCENTNS]*2.5),"PROFs");
   htemp = (TProfile*) gDirectory->Get("htemp");
   binmin=centbins_NS[0]*2.5;
   binmax=centbins_NS[NCENTNS]*2.5;
   eff0=firsteff(tr,var.Data(),centbins_NS[0]*2.5,centbins_NS[NCENTNS]*2.5);
   efferr=htemp->GetBinError(1);
   effmean=htemp->GetBinContent(1);
   cout << setprecision(3)<<fixed << var << " " << binmin << " " << binmax << " " << eff0 << " " << efferr << " " << effmean << endl;
   // print(intable,outtable,binmin,binmax,eff0,efferr);
   delete htemp;

   for (unsigned int i=0; i<NCENTNS; i++)
   {
      // cout << setprecision(3)<<fixed << Form("name==\"%s\"&&binlow==%f&&binhigh==%f",var.Data(),centbins_NS[i],centbins_NS[i+1]) << endl;
      tr->Draw("eff:1>>htemp(1,0,2)",Form("name==\"%s\"&&abs(binlow-%f)<.1&&abs(binhigh-%f)<.1",var.Data(),centbins_NS[i],centbins_NS[i+1]),"PROFs");
      htemp = (TProfile*) gDirectory->Get("htemp");
      binmin=centbins_NS[i]*2.5;
      binmax=centbins_NS[i+1]*2.5;
      eff0=firsteff(tr,var.Data(),centbins_NS[i]*2.5,centbins_NS[i+1]*2.5);
      efferr=htemp->GetBinError(1);
      effmean=htemp->GetBinContent(1);
      cout << setprecision(3)<<fixed << var << " " << binmin << " " << binmax << " " << eff0 << " " << efferr << " " << effmean << endl;
      print(intable,outtable,binmin,binmax,eff0,efferr);
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

void print(ifstream &intable, ofstream &outtable, double binmin, double binmax, double eff0, double efferr)
{
   // p$_{\rm T}$ [\GeVc]& Reco Efficiency &Acceptance& Acc$\times$Eff & Scale Factor & Acc$\times$Eff$\times$SF  & Sys Err \\
   // \hline
   // 0.0-100.0   &  0.679  $\pm$  0.001  &  0.353  $\pm$  0.001  &  0.239  $\pm$  0.001  &  1.084  $\pm$  0.002  &  0.259  $\pm$  0.001  &  0.007 \\ 

   string dummy, label;
   double o_eff, o_efferr, o_acc, o_accerr, o_sys;
   intable >> label >> dummy >> 
      o_eff >> dummy >> o_efferr >> dummy >> // efficiency
      o_acc >> dummy >> o_accerr >> dummy >> // acceptance
      dummy >> dummy >> dummy >> dummy >>    // acc*eff
      dummy >> dummy >> dummy >> dummy >>    // SF
      dummy >> dummy >> dummy >> dummy >>    // acc*eff*SF
      o_sys >> dummy;                        // syst
   // cout << "bin check: I read " << label << ", you're asking for " << binmin << "-" << binmax << endl;
   outtable << setprecision(3) << fixed <<
      label << " & " <<
      o_eff << " $\\pm$ " << o_efferr << " & " <<
      o_acc << " $\\pm$ " << o_accerr << " & " <<
      o_acc*o_eff << " $\\pm$ " << sqrt(pow(o_accerr,2)+pow(o_efferr,2)) << " & " <<
      eff0 << " $\\pm$ " << efferr << " & " <<
      o_acc*o_eff*eff0 << " $\\pm$ " << sqrt(pow(o_accerr,2)+pow(o_efferr,2))*eff0 << " & " <<
      sqrt(pow(o_sys,2)+pow(efferr,2)) << " \\\\" << endl;
}
