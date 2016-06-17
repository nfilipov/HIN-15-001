#include "tnp_weight.h"
#include "TF1.h"
#include "TLegend.h"
#include "TH1.h"
#include "TCanvas.h"

Double_t tnp_weight_muidtrg_pbpb_wrapper(Double_t *x, Double_t *par) {
   return tnp_weight_muidtrg_pbpb(x[0],par[0],par[1]);
}
Double_t tnp_weight_muidtrg_pp_wrapper(Double_t *x, Double_t *par) {
   return tnp_weight_muidtrg_pp(x[0],par[0],par[1]);
}
Double_t tnp_weight_sta_pbpb_wrapper(Double_t *x, Double_t *par) {
   return tnp_weight_sta_pbpb(x[0],par[0],par[1]);
}
Double_t tnp_weight_sta_pp_wrapper(Double_t *x, Double_t *par) {
   return tnp_weight_sta_pp(x[0],par[0],par[1]);
}

float ptmin(float etamax) {
   float ans=0;
   if (etamax<1.) ans = 3.4;
   else if (etamax<1.5) ans = 5.8-2.4*etamax;
   else ans = 3.36667 - (7./9.)*etamax;
   ans = (int) (ans*10.);
   ans = ans/10.;
   return ans;
}

void plotSFs() {
   TCanvas *c1 = new TCanvas();
   TH1F *haxes = new TH1F("haxes",";p_{T} [GeV/c];Scale factor",1,0,30);

   float *etamin=NULL, *etamax=NULL;
   float eta, ptminval;

   // muidtrg, pbpb
   etamin = new float[4]; etamin[0]=0.; etamin[1]=0.9; etamin[2]=1.6; etamin[3]=2.1;
   etamax = new float[4]; etamax[0]=0.9; etamax[1]=1.6; etamax[2]=2.1; etamax[3] = 2.4;

   for (int i=0; i<4; i++) {
      haxes->GetYaxis()->SetRangeUser(0.5,1.5);
      haxes->Draw();

      TLegend *tleg = new TLegend(0.53,0.16,0.91,0.41);
      tleg->SetBorderSize(0);

      eta = (etamax[i]+etamin[i])/2.;
      ptminval = ptmin(etamax[i]);
      for (int i=1; i<=100; i++) {
         TF1 *fnom = new TF1(Form("f%i",i),tnp_weight_muidtrg_pbpb_wrapper,ptminval,30,2);
         fnom->SetParameters(eta,i);
         fnom->SetLineColor(kBlack);
         fnom->Draw("same");
      }
      TF1 *fp = new TF1("fp",tnp_weight_muidtrg_pbpb_wrapper,ptminval,30,2);
      fp->SetParameters(eta,-1);
      fp->SetLineColor(kBlue);
      fp->Draw("same");
      TF1 *fm = new TF1("fm",tnp_weight_muidtrg_pbpb_wrapper,ptminval,30,2);
      fm->SetParameters(eta,-2);
      fm->SetLineColor(kBlue);
      fm->Draw("same");
      TF1 *fnom = new TF1("fnom",tnp_weight_muidtrg_pbpb_wrapper,ptminval,30,2);
      fnom->SetParameters(eta,0);
      fnom->SetLineColor(kRed);
      fnom->Draw("same");

      tleg->SetHeader(Form("#splitline{PbPb, MuId+Trg}{#eta #in [%.1f,%.1f], p_{T}>%.1f GeV/c}",etamin[i],etamax[i],ptminval));
      tleg->AddEntry(fnom,"Nominal","l");
      tleg->AddEntry("f1","stat (100 toys)","l");
      tleg->AddEntry(fp,"syst (+/1#sigma)","l");
      tleg->Draw();
      c1->SaveAs(Form("tnp_muidtrg_pbpb_eta%.1f-%.1f.pdf",etamin[i],etamax[i]));
      c1->SaveAs(Form("tnp_muidtrg_pbpb_eta%.1f-%.1f.png",etamin[i],etamax[i]));
   }

   // muidtrg, pp
   for (int i=0; i<4; i++) {
      haxes->GetYaxis()->SetRangeUser(0.5,1.5);
      haxes->Draw();

      TLegend *tleg = new TLegend(0.53,0.16,0.91,0.41);
      tleg->SetBorderSize(0);

      eta = (etamax[i]+etamin[i])/2.;
      ptminval = ptmin(etamax[i]);
      for (int i=1; i<=100; i++) {
         TF1 *fnom = new TF1(Form("f%i",i),tnp_weight_muidtrg_pp_wrapper,ptminval,30,2);
         fnom->SetParameters(eta,i);
         fnom->SetLineColor(kBlack);
         fnom->Draw("same");
      }
      TF1 *fp = new TF1("fp",tnp_weight_muidtrg_pp_wrapper,ptminval,30,2);
      fp->SetParameters(eta,-1);
      fp->SetLineColor(kBlue);
      fp->Draw("same");
      TF1 *fm = new TF1("fm",tnp_weight_muidtrg_pp_wrapper,ptminval,30,2);
      fm->SetParameters(eta,-2);
      fm->SetLineColor(kBlue);
      fm->Draw("same");
      TF1 *fnom = new TF1("fnom",tnp_weight_muidtrg_pp_wrapper,ptminval,30,2);
      fnom->SetParameters(eta,0);
      fnom->SetLineColor(kRed);
      fnom->Draw("same");

      tleg->SetHeader(Form("#splitline{pp, MuId+Trg}{#eta #in [%.1f,%.1f], p_{T}>%.1f GeV/c}",etamin[i],etamax[i],ptminval));
      tleg->AddEntry(fnom,"Nominal","l");
      tleg->AddEntry("f1","stat (100 toys)","l");
      tleg->AddEntry(fp,"syst (+/1#sigma)","l");
      tleg->Draw();
      c1->SaveAs(Form("tnp_muidtrg_pp_eta%.1f-%.1f.pdf",etamin[i],etamax[i]));
      c1->SaveAs(Form("tnp_muidtrg_pp_eta%.1f-%.1f.png",etamin[i],etamax[i]));
   }

   // sta, pbpb
   etamin = new float[2]; etamin[0]=0.; etamin[1]=1.6;;
   etamax = new float[2]; etamax[0]=1.6; etamax[1]=2.4;

   for (int i=0; i<2; i++) {
      haxes->GetYaxis()->SetRangeUser(0.5,1.5);
      haxes->Draw();

      TLegend *tleg = new TLegend(0.53,0.16,0.91,0.41);
      tleg->SetBorderSize(0);

      eta = (etamax[i]+etamin[i])/2.;
      ptminval = ptmin(etamax[i]);
      for (int i=1; i<=100; i++) {
         TF1 *fnom = new TF1(Form("f%i",i),tnp_weight_sta_pbpb_wrapper,ptminval,30,2);
         fnom->SetParameters(eta,i);
         fnom->SetLineColor(kBlack);
         fnom->Draw("same");
      }
      TF1 *fp = new TF1("fp",tnp_weight_sta_pbpb_wrapper,ptminval,30,2);
      fp->SetParameters(eta,-1);
      fp->SetLineColor(kBlue);
      fp->Draw("same");
      TF1 *fm = new TF1("fm",tnp_weight_sta_pbpb_wrapper,ptminval,30,2);
      fm->SetParameters(eta,-2);
      fm->SetLineColor(kBlue);
      fm->Draw("same");
      TF1 *fnom = new TF1("fnom",tnp_weight_sta_pbpb_wrapper,ptminval,30,2);
      fnom->SetParameters(eta,0);
      fnom->SetLineColor(kRed);
      fnom->Draw("same");

      tleg->SetHeader(Form("#splitline{PbPb, STA}{#eta #in [%.1f,%.1f], p_{T}>%.1f GeV/c}",etamin[i],etamax[i],ptminval));
      tleg->AddEntry(fnom,"Nominal","l");
      tleg->AddEntry("f1","stat (100 toys)","l");
      tleg->AddEntry(fp,"syst (+/1#sigma)","l");
      tleg->Draw();
      c1->SaveAs(Form("tnp_sta_pbpb_eta%.1f-%.1f.pdf",etamin[i],etamax[i]));
      c1->SaveAs(Form("tnp_sta_pbpb_eta%.1f-%.1f.png",etamin[i],etamax[i]));
   }

   // sta, pp
   for (int i=0; i<2; i++) {
      haxes->GetYaxis()->SetRangeUser(0.5,1.5);
      haxes->Draw();

      TLegend *tleg = new TLegend(0.53,0.16,0.91,0.41);
      tleg->SetBorderSize(0);

      eta = (etamax[i]+etamin[i])/2.;
      ptminval = ptmin(etamax[i]);
      for (int i=1; i<=100; i++) {
         TF1 *fnom = new TF1(Form("f%i",i),tnp_weight_sta_pp_wrapper,ptminval,30,2);
         fnom->SetParameters(eta,i);
         fnom->SetLineColor(kBlack);
         fnom->Draw("same");
      }
      TF1 *fp = new TF1("fp",tnp_weight_sta_pp_wrapper,ptminval,30,2);
      fp->SetParameters(eta,-1);
      fp->SetLineColor(kBlue);
      fp->Draw("same");
      TF1 *fm = new TF1("fm",tnp_weight_sta_pp_wrapper,ptminval,30,2);
      fm->SetParameters(eta,-2);
      fm->SetLineColor(kBlue);
      fm->Draw("same");
      TF1 *fnom = new TF1("fnom",tnp_weight_sta_pp_wrapper,ptminval,30,2);
      fnom->SetParameters(eta,0);
      fnom->SetLineColor(kRed);
      fnom->Draw("same");

      tleg->SetHeader(Form("#splitline{pp, STA}{#eta #in [%.1f,%.1f], p_{T}>%.1f GeV/c}",etamin[i],etamax[i],ptminval));
      tleg->AddEntry(fnom,"Nominal","l");
      tleg->AddEntry("f1","stat (100 toys)","l");
      tleg->AddEntry(fp,"syst (+/1#sigma)","l");
      tleg->Draw();
      c1->SaveAs(Form("tnp_sta_pp_eta%.1f-%.1f.pdf",etamin[i],etamax[i]));
      c1->SaveAs(Form("tnp_sta_pp_eta%.1f-%.1f.png",etamin[i],etamax[i]));
   }
}
