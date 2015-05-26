#include "tnp_weight.h"

void draw_variations_pbpb_midrap()
{
   TCanvas *c1 = new TCanvas();
   TH1F *haxes = new TH1F("haxes","haxes",10,2,10);
   haxes->GetYaxis()->SetRangeUser(0,2);
   haxes->Draw();

   for (int i=100; i>=0; i--)
   {
      TF1 *func = new TF1(Form("var_%i",i),Form("tnp_weight_pbpb_midrap(x,%i)",i),2,10);
      if (i==0) func->SetLineColor(kRed);
      else func->SetLineColor(kBlack);
      func->Draw("same");
   }
}

void draw_variations_pp_midrap()
{
   TCanvas *c1 = new TCanvas();
   TH1F *haxes = new TH1F("haxes","haxes",10,2,10);
   haxes->GetYaxis()->SetRangeUser(0,2);
   haxes->Draw();

   for (int i=100; i>=0; i--)
   {
      TF1 *func = new TF1(Form("var_%i",i),Form("tnp_weight_pp_midrap(x,%i)",i),2,10);
      if (i==0) func->SetLineColor(kRed);
      else func->SetLineColor(kBlack);
      func->Draw("same");
   }
}

void draw_variations_pbpb_fwdrap()
{
   TCanvas *c1 = new TCanvas();
   TH1F *haxes = new TH1F("haxes","haxes",10,2,10);
   haxes->GetYaxis()->SetRangeUser(0,2);
   haxes->Draw();

   for (int i=100; i>=0; i--)
   {
      TF1 *func = new TF1(Form("var_%i",i),Form("tnp_weight_pbpb_fwdrap(x,%i)",i),2,10);
      if (i==0) func->SetLineColor(kRed);
      else func->SetLineColor(kBlack);
      func->Draw("same");
   }
}

void draw_variations_pp_fwdrap()
{
   TCanvas *c1 = new TCanvas();
   TH1F *haxes = new TH1F("haxes","haxes",10,2,10);
   haxes->GetYaxis()->SetRangeUser(0,2);
   haxes->Draw();

   for (int i=100; i>=0; i--)
   {
      TF1 *func = new TF1(Form("var_%i",i),Form("tnp_weight_pp_fwdrap(x,%i)",i),2,10);
      if (i==0) func->SetLineColor(kRed);
      else func->SetLineColor(kBlack);
      func->Draw("same");
   }
}
