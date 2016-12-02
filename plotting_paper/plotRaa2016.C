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
#include "TGraphErrors.h"
#include "TGraphAsymmErrors.h"
#include "TF1.h"
#include "TLegend.h"
#include "TFrame.h"
#include "TH1F.h"
#include "TArrow.h"

#include "data_raa2015.h"
//#include "systematics.C"
#include "recomputeSyst.C"
#include "CMS_lumi.C"
#include "tdrstyle.C"
#include "data_raaSyst.h"
#include "RAA2016.h"
// miscellaneous  
#include <fstream>
#include <iostream>

//using namespace std;

/// we will:
// - print syst in tables including the global scale (although its redundant)
// - print the CS and RAA uncertainties in tables in the format: stat +/- syst +/- global (instead of the syst total with the global part in parenthesis)
// - plot the CS and RAA uncertainties with point-dependent systematics in boxes. The boxes are at the moment only drawn in RAA plots. Global  uncertainties in Cross sections are only mentioned in the plot description. For RAA plots, The global scale is represented as a box at unity if the plotBox boolean is true, otherwise it's a text on the plot, saying " global unc. = XX% "
const bool plotBox =true;
const bool plotLin=true; // plot linear plots as well

const TString basedir1 = "~/Desktop/figs";
const TString basedir2 = "/tmp"; //"~/Documents/PR/forTWiki/CSandRAA"
const string outSyst = "FinalSystFile.txt";
const string outRes = "FinalResultFile.txt";
const string outplot = "RAA2016.h";
// colors
Color_t color1Spp = kCyan-3;
Color_t color2Spp = kBlue+1;
Color_t color3Spp = kBlue+4;
Color_t color1Saa = kRed+1;
Color_t color2Saa = kRed+4;
Color_t color3Saa = kRed+3; // change the colour to GOLD when you observe it :D
Color_t color1Sraa = kRed+1;
Color_t color2Sraa = kRed+4;
Color_t color3Sraa = kRed+3;
Color_t ALICE = kGray+3;
Color_t STAR = kGray;
Color_t STARU = kBlue+1;

int symbol1S = 21; // filled square
int symbol1Sc = 25;// open square
int symbol2S = 20; // filled circle
int symbol2Sc = 24;// open circle
int symbol3S = 22; // filled triangle
int symbol3Sc = 26;// open triangle

int filledCross = 34;
int openCrosss = 28;
int filledStar = 29;
int openStar = 30;

const float gTextSize = 0.042;
const float markerSize = 1.4;
const float xfrac = 0.85;

float computeRatio(float x, float y) ;
float computeRatioError(float x, float y, float xerr, float yerr);
void plotComparisons(bool exp, int plug);

void plotRaa2016()
{
  setTDRStyle();
  std::ofstream ofplot;
  std::ofstream ofRes;
  std::ofstream ofSyst;
  ofplot.open(outplot.c_str(), ios_base::out);  //open the out stream for c-header formatted results
  ofRes.open(outRes.c_str(), ios_base::out);  //open the out stream for full results.
  ofSyst.open(outSyst.c_str(), ios_base::out);  //open the out stream for syst results.
  // global scale uncertainties: pp luminosity, minbias efficiency, nuclear overlap function. tracking is coded in the header.
  float syst_lumi=L_pp_e;
  float syst_nmb=N_MB_e;
  float syst_taa=T_AA_e;
  ///===============================
  /// pp cross sections vs Pt in fine bins (of course)
  ///===============================
  /// 1. Define variables
  /// 2. Define syst variables
  /// 3. Compute the syst
  /// 4. Compute the CS.
  /// 5. Print the outputs
  /// 6. Draw and save
  ///-------------------------------
  /// 1.a. Y(1S)
  float CS1S_pp_tnp_pt[nPtBins_2013] = {};
  float CS1S_pp_tnp_pte[nPtBins_2013] = {};
  float CS1S_pp_tnp_pts[nPtBins_2013] = {};
  /// 1.b. Y(2S)
  float CS2S_pp_tnp_pt[nPtBins_2013] = {};
  float CS2S_pp_tnp_pte[nPtBins_2013] = {};
  float CS2S_pp_tnp_pts[nPtBins_2013] = {};
  /// 1.c Y(3S)
  float CS3S_pp_tnp_pt[nPtBins_2013] = {};
  float CS3S_pp_tnp_pte[nPtBins_2013] = {};
  float CS3S_pp_tnp_pts[nPtBins_2013] = {};
  /// 2.a Y(1S)
  float stat1S_pp_pt[nPtBins_2013]={}; //stat. pp relative uncertainty (contributing to R_AA as a pt to pt syst. uncertainty!
  float syst1S_pptnp_pt[nPtBins_2013]={};// tnp uncertainty
  float syst1S_pp_pt[nPtBins_2013]={};   //fit syst. uncertainty.
  float syst1S_ppgs_pt[nPtBins_2013]={};   //gen shape
  float syst1S_ppsta_pt[nPtBins_2013]={}; ///sta uncertainty
  float syst1S_ppmuid_pt[nPtBins_2013]={};/// muid uncertainty
  float syst1S_cspp_pt[nPtBins_2013]={}; /// quadratic sum.
  /// 2.b Y(2S)
  float stat2S_pp_pt[nPtBins_2013]={}; //stat. pp relative uncertainty (contributing to R_AA as a pt to pt syst. uncertainty!
  float syst2S_pptnp_pt[nPtBins_2013]={};// tnp uncertainty
  float syst2S_pp_pt[nPtBins_2013]={};   //fit syst. uncertainty.
  float syst2S_ppgs_pt[nPtBins_2013]={};   //gen shape
  float syst2S_ppsta_pt[nPtBins_2013]={}; ///sta uncertainty
  float syst2S_ppmuid_pt[nPtBins_2013]={};/// muid uncertainty
  float syst2S_cspp_pt[nPtBins_2013]={}; /// quadratic sum.
  /// 2.c Y(3S)
  float stat3S_pp_pt[nPtBins_2013]={}; //stat. pp relative uncertainty (contributing to R_AA as a pt to pt syst. uncertainty!
  float syst3S_pptnp_pt[nPtBins_2013]={};// tnp uncertainty
  float syst3S_pp_pt[nPtBins_2013]={};   //fit syst. uncertainty.
  float syst3S_ppgs_pt[nPtBins_2013]={};   //gen shape
  float syst3S_ppsta_pt[nPtBins_2013]={}; ///sta uncertainty
  float syst3S_ppmuid_pt[nPtBins_2013]={};/// muid uncertainty
  float syst3S_cspp_pt[nPtBins_2013]={}; /// quadratic sum.
  /// 3.
  /// NOTE:
  /// The systXS_cspp, just as the systXS_csaa/raa, will NOT include the global scale uncertainties anymore (this makes them bigger for no reason). Then the global is computed once and simply multiplied to CSXS_pp/aa or RAA_XS in the printed tables (no more parentheses).
  float systXS_pp_glob = sqrt(pow(tracking_pp,2)+pow(syst_lumi,2));
  
  syst1S_pp_pt[0]=ppAlphaSyst(N1S_pp_pt3p5[0],N1S_pp_pt3p5s_2p5,N1B_pp_pt3p5s_2p5,N1S_pp_pt3p5[0],N1S_pp_pt3p5s_2p5[1]);   
  syst1S_pp_pt[1]=ppAlphaSyst(N1S_pp_pt3p5[1],N1S_pp_pt3p5s_5,N1B_pp_pt3p5s_5,N1S_pp_pt3p5[1],N1S_pp_pt3p5s_5[1]);	    
  syst1S_pp_pt[2]=ppAlphaSyst(N1S_pp_pt3p5[2],N1S_pp_pt3p5s_8,N1B_pp_pt3p5s_8,N1S_pp_pt3p5[2],N1S_pp_pt3p5s_8[1]);	    
  syst1S_pp_pt[3]=ppAlphaSyst(N1S_pp_pt3p5[3],N1S_pp_pt3p5s_12,N1B_pp_pt3p5s_12,N1S_pp_pt3p5[3],N1S_pp_pt3p5s_12[1]);      
  syst1S_pp_pt[4]=ppAlphaSyst(N1S_pp_pt3p5[4],N1S_pp_pt3p5s_20,N1B_pp_pt3p5s_20,N1S_pp_pt3p5[4],N1S_pp_pt3p5s_20[1]);
  ///
  syst2S_pp_pt[0]=ppAlphaSyst(N2S_pp_pt4_2013[0],N2S_pp_pt4s_2p5,N2B_pp_pt4s_2p5,N2S_pp_pt4_2013[0],N2S_pp_pt4s_2p5[1]);
  syst2S_pp_pt[1]=ppAlphaSyst(N2S_pp_pt4_2013[1],N2S_pp_pt4s_5,N2B_pp_pt4s_5,N2S_pp_pt4_2013[1],N2S_pp_pt4s_5[1]);
  syst2S_pp_pt[2]=ppAlphaSyst(N2S_pp_pt4_2013[2],N2S_pp_pt4s_8,N2B_pp_pt4s_8,N2S_pp_pt4_2013[2],N2S_pp_pt4s_8[1]);
  syst2S_pp_pt[3]=ppAlphaSyst(N2S_pp_pt4_2013[3],N2S_pp_pt4s_12,N2B_pp_pt4s_12,N2S_pp_pt4_2013[3],N2S_pp_pt4s_12[1]); 	   
  syst2S_pp_pt[4]=ppAlphaSyst(N2S_pp_pt4_2013[4],N2S_pp_pt4s_20,N2B_pp_pt4s_20,N2S_pp_pt4_2013[4],N2S_pp_pt4s_20[1]); 
  ///
  syst3S_pp_pt[0]=ppAlphaSyst(N3S_pp_pt4_2013[0],N3S_pp_pt4s_2p5,N3B_pp_pt4s_2p5,N3S_pp_pt4_2013[0],N3S_pp_pt4s_2p5[1]); 
  syst3S_pp_pt[1]=ppAlphaSyst(N3S_pp_pt4_2013[1],N3S_pp_pt4s_5,N3B_pp_pt4s_5,N3S_pp_pt4_2013[1],N3S_pp_pt4s_5[1]);
  syst3S_pp_pt[2]=ppAlphaSyst(N3S_pp_pt4_2013[2],N3S_pp_pt4s_8,N3B_pp_pt4s_8,N3S_pp_pt4_2013[2],N3S_pp_pt4s_8[1]); 
  syst3S_pp_pt[3]=ppAlphaSyst(N3S_pp_pt4_2013[3],N3S_pp_pt4s_12,N3B_pp_pt4s_12,N3S_pp_pt4_2013[3],N3S_pp_pt4s_12[1]); 
  syst3S_pp_pt[4]=ppAlphaSyst(N3S_pp_pt4_2013[4],N3S_pp_pt4s_20,N3B_pp_pt4s_20,N3S_pp_pt4_2013[4],N3S_pp_pt4s_20[1]);  
 
  for(int i = 0 ; i<nPtBins_2013 ; i++)
    {
      stat1S_pp_pt[i]=N1S_pp_pt3p5e[i]/N1S_pp_pt3p5[i];
      syst1S_pptnp_pt[i]=Aet_1S_pythia_pt_fulls[i]/Aet_1S_pythia_pt_STA[i]; //fulls is the full tnp syst (muidtrg+sta added in quadrature)
      syst1S_ppgs_pt[i]=Aet_1S_pythia_pt_STAe[i]/Aet_1S_pythia_pt_STA[i]; // doesnt matter if we use STA or MuID
      syst1S_ppsta_pt[i]=Aet_1S_pythia_pt_STAs[i]/Aet_1S_pythia_pt_STA[i];
      syst1S_ppmuid_pt[i]=Aet_1S_pythia_pt_muIDTrigs[i]/Aet_1S_pythia_pt_muIDTrig[i];
      syst1S_cspp_pt[i]=sqrt(syst1S_pptnp_pt[i]*syst1S_pptnp_pt[i]+syst1S_pp_pt[i]*syst1S_pp_pt[i]+pow(syst1S_ppgs_pt[i],2));
      //2S
      stat2S_pp_pt[i]=N2S_pp_pt4_2013e[i]/N2S_pp_pt4_2013[i];
      syst2S_pptnp_pt[i]=Aet_2S_pythia_pt2013s[i]/Aet_2S_pythia_pt2013[i];
      syst2S_ppgs_pt[i]=Aet_2S_pythia_pt2013e[i]/Aet_2S_pythia_pt2013[i]; // doesnt matter if we use STA or MuID
      syst2S_ppsta_pt[i]=Aet_2S_pythia_pt2013_STAe[i]/Aet_2S_pythia_pt2013[i];
      syst2S_ppmuid_pt[i]=Aet_2S_pythia_pt2013_muIDTrige[i]/Aet_2S_pythia_pt2013[i];
      syst2S_cspp_pt[i]=sqrt(syst2S_pptnp_pt[i]*syst2S_pptnp_pt[i]+syst2S_pp_pt[i]*syst2S_pp_pt[i]+pow(syst2S_ppgs_pt[i],2));
      //3S
      stat3S_pp_pt[i]=N3S_pp_pt4_2013e[i]/N3S_pp_pt4_2013[i];
      syst3S_pptnp_pt[i]=Aet_3S_pythia_pt2013s[i]/Aet_3S_pythia_pt2013[i];
      syst3S_ppgs_pt[i]=Aet_3S_pythia_pt2013e[i]/Aet_3S_pythia_pt2013[i]; // doesnt matter if we use STA or MuID
      syst3S_ppsta_pt[i]=Aet_3S_pythia_pt2013_STAe[i]/Aet_3S_pythia_pt2013[i];
      syst3S_ppmuid_pt[i]=Aet_3S_pythia_pt2013_muIDTrige[i]/Aet_3S_pythia_pt2013[i];
      syst3S_cspp_pt[i]=sqrt(syst3S_pptnp_pt[i]*syst3S_pptnp_pt[i]+syst3S_pp_pt[i]*syst3S_pp_pt[i]+pow(syst3S_ppgs_pt[i],2));

    }
  /// 4.
  for(int i = 0 ; i<nPtBins_2013 ; i++)
    {
      CS1S_pp_tnp_pt[i]= computeRatio( N1S_pp_pt3p5[i] , Aet_1S_pythia_pt_STA[i] )/(L_pp_invNb*RapBinWidth*deltaPt[i]);   
      CS1S_pp_tnp_pte[i] = computeRatioError( N1S_pp_pt3p5[i] , Aet_1S_pythia_pt_STA[i], N1S_pp_pt3p5e[i] ,0)/(L_pp_invNb*RapBinWidth*deltaPt[i]) ; 
      CS1S_pp_tnp_pts[i] = CS1S_pp_tnp_pt[i]*syst1S_cspp_pt[i];
      //2S
      CS2S_pp_tnp_pt[i]= computeRatio( N2S_pp_pt4_2013[i] , Aet_2S_pythia_pt2013[i] )/(L_pp_invNb*RapBinWidth*deltaPt[i]);   
      CS2S_pp_tnp_pte[i] = computeRatioError( N2S_pp_pt4_2013[i] , Aet_2S_pythia_pt2013[i], N2S_pp_pt4_2013e[i] ,0)/(L_pp_invNb*RapBinWidth*deltaPt[i]) ; 
      CS2S_pp_tnp_pts[i] = CS2S_pp_tnp_pt[i]*syst2S_cspp_pt[i];
      //3S
      CS3S_pp_tnp_pt[i]= computeRatio( N3S_pp_pt4_2013[i] , Aet_3S_pythia_pt2013[i] )/(L_pp_invNb*RapBinWidth*deltaPt[i]);   
      CS3S_pp_tnp_pte[i] = computeRatioError( N3S_pp_pt4_2013[i] , Aet_3S_pythia_pt2013[i], N3S_pp_pt4_2013e[i] ,0)/(L_pp_invNb*RapBinWidth*deltaPt[i]) ; 
      CS3S_pp_tnp_pts[i] = CS3S_pp_tnp_pt[i]*syst3S_cspp_pt[i];
    }
  ///5.a. Y(1S)
  ofSyst <<"1S pp Pt Bins | stat err. | syst err. = +/- syst.fit +/- syst.gs +/- syst.muid +/- syst.sta +/- syst.lumi +/- syst.trk"<<endl;
   for(int j =0 ; j<nPtBins_2013 ; j++)
   {
     ofSyst <<  (binsPt[j]).c_str() << " & " << setprecision(3) << 
       stat1S_pp_pt[j] << " & " <<
       syst1S_cspp_pt[j] << " & " <<
       syst1S_pp_pt[j] << " & " <<
       syst1S_ppgs_pt[j] << " & " <<
       syst1S_ppmuid_pt[j] << " & " <<
       syst1S_ppsta_pt[j] << " & " <<
       syst_lumi << " & " <<
       tracking_pp <<" \\\\ " << endl;
   }
   ofRes<<"1S pp Pt Bins | Cross section +/- stat err. +/- syst err. +/- global unc. "<<endl;
   for(int j =0 ; j<nPtBins_2013 ; j++)
   {
     ofRes << (binsPt[j]).c_str() << " & " << setprecision(3) << 
       CS1S_pp_tnp_pt[j] << " \\pm "<<
       CS1S_pp_tnp_pte[j]<<" \\pm "<<
       CS1S_pp_tnp_pts[j]<<" \\pm "<<
       CS1S_pp_tnp_pt[j]*systXS_pp_glob << " \\\\"
	  << endl;
   }
   ///5.b. Y(2S)
  ofSyst <<"2S pp Pt Bins | stat err. | syst err. = +/- syst.fit +/- syst.gs +/- syst.muid +/- syst.sta +/- syst.lumi +/- syst.trk"<<endl;
  for(int j =0 ; j<nPtBins_2013 ; j++)
    {
      ofSyst <<  (binsPt[j]).c_str() << " & " << setprecision(3) << 
	stat2S_pp_pt[j] << " & " <<
	syst2S_cspp_pt[j] << " & " <<
	syst2S_pp_pt[j] << " & " <<
	syst2S_ppgs_pt[j] << " & " <<
	syst2S_ppmuid_pt[j] << " & " <<
	syst2S_ppsta_pt[j] << " & " <<
	syst_lumi << " & " <<
	tracking_pp <<" \\\\ " << endl;
    }
  ofRes<<"2S pp Pt Bins | Cross section +/- stat err. +/- syst err. +/- global unc. "<<endl;
  for(int j =0 ; j<nPtBins_2013 ; j++)
    {
      ofRes << (binsPt[j]).c_str() << " & " << setprecision(3) << 
	CS2S_pp_tnp_pt[j] << " \\pm "<<
	CS2S_pp_tnp_pte[j]<<" \\pm "<<
	CS2S_pp_tnp_pts[j]<<" \\pm "<<
	CS2S_pp_tnp_pt[j]*systXS_pp_glob << "  \\\\"
	    << endl;
    }
  ///5.c. Y(3S)
  ofSyst <<"3S pp Pt Bins | stat err. | syst err. = +/- syst.fit +/- syst.gs +/- syst.muid +/- syst.sta +/- syst.lumi +/- syst.trk"<<endl;
  for(int j =0 ; j<nPtBins_2013 ; j++)
    {
      ofSyst <<  (binsPt[j]).c_str() << " & " << setprecision(3) << 
	stat3S_pp_pt[j] << " & " <<
	syst3S_cspp_pt[j] << " & " <<
	syst3S_pp_pt[j] << " & " <<
	syst3S_ppgs_pt[j] << " & " <<
	syst3S_ppmuid_pt[j] << " & " <<
	syst3S_ppsta_pt[j] << " & " <<
	syst_lumi << " & " <<
	tracking_pp <<" \\\\ " << endl;
    }
  ofRes<<"3S pp Pt Bins | Cross section +/- stat err. +/- syst err. +/- global unc. "<<endl;
  for(int j =0 ; j<nPtBins_2013 ; j++)
    {
      ofRes << (binsPt[j]).c_str() << " & " << setprecision(3) << 
	CS3S_pp_tnp_pt[j] << " \\pm "<<
	CS3S_pp_tnp_pte[j]<<" \\pm "<<
	CS3S_pp_tnp_pts[j]<<" \\pm "<<
	CS3S_pp_tnp_pt[j]*systXS_pp_glob << "  \\\\"
	    << endl;
    }
  /// 6.
  TCanvas *cptpp = new TCanvas("cptpp","cptpp");
  gStyle->SetPadRightMargin(0.025); //overriding style for the pt-binned plots only, but will have to change again later...
  cptpp->SetLogy();
  cptpp->cd();
   TF1 *f4Pt = new TF1("f4Pt","10",0,20);
   f4Pt->SetLineWidth(0);
   f4Pt->GetXaxis()->SetTitle("p_{T}^{#varUpsilon} (GeV/c)");		
   f4Pt->GetYaxis()->SetTitle("#frac{d^{2}#sigma}{dy dp_{T}}  (nb/ GeV/c)");
   
   f4Pt->GetXaxis()->SetTitleSize(gTextSize+0.01);
   f4Pt->GetXaxis()->SetTitleOffset(f4Pt->GetXaxis()->GetTitleOffset()*1.1);
   f4Pt->GetYaxis()->SetTitleSize(gTextSize);
   f4Pt->GetYaxis()->SetLabelSize(0.8*f4Pt->GetYaxis()->GetLabelSize()); //  Y axis title is fat
   f4Pt->GetYaxis()->SetTitleOffset(1.65);
   //   f4Pt->GetYaxis()->SetRangeUser(0.0005,0.2);
   f4Pt->GetYaxis()->SetRangeUser(0.0001,0.2);
   //f4Pt->GetYaxis()->SetRangeUser(0.01,.09);
   f4Pt->GetXaxis()->CenterTitle(kTRUE);

   
   f4Pt->Draw();
   TGraphErrors *gpt1TNPpp = new TGraphErrors(nPtBins_2013,pt,CS1S_pp_tnp_pt,0,CS1S_pp_tnp_pte);
   gpt1TNPpp->SetMarkerColor(color1Spp);
   gpt1TNPpp->SetMarkerStyle(symbol1S);
   gpt1TNPpp->SetMarkerSize(markerSize);
   TGraphErrors *gpt1circlepp = new TGraphErrors(nPtBins_2013,pt,CS1S_pp_tnp_pt,0,CS1S_pp_tnp_pte);
   gpt1circlepp->SetMarkerStyle(symbol1Sc);
   gpt1circlepp->SetMarkerSize(markerSize);
   gpt1circlepp->SetLineColor(kBlack);
   gpt1circlepp->SetLineWidth(2);
   TGraphErrors *gPt1ppsyst = new TGraphErrors(nPtBins_2013,pt,CS1S_pp_tnp_pt,pte,CS1S_pp_tnp_pts);
   gPt1ppsyst->SetLineColor(color1Spp);
   gPt1ppsyst->SetFillStyle(0);
   gPt1ppsyst->SetLineWidth(2);
   gPt1ppsyst->SetMarkerSize(0);
   gPt1ppsyst->Draw("2");
   gpt1TNPpp->Draw("pe");
   gpt1circlepp->Draw("p");
   //2S
   TGraphErrors *gpt2TNPpp = new TGraphErrors(nPtBins_2013,pt,CS2S_pp_tnp_pt,0,CS2S_pp_tnp_pte);
   gpt2TNPpp->SetMarkerColor(color2Spp);
   gpt2TNPpp->SetMarkerStyle(symbol2S);
   gpt2TNPpp->SetMarkerSize(markerSize);
   TGraphErrors *gpt2circlepp = new TGraphErrors(nPtBins_2013,pt,CS2S_pp_tnp_pt,0,CS2S_pp_tnp_pte);
   gpt2circlepp->SetMarkerStyle(symbol2Sc);
   gpt2circlepp->SetMarkerSize(markerSize);
   gpt2circlepp->SetLineColor(kBlack);
   gpt2circlepp->SetLineWidth(2);
   TGraphErrors *gPt2ppsyst = new TGraphErrors(nPtBins_2013,pt,CS2S_pp_tnp_pt,pte,CS2S_pp_tnp_pts);
   gPt2ppsyst->SetLineColor(color2Spp);
   gPt2ppsyst->SetFillStyle(0);
   gPt2ppsyst->SetLineWidth(2);
   gPt2ppsyst->SetMarkerSize(0);
   gPt2ppsyst->Draw("2");
   gpt2TNPpp->Draw("pe");
   gpt2circlepp->Draw("p");
   //3S
   TGraphErrors *gpt3TNPpp = new TGraphErrors(nPtBins_2013,pt,CS3S_pp_tnp_pt,0,CS3S_pp_tnp_pte);
   gpt3TNPpp->SetMarkerColor(color3Spp);
   gpt3TNPpp->SetMarkerStyle(symbol3S);
   gpt3TNPpp->SetMarkerSize(markerSize);
   TGraphErrors *gpt3circlepp = new TGraphErrors(nPtBins_2013,pt,CS3S_pp_tnp_pt,0,CS3S_pp_tnp_pte);
   gpt3circlepp->SetMarkerStyle(symbol3Sc);
   gpt3circlepp->SetMarkerSize(markerSize);
   gpt3circlepp->SetLineColor(kBlack);
   gpt3circlepp->SetLineWidth(2);
   TGraphErrors *gPt3ppsyst = new TGraphErrors(nPtBins_2013,pt,CS3S_pp_tnp_pt,pte,CS3S_pp_tnp_pts);
   gPt3ppsyst->SetLineColor(color3Spp);
   gPt3ppsyst->SetFillStyle(0);
   gPt3ppsyst->SetLineWidth(2);
   gPt3ppsyst->SetMarkerSize(0);
   gPt3ppsyst->Draw("2");
   gpt3TNPpp->Draw("pe");
   gpt3circlepp->Draw("p");
   gPad->RedrawAxis();
   TLegend *legend_cspppt = new TLegend(0.22,0.22,0.39,0.40);
   legend_cspppt->SetTextSize(gTextSize);
   legend_cspppt->SetFillStyle(0);
   legend_cspppt->SetFillColor(0);
   legend_cspppt->SetBorderSize(0);
   legend_cspppt->SetTextFont(42);
   legend_cspppt->AddEntry(gpt1TNPpp,"#varUpsilon(1S) ","p"); 
   legend_cspppt->AddEntry(gpt2TNPpp,"#varUpsilon(2S) ","p");
   legend_cspppt->AddEntry(gpt3TNPpp,"#varUpsilon(3S) ","p");
   legend_cspppt->Draw();
   
   // |y| < 2.4
   if (!plotBox && !plotLin){
   TLatex latexpt;
   latexpt.SetTextSize(gTextSize);
   latexpt.SetTextFont(42);
   TLatex *latexpttxt = latexpt.DrawLatex(15.7,0.025,"|y| < 2.4");
   latexpt.DrawLatex(1.2,0.0008,Form("Global uncertainty: %.1f",100*systXS_pp_glob));
   latexpt.DrawLatex(10.2,0.0008,"%"); ///
   }
   
   CMS_lumi(cptpp,102,33);
   cptpp->Update();
   cptpp->RedrawAxis();
   cptpp->GetFrame()->Draw();
   cptpp->SaveAs(basedir2 + TString("/CS_pp_Pt.pdf"));
   cptpp->SaveAs(basedir2 + TString("/CS_pp_Pt.png"));
   cptpp->SaveAs(basedir1 + TString("/pdf/Xsection_ppNS_Pt.pdf"));
   cptpp->SaveAs(basedir1 + TString("/png/Xsection_ppNS_Pt.png"));

   if (plotLin)
     {
       cptpp->SetLogy(0);
       legend_cspppt->SetX1NDC(0.77); legend_cspppt->SetX2NDC(1.); legend_cspppt->SetY1NDC(0.40); legend_cspppt->SetY2NDC(0.61); legend_cspppt->Draw();
       TLatex latexpt;
       latexpt.SetTextSize(gTextSize);
       latexpt.SetTextFont(42);
       TLatex *latexpttxt = latexpt.DrawLatex(15.7,0.025,"|y| < 2.4");
       if (!plotBox){
	 latexpt.DrawLatex(1.2,0.0008,Form("Global uncertainty: %.1f",100*systXS_pp_glob));
	 latexpt.DrawLatex(10.2,0.0008,"%"); ///
       }
       cptpp->cd();
       gPad->Update();
       f4Pt->GetYaxis()->SetRangeUser(0.,0.12);
       f4Pt->GetYaxis()->SetTitleOffset(1.65);
       f4Pt->GetYaxis()->SetTitleSize(gTextSize);
       latexpttxt->SetY(0.085);
       latexpttxt->Draw();
       gPad->Update();
       gPad->RedrawAxis();
       gPad->GetFrame()->Draw();
       cptpp->SaveAs(basedir2 + TString("/CSNS_ppPt_lin.pdf"));
       cptpp->SaveAs(basedir2 + TString("/CSNS_ppPt_lin.png"));
       cptpp->SaveAs(basedir1 + TString("/pdf/Xsection_ppNS_Pt_lin.pdf"));
       cptpp->SaveAs(basedir1 + TString("/png/Xsection_ppNS_Pt_lin.png"));
     }

   cptpp->Close();

   ///===============================
   /// pp cross sections vs Rap in fine bins (of course)
   ///===============================
   /// 1. Define variables
   /// 2. Define syst variables
   /// 3. Compute the syst
   /// 4. Compute the CS.
   /// 5. Print the outputs
   /// 6. Draw and save
   ///-------------------------------
   /// 1.a. Y(1S)
   float CS1S_pp_tnp_rap[nRapBins_2014] = {};
   float CS1S_pp_tnp_rape[nRapBins_2014] = {};
   float CS1S_pp_tnp_raps[nRapBins_2014] = {};
   /// 1.b. Y(2S)
   float CS2S_pp_tnp_rap[nRapBins_2014] = {};
   float CS2S_pp_tnp_rape[nRapBins_2014] = {};
   float CS2S_pp_tnp_raps[nRapBins_2014] = {};
   /// 1.c Y(3S)
   float CS3S_pp_tnp_rap[nRapBins_2014] = {};
   float CS3S_pp_tnp_rape[nRapBins_2014] = {};
   float CS3S_pp_tnp_raps[nRapBins_2014] = {};
   /// 2.a Y(1S)
   float stat1S_pp_rap[nRapBins_2014]={}; //stat. pp relative uncertainty (contributing to R_AA as a rap to rap syst. uncertainty!
   float syst1S_pptnp_rap[nRapBins_2014]={};// tnp uncertainty
   float syst1S_pp_rap[nRapBins_2014]={};   //fit syst. uncertainty.
   float syst1S_ppgs_rap[nRapBins_2014]={};   //gen shape
   float syst1S_ppsta_rap[nRapBins_2014]={}; ///sta uncertainty
   float syst1S_ppmuid_rap[nRapBins_2014]={};/// muid uncertainty
   float syst1S_cspp_rap[nRapBins_2014]={}; /// quadratic sum.
   /// 2.b Y(2S)
   float stat2S_pp_rap[nRapBins_2014]={}; //stat. pp relative uncertainty (contributing to R_AA as a Rap to Rap syst. uncertainty!
   float syst2S_pptnp_rap[nRapBins_2014]={};// tnp uncertainty
   float syst2S_pp_rap[nRapBins_2014]={};   //fit syst. uncertainty.
   float syst2S_ppgs_rap[nRapBins_2014]={};   //gen shape
   float syst2S_ppsta_rap[nRapBins_2014]={}; ///sta uncertainty
   float syst2S_ppmuid_rap[nRapBins_2014]={};/// muid uncertainty
   float syst2S_cspp_rap[nRapBins_2014]={}; /// quadratic sum.
   /// 2.c Y(3S)
   float stat3S_pp_rap[nRapBins_2014]={}; //stat. pp relative uncertainty (contributing to R_AA as a Rap to Rap syst. uncertainty!
   float syst3S_pptnp_rap[nRapBins_2014]={};// tnp uncertainty
   float syst3S_pp_rap[nRapBins_2014]={};   //fit syst. uncertainty.
   float syst3S_ppgs_rap[nRapBins_2014]={};   //gen shape
   float syst3S_ppsta_rap[nRapBins_2014]={}; ///sta uncertainty
   float syst3S_ppmuid_rap[nRapBins_2014]={};/// muid uncertainty
   float syst3S_cspp_rap[nRapBins_2014]={}; /// quadratic sum.
   /// 3.
   syst1S_pp_rap[0]=ppAlphaSyst(N1S_pp_rap3p5_2014[0],N1S_pp_rap3p5s_0p4,N1B_pp_rap3p5s_0p4,N1S_pp_rap3p5_2014[0],N1S_pp_rap3p5s_0p4[1]);
   syst1S_pp_rap[1]=ppAlphaSyst(N1S_pp_rap3p5_2014[1],N1S_pp_rap3p5s_0p8,N1B_pp_rap3p5s_0p8,N1S_pp_rap3p5_2014[1],N1S_pp_rap3p5s_0p8[1]);
   syst1S_pp_rap[2]=ppAlphaSyst(N1S_pp_rap3p5_2014[2],N1S_pp_rap3p5s_1p2,N1B_pp_rap3p5s_1p2,N1S_pp_rap3p5_2014[2],N1S_pp_rap3p5s_1p2[1]);
   syst1S_pp_rap[3]=ppAlphaSyst(N1S_pp_rap3p5_2014[3],N1S_pp_rap3p5s_1p6,N1B_pp_rap3p5s_1p6,N1S_pp_rap3p5_2014[3],N1S_pp_rap3p5s_1p6[1]);
   syst1S_pp_rap[4]=ppAlphaSyst(N1S_pp_rap3p5_2014[4],N1S_pp_rap3p5s_2p0,N1B_pp_rap3p5s_2p0,N1S_pp_rap3p5_2014[4],N1S_pp_rap3p5s_2p0[1]);
   syst1S_pp_rap[5]=ppAlphaSyst(N1S_pp_rap3p5_2014[5],N1S_pp_rap3p5s_2p4,N1B_pp_rap3p5s_2p4,N1S_pp_rap3p5_2014[5],N1S_pp_rap3p5s_2p4[1]);
   ///
   syst2S_pp_rap[0]= ppAlphaSyst(N2S_pp_rap4_2014[0],N2S_pp_rap4s_0p4,N2B_pp_rap4s_0p4,N2S_pp_rap4_2014[0],N2S_pp_rap4s_0p4[1]);
   syst2S_pp_rap[1]= ppAlphaSyst(N2S_pp_rap4_2014[1],N2S_pp_rap4s_0p8,N2B_pp_rap4s_0p8,N2S_pp_rap4_2014[1],N2S_pp_rap4s_0p8[1]);
   syst2S_pp_rap[2]= ppAlphaSyst(N2S_pp_rap4_2014[2],N2S_pp_rap4s_1p2,N2B_pp_rap4s_1p2,N2S_pp_rap4_2014[2],N2S_pp_rap4s_1p2[1]);
   syst2S_pp_rap[3]= ppAlphaSyst(N2S_pp_rap4_2014[3],N2S_pp_rap4s_1p6,N2B_pp_rap4s_1p6,N2S_pp_rap4_2014[3],N2S_pp_rap4s_1p6[1]);
   syst2S_pp_rap[4]= ppAlphaSyst(N2S_pp_rap4_2014[4],N2S_pp_rap4s_2p0,N2B_pp_rap4s_2p0,N2S_pp_rap4_2014[4],N2S_pp_rap4s_2p0[1]);
   syst2S_pp_rap[5]= ppAlphaSyst(N2S_pp_rap4_2014[5],N2S_pp_rap4s_2p4,N2B_pp_rap4s_2p4,N2S_pp_rap4_2014[5],N2S_pp_rap4s_2p4[1]);
   ///
   syst3S_pp_rap[0]= ppAlphaSyst(N3S_pp_rap4_2014[0],N3S_pp_rap4s_0p4,N3B_pp_rap4s_0p4,N3S_pp_rap4_2014[0],N3S_pp_rap4s_0p4[1]);
   syst3S_pp_rap[1]= ppAlphaSyst(N3S_pp_rap4_2014[1],N3S_pp_rap4s_0p8,N3B_pp_rap4s_0p8,N3S_pp_rap4_2014[1],N3S_pp_rap4s_0p8[1]);
   syst3S_pp_rap[2]= ppAlphaSyst(N3S_pp_rap4_2014[2],N3S_pp_rap4s_1p2,N3B_pp_rap4s_1p2,N3S_pp_rap4_2014[2],N3S_pp_rap4s_1p2[1]);
   syst3S_pp_rap[3]= ppAlphaSyst(N3S_pp_rap4_2014[3],N3S_pp_rap4s_1p6,N3B_pp_rap4s_1p6,N3S_pp_rap4_2014[3],N3S_pp_rap4s_1p6[1]);
   syst3S_pp_rap[4]= ppAlphaSyst(N3S_pp_rap4_2014[4],N3S_pp_rap4s_2p0,N3B_pp_rap4s_2p0,N3S_pp_rap4_2014[4],N3S_pp_rap4s_2p0[1]);
   syst3S_pp_rap[5]= ppAlphaSyst(N3S_pp_rap4_2014[5],N3S_pp_rap4s_2p4,N3B_pp_rap4s_2p4,N3S_pp_rap4_2014[5],N3S_pp_rap4s_2p4[1]);
 
   for(int i = 0 ; i<nRapBins_2014 ; i++)
     {
       stat1S_pp_rap[i]=N1S_pp_rap3p5_2014e[i]/N1S_pp_rap3p5_2014[i];
       syst1S_pptnp_rap[i]=Aet_1S_pythia_rap3p5_fulls[i]/Aet_1S_pythia_rap2014_STA[i]; //fulls is the full tnp syst (muidtrg+sta added in quadrature)
       syst1S_ppgs_rap[i]=Aet_1S_pythia_rap2014_STAe[i]/Aet_1S_pythia_rap2014_STA[i]; // doesnt matter if we use STA or MuID
       syst1S_ppsta_rap[i]=Aet_1S_pythia_rap2014_STAs[i]/Aet_1S_pythia_rap2014_STA[i];
       syst1S_ppmuid_rap[i]=Aet_1S_pythia_rap2014_muIDTrigs[i]/Aet_1S_pythia_rap2014_muIDTrig[i];
       syst1S_cspp_rap[i]=sqrt(syst1S_pptnp_rap[i]*syst1S_pptnp_rap[i]+syst1S_pp_rap[i]*syst1S_pp_rap[i]+pow(syst1S_ppgs_rap[i],2));
       //2S
       stat2S_pp_rap[i]=N2S_pp_rap4_2014e[i]/N2S_pp_rap4_2014[i];
       syst2S_pptnp_rap[i]=Aet_2S_pythia_rap2014s[i]/Aet_2S_pythia_rap2014[i];
       syst2S_ppgs_rap[i]=Aet_2S_pythia_rap2014e[i]/Aet_2S_pythia_rap2014[i]; // doesnt matter if we use STA or MuID
       syst2S_ppsta_rap[i]=Aet_2S_pythia_rap2014_STAe[i]/Aet_2S_pythia_rap2014[i];
       syst2S_ppmuid_rap[i]=Aet_2S_pythia_rap2014_muIDTrige[i]/Aet_2S_pythia_rap2014[i];
       syst2S_cspp_rap[i]=sqrt(syst2S_pptnp_rap[i]*syst2S_pptnp_rap[i]+syst2S_pp_rap[i]*syst2S_pp_rap[i]+pow(syst2S_ppgs_rap[i],2));
       //3S
       stat3S_pp_rap[i]=N3S_pp_rap4_2014e[i]/N3S_pp_rap4_2014[i];
       syst3S_pptnp_rap[i]=Aet_3S_pythia_rap2014s[i]/Aet_3S_pythia_rap2014[i];
       syst3S_ppgs_rap[i]=Aet_3S_pythia_rap2014e[i]/Aet_3S_pythia_rap2014[i]; // doesnt matter if we use STA or MuID
       syst3S_ppsta_rap[i]=Aet_3S_pythia_rap2014_STAe[i]/Aet_3S_pythia_rap2014[i];
       syst3S_ppmuid_rap[i]=Aet_3S_pythia_rap2014_muIDTrige[i]/Aet_3S_pythia_rap2014[i];
       syst3S_cspp_rap[i]=sqrt(syst3S_pptnp_rap[i]*syst3S_pptnp_rap[i]+syst3S_pp_rap[i]*syst3S_pp_rap[i]+pow(syst3S_ppgs_rap[i],2));

     }
   /// 4.
   for(int i = 0 ; i<nRapBins_2014 ; i++)
     {
       CS1S_pp_tnp_rap[i]= computeRatio( N1S_pp_rap3p5_2014[i] , Aet_1S_pythia_rap2014_STA[i] )/(L_pp_invNb*deltaRapEven[i]);   
       CS1S_pp_tnp_rape[i] = computeRatioError( N1S_pp_rap3p5_2014[i] , Aet_1S_pythia_rap2014_STA[i], N1S_pp_rap3p5_2014e[i] ,0)/(L_pp_invNb*deltaRapEven[i]) ; 
       CS1S_pp_tnp_raps[i] = CS1S_pp_tnp_rap[i]*syst1S_cspp_rap[i];
       //2S
       CS2S_pp_tnp_rap[i]= computeRatio( N2S_pp_rap4_2014[i] , Aet_2S_pythia_rap2014[i] )/(L_pp_invNb*deltaRapEven[i]);   
       CS2S_pp_tnp_rape[i] = computeRatioError( N2S_pp_rap4_2014[i] , Aet_2S_pythia_rap2014[i], N2S_pp_rap4_2014e[i] ,0)/(L_pp_invNb*deltaRapEven[i]) ; 
       CS2S_pp_tnp_raps[i] = CS2S_pp_tnp_rap[i]*syst2S_cspp_rap[i];
       //3S
       CS3S_pp_tnp_rap[i]= computeRatio( N3S_pp_rap4_2014[i] , Aet_3S_pythia_rap2014[i] )/(L_pp_invNb*deltaRapEven[i]);   
       CS3S_pp_tnp_rape[i] = computeRatioError( N3S_pp_rap4_2014[i] , Aet_3S_pythia_rap2014[i], N3S_pp_rap4_2014e[i] ,0)/(L_pp_invNb*deltaRapEven[i]) ; 
       CS3S_pp_tnp_raps[i] = CS3S_pp_tnp_rap[i]*syst3S_cspp_rap[i];
      
     }
   ///5.a. Y(1S)
   ofSyst <<"1S pp Rap Bins | stat err. | syst err. = +/- syst.fit +/- syst.gs +/- syst.muid +/- syst.sta +/- syst.lumi +/- syst.trk"<<endl;
   for(int j =0 ; j<nRapBins_2014 ; j++)
     {
       ofSyst <<  (binsRap[j]).c_str() << " & " << setprecision(3) << 
	 stat1S_pp_rap[j] << " & " <<
	 syst1S_cspp_rap[j] << " & " <<
	 syst1S_pp_rap[j] << " & " <<
	 syst1S_ppgs_rap[j] << " & " <<
	 syst1S_ppmuid_rap[j] << " & " <<
	 syst1S_ppsta_rap[j] << " & " <<
	 syst_lumi << " & " <<
	 tracking_pp <<" \\\\ " << endl;
     }
   ofRes<<"1S pp Rap Bins | Cross section +/- stat err. +/- syst err. +/- global unc. "<<endl;
   for(int j =0 ; j<nRapBins_2014 ; j++)
     {
       ofRes << (binsRap[j]).c_str() << " & " << setprecision(3) << 
	 CS1S_pp_tnp_rap[j] << " \\pm "<<
	 CS1S_pp_tnp_rape[j]<<" \\pm "<<
	 CS1S_pp_tnp_raps[j]<<" \\pm "<<
	 CS1S_pp_tnp_rap[j]*systXS_pp_glob << " \\\\"
	     << endl;
     }
   ///5.b. Y(2S)
   ofSyst <<"2S pp Rap Bins | stat err. | syst err. = +/- syst.fit +/- syst.gs +/- syst.muid +/- syst.sta +/- syst.lumi +/- syst.trk"<<endl;
   for(int j =0 ; j<nRapBins_2014 ; j++)
     {
       ofSyst <<  (binsRap[j]).c_str() << " & " << setprecision(3) << 
	 stat2S_pp_rap[j] << " & " <<
	 syst2S_cspp_rap[j] << " & " <<
	 syst2S_pp_rap[j] << " & " <<
	 syst2S_ppgs_rap[j] << " & " <<
	 syst2S_ppmuid_rap[j] << " & " <<
	 syst2S_ppsta_rap[j] << " & " <<
	 syst_lumi << " & " <<
	 tracking_pp <<" \\\\ " << endl;
     }
   ofRes<<"2S pp Rap Bins | Cross section +/- stat err. +/- syst err. +/- global unc. "<<endl;
   for(int j =0 ; j<nRapBins_2014 ; j++)
     {
       ofRes << (binsRap[j]).c_str() << " & " << setprecision(3) << 
	 CS2S_pp_tnp_rap[j] << " \\pm "<<
	 CS2S_pp_tnp_rape[j]<<" \\pm "<<
	 CS2S_pp_tnp_raps[j]<<" \\pm "<<
	 CS2S_pp_tnp_rap[j]*systXS_pp_glob << "  \\\\"
	     << endl;
     }
   ///5.c. Y(3S)
   ofSyst <<"3S pp Rap Bins | stat err. | syst err. = +/- syst.fit +/- syst.gs +/- syst.muid +/- syst.sta +/- syst.lumi +/- syst.trk "<<endl;
   for(int j =0 ; j<nRapBins_2014 ; j++)
     {
       ofSyst <<  (binsRap[j]).c_str() << " & " << setprecision(3) << 
	 stat3S_pp_rap[j] << " & " <<
	 syst3S_cspp_rap[j] << " & " <<
	 syst3S_pp_rap[j] << " & " <<
	 syst3S_ppgs_rap[j] << " & " <<
	 syst3S_ppmuid_rap[j] << " & " <<
	 syst3S_ppsta_rap[j] << " & " <<
	 syst_lumi << " & " <<
	 tracking_pp <<" \\\\ " << endl;
     }
   ofRes<<"3S pp Rap Bins | Cross section +/- stat err. +/- syst err. +/- global unc. "<<endl;
   for(int j =0 ; j<nRapBins_2014 ; j++)
     {
       ofRes << (binsRap[j]).c_str() << " & " << setprecision(3) << 
	 CS3S_pp_tnp_rap[j] << " \\pm "<<
	 CS3S_pp_tnp_rape[j]<<" \\pm "<<
	 CS3S_pp_tnp_raps[j]<<" \\pm "<<
	 CS3S_pp_tnp_rap[j]*systXS_pp_glob << "  \\\\"
	     << endl;
     }
   /// 6.
   gStyle->SetPadRightMargin(0.04); //reverting style here...
   TCanvas *cRappp = new TCanvas("cRappp","cRappp"); 
   cRappp->SetLogy();
   cRappp->cd();
   TF1 *f4Rap = new TF1("f4Rap","10",0,2.4);
   f4Rap->SetLineWidth(0);
   f4Rap->GetXaxis()->SetTitle("|y|");
   f4Rap->GetYaxis()->SetTitle("#frac{d#sigma}{dy}   (nb)");
   
   f4Rap->GetXaxis()->SetTitleSize(gTextSize+0.01);
   f4Rap->GetXaxis()->SetTitleOffset(f4Rap->GetXaxis()->GetTitleOffset()*1.1);
   f4Rap->GetYaxis()->SetTitleSize(gTextSize);
   f4Rap->GetYaxis()->SetLabelSize(0.9*f4Rap->GetYaxis()->GetLabelSize()); //  Y axis title is fat
   f4Rap->GetYaxis()->SetTitleOffset(1.6);
   f4Rap->GetYaxis()->SetRangeUser(0.01,1.6);
   f4Rap->GetXaxis()->CenterTitle(kTRUE);
   f4Rap->Draw();
   TGraphErrors *gRap1TNPpp = new TGraphErrors(nRapBins_2014,rap2014,CS1S_pp_tnp_rap,0,CS1S_pp_tnp_rape);
   gRap1TNPpp->SetMarkerColor(color1Spp);
   gRap1TNPpp->SetMarkerStyle(symbol1S);
   gRap1TNPpp->SetMarkerSize(markerSize);
   TGraphErrors *gRap1circlepp = new TGraphErrors(nRapBins_2014,rap2014,CS1S_pp_tnp_rap,0,CS1S_pp_tnp_rape);
   gRap1circlepp->SetMarkerStyle(symbol1Sc);
   gRap1circlepp->SetMarkerSize(markerSize);
   gRap1circlepp->SetLineColor(kBlack);
   gRap1circlepp->SetLineWidth(2);
   TGraphErrors *gRap1ppsyst = new TGraphErrors(nRapBins_2014,rap2014,CS1S_pp_tnp_rap,rap2014e,CS1S_pp_tnp_raps);
   gRap1ppsyst->SetLineColor(color1Spp);
   gRap1ppsyst->SetFillStyle(0);
   gRap1ppsyst->SetLineWidth(2);
   gRap1ppsyst->SetMarkerSize(0);
   gRap1ppsyst->Draw("2");
   gRap1TNPpp->Draw("pe");
   gRap1circlepp->Draw("p");
   //2S
   TGraphErrors *gRap2TNPpp = new TGraphErrors(nRapBins_2014,rap2014,CS2S_pp_tnp_rap,0,CS2S_pp_tnp_rape);
   gRap2TNPpp->SetMarkerColor(color2Spp);
   gRap2TNPpp->SetMarkerStyle(symbol2S);
   gRap2TNPpp->SetMarkerSize(markerSize);
   TGraphErrors *gRap2circlepp = new TGraphErrors(nRapBins_2014,rap2014,CS2S_pp_tnp_rap,0,CS2S_pp_tnp_rape);
   gRap2circlepp->SetMarkerStyle(symbol2Sc);
   gRap2circlepp->SetMarkerSize(markerSize);
   gRap2circlepp->SetLineColor(kBlack);
   gRap2circlepp->SetLineWidth(2);
   TGraphErrors *gRap2ppsyst = new TGraphErrors(nRapBins_2014,rap2014,CS2S_pp_tnp_rap,rap2014e,CS2S_pp_tnp_raps);
   gRap2ppsyst->SetLineColor(color2Spp);
   gRap2ppsyst->SetFillStyle(0);
   gRap2ppsyst->SetLineWidth(2);
   gRap2ppsyst->SetMarkerSize(0);
   gRap2ppsyst->Draw("2");
   gRap2TNPpp->Draw("pe");
   gRap2circlepp->Draw("p");
   //3S
   TGraphErrors *gRap3TNPpp = new TGraphErrors(nRapBins_2014,rap2014,CS3S_pp_tnp_rap,0,CS3S_pp_tnp_rape);
   gRap3TNPpp->SetMarkerColor(color3Spp);
   gRap3TNPpp->SetMarkerStyle(symbol3S);
   gRap3TNPpp->SetMarkerSize(markerSize);
   TGraphErrors *gRap3circlepp = new TGraphErrors(nRapBins_2014,rap2014,CS3S_pp_tnp_rap,0,CS3S_pp_tnp_rape);
   gRap3circlepp->SetMarkerStyle(symbol3Sc);
   gRap3circlepp->SetMarkerSize(markerSize);
   gRap3circlepp->SetLineColor(kBlack);
   gRap3circlepp->SetLineWidth(2);
   TGraphErrors *gRap3ppsyst = new TGraphErrors(nRapBins_2014,rap2014,CS3S_pp_tnp_rap,rap2014e,CS3S_pp_tnp_raps);
   gRap3ppsyst->SetLineColor(color3Spp);
   gRap3ppsyst->SetFillStyle(0);
   gRap3ppsyst->SetLineWidth(2);
   gRap3ppsyst->SetMarkerSize(0);
   gRap3ppsyst->Draw("2");
   gRap3TNPpp->Draw("pe");
   gRap3circlepp->Draw("p");
   gPad->RedrawAxis();
   TLegend *legend_cspprap = new TLegend(0.22,0.22,0.39,0.4);
   legend_cspprap->SetTextSize(gTextSize);
   legend_cspprap->SetFillStyle(0);
   legend_cspprap->SetFillColor(0);
   legend_cspprap->SetBorderSize(0);
   legend_cspprap->SetTextFont(42);
   legend_cspprap->AddEntry(gRap1TNPpp,"#varUpsilon(1S) ","p"); 
   legend_cspprap->AddEntry(gRap2TNPpp,"#varUpsilon(2S) ","p");
   legend_cspprap->AddEntry(gRap3TNPpp,"#varUpsilon(3S) ","p");
   legend_cspprap->Draw();

   if (!plotLin && !plotBox) {
     TLatex latexRap;
     latexRap.SetTextSize(gTextSize);
     latexRap.SetTextFont(42);
     TLatex *latexRaptxt = latexRap.DrawLatex(1.,0.015,Form("Global uncertainty: %.1f",100*systXS_pp_glob));
     latexRaptxt->DrawLatex(2.06,0.015,"%"); /// 
   }
   // /// plotBox goes here.
   // TBox *boxRap = new TBox(2.25,1-systXS_raa_glob,2.4,1+systXS_raa_glob); 
   // boxRap->SetFillColor(kGray);
   // boxRap->Draw();
   // }
 
   CMS_lumi(cRappp,102,33);
   cRappp->Update();
   cRappp->RedrawAxis();
   cRappp->GetFrame()->Draw();
   
   cRappp->SaveAs(basedir2 + TString("/CS_pp_rap.pdf"));
   cRappp->SaveAs(basedir2 + TString("/CS_pp_rap.png"));
   cRappp->SaveAs(basedir1 + TString("/pdf/Xsection_ppNS_rap.pdf"));
   cRappp->SaveAs(basedir1 + TString("/png/Xsection_ppNS_rap.png"));
   if (plotLin)
     {
       cRappp->SetLogy(0);
       legend_cspprap->SetY1NDC(0.44); legend_cspprap->SetY2NDC(0.63); legend_cspprap->Draw();
       TLatex latexRapLin;
       latexRapLin.SetTextSize(gTextSize);
       latexRapLin.SetTextFont(42);
       if (!plotBox){
       TLatex *latexRaptxtLin =  latexRapLin.DrawLatex(1.,0.45,Form("Global uncertainty: %.1f",100*systXS_pp_glob));
       latexRaptxtLin->DrawLatex(2.06,0.45,"%"); ///
       }
       cRappp->cd();
       gPad->Update();
       f4Rap->GetYaxis()->SetRangeUser(0.,1.);
       f4Rap->GetYaxis()->SetTitleOffset(1.6);
       f4Rap->GetYaxis()->SetTitleSize(gTextSize);
       gPad->Update();
       gPad->RedrawAxis();
       gPad->GetFrame()->Draw();
       cRappp->SaveAs(basedir2 + TString("/CS1S_ppRap_lin.pdf"));
       cRappp->SaveAs(basedir2 + TString("/CS1S_ppRap_lin.png")); 
       cRappp->SaveAs(basedir1 + TString("/pdf/Xsection_pp_1S_Rap_lin.pdf"));
       cRappp->SaveAs(basedir1 + TString("/png/Xsection_pp_1S_Rap_lin.png"));
     }
   cRappp->Close();
   
   ///===============================
   /// (PbPb cross sections + pp cross sections in Large Bins) vs Pt
   ///===============================
   /// 1. Define variables
   /// 2. Define syst variables
   /// 3. Compute the syst
   /// 4. Compute the CS.
   /// 5. Print the outputs
   /// 6. Draw and save
   ///-------------------------------
   /// 1.a. Y(1S)
   float CS1S_aa_tnp_pt[nPtBins_2013] = {};
   float CS1S_aa_tnp_pte[nPtBins_2013] = {};
   float CS1S_aa_tnp_pts[nPtBins_2013] = {};

   /// 1.b. Y(2S)
   float CS2S_aa_tnp_pt[nPtBins_2010] = {};
   float CS2S_aa_tnp_pte[nPtBins_2010] = {};
   float CS2S_aa_tnp_pts[nPtBins_2010] = {};

   /// 1.d. Y(2S) pp large
   float CS2S_ppL_tnp_pt[nPtBins_2010] = {};
   float CS2S_ppL_tnp_pte[nPtBins_2010] = {};
   float CS2S_ppL_tnp_pts[nPtBins_2010] = {};

   /// 2.a Y(1S)
   float stat1S_aa_pt[nPtBins_2013]={}; //stat. aa relative uncertainty (contributing to R_AA as a pt to pt syst. uncertainty!
   float syst1S_aatnp_pt[nPtBins_2013]={};// tnp uncertainty
   float syst1S_aa_pt[nPtBins_2013]={};   //fit syst. uncertainty.
   float syst1S_aags_pt[nPtBins_2013]={};   //gen shape
   float syst1S_aasta_pt[nPtBins_2013]={}; ///sta uncertainty
   float syst1S_aamuid_pt[nPtBins_2013]={};/// muid uncertainty
   float syst1S_csaa_pt[nPtBins_2013]={}; /// quadratic sum.

   /// 2.b Y(2S)
   float stat2S_aa_pt[nPtBins_2010]={}; //stat. aa relative uncertainty (contributing to R_AA as a pt to pt syst. uncertainty!
   float syst2S_aatnp_pt[nPtBins_2010]={};// tnp uncertainty
   float syst2S_aa_pt[nPtBins_2010]={};   //fit syst. uncertainty.
   float syst2S_aags_pt[nPtBins_2010]={};   //gen shape
   float syst2S_aasta_pt[nPtBins_2010]={}; ///sta uncertainty
   float syst2S_aamuid_pt[nPtBins_2010]={};/// muid uncertainty
   float syst2S_csaa_pt[nPtBins_2010]={}; /// quadratic sum.


   /// 2.d Y(2S)
   float stat2S_ppL_pt[nPtBins_2010]={}; //stat. aa relative uncertainty (contributing to R_AA as a pt to pt syst. uncertainty!
   float syst2S_ppLtnp_pt[nPtBins_2010]={};// tnp uncertainty
   float syst2S_pp_ptLarge[nPtBins_2010]={};   //fit syst. uncertainty.
   float syst2S_ppLgs_pt[nPtBins_2010]={};   //gen shape
   float syst2S_ppLsta_pt[nPtBins_2010]={}; ///sta uncertainty
   float syst2S_ppLmuid_pt[nPtBins_2010]={};/// muid uncertainty
   float syst2S_csppL_pt[nPtBins_2010]={}; /// quadratic sum.


   /// 3.
   /// NOTE: the systematic uncertainty changes (see the text above). In pbpb, the glob is trk_aa, taa, nmb uncertainty.
   float systXS_aa_glob = sqrt(pow(tracking_aa,2)+pow(syst_taa,2)+pow(syst_nmb,2));
   syst1S_aa_pt[0]= ppAlphaSyst(N1S_aa_pt3p5[0],N1S_aa_pt3p5s_2p5,N1B_aa_pt3p5s_2p5,N1S_pp_pt3p5[0],N1S_pp_pt3p5s_2p5[1]);
   syst1S_aa_pt[1]= ppAlphaSyst(N1S_aa_pt3p5[1],N1S_aa_pt3p5s_5,N1B_aa_pt3p5s_5,N1S_pp_pt3p5[1],N1S_pp_pt3p5s_5[1]);
   syst1S_aa_pt[2]= ppAlphaSyst(N1S_aa_pt3p5[2],N1S_aa_pt3p5s_8,N1B_aa_pt3p5s_8,N1S_pp_pt3p5[2],N1S_pp_pt3p5s_8[1]);
   syst1S_aa_pt[3]= ppAlphaSyst(N1S_aa_pt3p5[3],N1S_aa_pt3p5s_12,N1B_aa_pt3p5s_12,N1S_pp_pt3p5[3],N1S_pp_pt3p5s_12[1]); 
   syst1S_aa_pt[4]= ppAlphaSyst(N1S_aa_pt3p5[4],N1S_aa_pt3p5s_20,N1B_aa_pt3p5s_20,N1S_pp_pt3p5[4],N1S_pp_pt3p5s_20[1]);
   // large bins of pT for 2S
   syst2S_aa_pt[0]=ppAlphaSyst(N2S_aa_pt4_2013Large[0],N2S_aa_pt4Larges_5,N2B_aa_pt4Larges_5,N2S_pp_pt4_2013Large[0],N2S_pp_pt4Larges_5[1]);
   syst2S_aa_pt[1]=ppAlphaSyst(N2S_aa_pt4_2013Large[1],N2S_aa_pt4Larges_12,N2B_aa_pt4Larges_12,N2S_pp_pt4_2013Large[1],N2S_pp_pt4Larges_12[1]);
   syst2S_aa_pt[2]=ppAlphaSyst(N2S_aa_pt4_2013Large[2],N2S_aa_pt4Larges_20,N2B_aa_pt4Larges_20,N2S_pp_pt4_2013Large[2],N2S_pp_pt4Larges_20[1]);
   // large pp PT bins for 2S
   syst2S_pp_ptLarge[0]=ppAlphaSyst(N2S_pp_pt4_2013Large[0],N2S_pp_pt4Larges_5,N2B_pp_pt4Larges_5,N2S_pp_pt4_2013Large[0],N2S_pp_pt4Larges_5[1]);
   syst2S_pp_ptLarge[1]=ppAlphaSyst(N2S_pp_pt4_2013Large[1],N2S_pp_pt4Larges_12,N2B_pp_pt4Larges_12,N2S_pp_pt4_2013Large[1],N2S_pp_pt4Larges_12[1]);
   syst2S_pp_ptLarge[2]=ppAlphaSyst(N2S_pp_pt4_2013Large[2],N2S_pp_pt4Larges_20,N2B_pp_pt4Larges_20,N2S_pp_pt4_2013Large[2],N2S_pp_pt4Larges_20[1]);
 
 
  for(int i = 0 ; i<nPtBins_2013 ; i++)
    {
      stat1S_aa_pt[i]=N1S_aa_pt3p5e[i]/N1S_aa_pt3p5[i];
      syst1S_aatnp_pt[i]=Aet_1S_pyquen_pt_fulls[i]/Aet_1S_pyquen_pt_STA[i]; //fulls is the full tnp syst (muidtrg+sta added in quadrature)
      syst1S_aags_pt[i]=Aet_1S_pyquen_pt_STAe[i]/Aet_1S_pyquen_pt_STA[i]; // doesnt matter if we use STA or MuID
      syst1S_aasta_pt[i]=Aet_1S_pyquen_pt_STAs[i]/Aet_1S_pyquen_pt_STA[i];
      syst1S_aamuid_pt[i]=Aet_1S_pyquen_pt_muIDTrigs[i]/Aet_1S_pyquen_pt_muIDTrig[i];
      syst1S_csaa_pt[i]=sqrt(syst1S_aatnp_pt[i]*syst1S_aatnp_pt[i]+syst1S_aa_pt[i]*syst1S_aa_pt[i]+pow(syst1S_aags_pt[i],2));
    }
  // large pt bins for Y(2S), pbpb and pp, and 1S large pp, large pbpb bins (for DR)
  for(int i = 0 ; i<nPtBins_2010 ; i++)
    {
      stat2S_aa_pt[i]= N2S_aa_pt4_2013Largee[i]/ N2S_aa_pt4_2013Large[i];
      syst2S_aatnp_pt[i]=Aet_2S_pyquen_pt2013Large_fulls[i]/Aet_2S_pyquen_pt2013Large[i]; //fulls is the full tnp syst (muidtrg+sta added in quadrature)
      syst2S_aags_pt[i]=Aet_2S_pyquen_pt2013Largee[i]/Aet_2S_pyquen_pt2013Large[i];
      syst2S_aasta_pt[i]=Aet_2S_pyquen_pt2013Large_STAe[i]/Aet_2S_pyquen_pt2013Large[i];
      syst2S_aamuid_pt[i]=Aet_2S_pyquen_pt2013Large_muIDTrige[i]/Aet_2S_pyquen_pt2013Large[i];
      syst2S_csaa_pt[i]=sqrt(syst2S_aatnp_pt[i]*syst2S_aatnp_pt[i]+syst2S_aa_pt[i]*syst2S_aa_pt[i]+pow(syst2S_aags_pt[i],2));
      
      stat2S_ppL_pt[i]= N2S_pp_pt4_2013Largee[i]/ N2S_pp_pt4_2013Large[i];
      syst2S_ppLtnp_pt[i]=Aet_2S_pythia_pt2013Larges[i]/Aet_2S_pythia_pt2013Large[i]; //fulls is the full tnp syst (muidtrg+sta added in quadrature)
      syst2S_ppLgs_pt[i]=Aet_2S_pythia_pt2013Largee[i]/Aet_2S_pythia_pt2013Large[i];
      syst2S_ppLsta_pt[i]=Aet_2S_pythia_pt2013Large_STAe[i]/Aet_2S_pythia_pt2013Large[i];
      syst2S_ppLmuid_pt[i]=Aet_2S_pythia_pt2013Large_muIDTrige[i]/Aet_2S_pythia_pt2013Large[i];
      syst2S_csppL_pt[i]=sqrt(syst2S_ppLtnp_pt[i]*syst2S_ppLtnp_pt[i]+syst2S_pp_ptLarge[i]*syst2S_pp_ptLarge[i]+pow(syst2S_ppLgs_pt[i],2));

    }
  /// 4.a Y(1S)
  for(int i = 0 ; i<nPtBins_2013 ; i++)
    {
      CS1S_aa_tnp_pt[i]= computeRatio( N1S_aa_pt3p5[i] , Aet_1S_pyquen_pt_STA[i] )/(N_MB_corr * T_AA_b*RapBinWidth*deltaPt[i]);
      CS1S_aa_tnp_pte[i] = computeRatioError( N1S_aa_pt3p5[i] , Aet_1S_pyquen_pt_STA[i], N1S_aa_pt3p5e[i] ,0)/(N_MB_corr * T_AA_b*RapBinWidth*deltaPt[i]);
      CS1S_aa_tnp_pts[i] = CS1S_aa_tnp_pt[i]*syst1S_csaa_pt[i];
    }
  /// 4.b,c,d,e Y(2S) pbpb, 2S pp, 1S pp, 1S aa
  for(int i = 0 ; i<nPtBins_2010 ; i++)
    {
      CS2S_aa_tnp_pt[i]= computeRatio(N2S_aa_pt4_2013Large[i] , Aet_2S_pyquen_pt2013Large[i] )/(N_MB_corr * T_AA_b*RapBinWidth*deltaPt_2010[i]);
      CS2S_aa_tnp_pte[i] = computeRatioError(N2S_aa_pt4_2013Large[i] , Aet_2S_pyquen_pt2013Large[i], N2S_aa_pt4_2013Largee[i] ,0)/(N_MB_corr * T_AA_b*RapBinWidth*deltaPt_2010[i]);
      CS2S_aa_tnp_pts[i] = CS2S_aa_tnp_pt[i]*syst2S_csaa_pt[i];
      //4.c 2S pp Large, computed with:
      //N2S pt4 in large bins,
      //Aet 2S in large bins (also pt4)
      //systematics in large bins with up to date TNP.
      CS2S_ppL_tnp_pt[i]= computeRatio(N2S_pp_pt4_2013Large[i] , Aet_2S_pythia_pt2013Large[i] )/(L_pp_invNb*RapBinWidth*deltaPt_2010[i]);
      CS2S_ppL_tnp_pte[i] = computeRatioError(N2S_pp_pt4_2013Large[i] , Aet_2S_pythia_pt2013Large[i], N2S_pp_pt4_2013Largee[i] ,0)/(L_pp_invNb*RapBinWidth*deltaPt_2010[i]);
      CS2S_ppL_tnp_pts[i] = CS2S_ppL_tnp_pt[i]*syst2S_csppL_pt[i];

    }
  ///5.a. Y(1S)
  ofSyst <<"1S PbPb Pt Bins | stat err. | syst err. = ( syst.fit +/- syst.gs +/- syst.muid +/- syst.sta ) +/- glob = ( syst.taa +/- syst.nmb +/- syst.trk )"<<endl;
   for(int j =0 ; j<nPtBins_2013 ; j++)
   {
     ofSyst <<  (binsPt[j]).c_str() << " & " << setprecision(3) << 
       stat1S_aa_pt[j] << " & " <<
       syst1S_csaa_pt[j] << " & " <<
       syst1S_aa_pt[j] << " & " <<
       syst1S_aags_pt[j] << " & " <<
       syst1S_aamuid_pt[j] << " & " <<
       syst1S_aasta_pt[j] << " & " <<
       syst_taa << " & " <<
       syst_nmb << " & " <<
       tracking_aa <<" \\\\ " << endl;
   }
   ofRes<<"1S PbPb Pt Bins | Cross section +/- stat err. +/- syst err. +/- global unc. "<<endl;
   for(int j =0 ; j<nPtBins_2013 ; j++)
   {
     ofRes << (binsPt[j]).c_str() << " & " << setprecision(3) << 
       CS1S_aa_tnp_pt[j] << " \\pm "<<
       CS1S_aa_tnp_pte[j]<<" \\pm "<<
       CS1S_aa_tnp_pts[j]<<" \\pm "<<
       CS1S_aa_tnp_pt[j]*systXS_aa_glob << " \\\\"
	  << endl;
   }
   
   ///5.b. Y(2S)
   ofSyst <<"2S PbPb Pt Bins | stat err. | syst err. = ( syst.fit +/- syst.gs +/- syst.muid +/- syst.sta ) +/- glob = ( syst.taa +/- syst.nmb +/- syst.trk )"<<endl;
   for(int j =0 ; j<nPtBins_2010 ; j++)
     {
     ofSyst <<  (binsPt2010[j]).c_str() << " & " << setprecision(3) << 
       stat2S_aa_pt[j] << " & " <<
       syst2S_csaa_pt[j] << " & " <<
       syst2S_aa_pt[j] << " & " <<
       syst2S_aags_pt[j] << " & " <<
       syst2S_aamuid_pt[j] << " & " <<
       syst2S_aasta_pt[j] << " & " <<
       syst_taa << " & " <<
       syst_nmb << " & " <<
       tracking_aa <<" \\\\ " << endl;
   }

   ofRes<<"2S PbPb Pt Bins | Cross section +/- stat err. +/- syst err. +/- global unc. "<<endl;
   for(int j =0 ; j<nPtBins_2010 ; j++)
     {
     ofRes << (binsPt2010[j]).c_str() << " & " << setprecision(3) << 
       CS2S_aa_tnp_pt[j] << " \\pm "<<
       CS2S_aa_tnp_pte[j]<<" \\pm "<<
       CS2S_aa_tnp_pts[j]<<" \\pm "<<
       CS2S_aa_tnp_pt[j]*systXS_pp_glob << " \\\\"
	  << endl;
   }
   
   ///5.c. Y(2S) pp Large
  ofSyst <<"2S pp large Pt Bins | stat err. | syst err. = +/- syst.fit +/- syst.gs +/- syst.muid +/- syst.sta +/- syst.lumi +/- syst.trk"<<endl;
   for(int j =0 ; j<nPtBins_2010 ; j++)
   {
     ofSyst <<  (binsPt2010[j]).c_str() << " & " << setprecision(3) << 
       stat2S_ppL_pt[j] << " & " <<
       syst2S_csppL_pt[j] << " & " <<
       syst2S_pp_ptLarge[j] << " & " <<
       syst2S_ppLgs_pt[j] << " & " <<
       syst2S_ppLmuid_pt[j] << " & " <<
       syst2S_ppLsta_pt[j] << " & " <<
       syst_lumi << " & " <<
       tracking_pp <<" \\\\ " << endl;
   }
   ofRes<<"2S pp Pt Large Bins | Cross section +/- stat err. +/- syst err. +/- global unc. "<<endl;
   for(int j =0 ; j<nPtBins_2010 ; j++)
   {
     ofRes << (binsPt2010[j]).c_str() << " & " << setprecision(3) << 
       CS2S_ppL_tnp_pt[j] << " \\pm "<<
       CS2S_ppL_tnp_pte[j]<<" \\pm "<<
       CS2S_ppL_tnp_pts[j]<<" \\pm "<<
       CS2S_ppL_tnp_pt[j]*systXS_pp_glob << "  \\\\"
	  << endl;
   }

   /// 6.a plot AA cross section
   gStyle->SetPadRightMargin(0.025); //overriding style for the pt-binned plots only, but will have to change again later...
   TCanvas *cptaa = new TCanvas("cptaa","cptaa"); 
   cptaa->SetLogy();
   cptaa->cd();
   TF1 *f4Ptaa = new TF1("f4Ptaa","10",0,20);
   f4Ptaa->SetLineWidth(0);
   f4Ptaa->GetXaxis()->SetTitle("p_{T}^{#varUpsilon} (GeV/c)");		
   f4Ptaa->GetYaxis()->SetTitle("#frac{1}{T_{AA}} #frac{d^{2}N}{dy dp_{T}}  (nb/ GeV/c)");
   
   f4Ptaa->GetXaxis()->SetTitleSize(gTextSize+0.01);
   f4Ptaa->GetXaxis()->SetTitleOffset(f4Ptaa->GetXaxis()->GetTitleOffset()*1.1);
   f4Ptaa->GetYaxis()->SetTitleSize(gTextSize);
   f4Ptaa->GetYaxis()->SetLabelSize(0.8*f4Ptaa->GetYaxis()->GetLabelSize()); //  Y axis title is fat
   f4Ptaa->GetYaxis()->SetTitleOffset(1.65);
   f4Ptaa->GetYaxis()->SetRangeUser(0.0001,0.2);
   //f4Ptaa->GetYaxis()->SetRangeUser(0.01,.09);
   f4Ptaa->GetXaxis()->CenterTitle(kTRUE);
   f4Ptaa->Draw();
   TGraphErrors *gpt1TNPaa = new TGraphErrors(nPtBins_2013,pt,CS1S_aa_tnp_pt,0,CS1S_aa_tnp_pte);
   gpt1TNPaa->SetMarkerColor(color1Saa);
   gpt1TNPaa->SetMarkerStyle(symbol1S);
   gpt1TNPaa->SetMarkerSize(markerSize);
   TGraphErrors *gpt1circleaa = new TGraphErrors(nPtBins_2013,pt,CS1S_aa_tnp_pt,0,CS1S_aa_tnp_pte);
   gpt1circleaa->SetMarkerStyle(symbol1Sc);
   gpt1circleaa->SetMarkerSize(markerSize);
   gpt1circleaa->SetLineColor(kBlack);
   gpt1circleaa->SetLineWidth(2);
   TGraphErrors *gPt1aasyst = new TGraphErrors(nPtBins_2013,pt,CS1S_aa_tnp_pt,pte,CS1S_aa_tnp_pts);
   gPt1aasyst->SetLineColor(color1Saa);
   gPt1aasyst->SetFillStyle(0);
   gPt1aasyst->SetLineWidth(2);
   gPt1aasyst->SetMarkerSize(0);
   gPt1aasyst->Draw("2");
   gpt1TNPaa->Draw("pe");
   gpt1circleaa->Draw("p");
   TGraphErrors *gpt2TNPaa = new TGraphErrors(nPtBins_2010,pt2010,CS2S_aa_tnp_pt,0,CS2S_aa_tnp_pte);
   gpt2TNPaa->SetMarkerColor(color2Saa);
   gpt2TNPaa->SetMarkerStyle(symbol2S);
   gpt2TNPaa->SetMarkerSize(markerSize);
   TGraphErrors *gpt2circleaa = new TGraphErrors(nPtBins_2010,pt2010,CS2S_aa_tnp_pt,0,CS2S_aa_tnp_pte);
   gpt2circleaa->SetMarkerStyle(symbol2Sc);
   gpt2circleaa->SetMarkerSize(markerSize);
   gpt2circleaa->SetLineColor(kBlack);
   gpt2circleaa->SetLineWidth(2);
   TGraphErrors *gPt2aasyst = new TGraphErrors(nPtBins_2010,pt2010,CS2S_aa_tnp_pt,pt2010e,CS2S_aa_tnp_pts);
   gPt2aasyst->SetLineColor(color2Saa);
   gPt2aasyst->SetFillStyle(0);
   gPt2aasyst->SetLineWidth(2);
   gPt2aasyst->SetMarkerSize(0);
   gPt2aasyst->Draw("2");
   gpt2TNPaa->Draw("pe");
   gpt2circleaa->Draw("p");
   TLegend *legend_csaapt = new TLegend(0.22,0.15,0.45,0.28);
   legend_csaapt->SetTextSize(gTextSize);
   legend_csaapt->SetFillStyle(0);
   legend_csaapt->SetFillColor(0);
   legend_csaapt->SetBorderSize(0);
   legend_csaapt->SetTextFont(42);
   legend_csaapt->AddEntry(gpt1TNPaa,"#varUpsilon(1S) ","p"); 
   legend_csaapt->AddEntry(gpt2TNPaa,"#varUpsilon(2S) ","p");
   legend_csaapt->Draw();
   

   if (!plotLin && !plotBox) {
   TLatex latexptaa;
   latexptaa.SetTextSize(gTextSize);
   latexptaa.SetTextFont(42);
   TLatex *latexpttxtaa = latexptaa.DrawLatex(15.7,0.01,"|y| < 2.4");
   latexpttxtaa->DrawLatex(1.5,0.0005,Form("Global uncertainty: %.1f",100*systXS_aa_glob));
   latexpttxtaa->DrawLatex(10.6,0.0005,"%"); /// 
   }

   CMS_lumi(cptaa,104,33);
   cptaa->Update();
   cptaa->RedrawAxis();
   cptaa->GetFrame()->Draw();
   cptaa->SaveAs(basedir2 + TString("/CS_aa_Pt.pdf"));
   cptaa->SaveAs(basedir2 + TString("/CS_aa_Pt.png"));
   cptaa->SaveAs(basedir1 + TString("/pdf/Xsection_aaNS_Pt.pdf"));
   cptaa->SaveAs(basedir1 + TString("/png/Xsection_aaNS_Pt.png"));

   if (plotLin)
     {
       cptaa->SetLogy(0);
       legend_csaapt->SetX1NDC(0.77); legend_csaapt->SetX2NDC(1.); legend_csaapt->SetY1NDC(0.50); legend_csaapt->SetY2NDC(0.67); legend_csaapt->Draw();
       TLatex latexptaaLin;
       latexptaaLin.SetTextSize(gTextSize);
       latexptaaLin.SetTextFont(42);
       TLatex *latexpttxtaaLin = latexptaaLin.DrawLatex(15.7,0.037,"|y| < 2.4");
       if (!plotBox){
	 latexpttxtaaLin->DrawLatex(1.5,0.004,Form("Global uncertainty: %.1f",100*systXS_aa_glob));
	 latexpttxtaaLin->DrawLatex(10.5,0.004,"%"); /// 
       }
       cptaa->cd();
       gPad->Update();
       f4Ptaa->GetYaxis()->SetRangeUser(0.,0.05);
       f4Ptaa->GetYaxis()->SetTitleOffset(1.75);
       f4Ptaa->GetYaxis()->SetTitleSize(0.04);
       f4Ptaa->GetYaxis()->SetLabelSize(0.8*f4Ptaa->GetYaxis()->GetLabelSize());
       gPad->Update();
       gPad->RedrawAxis();
       gPad->GetFrame()->Draw();
       cptaa->SaveAs(basedir2 + TString("/CSNS_aaPt_lin.pdf"));
       cptaa->SaveAs(basedir2 + TString("/CSNS_aaPt_lin.png"));
       cptaa->SaveAs(basedir1 + TString("/pdf/Xsection_aaNS_Pt_lin.pdf"));
       cptaa->SaveAs(basedir1 + TString("/png/Xsection_aaNS_Pt_lin.png"));
     }

   cptaa->Close();


     
   ///===============================
   /// RAA vs Pt
   ///===============================
   /// 1. Define variables
   /// 2. Define syst variables
   /// 3. Compute the syst
   /// 4. Compute the CS.
   /// 5. Print the outputs
   /// 6. Draw and save
   ///-------------------------------
   /// 1.a. Y(1S)
   float RAA_1S_tnp_pt[nPtBins_2013] = {};
   float RAA_1S_tnp_pte[nPtBins_2013] = {};
   float RAA_1S_tnp_pts[nPtBins_2013] = {};
   /// 1.b. Y(2S)
   float RAA_2S_tnp_pt[nPtBins_2010] = {};
   float RAA_2S_tnp_pte[nPtBins_2010] = {};
   float RAA_2S_tnp_pts[nPtBins_2010] = {};
   /// 1.c. Y(1S) large
   float RAA_1S_tnp_ptL[nPtBins_2010] = {};
   float RAA_1S_tnp_ptLe[nPtBins_2010] = {};
   float RAA_1S_tnp_ptLs[nPtBins_2010] = {};
   /// 2.a Y(1S)
   float syst1S_raa_pt[nPtBins_2013]={}; /// quadratic sum of all systematic uncertainties but the global scale uncertainties.
   /// 2.b Y(2S)
   float syst2S_raa_pt[nPtBins_2010]={}; /// quadratic sum
   /// 2.c Y(1S) large
   float syst1S_raa_ptL[nPtBins_2010]={}; /// quadratic sum
   //3.a Y(1S)
   // The global uncertainty is the same for all upsilons (vs. pt and y)
   float systXS_raa_glob = sqrt(pow(tracking_pp,2)+pow(tracking_aa,2)+pow(L_pp_e,2)+pow(T_AA_e,2)+pow(syst_nmb,2));
   for(int i =0 ; i<nPtBins_2013 ; i++)
     {
       syst1S_raa_pt[i]=sqrt(pow(stat1S_pp_pt[i],2)+syst1S_pptnp_pt[i]*syst1S_pptnp_pt[i]+syst1S_pp_pt[i]*syst1S_pp_pt[i]+pow(syst1S_ppgs_pt[i],2)+syst1S_aatnp_pt[i]*syst1S_aatnp_pt[i]+syst1S_aa_pt[i]*syst1S_aa_pt[i]+pow(syst1S_aags_pt[i],2)); /// all the ones varying point-to-point, and nothing else:
       // pp_fit, pp_gs, pp_tnp, pp_stat, aa_fit, aa_gs, aa_tnp (7 sources).
       // In other words, this is: stat_pp +/- syst.cspp +/- syst.csaa
     }
   //3.b Y(2S)
   for(int i =0 ; i<nPtBins_2010 ; i++)
     {
       syst2S_raa_pt[i]=sqrt(pow(stat2S_ppL_pt[i],2)+syst2S_ppLtnp_pt[i]*syst2S_ppLtnp_pt[i]+syst2S_pp_ptLarge[i]*syst2S_pp_ptLarge[i]+pow(syst2S_ppLgs_pt[i],2)+syst2S_aatnp_pt[i]*syst2S_aatnp_pt[i]+syst2S_aa_pt[i]*syst2S_aa_pt[i]+pow(syst2S_aags_pt[i],2)); /// all the ones varying point-to-point
     }
   /// 4.a Y(1S)
   for(int i = 0 ; i<nPtBins_2013 ; i++)
     {
       RAA_1S_tnp_pt[i]=CS1S_aa_tnp_pt[i]/CS1S_pp_tnp_pt[i];
       RAA_1S_tnp_pte[i]=computeRatioError( CS1S_aa_tnp_pt[i] , CS1S_pp_tnp_pt[i], CS1S_aa_tnp_pte[i] , 0);
       RAA_1S_tnp_pts[i]=RAA_1S_tnp_pt[i]*syst1S_raa_pt[i];
     }
   /// 4.b Y(2S)
   for(int i = 0 ; i<nPtBins_2010 ; i++)
     {
       RAA_2S_tnp_pt[i]=CS2S_aa_tnp_pt[i]/CS2S_ppL_tnp_pt[i];
       RAA_2S_tnp_pte[i]=computeRatioError( CS2S_aa_tnp_pt[i] , CS2S_ppL_tnp_pt[i], CS2S_aa_tnp_pte[i] , 0);
       RAA_2S_tnp_pts[i]=RAA_2S_tnp_pt[i]*syst2S_raa_pt[i];
     }
   /// 5.a Y(1S)
   //// for the printing of the RAA sources of syst, we have:
   //// 7 sources varying point by point (tnp,fit,gs)_pp/aa + stat pp. but we may want to split the tnp syst to see how all the systematics compare (sta_aa vs sta_pp, etc). so there's a lot of columns. I will think about a nice way to put all this in tables
   ofSyst <<"1S RAA Pt Bins | stat err. | syst err. = syst.csaa = (syst.fit +/- syst.gs +/- syst.muid +/- syst.sta) +/- stat.pp +/- syst.cspp = ( syst.pp.fit +/- syst.pp.gs +/- syst.pp.muid +/- syst.pp.sta) | syst glob. = +/- syst.taa +/- syst.trk.aa +/- syst.nmb +/- syst.lumi +/- syst.trk.pp"<<endl;
   for(int j =0 ; j<nPtBins_2013 ; j++)
     {
       ofSyst <<  (binsPt[j]).c_str() << " & " << setprecision(2) << 
	 stat1S_aa_pt[j]     << " & " <<
	 syst1S_raa_pt[j]    << " & " <<
	 syst1S_csaa_pt[j]   << " & " <<
	 syst1S_aa_pt[j]     << " & " <<
	 syst1S_aags_pt[j]   << " & " <<
	 syst1S_aamuid_pt[j] << " & " <<
	 syst1S_aasta_pt[j]  << " & " <<
	 stat1S_pp_pt[j]     << " & " <<
	 syst1S_cspp_pt[j]   << " & " <<
	 syst1S_pp_pt[j]     << " & " <<
	 syst1S_ppgs_pt[j]   << " & " <<
	 syst1S_ppmuid_pt[j] << " & " <<
	 syst1S_ppsta_pt[j]  << " & " <<
	 systXS_raa_glob     << " & " <<
	 syst_taa            << " & " <<
	 tracking_aa         << " & " <<
	 syst_nmb            << " & " <<
	 syst_lumi           << " & " <<
	 tracking_pp <<" \\\\ " << endl;
     }
   /// for tables
   ofRes<<"1S RAA Pt Bins | RAA +/- stat err. +/- syst err. +/- global unc. "<<endl;
   for(int j =0 ; j<nPtBins_2013 ; j++)
     {
       ofRes << (binsPt[j]).c_str() << " & " << setprecision(3) << 
	 RAA_1S_tnp_pt[j] << " \\pm "<<
	 RAA_1S_tnp_pte[j]<<" \\pm "<<
	 RAA_1S_tnp_pts[j]<<" \\pm "<<
	 RAA_1S_tnp_pt[j]*systXS_raa_glob << " \\\\"
	     << endl;
     }
   /// for plots, to share with your friends on facebook
   ofplot<<"float raa1Spt["<<nPtBins_2013<<"]={";
   for(int j =0 ; j<nPtBins_2013 ; j++)
     {
       ofplot <<RAA_1S_tnp_pt[j]; if (j==nPtBins_2013-1) ofplot<<"};"<<endl; else ofplot<<",";
     }
   ofplot<<"float raa1Spt_e["<<nPtBins_2013<<"]={";
   for(int j =0 ; j<nPtBins_2013 ; j++)
     {
       ofplot <<RAA_1S_tnp_pte[j]; if (j==nPtBins_2013-1) ofplot<<"};"<<endl; else ofplot<<",";
     }
   ofplot<<"float raa1Spt_s["<<nPtBins_2013<<"]={";
   for(int j =0 ; j<nPtBins_2013 ; j++)
     {
       ofplot <<RAA_1S_tnp_pts[j]; if (j==nPtBins_2013-1) ofplot<<"};"<<endl; else ofplot<<",";
     }
   ofplot<<"float ptbin["<<nPtBins_2013<<"]={";
   for(int j =0 ; j<nPtBins_2013 ; j++)
     {
       ofplot <<pt[j]; if (j==nPtBins_2013-1) ofplot<<"};"<<endl; else ofplot<<",";
     }
   ofplot<<"float ptbine["<<nPtBins_2013<<"]={";
   for(int j =0 ; j<nPtBins_2013 ; j++)
     {
       ofplot <<pte[j]; if (j==nPtBins_2013-1) ofplot<<"};"<<endl; else ofplot<<",";
     }
   
   /// 5.b Y(2S)
   ofSyst <<"2S RAA Pt Bins | stat err. | syst err. = syst.csaa = (syst.fit +/- syst.gs +/- syst.muid +/- syst.sta) +/- stat.pp +/- syst.cspp = ( syst.pp.fit +/- syst.pp.gs +/- syst.pp.muid +/- syst.pp.sta) | syst glob. = +/- syst.taa +/- syst.trk.aa +/- syst.nmb +/- syst.lumi +/- syst.trk.pp"<<endl;
   for(int j =0 ; j<nPtBins_2010 ; j++)
     {
       ofSyst <<  (binsPt2010[j]).c_str() << " & " << setprecision(2) << 
	 stat2S_aa_pt[j]     << " & " <<
	 syst2S_raa_pt[j]    << " & " <<
	 syst2S_csaa_pt[j]   << " & " <<
	 syst2S_aa_pt[j]     << " & " <<
	 syst2S_aags_pt[j]   << " & " <<
	 syst2S_aamuid_pt[j] << " & " <<
	 syst2S_aasta_pt[j]  << " & " <<
	 stat2S_ppL_pt[j]     << " & " <<
	 syst2S_csppL_pt[j]   << " & " <<
	 syst2S_pp_ptLarge[j]     << " & " <<
	 syst2S_ppLgs_pt[j]   << " & " <<
	 syst2S_ppLmuid_pt[j] << " & " <<
	 syst2S_ppLsta_pt[j]  << " & " <<
	 systXS_raa_glob     << " & " <<
	 syst_taa            << " & " <<
	 tracking_aa         << " & " <<
	 syst_nmb            << " & " <<
	 syst_lumi           << " & " <<
	 tracking_pp <<" \\\\ " << endl;
     }
   /// for tables
   ofRes<<"2S RAA Pt Bins | RAA +/- stat err. +/- syst err. +/- global unc. "<<endl;
   for(int j =0 ; j<nPtBins_2010 ; j++)
     {
       ofRes << (binsPt2010[j]).c_str() << " & " << setprecision(3) << 
	 RAA_2S_tnp_pt[j] << " \\pm "<<
	 RAA_2S_tnp_pte[j]<<" \\pm "<<
	 RAA_2S_tnp_pts[j]<<" \\pm "<<
	 RAA_2S_tnp_pt[j]*systXS_raa_glob << " \\\\"
	     << endl;
     }

   /// for plots, to share with your friends on facebook
   ofplot<<"float raa2Spt["<<nPtBins_2010<<"]={";
   for(int j =0 ; j<nPtBins_2010 ; j++)
     {
       ofplot <<RAA_2S_tnp_pt[j]; if (j==nPtBins_2010-1) ofplot<<"};"<<endl; else ofplot<<",";
     }
   ofplot<<"float raa2Spt_e["<<nPtBins_2010<<"]={";
   for(int j =0 ; j<nPtBins_2010 ; j++)
     {
       ofplot <<RAA_2S_tnp_pte[j]; if (j==nPtBins_2010-1) ofplot<<"};"<<endl; else ofplot<<",";
     }
   ofplot<<"float raa2Spt_s["<<nPtBins_2010<<"]={";
   for(int j =0 ; j<nPtBins_2010 ; j++)
     {
       ofplot <<RAA_2S_tnp_pts[j]; if (j==nPtBins_2010-1) ofplot<<"};"<<endl; else ofplot<<",";
     }   
   ofplot<<"float ptbin2["<<nPtBins_2010<<"]={";
   for(int j =0 ; j<nPtBins_2010 ; j++)
     {
       ofplot <<pt2010[j]; if (j==nPtBins_2010-1) ofplot<<"};"<<endl; else ofplot<<",";
     }
   ofplot<<"float ptbin2e["<<nPtBins_2010<<"]={";
   for(int j =0 ; j<nPtBins_2010 ; j++)
     {
       ofplot <<pt2010e[j]; if (j==nPtBins_2010-1) ofplot<<"};"<<endl; else ofplot<<",";
     }
   
   // 6. RAA pt plot
   TCanvas *cRaapt = new TCanvas("cRaapt","cRaapt"); 
   cRaapt->cd();
   TF1 *f4RaaPt = new TF1("f4RaaPt","1",0,20);
   f4RaaPt->SetLineWidth(1);
   f4RaaPt->SetLineColor(kBlack);
   f4RaaPt->GetXaxis()->SetTitle("p_{T}^{#varUpsilon} (GeV/c)");
   f4RaaPt->GetYaxis()->SetTitle("R_{AA}");
   f4RaaPt->GetXaxis()->SetTitleOffset(f4RaaPt->GetXaxis()->GetTitleOffset()*1.1);
   f4RaaPt->GetXaxis()->SetTitleSize(gTextSize+0.01);
   f4RaaPt->GetYaxis()->SetRangeUser(0.,1.2);
   f4RaaPt->GetXaxis()->CenterTitle(kTRUE);
   f4RaaPt->Draw();
   TGraphErrors *gpt1TNPRAA = new TGraphErrors(nPtBins_2013,pt,RAA_1S_tnp_pt,0,RAA_1S_tnp_pte);
   gpt1TNPRAA->SetMarkerColor(color1Sraa);
   gpt1TNPRAA->SetMarkerStyle(symbol1S);
   gpt1TNPRAA->SetMarkerSize(markerSize);
   TGraphErrors *gpt1circleRAA = new TGraphErrors(nPtBins_2013,pt,RAA_1S_tnp_pt,0,RAA_1S_tnp_pte);
   gpt1circleRAA->SetMarkerStyle(symbol1Sc);
   gpt1circleRAA->SetMarkerSize(markerSize);
   gpt1circleRAA->SetLineColor(kBlack);
   gpt1circleRAA->SetLineWidth(2);
   TGraphErrors *gPt1RAAsyst = new TGraphErrors(nPtBins_2013,pt,RAA_1S_tnp_pt,pte,RAA_1S_tnp_pts);
   gPt1RAAsyst->SetLineColor(color1Sraa);
   gPt1RAAsyst->SetFillStyle(0);
   gPt1RAAsyst->SetLineWidth(2);
   gPt1RAAsyst->SetMarkerSize(0);
   // drawing theory stuff
    //M.Strickland data part
      ////Strickland comparisons are now based on his '5TeV predictions' paper, which has 2.76 as a reference. The advantage is basically more points on the prediction curve, except on the pt curve. Check out https://arxiv.org/src/1605.03561v1/anc
      float pt_th[6];       float pt2_th[6];
      float raa1Spt_the1x0[6], raa1Spt_the2x0[6], raa1Spt_the3x0[6];
      float raa2Spt_the1x0[6], raa2Spt_the2x0[6], raa2Spt_the3x0[6];
      ifstream ipt1Sx0;
      ifstream ipt2Sx0;
      // this is the input file for 1Srap and xi=0
      ipt1Sx0.open("Strick_Pt_1S_xi0.tsv");
      ipt2Sx0.open("Strick_Pt_2S_xi0.tsv");
      for (int i=0; i<6;i++){
	ipt1Sx0>> pt_th[i]>> raa1Spt_the1x0[i]>> raa1Spt_the2x0[i]>> raa1Spt_the3x0[i];
	ipt2Sx0>> pt2_th[i]>> raa2Spt_the1x0[i]>> raa2Spt_the2x0[i]>> raa2Spt_the3x0[i];
      }
      TGraph *sups1Spt1x0 = new TGraph(5,pt_th,raa1Spt_the1x0);
      sups1Spt1x0->SetLineWidth(2);
      sups1Spt1x0->SetLineColor(color1Sraa);
      sups1Spt1x0->SetLineStyle(1);
      sups1Spt1x0->Draw("l same");
      TGraph *sups1Spt2x0 = new TGraph(5,pt_th,raa1Spt_the2x0);
      sups1Spt2x0->SetLineWidth(2);
      sups1Spt2x0->SetLineColor(color1Sraa);
      sups1Spt2x0->SetLineStyle(2);
      sups1Spt2x0->Draw("l same");
      TGraph *sups1Spt3x0 = new TGraph(5,pt_th,raa1Spt_the3x0);
      sups1Spt3x0->SetLineWidth(2);
      sups1Spt3x0->SetLineColor(color1Sraa);
      sups1Spt3x0->SetLineStyle(3);
      sups1Spt3x0->Draw("l same");
      TGraph *sups2Spt1x0 = new TGraph(3,pt2_th,raa2Spt_the1x0);
      sups2Spt1x0->SetLineWidth(2);
      sups2Spt1x0->SetLineColor(color2Sraa);
      sups2Spt1x0->SetLineStyle(1);
      sups2Spt1x0->Draw("l same");
      TGraph *sups2Spt2x0 = new TGraph(3,pt2_th,raa2Spt_the2x0);
      sups2Spt2x0->SetLineWidth(2);
      sups2Spt2x0->SetLineColor(color2Sraa);
      sups2Spt2x0->SetLineStyle(2);
      sups2Spt2x0->Draw("l same");
      TGraph *sups2Spt3x0 = new TGraph(3,pt2_th,raa2Spt_the3x0);
      sups2Spt3x0->SetLineWidth(2);
      sups2Spt3x0->SetLineColor(color2Sraa);
      sups2Spt3x0->SetLineStyle(3);
      sups2Spt3x0->Draw("l same");
      TLegend *legR2= new TLegend(0.45,0.69,0.8,0.75);
      legR2->SetBorderSize(0);
      legR2->SetTextSize(gTextSize-0.01);
      legR2->SetTextFont(42);
      legR2->SetLineColor(0);
      legR2->SetLineStyle(1);
      legR2->SetLineWidth(2);
      legR2->SetFillColor(0);
      legR2->SetFillStyle(0);
      TLegend *legR3 = new TLegend(0.45,0.55,0.8,0.7);
      legR3->SetBorderSize(0);
      legR3->SetTextSize(gTextSize-0.01);
      legR3->SetTextFont(42);
      legR3->SetLineColor(0);
      legR3->SetLineStyle(2);
      legR3->SetLineWidth(1);
      legR3->SetFillColor(0);
      legR3->SetFillStyle(0);
      legR3->SetHeader("Strickland et al., Universe 2016, 2(3), 16");
      legR2->SetHeader("");
      legR3->AddEntry(sups1Spt3x0," 4#pi#eta/s = 3","L");
      legR3->AddEntry(sups1Spt2x0," 4#pi#eta/s = 2","L");
      legR3->AddEntry(sups1Spt1x0," 4#pi#eta/s = 1","L");
     
      legR2->Draw();
      legR3->Draw();
      
   gPt1RAAsyst->Draw("2");
   gpt1TNPRAA->Draw("pe");
   gpt1circleRAA->Draw("p");
   TGraphErrors *gpt2TNPRAA = new TGraphErrors(nPtBins_2010,pt2010,RAA_2S_tnp_pt,0,RAA_2S_tnp_pte);
   gpt2TNPRAA->SetMarkerColor(color2Sraa);
   gpt2TNPRAA->SetMarkerStyle(symbol2S);
   gpt2TNPRAA->SetMarkerSize(markerSize);
   TGraphErrors *gpt2circleRAA = new TGraphErrors(nPtBins_2010,pt2010,RAA_2S_tnp_pt,0,RAA_2S_tnp_pte);
   gpt2circleRAA->SetMarkerStyle(symbol2Sc);
   gpt2circleRAA->SetMarkerSize(markerSize);
   gpt2circleRAA->SetLineColor(kBlack);
   gpt2circleRAA->SetLineWidth(2);
   TGraphErrors *gPt2RAAsyst = new TGraphErrors(nPtBins_2010,pt2010,RAA_2S_tnp_pt,pt2010e,RAA_2S_tnp_pts);
   gPt2RAAsyst->SetLineColor(color2Sraa);
   gPt2RAAsyst->SetFillStyle(0);
   gPt2RAAsyst->SetLineWidth(2);
   gPt2RAAsyst->SetMarkerSize(0);
   gPt2RAAsyst->Draw("2");
   gpt2TNPRAA->Draw("pe");
   gpt2circleRAA->Draw("p");

   TLegend *legend_RAApt = new TLegend(0.24,0.5,0.49,0.66);
   legend_RAApt->SetTextSize(gTextSize);
   legend_RAApt->SetFillStyle(0);
   legend_RAApt->SetFillColor(0);
   legend_RAApt->SetBorderSize(0);
   legend_RAApt->SetTextFont(42);
   legend_RAApt->AddEntry(gpt1TNPRAA,"#varUpsilon(1S) ","p"); 
   legend_RAApt->AddEntry(gpt2TNPRAA,"#varUpsilon(2S) ","p");
   legend_RAApt->Draw();
   
   // Cent. 0-100 %
   TLatex latexptRaa;
   latexptRaa.SetTextSize(gTextSize);
   latexptRaa.SetTextFont(42);
   latexptRaa.DrawLatex(1.5,1.08,"Cent. 0-100%, |y| < 2.4"); // y=1.2 before
   if (!plotBox) {
     latexptRaa.DrawLatex(1.5,0.83,Form("Global uncertainty: %.1f",100*systXS_raa_glob));
     latexptRaa.DrawLatex(10.5,0.83,"%"); /// y=1.1 before
   } else{
   /// plotBox goes here.
     TBox *boxPt = new TBox(19,1-systXS_raa_glob,20,1+systXS_raa_glob); 
     boxPt->SetFillColor(kGray);
     boxPt->Draw();
   }
   CMS_lumi(cRaapt,104,33);
   cRaapt->Update();
   cRaapt->RedrawAxis();
   cRaapt->GetFrame()->Draw();
   // cRaapt->SaveAs(basedir2 + TString("/RAA_Pt.pdf"));
   // cRaapt->SaveAs(basedir2 + TString("/RAA_Pt.png"));
   // cRaapt->SaveAs(basedir1 + TString("/pdf/RAA_Pt.pdf"));
   // cRaapt->SaveAs(basedir1 + TString("/png/RAA_Pt.png"));

    cRaapt->SaveAs(basedir2 + TString("/RAA_Pt_Strickland.pdf"));	 
    cRaapt->SaveAs(basedir2 + TString("/RAA_Pt_Strickland.png"));	 
    cRaapt->SaveAs(basedir1 + TString("/pdf/RAA_Pt_Strickland.pdf"));
    cRaapt->SaveAs(basedir1 + TString("/png/RAA_Pt_Strickland.png"));///===============================
   /// (PbPb cross sections + pp cross sections in Large Bins) vs Rap
   ///===============================
   /// 1. Define variables
   /// 2. Define syst variables
   /// 3. Compute the syst
   /// 4. Compute the CS.
   /// 5. Print the outputs
   /// 6. Draw and save
   ///-------------------------------
   /// 1.a. Y(1S)
   float CS1S_aa_tnp_rap[nRapBins_2014] = {};
   float CS1S_aa_tnp_rape[nRapBins_2014] = {};
   float CS1S_aa_tnp_raps[nRapBins_2014] = {};

   /// 1.b. Y(2S)
   float CS2S_aa_tnp_rap[nRapBins_2010] = {};
   float CS2S_aa_tnp_rape[nRapBins_2010] = {};
   float CS2S_aa_tnp_raps[nRapBins_2010] = {};

   /// 1.d. Y(2S) pp large
   float CS2S_ppL_tnp_rap[nRapBins_2010] = {};
   float CS2S_ppL_tnp_rape[nRapBins_2010] = {};
   float CS2S_ppL_tnp_raps[nRapBins_2010] = {};

   /// 2.a Y(1S)
   float stat1S_aa_rap[nRapBins_2014]={}; //stat. aa relative uncertainty (contributing to R_AA as a pt to pt syst. uncertainty!
   float syst1S_aatnp_rap[nRapBins_2014]={};// tnp uncertainty
   float syst1S_aa_rap[nRapBins_2014]={};   //fit syst. uncertainty.
   float syst1S_aags_rap[nRapBins_2014]={};   //gen shape
   float syst1S_aasta_rap[nRapBins_2014]={}; ///sta uncertainty
   float syst1S_aamuid_rap[nRapBins_2014]={};/// muid uncertainty
   float syst1S_csaa_rap[nRapBins_2014]={}; /// quadratic sum.

   /// 2.b Y(2S)
   float stat2S_aa_rap[nRapBins_2010]={}; //stat. aa relative uncertainty (contributing to R_AA as a rap to rap syst. uncertainty!
   float syst2S_aatnp_rap[nRapBins_2010]={};// tnp uncertainty
   float syst2S_aa_rap[nRapBins_2010]={};   //fit syst. uncertainty.
   float syst2S_aags_rap[nRapBins_2010]={};   //gen shape
   float syst2S_aasta_rap[nRapBins_2010]={}; ///sta uncertainty
   float syst2S_aamuid_rap[nRapBins_2010]={};/// muid uncertainty
   float syst2S_csaa_rap[nRapBins_2010]={}; /// quadratic sum.

   /// 2.d Y(2S)
   float stat2S_ppL_rap[nRapBins_2010]={}; //stat. aa relative uncertainty (contributing to R_AA as a rap to rap syst. uncertainty!
   float syst2S_ppLtnp_rap[nRapBins_2010]={};// tnp uncertainty
   float syst2S_pp_rapLarge[nRapBins_2010]={};   //fit syst. uncertainty.
   float syst2S_ppLgs_rap[nRapBins_2010]={};   //gen shape
   float syst2S_ppLsta_rap[nRapBins_2010]={}; ///sta uncertainty
   float syst2S_ppLmuid_rap[nRapBins_2010]={};/// muid uncertainty
   float syst2S_csppL_rap[nRapBins_2010]={}; /// quadratic sum.

   /// 3.
   syst1S_aa_rap[0]= ppAlphaSyst(N1S_aa_rap3p5_2014[0],N1S_aa_rap3p5s_0p4,N1B_aa_rap3p5s_0p4,N1S_pp_rap3p5_2014[0],N1S_pp_rap3p5s_0p4[1]);
   syst1S_aa_rap[1]= ppAlphaSyst(N1S_aa_rap3p5_2014[1],N1S_aa_rap3p5s_0p8,N1B_aa_rap3p5s_0p8,N1S_pp_rap3p5_2014[1],N1S_pp_rap3p5s_0p8[1]);
   syst1S_aa_rap[2]= ppAlphaSyst(N1S_aa_rap3p5_2014[2],N1S_aa_rap3p5s_1p2,N1B_aa_rap3p5s_1p2,N1S_pp_rap3p5_2014[2],N1S_pp_rap3p5s_1p2[1]);
   syst1S_aa_rap[3]= ppAlphaSyst(N1S_aa_rap3p5_2014[3],N1S_aa_rap3p5s_1p6,N1B_aa_rap3p5s_1p6,N1S_pp_rap3p5_2014[3],N1S_pp_rap3p5s_1p6[1]);
   syst1S_aa_rap[4]= ppAlphaSyst(N1S_aa_rap3p5_2014[4],N1S_aa_rap3p5s_2p0,N1B_aa_rap3p5s_2p0,N1S_pp_rap3p5_2014[4],N1S_pp_rap3p5s_2p0[1]);
   syst1S_aa_rap[5]= ppAlphaSyst(N1S_aa_rap3p5_2014[5],N1S_aa_rap3p5s_2p4,N1B_aa_rap3p5s_2p4,N1S_pp_rap3p5_2014[5],N1S_pp_rap3p5s_2p4[1]);
 
   syst2S_pp_rapLarge[0]=ppAlphaSyst(N2S_pp_rap4_2014Large[0],N2S_pp_rap4Larges_1p2,N2B_pp_rap4Larges_1p2,N2S_pp_rap4_2014Large[0],N2S_pp_rap4Larges_1p2[1]);
   syst2S_pp_rapLarge[1]=ppAlphaSyst(N2S_pp_rap4_2014Large[1],N2S_pp_rap4Larges_2p4,N2B_pp_rap4Larges_2p4,N2S_pp_rap4_2014Large[1],N2S_pp_rap4Larges_2p4[1]);

   syst2S_aa_rap[0]=ppAlphaSyst(N2S_aa_rap4_2014Large[0],N2S_aa_rap4Larges_1p2,N2B_aa_rap4Larges_1p2,N2S_pp_rap4_2014Large[0],N2S_pp_rap4Larges_1p2[1]);
   syst2S_aa_rap[1]=ppAlphaSyst(N2S_aa_rap4_2014Large[1],N2S_aa_rap4Larges_2p4,N2B_aa_rap4Larges_2p4,N2S_pp_rap4_2014Large[1],N2S_pp_rap4Larges_2p4[1]);

 
 
  for(int i = 0 ; i<nRapBins_2014 ; i++)
    {
      stat1S_aa_rap[i]=N1S_aa_rap3p5_2014e[i]/N1S_aa_rap3p5_2014[i];
      syst1S_aatnp_rap[i]=Aet_1S_pyquen_rap2014_fulls[i]/Aet_1S_pyquen_rap2014_STA[i]; //fulls is the full tnp syst (muidtrg+sta added in quadrature)
      syst1S_aags_rap[i]=Aet_1S_pyquen_rap2014_STAe[i]/Aet_1S_pyquen_rap2014_STA[i]; // doesnt matter if we use STA or MuID
      syst1S_aasta_rap[i]=Aet_1S_pyquen_rap2014_STAs[i]/Aet_1S_pyquen_rap2014_STA[i];
      syst1S_aamuid_rap[i]=Aet_1S_pyquen_rap2014_muIDTrigs[i]/Aet_1S_pyquen_rap2014_muIDTrig[i];
      syst1S_csaa_rap[i]=sqrt(syst1S_aatnp_rap[i]*syst1S_aatnp_rap[i]+syst1S_aa_rap[i]*syst1S_aa_rap[i]+pow(syst1S_aags_rap[i],2));
    }
  // large rap bins for Y(2S), pbpb and pp, and 1S large pp, large pbpb bins (for DR)
  for(int i = 0 ; i<nRapBins_2010 ; i++)
    {
      stat2S_aa_rap[i]= N2S_aa_rap4_2014Largee[i]/ N2S_aa_rap4_2014Large[i];
      syst2S_aatnp_rap[i]=Aet_2S_pyquen_rap2014Larges[i]/Aet_2S_pyquen_rap2014Large[i]; //fulls is the full tnp syst (muidtrg+sta added in quadrature)
      syst2S_aags_rap[i]=Aet_2S_pyquen_rap2014Largee[i]/Aet_2S_pyquen_rap2014Large[i];
      syst2S_aasta_rap[i]=Aet_2S_pyquen_rap2014Large_STAe[i]/Aet_2S_pyquen_rap2014Large[i];
      syst2S_aamuid_rap[i]=Aet_2S_pyquen_rap2014Large_muIDTrige[i]/Aet_2S_pyquen_rap2014Large[i];
      syst2S_csaa_rap[i]=sqrt(syst2S_aatnp_rap[i]*syst2S_aatnp_rap[i]+syst2S_aa_rap[i]*syst2S_aa_rap[i]+pow(syst2S_aags_rap[i],2));
      
      stat2S_ppL_rap[i]= N2S_pp_rap4_2014Largee[i]/ N2S_pp_rap4_2014Large[i];
      syst2S_ppLtnp_rap[i]=Aet_2S_pythia_rap2014Larges[i]/Aet_2S_pythia_rap2014Large[i]; //fulls is the full tnp syst (muidtrg+sta added in quadrature)
      syst2S_ppLgs_rap[i]=Aet_2S_pythia_rap2014Largee[i]/Aet_2S_pythia_rap2014Large[i];
      syst2S_ppLsta_rap[i]=Aet_2S_pythia_rap2014Large_STAe[i]/Aet_2S_pythia_rap2014Large[i];
      syst2S_ppLmuid_rap[i]=Aet_2S_pythia_rap2014Large_muIDTrige[i]/Aet_2S_pythia_rap2014Large[i];
      syst2S_csppL_rap[i]=sqrt(syst2S_ppLtnp_rap[i]*syst2S_ppLtnp_rap[i]+syst2S_pp_rapLarge[i]*syst2S_pp_rapLarge[i]+pow(syst2S_ppLgs_rap[i],2));
    }
  /// 4.a Y(1S)
  for(int i = 0 ; i<nRapBins_2014 ; i++)
    {
      CS1S_aa_tnp_rap[i]= computeRatio( N1S_aa_rap3p5_2014[i] , Aet_1S_pyquen_rap2014_STA[i] )/(N_MB_corr * T_AA_b*deltaRapEven[i]);
      CS1S_aa_tnp_rape[i] = computeRatioError( N1S_aa_rap3p5_2014[i] , Aet_1S_pyquen_rap2014_STA[i], N1S_aa_rap3p5_2014e[i] ,0)/(N_MB_corr * T_AA_b*deltaRapEven[i]);
      CS1S_aa_tnp_raps[i] = CS1S_aa_tnp_rap[i]*syst1S_csaa_rap[i];
    }
  /// 4.b,c,d,e Y(2S) pbpb, 2S pp, 1S pp, 1S aa
  for(int i = 0 ; i<nRapBins_2010 ; i++)
    {
      CS2S_aa_tnp_rap[i]= computeRatio(N2S_aa_rap4_2014Large[i] , Aet_2S_pyquen_rap2014Large[i] )/(N_MB_corr * T_AA_b*deltaRap2010[i]);
      CS2S_aa_tnp_rape[i] = computeRatioError(N2S_aa_rap4_2014Large[i] , Aet_2S_pyquen_rap2014Large[i], N2S_aa_rap4_2014Largee[i] ,0)/(N_MB_corr * T_AA_b*deltaRap2010[i]);
      CS2S_aa_tnp_raps[i] = CS2S_aa_tnp_rap[i]*syst2S_csaa_rap[i];
      //4.c 2S pp Large, computed with:
      //N2S rap4 in large bins,
      //Aet 2S in large bins (also rap4)
      //systematics in large bins with up to date TNP.
      CS2S_ppL_tnp_rap[i]= computeRatio(N2S_pp_rap4_2014Large[i] , Aet_2S_pythia_rap2014Large[i] )/(L_pp_invNb*deltaRap2010[i]);
      CS2S_ppL_tnp_rape[i] = computeRatioError(N2S_pp_rap4_2014Large[i] , Aet_2S_pythia_rap2014Large[i], N2S_pp_rap4_2014Largee[i] ,0)/(L_pp_invNb*deltaRap2010[i]);
      CS2S_ppL_tnp_raps[i] = CS2S_ppL_tnp_rap[i]*syst2S_csppL_rap[i];
      
    }
  ///5.a. Y(1S)
  ofSyst <<"1S PbPb Rap Bins | stat err. | syst err. = +/- syst.fit +/- syst.gs +/- syst.muid +/- syst.sta +/- syst.taa +/- syst.trk"<<endl;
   for(int j =0 ; j<nRapBins_2014 ; j++)
   {
     ofSyst <<  (binsRap[j]).c_str() << " & " << setprecision(3) << 
       stat1S_aa_rap[j] << " & " <<
       syst1S_csaa_rap[j] << " & " <<
       syst1S_aa_rap[j] << " & " <<
       syst1S_aags_rap[j] << " & " <<
       syst1S_aamuid_rap[j] << " & " <<
       syst1S_aasta_rap[j] << " & " <<
       syst_taa << " & " <<
       tracking_aa <<" \\\\ " << endl;
   }
   ofRes<<"1S PbPb Rap Bins | Cross section +/- stat err. +/- syst err. +/- global unc. "<<endl;
   for(int j =0 ; j<nRapBins_2014 ; j++)
   {
     ofRes << (binsRap[j]).c_str() << " & " << setprecision(3) << 
       CS1S_aa_tnp_rap[j] << " \\pm "<<
       CS1S_aa_tnp_rape[j]<<" \\pm "<<
       CS1S_aa_tnp_raps[j]<<" \\pm  "<<
       CS1S_aa_tnp_rap[j]*systXS_aa_glob<< "  \\\\"
	  << endl;
   }
   
   ///5.b. Y(2S)
   ofSyst <<"2S PbPb Rap Bins | stat err. | syst err. = +/- syst.fit +/- syst.gs +/- syst.muid +/- syst.sta +/- syst.taa +/- syst.trk"<<endl;
   for(int j =0 ; j<nRapBins_2010 ; j++)
     {
     ofSyst <<  (binsRap2010[j]).c_str() << " & " << setprecision(3) << 
       stat2S_aa_rap[j] << " & " <<
       syst2S_csaa_rap[j] << " & " <<
       syst2S_aa_rap[j] << " & " <<
       syst2S_aags_rap[j] << " & " <<
       syst2S_aamuid_rap[j] << " & " <<
       syst2S_aasta_rap[j] << " & " <<
       syst_taa << " & " <<
       tracking_aa <<" \\\\ " << endl;
   }

   ofRes<<"2S PbPb Rap Bins | Cross section +/- stat err. +/- syst err. +/- global unc. "<<endl;
   for(int j =0 ; j<nRapBins_2010 ; j++)
     {
     ofRes << (binsRap2010[j]).c_str() << " & " << setprecision(3) << 
       CS2S_aa_tnp_rap[j] << " \\pm "<<
       CS2S_aa_tnp_rape[j]<<" \\pm "<<
       CS2S_aa_tnp_raps[j]<<" \\pm "<<
       CS2S_aa_tnp_rap[j]*systXS_aa_glob << " \\\\"
	  << endl;
   }
   
   ///5.c. Y(2S) pp Large
  ofSyst <<"2S pp large Rap Bins | stat err. | syst err. = +/- syst.fit +/- syst.gs +/- syst.muid +/- syst.sta +/- syst.lumi +/- syst.trk"<<endl;
   for(int j =0 ; j<nRapBins_2010 ; j++)
   {
     ofSyst <<  (binsRap2010[j]).c_str() << " & " << setprecision(3) << 
       stat2S_ppL_rap[j] << " & " <<
       syst2S_csppL_rap[j] << " & " <<
       syst2S_pp_rapLarge[j] << " & " <<
       syst2S_ppLgs_rap[j] << " & " <<
       syst2S_ppLmuid_rap[j] << " & " <<
       syst2S_ppLsta_rap[j] << " & " <<
       syst_lumi << " & " <<
       tracking_pp <<" \\\\ " << endl;
   }
   ofRes<<"2S pp Rap Large Bins | Cross section +/- stat err. +/- syst err. +/- global unc. "<<endl;
   for(int j =0 ; j<nRapBins_2010 ; j++)
   {
     ofRes << (binsRap2010[j]).c_str() << " & " << setprecision(3) << 
       CS2S_ppL_tnp_rap[j] << " \\pm "<<
       CS2S_ppL_tnp_rape[j]<<" \\pm "<<
       CS2S_ppL_tnp_raps[j]<<" \\pm "<<
       CS2S_ppL_tnp_rap[j]*systXS_pp_glob << "  \\\\"
	  << endl;
   }

   /// 6.a plot AA cross section
   TCanvas *crapaa = new TCanvas("crapaa","crapaa"); 
   crapaa->SetLogy();
   crapaa->cd();
   TF1 *f4Rapaa = new TF1("f4Rapaa","10",0,2.4);
   f4Rapaa->SetLineWidth(0);
   f4Rapaa->GetXaxis()->SetTitle("|y|");
   f4Rapaa->GetYaxis()->SetTitle("#frac{1}{T_{AA}} #frac{dN}{dy}   (nb)");
   
   f4Rapaa->GetXaxis()->SetTitleSize(gTextSize+0.01);
   f4Rapaa->GetXaxis()->SetTitleOffset(f4Rapaa->GetXaxis()->GetTitleOffset()*1.1);
   f4Rapaa->GetYaxis()->SetTitleSize(gTextSize);
   f4Rapaa->GetYaxis()->SetLabelSize(0.9*f4Rapaa->GetYaxis()->GetLabelSize()); //  Y axis title is fat
   f4Rapaa->GetYaxis()->SetTitleOffset(1.55);
   f4Rapaa->GetYaxis()->SetRangeUser(0.01,1.6);
   //f4Rapaa->GetYaxis()->SetRangeUser(0.01,.09);
   f4Rapaa->GetXaxis()->CenterTitle(kTRUE);
   f4Rapaa->Draw();
   TGraphErrors *grap1TNPaa = new TGraphErrors(nRapBins_2014,rap2014,CS1S_aa_tnp_rap,0,CS1S_aa_tnp_rape);
   grap1TNPaa->SetMarkerColor(color1Saa);
   grap1TNPaa->SetMarkerStyle(symbol1S);
   grap1TNPaa->SetMarkerSize(markerSize);
   TGraphErrors *grap1circleaa = new TGraphErrors(nRapBins_2014,rap2014,CS1S_aa_tnp_rap,0,CS1S_aa_tnp_rape);
   grap1circleaa->SetMarkerStyle(symbol1Sc);
   grap1circleaa->SetMarkerSize(markerSize);
   grap1circleaa->SetLineColor(kBlack);
   grap1circleaa->SetLineWidth(2);
   TGraphErrors *gRap1aasyst = new TGraphErrors(nRapBins_2014,rap2014,CS1S_aa_tnp_rap,rap2014e,CS1S_aa_tnp_raps);
   gRap1aasyst->SetLineColor(color1Saa);
   gRap1aasyst->SetFillStyle(0);
   gRap1aasyst->SetLineWidth(2);
   gRap1aasyst->SetMarkerSize(0);
   gRap1aasyst->Draw("2");
   grap1TNPaa->Draw("pe");
   grap1circleaa->Draw("p");
   TGraphErrors *grap2TNPaa = new TGraphErrors(nRapBins_2010,rap2010,CS2S_aa_tnp_rap,0,CS2S_aa_tnp_rape);
   grap2TNPaa->SetMarkerColor(color2Saa);
   grap2TNPaa->SetMarkerStyle(symbol2S);
   grap2TNPaa->SetMarkerSize(markerSize);
   TGraphErrors *grap2circleaa = new TGraphErrors(nRapBins_2010,rap2010,CS2S_aa_tnp_rap,0,CS2S_aa_tnp_rape);
   grap2circleaa->SetMarkerStyle(symbol2Sc);
   grap2circleaa->SetMarkerSize(markerSize);
   grap2circleaa->SetLineColor(kBlack);
   grap2circleaa->SetLineWidth(2);
   TGraphErrors *gRap2aasyst = new TGraphErrors(nRapBins_2010,rap2010,CS2S_aa_tnp_rap,rap2010e,CS2S_aa_tnp_raps);
   gRap2aasyst->SetLineColor(color2Saa);
   gRap2aasyst->SetFillStyle(0);
   gRap2aasyst->SetLineWidth(2);
   gRap2aasyst->SetMarkerSize(0);
   gRap2aasyst->Draw("2");
   grap2TNPaa->Draw("pe");
   grap2circleaa->Draw("p");
   TLegend *legend_csaarap = new TLegend(0.24,0.4,0.49,0.59);
   legend_csaarap->SetTextSize(gTextSize);
   legend_csaarap->SetFillStyle(0);
   legend_csaarap->SetFillColor(0);
   legend_csaarap->SetBorderSize(0);
   legend_csaarap->SetTextFont(42);
   legend_csaarap->AddEntry(grap1TNPaa,"#varUpsilon(1S) ","p"); 
   legend_csaarap->AddEntry(grap2TNPaa,"#varUpsilon(2S) ","p");
   legend_csaarap->Draw();

   // |y| < 2.4
   TLatex latexrapaa;
   latexrapaa.SetTextSize(gTextSize);
   latexrapaa.SetTextFont(42);
   TLatex *latexraptxtaa = latexrapaa.DrawLatex(15.7,0.025,"|y| < 2.4");
   ///plotBox.
   CMS_lumi(crapaa,104,33);
   crapaa->Update();
   crapaa->RedrawAxis();
   crapaa->GetFrame()->Draw();
   crapaa->SaveAs(basedir2 + TString("/CS_aa_Rap.pdf"));
   crapaa->SaveAs(basedir2 + TString("/CS_aa_Rap.png"));
   crapaa->SaveAs(basedir1 + TString("/pdf/Xsection_aaNS_Rap.pdf"));
   crapaa->SaveAs(basedir1 + TString("/png/Xsection_aaNS_Rap.png"));

   if (plotLin)
     {
       crapaa->SetLogy(0);
       legend_csaarap->SetX1NDC(0.77); legend_csaarap->SetX2NDC(1.); legend_csaarap->SetY1NDC(0.40); legend_csaarap->SetY2NDC(0.61); legend_csaarap->Draw();
       crapaa->cd();
       gPad->Update();
       f4Rapaa->GetYaxis()->SetRangeUser(0.0,1.);
       f4Rapaa->GetYaxis()->SetTitleOffset(1.8);
       f4Rapaa->GetYaxis()->SetTitleSize(gTextSize);
       latexraptxtaa->SetY(0.085);
       latexraptxtaa->Draw();
       gPad->Update();
       gPad->RedrawAxis();
       gPad->GetFrame()->Draw();
       crapaa->SaveAs(basedir2 + TString("/CSNS_aaRap_lin.pdf"));
       crapaa->SaveAs(basedir2 + TString("/CSNS_aaRap_lin.png"));
       crapaa->SaveAs(basedir1 + TString("/pdf/Xsection_aaNS_Rap_lin.pdf"));
       crapaa->SaveAs(basedir1 + TString("/png/Xsection_aaNS_Rap_lin.png"));
     }

   crapaa->Close();

   ///===============================
   /// RAA vs Rap
   ///===============================
   /// 1. Define variables
   /// 2. Define syst variables
   /// 3. Compute the syst
   /// 4. Compute the CS.
   /// 5. Print the outputs
   /// 6. Draw and save
   ///-------------------------------
   /// 1.a. Y(1S)
   float RAA_1S_tnp_rap[nRapBins_2014] = {};
   float RAA_1S_tnp_rape[nRapBins_2014] = {};
   float RAA_1S_tnp_raps[nRapBins_2014] = {};
   float RAA_1S_tnp_rapsT[nRapBins_2014] = {}; //total!
   /// 1.b. Y(2S)
   float RAA_2S_tnp_rap[nRapBins_2010] = {};
   float RAA_2S_tnp_rape[nRapBins_2010] = {};
   float RAA_2S_tnp_raps[nRapBins_2010] = {};
   float RAA_2S_tnp_rapsT[nRapBins_2010] = {}; //total!
   /// 2.a Y(1S)
   float syst1S_raa_rap[nRapBins_2014]={}; /// quadratic sum
   /// 2.b Y(2S)
   float syst2S_raa_rap[nRapBins_2010]={}; /// quadratic sum
   //3.a Y(1S)
   for(int i =0 ; i<nRapBins_2014 ; i++)
     {
       syst1S_raa_rap[i]=sqrt(pow(stat1S_pp_rap[i],2)+syst1S_pptnp_rap[i]*syst1S_pptnp_rap[i]+syst1S_pp_rap[i]*syst1S_pp_rap[i]+pow(syst1S_ppgs_rap[i],2)+syst1S_aatnp_rap[i]*syst1S_aatnp_rap[i]+syst1S_aa_rap[i]*syst1S_aa_rap[i]+pow(syst1S_aags_rap[i],2)); /// all the ones varying point-to-point
     }
   //3.b Y(2S)
   for(int i =0 ; i<nRapBins_2010 ; i++)
     {
       syst2S_raa_rap[i]=sqrt(pow(stat2S_ppL_rap[i],2)+syst2S_ppLtnp_rap[i]*syst2S_ppLtnp_rap[i]+syst2S_pp_rapLarge[i]*syst2S_pp_rapLarge[i]+pow(syst2S_ppLgs_rap[i],2)+syst2S_aatnp_rap[i]*syst2S_aatnp_rap[i]+syst2S_aa_rap[i]*syst2S_aa_rap[i]+pow(syst2S_aags_rap[i],2)); /// all the ones varying point-to-point
     }
   /// 4.a Y(1S)
   for(int i = 0 ; i<nRapBins_2014 ; i++)
     {
       RAA_1S_tnp_rap[i]=CS1S_aa_tnp_rap[i]/CS1S_pp_tnp_rap[i];
       RAA_1S_tnp_rape[i]=computeRatioError( CS1S_aa_tnp_rap[i] , CS1S_pp_tnp_rap[i], CS1S_aa_tnp_rape[i] , 0);
       RAA_1S_tnp_raps[i]=RAA_1S_tnp_rap[i]*syst1S_raa_rap[i];
     }
   /// 4.b Y(2S)
   for(int i = 0 ; i<nRapBins_2010 ; i++)
     {
       RAA_2S_tnp_rap[i]=CS2S_aa_tnp_rap[i]/CS2S_ppL_tnp_rap[i];
       RAA_2S_tnp_rape[i]=computeRatioError( CS2S_aa_tnp_rap[i] , CS2S_ppL_tnp_rap[i], CS2S_aa_tnp_rape[i] , 0);
       RAA_2S_tnp_raps[i]=RAA_2S_tnp_rap[i]*syst2S_raa_rap[i];
     }

   /// 5.a Y(1S)
   /// the detail of all systematics may be a bit too exhaustive, but it's good to have evverything on the same line.
   ofSyst <<"1S RAA Rap Bins | stat err. | syst err. = +/- syst.fit +/- syst.gs +/- syst.muid +/- syst.sta +/- syst.taa +/- syst.trk"<<endl;
   for(int j =0 ; j<nRapBins_2014 ; j++)
     {
       ofSyst <<  (binsRap[j]).c_str() << " & " << setprecision(2) << 
	 stat1S_aa_rap[j]     << " & " <<
	 syst1S_raa_rap[j]    << " & " <<
	 syst1S_aa_rap[j]     << " & " <<
	 syst1S_aags_rap[j]   << " & " <<
	 syst1S_aamuid_rap[j] << " & " <<
	 syst1S_aasta_rap[j]  << " & " <<
	 stat1S_pp_rap[j]     << " & " <<
	 syst1S_pp_rap[j]     << " & " <<
	 syst1S_ppgs_rap[j]   << " & " <<
	 syst1S_ppmuid_rap[j] << " & " <<
	 syst1S_ppsta_rap[j]  << " & " <<
	 systXS_raa_glob     << " & " <<
	 syst_taa             << " & " <<
	 tracking_aa          << " & " <<
	 syst_nmb             << " & " << 
	 syst_lumi            << " & " <<
	 tracking_pp <<" \\\\ " << endl;
     }
   /// for tables
   ofRes<<"1S RAA Rap Bins | RAA +/- stat err. +/- syst err. +/- global unc. "<<endl;
   for(int j =0 ; j<nRapBins_2014 ; j++)
     {
       ofRes << (binsRap[j]).c_str() << " & " << setprecision(3) << 
	 RAA_1S_tnp_rap[j] << " \\pm "<<
	 RAA_1S_tnp_rape[j]<<" \\pm "<<
	 RAA_1S_tnp_raps[j]<<" \\pm "<<
	 RAA_1S_tnp_rap[j]*systXS_raa_glob << " \\\\"
	     << endl;
     }

   /// for plots, to share with your friends on facebook
   ofplot<<"float raa1Srap["<<nRapBins_2014<<"]={";
   for(int j =0 ; j<nRapBins_2014 ; j++)
     {
       ofplot <<RAA_1S_tnp_rap[j]; if (j==nRapBins_2014-1) ofplot<<"};"<<endl; else ofplot<<",";
     }
   ofplot<<"float raa1Srap_e["<<nRapBins_2014<<"]={";
   for(int j =0 ; j<nRapBins_2014 ; j++)
     {
       ofplot <<RAA_1S_tnp_rape[j]; if (j==nRapBins_2014-1) ofplot<<"};"<<endl; else ofplot<<",";
     }
   ofplot<<"float raa1Srap_s["<<nRapBins_2014<<"]={";
   for(int j =0 ; j<nRapBins_2014 ; j++)
     {
       ofplot <<RAA_1S_tnp_raps[j]; if (j==nRapBins_2014-1) ofplot<<"};"<<endl; else ofplot<<",";
     }   
   ofplot<<"float rapbin1["<<nRapBins_2014<<"]={";
   for(int j =0 ; j<nRapBins_2014 ; j++)
     {
       ofplot <<rap2014[j]; if (j==nRapBins_2014-1) ofplot<<"};"<<endl; else ofplot<<",";
     }
   ofplot<<"float rapbin1_e["<<nRapBins_2014<<"]={";
   for(int j =0 ; j<nRapBins_2014 ; j++)
     {
       ofplot <<rap2014e[j]; if (j==nRapBins_2014-1) ofplot<<"};"<<endl; else ofplot<<",";
     }


   /// 5.b Y(2S)
   ofSyst <<"2S RAA Rap Bins | stat err. | syst err. = +/- syst.fit +/- syst.gs +/- syst.muid +/- syst.sta +/- syst.taa +/- syst.trk"<<endl;
   for(int j =0 ; j<nRapBins_2010 ; j++)
     {
       ofSyst <<  (binsRap2010[j]).c_str() << " & " << setprecision(2) << 
	 stat2S_aa_rap[j]     << " & " <<
	 syst2S_raa_rap[j]   << " & " <<
	 syst2S_aa_rap[j]     << " & " <<
	 syst2S_aags_rap[j]   << " & " <<
	 syst2S_aamuid_rap[j] << " & " <<
	 syst2S_aasta_rap[j]  << " & " <<
	 stat2S_ppL_rap[j]     << " & " <<
	 syst2S_pp_rapLarge[j]     << " & " <<
	 syst2S_ppLgs_rap[j]   << " & " <<
	 syst2S_ppLmuid_rap[j] << " & " <<
	 syst2S_ppLsta_rap[j]  << " & " <<
	 systXS_raa_glob     << " & " <<
	 syst_taa            << " & " <<
	 tracking_aa << " & " <<
	 syst_nmb << " & " << 
	 syst_lumi           << " & " <<
	 tracking_pp <<" \\\\ " << endl;
     }
   ////for tables
   ofRes<<"2S RAA Rap Bins | RAA +/- stat err. +/- syst err. +/- global unc. "<<endl;
   for(int j =0 ; j<nRapBins_2010 ; j++)
     {
       ofRes << (binsRap2010[j]).c_str() << " & " << setprecision(3) << 
	 RAA_2S_tnp_rap[j] << " \\pm "<<
	 RAA_2S_tnp_rape[j]<<" \\pm "<<
	 RAA_2S_tnp_raps[j]<<" \\pm "<<
	 RAA_2S_tnp_rap[j]*systXS_raa_glob << " \\\\"
	     << endl;
     }

   /// for plots, to share with your friends on facebook
   ofplot<<"float raa2Srap["<<nRapBins_2010<<"]={";
   for(int j =0 ; j<nRapBins_2010 ; j++)
     {
       ofplot <<RAA_2S_tnp_rap[j]; if (j==nRapBins_2010-1) ofplot<<"};"<<endl; else ofplot<<",";
     }
   ofplot<<"float raa2Srap_e["<<nRapBins_2010<<"]={";
   for(int j =0 ; j<nRapBins_2010 ; j++)
     {
       ofplot <<RAA_2S_tnp_rape[j]; if (j==nRapBins_2010-1) ofplot<<"};"<<endl; else ofplot<<",";
     }
   ofplot<<"float raa2Srap_s["<<nRapBins_2010<<"]={";
   for(int j =0 ; j<nRapBins_2010 ; j++)
     {
       ofplot <<RAA_2S_tnp_raps[j]; if (j==nRapBins_2010-1) ofplot<<"};"<<endl; else ofplot<<",";
     }   
   ofplot<<"float rapbin2["<<nRapBins_2010<<"]={";
   for(int j =0 ; j<nRapBins_2010 ; j++)
     {
       ofplot <<rap2010[j]; if (j==nRapBins_2010-1) ofplot<<"};"<<endl; else ofplot<<",";
     }
   ofplot<<"float rapbin2_e["<<nRapBins_2010<<"]={";
   for(int j =0 ; j<nRapBins_2010 ; j++)
     {
       ofplot <<rap2010e[j]; if (j==nRapBins_2010-1) ofplot<<"};"<<endl; else ofplot<<",";
     }

   // 6. RAA rap plot
   TCanvas *cRaarap = new TCanvas("cRaarap","cRaarap"); 
   cRaarap->cd();
   TF1 *f4RaaRap = new TF1("f4RaaRap","1",0,2.4);
   f4RaaRap->SetLineWidth(1);
   f4RaaRap->SetLineColor(kBlack);
   f4RaaRap->GetXaxis()->SetTitle("|y|");
   f4RaaRap->GetYaxis()->SetTitle("R_{AA}");
   //   f4Rapaa->GetYaxis()->SetTitle("#frac{1}{T_{AA}} #frac{dN}{dy}   [nb]");
   f4RaaRap->GetXaxis()->SetTitleOffset(f4RaaRap->GetXaxis()->GetTitleOffset()*1.1);
   f4RaaRap->GetXaxis()->SetTitleSize(gTextSize+0.01);
   f4RaaRap->GetYaxis()->SetRangeUser(0.,1.2);
   f4RaaRap->GetXaxis()->CenterTitle(kTRUE);
   f4RaaRap->Draw();
   TGraphErrors *grap1TNPRAA = new TGraphErrors(nRapBins_2014,rap2014,RAA_1S_tnp_rap,0,RAA_1S_tnp_rape);
   grap1TNPRAA->SetMarkerColor(color1Sraa);
   grap1TNPRAA->SetMarkerStyle(symbol1S);
   grap1TNPRAA->SetMarkerSize(markerSize);
   TGraphErrors *grap1circleRAA = new TGraphErrors(nRapBins_2014,rap2014,RAA_1S_tnp_rap,0,RAA_1S_tnp_rape);
   grap1circleRAA->SetMarkerStyle(symbol1Sc);
   grap1circleRAA->SetMarkerSize(markerSize);
   grap1circleRAA->SetLineColor(kBlack);
   grap1circleRAA->SetLineWidth(2);
   TGraphErrors *gRap1RAAsyst = new TGraphErrors(nRapBins_2014,rap2014,RAA_1S_tnp_rap,rap2014e,RAA_1S_tnp_raps);
   gRap1RAAsyst->SetLineColor(color1Sraa);
   gRap1RAAsyst->SetFillStyle(0);
   gRap1RAAsyst->SetLineWidth(2);
   gRap1RAAsyst->SetMarkerSize(0);
   gRap1RAAsyst->Draw("2");
   grap1TNPRAA->Draw("pe");
   grap1circleRAA->Draw("p");
   TGraphErrors *grap2TNPRAA = new TGraphErrors(nRapBins_2010,rap2010,RAA_2S_tnp_rap,0,RAA_2S_tnp_rape);
   grap2TNPRAA->SetMarkerColor(color2Sraa);
   grap2TNPRAA->SetMarkerStyle(symbol2S);
   grap2TNPRAA->SetMarkerSize(markerSize);
   TGraphErrors *grap2circleRAA =new TGraphErrors(nRapBins_2010,rap2010,RAA_2S_tnp_rap,0,RAA_2S_tnp_rape);
   grap2circleRAA->SetMarkerStyle(symbol2Sc); 
   grap2circleRAA->SetMarkerSize(markerSize);
   grap2circleRAA->SetLineColor(kBlack);
   grap2circleRAA->SetLineWidth(2);
   TGraphErrors *gRap2RAAsyst = new TGraphErrors(nRapBins_2010,rap2010,RAA_2S_tnp_rap,rap2010e,RAA_2S_tnp_raps);
   gRap2RAAsyst->SetLineColor(color2Sraa);
   gRap2RAAsyst->SetFillStyle(0);
   gRap2RAAsyst->SetLineWidth(2);
   gRap2RAAsyst->SetMarkerSize(0);
   gRap2RAAsyst->Draw("2");
   grap2TNPRAA->Draw("pe");
   grap2circleRAA->Draw("p");

   TLegend *legend_RAArap = new TLegend(0.24,0.5,0.49,0.66);
   legend_RAArap->SetTextSize(gTextSize);
   legend_RAArap->SetFillStyle(0);
   legend_RAArap->SetFillColor(0);
   legend_RAArap->SetBorderSize(0);
   legend_RAArap->SetTextFont(42);
   legend_RAArap->AddEntry(grap1TNPRAA,"#varUpsilon(1S) ","p"); 
   legend_RAArap->AddEntry(grap2TNPRAA,"#varUpsilon(2S) ","p");
   legend_RAArap->Draw();
   
   // Cent. 0-100 %
   TLatex latexrapRaa;
   latexrapRaa.SetTextSize(gTextSize);
   latexrapRaa.SetTextFont(42);
   latexrapRaa.DrawLatex(0.2,.9,"Cent. 0-100%"); // y=1.2 in the previous version
   if (!plotBox) {
     latexrapRaa.DrawLatex(0.2,0.83,Form("Global uncertainty: %.1f",100*systXS_raa_glob));
     latexrapRaa.DrawLatex(1.27,0.83,"%"); /// y=1.1
   } else{
     //plotBox
     TBox *boxRap = new TBox(2.3,1-systXS_raa_glob,2.4,1+systXS_raa_glob); 
     boxRap->SetFillColor(kGray);
     boxRap->Draw();
   }   

   CMS_lumi(cRaarap,104,33);
   cRaarap->Update();
   cRaarap->RedrawAxis();
   cRaarap->GetFrame()->Draw();
   cRaarap->SaveAs(basedir2 + TString("/RAA_Rap.pdf"));
   cRaarap->SaveAs(basedir2 + TString("/RAA_Rap.png"));
   cRaarap->SaveAs(basedir1 + TString("/pdf/RAA_Rap.pdf"));
   cRaarap->SaveAs(basedir1 + TString("/png/RAA_Rap.png"));

   //// ALICE + Strickland + CMS
   // 6. RAA rap plot
   TCanvas *cRaarapAS = new TCanvas("cRaarapAS","cRaarapAS"); 
   cRaarapAS->cd();
   TF1 *f4RaaRapAS = new TF1("f4RaaRapAS","1",0,4);
   f4RaaRapAS->SetLineWidth(1);
   f4RaaRapAS->SetLineColor(kBlack);
   f4RaaRapAS->GetXaxis()->SetTitle("|y|");
   f4RaaRapAS->GetYaxis()->SetTitle("R_{AA}");
   //   f4Rapaa->GetYaxis()->SetTitle("#frac{1}{T_{AA}} #frac{dN}{dy}   [nb]");
   f4RaaRapAS->GetXaxis()->SetTitleOffset(f4RaaRapAS->GetXaxis()->GetTitleOffset()*1.1);
   f4RaaRapAS->GetXaxis()->SetTitleSize(gTextSize+0.01);
   f4RaaRapAS->GetYaxis()->SetRangeUser(0.,1.2);
   f4RaaRapAS->GetXaxis()->CenterTitle(kTRUE);
   f4RaaRapAS->Draw();
   TGraphErrors *grapAS1TNPRAA = new TGraphErrors(nRapBins_2014,rap2014,RAA_1S_tnp_rap,0,RAA_1S_tnp_rape);
   grapAS1TNPRAA->SetMarkerColor(color1Sraa);
   grapAS1TNPRAA->SetMarkerStyle(symbol1S);
   grapAS1TNPRAA->SetMarkerSize(markerSize);
   TGraphErrors *grapAS1circleRAA = new TGraphErrors(nRapBins_2014,rap2014,RAA_1S_tnp_rap,0,RAA_1S_tnp_rape);
   grapAS1circleRAA->SetMarkerStyle(symbol1Sc);
   grapAS1circleRAA->SetMarkerSize(markerSize);
   grapAS1circleRAA->SetLineColor(kBlack);
   grapAS1circleRAA->SetLineWidth(2);
   TGraphErrors *gRapAS1RAAsyst = new TGraphErrors(nRapBins_2014,rap2014,RAA_1S_tnp_rap,rap2014e,RAA_1S_tnp_raps);
   gRapAS1RAAsyst->SetLineColor(color1Sraa);
   gRapAS1RAAsyst->SetFillStyle(0);
   gRapAS1RAAsyst->SetLineWidth(2);
   gRapAS1RAAsyst->SetMarkerSize(0);
   gRapAS1RAAsyst->Draw("2");
   grapAS1TNPRAA->Draw("pe");
   grapAS1circleRAA->Draw("p");
   TGraphErrors *grapAS2TNPRAA = new TGraphErrors(nRapBins_2010,rap2010,RAA_2S_tnp_rap,0,RAA_2S_tnp_rape);
   grapAS2TNPRAA->SetMarkerColor(color2Sraa);
   grapAS2TNPRAA->SetMarkerStyle(symbol2S);
   grapAS2TNPRAA->SetMarkerSize(markerSize);
   TGraphErrors *grapAS2circleRAA =new TGraphErrors(nRapBins_2010,rap2010,RAA_2S_tnp_rap,0,RAA_2S_tnp_rape);
   grapAS2circleRAA->SetMarkerStyle(symbol2Sc); 
   grapAS2circleRAA->SetMarkerSize(markerSize);
   grapAS2circleRAA->SetLineColor(kBlack);
   grapAS2circleRAA->SetLineWidth(2);
   TGraphErrors *gRapAS2RAAsyst = new TGraphErrors(nRapBins_2010,rap2010,RAA_2S_tnp_rap,rap2010e,RAA_2S_tnp_raps);
   gRapAS2RAAsyst->SetLineColor(color2Sraa);
   gRapAS2RAAsyst->SetFillStyle(0);
   gRapAS2RAAsyst->SetLineWidth(2);
   gRapAS2RAAsyst->SetMarkerSize(0);
   gRapAS2RAAsyst->Draw("2");
   grapAS2TNPRAA->Draw("pe");
   grapAS2circleRAA->Draw("p");

   //defining ALICE stuff in a larger scope...
///RAA Upsilon ALICE 
// http://arxiv.org/pdf/1405.4493v3.pdf
float ALICE_RAP[2]={2.85,3.6};
float ALICE_RAPe[2]={0.35,0.4};

float ALICE_PT[7]= {0.5,1.5,2.5,3.5,4.5,5.5,7};
float ALICE_PTe[7]={0.5,0.5,0.5,0.5,0.5,0.5,1};

float ALICE_RAA_1S_rap[2]={0.30,0.29};
float ALICE_RAA_1S_rape[2]={0.05,0.07};
float ALICE_RAA_1S_raps[2]={0.04,0.05};
float AliceBox=0.12;
float AliceBoxKin=0.08;
 
   TGraphErrors *ga1rps= new TGraphErrors(2,ALICE_RAP,ALICE_RAA_1S_rap,rapbin1_e,ALICE_RAA_1S_raps); 
  ga1rps->SetLineColor(ALICE);
  ga1rps->SetFillStyle(0);
  ga1rps->SetLineWidth(2);
  ga1rps->SetMarkerSize(0);
  TGraphErrors *ga1r = new TGraphErrors(2,ALICE_RAP,ALICE_RAA_1S_rap,rapbin1_e,ALICE_RAA_1S_rape); 
  ga1r->SetMarkerColor(ALICE);
  ga1r->SetMarkerStyle(filledCross);
  ga1r->SetMarkerSize(1.5*markerSize);
  TGraphErrors *ga1rc = new TGraphErrors(2,ALICE_RAP,ALICE_RAA_1S_rap,rapbin1_e,ALICE_RAA_1S_rape);
  ga1rc->SetMarkerStyle(filledCross);
  ga1rc->SetMarkerSize(1.5*markerSize);
  ga1rc->SetLineColor(ALICE);
  ga1rc->SetLineWidth(2);
  ga1rps->Draw("2");
      ga1r->Draw("pe");
      ga1rc->Draw("p");
   //M.Strickland data part
      ////Strickland comparisons are now based on his '5TeV predictions' paper, which has 2.76 as a reference. The advantage is basically more points on the prediction curve. Check out https://arxiv.org/src/1605.03561v1/anc
      float rap_th[36];
      float raa1Srap_the1x0[36], raa1Srap_the2x0[36], raa1Srap_the3x0[36];
      float raa2Srap_the1x0[36], raa2Srap_the2x0[36], raa2Srap_the3x0[36];
      ifstream irap1Sx0;
      ifstream irap2Sx0;
      // this is the input file for 1Srap and xi=0
      irap1Sx0.open("Strick_Rapidity_1S_xi0.tsv");
      irap2Sx0.open("Strick_Rapidity_2S_xi0.tsv");
      for (int i=0; i<36;i++){
	irap1Sx0>> rap_th[i]>> raa1Srap_the1x0[i]>> raa1Srap_the2x0[i]>> raa1Srap_the3x0[i];
	irap2Sx0>> rap_th[i]>> raa2Srap_the1x0[i]>> raa2Srap_the2x0[i]>> raa2Srap_the3x0[i];
      }
      TGraph *sups1Srap1x0 = new TGraph(35,rap_th,raa1Srap_the1x0);
      sups1Srap1x0->SetLineWidth(2);
      sups1Srap1x0->SetLineColor(color1Sraa);
      sups1Srap1x0->SetLineStyle(1);
      sups1Srap1x0->Draw("l same");
      TGraph *sups1Srap2x0 = new TGraph(35,rap_th,raa1Srap_the2x0);
      sups1Srap2x0->SetLineWidth(2);
      sups1Srap2x0->SetLineColor(color1Sraa);
      sups1Srap2x0->SetLineStyle(2);
      sups1Srap2x0->Draw("l same");
      TGraph *sups1Srap3x0 = new TGraph(35,rap_th,raa1Srap_the3x0);
      sups1Srap3x0->SetLineWidth(2);
      sups1Srap3x0->SetLineColor(color1Sraa);
      sups1Srap3x0->SetLineStyle(3);
      sups1Srap3x0->Draw("l same");
      TGraph *sups2Srap1x0 = new TGraph(35,rap_th,raa2Srap_the1x0);
      sups2Srap1x0->SetLineWidth(2);
      sups2Srap1x0->SetLineColor(color2Sraa);
      sups2Srap1x0->SetLineStyle(1);
      sups2Srap1x0->Draw("l same");
      TGraph *sups2Srap2x0 = new TGraph(35,rap_th,raa2Srap_the2x0);
      sups2Srap2x0->SetLineWidth(2);
      sups2Srap2x0->SetLineColor(color2Sraa);
      sups2Srap2x0->SetLineStyle(2);
      sups2Srap2x0->Draw("l same");
      TGraph *sups2Srap3x0 = new TGraph(35,rap_th,raa2Srap_the3x0);
      sups2Srap3x0->SetLineWidth(2);
      sups2Srap3x0->SetLineColor(color2Sraa);
      sups2Srap3x0->SetLineStyle(3);
      sups2Srap3x0->Draw("l same");
      TLegend *legR2AS= new TLegend(0.25,0.69,0.4,0.75);
      legR2AS->SetBorderSize(0);
      legR2AS->SetTextSize(gTextSize-0.01);
      legR2AS->SetTextFont(42);
      legR2AS->SetLineColor(0);
      legR2AS->SetLineStyle(1);
      legR2AS->SetLineWidth(2);
      legR2AS->SetFillColor(0);
      legR2AS->SetFillStyle(0);
      TLegend *legR3AS = new TLegend(0.25,0.55,0.4,0.7);
      legR3AS->SetBorderSize(0);
      legR3AS->SetTextSize(gTextSize-0.01);
      legR3AS->SetTextFont(42);
      legR3AS->SetLineColor(0);
      legR3AS->SetLineStyle(2);
      legR3AS->SetLineWidth(1);
      legR3AS->SetFillColor(0);
      legR3AS->SetFillStyle(0);
      legR3AS->SetHeader("Strickland et al., Universe 2016, 2(3), 16");

      legR2AS->SetHeader("ALICE "); // (PLB 738 (2014) 361)
      legR2AS->AddEntry(ga1rc,"#varUpsilon(1S) PLB 738(2014) 361","P");
      legR3AS->AddEntry(sups1Srap3x0," 4#pi#eta/s = 3","L");
      legR3AS->AddEntry(sups1Srap2x0," 4#pi#eta/s = 2","L");
      legR3AS->AddEntry(sups1Srap1x0," 4#pi#eta/s = 1","L");

      legR2AS->Draw();
      legR3AS->Draw();
   TLegend *legend_RAArapAS = new TLegend(0.24,0.5,0.49,0.66);
   legend_RAArapAS->SetTextSize(gTextSize);
   legend_RAArapAS->SetFillStyle(0);
   legend_RAArapAS->SetFillColor(0);
   legend_RAArapAS->SetBorderSize(0);
   legend_RAArapAS->SetTextFont(42);
   legend_RAArapAS->AddEntry(grapAS1TNPRAA,"#varUpsilon(1S) ","p"); 
   legend_RAArapAS->AddEntry(grapAS2TNPRAA,"#varUpsilon(2S) ","p");
   legend_RAArapAS->Draw();
   
   // Cent. 0-100 %
   TLatex latexrapASRaa;
   latexrapASRaa.SetTextSize(gTextSize);
   latexrapASRaa.SetTextFont(42);
   latexrapASRaa.DrawLatex(0.2,.9,"Cent. 0-100%"); // y=1.2 in the previous version
   if (!plotBox) {
     latexrapASRaa.DrawLatex(0.2,0.83,Form("Global uncertainty: %.1f",100*systXS_raa_glob));
     latexrapASRaa.DrawLatex(1.27,0.83,"%"); /// y=1.1
   } else{
     //plotBox
     TBox *boxRapAS = new TBox(3.8,1-systXS_raa_glob,4,1+systXS_raa_glob); 
     boxRapAS->SetFillColor(kGray);
     boxRapAS->Draw();
   }   

   CMS_lumi(cRaarapAS,104,33);
   cRaarapAS->Update();
   cRaarapAS->RedrawAxis();
   cRaarapAS->GetFrame()->Draw();
   cRaarapAS->SaveAs(basedir2 + TString("/RAA_RapAliceStrickland.pdf"));
   cRaarapAS->SaveAs(basedir2 + TString("/RAA_RapAliceStrickland.png"));
   cRaarapAS->SaveAs(basedir1 + TString("/pdf/RAA_RapAliceStrickland.pdf"));
   cRaarapAS->SaveAs(basedir1 + TString("/png/RAA_RapAliceStrickland.png"));

   ///===============================
   /// Integrated cross sections (pt<40 actually)
   ///===============================
   /// 1. Define variables
   /// 2. Define syst variables
   /// 3. Compute the syst
   /// 4. Compute the CS.
   /// 5. Print the outputs
   ///-------------------------------
   /// 1.a.pp
   float CS1S_pp_tot;
   float CS1S_pp_tote;
   float CS1S_pp_tots;
  
   float CS2S_pp_tot;
   float CS2S_pp_tote;
   float CS2S_pp_tots;
  
   float CS3S_pp_tot;
   float CS3S_pp_tote;
   float CS3S_pp_tots;
   /// 1.b.aa
   float CS1S_aa_tot;
   float CS1S_aa_tote;
   float CS1S_aa_tots;

   float CS2S_aa_tot;
   float CS2S_aa_tote;
   float CS2S_aa_tots;

   float CS3S_aa_tot;
   float CS3S_aa_tote;
   float CS3S_aa_tots;
   /// 2.a.pp
   float stat1S_pp_tot;    //fit syst. uncertainty.
   float syst1S_pptnp_tot; // tnp uncertainty
   float syst1S_pp_tot;    //fit syst. uncertainty.
   float syst1S_ppgs_tot;  //gen shape
   float syst1S_ppsta_tot; ///sta uncertainty
   float syst1S_ppmuid_tot;/// muid uncertainty
   float syst1S_cspp_tot;  /// quadratic sum.

   float stat2S_pp_tot;    //fit syst. uncertainty.
   float syst2S_pptnp_tot;// tnp uncertainty
   float syst2S_pp_tot;   //fit syst. uncertainty.
   float syst2S_ppgs_tot;   //gen shape
   float syst2S_ppsta_tot; ///sta uncertainty
   float syst2S_ppmuid_tot;/// muid uncertainty
   float syst2S_cspp_tot; /// quadratic sum.

   float stat3S_pp_tot;    //fit syst. uncertainty.
   float syst3S_pptnp_tot;// tnp uncertainty
   float syst3S_pp_tot;   //fit syst. uncertainty.
   float syst3S_ppgs_tot;   //gen shape
   float syst3S_ppsta_tot; ///sta uncertainty
   float syst3S_ppmuid_tot;/// muid uncertainty
   float syst3S_cspp_tot; /// quadratic sum.
   /// 2.b.aa
   float stat1S_aa_tot;    //fit syst. uncertainty.
   float syst1S_aatnp_tot;// tnp uncertainty
   float syst1S_aa_tot;   //fit syst. uncertainty.
   float syst1S_aags_tot;   //gen shape
   float syst1S_aasta_tot; ///sta uncertainty
   float syst1S_aamuid_tot;/// muid uncertainty
   float syst1S_csaa_tot; /// quadratic sum.

   float stat2S_aa_tot;    //fit syst. uncertainty.
   float syst2S_aatnp_tot;// tnp uncertainty
   float syst2S_aa_tot;   //fit syst. uncertainty.
   float syst2S_aags_tot;   //gen shape
   float syst2S_aasta_tot; ///sta uncertainty
   float syst2S_aamuid_tot;/// muid uncertainty
   float syst2S_csaa_tot; /// quadratic sum.
   // rest not used!
   float stat3S_aa_tot;    //fit syst. uncertainty.
   float syst3S_aatnp_tot;// tnp uncertainty
   float syst3S_aa_tot;   //fit syst. uncertainty.
   float syst3S_aags_tot;   //gen shape
   float syst3S_aasta_tot; ///sta uncertainty
   float syst3S_aamuid_tot;/// muid uncertainty
   float syst3S_csaa_tot; /// quadratic sum.
   // 3.a pp syst computation
   stat1S_pp_tot=N1S_pp_tot3p5e/N1S_pp_tot3p5;
   syst1S_pp_tot=N1S_pp_tot3p5s; //fitting
   syst1S_pptnp_tot=Aet_1S_pythia_tots/Aet_1S_pythia_tot; // is the full tnp syst (muidtrg+sta added in quadrature)
   syst1S_ppgs_tot=Aet_1S_pythia_totgse/Aet_1S_pythia_tot; // gs only (very small)
   syst1S_ppsta_tot=t_1S_pythia_tot3p5_STAe/t_1S_pythia_tot3p5;
   syst1S_ppmuid_tot=t_1S_pythia_tot3p5e/t_1S_pythia_tot3p5;
   syst1S_cspp_tot=sqrt(syst1S_pptnp_tot*syst1S_pptnp_tot+syst1S_pp_tot*syst1S_pp_tot+pow(syst1S_ppgs_tot,2));

   stat2S_pp_tot=N2S_pp_tot4e/N2S_pp_tot4;
   syst2S_pp_tot=N2S_pp_tot4s; //fitting
   syst2S_pptnp_tot=Aet_2S_pythia_tots/Aet_2S_pythia_tot; // is the full tnp syst (muidtrg+sta added in quadrature)
   syst2S_ppgs_tot=Aet_2S_pythia_totgse/Aet_2S_pythia_tot; // gs only (very small)
   syst2S_ppsta_tot=Aet_2S_pythia_tot_STAe/Aet_2S_pythia_tot;
   syst2S_ppmuid_tot=Aet_2S_pythia_tot_muIDe/Aet_2S_pythia_tot;
   syst2S_cspp_tot=sqrt(syst2S_pptnp_tot*syst2S_pptnp_tot+syst2S_pp_tot*syst2S_pp_tot+pow(syst2S_ppgs_tot,2));

   stat3S_pp_tot=N3S_pp_tot4e/N3S_pp_tot4;
   syst3S_pp_tot=N3S_pp_tot4s; //fitting
   syst3S_pptnp_tot=Aet_3S_pythia_tote/Aet_3S_pythia_tot; //fulls is the full tnp syst (muidtrg+sta added in quadrature)
   syst3S_ppgs_tot=Aet_3S_pythia_totgse/Aet_3S_pythia_tot; // gs only (very small)
   syst3S_ppsta_tot=Aet_3S_pythia_tot_STAe/Aet_3S_pythia_tot;
   syst3S_ppmuid_tot=Aet_3S_pythia_tot_muIDe/Aet_3S_pythia_tot;
   syst3S_cspp_tot=sqrt(syst3S_pptnp_tot*syst3S_pptnp_tot+syst3S_pp_tot*syst3S_pp_tot+pow(syst_lumi,2)+pow(tracking_pp,2)+pow(syst3S_ppgs_tot,2));

   // 3.b. PbPb syst
   stat1S_aa_tot=N1S_aa_tot3p5e/N1S_aa_tot3p5;
   syst1S_aa_tot=N1S_aa_tot3p5s; //fitting
   syst1S_aatnp_tot=t_1S_pyquen_tot3p5e/t_1S_pyquen_tot3p5; //fulle is the full tnp syst (muidtrg+sta added in quadrature)
   syst1S_aags_tot=Aet_1S_pyquen_totgse/Aet_1S_pyquen_tot; // gs only (very small)
   syst1S_aasta_tot=Aet_1S_pyquen_tot3p5_STAe/Aet_1S_pyquen_tot;
   syst1S_aamuid_tot=Aet_1S_pyquen_tot3p5_muIDe/Aet_1S_pyquen_tot;
   syst1S_csaa_tot=sqrt(syst1S_aatnp_tot*syst1S_aatnp_tot+syst1S_aa_tot*syst1S_aa_tot+pow(syst1S_aags_tot,2));

   stat2S_aa_tot=N2S_aa_tot4e/N2S_aa_tot4;
   syst2S_aa_tot=N2S_aa_tot4s; //fitting
   syst2S_aatnp_tot=Aet_2S_pyquen_tots/Aet_2S_pyquen_tot; //fulle is the full tnp syst (muidtrg+sta added in quadrature)
   syst2S_aags_tot=Aet_2S_pyquen_totgse/Aet_2S_pyquen_tot; // gs only (very small)
   syst2S_aasta_tot=Aet_2S_pyquen_tot_STAe/Aet_2S_pyquen_tot;
   syst2S_aamuid_tot=Aet_2S_pyquen_tot_muIDe/Aet_2S_pyquen_tot;
   syst2S_csaa_tot=sqrt(syst2S_aatnp_tot*syst2S_aatnp_tot+syst2S_aa_tot*syst2S_aa_tot+pow(syst2S_aags_tot,2));
   // 4.a compute pp cross section
   CS1S_pp_tot= computeRatio(N1S_pp_tot3p5,Aet_1S_pythia_tot)/(L_pp_invNb*RapBinWidth);
   CS1S_pp_tote= computeRatioError(N1S_pp_tot3p5,Aet_1S_pythia_tot,N1S_pp_tot3p5e,0)/(L_pp_invNb*RapBinWidth);
   CS1S_pp_tots= CS1S_pp_tot*syst1S_cspp_tot;
   CS2S_pp_tot= computeRatio(N2S_pp_tot4,Aet_2S_pythia_tot)/(L_pp_invNb*RapBinWidth);
   CS2S_pp_tote= computeRatioError(N2S_pp_tot4,Aet_2S_pythia_tot,N2S_pp_tot4e,0)/(L_pp_invNb*RapBinWidth);
   CS2S_pp_tots= CS2S_pp_tot*syst2S_cspp_tot;
   CS3S_pp_tot= computeRatio(N3S_pp_tot4,Aet_3S_pythia_tot)/(L_pp_invNb*RapBinWidth);
   CS3S_pp_tote= computeRatioError(N3S_pp_tot4,Aet_3S_pythia_tot,N3S_pp_tot4e,0)/(L_pp_invNb*RapBinWidth);
   CS3S_pp_tots= CS3S_pp_tot*syst3S_cspp_tot;
   // 4.b compute PbPb cross section
   CS1S_aa_tot= computeRatio(N1S_aa_tot3p5,Aet_1S_pyquen_tot)/(N_MB_corr*T_AA_b*RapBinWidth);
   CS1S_aa_tote= computeRatioError(N1S_aa_tot3p5,Aet_1S_pyquen_tot,N1S_aa_tot3p5e,0)/(N_MB_corr*T_AA_b*RapBinWidth);
   CS1S_aa_tots= CS1S_aa_tot*syst1S_csaa_tot;
   CS2S_aa_tot= computeRatio(N2S_aa_tot4,Aet_2S_pyquen_tot)/(N_MB_corr*T_AA_b*RapBinWidth);
   CS2S_aa_tote= computeRatioError(N2S_aa_tot4,Aet_2S_pyquen_tot,N2S_aa_tot4e,0)/(N_MB_corr*T_AA_b*RapBinWidth);
   CS2S_aa_tots= CS2S_aa_tot*syst2S_csaa_tot;
   /// 5.a pp
   ofSyst <<"1S pp integrated | stat err. | syst err. = +/- syst.fit +/- syst.gs +/- syst.muid +/- syst.sta +/- syst.lumi +/- syst.trk"<<endl;
   ofSyst <<  "0-inf" << " & " << setprecision(2) << 
     stat1S_pp_tot      << " & " <<
     syst1S_cspp_tot      << " & " <<
     syst1S_pp_tot      << " & " <<
     syst1S_ppgs_tot    << " & " <<
     syst1S_ppmuid_tot  << " & " <<
     syst1S_ppsta_tot   << " & " <<
     syst_lumi           << " & " <<
     tracking_pp <<" \\\\ " << endl;

   ofRes<<"1S integrated Cross section | CS +/- stat err. +/- syst err. +/- global unc. "<<endl;
   
   ofRes << "0-inf" << " & " << setprecision(3) << 
     CS1S_pp_tot << " \\pm "<<
     CS1S_pp_tote <<" \\pm "<<
     CS1S_pp_tots <<" \\pm "<<
     CS1S_pp_tot*systXS_pp_glob << " \\\\"
	 << endl;

    ofSyst <<"2S pp integrated | stat err. | syst err. = +/- syst.fit +/- syst.gs +/- syst.muid +/- syst.sta +/- syst.lumi +/- syst.trk"<<endl;
   ofSyst <<  "0-inf" << " & " << setprecision(2) << 
     stat2S_pp_tot      << " & " <<
     syst2S_cspp_tot      << " & " <<
     syst2S_pp_tot      << " & " <<
     syst2S_ppgs_tot    << " & " <<
     syst2S_ppmuid_tot  << " & " <<
     syst2S_ppsta_tot   << " & " <<
     syst_lumi           << " & " <<
     tracking_pp <<" \\\\ " << endl;

   ofRes<<"2S integrated Cross section | CS +/- stat err. +/- syst err. +/- global unc. "<<endl;
   
   ofRes << "0-inf" << " & " << setprecision(3) << 
     CS2S_pp_tot << " \\pm "<<
     CS2S_pp_tote <<" \\pm "<<
     CS2S_pp_tots <<" \\pm "<<
     CS2S_pp_tot*systXS_pp_glob << " \\\\"
	 << endl;

    ofSyst <<"3S pp integrated | stat err. | syst err. = +/- syst.fit +/- syst.gs +/- syst.muid +/- syst.sta +/- syst.lumi +/- syst.trk"<<endl;
   ofSyst <<  "0-inf" << " & " << setprecision(2) << 
     stat3S_pp_tot      << " & " <<
     syst3S_cspp_tot      << " & " <<
     syst3S_pp_tot      << " & " <<
     syst3S_ppgs_tot    << " & " <<
     syst3S_ppmuid_tot  << " & " <<
     syst3S_ppsta_tot   << " & " <<
     syst_lumi           << " & " <<
     tracking_pp <<" \\\\ " << endl;

   ofRes<<"3S integrated Cross section | CS +/- stat err. +/- syst err. +/- global unc. "<<endl;
   
   ofRes << "0-inf" << " & " << setprecision(3) << 
     CS3S_pp_tot << " \\pm "<<
     CS3S_pp_tote <<" \\pm "<<
     CS3S_pp_tots <<" \\pm "<<
     CS3S_pp_tot*systXS_pp_glob << " \\\\"
	 << endl;
     
    ofSyst <<"1S aa integrated | stat err. | syst err. = +/- syst.fit +/- syst.gs +/- syst.muid +/- syst.sta +/- syst.lumi +/- syst.trk"<<endl;
   ofSyst <<  "0-inf" << " & " << setprecision(2) << 
     stat1S_aa_tot      << " & " <<
     syst1S_csaa_tot      << " & " <<
     syst1S_aa_tot      << " & " <<
     syst1S_aags_tot    << " & " <<
     syst1S_aamuid_tot  << " & " <<
     syst1S_aasta_tot   << " & " <<
     syst_taa           << " & " <<
     tracking_aa <<" \\\\ " << endl;

   ofRes<<"1S integrated Cross section | CS +/- stat err. +/- syst err. +/- global unc. "<<endl;
   
   ofRes << "0-inf" << " & " << setprecision(3) << 
     CS1S_aa_tot << " \\pm "<<
     CS1S_aa_tote <<" \\pm "<<
     CS1S_aa_tots <<" \\pm "<<
     CS1S_aa_tot*systXS_aa_glob << " \\\\"
	 << endl;

    ofSyst <<"2S aa integrated | stat err. | syst err. = +/- syst.fit +/- syst.gs +/- syst.muid +/- syst.sta +/- syst.lumi +/- syst.trk"<<endl;
   ofSyst <<  "0-inf" << " & " << setprecision(2) << 
     stat2S_aa_tot      << " & " <<
     syst2S_csaa_tot      << " & " <<
     syst2S_aa_tot      << " & " <<
     syst2S_aags_tot    << " & " <<
     syst2S_aamuid_tot  << " & " <<
     syst2S_aasta_tot   << " & " <<
     syst_taa           << " & " <<
     tracking_aa <<" \\\\ " << endl;

   ofRes<<"2S integrated Cross section | CS +/- stat err. +/- syst err. +/- global unc. "<<endl;
   
   ofRes << "0-inf" << " & " << setprecision(3) << 
     CS2S_aa_tot << " \\pm "<<
     CS2S_aa_tote <<" \\pm "<<
     CS2S_aa_tots <<" \\pm "<<
     CS2S_aa_tot*systXS_aa_glob << " \\\\"
	 << endl;

   ///===============================
   /// RAA and PbPb yield vs cent
   ///===============================
   /// 1. Define variables
   /// 2. Define syst variables
   /// 3. Compute the syst
   /// 4. Compute the CS.
   /// 5. Print the outputs
   /// 6. Draw and save
   ///-------------------------------
   /// 1.
   float CS1S_aa_cent[nCentBins_2014] = {}; 
   float CS1S_aa_cente[nCentBins_2014] = {};
   float CS1S_aa_cents[nCentBins_2014] = {};
   float RAA_1S_cent[nCentBins_2014]={};
   float RAA_1S_cente[nCentBins_2014]={};
   float RAA_1S_cents[nCentBins_2014]={};
   float RAA_1S_centsT[nCentBins_2014]={};
   float CS2S_aa_cent[nCentBins2S] = {}; 
   float CS2S_aa_cente[nCentBins2S] = {};
   float CS2S_aa_cents[nCentBins2S] = {};
   float RAA_2S_cent[nCentBins2S]={};
   float RAA_2S_cente[nCentBins2S]={};
   float RAA_2S_cents[nCentBins2S]={};
   float RAA_2S_centsT[nCentBins2S]={};
   float RAA_1S_tot;
   float RAA_1S_tote;
   float RAA_1S_tots;
   float RAA_2S_tot;
   float RAA_2S_tote;
   float RAA_2S_tots;
   
   /// 2.
   float syst_aa_glob = sqrt(pow(tracking_aa,2)+pow(syst_nmb,2)); // all the AA syst, but TAA (pt to pt)
   float syst1S_pp_glob = sqrt(syst1S_pptnp_tot*syst1S_pptnp_tot+syst1S_pp_tot*syst1S_pp_tot+pow(syst1S_ppgs_tot,2)+pow(stat1S_pp_tot,2)+pow(syst_lumi,2)+pow(tracking_pp,2)); //1S global syst. this is the box at RAA = 1
   float syst2S_pp_glob = sqrt(syst2S_pptnp_tot*syst2S_pptnp_tot+syst2S_pp_tot*syst2S_pp_tot+pow(syst2S_ppgs_tot,2)+pow(stat2S_pp_tot,2)+pow(syst_lumi,2)+pow(tracking_pp,2)); //2S global syst. this is the box at RAA = 1
   /// then ,for RAA, i get one systematic in points (not defined here, but below) and i get one systematic pp (stat+syst of the total pp reference) and i also have the pp lumi. Then it's different for 1S and 2S (because of different total cross section uncertainties).

   float syst1S_raa_tot_aa; //for the integrated RAA: we can split in two parts, one part is pp, one part is pbpb... but in the end, it's only one syst for the centrality integrated number.
   float syst1S_raa_tot_pp;
 
   float syst2S_raa_tot_aa;
   float syst2S_raa_tot_pp;
   float stat1S_aa_cent[nCentBins_2014]={}; //stat. aa relative uncertainty
   float syst1S_aatnp_cent[nCentBins_2014]={};// tnp uncertainty
   float syst1S_aa_Cent[nCentBins_2014]={};   //fit syst. uncertainty.
   float syst1S_taa[nCentBins_2014]={};   //taa syst. uncertainty.
   float syst1S_aags_cent[nCentBins_2014]={};   //gen shape
   float syst1S_aasta_cent[nCentBins_2014]={}; ///sta uncertainty
   float syst1S_aamuid_cent[nCentBins_2014]={};/// muid uncertainty
   float syst1S_csaa_cent[nCentBins_2014]={}; /// quadratic sum.
   ///
   float stat2S_aa_cent[nCentBins2S]={}; //stat. aa relative uncertainty
   float syst2S_aatnp_cent[nCentBins2S]={};// tnp uncertainty
   float syst2S_aa_Cent[nCentBins2S]={};   //fit syst. uncertainty.
   float syst2S_taa[nCentBins2S]={};   //taa syst. uncertainty.
   float syst2S_aags_cent[nCentBins2S]={};   //gen shape
   float syst2S_aasta_cent[nCentBins2S]={}; ///sta uncertainty
   float syst2S_aamuid_cent[nCentBins2S]={};/// muid uncertainty
   float syst2S_csaa_cent[nCentBins2S]={}; /// quadratic sum.
   /// 3.
   syst1S_aa_Cent[0]=ppAlphaSyst(N1S_aa_cent3p5[0],N1S_aa_cents_100,N1B_aa_cents_100,N1S_pp_rap4_2014Large[0],N1S_pp_rap4Larges_1p2[1]) ;
   syst1S_aa_Cent[1]=ppAlphaSyst(N1S_aa_cent3p5[1],N1S_aa_cents_70,N1B_aa_cents_70,N1S_pp_rap4_2014Large[0],N1S_pp_rap4Larges_1p2[1]) ;
   syst1S_aa_Cent[2]=ppAlphaSyst(N1S_aa_cent3p5[2],N1S_aa_cents_50,N1B_aa_cents_50,N1S_pp_rap4_2014Large[0],N1S_pp_rap4Larges_1p2[1]) ;
   syst1S_aa_Cent[3]=ppAlphaSyst(N1S_aa_cent3p5[3],N1S_aa_cents_40,N1B_aa_cents_40,N1S_pp_rap4_2014Large[0],N1S_pp_rap4Larges_1p2[1]) ;
   syst1S_aa_Cent[4]=ppAlphaSyst(N1S_aa_cent3p5[4],N1S_aa_cents_30,N1B_aa_cents_30,N1S_pp_rap4_2014Large[0],N1S_pp_rap4Larges_1p2[1]) ;
   syst1S_aa_Cent[5]=ppAlphaSyst(N1S_aa_cent3p5[5],N1S_aa_cents_20,N1B_aa_cents_20,N1S_pp_rap4_2014Large[0],N1S_pp_rap4Larges_1p2[1]) ;
   syst1S_aa_Cent[6]=ppAlphaSyst(N1S_aa_cent3p5[6],N1S_aa_cents_10,N1B_aa_cents_10,N1S_pp_rap4_2014Large[0],N1S_pp_rap4Larges_1p2[1]) ;
   syst1S_aa_Cent[7]=ppAlphaSyst(N1S_aa_cent3p5[7],N1S_aa_cents_5,N1B_aa_cents_5,N1S_pp_rap4_2014Large[0],N1S_pp_rap4Larges_1p2[1]) ;
   //CENT 2S	
   syst2S_aa_Cent[0]=ppAlphaSyst(N2S_aa_cent4Large[0],N2S_aa_cent4Larges_100,N2B_aa_cent4Larges_100,N2S_pp_rap4_2014Large[0],N2S_pp_rap4Larges_1p2[1]) ;
   syst2S_aa_Cent[1]=ppAlphaSyst(N2S_aa_cent4Large[1],N2S_aa_cent4Larges_50,N2B_aa_cent4Larges_50,N2S_pp_rap4_2014Large[0],N2S_pp_rap4Larges_1p2[1]) ;
   syst2S_aa_Cent[2]=ppAlphaSyst(N2S_aa_cent4Large[2],N2S_aa_cent4Larges_30,N2B_aa_cent4Larges_30,N2S_pp_rap4_2014Large[0],N2S_pp_rap4Larges_1p2[1]) ;
   syst2S_aa_Cent[3]=ppAlphaSyst(N2S_aa_cent4Large[3],N2S_aa_cent4Larges_10,N2B_aa_cent4Larges_10,N2S_pp_rap4_2014Large[0],N2S_pp_rap4Larges_1p2[1]) ;
   ///4. calcul
   // 1S
   for(int i=0; i<nCentBins_2014;i++){
     stat1S_aa_cent[i]=N1S_aa_cent3p5e[i]/N1S_aa_cent3p5[i]; //stat. aa relative uncertainty
     syst1S_aatnp_cent[i]=sqrt(pow(Aet_1S_pyquen_cent2014_muIDTrigs[i]/Aet_1S_pyquen_cent2014_muIDTrig[i],2)+pow(Aet_1S_pyquen_cent2014_STAs[i]/Aet_1S_pyquen_cent2014_STA[i],2));// tnp uncertainty
     syst1S_aags_cent[i]=Aet_1S_pyquen_cent2014_STAe[i]/Aet_1S_pyquen_cent2014_STA[i];   //gen shape
     syst1S_aasta_cent[i]=Aet_1S_pyquen_cent2014_STAs[i]/Aet_1S_pyquen_cent2014_STA[i]; ///sta uncertainty
     syst1S_aamuid_cent[i]=Aet_1S_pyquen_cent2014_muIDTrigs[i]/Aet_1S_pyquen_cent2014_muIDTrig[i];/// muid uncertainty
     syst1S_taa[i]=taa2014e[i]/taa2014[i];
     syst1S_csaa_cent[i]=sqrt(pow(syst1S_aatnp_cent[i],2)+pow(syst1S_aags_cent[i],2)+pow(syst1S_taa[i],2)+pow(syst1S_aa_Cent[i],2)); /// quadratic sum of 4 pt to pt sources.
   }
   // 2S
   for(int i=0; i<nCentBins2S;i++){
     stat2S_aa_cent[i]=N2S_aa_cent4Largee[i]/N2S_aa_cent4Large[i]; //stat. aa relative uncertainty
     syst2S_aatnp_cent[i]=sqrt(pow(Aet_2S_pyquen_cent2014_muIDTrige[i]/Aet_2S_pyquen_cent2014[i],2)+pow(Aet_2S_pyquen_cent2014_STAe[i]/Aet_2S_pyquen_cent2014[i],2));// tnp uncertainty
     syst2S_aags_cent[i]=Aet_2S_pyquen_cent2014e[i]/Aet_2S_pyquen_cent2014[i];   //gen shape
     syst2S_aasta_cent[i]=Aet_2S_pyquen_cent2014_STAe[i]/Aet_2S_pyquen_cent2014[i]; ///sta uncertainty
     syst2S_aamuid_cent[i]=Aet_2S_pyquen_cent2014_muIDTrige[i]/Aet_2S_pyquen_cent2014[i];/// muid uncertainty
     syst2S_taa[i]=taa2Se[i]/taa2S[i];
     syst2S_csaa_cent[i]=sqrt(pow(syst2S_aatnp_cent[i],2)+pow(syst2S_aags_cent[i],2)+pow(syst2S_taa[i],2)+pow(syst2S_aa_Cent[i],2)); /// quadratic sum of 4 pt to pt sources.
   }
 
   /// 5. compute CS PbPb and RAA!
   for(int i=0; i<nCentBins_2014;i++){
     taa2014[i]=taa2014[i]*1000;
     CS1S_aa_cent[i]=computeRatio( N1S_aa_cent3p5[i] , Aet_1S_pyquen_cent2014_STA[i] )/(mb_percentage2014[i]*N_MB_corr * taa2014[i]*RapBinWidth);
     CS1S_aa_cente[i]=computeRatioError( N1S_aa_cent3p5[i] , Aet_1S_pyquen_cent2014_STA[i], N1S_aa_cent3p5e[i] , 0)/(mb_percentage2014[i]*N_MB_corr * taa2014[i]*RapBinWidth); // that's just the pbpb stat uncertainty!
     CS1S_aa_cents[i]=CS1S_aa_cent[i]*syst1S_csaa_cent[i];
     // RAA now. CS_aa is divided by CS_pp
     RAA_1S_cent[i]= computeRatio( CS1S_aa_cent[i] , CS1S_pp_tot);
     RAA_1S_cente[i]= computeRatioError( CS1S_aa_cent[i] , CS1S_pp_tot,  CS1S_aa_cente[i] ,0);// // that's just the pbpb stat uncertainty!
     RAA_1S_cents[i]=RAA_1S_cent[i]*syst1S_csaa_cent[i];
   }

   for(int i=0; i<nCentBins2S;i++){
     taa2S[i]=taa2S[i]*1000;
     CS2S_aa_cent[i]=computeRatio( N2S_aa_cent4Large[i] , Aet_2S_pyquen_cent2014[i] )/(mb_percentage2S[i]*N_MB_corr * taa2S[i]*RapBinWidth);
     CS2S_aa_cente[i]=computeRatioError( N2S_aa_cent4Large[i] , Aet_2S_pyquen_cent2014[i], N2S_aa_cent4Largee[i] , 0)/(mb_percentage2S[i]*N_MB_corr * taa2S[i]*RapBinWidth); //
     CS2S_aa_cents[i]=CS2S_aa_cent[i]*syst2S_csaa_cent[i];
     // RAA now. CS_aa is divided by CS_pp
     RAA_2S_cent[i]= computeRatio( CS2S_aa_cent[i] , CS2S_pp_tot);
     RAA_2S_cente[i]= computeRatioError( CS2S_aa_cent[i] , CS2S_pp_tot,  CS2S_aa_cente[i] ,0);// // that's just the pbpb stat uncertainty!
     RAA_2S_cents[i]=RAA_2S_cent[i]*syst2S_csaa_cent[i];
   }
   /// RAA total results:

   /// total RAA syst come last so we're in line with the settings of above (plotting or not CS global uncertainties, tracking, taa.
   syst1S_raa_tot_pp=sqrt(pow(stat1S_pp_tot,2)+pow(syst1S_pptnp_tot,2)+pow(syst1S_pp_tot,2)+pow(syst1S_ppgs_tot,2)+pow(syst_lumi,2)+pow(tracking_pp,2));
   syst1S_raa_tot_aa=sqrt(pow(syst1S_aatnp_tot,2)+pow(syst1S_aa_tot,2)+pow(syst1S_aags_tot,2)+pow(syst_nmb,2)+pow(tracking_aa,2)+pow(syst_taa,2));
   syst2S_raa_tot_pp=sqrt(pow(stat2S_pp_tot,2)+pow(syst2S_pptnp_tot,2)+pow(syst2S_pp_tot,2)+pow(syst2S_ppgs_tot,2)+pow(syst_lumi,2)+pow(tracking_pp,2));
   syst2S_raa_tot_aa=sqrt(pow(syst2S_aatnp_tot,2)+pow(syst2S_aa_tot,2)+pow(syst2S_aags_tot,2)+pow(syst_nmb,2)+pow(tracking_aa,2)+pow(syst_taa,2));
  
   RAA_1S_tot =  computeRatio( CS1S_aa_tot , CS1S_pp_tot);
   RAA_1S_tote= computeRatioError( CS1S_aa_tot, CS1S_pp_tot,  CS1S_aa_tote ,0);// // that's just the pbpb stat uncertainty!
   RAA_1S_tots = syst1S_raa_tot_aa*RAA_1S_tot;
   RAA_2S_tot =  computeRatio( CS2S_aa_tot , CS2S_pp_tot);
   RAA_2S_tote= computeRatioError( CS2S_aa_tot, CS2S_pp_tot,  CS2S_aa_tote ,0);// // that's just the pbpb stat uncertainty!
   RAA_2S_tots = syst2S_raa_tot_aa*RAA_2S_tot;
   /// 5.a prints: CSAA vs centrality
   ofSyst <<"1S PbPb cross section vs centrality | stat err. | syst err. = +/- syst.fit +/- syst.gs +/- syst.muid +/- syst.sta +/- syst.taa +/- syst.mb +/- syst.trk"<<endl;
   for(int j =nCentBins_2014-1 ; j>=0 ; j--)
     {
       ofSyst << (binsCent[j]).c_str() << " & " << setprecision(2) <<
	 stat1S_aa_cent[j]      << " & " <<
	 syst1S_csaa_cent[j]    << " & " <<
	 syst1S_aa_Cent[j]      << " & " <<
	 syst1S_aags_cent[j]    << " & " <<
	 syst1S_aamuid_cent[j]  << " & " <<
	 syst1S_aasta_cent[j]   << " & " <<
	 syst1S_taa[j]           << " & " <<
	 syst_nmb           << " & " <<
	 tracking_aa <<" \\\\ " << endl;
     }
   ofRes<<"1S Cross section (cent)| CS +/- stat err. +/- syst err. +/- global PbPb unc. "<<endl;
   for(int j =nCentBins_2014-1 ; j>=0 ; j--)
     {
       ofRes << (binsCent[j]).c_str() << " & " << setprecision(3) << 
	 CS1S_aa_cent[j] << " \\pm "<<
	 CS1S_aa_cente[j] <<" \\pm "<<
	 CS1S_aa_cents[j] <<" \\pm "<<
	 CS1S_aa_cent[j]*syst_aa_glob  << " \\\\"
	     << endl;
     }
   ofSyst <<"2S PbPb cross section vs centrality | stat err. | syst err. = +/- syst.fit +/- syst.gs +/- syst.muid +/- syst.sta +/- syst.taa +/- syst.mb +/- syst.trk"<<endl;
   for(int j =nCentBins2S-1 ; j>=0 ; j--)
     {
       ofSyst << (bins4Bin[j]).c_str() << " & " << setprecision(2) <<
	 stat2S_aa_cent[j]      << " & " <<
	 syst2S_csaa_cent[j]    << " & " <<
	 syst2S_aa_Cent[j]      << " & " <<
	 syst2S_aags_cent[j]    << " & " <<
	 syst2S_aamuid_cent[j]  << " & " <<
	 syst2S_aasta_cent[j]   << " & " <<
	 syst2S_taa[j]          << " & " <<
	 syst_nmb               << " & " <<
	 tracking_aa <<" \\\\ " << endl;
     }
   ofRes<<"2S  Cross section (cent) | CS +/- stat err. +/- syst err. +/- global unc. "<<endl;
   for(int j =nCentBins2S-1 ; j>=0 ; j--)
     {
       ofRes << (bins4Bin[j]).c_str() << " & " << setprecision(3) << 
	 CS2S_aa_cent[j] << " \\pm "<<
	 CS2S_aa_cente[j] <<" \\pm "<<
	 CS2S_aa_cents[j] <<" \\pm "<<
	 CS2S_aa_cent[j]*syst_aa_glob  << " \\\\"
	     << endl;
     }
   /// 5.b prints: RAA vs centrality
   ofSyst <<"1S PbPb RAA vs centrality | stat err. | syst err. = +/- syst.fit +/- syst.gs +/- syst.muid +/- syst.sta +/- syst.taa | syst glob: pp (stat+syst+tnp+gs+trk+lumi) +/-  PbPb (syst.mb+syst.trk)"<<endl;
   for(int j =nCentBins_2014-1 ; j>=0 ; j--)
     {
       ofSyst << (binsCent[j]).c_str() << " & " << setprecision(2) <<
	 stat1S_aa_cent[j]      << " & " <<
	 syst1S_csaa_cent[j]      << " & " <<
	 syst1S_aa_Cent[j]      << " & " <<
	 syst1S_aags_cent[j]    << " & " <<
	 syst1S_aamuid_cent[j]  << " & " <<
	 syst1S_aasta_cent[j]   << " & " <<
	 syst1S_taa[j]           << " & " <<
	 syst1S_pp_glob      << " & " <<
	 syst_aa_glob << "\\\\" << endl;
     }
   /// for tables
   ofRes<<"1S RAA (cent)| CS +/- stat err. +/- syst err. +/- global unc. "<<endl;
   for(int j =nCentBins_2014-1 ; j>=0 ; j--)
     {
       ofRes << (binsCent[j]).c_str() << " & " << setprecision(3) << 
	 RAA_1S_cent[j] << " \\pm "<<
	 RAA_1S_cente[j] <<" \\pm "<<
	 RAA_1S_cents[j] <<" \\pm "<<
	 RAA_1S_cent[j]*syst_aa_glob << " \\pm" <<
	 RAA_1S_cent[j]*syst1S_pp_glob<< " \\\\ "
	     << endl;
     }
   /// for plots, to share with your friends on facebook
   ofplot<<"float raa1Scent["<<nCentBins_2014<<"]={";
   for(int j =0 ; j<nCentBins_2014 ; j++)
     {
       ofplot <<RAA_1S_cent[j]; if (j==nCentBins_2014-1) ofplot<<"};"<<endl; else ofplot<<",";
     }
   ofplot<<"float raa1Scent_e["<<nCentBins_2014<<"]={";
   for(int j =0 ; j<nCentBins_2014 ; j++)
     {
       ofplot <<RAA_1S_cente[j]; if (j==nCentBins_2014-1) ofplot<<"};"<<endl; else ofplot<<",";
     }
   ofplot<<"float raa1Scent_s["<<nCentBins_2014<<"]={";
   for(int j =0 ; j<nCentBins_2014 ; j++)
     {
       ofplot <<RAA_1S_cents[j]; if (j==nCentBins_2014-1) ofplot<<"};"<<endl; else ofplot<<",";
     }   
   ofplot<<"float npart1S["<<nCentBins_2014<<"]={";
   for(int j=0; j<nCentBins_2014 ; j++)
     {
       ofplot<<nPart2014[j]; if  (j==nCentBins_2014-1) ofplot<<"};"<<endl; else ofplot<<",";
     }

   
   ofSyst <<"2S PbPb RAA vs centrality | stat err. | syst err. = +/- syst.fit +/- syst.gs +/- syst.muid +/- syst.sta +/- syst.taa +/- syst.mb +/- syst.trk"<<endl;
   for(int j =nCentBins2S-1 ; j>=0 ; j--)
     {
       ofSyst << (bins4Bin[j]).c_str() << " & " << setprecision(2) <<
	 stat2S_aa_cent[j]      << " & " <<
	 syst2S_csaa_cent[j]    << " & " <<
	 syst2S_aa_Cent[j]    << " & " <<
	 syst2S_aags_cent[j]    << " & " <<
	 syst2S_aamuid_cent[j]  << " & " <<
	 syst2S_aasta_cent[j]   << " & " <<
	 syst2S_taa[j]          << " & " <<
	 syst2S_pp_glob      << " & " <<
	 syst_aa_glob << "\\\\" << endl;
     }
   //for tables
   ofRes<<"2S RAA (cent)| CS +/- stat err. +/- syst err. +/- global unc. "<<endl;
   for(int j =nCentBins2S-1 ; j>=0 ; j--)
     {
       ofRes << (bins4Bin[j]).c_str() << " & " << setprecision(3) << 
	 RAA_2S_cent[j] << " \\pm "<<
	 RAA_2S_cente[j] <<" \\pm "<<
	 RAA_2S_cents[j] <<" \\pm "<<
	 RAA_2S_cent[j]*syst_aa_glob << " \\pm " <<
	 RAA_2S_cent[j]*syst2S_pp_glob << "\\\\"
	     << endl;
     }
   /// for plots, to share with your friends on facebook
   ofplot<<"float raa2Scent["<<nCentBins2S<<"]={";
   for(int j =0 ; j<nCentBins2S ; j++)
     {
       ofplot <<RAA_2S_cent[j]; if (j==nCentBins2S-1) ofplot<<"};"<<endl; else ofplot<<",";
     }
   ofplot<<"float raa2Scent_e["<<nCentBins2S<<"]={";
   for(int j =0 ; j<nCentBins2S ; j++)
     {
       ofplot <<RAA_2S_cente[j]; if (j==nCentBins2S-1) ofplot<<"};"<<endl; else ofplot<<",";
     }
   ofplot<<"float raa2Scent_s["<<nCentBins2S<<"]={";
   for(int j =0 ; j<nCentBins2S ; j++)
     {
       ofplot <<RAA_2S_cents[j]; if (j==nCentBins2S-1) ofplot<<"};"<<endl; else ofplot<<",";
     }   
   ofplot<<"float npart2S["<<nCentBins2S<<"]={";
   for(int j=0; j<nCentBins2S ; j++)
     {
       ofplot<<nPart2[j]; if  (j==nCentBins2S-1) ofplot<<"};"<<endl; else ofplot<<",";
     }
   ofplot<<"float syst1S_pp_glob="<<syst1S_pp_glob<<";"<<endl;
   ofplot<<"float syst2S_pp_glob="<<syst2S_pp_glob<<";"<<endl;
   ofplot<<"float syst_aa_glob="<<syst_aa_glob<<";"<<endl;
   ofplot<<"float systXS_raa_glob="<<systXS_raa_glob<<";"<<endl;
   /// 5.c prints: total RAA
   ofSyst <<"1S aa integrated | stat err. | syst err. = +/- syst.fit +/- syst.gs +/- syst.muid +/- syst.sta +/- syst.taa +/- syst.cspp +/- syst.trk"<<endl;
   ofSyst <<  "0-100" << " & " << setprecision(2) << 
     stat1S_aa_tot      << " & " <<
     syst1S_raa_tot_aa      << " & " <<
     syst1S_raa_tot_pp      <<" \\\\ " << endl;

   ofRes<<"1S integrated RAA | RAA +/- stat err. +/- syst err. +/- global PbPb unc. +/- global pp unc "<<endl;
   
   ofRes << "0-100" << " & " << setprecision(3) << 
     RAA_1S_tot << " \\pm "<<
     RAA_1S_tote <<" \\pm "<<
     RAA_1S_tots <<" \\pm "<<
     RAA_1S_tot*syst1S_raa_tot_pp<< " \\\\ "
	 << endl;

   ofSyst <<"2S aa integrated | stat err. | syst PbPb | syst pp"<<endl;
   ofSyst <<  "0-100" << " & " << setprecision(2) << 
     stat2S_aa_tot      << " & " <<
     syst2S_raa_tot_aa      << " & " <<
     syst2S_raa_tot_pp      <<" \\\\ " << endl;

   ofRes<<"2S integrated RAA | RAA +/- stat err. +/- syst err. +/- global PbPb unc. +/- global pp unc. "<<endl;
   
   ofRes << "0-100" << " & " << setprecision(3) << 
     RAA_2S_tot << " \\pm "<<
     RAA_2S_tote <<" \\pm "<<
     RAA_2S_tots <<" \\pm "<<
     RAA_2S_tot*syst2S_raa_tot_pp<< " \\\\ "
	 << endl;
     
   // 6. RAA cent plot
   //   gStyle->SetPadRightMargin(0.04); //reverting style here (otherwise Npart=400 eats the margin)

   TCanvas *cRaacent = new TCanvas("cRaacent","cRaacent",750,700);  
   cRaacent->cd();
   TPad *main = new TPad("main","Main TPad",0.,0.,xfrac,1.);
   main->SetLeftMargin(gStyle->GetPadLeftMargin()/xfrac);
   main->SetRightMargin(0);
   main->SetFrameBorderMode(0);
   main->SetBorderMode(0);
   main->SetBorderSize(0);
   main->Draw();
   main->cd();
   TLine line, liner;
   TH1F *haxes = new TH1F("haxesl","haxesl",1,-10,420);
   haxes->GetXaxis()->SetTickLength(gStyle->GetTickLength("X")/xfrac);
   // haxes->GetYaxis()->SetTickLength(gStyle->GetTickLength("Y")*xfrac);
   line = TLine(0,1,420,1);
   haxes->GetYaxis()->SetRangeUser(0,1.6);
   TH1F *haxesr = new TH1F("haxesr","haxesr",1,0,2);
   haxesr->GetXaxis()->SetTickLength(0);
   haxesr->GetYaxis()->SetTickLength(gStyle->GetTickLength("Y")/(1.1-xfrac));
   haxesr->GetXaxis()->SetTitleSize(0);
   haxesr->GetXaxis()->SetLabelSize(0);
   haxesr->GetYaxis()->SetRangeUser(0,1.6);
   liner = TLine(0,1,2,1);
   haxes->GetYaxis()->SetTitle("R_{AA}");
   haxes->GetXaxis()->SetTitle("#LTN_{part}#GT");
   haxes->GetXaxis()->SetTitleSize(gTextSize+0.01);
   haxes->GetYaxis()->SetTitleSize(gTextSize+0.015);
   haxes->GetXaxis()->CenterTitle(kTRUE);
   haxes->GetXaxis()->SetTitleOffset(1.06);
   haxes->Draw();
   line.Draw();
   // TF1 *f4RaaCent = new TF1("f4RaaCent","1",-10,410);
   // f4RaaCent->SetLineWidth(1);
   // f4RaaCent->SetLineColor(kBlack);
   // f4RaaCent->GetXaxis()->SetTitle("N_{part}");
   // f4RaaCent->GetYaxis()->SetTitle("R_{AA}");   
   // f4RaaCent->GetXaxis()->SetTitleOffset(f4RaaCent->GetXaxis()->GetTitleOffset()*1.3);
   // f4RaaCent->GetXaxis()->SetTitleSize(0.045);
   // f4RaaCent->GetYaxis()->SetRangeUser(0.,1.6);
   // f4RaaCent->GetXaxis()->CenterTitle(kTRUE);
   // f4RaaCent->Draw();
   int plug=1;
   TLegend *leg2= new TLegend(0.25,0.65,0.4,0.72);
   TLegend *leg3 = new TLegend(0.25,0.7,0.4,0.85);
   leg3->SetBorderSize(0);
   leg3->SetTextSize(gTextSize-0.01);
   leg3->SetTextFont(42);
   leg3->SetLineColor(0);
   leg3->SetLineStyle(2);
   leg3->SetLineWidth(1);
   leg3->SetFillColor(0);
   leg3->SetFillStyle(0);
   leg2->SetBorderSize(0);
   leg2->SetTextSize(gTextSize-0.01);
   leg2->SetTextFont(42);
   leg2->SetLineColor(0);
   leg2->SetLineStyle(1);
   leg2->SetLineWidth(2);
   leg2->SetFillColor(0);
   leg2->SetFillStyle(0);

    //M.Strickland data part
   if (plug==0){
   ////Strickland comparisons are now based on his '5TeV predictions' paper, which has 2.76 as a reference. The advantage is basically more points on the prediction curve. Check out https://arxiv.org/src/1605.03561v1/anc
      float npart_th[407];
      float raa1Snpart_the1x0[407], raa1Snpart_the2x0[407], raa1Snpart_the3x0[407];
      float raa2Snpart_the1x0[407], raa2Snpart_the2x0[407], raa2Snpart_the3x0[407];
      ifstream inpart1Sx0;
      ifstream inpart2Sx0;
      // this is the input file for 1Snpart and xi=0
      inpart1Sx0.open("Strick_Npart_1S_xi0.tsv");
      inpart2Sx0.open("Strick_Npart_2S_xi0.tsv");
      for (int i=0; i<407;i++){
	inpart1Sx0>> npart_th[i]>> raa1Snpart_the1x0[i]>> raa1Snpart_the2x0[i]>> raa1Snpart_the3x0[i];
	inpart2Sx0>> npart_th[i]>> raa2Snpart_the1x0[i]>> raa2Snpart_the2x0[i]>> raa2Snpart_the3x0[i];
      }
      TGraph *sups1Snpart1x0 = new TGraph(407,npart_th,raa1Snpart_the1x0);
      sups1Snpart1x0->SetLineWidth(2);
      sups1Snpart1x0->SetLineColor(color1Sraa);
      sups1Snpart1x0->SetLineStyle(1);
      sups1Snpart1x0->Draw("l same");
      TGraph *sups1Snpart2x0 = new TGraph(407,npart_th,raa1Snpart_the2x0);
      sups1Snpart2x0->SetLineWidth(2);
      sups1Snpart2x0->SetLineColor(color1Sraa);
      sups1Snpart2x0->SetLineStyle(2);
      sups1Snpart2x0->Draw("l same");
      TGraph *sups1Snpart3x0 = new TGraph(407,npart_th,raa1Snpart_the3x0);
      sups1Snpart3x0->SetLineWidth(2);
      sups1Snpart3x0->SetLineColor(color1Sraa);
      sups1Snpart3x0->SetLineStyle(3);
      sups1Snpart3x0->Draw("l same");
      TGraph *sups2Snpart1x0 = new TGraph(407,npart_th,raa2Snpart_the1x0);
      sups2Snpart1x0->SetLineWidth(2);
      sups2Snpart1x0->SetLineColor(color2Sraa);
      sups2Snpart1x0->SetLineStyle(1);
      sups2Snpart1x0->Draw("l same");
      TGraph *sups2Snpart2x0 = new TGraph(407,npart_th,raa2Snpart_the2x0);
      sups2Snpart2x0->SetLineWidth(2);
      sups2Snpart2x0->SetLineColor(color2Sraa);
      sups2Snpart2x0->SetLineStyle(2);
      sups2Snpart2x0->Draw("l same");
      TGraph *sups2Snpart3x0 = new TGraph(407,npart_th,raa2Snpart_the3x0);
      sups2Snpart3x0->SetLineWidth(2);
      sups2Snpart3x0->SetLineColor(color2Sraa);
      sups2Snpart3x0->SetLineStyle(3);
      sups2Snpart3x0->Draw("l same");


      leg3->SetHeader("Strickland et al., Universe 2016, 2(3), 16");
      leg2->SetHeader("");
      leg3->AddEntry(sups1Snpart3x0," 4#pi#eta/s = 3","L");
      leg3->AddEntry(sups1Snpart2x0," 4#pi#eta/s = 2","L");
      leg3->AddEntry(sups1Snpart1x0," 4#pi#eta/s = 1","L");

      leg2->Draw();
      leg3->Draw();
}else if (plug==1){
      //M.Rapp data part

      ifstream in_SBS1S, in_SBS2S;
      in_SBS1S.open("LHC-SBS-nabs0.0-2.0-1sRAA.dat");
      in_SBS2S.open("LHC-SBS-nabs0.0-2.0-2sRAA.dat");

      float N_part_1S[28], N_coll_1S[28], Absorp_l_1S[28], Primordial_l_1S[28], Total_l_1S[28], Absorp_h_1S[28], Primordial_h_1S[28], Total_h_1S[28];
      float N_part_Err[28], Absorp_1S[28], Primordial_1S[28], Total_1S[28], Absorp_1S_err[28], Primordial_1S_err[28], Total_1S_err[28];
      float regen_l_1S[28], regen_h_1S[28],  regen_mean_1S[28], regen_err_1S[28];

   
      float N_part_2S[50], N_coll_2S[50], Absorp_l_2S[50], Primordial_l_2S[50], Total_l_2S[50], Absorp_h_2S[50], Primordial_h_2S[50], Total_h_2S[50];
      float Absorp_2S[50], Primordial_2S[50], Total_2S[50], Absorp_2S_err[50], Primordial_2S_err[50], Total_2S_err[50];
      float regen_l_2S[50], regen_h_2S[50], regen_mean_2S[50], regen_err_2S[50];
      for (int i=0; i<28; i++) {
	in_SBS1S >> N_part_1S[i] >> N_coll_1S[i] >> Absorp_l_1S[i] >> Primordial_l_1S[i] >> Total_l_1S[i] >> Absorp_h_1S[i] >> Primordial_h_1S[i] >> Total_h_1S[i];
   
	Absorp_1S[i] = (Absorp_l_1S[i] + Absorp_h_1S[i])/2;
	Primordial_1S[i] = (Primordial_l_1S[i] + Primordial_h_1S[i])/2;
	Total_1S[i] = (Total_l_1S[i] + Total_h_1S[i])/2;
	Absorp_1S_err[i] = (Absorp_l_1S[i] - Absorp_h_1S[i])/2;
	Primordial_1S_err[i] = (Primordial_l_1S[i] - Primordial_h_1S[i])/2;
	Total_1S_err[i] = (Total_l_1S[i] - Total_h_1S[i])/2;
	regen_l_1S[i] = Total_l_1S[i] - Primordial_l_1S[i];
	regen_h_1S[i] = Total_h_1S[i] - Primordial_h_1S[i];
	regen_mean_1S[i] = (regen_l_1S[i] + regen_h_1S[i])/2;
	regen_err_1S[i] = (regen_l_1S[i] - regen_h_1S[i])/2;
	N_part_Err[i]=0;

	in_SBS2S >> N_part_2S[i] >> N_coll_2S[i] >> Absorp_l_2S[i] >> Primordial_l_2S[i] >> Total_l_2S[i] >> Absorp_h_2S[i] >> Primordial_h_2S[i] >> Total_h_2S[i];

	Absorp_2S[i] = (Absorp_l_2S[i] + Absorp_h_2S[i])/2;
	Primordial_2S[i] = (Primordial_l_2S[i] + Primordial_h_2S[i])/2;
	Total_2S[i] = (Total_l_2S[i] + Total_h_2S[i])/2;
	Absorp_2S_err[i] = (Absorp_l_2S[i] - Absorp_h_2S[i])/2;
	Primordial_2S_err[i] = (Primordial_l_2S[i] - Primordial_h_2S[i])/2;
	Total_2S_err[i] = (Total_l_2S[i] - Total_h_2S[i])/2;
	regen_l_2S[i] = Total_l_2S[i] - Primordial_l_2S[i];
	regen_h_2S[i] = Total_h_2S[i] - Primordial_h_2S[i];
	regen_mean_2S[i] = (regen_l_2S[i] + regen_h_2S[i])/2;
	regen_err_2S[i] = (regen_l_2S[i] - regen_h_2S[i])/2;
      }
      TGraphErrors* SBS_Absorp_1S = new TGraphErrors(28, N_part_1S, Absorp_1S, N_part_Err, Absorp_1S_err);
      TGraphErrors* SBS_Primordial_1S = new TGraphErrors(28, N_part_1S, Primordial_1S, N_part_Err, Primordial_1S_err);
      TGraphErrors* SBS_Total_1S = new TGraphErrors(28, N_part_1S, Total_1S, N_part_Err, Total_1S_err);
      TGraph* SBS_regen_1S = new TGraph(28, N_part_1S, regen_mean_1S);

      TGraphErrors* SBS_Absorp_2S = new TGraphErrors(28, N_part_2S, Absorp_2S, N_part_Err, Absorp_2S_err);
      TGraphErrors* SBS_Primordial_2S = new TGraphErrors(28, N_part_2S, Primordial_2S, N_part_Err, Primordial_2S_err);
      TGraphErrors* SBS_Total_2S = new TGraphErrors(28, N_part_2S, Total_2S, N_part_Err, Total_2S_err);
      TGraph* SBS_regen_2S = new TGraph(28, N_part_2S, regen_mean_2S);

      SBS_Total_1S->SetLineWidth(2);
      SBS_Total_2S->SetLineWidth(2);
      SBS_Total_1S->SetFillColorAlpha(color1Spp,1);
      SBS_Total_1S->SetFillStyle(3001);
      SBS_Total_2S->SetFillColorAlpha(color1Saa,1);
      SBS_Total_2S->SetFillStyle(1001);
 
      SBS_Total_1S->Draw("3");
      SBS_Total_2S->Draw("3");   

      SBS_Absorp_1S->SetFillColor(kOrange-4);
      SBS_Absorp_1S->SetLineColor(kOrange-4);
      SBS_Absorp_1S->Draw("3");

      TLegend *legR3 = new TLegend(0.29,0.68,0.45,0.81);
      legR3->SetBorderSize(0);
      legR3->SetTextSize(gTextSize-0.005);
      legR3->SetTextFont(42);
      legR3->SetLineColor(0);
      legR3->SetLineStyle(2);
      legR3->SetLineWidth(1);
      legR3->SetFillColor(0);
      legR3->SetFillStyle(0);
      // legR3->SetHeader("");
      legR3->AddEntry(SBS_Total_1S,"#varUpsilon(1S)","f");
      legR3->AddEntry(SBS_Total_2S,"#varUpsilon(2S)","f");
      legR3->Draw();
      TLatex *NucAbs = new TLatex(200,0.85,"Nuc. Abs.");
      NucAbs->Draw();
      TLatex latexrappC;
      latexrappC.SetTextSize(gTextSize);
      latexrappC.SetTextFont(42);
      latexrappC.DrawLatex(40,1.45,"Eur. Phys. J. A 48 (2012) 72");
    } 
   TGraphErrors *gcent1syst = new TGraphErrors(nCentBins_2014,nPart2014,RAA_1S_cent,centErr2014,RAA_1S_cents); //for fun
   gcent1syst->SetLineColor(color1Sraa);
   gcent1syst->SetFillStyle(0);
   gcent1syst->SetLineWidth(2);
   gcent1syst->SetMarkerSize(0);
   gcent1syst->Draw("2");
   TGraphErrors *gcent1 = new TGraphErrors(nCentBins_2014,nPart2014,RAA_1S_cent,centnoErr,RAA_1S_cente); //for fun
   gcent1->SetMarkerColor(color1Sraa);
   gcent1->SetMarkerStyle(symbol1S);
   gcent1->SetMarkerSize(markerSize);

   TGraphErrors *gcent1circle = new TGraphErrors(nCentBins_2014,nPart2014,RAA_1S_cent,centnoErr,RAA_1S_cente);
   gcent1circle->SetMarkerStyle(symbol1Sc);
   gcent1circle->SetMarkerSize(markerSize);
   gcent1circle->SetLineColor(kBlack);
   gcent1circle->SetLineWidth(2);
   gcent1->Draw("pe");
   gcent1circle->Draw("p");
   //  f4RaaCent->Draw("same");
   gPad->RedrawAxis();
   TGraphErrors *gcent2syst = new TGraphErrors(nCentBins2S,nPart2,RAA_2S_cent,centErr2014,RAA_2S_cents); //for fun
   gcent2syst->SetLineColor(color2Sraa);
   gcent2syst->SetFillStyle(0);
   gcent2syst->SetLineWidth(2);
   gcent2syst->SetMarkerSize(0);
   gcent2syst->Draw("2");
   TGraphErrors *gcent2 = new TGraphErrors(nCentBins2S,nPart2,RAA_2S_cent,centnoErr,RAA_2S_cente); //for fun

   gcent2->SetMarkerColor(color2Sraa);
   gcent2->SetMarkerStyle(symbol2S);
   gcent2->SetMarkerSize(markerSize);

   TGraphErrors *gcent2circle = new TGraphErrors(nCentBins2S,nPart2,RAA_2S_cent,centnoErr,RAA_2S_cente);
   gcent2circle->SetMarkerStyle(symbol2Sc);
   gcent2circle->SetMarkerSize(markerSize);
   gcent2circle->SetLineColor(kBlack);
   gcent2circle->SetLineWidth(2);
   gcent2->Draw("pe");
   gcent2circle->Draw("p");
   //  f4RaaCent->Draw("same");
   gPad->RedrawAxis();

   // TGraphErrors *gcent2 = new TGraphErrors(nCentBins2S,nPart2,RAA_2S_cent,centnoErr,RAA_2S_cente); //for fun

   // gcent2->SetMarkerColor(color2Sraa);
   // gcent2->SetMarkerStyle(symbol2S);
   // gcent2->SetMarkerSize(markerSize);

   
   TLegend *legend_RAAcent = new TLegend(0.75,0.45,0.88,0.6);
   legend_RAAcent->SetTextSize(gTextSize);
   legend_RAAcent->SetFillStyle(0);
   legend_RAAcent->SetFillColor(0);
   legend_RAAcent->SetBorderSize(0);
   legend_RAAcent->SetTextFont(42);
   legend_RAAcent->AddEntry(gcent1,"#varUpsilon(1S) ","p"); 
   legend_RAAcent->AddEntry(gcent2,"#varUpsilon(2S) ","p");


   // Cent. 0-100 %
   TLatex latexcentRaa;
   latexcentRaa.SetTextSize(gTextSize);
   latexcentRaa.SetTextFont(42);
   latexcentRaa.DrawLatex(150,0.8,"|y| < 2.4");


   TBox *box1S = new TBox(390,1-syst1S_pp_glob,405,1+syst1S_pp_glob); 
   box1S->SetFillColor(color1Sraa);
   box1S->Draw();
   TBox *box2S = new TBox(405,1-syst2S_pp_glob,420,1+syst2S_pp_glob); 
   box2S->SetFillColor(color2Sraa);
   box2S->Draw();
   TBox *boxAA = new TBox(375,1-syst_aa_glob,390,1+syst_aa_glob); 
   boxAA->SetFillStyle(0);
   boxAA->SetLineWidth(2);
   boxAA->SetLineColor(kBlack);
   boxAA->Draw();

   ///Doing the right-panel part here...
   cRaacent->cd();
   TPad *sec = new TPad("sec","2nd TPad",xfrac,0.,1.,1.);
   sec->SetRightMargin(gStyle->GetPadRightMargin()/(1.-xfrac));
   sec->SetLeftMargin(0);
   // sec->SetBottomMargin(gStyle->GetPadBottomMargin());
   // sec->SetTopMargin(gStyle->GetPadTopMargin());
   sec->SetFrameBorderMode(0);
   sec->SetBorderMode(0);
   sec->SetBorderSize(0);
   sec->Draw();
   sec->cd();
  
   haxesr->Draw();
   liner.Draw();
   TLatex tlr;
   tlr.SetTextSize(gTextSize*xfrac/(1.1-xfrac));
   //   tlr.SetTextFont(42);
   tlr.DrawLatex(0.55,1.15,"Cent.");
   tlr.DrawLatex(0.48,1.1,"0-100%");
 
   float x[1] = {0.8};
   float x1[1] = {1};
   float xe[1]= {0.3};
   float x0[1] = {centnoErr[0]};

   float y1[1] = {RAA_1S_tot};
   float y1e[1] = {RAA_1S_tote};
   float y1s[1] = {static_cast<float>(RAA_1S_tot*sqrt(pow(RAA_1S_tots,2)+pow(syst1S_raa_tot_pp,2)))};

   float y2[1] = {RAA_2S_tot};
   float y2e[1] = {RAA_2S_tote};
   float y2s[1] = {static_cast<float>(RAA_2S_tot*sqrt(pow(RAA_2S_tots,2)+pow(syst2S_raa_tot_pp,2)))};

   TGraphErrors *gtot1syst = new TGraphErrors(1,x1,y1,xe,y1s); //for fun
   gtot1syst->SetLineColor(color1Sraa);
   gtot1syst->SetFillStyle(0);
   gtot1syst->SetLineWidth(2);
   gtot1syst->SetMarkerSize(0);
   gtot1syst->Draw("2");
   TGraphErrors *gtot1 = new TGraphErrors(1,x1,y1,x0,y1e); //for fun

   gtot1->SetMarkerColor(color1Sraa);
   gtot1->SetMarkerStyle(symbol1S);
   gtot1->SetMarkerSize(markerSize);

   TGraphErrors *gtot1circle = new TGraphErrors(1,x1,y1,x0,y1e);
   gtot1circle->SetMarkerStyle(symbol1Sc);
   gtot1circle->SetMarkerSize(markerSize);
   gtot1circle->SetLineColor(kBlack);
   gtot1circle->SetLineWidth(2);
   gtot1->Draw("pe");
   gtot1circle->Draw("p");
   //  f4RaaTot->Draw("same");
   gPad->RedrawAxis();
   
   TGraphErrors *gtot2syst = new TGraphErrors(1,x,y2,xe,y2s); //for fun
   gtot2syst->SetLineColor(color2Sraa);
   gtot2syst->SetFillStyle(0);
   gtot2syst->SetLineWidth(2);
   gtot2syst->SetMarkerSize(0);
   gtot2syst->Draw("2");
   TGraphErrors *gtot2 = new TGraphErrors(1,x,y2,x0,y2e); //for fun

   gtot2->SetMarkerColor(color2Sraa);
   gtot2->SetMarkerStyle(symbol2S);
   gtot2->SetMarkerSize(markerSize);

   TGraphErrors *gtot2circle = new TGraphErrors(1,x,y2,x0,y2e);
   gtot2circle->SetMarkerStyle(symbol2Sc);
   gtot2circle->SetMarkerSize(markerSize);
   gtot2circle->SetLineColor(kBlack);
   gtot2circle->SetLineWidth(2);
   gtot2->Draw("pe");
   gtot2circle->Draw("p");
   //  f4RaaTot->Draw("same");
   gPad->RedrawAxis();

   TArrow *arrow = new TArrow(1.55,0.15,1.55,0.,0.03,"|->");
   arrow->SetLineColor(color3Spp);
   arrow->SetLineStyle(1);
   arrow->SetLineWidth(2);
   arrow->Draw();
   
   main->cd();
   legend_RAAcent->AddEntry(arrow,"#varUpsilon(3S) ","l");
   legend_RAAcent->Draw();

   //   main->Draw();
   CMS_lumi(main,104,33);
   cRaacent->cd();
   cRaacent->Update();
   cRaacent->RedrawAxis();
   // cRaacent->GetFrame()->Draw();
   if (plug==0){
     cRaacent->SaveAs(basedir2 + TString("/RAA_Cent_Strickland.pdf"));    
     cRaacent->SaveAs(basedir2 + TString("/RAA_Cent_Strickland.png"));    
     cRaacent->SaveAs(basedir1 + TString("/pdf/RAA_Cent_Strickland.pdf"));
     cRaacent->SaveAs(basedir1 + TString("/png/RAA_Cent_Strickland.png"));
   }else if (plug==1){
     legend_RAAcent->SetX1(0.34);
     legend_RAAcent->SetX2(0.54);
     legend_RAAcent->SetY1(0.68);
     legend_RAAcent->SetY2(0.81);
     legend_RAAcent->Draw();
      // CMS_lumi(cRaacent,104,33);
      // cRaacent->Update();
      // cRaacent->RedrawAxis();
      // cRaacent->GetFrame()->Draw();
      cRaacent->SaveAs(basedir2 + TString("/RAA_Cent_Rapp.pdf"));    
      cRaacent->SaveAs(basedir2 + TString("/RAA_Cent_Rapp.png"));    
      cRaacent->SaveAs(basedir1 + TString("/pdf/RAA_Cent_Rapp.pdf"));
      cRaacent->SaveAs(basedir1 + TString("/png/RAA_Cent_Rapp.png"));
   }else if (plug==2){
     cRaacent->SaveAs(basedir2 + TString("/RAA_Cent.pdf"));    
     cRaacent->SaveAs(basedir2 + TString("/RAA_Cent.png"));    
     cRaacent->SaveAs(basedir1 + TString("/pdf/RAA_Cent.pdf"));
     cRaacent->SaveAs(basedir1 + TString("/png/RAA_Cent.png"));
   }
}


float computeRatio(float x, float y) 
{
  // pass the yield (x), and Acc*eff (y), and computes the corrected yield. then divide by lumi and delta rapidity to get the cross section. in case of pbpb, divide by taa*nMB to get the nColl scaled invariant yield.
  float ratio;
  ratio = x/y;
    
  return ratio;
}
 
float computeRatioError(float x, float y, float xerr, float yerr) 
{
  //propagate the error of the ratio
  float err = (xerr*xerr)/(x*x) + (yerr*yerr)/(y*y);
  
  // + 2.*(x.getError()*y.getError())/(x.getVal()*y.getVal())*correlation; // can be needed in case of correlations.
   
  return fabs(computeRatio(x,y))*sqrt(err);
}

void plotComparisons(bool exp, int plug)
{
  // let's hope it works.
  // First bool : th or exp comparisons
  // second bool : switch between cases:
  ///      - if exp=1 plug=0: plot ALICE comparisons (rap and centrality)
  ///      - if exp=1 plug=1: STAR comparisons (centrality)
  ///      - if exp=1 plug=2: ALICE + jpsi comparison (pt, rap)
  ///      - if exp=0 plug=0: Strickland plots
  ///      - if exp=0 plug=1: Rapp plots
  ///      - if exp=0 plug=2: nothing happens.
  setTDRStyle();
  gStyle->SetPadRightMargin(0.04); //reverting style here (otherwise Npart=400 eats the margin)
  TCanvas *crcth = new TCanvas("crcth","Canvas Raa Centrality ");
  crcth->cd();
  TPad *main = new TPad("main","Main TPad",0.,0.,xfrac,1.);
  main->SetLeftMargin(gStyle->GetPadLeftMargin()/xfrac);
  main->SetRightMargin(0);
  main->SetFrameBorderMode(0);
  main->SetBorderMode(0);
  main->SetBorderSize(0);
  main->Draw();
  main->cd();
  TLine line, liner;
  TH1F *haxes = new TH1F("haxesl","haxesl",1,-10,420);
  haxes->GetXaxis()->SetTickLength(gStyle->GetTickLength("X")/xfrac);
  // haxes->GetYaxis()->SetTickLength(gStyle->GetTickLength("Y")*xfrac);
  line = TLine(0,1,420,1);
  haxes->GetYaxis()->SetRangeUser(0,1.6);
  TH1F *haxesr = new TH1F("haxesr","haxesr",1,0,2);
  haxesr->GetXaxis()->SetTickLength(0);
  haxesr->GetYaxis()->SetTickLength(gStyle->GetTickLength("Y")/(1.1-xfrac));
  haxesr->GetXaxis()->SetTitleSize(0);
  haxesr->GetXaxis()->SetLabelSize(0);
  haxesr->GetYaxis()->SetRangeUser(0,1.6);
  liner = TLine(0,1,2,1);
  haxes->GetYaxis()->SetTitle("R_{AA}");
  haxes->GetXaxis()->SetTitle("#LTN_{part}#GT");
  haxes->GetXaxis()->SetTitleSize(gTextSize+0.01);
  haxes->GetYaxis()->SetTitleSize(gTextSize+0.015);
  haxes->GetXaxis()->CenterTitle(kTRUE);
  haxes->GetXaxis()->SetTitleOffset(1.06);
  haxes->Draw();
  line.Draw();
}
