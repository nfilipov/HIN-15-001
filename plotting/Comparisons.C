// Root stuff
#include "TROOT.h"
#include "TAxis.h"
#include "TCanvas.h"
#include "TDirectory.h"
#include "TFile.h"
#include "TLatex.h"

#include "TMath.h"
#include "TPaveLabel.h"
#include "TPaveText.h"
#include "TStyle.h"
#include "TText.h"

#include "data_raa2015.h"
#include "systematics.C"
#include "CMS_lumi.C"
#include "tdrstyle.C"
// miscellaneous  
#include <fstream>
#include <iostream>

using namespace std;


const TString basedir1 = "~/Desktop/Figures";
const TString basedir2 = "/tmp"; //"~/Documents/PR/forTWiki/CSandRAA"

// colors
Color_t color1Spp = kCyan+1;
Color_t color2Spp = kCyan+2;
Color_t color3Spp = kCyan+3;
Color_t color1Saa = kGreen+2;
Color_t color2Saa = kGreen+3;
Color_t color3Saa = kGreen+4;
Color_t color1Sraa = kOrange+1;
Color_t color2Sraa = kOrange+4;
Color_t color3Sraa = kOrange+3;
 
const  ofstream ofSyst;

const float gTextSize = 0.04;

void Comparisons()
{
  float GreyBox = 0.132;
  float OrangeBox = 0.123;
  float RedBox = 0.137;

  float RAA_1S_npart[8]={1.14,0.761,0.567,0.513,0.447,0.415,0.383,0.31};
  float RAA_1S_nparte[8]={0.206,0.0775,0.0613,0.0445,0.0331,0.0261,0.0311,0.0276};
  float RAA_1S_npartsT[8]={0.341,0.159,0.133,0.103,0.0783,0.0745,0.0723,0.0631}; // tot syst=point+global
  float RAA_1S_nparts[8]={0.313,0.131,0.116,0.084,0.058,0.057,0.057,0.052}; // syst=point

  float RAA_2S_npart[8]={0.220,0.286,0.090,0.074};
  float RAA_2S_nparte[8]={0.145,0.077,0.042,0.044};
  float RAA_2S_npartsT[8]={0.116,0.105,0.055,0.039};
  float RAA_2S_nparts[8]={0.113,0.099,0.054,0.038};

  float nPart8Bins[8]  ={8.75, 42.02, 86.23, 130.06, 187.35, 261.49, 329.48, 381.41};
  float nPart4Bins[4]  ={22.06,108.19,224.30,355.79};

  float binding_3S=0.2; // based on a silly computation, 2M(B)-m(onia)
  float binding_2S=0.54;
  float binding_1S=1.1;

  float RAA_1S_pt[5]= {0.428,0.410,0.450,0.478,0.430};
  float RAA_1S_pte[5]={0.029,0.029,0.034,0.042,0.048};
  float RAA_1S_pts[5]={0.067,0.051,0.053,0.044,0.035};
  float RAA_1S_ptsT[5]={0.090,0.077,0.083,0.080,0.070};

  float RAA_1S_rap[6]={0.421,0.393,0.469,0.476,0.466,0.363};
  float RAA_1S_rape[6]={0.027,0.027,0.032,0.035,0.037,0.055};
  float RAA_1S_raps[6]={0.027,0.033,0.041,0.054,0.067,0.078};
  float RAA_1S_rapsT[6]={0.065,0.064,0.077,0.086,0.094,0.094};

  float RAA_2S_pt[3]=  {0.082,0.066,0.141};
  float RAA_2S_pte[3]= {0.047,0.046,0.011};
  float RAA_2S_pts[3]= {0.018,0.011,0.025};
  float RAA_2S_ptsT[3]={0.018,0.011,0.025};

  float RAA_2S_rap[2]={0.113,0.135};
  float RAA_2S_rape[2]={0.034,0.049};
  float RAA_2S_raps[2]={0.034,0.073};
  float RAA_2S_rapsT[2]={0.034,0.073};

  // set the style
  setTDRStyle();

  TCanvas *cRaapt = new TCanvas("cRaapt","cRaapt"); 
  cRaapt->cd();
  TF1 *f4RaaPt = new TF1("f4RaaPt","1",0,20);
  f4RaaPt->SetLineWidth(0);
  f4RaaPt->SetLineColor(kBlack);
  f4RaaPt->GetXaxis()->SetTitle("p_{T}^{#varUpsilon} (GeV/c)");
  f4RaaPt->GetYaxis()->SetTitle("R_{AA}");
  f4RaaPt->GetXaxis()->SetTitleOffset(f4RaaPt->GetXaxis()->GetTitleOffset()*1.3);
  f4RaaPt->GetXaxis()->SetTitleSize(0.045);
  f4RaaPt->GetYaxis()->SetRangeUser(0.,1.6);
  f4RaaPt->GetXaxis()->CenterTitle(kTRUE);
  f4RaaPt->Draw();
  TGraphErrors *gRaaPt1TNP = new TGraphErrors(nPtBins_2013,pt,RAA_1S_pt,0,RAA_1S_pte);
  gRaaPt1TNP->SetMarkerColor(color1Sraa);
  gRaaPt1TNP->SetMarkerStyle(21);
  gRaaPt1TNP->SetMarkerSize(1.2);
  TGraphErrors *gRaaPt1TNPcircle = new TGraphErrors(nPtBins_2013,pt,RAA_1S_pt,0,RAA_1S_pte);
  gRaaPt1TNPcircle->SetMarkerStyle(25);
  gRaaPt1TNPcircle->SetMarkerSize(1.2);
  gRaaPt1TNPcircle->SetLineColor(kBlack);
  gRaaPt1TNP->Draw("pe");
  gRaaPt1TNPcircle->Draw("p");
  f4RaaPt->Draw("same");

  TGraphErrors *gRaaPt1syst = new TGraphErrors(nPtBins_2013,pt,RAA_1S_pt,pte,RAA_1S_pts);
  gRaaPt1syst->SetLineColor(color1Sraa);
  gRaaPt1syst->SetFillStyle(0);
  gRaaPt1syst->SetLineWidth(2);
  gRaaPt1syst->SetMarkerSize(0);
  gRaaPt1syst->Draw("2");
  
  TGraphErrors *gRaaPt2TNP = new TGraphErrors(nPtBins_2010,pt2010,RAA_2S_pt,0,RAA_2S_pte);
  gRaaPt2TNP->SetMarkerColor(color2Sraa);
  gRaaPt2TNP->SetMarkerStyle(20);
  gRaaPt2TNP->SetMarkerSize(1.2);
  TGraphErrors *gRaaPt2TNPcircle = new TGraphErrors(nPtBins_2010,pt2010,RAA_2S_pt,0,RAA_2S_pte);
  gRaaPt2TNPcircle->SetMarkerStyle(24);
  gRaaPt2TNPcircle->SetMarkerSize(1.2);
  gRaaPt2TNPcircle->SetLineColor(kBlack);
  // gRaaPt2TNP->Draw("pe");
  // gRaaPt2TNPcircle->Draw("p");
  f4RaaPt->Draw("same");
  TGraphErrors *gRaaPt2syst = new TGraphErrors(nPtBins_2010,pt2010,RAA_2S_pt,pt2010e,RAA_2S_pts);
  gRaaPt2syst->SetLineColor(color2Sraa);
  gRaaPt2syst->SetFillStyle(0);
  gRaaPt2syst->SetLineWidth(2);
  gRaaPt2syst->SetMarkerSize(0);
  //  gRaaPt2syst->Draw("2");

  float PT[6];
  float Raa_Y1Spt1[6], Raa_Y1Spt2[6], Raa_Y1Spt3[6];
  ifstream in_1Spt1, in_1Spt2, in_1Spt3;

  ////////
  //Strickland vs Pt.
  ///////

  in_1Spt1.open("strickland-y1pt-gaussian1.dat");
  in_1Spt2.open("strickland-y1pt-gaussian2.dat");
  in_1Spt3.open("strickland-y1pt-gaussian3.dat");
  for (int i=0; i<6; i++) {
    in_1Spt1 >> PT[i] >> Raa_Y1Spt1[i];
    in_1Spt2 >> PT[i] >> Raa_Y1Spt2[i];
    in_1Spt3 >> PT[i] >> Raa_Y1Spt3[i];
  }
  pgStrickland_Ups1S_PT1 = new TGraph(6, PT, Raa_Y1Spt1);
  pgStrickland_Ups1S_PT1->SetLineWidth(2);
  pgStrickland_Ups1S_PT1->SetLineColor(kBlack);
  pgStrickland_Ups1S_PT1->SetLineStyle(1);
  pgStrickland_Ups1S_PT1->Draw("");
  pgStrickland_Ups1S_PT2 = new TGraph(6, PT, Raa_Y1Spt2);
  pgStrickland_Ups1S_PT2->SetLineWidth(2);
  pgStrickland_Ups1S_PT2->SetLineColor(kBlack);
  pgStrickland_Ups1S_PT2->SetLineStyle(2);
  pgStrickland_Ups1S_PT2->Draw("");
  pgStrickland_Ups1S_PT3 = new TGraph(6, PT, Raa_Y1Spt3);
  pgStrickland_Ups1S_PT3->SetLineWidth(2);
  pgStrickland_Ups1S_PT3->SetLineColor(kBlack);
  pgStrickland_Ups1S_PT3->SetLineStyle(3);
  pgStrickland_Ups1S_PT3->Draw("");
  TBox *box = new TBox(19,1-GreyBox,20,1+GreyBox);
  box->SetFillColor(kGray);//color1Sraa);
  box->Draw();
  //Nucl.Phys. A879 (2012) 25-58
  TLegend *legend = new TLegend(0.65,0.68,0.8,0.77);
  legend->SetTextSize(gTextSize);
  legend->SetFillStyle(0);
  legend->SetFillColor(0);
  legend->SetBorderSize(0);
  legend->SetTextFont(42);
  legend->AddEntry(gRaaPt1TNP,"#varUpsilon(1S)","pe");
  //  legend->AddEntry(gRaaPt2TNP,"#varUpsilon(2S)","pe");
  legend->Draw();
  TLegend *leg2= new TLegend(0.65,0.63,0.8,0.7);
  leg2->SetBorderSize(0);
  leg2->SetTextSize(0.036);
  leg2->SetTextFont(42);
  leg2->SetLineColor(0);
  leg2->SetLineStyle(1);
  leg2->SetLineWidth(0.4);
  leg2->SetFillColor(0);
  leg2->SetFillStyle(0);
  leg2->AddEntry(box,"global syst.","f");
  leg3 = new TLegend(0.18,0.7,0.6,0.9);
  leg3->SetBorderSize(0);
  leg3->SetTextSize(0.036);
  leg3->SetTextFont(42);
  leg3->SetLineColor(0);
  leg3->SetLineStyle(1);
  leg3->SetLineWidth(0.4);
  leg3->SetFillColor(0);
  leg3->SetFillStyle(0);
  
  leg3->SetHeader("Nucl.Phys. A879 (2012) 25-58"); // (arXiv:1106.2571)
  leg3->AddEntry(pgStrickland_Ups1S_PT3,"#varUpsilon(1S), 4#pi#eta/s = 3","L");
  leg3->AddEntry(pgStrickland_Ups1S_PT2,"#varUpsilon(1S), 4#pi#eta/s = 2","L");
  leg3->AddEntry(pgStrickland_Ups1S_PT1,"#varUpsilon(1S), 4#pi#eta/s = 1","L");
  leg3->Draw();
  leg2->Draw();
  TLatex latexrap;
  latexrap.SetTextSize(gTextSize);
  latexrap.SetTextFont(42);
  latexrap.DrawLatex(10,0.15,"Cent. 0-100%, |y| < 2.4");
  gPad->RedrawAxis();
  cRaapt->cd();
  CMS_lumi(cRaapt,103,33);
  cRaapt->Update();
  cRaapt->RedrawAxis();
  cRaapt->GetFrame()->Draw();
  cRaapt->SaveAs(basedir1 + TString("/RAA_PT1S_Strickland.pdf"));
  cRaapt->SaveAs(basedir1 + TString("/RAA_PT1S_Strickland.png"));
  cRaapt->SaveAs(basedir2 + TString("/RAA_PT1S_Strickland.pdf"));
  cRaapt->SaveAs(basedir2 + TString("/RAA_PT1S_Strickland.png"));
  //////////
  //Strickland vs. rap
  /////////
  TCanvas *cRaarap = new TCanvas("cRaarap","cRaarap"); 
  cRaarap->cd();
  TF1 *f4RaaRap = new TF1("f4RaaRap","1",0.0,2.4);
  f4RaaRap->SetLineWidth(0);
  f4RaaRap->SetLineColor(kBlack);
  f4RaaRap->GetXaxis()->SetTitle("|y|");
  f4RaaRap->GetYaxis()->SetTitle("R_{AA}");
  f4RaaRap->GetYaxis()->SetRangeUser(0.,1.6);
  f4RaaRap->GetXaxis()->CenterTitle(kTRUE);
  f4RaaRap->GetXaxis()->SetNdivisions(6,8,0,kFALSE);
  f4RaaRap->Draw();
  TGraphErrors *gRaaRap1syst = new TGraphErrors(nRapBins_2014,rap2014,RAA_1S_rap,rap2014e,RAA_1S_raps);
  gRaaRap1syst->SetLineColor(color1Sraa);
  gRaaRap1syst->SetFillStyle(0);
  gRaaRap1syst->SetLineWidth(2);
  gRaaRap1syst->SetMarkerSize(0);
  gRaaRap1syst->Draw("2");
  TGraphErrors *gRaaRap1TNP = new TGraphErrors(nRapBins_2014,rap2014,RAA_1S_rap,0,RAA_1S_rape);
  gRaaRap1TNP->SetMarkerColor(color1Sraa);
  gRaaRap1TNP->SetMarkerStyle(21);
  gRaaRap1TNP->SetMarkerSize(1.2);
  TGraphErrors *gRaaRap1TNPcircle = new TGraphErrors(nRapBins_2014,rap2014,RAA_1S_rap,0,RAA_1S_rape);
  gRaaRap1TNPcircle->SetMarkerStyle(25);
  gRaaRap1TNPcircle->SetMarkerSize(1.2);
  gRaaRap1TNPcircle->SetLineColor(kBlack);
  gRaaRap1TNP->Draw("pe");
  gRaaRap1TNPcircle->Draw("p");
  f4RaaRap->Draw("same");
  float RAP[61];
  float Raa_Y1Srap1[61], Raa_Y1Srap2[61], Raa_Y1Srap3[61];
  ifstream in_1Srap1, in_1Srap2, in_1Srap3;
  in_1Srap1.open("strickland-y1srap-gaussian1.dat");
  in_1Srap2.open("strickland-y1srap-gaussian2.dat");
  in_1Srap3.open("strickland-y1srap-gaussian3.dat");
  for (int i=0; i<61; i++) {
    in_1Srap1 >> RAP[i] >> Raa_Y1Srap1[i];
    in_1Srap2 >> RAP[i] >> Raa_Y1Srap2[i];
    in_1Srap3 >> RAP[i] >> Raa_Y1Srap3[i];
  } 
  pgStrickland_Ups1S_RAP1 = new TGraph(61, RAP, Raa_Y1Srap1);
  pgStrickland_Ups1S_RAP1->SetLineWidth(2);
  pgStrickland_Ups1S_RAP1->SetLineColor(kBlack);
  pgStrickland_Ups1S_RAP1->SetLineStyle(1);
  pgStrickland_Ups1S_RAP1->Draw("");
  pgStrickland_Ups1S_RAP2 = new TGraph(61, RAP, Raa_Y1Srap2);
  pgStrickland_Ups1S_RAP2->SetLineWidth(2);
  pgStrickland_Ups1S_RAP2->SetLineColor(kBlack);
  pgStrickland_Ups1S_RAP2->SetLineStyle(2);
  pgStrickland_Ups1S_RAP2->Draw("");
  pgStrickland_Ups1S_RAP3 = new TGraph(61, RAP, Raa_Y1Srap3);
  pgStrickland_Ups1S_RAP3->SetLineWidth(2);
  pgStrickland_Ups1S_RAP3->SetLineColor(kBlack);
  pgStrickland_Ups1S_RAP3->SetLineStyle(3);
  pgStrickland_Ups1S_RAP3->Draw("");

  TBox *box = new TBox(2.27,1-GreyBox,2.4,1+GreyBox);
  box->SetFillColor(kGray);//color1Sraa);
  box->Draw();
  //Nucl.Phys. A879 (2012) 25-58
  TLegend *legend = new TLegend(0.65,0.68,0.8,0.77);
  legend->SetTextSize(gTextSize);
  legend->SetFillStyle(0);
  legend->SetFillColor(0);
  legend->SetBorderSize(0);
  legend->SetTextFont(42);
  legend->AddEntry(gRaaRap1TNP,"#varUpsilon(1S)","pe");
  //  legend->AddEntry(gRaaPt2TNP,"#varUpsilon(2S)","pe");
  legend->Draw();
  TLegend *leg2= new TLegend(0.65,0.63,0.8,0.7);
  leg2->SetBorderSize(0);
  leg2->SetTextSize(0.036);
  leg2->SetTextFont(42);
  leg2->SetLineColor(0);
  leg2->SetLineStyle(1);
  leg2->SetLineWidth(0.4);
  leg2->SetFillColor(0);
  leg2->SetFillStyle(0);
  leg2->AddEntry(box,"global syst.","f");
  leg3 = new TLegend(0.18,0.7,0.6,0.9);
  leg3->SetBorderSize(0);
  leg3->SetTextSize(0.036);
  leg3->SetTextFont(42);
  leg3->SetLineColor(0);
  leg3->SetLineStyle(1);
  leg3->SetLineWidth(0.4);
  leg3->SetFillColor(0);
  leg3->SetFillStyle(0);
  
leg3->SetHeader("Nucl.Phys. A879 (2012) 25-58"); // (arXiv:1106.2571)
leg3->AddEntry(pgStrickland_Ups1S_RAP3,"#varUpsilon(1S), 4#pi#eta/s = 3","L");
leg3->AddEntry(pgStrickland_Ups1S_RAP2,"#varUpsilon(1S), 4#pi#eta/s = 2","L");
leg3->AddEntry(pgStrickland_Ups1S_RAP1,"#varUpsilon(1S), 4#pi#eta/s = 1","L");
leg3->Draw();
leg2->Draw();
TLatex latexrap;
latexrap.SetTextSize(gTextSize);
latexrap.SetTextFont(42);
latexrap.DrawLatex(1.6,0.15,"Cent. 0-100%");
gPad->RedrawAxis();
cRaarap->cd();
CMS_lumi(cRaarap,103,33);
cRaarap->Update();
cRaarap->RedrawAxis();
cRaarap->GetFrame()->Draw();
cRaarap->SaveAs(basedir1 + TString("/RAA_RAP1S_Strickland.pdf"));
cRaarap->SaveAs(basedir1 + TString("/RAA_RAP1S_Strickland.png"));
cRaarap->SaveAs(basedir2 + TString("/RAA_RAP1S_Strickland.pdf"));
cRaarap->SaveAs(basedir2 + TString("/RAA_RAP1S_Strickland.png"));

  ///////////
  //Strickland vs. nPart
  ///////////

TCanvas *cRaanpart = new TCanvas("cRaanpart", "cRaanpart",423,55,600,600);
  cRaanpart->cd();

    TF1 *f4 = new TF1("f4","1",0,400);
    f4->SetLineWidth(1);
    f4->GetYaxis()->SetRangeUser(0.0,1.6);
    f4->GetXaxis()->SetTitle("N_{Part}");
    f4->GetXaxis()->CenterTitle(true);
    f4->GetYaxis()->SetTitle("R_{AA}");
    f4->SetLineColor(kBlack);
    f4->Draw();
TGraphErrors *gcent1syst = new TGraphErrors(nCentBins_2014,nPart2014,RAA_1S_npart,centErr2014,RAA_1S_nparts); //for fun
gcent1syst->SetLineColor(color1Sraa);
gcent1syst->SetFillStyle(0);
gcent1syst->SetLineWidth(2);
gcent1syst->SetMarkerSize(0);
gcent1syst->Draw("2");
TGraphErrors *gcent1 = new TGraphErrors(nCentBins_2014,nPart2014,RAA_1S_npart,centnoErr,RAA_1S_nparte); //for fun

gcent1->SetMarkerColor(color1Sraa);
gcent1->SetMarkerStyle(21);
gcent1->SetMarkerSize(1.2);

TGraphErrors *gcent1circle = new TGraphErrors(nCentBins_2014,nPart2014,RAA_1S_npart,centnoErr,RAA_1S_nparte);
gcent1circle->SetMarkerStyle(25);
gcent1circle->SetMarkerSize(1.2);
gcent1circle->SetLineColor(kBlack);
gcent1->Draw("pe");
gcent1circle->Draw("p");
f4->Draw("same");
gPad->RedrawAxis();



float NPART[101];
  float Raa_Y1Snpart1[101], Raa_Y1Snpart2[101], Raa_Y1Snpart3[101];
  ifstream in_1Snpart1, in_1Snpart2, in_1Snpart3;
  in_1Snpart1.open("Y1sFull-potb-eta1-npart.dat");
  in_1Snpart2.open("Y1sFull-potb-eta2-npart.dat");
  in_1Snpart3.open("Y1sFull-potb-eta3-npart.dat");
  for (int i=0; i<101; i++) {
    in_1Snpart1 >> NPART[i] >> Raa_Y1Snpart1[i];
    in_1Snpart2 >> NPART[i] >> Raa_Y1Snpart2[i];
    in_1Snpart3 >> NPART[i] >> Raa_Y1Snpart3[i];
  } 
  pgStrickland_Ups1S_NPART1 = new TGraph(101, NPART, Raa_Y1Snpart1);
  pgStrickland_Ups1S_NPART1->SetLineWidth(2);
  pgStrickland_Ups1S_NPART1->SetLineColor(kBlack);
  pgStrickland_Ups1S_NPART1->SetLineStyle(1);
  pgStrickland_Ups1S_NPART1->Draw("");
  pgStrickland_Ups1S_NPART2 = new TGraph(101, NPART, Raa_Y1Snpart2);
  pgStrickland_Ups1S_NPART2->SetLineWidth(2);
  pgStrickland_Ups1S_NPART2->SetLineColor(kBlack);
  pgStrickland_Ups1S_NPART2->SetLineStyle(2);
  pgStrickland_Ups1S_NPART2->Draw("");
  pgStrickland_Ups1S_NPART3 = new TGraph(101, NPART, Raa_Y1Snpart3);
  pgStrickland_Ups1S_NPART3->SetLineWidth(2);
  pgStrickland_Ups1S_NPART3->SetLineColor(kBlack);
  pgStrickland_Ups1S_NPART3->SetLineStyle(3);
  pgStrickland_Ups1S_NPART3->Draw("");

 TBox *box1S = new TBox(385,1-OrangeBox,400,1+OrangeBox);
box1S->SetFillColor(color1Sraa);
box1S->Draw();
  //Nucl.Phys. A879 (2012) 25-58
  TLegend *legend = new TLegend(0.65,0.68,0.8,0.77);
  legend->SetTextSize(gTextSize);
  legend->SetFillStyle(0);
  legend->SetFillColor(0);
  legend->SetBorderSize(0);
  legend->SetTextFont(42);
  legend->AddEntry(gcent1,"#varUpsilon(1S)","pe");
  //  legend->AddEntry(gRaaPt2TNP,"#varUpsilon(2S)","pe");
  legend->Draw();
  TLegend *leg2= new TLegend(0.65,0.63,0.8,0.7);
  leg2->SetBorderSize(0);
  leg2->SetTextSize(0.036);
  leg2->SetTextFont(42);
  leg2->SetLineColor(0);
  leg2->SetLineStyle(1);
  leg2->SetLineWidth(0.4);
  leg2->SetFillColor(0);
  leg2->SetFillStyle(0);
  leg2->AddEntry(box1S,"global syst.","f");
  leg3 = new TLegend(0.2,0.7,0.6,0.9);
  leg3->SetBorderSize(0);
  leg3->SetTextSize(0.036);
  leg3->SetTextFont(42);
  leg3->SetLineColor(0);
  leg3->SetLineStyle(1);
  leg3->SetLineWidth(0.4);
  leg3->SetFillColor(0);
  leg3->SetFillStyle(0);
  
leg3->SetHeader("Nucl.Phys. A879 (2012) 25-58"); // (arXiv:1106.2571)
leg3->AddEntry(pgStrickland_Ups1S_NPART3,"#varUpsilon(1S), 4#pi#eta/s = 3","L");
leg3->AddEntry(pgStrickland_Ups1S_NPART2,"#varUpsilon(1S), 4#pi#eta/s = 2","L");
leg3->AddEntry(pgStrickland_Ups1S_NPART1,"#varUpsilon(1S), 4#pi#eta/s = 1","L");
leg3->Draw();
leg2->Draw();

  // |y| < 2.4
    TLatex latexrap;
    latexrap.SetTextSize(gTextSize);
    latexrap.SetTextFont(42);
    latexrap.DrawLatex(30,0.2,"|y| < 2.4");


gPad->RedrawAxis();
cRaanpart->cd();
CMS_lumi(cRaanpart,103,33);
cRaanpart->Update();
cRaanpart->RedrawAxis();
cRaanpart->GetFrame()->Draw();
cRaanpart->SaveAs(basedir1 + TString("/RAA_NPART1S_Strickland.pdf"));
cRaanpart->SaveAs(basedir1 + TString("/RAA_NPART1S_Strickland.png"));
cRaanpart->SaveAs(basedir2 + TString("/RAA_NPART1S_Strickland.pdf"));
cRaanpart->SaveAs(basedir2 + TString("/RAA_NPART1S_Strickland.png"));


      // TBox *box2S = new TBox(385,1-syst2S_pp_centGlob4,400,1+syst2S_pp_centGlob4);
      // box2S->SetFillColor(color2Sraa);
      // box2S->Draw();
      // cout << "Syst2S_pp_cent_glob = " << syst2S_pp_centGlob4 << endl;

}

