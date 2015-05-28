#include "dimueff.C"

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
   cout << var << " " << ptbins_NS[0] << " " << ptbins_NS[NPTNS] << " " << htemp->GetBinContent(1) << " " << htemp->GetBinError(1) << endl;
   delete htemp;
   for (int i=0; i<NPTNS; i++)
   {
      // cout << Form("name==\"%s\"&&binlow==%f&&binhigh==%f",var.Data(),ptbins_NS[i],ptbins_NS[i+1]) << endl;
      tr->Draw("eff:1>>htemp(1,0,2)",Form("name==\"%s\"&&abs(binlow-%f)<.1&&abs(binhigh-%f)<.1",var.Data(),ptbins_NS[i],ptbins_NS[i+1]),"PROFs");
      TProfile *htemp = (TProfile*) gDirectory->Get("htemp");
      cout << var << " " << ptbins_NS[i] << " " << ptbins_NS[i+1] << " " << htemp->GetBinContent(1) << " " << htemp->GetBinError(1) << endl;
      delete htemp;
   }

   TString var("rapidity_SF");
   tr->Draw("eff:1>>htemp(1,0,2)",Form("name==\"%s\"&&abs(binlow-%f)<.1&&abs(binhigh-%f)<.1",var.Data(),rapbins_NS[0],rapbins_NS[NRAPNS]),"PROFs");
   TProfile *htemp = (TProfile*) gDirectory->Get("htemp");
   cout << var << " " << rapbins_NS[0] << " " << rapbins_NS[NRAPNS] << " " << htemp->GetBinContent(1) << " " << htemp->GetBinError(1) << endl;
   delete htemp;
   for (int i=0; i<NRAPNS; i++)
   {
      // cout << Form("name==\"%s\"&&binlow==%f&&binhigh==%f",var.Data(),rapbins_NS[i],rapbins_NS[i+1]) << endl;
      tr->Draw("eff:1>>htemp(1,0,2)",Form("name==\"%s\"&&abs(binlow-%f)<.1&&abs(binhigh-%f)<.1",var.Data(),rapbins_NS[i],rapbins_NS[i+1]),"PROFs");
      TProfile *htemp = (TProfile*) gDirectory->Get("htemp");
      cout << var << " " << rapbins_NS[i] << " " << rapbins_NS[i+1] << " " << htemp->GetBinContent(1) << " " << htemp->GetBinError(1) << endl;
      delete htemp;
   }

   TString var("centrality_SF");
   tr->Draw("eff:1>>htemp(1,0,2)",Form("name==\"%s\"&&abs(binlow-%f)<.1&&abs(binhigh-%f)<.1",var.Data(),centbins_NS[0]*2.5,centbins_NS[NCENTNS]*2.5),"PROFs");
   TProfile *htemp = (TProfile*) gDirectory->Get("htemp");
   cout << var << " " << centbins_NS[0] << " " << centbins_NS[NCENTNS] << " " << htemp->GetBinContent(1) << " " << htemp->GetBinError(1) << endl;
   delete htemp;
   for (int i=0; i<NCENTNS; i++)
   {
      // cout << Form("name==\"%s\"&&binlow==%f&&binhigh==%f",var.Data(),centbins_NS[i],centbins_NS[i+1]) << endl;
      tr->Draw("eff:1>>htemp(1,0,2)",Form("name==\"%s\"&&abs(binlow-%f)<.1&&abs(binhigh-%f)<.1",var.Data(),centbins_NS[i]*2.5,centbins_NS[i+1]*2.5),"PROFs");
      TProfile *htemp = (TProfile*) gDirectory->Get("htemp");
      cout << var << " " << centbins_NS[i] << " " << centbins_NS[i+1] << " " << htemp->GetBinContent(1) << " " << htemp->GetBinError(1) << endl;
      delete htemp;
   }

   f->Write();
   f->Close();
}
