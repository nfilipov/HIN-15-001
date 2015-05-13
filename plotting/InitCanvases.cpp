//#include "TCanvas.h"
void InitCanvases (TCanvas& canvas_ , bool pt, bool rap)
{
  // TCanvas *canvas_ = new TCanvas();
  canvas_.cd();
  canvas_.Draw();
  TPad *prapcent = new TPad("prapcent","prapcent",0.0,0.0,1.0,1.0);
  prapcent->SetBottomMargin(0.12);
  prapcent->SetTopMargin(0.03);
  prapcent->SetRightMargin(0.03);
  prapcent->SetLeftMargin(0.16);
  prapcent->Draw();
  prapcent->cd();
  //one pad to draw RaaPt!
  if(pt){
    if(!doControlPlots){
      TF1 *f4RaaPt = new TF1("f4RaaPt","1",0,42);
      f4RaaPt->SetLineWidth(0);
      f4RaaPt->GetXaxis()->SetTitle("p_{T}");
      f4RaaPt->GetYaxis()->SetTitle("R_{AA}");
      f4RaaPt->GetYaxis()->SetTitleOffset(1.8);
      f4RaaPt->GetYaxis()->SetTitleSize(0.028);
      f4RaaPt->GetYaxis()->SetRangeUser(0.,1.3);
      f4RaaPt->GetXaxis()->CenterTitle(kTRUE);
      f4RaaPt->Draw();
    }else{
      TF1 *f4significance = new TF1("f4significance","0",0,pt15[5]);
      f4significance->SetLineWidth(0);
      f4significance->GetXaxis()->SetTitle("p_{T}");
      f4significance->GetYaxis()->SetTitle("N_{FIT}/err_{Nfit}");
      f4significance->GetYaxis()->SetTitleOffset(1.8);
      f4significance->GetYaxis()->SetTitleSize(0.028);
      f4significance->GetYaxis()->SetRangeUser(0.,35);
      f4significance->GetXaxis()->CenterTitle(kTRUE);
      f4significance->Draw();
    }
  }
  if(rap){
    if(!doControlPlots){
      TF1 *f4RaaRap = new TF1("f4RaaRap","1",0,42);
      f4RaaRap->SetLineWidth(0);
      f4RaaRap->GetXaxis()->SetTitle("|y|");
      f4RaaRap->GetYaxis()->SetTitle("R_{AA}");
      f4RaaRap->GetYaxis()->SetTitleOffset(1.8);
      f4RaaRap->GetYaxis()->SetTitleSize(0.028);
      f4RaaRap->GetYaxis()->SetRangeUser(0.,1.3);
      f4RaaRap->GetXaxis()->CenterTitle(kTRUE);
      f4RaaRap->Draw();
    }else{
      TF1 *f4significance = new TF1("f4significance","0",0,rap2014[5]);
      f4significance->SetLineWidth(0);
      f4significance->GetXaxis()->SetTitle("|y|");
      f4significance->GetYaxis()->SetTitle("N_{FIT}/err_{Nfit}");
      f4significance->GetYaxis()->SetTitleOffset(1.8);
      f4significance->GetYaxis()->SetTitleSize(0.028);
      f4significance->GetYaxis()->SetRangeUser(0.,35);
      f4significance->GetXaxis()->CenterTitle(kTRUE);
      f4significance->Draw();
    }
  }
}
