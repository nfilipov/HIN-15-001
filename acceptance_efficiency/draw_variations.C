#include "tnp_weight.h"
#include "tnp_weight_statonly.h"

void draw_variations_muidtrg_pbpb(int ieta, bool plotAll, int stamode, bool statonly=false)
{
   // ieta = 0 (0-0.9), 1 (0.9-1.6), 2 (1.6-2.1), 3 (2.1-2.4)
   // plotAll: plot 100 variations for muid+trg if true, plot only +1/-1 sigma if false
   // stamode: 0 -> no STA correction, 1 -> correct only variations (for plotAll=false), 2 -> correct nominal and variations
   // statonly: false -> stat+syst variations, true -> stat only variations

   const char* statonly_str = statonly ? "_statonly" : "";

   double eta;
   double ptmin = 0;
   if (ieta==0) {ptmin = 3.4; eta=0.3;}
   else if (ieta==1) {ptmin = 2.1; eta=1.2;}
   else if (ieta==2) {ptmin = 1.7; eta=1.9;}
   else {ptmin = 1.5; eta=2.3;}
   TCanvas *c1 = new TCanvas();
   TH1F *haxes = new TH1F("haxes","haxes",10,0,20);
   haxes->GetYaxis()->SetRangeUser(0.8,1.5);
   haxes->GetXaxis()->SetTitle("p_{T}");
   haxes->GetYaxis()->SetTitle("Correction");
   haxes->Draw();

   TLegend *tleg = new TLegend(0.55,0.5,0.9,0.83);
   tleg->SetFillStyle(0);
   tleg->SetFillColor(0);
   tleg->SetBorderSize(0);
   tleg->SetTextSize(0.035);
   if (ieta==0) tleg->SetHeader("MuId+Trg #eta^{#mu} #in [0.0, 0.9]");
   else if (ieta==1) tleg->SetHeader("MuId+Trg #eta^{#mu} #in [0.9, 1.6]");
   else if (ieta==2) tleg->SetHeader("MuId+Trg #eta^{#mu} #in [1.6, 2.1]");
   else tleg->SetHeader("MuId+Trg #eta^{#mu} #in [2.1, 2.4]");

   int istart, istep;
   if (plotAll) {
      istart = 100; istep = -1;
   } else {
      istart = -2; istep = 1;
   }
   for (int i=istart; i*istep<=0; i += istep)
   {
      TF1 *func = new TF1(Form("var_%i",i),Form("tnp_weight%s_muidtrg_pbpb(x,%f,%i)",statonly_str,eta,i),ptmin,20);
      if (stamode==2) func = new TF1(Form("var_%i",i),Form("tnp_weight%s_muidtrg_pbpb(x,%f,%i)*tnp_weight%s_sta_pbpb(x,%f,0)",statonly_str,eta,i,statonly_str,eta),ptmin,20);
      if (i==0) func->SetLineColor(kRed);
      else func->SetLineColor(kBlack);
      func->Draw("same");

      if (i==0) {
         if (stamode==2) tleg->AddEntry(func,"nominal * STA","l");
         else tleg->AddEntry(func,"nominal","l");
      } else if (abs(i)==1) {
         if (stamode==2) tleg->AddEntry(func,"variation * STA","l");
         else tleg->AddEntry(func,"variation","l");
      }
   }
   if (stamode==1 && !plotAll) {
      TF1 *func1 = new TF1("var1_0",Form("tnp_weight%s_muidtrg_pbpb(x,%f,0)*tnp_weight%s_sta_pbpb(x,%f,0)",statonly_str,eta,statonly_str,eta),ptmin,20);
      func1->SetLineColor(kBlue);
      func1->Draw("same");
      tleg->AddEntry(func1,"nominal * STA", "l");
      TF1 *func2 = new TF1("var2_0",Form("tnp_weight%s_muidtrg_pbpb(x,%f,0)/tnp_weight%s_sta_pbpb(x,%f,0)",statonly_str,eta,statonly_str,eta),ptmin,20);
      func2->SetLineColor(kBlue);
      func2->Draw("same");
   }

   tleg->Draw();

   TLatex *lt1 = new TLatex(); lt1->SetNDC();
   lt1->SetTextSize(0.05);
   lt1->DrawLatex(0.55,0.86,"PbPb  #sqrt{s_{NN}} = 2.76 TeV");
}

void draw_variations_muidtrg_pp(int ieta, bool plotAll, double stamode, bool statonly=false)
{
   // ieta = 0 (0-0.9), 1 (0.9-1.6), 2 (1.6-2.1), 3 (2.1-2.4)
   // plotAll: plot 100 variations for muid+trg if true, plot only +1/-1 sigma if false
   // stamode: 0 -> no STA correction, 1 -> correct only variations (for plotAll=false), 2 -> correct nominal and variations
   // statonly: false -> stat+syst variations, true -> stat only variations

   const char* statonly_str = statonly ? "_statonly" : "";

   double eta;
   double ptmin = 0;
   if (ieta==0) {ptmin = 3.4; eta=0.3;}
   else if (ieta==1) {ptmin = 2.1; eta=1.2;}
   else if (ieta==2) {ptmin = 1.7; eta=1.9;}
   else {ptmin = 1.5; eta=2.3;}
   TCanvas *c1 = new TCanvas();
   TH1F *haxes = new TH1F("haxes","haxes",10,0,20);
   haxes->GetYaxis()->SetRangeUser(0.8,1.5);
   haxes->GetXaxis()->SetTitle("p_{T}");
   haxes->GetYaxis()->SetTitle("Correction");
   haxes->Draw();

   TLegend *tleg = new TLegend(0.55,0.5,0.9,0.83);
   tleg->SetFillStyle(0);
   tleg->SetFillColor(0);
   tleg->SetBorderSize(0);
   tleg->SetTextSize(0.035);
   if (ieta==0) tleg->SetHeader("MuId+Trg #eta^{#mu} #in [0.0, 0.9]");
   else if (ieta==1) tleg->SetHeader("MuId+Trg #eta^{#mu} #in [0.9, 1.6]");
   else if (ieta==2) tleg->SetHeader("MuId+Trg #eta^{#mu} #in [1.6, 2.1]");
   else tleg->SetHeader("MuId+Trg #eta^{#mu} #in [2.1, 2.4]");

   int istart, istep;
   if (plotAll) {
      istart = 100; istep = -1;
   } else {
      istart = -2; istep = 1;
   }
   for (int i=istart; i*istep<=0; i += istep)
   {
      TF1 *func = new TF1(Form("var_%i",i),Form("tnp_weight%s_muidtrg_pp(x,%f,%i)",statonly_str,eta,i),ptmin,20);
      if (stamode==2) func = new TF1(Form("var_%i",i),Form("tnp_weight%s_muidtrg_pp(x,%f,%i)*tnp_weight%s_sta_pp(x,%f,0)",statonly_str,eta,i,statonly_str,eta),ptmin,20);
      if (i==0) func->SetLineColor(kRed);
      else func->SetLineColor(kBlack);
      func->Draw("same");

      if (i==0) {
         if (stamode==2) tleg->AddEntry(func,"nominal * STA","l");
         else tleg->AddEntry(func,"nominal","l");
      } else if (abs(i)==1) {
         if (stamode==2) tleg->AddEntry(func,"variation * STA","l");
         else tleg->AddEntry(func,"variation","l");
      }
   }
   if (stamode==1 && !plotAll) {
      TF1 *func1 = new TF1("var1_0",Form("tnp_weight%s_muidtrg_pp(x,%f,0)*tnp_weight%s_sta_pp(x,%f,0)",statonly_str,eta,statonly_str,eta),ptmin,20);
      func1->SetLineColor(kBlue);
      func1->Draw("same");
      tleg->AddEntry(func1,"nominal * STA", "l");
      TF1 *func2 = new TF1("var2_0",Form("tnp_weight%s_muidtrg_pp(x,%f,0)/tnp_weight%s_sta_pp(x,%f,0)",statonly_str,eta,statonly_str,eta),ptmin,20);
      func2->SetLineColor(kBlue);
      func2->Draw("same");
   }

   tleg->Draw();

   TLatex *lt1 = new TLatex(); lt1->SetNDC();
   lt1->SetTextSize(0.05);
   lt1->DrawLatex(0.55,0.86,"pp  #sqrt{s} = 2.76 TeV");
}

void draw_variations_sta_pbpb(int ieta, bool plotAll, bool statonly=false)
{
   // ieta = 0 (0-1.6), 1 (1.6-2.4)
   // plotAll: plot 100 variations for muid+trg if true, plot only +1/-1 sigma if false
   // statonly: false -> stat+syst variations, true -> stat only variations

   const char* statonly_str = statonly ? "_statonly" : "";

   double eta;
   double ptmin = 0;
   if (ieta==0) {ptmin = 2.1; eta=0.3;}
   else {ptmin = 1.5; eta=2.3;}
   TCanvas *c1 = new TCanvas();
   TH1F *haxes = new TH1F("haxes","haxes",10,0,20);
   haxes->GetYaxis()->SetRangeUser(0.8,1.5);
   haxes->GetXaxis()->SetTitle("p_{T}");
   haxes->GetYaxis()->SetTitle("Correction");
   haxes->Draw();

   TLegend *tleg = new TLegend(0.55,0.5,0.9,0.83);
   tleg->SetFillStyle(0);
   tleg->SetFillColor(0);
   tleg->SetBorderSize(0);
   tleg->SetTextSize(0.035);
   if (ieta==0) tleg->SetHeader("STA #eta^{#mu} #in [0.0, 0.9]");
   else if (ieta==1) tleg->SetHeader("STA #eta^{#mu} #in [0.9, 1.6]");
   else if (ieta==2) tleg->SetHeader("STA #eta^{#mu} #in [1.6, 2.1]");
   else tleg->SetHeader("STA #eta^{#mu} #in [2.1, 2.4]");

   int istart, istep;
   if (plotAll) {
      istart = 100; istep = -1;
   } else {
      istart = -2; istep = 1;
   }
   for (int i=istart; i*istep<=0; i += istep)
   {
      TF1 *func = new TF1(Form("var_%i",i),Form("tnp_weight%s_sta_pbpb(x,%f,%i)",statonly_str,eta,i),ptmin,20);
      if (i==0) func->SetLineColor(kRed);
      else func->SetLineColor(kBlack);
      func->Draw("same");

      if (i==0) {
         tleg->AddEntry(func,"nominal","l");
      } else if (abs(i)==1) {
         tleg->AddEntry(func,"variation","l");
      }
   }

   tleg->Draw();

   TLatex *lt1 = new TLatex(); lt1->SetNDC();
   lt1->SetTextSize(0.05);
   lt1->DrawLatex(0.55,0.86,"PbPb  #sqrt{s_{NN}} = 2.76 TeV");
}

void draw_variations_sta_pp(int ieta, bool plotAll, bool statonly=false)
{
   // ieta = 0 (0-1.6), 1 (1.6-2.4)
   // plotAll: plot 100 variations for muid+trg if true, plot only +1/-1 sigma if false
   // statonly: false -> stat+syst variations, true -> stat only variations

   const char* statonly_str = statonly ? "_statonly" : "";

   double eta;
   double ptmin = 0;
   if (ieta==0) {ptmin = 2.1; eta=0.3;}
   else {ptmin = 1.5; eta=2.3;}
   TCanvas *c1 = new TCanvas();
   TH1F *haxes = new TH1F("haxes","haxes",10,0,20);
   haxes->GetYaxis()->SetRangeUser(0.8,1.5);
   haxes->GetXaxis()->SetTitle("p_{T}");
   haxes->GetYaxis()->SetTitle("Correction");
   haxes->Draw();

   TLegend *tleg = new TLegend(0.55,0.5,0.9,0.83);
   tleg->SetFillStyle(0);
   tleg->SetFillColor(0);
   tleg->SetBorderSize(0);
   tleg->SetTextSize(0.035);
   if (ieta==0) tleg->SetHeader("STA #eta^{#mu} #in [0.0, 0.9]");
   else if (ieta==1) tleg->SetHeader("STA #eta^{#mu} #in [0.9, 1.6]");
   else if (ieta==2) tleg->SetHeader("STA #eta^{#mu} #in [1.6, 2.1]");
   else tleg->SetHeader("STA #eta^{#mu} #in [2.1, 2.4]");

   int istart, istep;
   if (plotAll) {
      istart = 100; istep = -1;
   } else {
      istart = -2; istep = 1;
   }
   for (int i=istart; i*istep<=0; i += istep)
   {
      TF1 *func = new TF1(Form("var_%i",i),Form("tnp_weight%s_sta_pp(x,%f,%i)",statonly_str,eta,i),ptmin,20);
      if (i==0) func->SetLineColor(kRed);
      else func->SetLineColor(kBlack);
      func->Draw("same");

      if (i==0) {
         tleg->AddEntry(func,"nominal","l");
      } else if (abs(i)==1) {
         tleg->AddEntry(func,"variation","l");
      }
   }

   tleg->Draw();

   TLatex *lt1 = new TLatex(); lt1->SetNDC();
   lt1->SetTextSize(0.05);
   lt1->DrawLatex(0.55,0.86,"pp  #sqrt{s} = 2.76 TeV");
}


