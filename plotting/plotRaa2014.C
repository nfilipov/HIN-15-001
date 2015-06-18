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

const bool plotCS =true;//fully corrected
const bool plotUncorrected = false;
const bool plotFiducial=false;//fiducial plots(not corrected for acc)
const bool plotEffOrAcc=false;//control plots (ratio of efficiencies etc)
const bool plotRAA=true;// centrality, transverse momentum, rapidity,
const bool plotPA=false;
const bool plotTNP=true;
const bool plot2010=false;
const bool plotSignificance=false;
const bool plotDD=false;
const bool plotTight=false;
const bool FourBins=true;
const string outSyst = "syst_outputfile.txt";
 
const  ofstream ofSyst;

const float gTextSize = 0.04;

float computeRatio(float x, float y) ;
float computeRatioError(float x, float y, float xerr, float yerr);
void plot2010();
void combine_blue(double val1, double err1, double val2, double err2);
void plotRAA_uncorr();
void plotDoubleRatios();
void plotRaa2014()
{
  // gROOT->Macro("../code/cm/logon.C+");//it all looks much nicer with this.
  //  gROOT->Macro("data_raa.h");

  // set the style
  setTDRStyle();

  double RapBinWidth = 4.8;
  double PtBinWidth = 20;
  float pt [nPtBins_2013] = {1.25, 3.75, 6.5, 10., 16.};
  float ptShift [nPtBins_2013] = {1.6, 4.1, 6.9, 10.4, 16.4};
  float pt2014 [nPtBins_2014] = {1.25, 3.75, 6.5, 10., 16.,30};
  //  float pt2014Shift [nPtBins_2014] = {1.45, 3.85, 6.6, 10.1, 16.1};
  float pt2014e[nPtBins_2014] = {1.25, 1.25, 1.5, 2., 4.,10.};
  //  float pt2014eShift[nPtBins_2014] = {1.25, 1.25, 1.5, 2., 4.,10.};
  float pte[nPtBins_2013] = {1.25, 1.25, 1.5, 2., 4.};
  //  float pteShift[nPtBins_2013] = {1.25, 1.25, 1.5, 2., 4.};
  float deltaPt[nPtBins_2013]   = {2.5,2.5,3,4,8};
  float pt_2010 [nPtBins_2010] = {2.6,8.6,20.1};
  float pte_2010[nPtBins_2010] = {2.5,3.5,4};
  float deltaPt_2010[nPtBins_2010]   = {5.,7.,8.};
  float deltaRap2010[nRapBins_2010] = {2.4,2.4};
  float deltaRapEven[nRapBins_2014] = {0.8,0.8,0.8,0.8,0.8,0.8};


  float R_A_1S_pt[nPtBins_2013]={};
  float R_A_1S_pte[nPtBins_2013]={};
  float R_A_1S_rap[nRapBins_2014]={};
  float R_A_1S_rape[nRapBins_2014]={}; 
  float R_e_1S_pt[nPtBins_2013]={};
  float R_e_1S_pte[nPtBins_2013]={};
  float R_e_1S_rap[nRapBins_2014]={};
  float R_e_1S_rape[nRapBins_2014]={};

  float CS1S_pp_rap[nRapBins_2013] = {}; // left this one to compare 2013 with 2014 (only difference: larger bin 1.5-2.4). /// not used for now.
  float CS1S_pp_rape[nRapBins_2013] = {};
  float CS1S_pp_pt[nPtBins_2013] = {};
  float CS1S_pp_pte[nPtBins_2013] = {};

  //large things
  float CS1S_pp_ptLarge[nPtBins_2010] = {};
  float CS1S_pp_pteLarge[nPtBins_2010] = {};
  float CS1S_aa_ptLarge[nPtBins_2010] = {};
  float CS1S_aa_pteLarge[nPtBins_2010] = {};
  //RAA pt 2010
  
  float RAA_1S_ptLarge[nPtBins_2010]={};
  float RAA_1S_pteLarge[nPtBins_2010]={};
  //large things
  float CS1S_pp_rapLarge[nRapBins_2010] = {};
  float CS1S_pp_rapeLarge[nRapBins_2010] = {};
  float CS1S_aa_rapLarge[nRapBins_2010] = {};
  float CS1S_aa_rapeLarge[nRapBins_2010] = {};
  //RAA rap 2010
  
  float RAA_1S_rapLarge[nRapBins_2010]={};
  float RAA_1S_rapeLarge[nRapBins_2010]={};
  //
  float CS1S_pp_tnp_pt[nPtBins_2013] = {};
  float CS1S_pp_tnp_pte[nPtBins_2013] = {};
  float CS1S_pp_tnp_pts[nPtBins_2013] = {};
  float CS1S_pp_tnp_pt4[nPtBins_2013] = {};  //pt4
  float CS1S_pp_tnp_pt4e[nPtBins_2013] = {};
  float CS1S_pp_tnp_pt4s[nPtBins_2013] = {};
  float CS1S_pp_rap2014[nRapBins_2014] = {};
  float CS1S_pp_rap2014e[nRapBins_2014] = {};
  float CS1S_pp_rap2014s[nRapBins_2014] = {};
  float CS1S_pp_tnp_rap2014[nRapBins_2014] = {};
  float CS1S_pp_tnp_rap2014e[nRapBins_2014] = {};
  float CS1S_pp_tnp_rap2014s[nRapBins_2014] = {};
  float CS1S_pp_tnp_rap42014[nRapBins_2014] = {};//pt4
  float CS1S_pp_tnp_rap42014e[nRapBins_2014] = {};
  float CS1S_pp_tnp_rap42014s[nRapBins_2014] = {};
  float CS1S_aa_pt[nPtBins_2013] = {};
  float CS1S_aa_pte[nPtBins_2013] = {}; //not sure i'll use it for the moment
  float CS1S_aa_rap[nRapBins_2013] = {};
  float CS1S_aa_rape[nRapBins_2013] = {};
  float CS1S_aa_rap2014[nRapBins_2014] = {};
  float CS1S_aa_rap2014e[nRapBins_2014] = {};
  float CS1S_aa_tnp_pt[nPtBins_2013] = {};
  float CS1S_aa_tnp_pts[nPtBins_2013] = {};
  float CS1S_aa_tnp_pte[nPtBins_2013] = {};
  float CS1S_aa_tnp_pt4[nPtBins_2013] = {}; //pt4
  float CS1S_aa_tnp_pt4s[nPtBins_2013] = {};
  float CS1S_aa_tnp_pt4e[nPtBins_2013] = {};
  float CS1S_aa_tnp_rap[nRapBins_2013] = {};
  float CS1S_aa_tnp_rape[nRapBins_2013] = {};
  float CS1S_aa_tnp_rap2014[nRapBins_2014] = {};
  float CS1S_aa_tnp_rap2014e[nRapBins_2014] = {};
  float CS1S_aa_tnp_rap2014s[nRapBins_2014] = {};
  float CS1S_aa_tnp_rap42014[nRapBins_2014] = {};//pt4
  float CS1S_aa_tnp_rap42014e[nRapBins_2014] = {};
  float CS1S_aa_tnp_rap42014s[nRapBins_2014] = {};

  float CS1S_pp_ptFiducial[nPtBins_2013]={}; //
  float CS1S_aa_ptFiducial[nPtBins_2013]={}; //
  float CS1S_pp_rap2014Fiducial[nRapBins_2014]={}; //
  float CS1S_aa_rapFiducial[nRapBins_2013]={};//

  float CS2S_pp_pt2013Fiducial[nPtBins_2013]={};//
  // float CS2S_pp_ptFiducial[nPtBins_2010]={};
  // float CS2S_aa_ptFiducial[nPtBins_2010]={};
  // float CS2S_aa_rapFiducial[nRapBins_2010]={};
  // float CS2S_pp_rapFiducial[nRapBins_2010]={};
  float CS2S_pp_rap2014Fiducial[nRapBins_2014]={};

  float CS1S_pp_ptFiduciale[nPtBins_2013]={};
  float CS1S_aa_ptFiduciale[nPtBins_2013]={};
  float CS1S_pp_rap2014Fiduciale[nRapBins_2014]={};
  float CS1S_aa_rapFiduciale[nRapBins_2014]={};

  float CS2S_pp_pt2013Fiduciale[nPtBins_2013]={};
  // float CS2S_pp_ptFiduciale[nPtBins_2010]={};
  // float CS2S_aa_ptFiduciale[nPtBins_2010]={};
  // float CS2S_aa_rapFiduciale[nRapBins_2010]={};
  // float CS2S_pp_rapFiduciale[nRapBins_2010]={};
  float CS2S_pp_rap2014Fiduciale[nRapBins_2014]={};

  float CS2S_pp_pt[nPtBins_2010] = {};
  float CS2S_pp_pt2013[nPtBins_2013] ={};
  float CS2S_pp_pte[nPtBins_2010] = {};
  float CS2S_pp_pts[nPtBins_2010] = {};
  float CS2S_pp_pt2013e[nPtBins_2013] ={};
  float CS2S_pp_tnp_pt[nPtBins_2010] = {};
  float CS2S_pp_tnp_pt2013[nPtBins_2013] ={};
  float CS2S_pp_tnp_pts[nPtBins_2013] ={};
  float CS2S_pp_tnp_pte[nPtBins_2010] = {};
  float CS2S_pp_tnp_pt2013e[nPtBins_2013] ={};
  float CS2S_pp_tnp_pts[nPtBins_2013] ={};
  float CS2S_pp_rap[nRapBins_2010] = {};
  float CS2S_pp_rap2014[nRapBins_2014] = {};
  float CS2S_pp_rape[nRapBins_2010] = {};
  float CS2S_pp_rap2014e[nRapBins_2014] = {};
  float CS2S_pp_tnp_rap[nRapBins_2010] = {};
  float CS2S_pp_tnp_rape[nRapBins_2010] = {};
  float CS2S_pp_tnp_raps[nRapBins_2010] = {};
  float CS2S_pp_tnp_rap2014[nRapBins_2014] = {};
  float CS2S_pp_tnp_rap2014e[nRapBins_2014] = {}; 
  float CS2S_pp_tnp_rap2014s[nRapBins_2014]={};
  float CS2S_aa_pt[nPtBins_2010] = {};
  float CS2S_aa_pte[nPtBins_2010] = {};
  float CS2S_aa_pts[nPtBins_2010] = {};
  float CS2S_aa_rap[nRapBins_2010] = {};
  float CS2S_aa_tnp_pt[nPtBins_2010] = {};
  float CS2S_aa_tnp_pte[nPtBins_2010] = {};
  float CS2S_aa_tnp_rap[nRapBins_2010] = {};
  float CS2S_aa_tnp_rape[nRapBins_2010] = {};
  float CS2S_aa_tnp_rape[nRapBins_2010] = {};
  float CS2S_aa_tnp_raps[nRapBins_2010] = {};

  
  float CS3S_pp_pt2013[nPtBins_2013] ={};
  float CS3S_pp_pt2013e[nPtBins_2013] ={};
  float CS3S_pp_rap2014[nRapBins_2014] = {};
  float CS3S_pp_rap2014e[nRapBins_2014] = {};
  float CS3S_pp_tnp_pt2013[nPtBins_2013] ={};
  float CS3S_pp_tnp_pt2013e[nPtBins_2013] ={};
  float CS3S_pp_tnp_pts[nPtBins_2013] ={};
  float CS3S_pp_tnp_rap2014[nRapBins_2014] = {};
  float CS3S_pp_tnp_rap2014e[nRapBins_2014] = {};
  float CS3S_pp_tnp_rap2014s[nRapBins_2014]={};

  float RAA_1S_pt[nPtBins_2013]={};
  float RAA_1S_rap[nRapBins_2014]={};
  float RAA_1S_pte[nPtBins_2013]={};
  float RAA_1S_rape[nRapBins_2014]={};

  float RAA_2S_pt[nPtBins_2010]={};
  float RAA_2S_rap[nRapBins_2010]={};
  float RAA_2S_pte[nPtBins_2010]={};
  float RAA_2S_rape[nRapBins_2010]={};
  //tnp correction
  float RAA_1S_tnp_pt[nPtBins_2013]={};
  float RAA_1S_tnp_rap[nRapBins_2014]={};
  float RAA_1S_tnp_pte[nPtBins_2013]={};
  float RAA_1S_tnp_pts[nPtBins_2013]={};//point-to-point for plots.
  float RAA_1S_tnp_ptsT[nPtBins_2013]={};// second one is global+loc.
  float RAA_1S_tnp_rape[nRapBins_2014]={};
  float RAA_1S_tnp_raps[nRapBins_2014]={};
  float RAA_1S_tnp_rapsT[nRapBins_2014]={};// second one is global+loc.

  float RAA_1S_tnp_pt4[nPtBins_2013]={};
  float RAA_1S_tnp_rap4[nRapBins_2014]={};
  float RAA_1S_tnp_pt4e[nPtBins_2013]={};
  float RAA_1S_tnp_pt4s[nPtBins_2013]={};//point-to-point for plots.
  float RAA_1S_tnp_pt4sT[nPtBins_2013]={};// second one is global+loc.
  float RAA_1S_tnp_rap4e[nRapBins_2014]={};
  float RAA_1S_tnp_rap4s[nRapBins_2014]={};
  float RAA_1S_tnp_rap4sT[nRapBins_2014]={};// second one is global+loc.

  float RAA_2S_tnp_pt[nPtBins_2010]={};
  float RAA_2S_tnp_rap[nRapBins_2010]={};
  float RAA_2S_tnp_pte[nPtBins_2010]={};
  float RAA_2S_tnp_pts[nPtBins_2010]={};
  float RAA_2S_tnp_ptsT[nPtBins_2010]={};
  float RAA_2S_tnp_rape[nRapBins_2010]={};
  float RAA_2S_tnp_raps[nRapBins_2010]={};
  float RAA_2S_tnp_rapsT[nRapBins_2010]={};
  //Significance, for all non-believers out there
  float SigOverErr_ppPt1S3p5[nPtBins_2013]={}; 
  float SigOverErr_ppPt1S4[nPtBins_2013]={};
  float SigOverErr_ppRap1S3p5[nRapBins_2014]={};
  float SigOverErr_ppRap1S4[nRapBins_2014]={};
  float SigOverErr_aaPt1S3p5[nPtBins_2013]={};
  float SigOverErr_aaPt1S4[nPtBins_2013]={};
  float SigOverErr_aaRap1S3p5[nRapBins_2014]={};
  float SigOverErr_aaRap1S4[nRapBins_2014]={};
  float SigOverErr_ppPt2S3p5[nPtBins_2013]={};
  float SigOverErr_ppRap2S3p5[nRapBins_2014]={};
  float SigOverErr_ppPt2S4[nPtBins_2013]={};
  float SigOverErr_ppRap2S4[nRapBins_2014]={};
  float SigOverErr_ppPt3S3p5[nPtBins_2013]={};
  float SigOverErr_ppRap3S3p5[nRapBins_2014]={};
  float SigOverErr_ppPt3S4[nPtBins_2013]={};
  float SigOverErr_ppRap3S4[nRapBins_2014]={};
  float SigOverErr_aaPt2S3p5[nPtBins_2010]={};
  float SigOverErr_aaRap2S3p5[nRapBins_2010]={};
  float SigOverErr_aaPt2S4[nPtBins_2010]={};
  float SigOverErr_aaRap2S4[nRapBins_2010]={};
  float twoBins[nRapBins_2010]={0.5,1.5};
  float threeBins[nPtBins_2010]={0.5,1.5,2.5};
  float fiveBins[nPtBins_2013]={0.5,1.5,2.5,3.5,4.5};
  float sixBins[nRapBins_2014]={0.5,1.5,2.5,3.5,4.5,5.5};
  //systematics (fit variations, bkgd variations, tnp, plus global stuff sometimes hardcoded)
  float syst1S_raa_global=sqrt((0.057*0.057)+(0.2/5.4)*(0.2/5.4)+pow(N1S_pp_tot3p5s,2)+pow(N1S_pp_tot3p5e/N1S_pp_tot3p5,2)+pow(t_1S_pythia_tot3p5e/t_1S_pythia_tot3p5,2));
  float syst1S_raa_global4=sqrt((0.057*0.057)+(0.2/5.4)*(0.2/5.4)+pow(N1S_pp_tot4s,2)+pow(N1S_pp_tot4e/N1S_pp_tot4,2)+pow(t_1S_pythia_tot4e/t_1S_pythia_tot4,2));
  float syst2S_raa_global=sqrt((0.2/5.4)*(0.2/5.4)+pow(N2S_pp_tot4s,2)+pow(N2S_pp_tot4e/N2S_pp_tot4,2));
  float syst2S_pp_glob=sqrt((0.057*0.057)+(0.2/5.4)*(0.2/5.4));
  /// L_pp + pp_fit(stat) +pp_fit(syst) + tnp_pp1S  
  // taa uncertainty + unfolding uncertainties + Lumi uncertainty. commenting out unfolding for now. +(0.045*0.045)+(0.02*0.02)
  float syst1S_pp_glob=sqrt((0.2/5.4)*(0.2/5.4));
  // taa?? + unfolding pp + lumi. commenting out unfolding and t_aa for now. (0.057*0.057)+(0.02*0.02)

  float syst1S_pp_pt[nPtBins_2013]={};//fit syst. uncertainty.
  float syst2S_pp_pt[nPtBins_2013]={};
  float syst2S_pp_ptLoose[nPtBins_2013]={};
  float syst3S_pp_pt[nPtBins_2013]={};
  float syst3S_pp_ptLoose[nPtBins_2013]={};
  float syst1S_aa_pt[nPtBins_2013]={};
  float syst1S_pp_pt4[nPtBins_2013]={};
  float syst1S_aa_pt4[nPtBins_2013]={};

  float syst1S_pp_rap[nRapBins_2014]={};
  float syst1S_pp_rap4[nRapBins_2014]={};
  float syst2S_pp_rap[nRapBins_2014]={};
  float syst3S_pp_rap[nRapBins_2014]={};
  float syst2S_pp_rapLoose[nRapBins_2014]={};
  float syst3S_pp_rapLoose[nRapBins_2014]={};
  float syst1S_aa_rap[nRapBins_2014]={};
  float syst1S_aa_rap4[nRapBins_2014]={};
  float syst2S_aa_pt[nPtBins_2010]={};
  float syst2S_aa_rap[nRapBins_2010]={};
  float syst2S_pp_ptLarge[nPtBins_2010]={};
  float syst2S_pp_rapLarge[nRapBins_2010]={};
  float syst2S_aa_ptLoose[nPtBins_2010]={};
  float syst2S_aa_rapLoose[nRapBins_2010]={};
  float syst2S_pp_ptLargeLoose[nPtBins_2010]={};
  float syst2S_pp_rapLargeLoose[nRapBins_2010]={};
  
  float syst1S_aa_Cent[nCentBins_2014]={};
  float syst1S_aa_Cent4[nCentBins_2014]={};
  float syst2S_aa_Cent[nCentBins2S]={};
  float syst2S_aa_CentLoose[nCentBins2S]={};
  //1S pp sources of uncertainty.
  float stat1S_pp_pt[nPtBins_2013]={}; //stat. pp relative uncertainty (contributing to R_AA as a pt to pt syst. uncertainty!
  float stat1S_pp_rap[nRapBins_2014]={};
  float syst1S_pptnp_pt[nPtBins_2013]={}; // tnp pp babies!
  float syst1S_pptnp_rap[nRapBins_2014]={};
  float syst1S_aatnp_pt[nPtBins_2013]={}; // tnp aa babies!
  float syst1S_aatnp_rap[nRapBins_2014]={}; // tnp aa babies!
  //1S pp TIGHT sources of uncertainty.
  float stat1S_pp_pt4[nPtBins_2013]={}; //stat. pp relative uncertainty (contributing to R_AA as a pt to pt syst. uncertainty!
  float stat1S_pp_rap4[nRapBins_2014]={};
  float syst1S_pptnp_pt4[nPtBins_2013]={}; // tnp pp babies!
  float syst1S_pptnp_rap4[nRapBins_2014]={};
  float syst1S_aatnp_pt4[nPtBins_2013]={}; // tnp aa babies!
  float syst1S_aatnp_rap4[nRapBins_2014]={}; // tnp aa babies!
  //2S pp sources of uncertainty.
  float stat2S_pp_pt[nPtBins_2013]={}; 
  float syst2S_pptnp_pt[nPtBins_2013]={};
  float stat2S_pp_ptLoose[nPtBins_2013]={}; 
  float syst2S_pptnp_ptLoose[nPtBins_2013]={};
  float stat2S_pp_rap[nRapBins_2014]={}; 
  float syst2S_pptnp_rap[nRapBins_2014]={};
  float stat2S_pp_rapLoose[nRapBins_2014]={}; 
  float syst2S_pptnp_rapLoose[nRapBins_2014]={};
  //3S pp sources of uncertainty.
  float stat3S_pp_pt[nPtBins_2013]={}; 
  float syst3S_pptnp_pt[nPtBins_2013]={};
  float stat3S_pp_ptLoose[nPtBins_2013]={}; 
  float syst3S_pptnp_ptLoose[nPtBins_2013]={};
  float stat3S_pp_rap[nRapBins_2014]={}; 
  float syst3S_pptnp_rap[nRapBins_2014]={};
  float stat3S_pp_rapLoose[nRapBins_2014]={}; 
  float syst3S_pptnp_rapLoose[nRapBins_2014]={};
  //2S large pT RAA
  float stat2S_pp_ptLarge[nPtBins_2010]={}; 
  float syst2S_aatnp_pt[nPtBins_2010]={};
  float syst2S_pptnp_ptLarge[nPtBins_2010]={};
  float syst2S_raa_pointPt[nPtBins_2010]={};
  float syst2S_raa_pt[nPtBins_2010]={};
  float syst2S_cspp_ptLarge[nPtBins_2010]={};
  float syst2S_csaa_pt[nPtBins_2010]={};
  //2S loose pt RAA
  float stat2S_pp_ptLargeLoose[nPtBins_2010]={}; 
  float syst2S_aatnp_ptLoose[nPtBins_2010]={};
  float syst2S_pptnp_ptLargeLoose[nPtBins_2010]={};
  float syst2S_raa_pointPtLoose[nPtBins_2010]={};
  float syst2S_raa_ptLoose[nPtBins_2010]={};
  float syst2S_cspp_ptLargeLoose[nPtBins_2010]={};
  float syst2S_csaa_ptLoose[nPtBins_2010]={};
 
 

  //2S large rap RAA 
  float stat2S_pp_rapLarge[nRapBins_2010]={};
  float syst2S_aatnp_rap[nRapBins_2010]={};
  float syst2S_pptnp_rapLarge[nRapBins_2010]={};
  float syst2S_raa_pointRap[nRapBins_2010]={};
  float syst2S_raa_rap[nRapBins_2010]={};
  float syst2S_cspp_rapLarge[nRapBins_2010]={};
  float syst2S_csaa_rap[nRapBins_2010]={};
  //2S large rap LOOSE RAA
  float stat2S_pp_rapLargeLoose[nRapBins_2010]={};
  float syst2S_aatnp_rapLoose[nRapBins_2010]={};
  float syst2S_pptnp_rapLargeLoose[nRapBins_2010]={};
  float syst2S_raa_pointRapLoose[nRapBins_2010]={};
  float syst2S_raa_rapLoose[nRapBins_2010]={};
  float syst2S_cspp_rapLargeLoose[nRapBins_2010]={};
  float syst2S_csaa_rapLoose[nRapBins_2010]={};


  float syst1S_raa_pointPt[nPtBins_2013]={};//point-to-point syst. for raa: stat pp, syst pp, tnp_pp, tnp_pbpb.
  float syst1S_raa_pointPt4[nPtBins_2013]={};//point-to-point syst. for raa: stat pp, syst pp, tnp_pp, tnp_pbpb.
  float syst1S_raa_pointRap[nRapBins_2014]={};
  float syst1S_raa_pointRap4[nRapBins_2014]={};
  float syst1S_raa_pt[nPtBins_2013]={};//total for tables = quad. sum of point and global.
  float syst1S_raa_pt4[nPtBins_2013]={};//total for tables = quad. sum of point and global.
  float syst1S_raa_rap[nRapBins_2014]={};
  float syst1S_raa_rap4[nRapBins_2014]={};
  float syst1S_cspp_pt[nPtBins_2013]={};
  float syst1S_cspp_pt4[nPtBins_2013]={};
  float syst2S_cspp_pt[nPtBins_2013]={};
  float syst3S_cspp_pt[nPtBins_2013]={};
  float syst1S_csaa_pt4[nPtBins_2013]={};
  float syst1S_csaa_pt[nPtBins_2013]={};
  float syst1S_cspp_rap[nRapBins_2014]={};
  float syst1S_cspp_rap4[nRapBins_2014]={};
  float syst2S_cspp_rap[nRapBins_2014]={};
  float syst3S_cspp_rap[nRapBins_2014]={};
  float syst1S_csaa_rap[nRapBins_2014]={};
  float syst1S_csaa_rap4[nRapBins_2014]={};
  ofSyst.open(outSyst.c_str(), ios_base::out);  //open the out stream for syst results.
  float recap_syst[10][nfitvars]; // array of relative deviations. the second dimensional array is for each variable 
  // 1S pt, 1S rap, 1S cent, 2S pt, 2S rap, 2S cent, 3S pt, 3S rap, 3S cent.
  // for(int j=0; j<10;j++)
  //   {
  //     recap_syst[j]=
  //   }

 syst1S_aa_pt[5]= sqrt (pow(RMS(N1S_aa_pt3p5[5],N1S_aa_pt3p5s_40,nfitvars),2) + pow(maxDeviation(N1S_aa_pt3p5[5],N1B_aa_pt3p5s_40,nbkgdvars),2));
 syst1S_aa_pt[4]= sqrt (pow(RMS(N1S_aa_pt3p5[4],N1S_aa_pt3p5s_20,nfitvars),2) + pow(maxDeviation(N1S_aa_pt3p5[4],N1B_aa_pt3p5s_20,nbkgdvars),2));
 syst1S_aa_pt[3]= sqrt (pow(RMS(N1S_aa_pt3p5[3],N1S_aa_pt3p5s_12,nfitvars),2) + pow(maxDeviation(N1S_aa_pt3p5[3],N1B_aa_pt3p5s_12,nbkgdvars),2));
 syst1S_aa_pt[2]= sqrt (pow(RMS(N1S_aa_pt3p5[2],N1S_aa_pt3p5s_8,nfitvars),2) + pow(maxDeviation(N1S_aa_pt3p5[2],N1B_aa_pt3p5s_8,nbkgdvars),2));
 syst1S_aa_pt[1]= sqrt (pow(RMS(N1S_aa_pt3p5[1],N1S_aa_pt3p5s_5,nfitvars),2) + pow(maxDeviation(N1S_aa_pt3p5[1],N1B_aa_pt3p5s_5,nbkgdvars),2));
 syst1S_aa_pt[0]= sqrt (pow(RMS(N1S_aa_pt3p5[0],N1S_aa_pt3p5s_2p5,nfitvars),2) + pow(maxDeviation(N1S_aa_pt3p5[0],N1B_aa_pt3p5s_2p5,nbkgdvars),2));

 syst1S_pp_pt[5]= sqrt (pow(RMS(N1S_pp_pt3p5[5],N1S_pp_pt3p5s_40,nfitvars),2) + pow(maxDeviation(N1S_pp_pt3p5[5],N1B_pp_pt3p5s_40,nbkgdvars),2));
 syst1S_pp_pt[4]= sqrt (pow(RMS(N1S_pp_pt3p5[4],N1S_pp_pt3p5s_20,nfitvars),2) + pow(maxDeviation(N1S_pp_pt3p5[4],N1B_pp_pt3p5s_20,nbkgdvars),2));
 syst1S_pp_pt[3]= sqrt (pow(RMS(N1S_pp_pt3p5[3],N1S_pp_pt3p5s_12,nfitvars),2) + pow(maxDeviation(N1S_pp_pt3p5[3],N1B_pp_pt3p5s_12,nbkgdvars),2));
 syst1S_pp_pt[2]= sqrt (pow(RMS(N1S_pp_pt3p5[2],N1S_pp_pt3p5s_8,nfitvars),2) + pow(maxDeviation(N1S_pp_pt3p5[2],N1B_pp_pt3p5s_8,nbkgdvars),2));
 syst1S_pp_pt[1]= sqrt (pow(RMS(N1S_pp_pt3p5[1],N1S_pp_pt3p5s_5,nfitvars),2) + pow(maxDeviation(N1S_pp_pt3p5[1],N1B_pp_pt3p5s_5,nbkgdvars),2));
 syst1S_pp_pt[0]= sqrt (pow(RMS(N1S_pp_pt3p5[0],N1S_pp_pt3p5s_2p5,nfitvars),2) + pow(maxDeviation(N1S_pp_pt3p5[0],N1B_pp_pt3p5s_2p5,nbkgdvars),2));

 syst1S_aa_pt4[5]= sqrt (pow(RMS(N1S_aa_pt4[5],N1S_aa_pt4s_40,nfitvars),2) + pow(maxDeviation(N1S_aa_pt4[5],N1B_aa_pt4s_40,nbkgdvars),2));
 syst1S_aa_pt4[4]= sqrt (pow(RMS(N1S_aa_pt4[4],N1S_aa_pt4s_20,nfitvars),2) + pow(maxDeviation(N1S_aa_pt4[4],N1B_aa_pt4s_20,nbkgdvars),2));
 syst1S_aa_pt4[3]= sqrt (pow(RMS(N1S_aa_pt4[3],N1S_aa_pt4s_12,nfitvars),2) + pow(maxDeviation(N1S_aa_pt4[3],N1B_aa_pt4s_12,nbkgdvars),2));
 syst1S_aa_pt4[2]= sqrt (pow(RMS(N1S_aa_pt4[2],N1S_aa_pt4s_8,nfitvars),2) + pow(maxDeviation(N1S_aa_pt4[2],N1B_aa_pt4s_8,nbkgdvars),2));
 syst1S_aa_pt4[1]= sqrt (pow(RMS(N1S_aa_pt4[1],N1S_aa_pt4s_5,nfitvars),2) + pow(maxDeviation(N1S_aa_pt4[1],N1B_aa_pt4s_5,nbkgdvars),2));
 syst1S_aa_pt4[0]= sqrt (pow(RMS(N1S_aa_pt4[0],N1S_aa_pt4s_2p5,nfitvars),2) + pow(maxDeviation(N1S_aa_pt4[0],N1B_aa_pt4s_2p5,nbkgdvars),2));

 syst1S_pp_pt4[5]= sqrt (pow(RMS(N1S_pp_pt4[5],N1S_pp_pt4s_40,nfitvars),2) + pow(maxDeviation(N1S_pp_pt4[5],N1B_pp_pt4s_40,nbkgdvars),2));
 syst1S_pp_pt4[4]= sqrt (pow(RMS(N1S_pp_pt4[4],N1S_pp_pt4s_20,nfitvars),2) + pow(maxDeviation(N1S_pp_pt4[4],N1B_pp_pt4s_20,nbkgdvars),2));
 syst1S_pp_pt4[3]= sqrt (pow(RMS(N1S_pp_pt4[3],N1S_pp_pt4s_12,nfitvars),2) + pow(maxDeviation(N1S_pp_pt4[3],N1B_pp_pt4s_12,nbkgdvars),2));
 syst1S_pp_pt4[2]= sqrt (pow(RMS(N1S_pp_pt4[2],N1S_pp_pt4s_8,nfitvars),2) + pow(maxDeviation(N1S_pp_pt4[2],N1B_pp_pt4s_8,nbkgdvars),2));
 syst1S_pp_pt4[1]= sqrt (pow(RMS(N1S_pp_pt4[1],N1S_pp_pt4s_5,nfitvars),2) + pow(maxDeviation(N1S_pp_pt4[1],N1B_pp_pt4s_5,nbkgdvars),2));
 syst1S_pp_pt4[0]= sqrt (pow(RMS(N1S_pp_pt4[0],N1S_pp_pt4s_2p5,nfitvars),2) + pow(maxDeviation(N1S_pp_pt4[0],N1B_pp_pt4s_2p5,nbkgdvars),2));

 syst2S_pp_pt[5]= sqrt (pow(RMS(N2S_pp_pt4_2013[5],N2S_pp_pt4s_40,nfitvars),2) + pow(maxDeviation(N2S_pp_pt4_2013[5],N2B_pp_pt4s_40,nbkgdvars),2));
 syst2S_pp_pt[4]= sqrt (pow(RMS(N2S_pp_pt4_2013[4],N2S_pp_pt4s_20,nfitvars),2) + pow(maxDeviation(N2S_pp_pt4_2013[4],N2B_pp_pt4s_20,nbkgdvars),2));
 syst2S_pp_pt[3]= sqrt (pow(RMS(N2S_pp_pt4_2013[3],N2S_pp_pt4s_12,nfitvars),2) + pow(maxDeviation(N2S_pp_pt4_2013[3],N2B_pp_pt4s_12,nbkgdvars),2));
 syst2S_pp_pt[2]= sqrt (pow(RMS(N2S_pp_pt4_2013[2],N2S_pp_pt4s_8,nfitvars),2) + pow(maxDeviation(N2S_pp_pt4_2013[2],N2B_pp_pt4s_8,nbkgdvars),2));
 syst2S_pp_pt[1]= sqrt (pow(RMS(N2S_pp_pt4_2013[1],N2S_pp_pt4s_5,nfitvars),2) + pow(maxDeviation(N2S_pp_pt4_2013[1],N2B_pp_pt4s_5,nbkgdvars),2));
 syst2S_pp_pt[0]= sqrt (pow(RMS(N2S_pp_pt4_2013[0],N2S_pp_pt4s_2p5,nfitvars),2) + pow(maxDeviation(N2S_pp_pt4_2013[0],N2B_pp_pt4s_2p5,nbkgdvars),2));

 syst3S_pp_pt[5]= sqrt (pow(RMS(N3S_pp_pt4_2013[5],N3S_pp_pt4s_40,nfitvars),2) + pow(maxDeviation(N3S_pp_pt4_2013[5],N3B_pp_pt4s_40,nbkgdvars),2));
 syst3S_pp_pt[4]= sqrt (pow(RMS(N3S_pp_pt4_2013[4],N3S_pp_pt4s_20,nfitvars),2) + pow(maxDeviation(N3S_pp_pt4_2013[4],N3B_pp_pt4s_20,nbkgdvars),2));
 syst3S_pp_pt[3]= sqrt (pow(RMS(N3S_pp_pt4_2013[3],N3S_pp_pt4s_12,nfitvars),2) + pow(maxDeviation(N3S_pp_pt4_2013[3],N3B_pp_pt4s_12,nbkgdvars),2));
 syst3S_pp_pt[2]= sqrt (pow(RMS(N3S_pp_pt4_2013[2],N3S_pp_pt4s_8,nfitvars),2) + pow(maxDeviation(N3S_pp_pt4_2013[2],N3B_pp_pt4s_8,nbkgdvars),2));
 syst3S_pp_pt[1]= sqrt (pow(RMS(N3S_pp_pt4_2013[1],N3S_pp_pt4s_5,nfitvars),2) + pow(maxDeviation(N3S_pp_pt4_2013[1],N3B_pp_pt4s_5,nbkgdvars),2));
 syst3S_pp_pt[0]= sqrt (pow(RMS(N3S_pp_pt4_2013[0],N3S_pp_pt4s_2p5,nfitvars),2) + pow(maxDeviation(N3S_pp_pt4_2013[0],N3B_pp_pt4s_2p5,nbkgdvars),2));

 // large bins of pT for 2S
 syst2S_aa_pt[2]= sqrt (pow(RMS(N2S_aa_pt4_2013Large[2],N2S_aa_pt4Larges_20,nfitvars),2)+ pow(maxDeviation(N2S_aa_pt4_2013Large[2],N2B_aa_pt4Larges_20,nbkgdvars),2)) ;
 syst2S_aa_pt[1]= sqrt (pow(RMS(N2S_aa_pt4_2013Large[1],N2S_aa_pt4Larges_12,nfitvars),2)+ pow(maxDeviation(N2S_aa_pt4_2013Large[1],N2B_aa_pt4Larges_12,nbkgdvars),2)) ;
 syst2S_aa_pt[0]= sqrt (pow(RMS(N2S_aa_pt4_2013Large[0],N2S_aa_pt4Larges_5,nfitvars),2) + pow(maxDeviation(N2S_aa_pt4_2013Large[0],N2B_aa_pt4Larges_5,nbkgdvars),2)) ;

 syst2S_pp_ptLarge[0]= sqrt (pow(RMS(N2S_pp_pt4_2013Large[0],N2S_pp_pt4Larges_5,nfitvars),2) + pow(maxDeviation(N2S_pp_pt4_2013Large[0],N2B_pp_pt4Larges_5,nbkgdvars),2)) ;
 syst2S_pp_ptLarge[1]= sqrt (pow(RMS(N2S_pp_pt4_2013Large[1],N2S_pp_pt4Larges_12,nfitvars),2) + pow(maxDeviation(N2S_pp_pt4_2013Large[1],N2B_pp_pt4Larges_12,nbkgdvars),2)) ;
 syst2S_pp_ptLarge[2]= sqrt (pow(RMS(N2S_pp_pt4_2013Large[2],N2S_pp_pt4Larges_20,nfitvars),2) + pow(maxDeviation(N2S_pp_pt4_2013Large[2],N2B_pp_pt4Larges_20,nbkgdvars),2)) ;

 cout << "--------------------1S-pt--------------------" << endl;
for(int i=0; i<nPtBins_2013; i++){  
  syst1S_pptnp_pt[i]=t_1S_pythia_pt3p5e[i]/t_1S_pythia_pt3p5[i]; //add syst. unc. from tnp
  syst1S_pptnp_pt4[i]=t_1S_pythia_pt4e[i]/t_1S_pythia_pt4[i]; //add syst. unc. from tnp
  syst2S_pptnp_pt[i]=t_2S_pythia_pt4e[i]/t_2S_pythia_pt4[i];
  syst3S_pptnp_pt[i]=t_3S_pythia_pt4e[i]/t_3S_pythia_pt4[i];
  syst1S_aatnp_pt[i]=t_1S_pyquen_pt3p5e[i]/t_1S_pyquen_pt3p5[i];
  syst1S_aatnp_pt4[i]=t_1S_pyquen_pt4e[i]/t_1S_pyquen_pt4[i];
    
  stat1S_pp_pt[i]=N1S_pp_pt3p5e[i]/N1S_pp_pt3p5[i];
  stat1S_pp_pt4[i]=N1S_pp_pt4e[i]/N1S_pp_pt4[i];
  stat2S_pp_pt[i]=N2S_pp_pt4_2013e[i]/N2S_pp_pt4_2013[i];
  stat3S_pp_pt[i]=N3S_pp_pt4_2013e[i]/N3S_pp_pt4_2013[i];
  syst1S_raa_pointPt[i]=sqrt(syst1S_pp_pt[i]*syst1S_pp_pt[i]+syst1S_aa_pt[i]*syst1S_aa_pt[i]+syst1S_pptnp_pt[i]*syst1S_pptnp_pt[i]+syst1S_aatnp_pt[i]*syst1S_aatnp_pt[i]+pow(Aet_1S_pyquen_pts[i]/Aet_1S_pyquen_pt[i],2)+pow(Aet_1S_pythia_pts[i]/Aet_1S_pythia_pt[i],2));//this one is big : stat.pp + syst.pp + syst.pbpb + tnp_pp + tnp_pbpb
  syst1S_raa_pointPt4[i]=sqrt(syst1S_pp_pt4[i]*syst1S_pp_pt4[i]+syst1S_aa_pt4[i]*syst1S_aa_pt4[i]+syst1S_pptnp_pt4[i]*syst1S_pptnp_pt4[i]+syst1S_aatnp_pt4[i]*syst1S_aatnp_pt4[i]+pow(Aet_1S_pyquen_pt4s[i]/Aet_1S_pyquen_pt4[i],2)+pow(Aet_1S_pythia_pt4s[i]/Aet_1S_pythia_pt4[i],2));//this one is big : stat.pp + syst.pp + syst.pbpb + tnp_pp + tnp_pbpb
  syst1S_raa_pt[i]=sqrt(syst1S_raa_pointPt[i]*syst1S_raa_pointPt[i]+syst1S_raa_global*syst1S_raa_global);
  syst1S_raa_pt4[i]=sqrt(syst1S_raa_pointPt4[i]*syst1S_raa_pointPt4[i]+syst1S_raa_global4*syst1S_raa_global4);
  syst1S_cspp_pt[i]=sqrt(syst1S_pptnp_pt[i]*syst1S_pptnp_pt[i]+syst1S_pp_pt[i]*syst1S_pp_pt[i]+(0.2/5.4)*(0.2/5.4));
  syst1S_cspp_pt4[i]=sqrt(syst1S_pptnp_pt4[i]*syst1S_pptnp_pt4[i]+syst1S_pp_pt4[i]*syst1S_pp_pt4[i]+(0.2/5.4)*(0.2/5.4));
  syst2S_cspp_pt[i]=sqrt(syst2S_pptnp_pt[i]*syst2S_pptnp_pt[i]+syst2S_pp_pt[i]*syst2S_pp_pt[i]+(0.2/5.4)*(0.2/5.4)+pow(Aet_2S_pythia_pt2013s[i]/Aet_2S_pythia_pt2013[i],2));
  syst3S_cspp_pt[i]=sqrt(syst3S_pptnp_pt[i]*syst3S_pptnp_pt[i]+syst3S_pp_pt[i]*syst3S_pp_pt[i]+(0.2/5.4)*(0.2/5.4)+pow(Aet_3S_pythia_pt2013s[i]/Aet_3S_pythia_pt2013[i],2));
  syst1S_csaa_pt[i]=sqrt(syst1S_aatnp_pt[i]*syst1S_aatnp_pt[i]+syst1S_aa_pt[i]*syst1S_aa_pt[i]+(0.057*0.057));
  syst1S_csaa_pt4[i]=sqrt(syst1S_aatnp_pt4[i]*syst1S_aatnp_pt4[i]+syst1S_aa_pt4[i]*syst1S_aa_pt4[i]+(0.057*0.057));
  cout << (binsPt[i]).c_str() << " " << stat1S_pp_pt[i] << " " <<syst1S_pp_pt[i] <<" "<< syst1S_aa_pt[i] <<" "<< syst1S_pptnp_pt[i] <<" "<< syst1S_aatnp_pt[i]<<" "<< syst1S_raa_pointPt[i] <<" "<< syst1S_raa_pt[i]<< endl;
 }
 cout << "--------------------1Spt4---------------------" << endl;
for(int i=0; i<nPtBins_2013; i++){
cout << (binsPt[i]).c_str() << " " << stat1S_pp_pt4[i] << " " <<syst1S_pp_pt4[i] <<" "<< syst1S_aa_pt4[i] <<" "<< syst1S_pptnp_pt4[i] <<" "<< syst1S_aatnp_pt4[i]<<" "<< syst1S_raa_pointPt4[i] <<" "<< syst1S_raa_pt4[i]<< endl;
 }


 syst1S_aa_rap[5]= sqrt (pow(RMS(N1S_aa_rap3p5_2014[5],N1S_aa_rap3p5s_2p4,nfitvars),2)+ pow(maxDeviation(N1S_aa_rap3p5_2014[5],N1B_aa_rap3p5s_2p4,nbkgdvars),2)) ;
 syst1S_aa_rap[4]= sqrt (pow(RMS(N1S_aa_rap3p5_2014[4],N1S_aa_rap3p5s_2p0,nfitvars),2)+ pow(maxDeviation(N1S_aa_rap3p5_2014[4],N1B_aa_rap3p5s_2p0,nbkgdvars),2)) ;
 syst1S_aa_rap[3]= sqrt (pow(RMS(N1S_aa_rap3p5_2014[3],N1S_aa_rap3p5s_1p6,nfitvars),2)+ pow(maxDeviation(N1S_aa_rap3p5_2014[3],N1B_aa_rap3p5s_1p6,nbkgdvars),2)) ;
 syst1S_aa_rap[2]= sqrt (pow(RMS(N1S_aa_rap3p5_2014[2],N1S_aa_rap3p5s_1p2,nfitvars),2)+ pow(maxDeviation(N1S_aa_rap3p5_2014[2],N1B_aa_rap3p5s_1p2,nbkgdvars),2)) ;
 syst1S_aa_rap[1]= sqrt (pow(RMS(N1S_aa_rap3p5_2014[1],N1S_aa_rap3p5s_0p8,nfitvars),2)+ pow(maxDeviation(N1S_aa_rap3p5_2014[1],N1B_aa_rap3p5s_0p8,nbkgdvars),2)) ;
 syst1S_aa_rap[0]= sqrt (pow(RMS(N1S_aa_rap3p5_2014[0],N1S_aa_rap3p5s_0p4,nfitvars),2)+ pow(maxDeviation(N1S_aa_rap3p5_2014[0],N1B_aa_rap3p5s_0p4,nbkgdvars),2)) ;
 
 syst1S_aa_rap4[5]= sqrt (pow(RMS(N1S_aa_rap4_2014[5],N1S_aa_rap4s_2p4,nfitvars),2)+ pow(maxDeviation(N1S_aa_rap4_2014[5],N1B_aa_rap4s_2p4,nbkgdvars),2)) ;
 syst1S_aa_rap4[4]= sqrt (pow(RMS(N1S_aa_rap4_2014[4],N1S_aa_rap4s_2p0,nfitvars),2)+ pow(maxDeviation(N1S_aa_rap4_2014[4],N1B_aa_rap4s_2p0,nbkgdvars),2)) ;
 syst1S_aa_rap4[3]= sqrt (pow(RMS(N1S_aa_rap4_2014[3],N1S_aa_rap4s_1p6,nfitvars),2)+ pow(maxDeviation(N1S_aa_rap4_2014[3],N1B_aa_rap4s_1p6,nbkgdvars),2)) ;
 syst1S_aa_rap4[2]= sqrt (pow(RMS(N1S_aa_rap4_2014[2],N1S_aa_rap4s_1p2,nfitvars),2)+ pow(maxDeviation(N1S_aa_rap4_2014[2],N1B_aa_rap4s_1p2,nbkgdvars),2)) ;
 syst1S_aa_rap4[1]= sqrt (pow(RMS(N1S_aa_rap4_2014[1],N1S_aa_rap4s_0p8,nfitvars),2)+ pow(maxDeviation(N1S_aa_rap4_2014[1],N1B_aa_rap4s_0p8,nbkgdvars),2)) ;
 syst1S_aa_rap4[0]= sqrt (pow(RMS(N1S_aa_rap4_2014[0],N1S_aa_rap4s_0p4,nfitvars),2)+ pow(maxDeviation(N1S_aa_rap4_2014[0],N1B_aa_rap4s_0p4,nbkgdvars),2)) ;
 
 syst1S_pp_rap[5]= sqrt (pow(RMS(N1S_pp_rap3p5_2014[5],N1S_pp_rap3p5s_2p4,nfitvars),2)+ pow(maxDeviation(N1S_pp_rap3p5_2014[5],N1B_pp_rap3p5s_2p4,nbkgdvars),2)) ;
 syst1S_pp_rap[4]= sqrt (pow(RMS(N1S_pp_rap3p5_2014[4],N1S_pp_rap3p5s_2p0,nfitvars),2)+ pow(maxDeviation(N1S_pp_rap3p5_2014[4],N1B_pp_rap3p5s_2p0,nbkgdvars),2)) ;
 syst1S_pp_rap[3]= sqrt (pow(RMS(N1S_pp_rap3p5_2014[3],N1S_pp_rap3p5s_1p6,nfitvars),2)+ pow(maxDeviation(N1S_pp_rap3p5_2014[3],N1B_pp_rap3p5s_1p6,nbkgdvars),2)) ;
 syst1S_pp_rap[2]= sqrt (pow(RMS(N1S_pp_rap3p5_2014[2],N1S_pp_rap3p5s_1p2,nfitvars),2)+ pow(maxDeviation(N1S_pp_rap3p5_2014[2],N1B_pp_rap3p5s_1p2,nbkgdvars),2)) ;
 syst1S_pp_rap[1]= sqrt (pow(RMS(N1S_pp_rap3p5_2014[1],N1S_pp_rap3p5s_0p8,nfitvars),2)+ pow(maxDeviation(N1S_pp_rap3p5_2014[1],N1B_pp_rap3p5s_0p8,nbkgdvars),2)) ;
 syst1S_pp_rap[0]= sqrt (pow(RMS(N1S_pp_rap3p5_2014[0],N1S_pp_rap3p5s_0p4,nfitvars),2)+ pow(maxDeviation(N1S_pp_rap3p5_2014[0],N1B_pp_rap3p5s_0p4,nbkgdvars),2)) ;
 
 syst1S_pp_rap4[5]= sqrt (pow(RMS(N1S_pp_rap4_2014[5],N1S_pp_rap4s_2p4,nfitvars),2)+ pow(maxDeviation(N1S_pp_rap4_2014[5],N1B_pp_rap4s_2p4,nbkgdvars),2)) ;
 syst1S_pp_rap4[4]= sqrt (pow(RMS(N1S_pp_rap4_2014[4],N1S_pp_rap4s_2p0,nfitvars),2)+ pow(maxDeviation(N1S_pp_rap4_2014[4],N1B_pp_rap4s_2p0,nbkgdvars),2)) ;
 syst1S_pp_rap4[3]= sqrt (pow(RMS(N1S_pp_rap4_2014[3],N1S_pp_rap4s_1p6,nfitvars),2)+ pow(maxDeviation(N1S_pp_rap4_2014[3],N1B_pp_rap4s_1p6,nbkgdvars),2)) ;
 syst1S_pp_rap4[2]= sqrt (pow(RMS(N1S_pp_rap4_2014[2],N1S_pp_rap4s_1p2,nfitvars),2)+ pow(maxDeviation(N1S_pp_rap4_2014[2],N1B_pp_rap4s_1p2,nbkgdvars),2)) ;
 syst1S_pp_rap4[1]= sqrt (pow(RMS(N1S_pp_rap4_2014[1],N1S_pp_rap4s_0p8,nfitvars),2)+ pow(maxDeviation(N1S_pp_rap4_2014[1],N1B_pp_rap4s_0p8,nbkgdvars),2)) ;
 syst1S_pp_rap4[0]= sqrt (pow(RMS(N1S_pp_rap4_2014[0],N1S_pp_rap4s_0p4,nfitvars),2)+ pow(maxDeviation(N1S_pp_rap4_2014[0],N1B_pp_rap4s_0p4,nbkgdvars),2)) ;
 
 syst2S_pp_rap[5]= sqrt (pow(RMS(N2S_pp_rap4_2014[5],N2S_pp_rap4s_2p4,nfitvars),2)+ pow(maxDeviation(N2S_pp_rap4_2014[5],N2B_pp_rap4s_2p4,nbkgdvars),2)) ;
 syst2S_pp_rap[4]= sqrt (pow(RMS(N2S_pp_rap4_2014[4],N2S_pp_rap4s_2p0,nfitvars),2)+ pow(maxDeviation(N2S_pp_rap4_2014[4],N2B_pp_rap4s_2p0,nbkgdvars),2)) ;
 syst2S_pp_rap[3]= sqrt (pow(RMS(N2S_pp_rap4_2014[3],N2S_pp_rap4s_1p6,nfitvars),2)+ pow(maxDeviation(N2S_pp_rap4_2014[3],N2B_pp_rap4s_1p6,nbkgdvars),2)) ;
 syst2S_pp_rap[2]= sqrt (pow(RMS(N2S_pp_rap4_2014[2],N2S_pp_rap4s_1p2,nfitvars),2)+ pow(maxDeviation(N2S_pp_rap4_2014[2],N2B_pp_rap4s_1p2,nbkgdvars),2)) ;
 syst2S_pp_rap[1]= sqrt (pow(RMS(N2S_pp_rap4_2014[1],N2S_pp_rap4s_0p8,nfitvars),2)+ pow(maxDeviation(N2S_pp_rap4_2014[1],N2B_pp_rap4s_0p8,nbkgdvars),2)) ;
 syst2S_pp_rap[0]= sqrt (pow(RMS(N2S_pp_rap4_2014[0],N2S_pp_rap4s_0p4,nfitvars),2)+ pow(maxDeviation(N2S_pp_rap4_2014[0],N2B_pp_rap4s_0p4,nbkgdvars),2)) ;

 syst3S_pp_rap[5]= sqrt (pow(RMS(N3S_pp_rap4_2014[5],N3S_pp_rap4s_2p4,nfitvars),2)+ pow(maxDeviation(N3S_pp_rap4_2014[5],N3B_pp_rap4s_2p4,nbkgdvars),2)) ;
 syst3S_pp_rap[4]= sqrt (pow(RMS(N3S_pp_rap4_2014[4],N3S_pp_rap4s_2p0,nfitvars),2)+ pow(maxDeviation(N3S_pp_rap4_2014[4],N3B_pp_rap4s_2p0,nbkgdvars),2)) ;
 syst3S_pp_rap[3]= sqrt (pow(RMS(N3S_pp_rap4_2014[3],N3S_pp_rap4s_1p6,nfitvars),2)+ pow(maxDeviation(N3S_pp_rap4_2014[3],N3B_pp_rap4s_1p6,nbkgdvars),2)) ;
 syst3S_pp_rap[2]= sqrt (pow(RMS(N3S_pp_rap4_2014[2],N3S_pp_rap4s_1p2,nfitvars),2)+ pow(maxDeviation(N3S_pp_rap4_2014[2],N3B_pp_rap4s_1p2,nbkgdvars),2)) ;
 syst3S_pp_rap[1]= sqrt (pow(RMS(N3S_pp_rap4_2014[1],N3S_pp_rap4s_0p8,nfitvars),2)+ pow(maxDeviation(N3S_pp_rap4_2014[1],N3B_pp_rap4s_0p8,nbkgdvars),2)) ;
 syst3S_pp_rap[0]= sqrt (pow(RMS(N3S_pp_rap4_2014[0],N3S_pp_rap4s_0p4,nfitvars),2)+ pow(maxDeviation(N3S_pp_rap4_2014[0],N3B_pp_rap4s_0p4,nbkgdvars),2)) ;

 syst2S_pp_rapLarge[1]=sqrt (pow(RMS(N2S_pp_rap4_2014Large[1],N2S_pp_rap4Larges_2p4,nfitvars),2)+ pow(maxDeviation(N2S_pp_rap4_2014Large[1],N2B_pp_rap4Larges_2p4,nbkgdvars),2));
 syst2S_pp_rapLarge[0]=sqrt (pow(RMS(N2S_pp_rap4_2014Large[0],N2S_pp_rap4Larges_1p2,nfitvars),2)+ pow(maxDeviation(N2S_pp_rap4_2014Large[0],N2B_pp_rap4Larges_1p2,nbkgdvars),2));

 syst2S_aa_rap[1]=sqrt (pow(RMS(N2S_aa_rap4_2014Large[1],N2S_aa_rap4Larges_2p4,nfitvars),2) + pow(maxDeviation(N2S_aa_rap4_2014Large[1],N2B_aa_rap4Larges_2p4,nbkgdvars),2)) ;
 syst2S_aa_rap[0]=sqrt (pow(RMS(N2S_aa_rap4_2014Large[0],N2S_aa_rap4Larges_1p2,nfitvars),2) + pow(maxDeviation(N2S_aa_rap4_2014Large[0],N2B_aa_rap4Larges_1p2,nbkgdvars),2)) ;


for(int i=0; i<nRapBins_2014; i++){
  syst1S_pptnp_rap[i] = t_1S_pythia_rap3p5e[i]/t_1S_pythia_rap3p5[i]; //add syst. unc. from tnp
  syst1S_pptnp_rap4[i]= t_1S_pythia_rap4e[i]/t_1S_pythia_rap4[i]; //add syst. unc. from tnp
  syst2S_pptnp_rap[i] = t_2S_pythia_rap4e[i]/t_2S_pythia_rap4[i];
  syst3S_pptnp_rap[i] = t_3S_pythia_rap4e[i]/t_3S_pythia_rap4[i];
  syst1S_aatnp_rap[i] = t_1S_pyquen_rap3p5e[i]/t_1S_pyquen_rap3p5[i];
  syst1S_aatnp_rap4[i]= t_1S_pyquen_rap4e[i]/t_1S_pyquen_rap4[i]; 
    
  stat1S_pp_rap[i]=N1S_pp_rap3p5_2014e[i]/N1S_pp_rap3p5_2014[i];
  stat1S_pp_rap4[i]=N1S_pp_rap4_2014e[i]/N1S_pp_rap4_2014[i];
  stat2S_pp_rap[i]=N2S_pp_rap4_2014e[i]/N2S_pp_rap4_2014[i];
  stat3S_pp_rap[i]=N3S_pp_rap4_2014e[i]/N3S_pp_rap4_2014[i];
  syst1S_raa_pointRap[i]=sqrt(syst1S_pp_rap[i]*syst1S_pp_rap[i]+syst1S_aa_rap[i]*syst1S_aa_rap[i]+syst1S_pptnp_rap[i]*syst1S_pptnp_rap[i]+syst1S_aatnp_rap[i]*syst1S_aatnp_rap[i]);//this one is big : stat.pp + syst.pp + syst.pbpb + tnp_pp + tnp_pbpb
  syst1S_raa_pointRap4[i]=sqrt(syst1S_pp_rap4[i]*syst1S_pp_rap4[i]+syst1S_aa_rap4[i]*syst1S_aa_rap4[i]+syst1S_pptnp_rap4[i]*syst1S_pptnp_rap4[i]+syst1S_aatnp_rap4[i]*syst1S_aatnp_rap4[i]);//this one is big : stat.pp + syst.pp + syst.pbpb + tnp_pp + tnp_pbpb
  syst1S_raa_rap[i]=sqrt(syst1S_raa_pointRap[i]*syst1S_raa_pointRap[i]+syst1S_raa_global*syst1S_raa_global+pow(Aet_1S_pyquen_rap2014s[i]/Aet_1S_pyquen_rap2014[i],2)+pow(Aet_1S_pythia_rap2014s[i]/Aet_1S_pythia_rap2014s[i],2));
  syst1S_raa_rap4[i]=sqrt(syst1S_raa_pointRap4[i]*syst1S_raa_pointRap4[i]+syst1S_raa_global4*syst1S_raa_global4+pow(Aet_1S_pyquen_rap42014s[i]/Aet_1S_pyquen_rap42014[i],2)+pow(Aet_1S_pythia_rap4s[i]/Aet_1S_pythia_rap4s[i],2));
  syst1S_cspp_rap[i]=sqrt(syst1S_pptnp_rap[i]*syst1S_pptnp_rap[i]+syst1S_pp_rap[i]*syst1S_pp_rap[i]+(0.2/5.4)*(0.2/5.4)+pow(Aet_1S_pythia_rap2014s[i]/Aet_1S_pythia_rap2014[i],2));
  syst1S_cspp_rap4[i]=sqrt(syst1S_pptnp_rap4[i]*syst1S_pptnp_rap4[i]+syst1S_pp_rap4[i]*syst1S_pp_rap4[i]+(0.2/5.4)*(0.2/5.4)+pow(Aet_1S_pythia_rap4s[i]/Aet_1S_pythia_rap4[i],2));
  syst2S_cspp_rap[i]=sqrt(syst2S_pptnp_rap[i]*syst2S_pptnp_rap[i]+syst2S_pp_rap[i]*syst2S_pp_rap[i]+(0.2/5.4)*(0.2/5.4)+pow(Aet_2S_pythia_rap2014s[i]/Aet_2S_pythia_rap2014[i],2));
  syst3S_cspp_rap[i]=sqrt(syst3S_pptnp_rap[i]*syst3S_pptnp_rap[i]+syst3S_pp_rap[i]*syst3S_pp_rap[i]+(0.2/5.4)*(0.2/5.4)+pow(Aet_3S_pythia_rap2014s[i]/Aet_3S_pythia_rap2014[i],2));
  syst1S_csaa_rap[i]=sqrt(syst1S_aatnp_rap[i]*syst1S_aatnp_rap[i]+syst1S_aa_rap[i]*syst1S_aa_rap[i]+(0.057*0.057)+pow(Aet_1S_pyquen_rap2014s[i]/Aet_1S_pyquen_rap2014[i],2));
  syst1S_csaa_rap4[i]=sqrt(syst1S_aatnp_rap4[i]*syst1S_aatnp_rap4[i]+syst1S_aa_rap4[i]*syst1S_aa_rap4[i]+(0.057*0.057)+pow(Aet_1S_pyquen_rap42014s[i]/Aet_1S_pyquen_rap42014[i],2));
 } 
 cout << "--------------------1S-rap--------------------" << endl;

 
 for(int i=0; i<nRapBins_2014; i++){
cout << (binsRap[i]).c_str() << " " << stat1S_pp_rap[i] << " " <<syst1S_pp_rap[i] <<" "<< syst1S_aa_rap[i] <<" "<< syst1S_pptnp_rap[i] <<" "<< syst1S_aatnp_rap[i]<<" "<< syst1S_raa_pointRap[i] <<" "<< syst1S_raa_rap[i]<< endl;
 }
 cout << "--------------------1Spt4---------------------" << endl;
for(int i=0; i<nRapBins_2014; i++){
cout << (binsRap[i]).c_str() << " " << stat1S_pp_rap4[i] << " " <<syst1S_pp_rap4[i] <<" "<< syst1S_aa_rap4[i] <<" "<< syst1S_pptnp_rap4[i] <<" "<< syst1S_aatnp_rap4[i]<<" "<< syst1S_raa_pointRap4[i] <<" "<< syst1S_raa_rap4[i]<< endl;
 }

 cout << "--------------------2S pt ---------------------" << endl; 
 for(int i=0; i<nPtBins_2010; i++){      
   stat2S_pp_ptLarge[i]=N2S_pp_pt4_2013Largee[i]/N2S_pp_pt4_2013Large[i];
   //  syst2S_aa_pt[i]=sqrt(syst2S_aa_pt[i])/(nfitvars+nbkgdvars);//fit
   //  syst2S_pp_ptLarge[i]=sqrt(syst2S_pp_ptLarge[i])/(nfitvars+nbkgdvars);  
   syst2S_aatnp_pt[i]=t_2S_pyquen_pt2010e[i]/t_2S_pyquen_pt2010[i];//tnp
   syst2S_pptnp_ptLarge[i]=sqrt((t_2S_pythia_pt2010[i]-1)*(t_2S_pythia_pt2010[i]-1));
   syst2S_raa_pointPt[i]=sqrt(stat2S_pp_ptLarge[i]*stat2S_pp_ptLarge[i]+syst2S_pp_ptLarge[i]*syst2S_pp_ptLarge[i]+syst2S_aa_pt[i]*syst2S_aa_pt[i]+syst2S_pptnp_ptLarge[i]*syst2S_pptnp_ptLarge[i]+syst2S_aatnp_pt[i]*syst2S_aatnp_pt[i]+pow(Aet_2S_pythia_pt2013Larges[i]/Aet_2S_pythia_pt2013Large[i],2)+pow(Aet_2S_pyquen_pt2013Larges[i]/Aet_2S_pyquen_pt2013Large[i],2));//this one is big : stat.pp + syst.pp + syst.pbpb + tnp_pp + tnp_pbpb
   syst2S_raa_pt[i]=sqrt(syst2S_raa_pointPt[i]*syst2S_raa_pointPt[i]+syst2S_raa_global*syst2S_raa_global);
   syst2S_cspp_ptLarge[i]=sqrt(syst2S_pptnp_pt[i]*syst2S_pptnp_pt[i]+syst2S_pp_ptLarge[i]*syst2S_pp_ptLarge[i]+(0.2/5.4)*(0.2/5.4)+pow(Aet_2S_pythia_pt2013Larges[i]/Aet_2S_pythia_pt2013Large[i],2));//CS:tnp+fit+glob
   syst2S_csaa_pt[i]=sqrt(syst2S_aatnp_pt[i]*syst2S_aatnp_pt[i]+syst2S_aa_pt[i]*syst2S_aa_pt[i]+(0.057*0.057)+pow(Aet_2S_pyquen_pt2013Larges[i]/Aet_2S_pyquen_pt2013Large[i],2));
   cout << (binsPt2010[i]).c_str() << " " << stat2S_pp_ptLarge[i] << " " <<syst2S_pp_ptLarge[i] <<" "<< syst2S_aa_pt[i] <<" "<< syst2S_pptnp_ptLarge[i] <<" "<< syst2S_aatnp_pt[i]<<" "<< syst2S_raa_pointPt[i] <<" "<< syst2S_raa_pt[i]<< endl;
 }
 cout << "--------------------2S rap ---------------------" << endl; 
 for(int i=0; i<nRapBins_2010; i++){
   stat2S_pp_rapLarge[i]=N2S_pp_rap4_2014Largee[i]/N2S_pp_rap4_2014Large[i];
   //  syst2S_aa_rap[i]=sqrt(syst2S_aa_rap[i])/(nfitvars+nbkgdvars);//fit
   //   syst2S_pp_rapLarge[i]=sqrt(syst2S_pp_rapLarge[i])/(nfitvars+nbkgdvars);  
   syst2S_aatnp_rap[i]=t_2S_pyquen_rap2010e[i]/t_2S_pyquen_rap2010[i];//tnp
   syst2S_pptnp_rapLarge[i]=t_2S_pythia_rap2010e[i]/t_2S_pythia_rap2010[i];
   syst2S_raa_pointRap[i]=sqrt(syst2S_pp_rapLarge[i]*syst2S_pp_rapLarge[i]+syst2S_aa_rap[i]*syst2S_aa_rap[i]+syst2S_pptnp_rapLarge[i]*syst2S_pptnp_rapLarge[i]+syst2S_aatnp_rap[i]*syst2S_aatnp_rap[i]+pow(Aet_2S_pyquen_rap2014Larges[i]/Aet_2S_pyquen_rap2014Large[i],2)+pow(Aet_2S_pythia_rap2014Larges[i]/Aet_2S_pythia_rap2014Large[i],2));//this one is big : stat.pp + syst.pp + syst.pbpb + tnp_pp + tnp_pbpb + Ae_syst pp + Ae_syst pbpb 
   syst2S_raa_rap[i]=sqrt(syst2S_raa_pointRap[i]*syst2S_raa_pointRap[i]+syst2S_raa_global*syst2S_raa_global);
   syst2S_cspp_rapLarge[i]=sqrt(syst2S_pptnp_rap[i]*syst2S_pptnp_rap[i]+syst2S_pp_rapLarge[i]*syst2S_pp_rapLarge[i]+(0.2/5.4)*(0.2/5.4));//CS:tnp+fit+glob
   syst2S_csaa_rap[i]=sqrt(syst2S_aatnp_rap[i]*syst2S_aatnp_rap[i]+syst2S_aa_rap[i]*syst2S_aa_rap[i]+(0.057*0.057));
  
  cout << (binsRap2010[i]).c_str() << " " << stat2S_pp_rapLarge[i] << " " <<syst2S_pp_rapLarge[i] <<" "<< syst2S_aa_rap[i] <<" "<< syst2S_pptnp_rapLarge[i] <<" "<< syst2S_aatnp_rap[i]<<" "<< syst2S_raa_pointRap[i] <<" "<< syst2S_raa_rap[i]<< endl;

   // syst2S_aa_rap[i]=(syst2S_aa_rap[i])/(nfitvars+nbkgdvars);
   // syst2S_aa_rap[i]+=((t_2S_pyquen_rap2010[i]-1)*(t_2S_pyquen_rap2010[i]-1));
   // syst2S_pp_rapLarge[i]=(syst2S_pp_rapLarge[i])/(nfitvars+nbkgdvars);
   // syst2S_pp_rapLarge[i]+=((t_2S_pythia_rap2010[i]-1)*(t_2S_pythia_rap2010[i]-1));

   // syst2S_aa_rap[i]=sqrt(syst2S_aa_rap[i]);
   // syst2S_pp_rapLarge[i]=sqrt(syst2S_pp_rapLarge[i]);
 }

for(int i=0; i<nPtBins_2013; i++){
  ofSyst<< "1S_pp_pt_" << (binsPt[i]).c_str() << " "<< 100*syst1S_pp_pt[i]<<" %"<<endl;
  ofSyst<< "1S_aa_pt_"<<i << " "<< 100*syst1S_aa_pt[i]<< " %"<<endl;
  ofSyst<< "2S_pp_pt_"<<i << " "<< 100*syst2S_pp_pt[i]<<" %"<< endl;
  ofSyst<< "3S_pp_pt_"<<i << " "<< 100*syst3S_pp_pt[i]<<" %"<< endl;
}

for(int i=0; i<nPtBins_2010; i++){
ofSyst<< "2S_aa_pt_"<<i << " "<< 100*syst2S_aa_pt[i]<< " %"<<endl;
ofSyst<< "2S_pp_ptLarge_"<<i << " "<< 100*syst2S_pp_ptLarge[i]<< " %"<<endl;
}

for(int i=0; i<nRapBins_2014; i++){
  ofSyst<< "1S_pp_rap_"<<i << " "<< 100*syst1S_pp_rap[i]<<" %"<<endl;
  ofSyst<< "1S_aa_rap_"<<i << " "<< 100*syst1S_aa_rap[i]<< " %"<<endl;
  ofSyst<< "2S_pp_rap_"<<i << " "<< 100*syst2S_pp_rap[i]<<" %"<< endl;
  ofSyst<< "3S_pp_rap_"<<i << " "<< 100*syst3S_pp_rap[i]<<" %"<< endl;
 }
for(int i=0; i<nRapBins_2010; i++){
ofSyst<< "2S_aa_rap_"<<i << " "<< 100*syst2S_aa_rap[i]<< " %"<<endl;
ofSyst<< "2S_pp_rapLarge_"<<i << " "<< 100*syst2S_pp_rapLarge[i]<< " %"<<endl;

 ofSyst.close();
}

  for(int i = 0 ; i<nPtBins_2013 ; i++)
    {
      //significance stuff, for all non-believers out there
      SigOverErr_ppPt1S3p5[i]=computeRatio(N1S_pp_pt3p5[i],N1S_pp_pt3p5e[i]);
      SigOverErr_aaPt1S3p5[i]=computeRatio(N1S_aa_pt3p5[i],N1S_aa_pt3p5e[i]);
      SigOverErr_ppPt2S3p5[i]=computeRatio(N2S_pp_pt3p5[i],N2S_pp_pt3p5e[i]);
      SigOverErr_ppPt3S3p5[i]=computeRatio(N3S_pp_pt3p5[i],N3S_pp_pt3p5e[i]);
      SigOverErr_ppPt1S4[i]=computeRatio(N1S_pp_pt4[i],N1S_pp_pt4e[i]);
      SigOverErr_aaPt1S4[i]=computeRatio(N1S_aa_pt4[i],N1S_aa_pt4e[i]);
      SigOverErr_ppPt2S4[i]=computeRatio(N2S_pp_pt4_2013[i],N2S_pp_pt4_2013e[i]);
      SigOverErr_ppPt3S4[i]=computeRatio(N3S_pp_pt4_2013[i],N3S_pp_pt4_2013e[i]);

      // tnp
      CS1S_pp_tnp_pt[i]= computeRatio( N1S_pp_pt3p5[i] , Aet_1S_pythia_pt[i] ); 
      CS1S_aa_tnp_pt[i]= computeRatio( N1S_aa_pt3p5[i] , Aet_1S_pyquen_pt[i] );
      CS1S_pp_tnp_pte[i] = computeRatioError( N1S_pp_pt3p5[i] , Aet_1S_pythia_pt[i], N1S_pp_pt3p5e[i] , Aet_1S_pythia_pte[i]);
      CS1S_aa_tnp_pte[i] = computeRatioError(  N1S_aa_pt3p5[i] , Aet_1S_pyquen_pt[i] ,  N1S_aa_pt3p5e[i] , Aet_1S_pyquen_pte[i] );
      CS1S_pp_tnp_pts[i] = N1S_pp_pt3p5[i]*syst1S_cspp_pt[i];
      CS1S_aa_tnp_pts[i] = N1S_aa_pt3p5[i]*syst1S_csaa_pt[i];
      //pt4
      CS1S_pp_tnp_pt4[i]= computeRatio( N1S_pp_pt4[i] , Aet_1S_pythia_pt4[i] ); 
      CS1S_aa_tnp_pt4[i]= computeRatio( N1S_aa_pt4[i] , Aet_1S_pyquen_pt4[i] );
      CS1S_pp_tnp_pt4e[i] = computeRatioError( N1S_pp_pt4[i] , Aet_1S_pythia_pt4[i], N1S_pp_pt4e[i] , Aet_1S_pythia_pt4e[i]);
      CS1S_aa_tnp_pt4e[i] = computeRatioError(  N1S_aa_pt4[i] , Aet_1S_pyquen_pt4[i] ,  N1S_aa_pt4e[i] , Aet_1S_pyquen_pt4e[i] );
      CS1S_pp_tnp_pt4s[i] = N1S_pp_pt4[i]*syst1S_cspp_pt[i];
      CS1S_aa_tnp_pt4s[i] = N1S_aa_pt4[i]*syst1S_csaa_pt[i];
      CS1S_pp_tnp_pt4[i]=CS1S_pp_tnp_pt4[i]/(L_pp_invNb*RapBinWidth*deltaPt[i]);    
      CS1S_aa_tnp_pt4[i]=CS1S_aa_tnp_pt4[i]/(N_MB_corr * T_AA_b*RapBinWidth*deltaPt[i]);
      CS1S_pp_tnp_pt4e[i]=CS1S_pp_tnp_pt4e[i]/(L_pp_invNb*RapBinWidth*deltaPt[i]);
      CS1S_aa_tnp_pt4e[i]=CS1S_aa_tnp_pt4e[i]/(N_MB_corr * T_AA_b *RapBinWidth*deltaPt[i]);
      CS1S_pp_tnp_pt4s[i] = CS1S_pp_tnp_pt4s[i]/(L_pp_invNb*RapBinWidth*deltaPt[i]);    
      CS1S_aa_tnp_pt4s[i] = CS1S_aa_tnp_pt4s[i]/(N_MB_corr * T_AA_b *(RapBinWidth*deltaPt[i])); 
      RAA_1S_tnp_pt4[i] = computeRatio( CS1S_aa_tnp_pt4[i] , CS1S_pp_tnp_pt4[i]);
      RAA_1S_tnp_pt4e[i] = computeRatioError( CS1S_aa_tnp_pt4[i] , CS1S_pp_tnp_pt4[i], CS1S_aa_tnp_pt4e[i] , CS1S_pp_tnp_pt4e[i]);
      RAA_1S_tnp_pt4s[i] = RAA_1S_tnp_pt4[i]*syst1S_raa_pointPt4[i]; //computeRatioError( CS1S_aa_tnp_pt[i] , CS1S_pp_tnp_pt[i], CS1S_aa_tnp_pts[i] , CS1S_pp_tnp_pts[i]);
      RAA_1S_tnp_pt4sT[i] = RAA_1S_tnp_pt4[i]*syst1S_raa_pt4[i]; //computeRatioError( CS1S_aa_tnp_pt[i] , CS1S_pp_tnp_pt[i], CS1S_aa_tnp_pts[i] , CS1S_pp_tnp_pts[i]);
    
      //excited ones
      CS2S_pp_tnp_pts[i] = N2S_pp_pt4_2013[i]*syst2S_cspp_pt[i];
      CS3S_pp_tnp_pts[i] = N3S_pp_pt4_2013[i]*syst3S_cspp_pt[i];
      CS2S_pp_tnp_pt2013[i]= computeRatio( N2S_pp_pt4_2013[i] , Aet_2S_pythia_pt2013[i] ); 
      CS2S_pp_tnp_pt2013e[i] = computeRatioError( N2S_pp_pt4_2013[i] , Aet_2S_pythia_pt2013[i] , N2S_pp_pt4_2013e[i] , Aet_2S_pythia_pt2013e[i] );        
      CS3S_pp_tnp_pt2013[i]= computeRatio( N3S_pp_pt4_2013[i] , Aet_3S_pythia_pt2013[i] ); 
      CS3S_pp_tnp_pt2013e[i] = computeRatioError( N3S_pp_pt4_2013[i] , Aet_3S_pythia_pt2013[i] , N3S_pp_pt4_2013e[i] , Aet_3S_pythia_pt2013e[i] );

      //fiducial shit
      CS2S_pp_pt2013Fiducial[i]= computeRatio( N2S_pp_pt4_2013[i] , e_2S_pythia_pt2013[i] );      
      CS2S_pp_pt2013Fiduciale[i] = computeRatioError( N2S_pp_pt4_2013[i] , e_2S_pythia_pt2013[i] , N2S_pp_pt4_2013e[i] , e_2S_pythia_pt2013e[i] );
      CS1S_aa_ptFiducial[i]= computeRatio( N1S_aa_pt3p5[i] , e_1S_pyquen_pt[i] );
      CS1S_pp_ptFiducial[i]= computeRatio( N1S_pp_pt3p5[i] , e_1S_pythia_pt3p5[i] );
      CS1S_aa_pt[i]= computeRatio( N1S_aa_pt3p5[i] , Ae_1S_pyquen_pt[i] ); 
      CS1S_pp_ptFiducial[i] = computeRatio( N1S_pp_pt3p5[i] , e_1S_pythia_pt3p5[i] ); 
      CS1S_aa_ptFiducial[i] = computeRatio( N1S_aa_pt3p5[i] , e_1S_pyquen_pt[i] );
      CS1S_pp_ptFiduciale[i] = computeRatioError( N1S_pp_pt3p5[i] , e_1S_pythia_pt3p5[i], N1S_pp_pt3p5e[i] , e_1S_pythia_pt3p5e[i]);   
      CS1S_aa_ptFiduciale[i] = computeRatioError(  N1S_aa_pt3p5[i] , e_1S_pyquen_pt[i] ,  N1S_aa_pt3p5e[i] , e_1S_pyquen_pte[i] );
      CS1S_pp_ptFiducial[i]=CS1S_pp_ptFiducial[i]/L_pp_invNb;
      CS1S_aa_ptFiducial[i]=CS1S_aa_ptFiducial[i]/(N_MB_corr * T_AA_b);
      CS1S_pp_ptFiduciale[i]=CS1S_pp_ptFiduciale[i]/L_pp_invNb;
      CS1S_aa_ptFiduciale[i]=CS1S_aa_ptFiduciale[i]/(N_MB_corr * T_AA_b);
      CS1S_pp_ptFiducial[i]=CS1S_pp_ptFiducial[i]/deltaPt[i];
      CS1S_aa_ptFiducial[i]=CS1S_aa_ptFiducial[i]/deltaPt[i];
      CS1S_pp_ptFiduciale[i]=CS1S_pp_ptFiduciale[i]/deltaPt[i];
      CS1S_aa_ptFiduciale[i]=CS1S_aa_ptFiduciale[i]/deltaPt[i];    
      CS2S_pp_pt2013Fiducial[i]=CS2S_pp_pt2013Fiducial[i]/L_pp_invNb;
      CS2S_pp_pt2013Fiduciale[i]=CS2S_pp_pt2013Fiduciale[i]/L_pp_invNb;
      CS2S_pp_pt2013Fiducial[i]=CS2S_pp_pt2013Fiducial[i]/deltaPt[i];
      CS2S_pp_pt2013Fiduciale[i]=CS2S_pp_pt2013Fiduciale[i]/deltaPt[i];
      //good ones
      CS1S_pp_pt[i]=CS1S_pp_pt[i]/(L_pp_invNb*RapBinWidth*deltaPt[i]);    
      CS1S_aa_pt[i]=CS1S_aa_pt[i]/(N_MB_corr * T_AA_b*(RapBinWidth*deltaPt[i]));
      CS1S_pp_pte[i]=CS1S_pp_pte[i]/(L_pp_invNb*RapBinWidth*deltaPt[i]);
      CS1S_aa_pte[i]=CS1S_aa_pte[i]/(N_MB_corr * T_AA_b *(RapBinWidth*deltaPt[i]));
      CS2S_pp_tnp_pts[i] = CS2S_pp_tnp_pts[i]/(L_pp_invNb*RapBinWidth*deltaPt[i]);    
      CS3S_pp_tnp_pts[i] = CS3S_pp_tnp_pts[i]/(L_pp_invNb*RapBinWidth*deltaPt[i]);    
      CS2S_pp_pt2013[i]=CS2S_pp_pt2013[i]/(RapBinWidth*deltaPt[i]*L_pp_invNb);
      CS2S_pp_pt2013e[i]=CS2S_pp_pt2013e[i]/(RapBinWidth*deltaPt[i]*L_pp_invNb);
      CS3S_pp_pt2013[i]=CS3S_pp_pt2013[i]/(RapBinWidth*deltaPt[i]*L_pp_invNb);
      CS3S_pp_pt2013e[i]=CS3S_pp_pt2013e[i]/(RapBinWidth*deltaPt[i]*L_pp_invNb);
      //tnp correction
      CS1S_pp_tnp_pt[i]=CS1S_pp_tnp_pt[i]/(L_pp_invNb*RapBinWidth*deltaPt[i]);    
      CS1S_aa_tnp_pt[i]=CS1S_aa_tnp_pt[i]/(N_MB_corr * T_AA_b*RapBinWidth*deltaPt[i]);
      CS1S_pp_tnp_pte[i]=CS1S_pp_tnp_pte[i]/(L_pp_invNb*RapBinWidth*deltaPt[i]);
      CS1S_aa_tnp_pte[i]=CS1S_aa_tnp_pte[i]/(N_MB_corr * T_AA_b *RapBinWidth*deltaPt[i]);
      CS1S_aa_tnp_pts[i] = CS1S_aa_tnp_pts[i]/(N_MB_corr * T_AA_b *(RapBinWidth*deltaPt[i])); 
      CS1S_pp_tnp_pts[i] = CS1S_pp_tnp_pts[i]/(L_pp_invNb*RapBinWidth*deltaPt[i]);    
      CS2S_pp_tnp_pt2013[i]=CS2S_pp_tnp_pt2013[i]/(RapBinWidth*deltaPt[i]*L_pp_invNb);
      CS2S_pp_tnp_pt2013e[i]=CS2S_pp_tnp_pt2013e[i]/(RapBinWidth*deltaPt[i]*L_pp_invNb);
      CS3S_pp_tnp_pt2013[i]=CS3S_pp_tnp_pt2013[i]/(RapBinWidth*deltaPt[i]*L_pp_invNb);
      CS3S_pp_tnp_pt2013e[i]=CS3S_pp_tnp_pt2013e[i]/(RapBinWidth*deltaPt[i]*L_pp_invNb);
      RAA_1S_pt[i] = computeRatio( CS1S_aa_pt[i] , CS1S_pp_pt[i]);
      RAA_1S_pte[i] = computeRatioError( CS1S_aa_pt[i] , CS1S_pp_pt[i], CS1S_aa_pte[i] , CS1S_pp_pte[i]);
      // cout<<"cs1S (ppPt, ppRap, aaPt, aaRap)"<< CS1S_pp_pt[i] <<", " <<CS1S_pp_rap2014[i] <<", " <<CS1S_aa_pt[i] <<", " <<CS1S_aa_rap[i] <<". " << endl;
      // cout <<"sigma(1S)_pp vs Pt ="<< endl;
      //invariant yields, corrected by taa and lumi corr.//////raaaaaaaa!
      RAA_1S_tnp_pt[i] = computeRatio( CS1S_aa_tnp_pt[i] , CS1S_pp_tnp_pt[i]);
      RAA_1S_tnp_pte[i] = computeRatioError( CS1S_aa_tnp_pt[i] , CS1S_pp_tnp_pt[i], CS1S_aa_tnp_pte[i] , CS1S_pp_tnp_pte[i]);
      RAA_1S_tnp_pts[i] = RAA_1S_tnp_pt[i]*syst1S_raa_pointPt[i]; //computeRatioError( CS1S_aa_tnp_pt[i] , CS1S_pp_tnp_pt[i], CS1S_aa_tnp_pts[i] , CS1S_pp_tnp_pts[i]);
      RAA_1S_tnp_ptsT[i] = RAA_1S_tnp_pt[i]*syst1S_raa_pt[i]; //computeRatioError( CS1S_aa_tnp_pt[i] , CS1S_pp_tnp_pt[i], CS1S_aa_tnp_pts[i] , CS1S_pp_tnp_pts[i]);
      R_A_1S_pt[i]=computeRatio(A_1S_pythia_pt3p5[i],A_1S_pyquen_pt[i]);
      R_A_1S_pte[i]=computeRatioError(A_1S_pythia_pt3p5[i],A_1S_pyquen_pt[i],A_1S_pythia_pt3p5e[i],A_1S_pyquen_pte[i]);
      R_e_1S_pt[i]=computeRatio(e_1S_pythia_pt3p5[i],e_1S_pyquen_pt[i]);
      R_e_1S_pte[i]=computeRatioError(e_1S_pythia_pt3p5[i],e_1S_pyquen_pt[i],e_1S_pythia_pt3p5e[i],e_1S_pyquen_pte[i]);
    }
 
  for(int i=0; i < nRapBins_2014; i++)
    {
      //significance, die non-believers!
      SigOverErr_ppRap1S3p5[i]=computeRatio(N1S_pp_rap3p5_2014[i],N1S_pp_rap3p5_2014e[i]);
      SigOverErr_ppRap1S4[i]=computeRatio(N1S_pp_rap4_2014[i],N1S_pp_rap4_2014e[i]);
      SigOverErr_aaRap1S3p5[i]=computeRatio(N1S_aa_rap3p5_2014[i],N1S_aa_rap3p5_2014e[i]);
      SigOverErr_aaRap1S4[i]=computeRatio(N1S_aa_rap4_2014[i],N1S_aa_rap4_2014e[i]);
      SigOverErr_ppRap2S3p5[i]=computeRatio(N2S_pp_rap3p5_2014[i],N2S_pp_rap3p5_2014e[i]); 
      SigOverErr_ppRap2S4[i]=computeRatio(N2S_pp_rap4_2014[i],N2S_pp_rap4_2014e[i]);
      SigOverErr_ppRap3S4[i]=computeRatio(N3S_pp_rap4_2014[i],N3S_pp_rap4_2014e[i]);
      SigOverErr_ppRap3S3p5[i]=computeRatio(N3S_pp_rap3p5_2014[i],N3S_pp_rap3p5_2014e[i]);
      //fiducial shit
      CS1S_aa_rapFiducial[i] = computeRatio( N1S_aa_rap3p5_2014[i] , e_1S_pyquen_rap2014[i] );
      CS1S_pp_rap2014Fiduciale[i] = computeRatioError(  N1S_pp_rap3p5_2014[i] , e_1S_pythia_rap3p5[i] ,  N1S_pp_rap3p5_2014e[i] , e_1S_pythia_rap3p5e[i] );
      CS1S_pp_rap2014Fiducial[i]= computeRatio( N1S_pp_rap3p5_2014[i] , e_1S_pythia_rap3p5[i] );  
      CS1S_aa_rapFiduciale[i] = computeRatioError(   N1S_aa_rap3p5_2014[i] , e_1S_pyquen_rap2014[i] ,  N1S_aa_rap3p5_2014e[i] , e_1S_pyquen_rap2014e[i]);
      CS1S_pp_rap2014Fiducial[i]=CS1S_pp_rap2014Fiducial[i]/L_pp_invNb;
      CS1S_aa_rapFiducial[i]=CS1S_aa_rapFiducial[i]/(N_MB_corr * T_AA_b);
      CS1S_pp_rap2014Fiduciale[i]=CS1S_pp_rap2014Fiduciale[i]/L_pp_invNb;
      CS1S_aa_rapFiduciale[i]=CS1S_aa_rapFiduciale[i]/(N_MB_corr * T_AA_b);
      CS1S_pp_rap2014Fiducial[i]=CS1S_pp_rap2014Fiducial[i]/deltaRapEven[i];
      CS1S_aa_rapFiducial[i]=CS1S_aa_rapFiducial[i]/deltaRapEven[i];
      CS1S_pp_rap2014Fiduciale[i]=CS1S_pp_rap2014Fiduciale[i]/deltaRapEven[i];
      CS1S_aa_rapFiduciale[i]=CS1S_aa_rapFiduciale[i]/deltaRapEven[i];
      ///good ones
      CS1S_pp_rap2014[i]= computeRatio(N1S_pp_rap3p5_2014[i] , Ae_1S_pythia_rap2014[i]); 
      CS1S_aa_rap[i]= computeRatio(N1S_aa_rap3p5_2014[i] , Ae_1S_pyquen_rap2014[i]);
      CS1S_pp_rap2014e[i] = computeRatioError(N1S_pp_rap3p5_2014[i] , Ae_1S_pythia_rap2014[i] ,  N1S_pp_rap3p5_2014e[i] , Ae_1S_pythia_rap2014e[i] );
      CS1S_aa_rape[i] = computeRatioError(N1S_aa_rap3p5_2014[i] , Ae_1S_pyquen_rap2014[i] ,  N1S_aa_rap3p5_2014e[i] , Ae_1S_pyquen_rap2014e[i]); 
      CS1S_pp_rap2014[i]=CS1S_pp_rap2014[i]/L_pp_invNb;
      CS1S_aa_rap[i]=CS1S_aa_rap[i]/(N_MB_corr * T_AA_b);
      CS1S_pp_rap2014e[i]=CS1S_pp_rap2014e[i]/L_pp_invNb;
      CS1S_aa_rape[i]=CS1S_aa_rape[i]/(N_MB_corr * T_AA_b);
      CS1S_pp_rap2014[i]=CS1S_pp_rap2014[i]/(deltaRapEven[i]);
      CS1S_aa_rap[i]=CS1S_aa_rap[i]/deltaRapEven[i];
      CS1S_pp_rap2014e[i]=CS1S_pp_rap2014e[i]; ///(deltaRapEven[i]);
      CS1S_aa_rape[i]=CS1S_aa_rape[i]/deltaRapEven[i];
      //2S
      CS2S_pp_rap2014[i]= computeRatio( N2S_pp_rap4_2014[i] , Ae_2S_pythia_rap2014[i] ); 
      CS2S_pp_rap2014e[i]= computeRatioError(  N2S_pp_rap4_2014[i] , Ae_2S_pythia_rap2014[i] ,  N2S_pp_rap4_2014e[i] , Ae_2S_pythia_rap2014e[i] );
      CS2S_pp_rap2014[i]=CS2S_pp_rap2014[i]/(deltaRapEven[i] * L_pp_invNb);
      CS2S_pp_rap2014e[i]=CS2S_pp_rap2014e[i]/( L_pp_invNb);//deltaRapEven[i] *
      //3S
      CS3S_pp_rap2014[i]= computeRatio( N3S_pp_rap4_2014[i] , Aet_3S_pythia_rap2014[i] ); 
      CS3S_pp_rap2014e[i] = computeRatioError( N3S_pp_rap4_2014[i] , Aet_3S_pythia_rap2014[i] , N3S_pp_rap4_2014e[i] , 0 );
      CS3S_pp_rap2014[i]=      CS3S_pp_rap2014[i]/L_pp_invNb;
      CS3S_pp_rap2014e[i]= CS3S_pp_rap2014e[i]/L_pp_invNb;
      CS3S_pp_rap2014[i]=      CS3S_pp_rap2014[i]/(deltaRapEven[i]);
      CS3S_pp_rap2014e[i]= CS3S_pp_rap2014e[i];///(deltaRapEven[i]);
      //TAG AND PROBE COMPARISON
      //1S
      CS1S_pp_tnp_rap2014[i]= computeRatio( N1S_pp_rap3p5_2014[i] , Aet_1S_pythia_rap2014[i] ); 
      //    CS1S_pp_tnp_rap2014[i]= computeRatio( CS1S_pp_tnp_rap2014[i], t_1S_pythia_rap3p5[i] ); 
      CS1S_aa_tnp_rap2014[i]= computeRatio( N1S_aa_rap3p5_2014[i] , Aet_1S_pyquen_rap2014[i] );
      // CS1S_aa_tnp_rap2014[i]= computeRatio( CS1S_aa_tnp_rap2014[i] , t_1S_pyquen_rap3p5[i] );
       CS1S_pp_tnp_rap2014e[i] = computeRatioError(  N1S_pp_rap3p5_2014[i] , Aet_1S_pythia_rap2014[i] ,  N1S_pp_rap3p5_2014e[i] , 0);
       //  CS1S_pp_tnp_rap2014e[i] = computeRatioError(N1S_pp_rap3p5_2014[i] , Ae_1S_pythia_rap2014[i]*t_1S_pythia_rap3p5[i] ,  N1S_pp_rap3p5_2014e[i] , Ae_1S_pythia_rap2014e[i] );
      CS1S_pp_tnp_rap2014s[i] = N1S_pp_rap3p5_2014[i]*syst1S_cspp_rap[i];
      
      CS1S_aa_tnp_rap2014e[i] = computeRatioError(N1S_aa_rap3p5_2014[i] , Aet_1S_pyquen_rap2014[i] ,  N1S_aa_rap3p5_2014e[i] , 0); 
      //CS1S_aa_tnp_rap2014e[i] = computeRatioError(N1S_aa_rap3p5_2014[i] , Ae_1S_pyquen_rap2014[i]*t_1S_pyquen_rap3p5[i]  ,  N1S_aa_rap3p5_2014e[i] , Ae_1S_pyquen_rap2014e[i]); 
      CS1S_aa_tnp_rap2014s[i] =N1S_aa_rap3p5_2014[i]*syst1S_csaa_rap[i];
     
 
      CS1S_pp_tnp_rap2014[i]=CS1S_pp_tnp_rap2014[i]/L_pp_invNb;
      CS1S_aa_tnp_rap2014[i]=CS1S_aa_tnp_rap2014[i]/(N_MB_corr * T_AA_b);
      CS1S_pp_tnp_rap2014e[i]=CS1S_pp_tnp_rap2014e[i]/L_pp_invNb;
      CS1S_aa_tnp_rap2014e[i]=CS1S_aa_tnp_rap2014e[i]/(N_MB_corr * T_AA_b);
      CS1S_pp_tnp_rap2014[i]=CS1S_pp_tnp_rap2014[i]/(deltaRapEven[i]);
      CS1S_aa_tnp_rap2014[i]=CS1S_aa_tnp_rap2014[i]/deltaRapEven[i];
      CS1S_pp_tnp_rap2014e[i]=CS1S_pp_tnp_rap2014e[i]/(deltaRapEven[i]);
      CS1S_aa_tnp_rap2014e[i]=CS1S_aa_tnp_rap2014e[i]/deltaRapEven[i];
      CS1S_pp_tnp_rap2014s[i] = CS1S_pp_tnp_rap2014s[i]/(L_pp_invNb*deltaRapEven[i]);       
      CS1S_aa_tnp_rap2014s[i] = CS1S_aa_tnp_rap2014s[i]/(N_MB_corr * T_AA_b *deltaRapEven[i]); 
      //1Spt4
      CS1S_pp_tnp_rap42014[i]= computeRatio( N1S_pp_rap4_2014[i] , Aet_1S_pythia_rap4[i] ); 
      CS1S_aa_tnp_rap42014[i]= computeRatio( N1S_aa_rap4_2014[i] , Aet_1S_pyquen_rap42014[i] );
      CS1S_pp_tnp_rap42014e[i] = computeRatioError(  N1S_pp_rap4_2014[i] , Aet_1S_pythia_rap4[i] ,  N1S_pp_rap4_2014e[i] , Aet_1S_pythia_rap4e[i] );
      CS1S_pp_tnp_rap42014s[i] = N1S_pp_rap4_2014[i]*syst1S_cspp_rap4[i];
      
      CS1S_aa_tnp_rap42014e[i] = computeRatioError(N1S_aa_rap4_2014[i] , Aet_1S_pyquen_rap42014[i] ,  N1S_aa_rap4_2014e[i] , Aet_1S_pyquen_rap42014e[i]); 
      //  CS1S_aa_tnp_rap42014s[i]=N1S_aa_rap4_2014[i]*N1S_aa_rap4s[i];
      CS1S_aa_tnp_rap42014s[i] =N1S_aa_rap4_2014[i]*syst1S_csaa_rap4[i];
     
 
      CS1S_pp_tnp_rap42014[i]=CS1S_pp_tnp_rap42014[i]/L_pp_invNb;
      CS1S_aa_tnp_rap42014[i]=CS1S_aa_tnp_rap42014[i]/(N_MB_corr * T_AA_b);
      CS1S_pp_tnp_rap42014e[i]=CS1S_pp_tnp_rap42014e[i]/L_pp_invNb;
      CS1S_aa_tnp_rap42014e[i]=CS1S_aa_tnp_rap42014e[i]/(N_MB_corr * T_AA_b);
      CS1S_pp_tnp_rap42014[i]=CS1S_pp_tnp_rap42014[i]/(deltaRapEven[i]);
      CS1S_aa_tnp_rap42014[i]=CS1S_aa_tnp_rap42014[i]/deltaRapEven[i];
      CS1S_pp_tnp_rap42014e[i]=CS1S_pp_tnp_rap42014e[i]/(deltaRapEven[i]);
      CS1S_aa_tnp_rap42014e[i]=CS1S_aa_tnp_rap42014e[i]/deltaRapEven[i];
      CS1S_pp_tnp_rap42014s[i] = CS1S_pp_tnp_rap42014s[i]/(L_pp_invNb*deltaRapEven[i]);       
      CS1S_aa_tnp_rap42014s[i] = CS1S_aa_tnp_rap42014s[i]/(N_MB_corr * T_AA_b *deltaRapEven[i]); 

      //2S
      CS2S_pp_tnp_rap2014[i] = computeRatio( N2S_pp_rap4_2014[i] , Aet_2S_pythia_rap2014[i] ); 
      CS2S_pp_tnp_rap2014e[i]= computeRatioError(  N2S_pp_rap4_2014[i] , Aet_2S_pythia_rap2014[i] ,  N2S_pp_rap4_2014e[i] , 0 );
      CS2S_pp_tnp_rap2014[i] = CS2S_pp_tnp_rap2014[i]/(deltaRapEven[i] * L_pp_invNb);
      CS2S_pp_tnp_rap2014e[i]= CS2S_pp_tnp_rap2014e[i]/(deltaRapEven[i] * L_pp_invNb);
      CS2S_pp_tnp_rap2014s[i]= N2S_pp_rap4_2014[i]*syst2S_cspp_rap[i];
      CS2S_pp_tnp_rap2014s[i]= CS2S_pp_tnp_rap2014s[i]/(deltaRapEven[i] * L_pp_invNb);
      //3S
      CS3S_pp_tnp_rap2014[i]= computeRatio( N3S_pp_rap4_2014[i] ,  Aet_3S_pythia_rap2014[i] ); 
      CS3S_pp_tnp_rap2014e[i]= computeRatioError( N3S_pp_rap4_2014[i] , Aet_3S_pythia_rap2014[i] , N3S_pp_rap4_2014e[i] , 0 );
      CS3S_pp_tnp_rap2014[i]=  CS3S_pp_tnp_rap2014[i]/L_pp_invNb;
      CS3S_pp_tnp_rap2014[i]=  CS3S_pp_tnp_rap2014[i]/(deltaRapEven[i]);
      CS3S_pp_tnp_rap2014e[i]= CS3S_pp_tnp_rap2014e[i]/L_pp_invNb;
      CS3S_pp_tnp_rap2014e[i]= CS3S_pp_tnp_rap2014e[i]/(deltaRapEven[i]);
      CS3S_pp_tnp_rap2014s[i]= N3S_pp_rap4_2014[i]*syst3S_cspp_rap[i];
      CS3S_pp_tnp_rap2014s[i]= CS3S_pp_tnp_rap2014s[i]/(deltaRapEven[i] * L_pp_invNb);
      //RAAAA and other ratios!
      RAA_1S_rap[i]= computeRatio( CS1S_aa_rap[i] , CS1S_pp_rap2014[i]);
      RAA_1S_rape[i]= computeRatioError( CS1S_aa_rap[i] , CS1S_pp_rap2014[i],  CS1S_aa_rape[i] , CS1S_pp_rap2014e[i]);
      //tag and probe just after
      RAA_1S_tnp_rap[i]= computeRatio( CS1S_aa_tnp_rap2014[i] , CS1S_pp_tnp_rap2014[i]);
      RAA_1S_tnp_rape[i]= computeRatioError( CS1S_aa_tnp_rap2014[i] , CS1S_pp_tnp_rap2014[i],  CS1S_aa_tnp_rap2014e[i] ,0 );// CS1S_pp_tnp_rap2014e[i]
      RAA_1S_tnp_raps[i]= RAA_1S_tnp_rap[i]*syst1S_raa_pointRap[i];//computeRatioError( CS1S_aa_tnp_rap2014[i] , CS1S_pp_tnp_rap2014[i],  CS1S_aa_tnp_rap2014s[i] , CS1S_pp_tnp_rap2014s[i]);
      RAA_1S_tnp_rapsT[i]= RAA_1S_tnp_rap[i]*syst1S_raa_rap[i];
      //1S_pt4
      RAA_1S_tnp_rap4[i]= computeRatio( CS1S_aa_tnp_rap42014[i] , CS1S_pp_tnp_rap42014[i]);
      RAA_1S_tnp_rap4e[i]= computeRatioError( CS1S_aa_tnp_rap42014[i] , CS1S_pp_tnp_rap42014[i],  CS1S_aa_tnp_rap42014e[i] ,0); // CS1S_pp_tnp_rap42014e[i]
      RAA_1S_tnp_rap4s[i]= RAA_1S_tnp_rap4[i]*syst1S_raa_pointRap4[i];//computeRatioError( CS1S_aa_tnp_rap2014[i] , CS1S_pp_tnp_rap2014[i],  CS1S_aa_tnp_rap2014s[i] , CS1S_pp_tnp_rap2014s[i]);
      RAA_1S_tnp_rap4sT[i]= RAA_1S_tnp_rap4[i]*syst1S_raa_rap4[i];
      //
      R_A_1S_rap[i]=computeRatio(A_1S_pythia_rap3p5[i],A_1S_pyquen_rap2014[i]);
      R_A_1S_rape[i]=computeRatioError(A_1S_pythia_rap3p5[i],A_1S_pyquen_rap2014[i],A_1S_pythia_rap3p5e[i],A_1S_pyquen_rap2014e[i]);
      R_e_1S_rap[i]=computeRatio(e_1S_pythia_rap3p5[i],e_1S_pyquen_rap2014[i]);
      R_e_1S_rape[i]=computeRatioError(e_1S_pythia_rap3p5[i],e_1S_pyquen_rap2014[i],e_1S_pythia_rap3p5e[i],e_1S_pyquen_rap2014e[i]);
      
    }


cout << "  --- 1S Cross section in pp vs. y ---" << endl;
 for(int j =0 ; j<nRapBins_2014 ; j++)
   {
     cout <<"j= "<< (binsRap[j]).c_str() << " & " << setprecision(3) << CS1S_pp_tnp_rap2014[j] <<" \\pm "<<CS1S_pp_tnp_rap2014e[j]  <<" \\pm "<<CS1S_pp_tnp_rap2014s[j] <<" & " << endl;
   }

cout << "  --- 1S Cross section in pp vs. pt ---" << endl;
 for(int j =0 ; j<nPtBins_2013 ; j++)
   {
    cout <<"j= "<< (binsPt[j]).c_str() << " & " << CS1S_pp_tnp_pt[j] <<"\\pm "<<CS1S_pp_tnp_pte[j]  <<" \\pm "<<CS1S_pp_tnp_pts[j]<<" \\" << endl;
   }

cout << "  --- 1S pt4 Cross section in pp vs. y ---" << endl;
 for(int j =0 ; j<nRapBins_2014 ; j++)
   {
     cout <<"j= "<< (binsRap[j]).c_str() << " & "  << CS1S_pp_tnp_rap42014[j] <<" \\pm "<<CS1S_pp_tnp_rap42014e[j]  <<" \\pm "<<CS1S_pp_tnp_rap42014s[j] <<" & " << endl;
   }

 
cout << "  --- 1S pt4 Cross section in pp vs. pt ---" << endl;
 for(int j =0 ; j<nPtBins_2013 ; j++)
   {
     cout <<"j= "<< (binsPt[j]).c_str() <<setprecision(3) <<" & " << CS1S_pp_tnp_pt4[j] <<"\\pm "<<CS1S_pp_tnp_pt4e[j]  <<" \\pm "<<CS1S_pp_tnp_pt4s[j]<<" \\" << endl;
   }

cout << "  --- 1S pt4 Cross section in AA vs. y ---" << endl;
 for(int j =0 ; j<nRapBins_2014 ; j++)
   {
     cout <<"j= "<< (binsRap[j]).c_str() <<setprecision(3)<< " & "  << CS1S_aa_tnp_rap42014[j] <<" \\pm "<<CS1S_aa_tnp_rap42014e[j]  <<" \\pm "<<CS1S_aa_tnp_rap42014s[j] <<" & " << endl;
   }


cout << "  --- 1S pt4 Cross section in AA vs. pt ---" << endl;
 for(int j =0 ; j<nPtBins_2013 ; j++)
   {
    cout <<"j= "<< (binsPt[j]).c_str() <<setprecision(3)<< " & " << CS1S_aa_tnp_pt4[j] <<"\\pm "<<CS1S_aa_tnp_pt4e[j]  <<" \\pm "<<CS1S_aa_tnp_pt4s[j]<<" \\" << endl;
   }


cout << "  --- 1S Cross section in PbPb vs. y ---" << endl;
 for(int j =0 ; j<nRapBins_2014 ; j++)
   {
    cout <<"j= "<< (binsRap[j]).c_str() << " & " << CS1S_aa_tnp_rap2014[j] <<" \\pm "<<CS1S_aa_tnp_rap2014e[j] <<" \\pm "<<CS1S_aa_tnp_rap2014s[j]<<" \\" << endl;
   }

cout << "  --- 1S Cross section in PbPb vs. pt ---" << endl;
 for(int j =0 ; j<nPtBins_2013 ; j++)
   {
    cout <<"j= "<< (binsPt[j]).c_str() << " & "<< CS1S_aa_tnp_pt[j] <<" \\pm "<<CS1S_aa_tnp_pte[j]  <<" \\pm "<<CS1S_aa_tnp_pts[j] <<" \\" << endl;
   }

cout << "  --- 1S RAA vs. p_{T} ---" << endl;
 for(int j =0 ; j<nPtBins_2013 ; j++)
   {
    cout <<"j= "<< (binsPt[j]).c_str() << " & "<< RAA_1S_tnp_pt[j] <<" \\pm "<< RAA_1S_tnp_pte[j] <<" \\pm "<< RAA_1S_tnp_ptsT[j]<< endl;
   }

cout << "  --- 1S RAA vs. y ---" << endl;
 for(int j =0 ; j<nRapBins_2014 ; j++)
   {
    cout <<"j= "<< (binsRap[j]).c_str() << " & "<< RAA_1S_tnp_rap[j] <<" \\pm "<< RAA_1S_tnp_rape[j]<<" \\pm "<< RAA_1S_tnp_rapsT[j]<< endl;
   }
cout << "  --- 1S pt4 RAA vs. p_{T} ---" << endl;
 for(int j =0 ; j<nPtBins_2013 ; j++)
   {
    cout <<"j= "<< (binsPt[j]).c_str() << " & "<< RAA_1S_tnp_pt4[j] <<" \\pm "<< RAA_1S_tnp_pt4e[j] <<" \\pm "<< RAA_1S_tnp_pt4sT[j]<< endl;
   }

cout << "  --- 1S pt4 RAA vs. y ---" << endl;
 for(int j =0 ; j<nRapBins_2014 ; j++)
   {
    cout <<"j= "<< (binsRap[j]).c_str() << " & "<< RAA_1S_tnp_rap4[j] <<" \\pm "<< RAA_1S_tnp_rap4e[j]<<" \\pm "<< RAA_1S_tnp_rap4sT[j]<< endl;
   }

 for(int i=0 ; i<nRapBins_2010; i++)
   {
     //significance, non-believers!
     SigOverErr_aaRap2S4[i]=computeRatio(N2S_aa_rap4_2014Large[i],N2S_aa_rap4_2014Largee[i]);
     SigOverErr_aaRap2S3p5[i]=computeRatio(N2S_aa_rap3p5[i],N2S_aa_rap3p5e[i]);
     //    CS2S_pp_rap[i]= computeRatio( N2S_pp_rap3p5[i] , Ae_2S_pythia_rap[i] ); 
     // CS2S_pp_rap[i]= computeRatio( N2S_pp_rap4_2014Large[i] , Ae_2S_pythia_rap2010[i] ); 
     // CS2S_aa_rap[i]= computeRatio( N2S_aa_rap4_2014Large[i] , Ae_2S_pyquen_rap[i] );
     //plot tnp
     CS2S_pp_tnp_rap[i]= computeRatio( N2S_pp_rap4_2014Large[i] , Aet_2S_pythia_rap2014Large[i] ); 
     CS2S_aa_tnp_rap[i]= computeRatio( N2S_aa_rap4_2014Large[i] , Aet_2S_pyquen_rap2014Large[i] );
     CS2S_aa_tnp_raps[i]= N2S_aa_rap4_2014Large[i]*syst2S_csaa_rap[i];
     CS2S_pp_tnp_raps[i]= N2S_pp_rap4_2014Large[i]*syst2S_cspp_rapLarge[i];
     //
     // CS2S_pp_rape[i] = computeRatioError(  N2S_pp_rap4_2014Large[i] , Ae_2S_pythia_rap2010[i] ,  N2S_pp_rap4_2014Largee[i] , Ae_2S_pythia_rap2010e[i] );
     // CS2S_aa_rape[i] = computeRatioError(   N2S_aa_rap4_2014Large[i] , Ae_2S_pyquen_rap[i] ,  N2S_aa_rap4_2014Largee[i] , Ae_2S_pyquen_rape[i]);
     //tnp
     CS2S_pp_tnp_rape[i] = computeRatioError(  N2S_pp_rap4_2014Large[i] , Aet_2S_pythia_rap2014Large[i] ,  N2S_pp_rap4_2014Largee[i] , Aet_2S_pythia_rap2014Largee[i] );
     CS2S_aa_tnp_rape[i] = computeRatioError(  N2S_aa_rap4_2014Large[i] , Aet_2S_pyquen_rap2014Large[i] ,  N2S_aa_rap4_2014Largee[i] , Aet_2S_pyquen_rap2014Largee[i]);
     CS2S_pp_tnp_rap[i]=CS2S_pp_tnp_rap[i]/(L_pp_invNb*deltaRap2010[i]);
     CS2S_aa_tnp_rap[i]=CS2S_aa_tnp_rap[i]/(N_MB_corr * T_AA_b * deltaRap2010[i]);
     CS2S_pp_tnp_rape[i]=CS2S_pp_tnp_rape[i]/(L_pp_invNb*deltaRap2010[i]);
     CS2S_aa_tnp_rape[i]=CS2S_aa_tnp_rape[i]/(N_MB_corr * T_AA_b * deltaRap2010[i]);
     CS2S_aa_tnp_raps[i]=CS2S_aa_tnp_raps[i]/(N_MB_corr * T_AA_b * deltaRap2010[i]);
     CS2S_pp_tnp_raps[i]=CS2S_pp_tnp_raps[i]/((L_pp_invNb*deltaRap2010[i]));
     RAA_2S_rap[i]= computeRatio( CS2S_aa_tnp_rap[i] , CS2S_pp_tnp_rap[i]);
     RAA_2S_rape[i]= computeRatioError( CS2S_aa_tnp_rap[i] , CS2S_pp_tnp_rap[i],  CS2S_aa_tnp_rape[i] , CS2S_pp_tnp_rape[i]);
     RAA_2S_tnp_rap[i]=RAA_2S_rap[i];
     RAA_2S_tnp_rape[i]=RAA_2S_rape[i];
     RAA_2S_tnp_raps[i]=RAA_2S_tnp_rap[i]*syst2S_raa_pointRap[i]; //computeRatioError( CS2S_aa_tnp_rap[i] , CS2S_pp_tnp_rap[i],  CS2S_aa_tnp_raps[i] , CS2S_pp_tnp_raps[i]);
     RAA_2S_tnp_rapsT[i]=RAA_2S_tnp_rap[i]*syst2S_raa_rap[i];
     //keeping it just in case i need to copy to compare with tnp in large bins as well.
     // CS2S_pp_rap[i]= computeRatio( N2S_pp_rap4_2014Large[i] , Ae_2S_pythia_rap2010[i] ); 
     // CS2S_aa_rap[i]= computeRatio( N2S_aa_rap4_2014Large[i] , Ae_2S_pyquen_rap[i] );
     // CS2S_pp_rape[i] = computeRatioError(  N2S_pp_rap4_2014Large[i] , Ae_2S_pythia_rap2010[i] ,  N2S_pp_rap4_2014Largee[i] , Ae_2S_pythia_rap2010e[i] );
     // CS2S_aa_rape[i] = computeRatioError(   N2S_aa_rap4_2014Large[i] , Ae_2S_pyquen_rap[i] ,  N2S_aa_rap4_2014Largee[i] , Ae_2S_pyquen_rape[i]);
     // CS2S_pp_rap[i]=CS2S_pp_rap[i]/(L_pp_invNb*deltaRap2010[i]);
     // CS2S_aa_rap[i]=CS2S_aa_rap[i]/(N_MB_corr * T_AA_b * deltaRap2010[i]);
     // CS2S_pp_rape[i]=CS2S_pp_rape[i]/(L_pp_invNb*deltaRap2010[i]);
     // CS2S_aa_rape[i]=CS2S_aa_rape[i]/(N_MB_corr * T_AA_b * deltaRap2010[i]);
 }
 
 for(int i = 0 ; i<nPtBins_2010 ; i++)
   {
     //significance, shitty non-believers
     SigOverErr_aaPt2S4[i]=computeRatio(N2S_aa_pt4_2013Large[i],N2S_aa_pt4_2013Largee[i]);
     SigOverErr_aaPt2S3p5[i]=computeRatio(N2S_aa_pt3p5[i],N2S_aa_pt3p5e[i]);
     CS1S_pp_ptLarge[i]=computeRatio(N1S_pp_pt3p5Large[i], Aet_1S_pythia_ptLarge[i]);
     CS1S_pp_pteLarge[i]=computeRatioError(N1S_pp_pt3p5Large[i], Aet_1S_pythia_ptLargee[i],N1S_pp_pt3p5Largee[i], Aet_1S_pythia_ptLargee[i]);
     CS1S_aa_ptLarge[i]=computeRatio(N1S_aa_pt3p5Large[i],Aet_1S_pyquen_ptLarge[i]);
     CS1S_aa_pteLarge[i]=computeRatioError(N1S_aa_pt3p5Large[i],Aet_1S_pyquen_ptLarge[i],N1S_aa_pt3p5eLarge[i],Aet_1S_pyquen_ptLargee[i]);
     //   CS1S_pp_ptLarge[i]=computeRatio(N1S_pp_pt3p5Large[i],N1S_aa_pt3p5Large[i]);
     CS1S_pp_ptLarge[i]=CS1S_pp_ptLarge[i]/(RapBinWidth*L_pp_invNb*deltaPt_2010[i]);
     CS1S_aa_ptLarge[i]=CS1S_aa_ptLarge[i]/(RapBinWidth*N_MB_corr*T_AA_b*deltaPt_2010[i]);
     CS1S_pp_pteLarge[i]=CS1S_pp_pteLarge[i]/(RapBinWidth*L_pp_invNb*deltaPt_2010[i]);
     CS1S_aa_pteLarge[i]=CS1S_aa_pteLarge[i]/(RapBinWidth*N_MB_corr*T_AA_b*deltaPt_2010[i]);
     //invariant yields.
     // CS2S_pp_pt[i]= computeRatio( N2S_pp_pt4_2013Large[i] , Ae_2S_pythia_pt2010[i] ); 
     // CS2S_aa_pt[i]= computeRatio( N2S_aa_pt4_2013Large[i] , Ae_2S_pyquen_pt[i] );
     // CS2S_pp_pte[i]= computeRatioError( N2S_pp_pt4_2013Large[i] , Ae_2S_pythia_pt2010[i], N2S_pp_pt4_2013Largee[i] , Ae_2S_pythia_pt2010e[i]);
     // CS2S_aa_pte[i]= computeRatioError(  N2S_aa_pt4_2013Large[i] , Ae_2S_pyquen_pt[i] ,  N2S_aa_pt4_2013Largee[i] , Ae_2S_pyquen_pte[i] );

     CS2S_pp_pt[i]= computeRatio( N2S_pp_pt4_2013Large[i] , Aet_2S_pythia_pt2013Large[i] ); 
     CS2S_aa_pt[i]= computeRatio( N2S_aa_pt4_2013Large[i] , Aet_2S_pyquen_pt2013Large[i] );
     CS2S_pp_pte[i]= computeRatioError( N2S_pp_pt4_2013Large[i] , Aet_2S_pythia_pt2013Large[i],N2S_pp_pt4_2013Largee[i], Aet_2S_pythia_pt2013Largee[i]);
     CS2S_aa_pte[i]= computeRatioError(  N2S_aa_pt4_2013Large[i] , Aet_2S_pyquen_pt2013Large[i] ,  N2S_aa_pt4_2013Largee[i] , Aet_2S_pyquen_pt2013Largee[i] );
     CS2S_pp_pts[i]= N2S_pp_pt4_2013Large[i]*syst2S_cspp_ptLarge[i];
     CS2S_aa_pts[i]=N2S_aa_pt4_2013Large[i]*syst2S_csaa_pt[i];
     // here, changed a few things.from 4 to 3p5.
     CS2S_aa_pts[i]=  CS2S_aa_pts[i]/(N_MB_corr * T_AA_b*RapBinWidth);
     CS2S_pp_pt[i]=CS2S_pp_pt[i]/(RapBinWidth*L_pp_invNb*deltaPt_2010[i]);
     CS2S_pp_pts[i]=CS2S_pp_pts[i]/(RapBinWidth*L_pp_invNb*deltaPt_2010[i]);
     CS2S_aa_pt[i]=CS2S_aa_pt[i]/(N_MB_corr * T_AA_b*RapBinWidth*deltaPt_2010[i]);
     CS2S_pp_pte[i]=CS2S_pp_pte[i]/(RapBinWidth*L_pp_invNb*deltaPt_2010[i]);
     CS2S_aa_pte[i]=CS2S_aa_pte[i]/(N_MB_corr * T_AA_b * RapBinWidth * deltaPt_2010[i]);
     // cout<<"cs1S (ppPt, ppRap, aaPt, aaRap)"<< CS2S_pp_pt[i] <<", " <<CS2S_pp_rap[i] <<", " <<CS2S_aa_pt[i] <<", " <<CS2S_aa_rap[i] <<". " << endl;
     // cout <<"sigma(2S)_pp vs Pt ="<< endl;
     //invariant yields, corrected by taa and lumi corr.
     RAA_1S_ptLarge[i]=computeRatio(CS1S_aa_ptLarge[i],CS1S_pp_ptLarge[i]); 
     RAA_1S_pteLarge[i]=computeRatioError(CS1S_aa_ptLarge[i],CS1S_pp_ptLarge[i],CS1S_aa_pteLarge[i],CS1S_pp_pteLarge[i]); 
     RAA_2S_pt[i]= computeRatio( CS2S_aa_pt[i] , CS2S_pp_pt[i]);
     RAA_2S_pte[i] =computeRatioError( CS2S_aa_pt[i] , CS2S_pp_pt[i], CS2S_aa_pte[i] , CS2S_pp_pte[i]);
     RAA_2S_tnp_pt[i]=RAA_2S_pt[i];
     RAA_2S_tnp_pte[i]=RAA_2S_pte[i];
     RAA_2S_tnp_pts[i]=RAA_2S_pt[i]*syst2S_raa_pointPt[i];//computeRatioError( CS2S_aa_pt[i] , CS2S_pp_pt[i], CS2S_aa_pts[i] , CS2S_pp_pts[i]);
     RAA_2S_tnp_ptsT[i]=RAA_2S_pt[i]*syst2S_raa_pt[i];//computeRatioError( CS2S_aa_pt[i] , CS2S_pp_pt[i], CS2S_aa_pts[i] , CS2S_pp_pts[i]);
   }

 cout << "  --- 2S Cross section in pp vs. y in large bins---" << endl;
 for(int j =0 ; j<nRapBins_2010 ; j++)
   {
     cout <<"j="<< j << "' ,sigma(2S)_pp = "<< CS2S_pp_tnp_rap[j] <<" \\pm "<<CS2S_pp_tnp_rape[j]<<" \\pm "<<CS2S_pp_tnp_raps[j]<<" \\"  << endl;
   }

cout << "  --- 2S Cross section in pp vs. pt in large bins---" << endl;
 for(int j =0 ; j<nPtBins_2010 ; j++)
   {
     cout <<"j="<< j << "' ,sigma(2S)_pp = "<< CS2S_pp_pt[j] <<" \\pm "<<CS2S_pp_pte[j] <<" \\pm " <<CS2S_pp_pts[j] <<" \\" << endl;
   }


cout << "  --- 2S Cross section in PbPb vs. y ---" << endl;
 for(int j =0 ; j<nRapBins_2010 ; j++)
   {
     cout <<"j="<< j << "' ,sigma(2S)_PbPb = "<< CS2S_aa_tnp_rap[j] <<" \\pm "<<CS2S_aa_tnp_rape[j] << " \\pm "<<CS2S_aa_tnp_raps[j]<<" \\" << endl;
   }

cout << "  --- 2S Cross section in PbPb vs. pt ---" << endl;
 for(int j =0 ; j<nPtBins_2010 ; j++)
   {
     cout <<"j="<< j << "' ,sigma(2S)_PbPb = "<< CS2S_aa_pt[j] <<" \\pm "<<CS2S_aa_pte[j]<< " \\pm "<<CS2S_aa_pts[j]<< " \\" << endl;
   }

cout << "  --- 1S RAA vs. p_{T} in LARGE BINS---" << endl;
 for(int j =0 ; j<nPtBins_2010 ; j++)
   {
     cout <<"j="<< j << "' , Raa = "<< RAA_1S_ptLarge[j] <<" \\pm "<< RAA_1S_pteLarge[j]<< endl;
   }

cout << "  --- 2S RAA vs. p_{T} ---" << endl;
 for(int j =0 ; j<nPtBins_2010 ; j++)
   {
     cout <<"j="<< j << "' , Raa = "<< RAA_2S_pt[j] <<" \\pm "<< RAA_2S_pte[j]<<" \\pm "<< RAA_2S_tnp_ptsT[j]<< endl;
   }

cout << "  --- 2S RAA vs. y ---" << endl;
 for(int j =0 ; j<nRapBins_2010 ; j++)
   {
     cout <<"j="<< j << "' , Raa = "<< RAA_2S_rap[j] <<" \\pm "<< RAA_2S_rape[j]<< " \\pm "<< RAA_2S_tnp_rapsT[j]<< endl;
   }

 //for the cross sections in pp : shorter bins


cout << "  --- 2S Cross section in pp vs. pt short bins---" << endl;
 for(int j =0 ; j<nPtBins_2013 ; j++)
   {
     cout <<"j= "<< (binsPt[j]).c_str() << " & " << CS2S_pp_tnp_pt2013[j] <<" \\pm "<<CS2S_pp_tnp_pt2013e[j]<<" \\pm "<<CS2S_pp_tnp_pts[j]<<"  &" << endl;
   }

cout << "  --- 2S Cross section in pp vs. y short bins---" << endl;
 for(int j =0 ; j<nRapBins_2014 ; j++)
   {
     cout <<"j= "<< (binsRap[j]).c_str() << " & " << CS2S_pp_tnp_rap2014[j] <<" \\pm "<<CS2S_pp_tnp_rap2014e[j]<<" \\pm "<<CS2S_pp_tnp_rap2014s[j]<<"  &" << endl;
   }

cout << "  --- 3S Cross section in pp vs. pt short bins---" << endl;
 for(int j =0 ; j<nPtBins_2013 ; j++)
   {
     cout <<"j= "<< (binsPt[j]).c_str() << " & " << CS3S_pp_tnp_pt2013[j] <<" \\pm "<<CS3S_pp_tnp_pt2013e[j]<<" \\pm "<<CS3S_pp_tnp_pts[j]<<"  &" << endl;
   }

cout << "  --- 3S Cross section in pp vs. y short bins---" << endl;
 for(int j =0 ; j<nRapBins_2014 ; j++)
   {
     cout <<"j= "<< (binsRap[j]).c_str() << " & " << CS3S_pp_tnp_rap2014[j] <<" \\pm "<<CS3S_pp_tnp_rap2014e[j]<<" \\pm "<<CS3S_pp_tnp_rap2014s[j]<<"  &" << endl;
   }
 ///plotting TNP corrections vs pt, rap, cent.
 if(plotTNP){
   float et_1S_pyquen_pt[nPtBins_2013]={};
   float et_1S_pythia_pt[nPtBins_2013]={};
   for(int i=0; i<nPtBins_2013;i++){
     // et_1S_pyquen_pt[i]=Aet_1S_pyquen_pt[i]/A_1S_pyquen_pt[i];
     // et_1S_pythia_pt[i]=Aet_1S_pythia_pt[i]/A_1S_pythia_pt3p5[i];
     et_1S_pyquen_pt[i]=e_1S_pyquen_pt[i]*t_1S_pyquen_pt3p5[i]; 
     et_1S_pythia_pt[i]=e_1S_pythia_pt3p5[i]*t_1S_pythia_pt3p5[i];

   }
   TCanvas *cTNP = new TCanvas("cTNP","cTNP");
   cTNP->cd();
   TPad *pTNP = new TPad("pTNP","pTNP",0.0,0.0,1.0,1.0);
   // pSignificance1->SetBottomMargin(0.12);
   // pSignificance1->SetTopMargin(0.03);
   // pSignificance1->SetRightMargin(0.03);
   // pSignificance1->SetLeftMargin(0.16);
   //   pSignificance1->SetLogy();
   TF1 *f4Significance = new TF1("f4Significance","1",0,20);
   f4Significance->SetLineWidth(0);
   f4Significance->GetYaxis()->SetTitleOffset(1.05);
   f4Significance->GetYaxis()->SetRangeUser(0,1);
   f4Significance->GetXaxis()->SetTitle("p_{T}^{#mu#mu}");
   f4Significance->GetXaxis()->SetTitleSize(0.048);		
   f4Significance->GetYaxis()->SetTitle("Efficiency");
   f4Significance->GetYaxis()->SetTitleSize(0.048);
   f4Significance->GetXaxis()->CenterTitle(kTRUE);
   f4Significance->Draw();

   TGraph *g1AA = new TGraph(nPtBins_2013,ptShift,et_1S_pyquen_pt);
   g1AA->SetMarkerColor(kBlue);
   g1AA->SetMarkerStyle(22);
   g1AA->SetMarkerSize(1.4);
   g1AA->Draw("pe");

   TGraph *g1pp = new TGraph(nPtBins_2013,pt,et_1S_pythia_pt);
   g1pp->SetMarkerColor(kRed);
   g1pp->SetMarkerStyle(22);
   g1pp->SetMarkerSize(1.4);
   g1pp->Draw("pe");

   TGraph *g1AA_noCorr = new TGraph(nPtBins_2013,ptShift,e_1S_pyquen_pt);
   g1AA_noCorr->SetMarkerColor(kBlue);
   g1AA_noCorr->SetMarkerStyle(20);
   g1AA_noCorr->SetMarkerSize(1.4);
   g1AA_noCorr->Draw("pe");

   TGraph *g1pp_noCorr = new TGraph(nPtBins_2013,pt,e_1S_pythia_pt3p5);
   g1pp_noCorr->SetMarkerColor(kRed);
   g1pp_noCorr->SetMarkerStyle(20);
   g1pp_noCorr->SetMarkerSize(1.4);
   g1pp_noCorr->Draw("pe");
   
   TLegend *legend = new TLegend(0.45,0.3,0.88,0.45);
   legend->SetTextSize(0.029);
   legend->SetFillStyle(0);
   legend->SetFillColor(0);
   legend->SetBorderSize(0);
   legend->SetTextFont(42);
   legend->AddEntry(g1pp_noCorr,"#varUpsilon(1S) pp Reco, MC truth","lp");
   legend->AddEntry(g1pp,"#varUpsilon(1S) pp Reco, T&P corrected ","lp");
   legend->AddEntry(g1AA_noCorr,"#varUpsilon(1S) HI Reco, MC truth","lp");
   legend->AddEntry(g1AA,"#varUpsilon(1S) HI Reco, T&P corrected ","lp");

 
   legend->Draw();
   cTNP->SaveAs("~/Desktop/TnPCorrection_Pt.png");
   cTNP->SaveAs("~/Documents/PR/forTWiki/CSandRAA/TnPCorrection_Pt.pdf");

   float et_1S_pyquen_rap2014[nRapBins_2014]={};
   float et_1S_pythia_rap2014[nRapBins_2014]={};
   for(int i=0; i<nRapBins_2014;i++){
     // et_1S_pyquen_rap2014[i]=Aet_1S_pyquen_rap2014[i]/A_1S_pyquen_rap2014[i];
     // et_1S_pythia_rap2014[i]=Aet_1S_pythia_rap2014[i]/A_1S_pythia_rap3p5[i];
     et_1S_pyquen_rap2014[i]=e_1S_pyquen_rap2014[i]*t_1S_pyquen_rap3p5[i];
     et_1S_pythia_rap2014[i]=e_1S_pythia_rap3p5[i]*t_1S_pythia_rap3p5[i];

   }
   TCanvas *cTNP2 = new TCanvas("cTNP2","cTNP2");
   cTNP2->cd();
   TPad *rapNP = new TPad("rapNP","rapNP",0.0,0.0,1.0,1.0);
   // pSignificance1->SetBottomMargin(0.12);
   // pSignificance1->SetTopMargin(0.03);
   // pSignificance1->SetRightMargin(0.03);
   // pSignificance1->SetLeftMargin(0.16);
   //   pSignificance1->SetLogy();
   TF1 *f4Significance = new TF1("f4Significance","1",0,2.4);
   f4Significance->SetLineWidth(0);
   f4Significance->GetYaxis()->SetTitleOffset(1.05);
   f4Significance->GetYaxis()->SetRangeUser(0,1);
   f4Significance->GetXaxis()->SetTitle("y");	
   f4Significance->GetXaxis()->SetTitleSize(0.048);	
   f4Significance->GetYaxis()->SetTitle("Efficiency");
   f4Significance->GetYaxis()->SetTitleSize(0.048);
   f4Significance->GetXaxis()->CenterTitle(kTRUE);
   f4Significance->Draw();

   TGraph *g1AA = new TGraph(nRapBins_2014,rap2014Shift,et_1S_pyquen_rap2014);
   g1AA->SetMarkerColor(kBlue);
   g1AA->SetMarkerStyle(22);
   g1AA->SetMarkerSize(1.4);
   g1AA->Draw("pe");

   TGraph *g1pp = new TGraph(nRapBins_2014,rap2014,et_1S_pythia_rap2014);
   g1pp->SetMarkerColor(kRed);
   g1pp->SetMarkerStyle(22);
   g1pp->SetMarkerSize(1.4);
   g1pp->Draw("pe");

   TGraph *g1AA_noCorr = new TGraph(nRapBins_2014,rap2014Shift,e_1S_pyquen_rap2014);
   g1AA_noCorr->SetMarkerColor(kBlue);
   g1AA_noCorr->SetMarkerStyle(20);
   g1AA_noCorr->SetMarkerSize(1.4);
   g1AA_noCorr->Draw("pe");

   TGraph *g1pp_noCorr = new TGraph(nRapBins_2014,rap2014,e_1S_pythia_rap3p5);
   g1pp_noCorr->SetMarkerColor(kRed);
   g1pp_noCorr->SetMarkerStyle(20);
   g1pp_noCorr->SetMarkerSize(1.4);
   g1pp_noCorr->Draw("pe");
   
   TLegend *legend = new TLegend(0.45,0.3,0.88,0.45);
   legend->SetTextSize(0.029);
   legend->SetFillStyle(0);
   legend->SetFillColor(0);
   legend->SetBorderSize(0);
   legend->SetTextFont(42);
   legend->AddEntry(g1pp_noCorr,"#varUpsilon(1S) pp Reco, MC truth","lp");
   legend->AddEntry(g1pp,"#varUpsilon(1S) pp Reco, T&P corrected ","lp");			     
   legend->AddEntry(g1AA_noCorr,"#varUpsilon(1S) HI Reco, MC truth","lp");
   legend->AddEntry(g1AA,"#varUpsilon(1S) HI Reco, T&P corrected ","lp");

   legend->Draw();
   cTNP2->SaveAs("~/Desktop/TnPCorrection_Rap.png");
   cTNP2->SaveAs("~/Documents/PR/forTWiki/CSandRAA/TnPCorrection_Rap.pdf");
 }
 if(plotSignificance)
   {
 
     TCanvas *cSignificance = new TCanvas("cSignficance","cSignificance"); 
     cSignificance->cd();
     TPad *pSignificance1 = new TPad("pSignificance1","pSignificance1",0.0,0.0,1.0,1.0);
     pSignificance1->SetBottomMargin(0.12);
     pSignificance1->SetTopMargin(0.03);
     pSignificance1->SetRightMargin(0.03);
     pSignificance1->SetLeftMargin(0.16);
     //   pSignificance1->SetLogy();
     pSignificance1->Draw();
     pSignificance1->cd();
     TF1 *f4Significance = new TF1("f4Significance","0",0,5);
     f4Significance->SetLineWidth(0);
     f4Significance->GetYaxis()->SetTitleOffset(1.5);
     f4Significance->GetYaxis()->SetRangeUser(0,35);
     f4Significance->GetXaxis()->SetTitle("Pt Bin Number");		
     f4Significance->GetYaxis()->SetTitle("Significance");
     f4Significance->GetYaxis()->SetTitleSize(0.038);
     f4Significance->GetXaxis()->CenterTitle(kTRUE);
     f4Significance->Draw();

     TGraph *g1 = new TGraph(nPtBins_2013,fiveBins,SigOverErr_ppPt1S3p5);
     g1->SetMarkerColor(kBlue);
     g1->SetMarkerStyle(21);
     g1->SetMarkerSize(2);
     g1->Draw("pe");

     TGraph *g2 = new TGraph(nPtBins_2013,fiveBins,SigOverErr_aaPt1S3p5);
     g2->SetMarkerColor(kOrange+1);
     g2->SetMarkerStyle(21);
     g2->SetMarkerSize(2);
     g2->Draw("pe");
     
     TGraph *g3 = new TGraph(nPtBins_2013,fiveBins,SigOverErr_ppPt1S4);
     g3->SetMarkerColor(kBlue);
     g3->SetMarkerStyle(29);
     g3->SetMarkerSize(2);
     g3->Draw("pe");

     TGraph *g4 = new TGraph(nPtBins_2013,fiveBins,SigOverErr_aaPt1S4);
     g4->SetMarkerColor(kOrange+1);
     g4->SetMarkerStyle(29);
     g4->SetMarkerSize(2);
     g4->Draw("pe");

     TLegend *legend = new TLegend(0.6,0.7,0.8,0.9);
     legend->SetTextSize(0.029);
     legend->SetFillStyle(0);
     legend->SetFillColor(0);
     legend->SetBorderSize(0);
     legend->SetTextFont(42);
     legend->AddEntry(g1,"1S pp vs pT, loose","lp");
     legend->AddEntry(g3,"1S pp vs pT, tight","lp");
     legend->AddEntry(g2,"1S PbPb vs pT, loose","lp");
     legend->AddEntry(g4,"1S PbPb vs pT, tight","lp");
     legend->Draw();
     cSignificance->SaveAs("~/Desktop/cSignificance_Pt.png");
     cSignificance->SaveAs("~/Documents/PR/forTWiki/CSandRAA/cSignificance_Pt.pdf");
   
     TCanvas *cSignificance2 = new TCanvas("cSignficance2","cSignificance2"); 
     cSignificance2->cd();
     TPad *pSignificance2 = new TPad("pSignificance2","pSignificance2",0.0,0.0,1.0,1.0);
     pSignificance2->SetBottomMargin(0.12);
     pSignificance2->SetTopMargin(0.03);
     pSignificance2->SetRightMargin(0.03);
     pSignificance2->SetLeftMargin(0.16);
     //   pSignificance2->SetLogy();
     pSignificance2->Draw();
     pSignificance2->cd();
     TF1 *f4Significance = new TF1("f4Significance","3",0,6);
     f4Significance->SetLineWidth(0);
     f4Significance->GetYaxis()->SetTitleOffset(1.5);
     f4Significance->GetYaxis()->SetRangeUser(0,35);
     f4Significance->GetXaxis()->SetTitle("Rap Bin Number");		
     f4Significance->GetYaxis()->SetTitle("Significance");
     f4Significance->GetYaxis()->SetTitleSize(0.038);
     f4Significance->GetXaxis()->CenterTitle(kTRUE);
     f4Significance->Draw();
     TGraph *g5 = new TGraph(nRapBins_2014,sixBins,SigOverErr_ppRap1S3p5);
     g5->SetMarkerColor(kBlue);
     g5->SetMarkerStyle(21);
     g5->SetMarkerSize(2);
     g5->Draw("pe");

     TGraph *g6 = new TGraph(nRapBins_2014,sixBins,SigOverErr_aaRap1S3p5);
     g6->SetMarkerColor(kOrange+1);
     g6->SetMarkerStyle(21);
     g6->SetMarkerSize(2);
     g6->Draw("pe");
     
     TGraph *g7 = new TGraph(nRapBins_2014,sixBins,SigOverErr_ppRap1S4);
     g7->SetMarkerColor(kBlue);
     g7->SetMarkerStyle(29);
     g7->SetMarkerSize(2);
     g7->Draw("pe");

     TGraph *g8 = new TGraph(nRapBins_2014,sixBins,SigOverErr_aaRap1S4);
     g8->SetMarkerColor(kOrange+1);
     g8->SetMarkerStyle(29);
     g8->SetMarkerSize(2);
     g8->Draw("pe");

     TLegend *legend = new TLegend(0.65,0.7,0.85,0.9);
     legend->SetTextSize(0.029);
     legend->SetFillStyle(0);
     legend->SetFillColor(0);
     legend->SetBorderSize(0);
     legend->SetTextFont(42);
     legend->AddEntry(g5,"1S pp vs y, loose","lp");
     legend->AddEntry(g7,"1S pp vs y, tight","lp");
     legend->AddEntry(g6,"1S PbPb vs y, loose","lp");
     legend->AddEntry(g8,"1S PbPb vs y, tight","lp");
     legend->Draw();
     cSignificance2->SaveAs("~/Desktop/cSignificance_Rap.png");
     cSignificance2->SaveAs("~/Documents/PR/forTWiki/CSandRAA/cSignificance_Rap.pdf");
   }
 if(plotCS){
 ////////////////////////////////////////////////////////////////
 /// drawing Pt-binned Data
 ////////////////////////////////////////////////////////////////
 
 TCanvas *cpt = new TCanvas("cpt","cpt"); 
 cpt->cd();
 TPad *ppt1 = new TPad("ppt1","ppt1",0.0,0.0,1.0,1.0);
 ppt1->SetBottomMargin(0.12);
 ppt1->SetTopMargin(0.03);
 ppt1->SetRightMargin(0.03);
 ppt1->SetLeftMargin(0.16);
 ppt1->SetLogy();
 ppt1->Draw();
 ppt1->cd();
 TF1 *f4Pt = new TF1("f4Pt","0.4",0,21);
 f4Pt->SetLineWidth(0);
 f4Pt->GetYaxis()->SetTitleOffset(1.5);
 f4Pt->GetXaxis()->SetTitle("p_{T}^{#varUpsilon} (GeV/c)");		
 f4Pt->GetYaxis()->SetTitle("(#frac{1}{L_{pp}}, #frac{1}{T_{AA}N_{MB}})#frac{d^{2}N}{A#varepsilon dy dp_{T}}  [nb/(GeV/c)]");
 // f4Pt->GetYaxis()->SetTitle("#sigma(#varUpsilon #rightarrow #mu^{+}#mu^{-1}) (b)");
 f4Pt->GetYaxis()->SetTitleSize(0.038);
 f4Pt->GetYaxis()->SetRangeUser(0.0002,0.4);
 f4Pt->GetXaxis()->CenterTitle(kTRUE);
 f4Pt->Draw();
 /// one pad to draw PbPb yields,
 TGraphErrors *gpt1 = new TGraphErrors(nPtBins_2013,pt,CS1S_aa_pt,0,CS1S_aa_pte);
 gpt1->SetMarkerColor(8);
 gpt1->SetMarkerStyle(33);
 gpt1->SetMarkerSize(2);
 TGraphErrors *gpt1circle = new TGraphErrors(nPtBins_2013,pt,CS1S_aa_pt,0,CS1S_aa_pte);
 gpt1circle->SetMarkerStyle(27);
 gpt1circle->SetMarkerSize(2);
 gpt1circle->SetLineColor(kBlack);
 if(!plotTNP){ gpt1->Draw("pe");
   gpt1circle->Draw("p");}
 // f4Pt->Draw("same");
 gPad->RedrawAxis();
 TGraphErrors *gpt1pp = new TGraphErrors(nPtBins_2013,pt,CS1S_pp_pt,0,CS1S_pp_pte);
 gpt1pp->SetMarkerColor(1);
 gpt1pp->SetMarkerStyle(21);
 gpt1pp->SetMarkerSize(1);
 TGraphErrors *gpt1circlepp = new TGraphErrors(nPtBins_2013,pt,CS1S_pp_pt,0,CS1S_pp_pte);
 gpt1circlepp->SetMarkerStyle(21);
 gpt1circlepp->SetMarkerSize(1);
 gpt1circlepp->SetLineColor(kBlack);
 if(!plotTNP){ gpt1pp->Draw("pe");
   gpt1circlepp->Draw("p");}
 //f4Pt->Draw("same");
 gPad->RedrawAxis();

 ///tnp comparison
 if(plotTNP){
   TGraphErrors *gPt1syst = new TGraphErrors(nPtBins_2013,pt,CS1S_aa_tnp_pt,pte,CS1S_aa_tnp_pts);
   gPt1syst->SetLineColor(kOrange+1);
   gPt1syst->SetFillStyle(0);
   gPt1syst->SetLineWidth(2);
   gPt1syst->SetMarkerSize(0);
   gPt1syst->Draw("2");
   TGraphErrors *gPt1ppsyst = new TGraphErrors(nPtBins_2013,pt,CS1S_pp_tnp_pt,pte,CS1S_pp_tnp_pts);
   gPt1ppsyst->SetLineColor(kAzure+1);
   gPt1ppsyst->SetFillStyle(0);
   gPt1ppsyst->SetLineWidth(2);
   gPt1ppsyst->SetMarkerSize(0);
   gPt1ppsyst->Draw("2");
   TGraphErrors *gpt1TNP = new TGraphErrors(nPtBins_2013,pt,CS1S_aa_tnp_pt,0,CS1S_aa_tnp_pte);
   gpt1TNP->SetMarkerColor(kOrange+1);
   gpt1TNP->SetMarkerStyle(21);
   gpt1TNP->SetMarkerSize(1);
   TGraphErrors *gpt1TNPcircle = new TGraphErrors(nPtBins_2013,pt,CS1S_aa_tnp_pt,0,CS1S_aa_tnp_pte);
   gpt1TNPcircle->SetMarkerStyle(25);
   gpt1TNPcircle->SetMarkerSize(1);
   gpt1TNPcircle->SetLineColor(kBlack);
   gpt1TNP->Draw("pe");
   double mean_pp = gpt1TNP->GetMean(1);
   gpt1TNPcircle->Draw("p");
   // f4Pt->Draw("same");
   gPad->RedrawAxis();
   TGraphErrors *gpt1TNPpp = new TGraphErrors(nPtBins_2013,pt,CS1S_pp_tnp_pt,0,CS1S_pp_tnp_pte);
   gpt1TNPpp->SetMarkerColor(kAzure+1);
   gpt1TNPpp->SetMarkerStyle(21);
   gpt1TNPpp->SetMarkerSize(1.2);
   TGraphErrors *gpt1TNPcirclepp = new TGraphErrors(nPtBins_2013,pt,CS1S_pp_tnp_pt,0,CS1S_pp_tnp_pte);
   gpt1TNPcirclepp->SetMarkerStyle(21);
   gpt1TNPcirclepp->SetMarkerSize(1.2);
   gpt1TNPcirclepp->SetLineColor(kBlack);
   gpt1TNPpp->Draw("pe");
  double mean_hi = gpt1TNPpp->GetMean(1);
   gpt1TNPcirclepp->Draw("p");
   //f4Pt->Draw("same");
   gPad->RedrawAxis(); 
 }
 TLegend *legend = new TLegend(0.7,0.55,0.9,0.7);
 legend->SetTextSize(0.029);
 legend->SetFillStyle(0);
 legend->SetFillColor(0);
 legend->SetBorderSize(0);
 legend->SetTextFont(42);
 if(!plotTNP){ legend->AddEntry(gpt1pp,"#varUpsilon(1S), pp ","lp");
   legend->AddEntry(gpt1,"#varUpsilon(1S), PbPb ","lp");}
 if(plotTNP){
   legend->AddEntry(gpt1TNPpp,"#varUpsilon(1S) pp","lp");
   legend->AddEntry(gpt1TNP,"#varUpsilon(1S) PbPb","lp");


   cout << mean_pp << " is the mean of 1S AA spectrum"<< endl;
 
   cout << mean_hi << " is the mean of 1S pp spectrum"<< endl;
   
 } 
 legend->Draw();
 TLatex *l1CMSpt = new TLatex(8,0.2, "CMS Internal #sqrt{s_{NN}} = 2.76 TeV");
 // TLatex *l1CMSpt = new TLatex(12,2e-10, "CMS internal");
 l1CMSpt->SetTextFont(42);
 l1CMSpt->SetTextSize(0.038);
 l1CMSpt->Draw();
 TLatex *lyL= new TLatex(3,0.004,"L_{PbPb} = 166 #mub^{-1}");
 lyL->SetTextFont(42);
 lyL->SetTextSize(0.032);
 lyL->DrawLatex(3,0.002,"L_{pp} = 5.4 pb^{-1}");
 lyL->DrawLatex(3,0.001,"|y| < 2.4");
 lyL->Draw();

 cpt->SaveAs("~/Documents/PR/forTWiki/CSandRAA/CS1S_ppAAPt.pdf");
 cpt->SaveAs("~/Desktop/Xsection_ppAA_1S_pt.png");
 //Unfolding unfolding!
 // TCanvas *cUnfold = new TCanvas("cUnfold","cUnfold"); 
 // cUnfold->cd();
 // TPad *pUnfold1 = new TPad("pUnfold1","pUnfold1",0.0,0.0,1.0,1.0);
 // pUnfold1->SetBottomMargin(0.12);
 // pUnfold1->SetTopMargin(0.03);
 // pUnfold1->SetRightMargin(0.03);
 // pUnfold1->SetLeftMargin(0.12);
 // pUnfold1->SetLogy();
 // pUnfold1->Draw();
 // pUnfold1->cd();
 // //f4Unfold->GetYaxis()->SetRangeUser(0.01,.09);
 // TGraphErrors *gpt1unfoldpp = new TGraphErrors(nPtBins_2013,pt,CS1S_pp_pt,pte,CS1S_pp_pte);
 // gpt1unfoldpp->SetMarkerStyle(25);
 // gpt1unfoldpp->SetMarkerSize(1.22);
 // gpt1unfoldpp->SetLineColor(kBlack);
 // gpt1unfoldpp->Draw("p");
 // gPad->RedrawAxis();

 TCanvas *cptaa = new TCanvas("cptaa","cptaa"); 
 cptaa->cd();
 TPad *ppt1 = new TPad("ppt1","ppt1",0.0,0.0,1.0,0.9);
 ppt1->SetBottomMargin(0.12);
 // ppt1->SetTopMargin(0.03);
 ppt1->SetRightMargin(0.03);
 ppt1->SetLeftMargin(0.16);
 ppt1->SetLogy();
 ppt1->Draw();
 ppt1->cd();
 TF1 *f4Ptaa = new TF1("f4Ptaa","0.4",0,21);
 f4Ptaa->SetLineWidth(0);
 f4Ptaa->GetYaxis()->SetTitleOffset(1.5);
 f4Ptaa->GetXaxis()->SetTitle("p_{T}^{#varUpsilon} (GeV/c)");		
 f4Ptaa->GetYaxis()->SetTitle(" #frac{1}{T_{AA}N_{MB}}#frac{d^{2}N}{A#varepsilon dy dp_{T}}  [nb/(GeV/c)]");
 // f4Ptaa->GetYaxis()->SetTitle("#sigma(#varUpsilon #rightarrow #mu^{+}#mu^{-1}) (b)");
 f4Ptaa->GetYaxis()->SetTitleSize(0.038);
 f4Ptaa->GetYaxis()->SetRangeUser(1e-4,0.1);
 f4Ptaa->GetXaxis()->CenterTitle(kTRUE);
 f4Ptaa->Draw();
 gPt1syst->Draw("2");
 gpt1TNP->Draw("pe");
 double mean_aa1=gpt1TNP->GetMean(1);
 gpt1TNPcircle->Draw("p");
 TGraphErrors *gPt2syst = new TGraphErrors(nPtBins_2010,pt2010,CS2S_aa_pt,pt2010e,CS2S_aa_pts);
 gPt2syst->SetLineColor(kOrange+4);
 gPt2syst->SetFillStyle(0);
 gPt2syst->SetLineWidth(2);
 gPt2syst->SetMarkerSize(0);
 gPt2syst->Draw("2");
 TGraphErrors *gpt2TNP = new TGraphErrors(nPtBins_2010,pt2010,CS2S_aa_pt,0,CS2S_aa_pte);
 gpt2TNP->SetMarkerColor(kOrange+4);
 gpt2TNP->SetMarkerStyle(20);
 gpt2TNP->SetMarkerSize(1);
 double mean_aa2 = gpt2TNP->GetMean(1);
 // cout << mean_aa1 << endl;
 // cout << mean_aa2 << endl;
 TGraphErrors *gpt2TNPcircle = new TGraphErrors(nPtBins_2010,pt2010,CS2S_aa_pt,0,CS2S_aa_pte);
 gpt2TNPcircle->SetMarkerStyle(24);
 gpt2TNPcircle->SetMarkerSize(1);
 gpt2TNPcircle->SetLineColor(kBlack);
 gpt2TNP->Draw("pe");
 gpt2TNPcircle->Draw("p");
 f4Ptaa->Draw("same");
 TLatex *l1CMSpt = new TLatex(16,0.05, "CMS");
 l1CMSpt->SetTextFont(62);
 l1CMSpt->SetTextSize(0.06);
 l1CMSpt->Draw();
 TLegend *legend = new TLegend(0.7,0.6,0.85,0.75);
 legend->SetTextSize(0.035);
 legend->SetFillStyle(0);
 legend->SetFillColor(0);
 legend->SetBorderSize(0);
 legend->SetTextFont(42);
 legend->AddEntry(gpt1TNP,"#varUpsilon(1S)","lp");
 legend->AddEntry(gpt2TNP,"#varUpsilon(2S)","lp");
 legend->Draw();
 cptaa->cd();
 TPad *p2 = new TPad("p2","p2",0.14,0.9,1.0,1.0);
 // p2->SetBottomMargin(0.12);
 p2->SetTopMargin(0.03);
 p2->SetRightMargin(0.0);
 p2->SetLeftMargin(0.01);
 p2->SetTickx(0);
 // p2->SetTicky(0);
 p2->Draw();
 p2->cd();
 TLatex *prelim =new TLatex(0.04,0.06,"Preliminary");
 prelim->SetTextFont(52);
 prelim->SetTextSize(0.5);
 prelim->Draw();
 TLatex *pbpb_pp = new TLatex (0.47,0.06,"PbPb 166 #mub^{-1}  #sqrt{s_{NN}} = 2.76 TeV"); 
 pbpb_pp->SetTextFont(42); //#sqrt{s} = 2.76 TeV
 pbpb_pp->SetTextSize(0.3);
 pbpb_pp->SetTextColor(kBlack);
 pbpb_pp->Draw(); 
 // TLatex *l1CMSpt = new TLatex(8,0.2, "CMS Internal #sqrt{s_{NN}} = 2.76 TeV");
 // // TLatex *l1CMSpt = new TLatex(12,2e-10, "CMS internal");
 // l1CMSpt->SetTextFont(42);
 // l1CMSpt->SetTextSize(0.038);
 // l1CMSpt->Draw();
 // TLatex *lyL= new TLatex(8,0.1,"L_{PbPb} = 166 #mub^{-1}, |y| < 2.4");
 // lyL->SetTextFont(42);
 // lyL->SetTextSize(0.03);
 // lyL->Draw();
 
 cptaa->SaveAs("~/Documents/PR/forTWiki/CSandRAA/CS_AAPt.pdf");
 cptaa->SaveAs("~/Desktop/Xsection_AA_1S_pt.png");
 //////////
 // pp
 TCanvas *cptpp = new TCanvas("cptpp","cptpp"); 
 cptpp->cd();
 TPad *ppt1pp = new TPad("ppt1pp","ppt1pp",0.0,0.0,1.0,0.9);
 ppt1pp->SetBottomMargin(0.12);
 ppt1pp->SetTopMargin(0.03);
 ppt1pp->SetRightMargin(0.03);
 ppt1pp->SetLeftMargin(0.16);
 ppt1pp->SetLogy();
 ppt1pp->Draw();
 ppt1pp->cd();
 TF1 *f4Pt = new TF1("f4Pt","10",0,20);
 f4Pt->SetLineWidth(0);
 f4Pt->GetYaxis()->SetTitleOffset(1.5);
 f4Pt->GetXaxis()->SetTitle("p_{T}^{#varUpsilon} (GeV/c)");		
 f4Pt->GetYaxis()->SetTitle("#frac{1}{#Deltay} #frac{d#sigma}{dp_{T}}  [nb/ GeV/c]");

 f4Pt->GetYaxis()->SetTitleSize(0.035);
 f4Pt->GetYaxis()->SetRangeUser(0.0005,0.2);
 //f4Pt->GetYaxis()->SetRangeUser(0.01,.09);
 f4Pt->GetXaxis()->CenterTitle(kTRUE);
 f4Pt->Draw();
 if(!plotTNP){
   TGraphErrors *g2circle = new TGraphErrors(nPtBins_2013,pt,CS2S_pp_pt2013,0,CS2S_pp_pt2013e);
   g2circle->SetMarkerStyle(20);
   g2circle->SetMarkerSize(1);
   g2circle->SetLineColor(kBlack);
   g2pt->Draw("pe");
   g2circle->Draw("p");

   TGraphErrors *g3circle = new TGraphErrors(nPtBins_2013,pt,CS3S_pp_pt2013,0,CS3S_pp_pt2013e);
   g3circle->SetMarkerStyle(22);
   g3circle->SetMarkerSize(1);
   g3circle->SetLineColor(kBlack);
   g3pt->Draw("pe");
   g3circle->Draw("p");

   TGraphErrors *gpt1pp = new TGraphErrors(nPtBins_2013,pt,CS1S_pp_tnp_pt,0,CS1S_pp_tnp_pte);
   gpt1pp->SetMarkerColor(1);
   gpt1pp->SetMarkerStyle(21);
   gpt1pp->SetMarkerSize(1.2);
   TGraphErrors *gpt1circlepp = new TGraphErrors(nPtBins_2013,pt,CS1S_pp_tnp_pt,0,CS1S_pp_tnp_pte);
   gpt1circlepp->SetMarkerStyle(21);
   gpt1circlepp->SetMarkerSize(1.22);
   gpt1circlepp->SetLineColor(kBlack);
   gpt1pp->Draw("pe");
   gpt1circlepp->Draw("p");
   TGraphErrors *g2pt = new TGraphErrors(nPtBins_2013,pt,CS2S_pp_pt2013,pte,CS2S_pp_pt2013e);
   g2pt->SetMarkerColor(kAzure+1);
   g2pt->SetMarkerStyle(21);
   g2pt->SetMarkerSize(1.2);

   TGraphErrors *g3pt = new TGraphErrors(nPtBins_2013,pt,CS3S_pp_pt2013,pte,CS3S_pp_pt2013e);
   g3pt->SetMarkerColor(kAzure+1);
   g3pt->SetMarkerStyle(21);
   g3pt->SetMarkerSize(1.2);
 }

 
 if(plotTNP){
   TGraphErrors *gPt2ppsyst = new TGraphErrors(nPtBins_2013,pt,CS2S_pp_tnp_pt2013,pte,CS2S_pp_tnp_pts);
   gPt2ppsyst->SetLineColor(kAzure+1);
   gPt2ppsyst->SetFillStyle(0);
   gPt2ppsyst->SetLineWidth(2);
   gPt2ppsyst->SetMarkerSize(0);
   gPt2ppsyst->Draw("2");
   TGraphErrors *gpt2TNPpp = new TGraphErrors(nPtBins_2013,pt,CS2S_pp_tnp_pt2013,0,CS2S_pp_tnp_pt2013e);
   gpt2TNPpp->SetMarkerColor(1);
   gpt2TNPpp->SetMarkerStyle(20);
   gpt2TNPpp->SetMarkerSize(1.2);
   TGraphErrors *gpt2TNPcirclepp = new TGraphErrors(nPtBins_2013,pt,CS2S_pp_tnp_pt2013,0,CS2S_pp_tnp_pt2013e);
   gpt2TNPcirclepp->SetMarkerStyle(20);
   gpt2TNPcirclepp->SetMarkerSize(1.2);
   gpt2TNPcirclepp->SetLineColor(kBlack);
   gpt2TNPpp->Draw("pe");

   gpt2TNPcirclepp->Draw("p");
   //f4Pt->Draw("same");
   gPad->RedrawAxis(); 
   TGraphErrors *gPt3ppsyst = new TGraphErrors(nPtBins_2013,pt,CS3S_pp_tnp_pt2013,pte,CS3S_pp_tnp_pts);
   gPt3ppsyst->SetLineColor(kAzure+1);
   gPt3ppsyst->SetFillStyle(0);
   gPt3ppsyst->SetLineWidth(2);
   gPt3ppsyst->SetMarkerSize(0);
    gPt3ppsyst->Draw("2");
   TGraphErrors *gpt3TNPpp = new TGraphErrors(nPtBins_2013,pt,CS3S_pp_tnp_pt2013,0,CS3S_pp_tnp_pt2013e);
   gpt3TNPpp->SetMarkerColor(1);
   gpt3TNPpp->SetMarkerStyle(22);
   gpt3TNPpp->SetMarkerSize(1.2);
   TGraphErrors *gpt3TNPcirclepp = new TGraphErrors(nPtBins_2013,pt,CS3S_pp_tnp_pt2013,0,CS3S_pp_tnp_pt2013e);
   gpt3TNPcirclepp->SetMarkerStyle(22);
   gpt3TNPcirclepp->SetMarkerSize(1.2);
   gpt3TNPcirclepp->SetLineColor(kBlack);
   f4Pt->Draw("same");
   gpt3TNPpp->Draw("pe");
   double mean_pp3 = gpt3TNPpp->GetMean(1);
   cout << "3S mean = "<< mean_pp3 << endl;
   gpt3TNPcirclepp->Draw("p");
   
   TGraphErrors *gPt1ppsyst = new TGraphErrors(nPtBins_2013,pt,CS1S_pp_tnp_pt,pte,CS1S_pp_tnp_pts);
   gPt1ppsyst->SetLineColor(kAzure+1);
   gPt1ppsyst->SetFillStyle(0);
   gPt1ppsyst->SetLineWidth(2);
   gPt1ppsyst->SetMarkerSize(0);
   gPt1ppsyst->Draw("2");
   gpt1pp->Draw("pe");
   gpt1TNPcirclepp->Draw("p");
   
  }


 //f4Pt->Draw("same");
 gPad->RedrawAxis();
 //f4Pt->Draw("same");
 gPad->RedrawAxis();
 TLegend *legend = new TLegend(0.7,0.55,0.95,0.7);
 legend->SetTextSize(0.029);
 legend->SetFillStyle(0);
 legend->SetFillColor(0);
 legend->SetBorderSize(0);
 legend->SetTextFont(42);
 legend->AddEntry(gpt1pp,"#varUpsilon(1S) ","lp"); 
 legend->AddEntry(gpt2TNPpp,"#varUpsilon(2S) ","lp");
 legend->AddEntry(gpt3TNPpp,"#varUpsilon(3S) ","lp");
 legend->Draw();
 TLatex *l1CMSpt = new TLatex(16,0.11, "CMS");
 l1CMSpt->SetTextFont(62);
 l1CMSpt->SetTextSize(0.06);
 l1CMSpt->Draw();
 cptpp->cd();
 TPad *p2 = new TPad("p2","p2",0.1,0.88,1.0,1.0);
 p2->SetBottomMargin(0.12);
 p2->SetTopMargin(0.03);
 p2->SetRightMargin(0.0);
 p2->SetLeftMargin(0.01);
 p2->SetTickx(0);
 // p2->SetTicky(0);
 p2->Draw();
 p2->cd();
 TLatex *prelim =new TLatex(0.08,0.06,"Preliminary");
 prelim->SetTextFont(52);
 prelim->SetTextSize(0.5);
 prelim->Draw();
 TLatex *pbpb_pp = new TLatex (0.57,0.06,"pp 5.4 pb^{-1}  #sqrt{s} = 2.76 TeV"); 
 pbpb_pp->SetTextFont(42); //#sqrt{s} = 2.76 TeV
 pbpb_pp->SetTextSize(0.3);
 pbpb_pp->SetTextColor(kBlack);
 pbpb_pp->Draw(); 
 // TLatex *l1CMSpt = new TLatex(8.1,0.2, "CMS Internal #sqrt{s} = 2.76 TeV");
 // l1CMSpt->SetTextFont(42);
 // l1CMSpt->SetTextSize(0.04);
 // l1CMSpt->Draw();
 
 // TLatex *lyL= new TLatex(8.1,0.08,"L_{pp} = 5.4 pb^{-1}; |y| < 2.4");
 // lyL->SetTextSize(0.03);
 // lyL->SetTextFont(42);
 // lyL->Draw();
 cptpp->SaveAs("~/Documents/PR/forTWiki/CSandRAA/CS1S_ppPt.pdf");
 cptpp->SaveAs("~/Desktop/Xsection_pp1S_Pt.png");
 }


 if(plotFiducial){
 //////////
 //2S+1S pp FIDUCIAL
 TCanvas *cptppFiducial = new TCanvas("cptppFiducial","cptppFiducial"); 
 cptppFiducial->cd();
 TPad *ppt1ppFiducial = new TPad("ppt1ppFiducial","ppt1ppFiducial",0.0,0.0,1.0,1.0);
 ppt1ppFiducial->SetBottomMargin(0.12);
 ppt1ppFiducial->SetTopMargin(0.03);
 ppt1ppFiducial->SetRightMargin(0.03);
 ppt1ppFiducial->SetLeftMargin(0.16);
 ppt1ppFiducial->SetLogy();
 ppt1ppFiducial->Draw();
 ppt1ppFiducial->cd();
 TF1 *f4Pt = new TF1("f4Pt","0.000000001",0,21);
 f4Pt->SetLineWidth(0);
 f4Pt->GetYaxis()->SetTitleOffset(2);
 f4Pt->GetXaxis()->SetTitle("p_{T}^{#varUpsilon} (GeV/c)");		
 f4Pt->GetYaxis()->SetTitle("#frac{1}{L_{pp}}#frac{N}{#varepsilon #Deltap_{T}} (b/(GeV/c))");

 f4Pt->GetYaxis()->SetTitleSize(0.028);
 //f4Pt->GetYaxis()->SetRangeUser(0.01,.09);
 f4Pt->GetXaxis()->CenterTitle(kTRUE);
 f4Pt->Draw();
 TGraphErrors *g2ptFiducial = new TGraphErrors(nPtBins_2013,pt,CS2S_pp_pt2013Fiducial,pte,CS2S_pp_pt2013Fiduciale);
 g2ptFiducial->SetMarkerColor(kAzure+1);
 g2ptFiducial->SetMarkerStyle(21);
 g2ptFiducial->SetMarkerSize(1.2);


 // TGraphErrors *g2Ssyst = new TGraphErrors(nPtBins_2013,pt,CS2S_pp_pt2013,pte,CS2S_pp_pt2013e);
 // g2Ssyst->SetLineColor(kAzure+1);
 // g2Ssyst->SetFillStyle(0);
 // // g2Ssyst->SetLineWidth(18);
 // g2Ssyst->SetMarkerSize(0);
 // g2Ssyst->Draw("2");


 TGraphErrors *g2circleF = new TGraphErrors(nPtBins_2013,pt,CS2S_pp_pt2013Fiducial,pte,CS2S_pp_pt2013Fiduciale);
 g2circleF->SetMarkerStyle(25);
 g2circleF->SetMarkerSize(1.2);
 g2circleF->SetLineColor(kBlack);
 g2ptFiducial->Draw("pe");
 g2circleF->Draw("p");

TGraphErrors *gpt1ppF = new TGraphErrors(nPtBins_2013,pt,CS1S_pp_ptFiducial,pte,CS1S_pp_ptFiduciale);
 gpt1ppF->SetMarkerColor(kAzure+1);
 gpt1ppF->SetMarkerStyle(21);
 gpt1ppF->SetMarkerSize(1.2);
 TGraphErrors *gpt1circleFpp = new TGraphErrors(nPtBins_2013,pt,CS1S_pp_ptFiducial,pte,CS1S_pp_ptFiduciale);
 gpt1circleFpp->SetMarkerStyle(25);
 gpt1circleFpp->SetMarkerSize(1.22);
 gpt1circleFpp->SetLineColor(kBlack);
 gpt1ppF->Draw("pe");
 gpt1circleFpp->Draw("p");
 f4Pt->Draw("same");
 gPad->RedrawAxis();
 f4Pt->Draw("same");
 gPad->RedrawAxis();
 TLegend *legend = new TLegend(0.482,0.84,0.88,0.7);
 legend->SetTextSize(0.029);
 legend->SetFillStyle(0);
 legend->SetFillColor(0);
 legend->SetBorderSize(0);
 legend->SetTextFont(42);
 legend->AddEntry(gpt1ppF,"#varUpsilon(1S), pp ","lp");
 legend->AddEntry(g2ptFiducial,"#varUpsilon(2S), pp ","lp");
 legend->Draw();
 TLatex *l1CMSpt = new TLatex(2,0.0000000008, "CMS Internal #sqrt{s} = 2.76 TeV");
 l1CMSpt->SetTextFont(42);
 l1CMSpt->SetTextSize(0.032);
 l1CMSpt->Draw();
 
 TLatex *lyL= new TLatex(2,0.0000000005,"L_{pp} = 5.4 pb^{-1}; |y| < 2.4");
 lyL->SetTextSize(0.04);
lyL->DrawLatex(2,0.000000002,"Fiducial");
 lyL->Draw();


 //comparison pp,pbpb fiducial



TCanvas *cptFiducial = new TCanvas("cptFiducial","cptFiducial"); 
 cptFiducial->cd();
 TPad *ppt1ppFiducial = new TPad("ppt1ppFiducial","ppt1ppFiducial",0.0,0.0,1.0,1.0);
 ppt1ppFiducial->SetBottomMargin(0.12);
 ppt1ppFiducial->SetTopMargin(0.03);
 ppt1ppFiducial->SetRightMargin(0.03);
 ppt1ppFiducial->SetLeftMargin(0.16);
 ppt1ppFiducial->SetLogy();
 ppt1ppFiducial->Draw();
 ppt1ppFiducial->cd();
 TF1 *f4Pt = new TF1("f4Pt","0.000000001",0,21);
 f4Pt->SetLineWidth(0);
 f4Pt->GetYaxis()->SetTitleOffset(2);
 f4Pt->GetXaxis()->SetTitle("p_{T}^{#varUpsilon} (GeV/c)");		
 f4Pt->GetYaxis()->SetTitle("#frac{1}{L_{pp}}#frac{N}{#varepsilon #Deltap_{T}} (b/(GeV/c))");

 f4Pt->GetYaxis()->SetTitleSize(0.028);
 //f4Pt->GetYaxis()->SetRangeUser(0.01,.09);
 f4Pt->GetXaxis()->CenterTitle(kTRUE);
 f4Pt->Draw();

TGraphErrors *gpt1F = new TGraphErrors(nPtBins_2013,pt,CS1S_aa_ptFiducial,pte,CS1S_aa_ptFiduciale);
 gpt1F->SetMarkerColor(8);
 gpt1F->SetMarkerStyle(33);
 gpt1F->SetMarkerSize(2);



 TGraphErrors *gpt1circle = new TGraphErrors(nPtBins_2013,pt,CS1S_aa_ptFiducial,pte,CS1S_aa_ptFiduciale);
 gpt1circle->SetMarkerStyle(27);
 gpt1circle->SetMarkerSize(2);
 gpt1circle->SetLineColor(kBlack);
 gpt1F->Draw("pe");
 gpt1circle->Draw("p");
 f4Pt->Draw("same");
 gPad->RedrawAxis();
    

TGraphErrors *gpt1ppF = new TGraphErrors(nPtBins_2013,pt,CS1S_pp_ptFiducial,pte,CS1S_pp_ptFiduciale);
 gpt1ppF->SetMarkerColor(kAzure+1);
 gpt1ppF->SetMarkerStyle(21);
 gpt1ppF->SetMarkerSize(1.2);
 TGraphErrors *gpt1circleFpp = new TGraphErrors(nPtBins_2013,pt,CS1S_pp_ptFiducial,pte,CS1S_pp_ptFiduciale);
 gpt1circleFpp->SetMarkerStyle(25);
 gpt1circleFpp->SetMarkerSize(1.22);
 gpt1circleFpp->SetLineColor(kBlack);
 gpt1ppF->Draw("pe");
 gpt1circleFpp->Draw("p");
 f4Pt->Draw("same");
 gPad->RedrawAxis();
 f4Pt->Draw("same");
 gPad->RedrawAxis();
 TLegend *legend = new TLegend(0.482,0.84,0.88,0.7);
 legend->SetTextSize(0.029);
 legend->SetFillStyle(0);
 legend->SetFillColor(0);
 legend->SetBorderSize(0);
 legend->SetTextFont(42);
 legend->AddEntry(gpt1ppF,"#varUpsilon(1S), pp ","lp");
 legend->AddEntry(gpt1F,"#varUpsilon(1S), PbPb ","lp");
 legend->Draw();
 TLatex *l1CMSpt = new TLatex(2,0.0000000008, "CMS Internal #sqrt{s} = 2.76 TeV");
 l1CMSpt->SetTextFont(42);
 l1CMSpt->SetTextSize(0.032);
 l1CMSpt->Draw();
 
 TLatex *lyL= new TLatex(2,0.000000008,"L_{pp} = 5.4 pb^{-1}; |y| < 2.4");
 lyL->SetTextSize(0.04);
lyL->DrawLatex(2,0.000000002,"Fiducial");
 lyL->Draw();

 }
 ///raa vs pt

 if(plotRAA){
 TCanvas *cRaapt = new TCanvas("cRaapt","cRaapt"); 
 cRaapt->cd();
 // TPad *ppt2 = new TPad("ppt2","ppt2",0.0,0.0,0.98,0.92);
 // ppt2->SetBottomMargin(0.12);
 // ppt2->SetTopMargin(0.03);
 // ppt2->SetRightMargin(0.03);
 // ppt2->SetLeftMargin(0.12);
 // ppt2->Draw();
 // ppt2->cd();
 //one pad to draw RaaPt!
 TF1 *f4RaaPt = new TF1("f4RaaPt","1",0,20);
 f4RaaPt->SetLineWidth(0);
 f4RaaPt->SetLineColor(kBlack);
 f4RaaPt->GetXaxis()->SetTitle("p_{T}^{#varUpsilon} (GeV/c)");
 f4RaaPt->GetYaxis()->SetTitle("R_{AA}");
 // f4RaaPt->GetYaxis()->SetTitleOffset(1.05);
 // f4RaaPt->GetYaxis()->SetTitleSize(0.05);
 f4RaaPt->GetXaxis()->SetTitleOffset(f4RaaPt->GetXaxis()->GetTitleOffset()*1.3);
 f4RaaPt->GetXaxis()->SetTitleSize(0.045);
 f4RaaPt->GetYaxis()->SetRangeUser(0.,1.4);
 f4RaaPt->GetXaxis()->CenterTitle(kTRUE);
 f4RaaPt->Draw();
 TGraphErrors *gRaaPt1 = new TGraphErrors(nPtBins_2013,pt,RAA_1S_pt,pte,RAA_1S_pte);
 gRaaPt1->SetMarkerColor(kAzure+1);
 gRaaPt1->SetMarkerStyle(21);
 gRaaPt1->SetMarkerSize(1);
 TGraphErrors *gRaaPt1circle = new TGraphErrors(nPtBins_2013,pt,RAA_1S_pt,pte,RAA_1S_pte);
 gRaaPt1circle->SetMarkerStyle(25);
 gRaaPt1circle->SetMarkerSize(1);
 gRaaPt1circle->SetLineColor(kBlack);
 if(!plotTNP){
   gRaaPt1->Draw("pe");
   gRaaPt1circle->Draw("p");
   f4RaaPt->Draw("same");
 }
 if(plotTNP){
   TGraphErrors *gRaaPt1TNP = new TGraphErrors(nPtBins_2013,pt,RAA_1S_tnp_pt,0,RAA_1S_tnp_pte);
   gRaaPt1TNP->SetMarkerColor(kOrange+1);
   gRaaPt1TNP->SetMarkerStyle(21);
   gRaaPt1TNP->SetMarkerSize(1);
   TGraphErrors *gRaaPt1TNPcircle = new TGraphErrors(nPtBins_2013,pt,RAA_1S_tnp_pt,0,RAA_1S_tnp_pte);
   gRaaPt1TNPcircle->SetMarkerStyle(25);
   gRaaPt1TNPcircle->SetMarkerSize(1);
   gRaaPt1TNPcircle->SetLineColor(kBlack);
   gRaaPt1TNP->Draw("pe");
   gRaaPt1TNPcircle->Draw("p");
   f4RaaPt->Draw("same");

   TGraphErrors *gRaaPt1syst = new TGraphErrors(nPtBins_2013,pt,RAA_1S_tnp_pt,pte,RAA_1S_tnp_pts);
   gRaaPt1syst->SetLineColor(kOrange+1);
   gRaaPt1syst->SetFillStyle(0);
   gRaaPt1syst->SetLineWidth(2);
   gRaaPt1syst->SetMarkerSize(0);
   gRaaPt1syst->Draw("2");

   if(plotTight){
     TGraphErrors *gRaaPt1TNP4 = new TGraphErrors(nPtBins_2013,ptShift,RAA_1S_tnp_pt4,0,RAA_1S_tnp_pt4e);
     gRaaPt1TNP4->SetMarkerColor(kGreen+1);
     gRaaPt1TNP4->SetMarkerStyle(21);
     gRaaPt1TNP4->SetMarkerSize(1);
     TGraphErrors *gRaaPt1TNPcircle4 = new TGraphErrors(nPtBins_2013,ptShift,RAA_1S_tnp_pt4,0,RAA_1S_tnp_pt4e);
     gRaaPt1TNPcircle4->SetMarkerStyle(25);
     gRaaPt1TNPcircle4->SetMarkerSize(1);
     gRaaPt1TNPcircle4->SetLineColor(kBlack);
     gRaaPt1TNP4->Draw("pe");
     gRaaPt1TNPcircle4->Draw("p");
     f4RaaPt->Draw("same");

     TGraphErrors *gRaaPt1syst4 = new TGraphErrors(nPtBins_2013,pt,RAA_1S_tnp_pt4,pte,RAA_1S_tnp_pt4s);
     gRaaPt1syst4->SetLineColor(kGreen+1);
     gRaaPt1syst4->SetFillStyle(0);
     gRaaPt1syst4->SetLineWidth(2);
     gRaaPt1syst4->SetMarkerSize(0);
     gRaaPt1syst4->Draw("2");

   }else{
   TGraphErrors *gRaaPt2TNP = new TGraphErrors(nPtBins_2010,pt2010,RAA_2S_tnp_pt,0,RAA_2S_tnp_pte);
   gRaaPt2TNP->SetMarkerColor(kOrange+4);
   gRaaPt2TNP->SetMarkerStyle(20);
   gRaaPt2TNP->SetMarkerSize(1);
   TGraphErrors *gRaaPt2TNPcircle = new TGraphErrors(nPtBins_2010,pt2010,RAA_2S_tnp_pt,0,RAA_2S_tnp_pte);
   gRaaPt2TNPcircle->SetMarkerStyle(24);
   gRaaPt2TNPcircle->SetMarkerSize(1);
   gRaaPt2TNPcircle->SetLineColor(kBlack);
   gRaaPt2TNP->Draw("pe");
   gRaaPt2TNPcircle->Draw("p");
   f4RaaPt->Draw("same");
   TGraphErrors *gRaaPt2syst = new TGraphErrors(nPtBins_2010,pt2010,RAA_2S_tnp_pt,pt2010e,RAA_2S_tnp_pts);
   gRaaPt2syst->SetLineColor(kOrange+4);
   gRaaPt2syst->SetFillStyle(0);
   gRaaPt2syst->SetLineWidth(2);
   gRaaPt2syst->SetMarkerSize(0);
   gRaaPt2syst->Draw("2");
     
   }
 }
 TBox *box = new TBox(19,1-syst1S_raa_global,20,1+syst1S_raa_global);
 
 box->SetFillColor(kGray);//kOrange+1);
 box->Draw();
 if(!plotTight){
 // TBox *box2S = new TBox(18,1-syst2S_raa_global,19,1+syst2S_raa_global);
 // 
 // box2S->SetFillColor(kOrange+4);
 // box2S->Draw();
 }
 if(plotTight){
   TBox *box1S4 = new TBox(18,1-syst1S_pp_glob,19,1+syst1S_pp_glob);
   box1S4->SetFillColor(kGreen+1);
   box1S4->Draw();
 }
 // TLatex *l1CMSpt = new TLatex(16,1.27, "CMS");
 // l1CMSpt->SetTextFont(62);
 // l1CMSpt->SetTextSize(gTextSize);
 // l1CMSpt->Draw();
 // TLatex *lyLPT= new TLatex(2,1.3,"2011 L_{int}^{PbPb} = 166 #mub^{-1}; 2013 L_{int}^{pp} = 5.4 pb^{-1};");
 // lyLPT->SetTextFont(42);
 // lyLPT->SetTextSize(0.027);
 // lyLPT->Draw();
 // if(plot2010){ lyLPT->DrawLatex(2,1.2,"2010 L_{int}^{PbPb} = 7.28 #mub^{-1}; L_{int}^{pp} = 225 nb^{-1};");}
 // ppt2->Update();
 //2010stuff
 // TLegend *legend = new TLegend(0.24,0.75,0.4,0.88);
 TLegend *legend = new TLegend(0.23,0.50,0.39,0.65);
 legend->SetTextSize(gTextSize);
 legend->SetFillStyle(0);
 legend->SetFillColor(0);
 legend->SetBorderSize(0);
 legend->SetTextFont(42);
 if(plot2010){
   TGraphErrors *gpt2010 = new TGraphErrors(nPtBins_2010,pt_2010,raaPt2010,pte_2010,raaPt2010e);
   gpt2010->SetMarkerColor(kTeal+3);
   gpt2010->SetMarkerStyle(33);
   gpt2010->SetMarkerSize(2);
   TGraphErrors *gpt2010s = new TGraphErrors(nPtBins_2010,pt_2010,raaPt2010,centnoErr,raaPt2010s);
   gpt2010s->SetLineColor(8);
   gpt2010s->SetLineWidth(18);
   gpt2010s->SetMarkerSize(0);
   gpt2010s->Draw("e");
   gpt2010->Draw("pe");
   TGraphErrors *gpt2010circle = new TGraphErrors(nPtBins_2010,pt_2010,raaPt2010,pte_2010,raaPt2010e);
   gpt2010circle->SetMarkerStyle(27);
   gpt2010circle->SetMarkerSize(2);
   gpt2010circle->SetLineColor(kBlack);
   gpt2010circle->Draw("p");
   f4RaaPt->Draw("same");
   gPad->RedrawAxis();

   legend->AddEntry(gpt2010,"#varUpsilon(1S) JHEP 05 (2012) 063","pe");
 }
 if(!plotTNP){ legend->AddEntry(gRaaPt1,"#varUpsilon(1S)","pe");}
  if(plotTNP)
    {
      legend->AddEntry(gRaaPt1TNP,"#varUpsilon(1S)","pe");
      if(plotTight){
	legend->AddEntry(gRaaPt1TNP4,"#varUpsilon(1S) ","pe");
      }else{
	legend->AddEntry(gRaaPt2TNP,"#varUpsilon(2S)","pe");}
     }
  legend->Draw();
  // TLegend *leg2= new TLegend(0.44,0.75,0.6,0.88);
  TLegend *leg2= new TLegend(0.57,0.54,0.73,0.62);
  leg2->SetBorderSize(0);
  leg2->SetTextSize(0.036);
  leg2->SetTextFont(42);
  leg2->SetLineColor(0);
  leg2->SetLineStyle(1);
  leg2->SetLineWidth(0.4);
  leg2->SetFillColor(0);
  leg2->SetFillStyle(0);
  
  if(plotTight){
    leg2->AddEntry(box,"#varUpsilon(1S) syst. unc. ,p_{T} > 3.5, 4","f");
    leg2->AddEntry(box1S4,"#varUpsilon(1S) syst. unc. , p_{T} > 4","f"); }
  else if(!plotTight){
    leg2->AddEntry(box,"global syst.","f");
    // leg2->AddEntry(box2S,"#varUpsilon(2S) syst. unc.","f");
    }
  leg2->Draw();
  gPad->RedrawAxis();
  cRaapt->cd();

    // Cent. 0-100 %
    TLatex latexrap;
    latexrap.SetTextSize(gTextSize);
    latexrap.SetTextFont(42);
    latexrap.DrawLatex(1.5,1.2,"Cent. 0-100%, |y|<2.4");

    CMS_lumi(cRaapt,103,33);
    cRaapt->Update();
    cRaapt->RedrawAxis();
    cRaapt->GetFrame()->Draw();
 
  if(plotTight){
    cRaapt->SaveAs("~/Documents/PR/forTWiki/CSandRAA/RAA_Pt4.pdf");
    cRaapt->SaveAs("~/Desktop/RAA_Pt4.png");
  }else{
    cRaapt->SaveAs("~/Documents/PR/forTWiki/CSandRAA/RAA_Pt.pdf");
    cRaapt->SaveAs("~/Desktop/RAA_Pt.png");
  }
 }


 ////////////////////////////////////////////////////////////////
 /// drawing Rap-binned Data
 ////////////////////////////////////////////////////////////////
 if(plotCS){
 TCanvas *crap = new TCanvas("crap","crap"); 
 crap->cd();
 TPad *prap1 = new TPad("prap1","prap1",0.0,0.0,1.0,1.0);
 prap1->SetBottomMargin(0.12);
 prap1->SetTopMargin(0.08);
 prap1->SetRightMargin(0.03);
 prap1->SetLeftMargin(0.12);
 prap1->SetLogy();
 prap1->Draw();
 prap1->cd();
 TF1 *f4Rap = new TF1("f4Rap","10",0,2.4);
 f4Rap->SetLineWidth(0);

 f4Rap->GetYaxis()->SetTitleOffset(1.5);
 f4Rap->GetYaxis()->SetTitleSize(0.035);
 f4Rap->GetYaxis()->SetRangeUser(0.01,10);
 f4Rap->GetXaxis()->SetTitle("|y| ");
 f4Rap->GetYaxis()->SetTitle("(#frac{1}{L_{pp}},#frac{1}{T_{AA}N_{MB}}) #frac{dN}{A #varepsilon dy}   [nb]");
 f4Rap->GetXaxis()->CenterTitle(kTRUE);
 f4Rap->Draw();
 //pbpb data
 TGraphErrors *grap1 = new TGraphErrors(nRapBins_2014,rap2014,CS1S_aa_rap,rap2014e,CS1S_aa_rape);
 grap1->SetMarkerColor(8);
 grap1->SetMarkerStyle(33);
 grap1->SetMarkerSize(2);
 TGraphErrors *grap1circle = new TGraphErrors(nRapBins_2014,rap2014,CS1S_aa_rap,rap2014e,CS1S_aa_rape);
 grap1circle->SetMarkerStyle(27);
 grap1circle->SetMarkerSize(2);
 grap1circle->SetLineColor(kBlack);
 if(!plotTNP){ grap1->Draw("pe");
   grap1circle->Draw("p");
   f4Rap->Draw("same");
 }
 gPad->RedrawAxis();
 TGraphErrors *grap1pp = new TGraphErrors(nRapBins_2014,rap2014,CS1S_pp_rap2014,rap2014e,CS1S_pp_rap2014e);
 grap1pp->SetMarkerColor(kAzure+1);
 grap1pp->SetMarkerStyle(21);
 grap1pp->SetMarkerSize(1.2);
 TGraphErrors *grap1circlepp = new TGraphErrors(nRapBins_2014,rap2014,CS1S_pp_rap2014,rap2014e,CS1S_pp_rap2014e);
 grap1circlepp->SetMarkerStyle(25);
 grap1circlepp->SetMarkerSize(1.22);
 grap1circlepp->SetLineColor(kBlack);
 if(!plotTNP) {
   grap1pp->Draw("pe");
   grap1circlepp->Draw("p");
 }
 f4Rap->Draw("same");

 if(plotTNP){
   TGraphErrors *gRap1syst = new TGraphErrors(nRapBins_2014,rap2014,CS1S_aa_tnp_rap2014,rap2014e,CS1S_aa_tnp_rap2014s);
   gRap1syst->SetLineColor(kOrange+1);
   gRap1syst->SetFillStyle(0);
   gRap1syst->SetLineWidth(2);
   gRap1syst->SetMarkerSize(0);
   gRap1syst->Draw("2");
   TGraphErrors *grap1TNP = new TGraphErrors(nRapBins_2014,rap2014,CS1S_aa_tnp_rap2014,0,CS1S_aa_tnp_rap2014e);
   grap1TNP->SetMarkerColor(kOrange+1);
   grap1TNP->SetMarkerStyle(21);
   grap1TNP->SetMarkerSize(1);
   TGraphErrors *grap1TNPcircle = new TGraphErrors(nRapBins_2014,rap2014,CS1S_aa_tnp_rap2014,0,CS1S_aa_tnp_rap2014e);
   grap1TNPcircle->SetMarkerStyle(25);
   grap1TNPcircle->SetMarkerSize(1);
   grap1TNPcircle->SetLineColor(kBlack);
   grap1TNP->Draw("pe");
   grap1TNPcircle->Draw("p");
   f4Rap->Draw("same");
   gPad->RedrawAxis();
   TGraphErrors *gRap1ppsyst = new TGraphErrors(nRapBins_2014,rap2014,CS1S_pp_tnp_rap2014,rap2014e,CS1S_pp_tnp_rap2014s);
   gRap1ppsyst->SetLineColor(kAzure+1);
   gRap1ppsyst->SetFillStyle(0);
   gRap1ppsyst->SetLineWidth(2);
   gRap1ppsyst->SetMarkerSize(0);
   gRap1ppsyst->Draw("2");
   TGraphErrors *grap1TNPpp = new TGraphErrors(nRapBins_2014,rap2014,CS1S_pp_tnp_rap2014,0,CS1S_pp_tnp_rap2014e);
   grap1TNPpp->SetMarkerColor(1);
   grap1TNPpp->SetMarkerStyle(20);
   grap1TNPpp->SetMarkerSize(1);
   TGraphErrors *grap1TNPcirclepp = new TGraphErrors(nRapBins_2014,rap2014,CS1S_pp_tnp_rap2014,0,CS1S_pp_tnp_rap2014e);
   grap1TNPcirclepp->SetMarkerStyle(24);
   grap1TNPcirclepp->SetMarkerSize(1);
   grap1TNPcirclepp->SetLineColor(kBlack);
   grap1TNPpp->Draw("pe");
   grap1TNPcirclepp->Draw("p");
   f4Rap->Draw("same");
 }
 TLatex *l1CMSpt = new TLatex(0.15,5, "CMS Internal #sqrt{s_{NN}} = 2.76 TeV");
 l1CMSpt->SetTextFont(42);
 l1CMSpt->SetTextSize(0.038);
 l1CMSpt->Draw();

 
 TLatex *lyL= new TLatex(0.15,3,"L_{PbPb} = 166 #mub^{-1}; |y| < 2.4");
 
 lyL->SetTextSize(0.029);
 lyL->DrawLatex(0.15,2,"L_{pp} = 5.4 pb^{-1}; |y| < 2.4");
 lyL->Draw();

TLegend *legendB = new TLegend(0.65,0.82,0.88,0.72);
legendB->SetTextSize(0.029);
legendB->SetFillStyle(0);
legendB->SetFillColor(0);
legendB->SetBorderSize(0);
legendB->SetTextFont(42);
 if(!plotTNP){legendB->AddEntry(grap1,"#varUpsilon(1S) PbPb ","lp");
   legendB->AddEntry(grap1pp,"#varUpsilon(1S) pp ","lp");}
 if(plotTNP){
   legendB->AddEntry(grap1TNP,"#varUpsilon(1S) PbPb","lp");
   legendB->AddEntry(grap1TNPpp,"#varUpsilon(1S) pp","lp");
 }
 legendB->Draw();

 // gPad->RedrawAxis();
 crap->SaveAs("~/Documents/PR/forTWiki/CSandRAA/CS1S_ppAA_Rap.pdf");
 crap->SaveAs("~/Desktop/Xsection_ppAA_1S_Rap.png");
 prap1->Close();
 TPad *prap2 = new TPad("prap2","prap2",0.0,0.0,1.0,0.9);
 prap2->SetBottomMargin(0.12);
 prap2->SetTopMargin(0.03);
 prap2->SetRightMargin(0.03);
 prap2->SetLeftMargin(0.16);
 prap2->SetLogy();
 prap2->Draw();
 prap2->cd();
 TLatex *l1CMSrap = new TLatex(0.7,1.27,"CMS");
 l1CMSrap->SetTextFont(62);
 l1CMSrap->SetTextSize(0.06);
 l1CMSrap->Draw();
 TLatex *l1CMSpt = new TLatex(0.15,5, "CMS Internal #sqrt{s_{NN}} = 2.76 TeV");
 l1CMSpt->SetTextFont(42);
 l1CMSpt->SetTextSize(0.038);
 l1CMSpt->Draw();
 TLatex *lyL= new TLatex(0.15,3,"L_{PbPb} = 166 #mub^{-1}; |y| < 2.4");
 lyL->SetTextSize(0.029);
 lyL->DrawLatex(0.15,2,"L_{pp} = 5.4 pb^{-1}; |y| < 2.4");
 lyL->Draw();
 crap->SaveAs("~/Desktop/test.pdf");

 TCanvas *crapaa = new TCanvas("crapaa","crapaa"); 
 crapaa->SetLogy();
 crapaa->cd();
 // TPad *prap1 = new TPad("prap1","prap1",0.0,0.0,1.0,0.9);
 // prap1->SetBottomMargin(0.12);
 // prap1->SetTopMargin(0.03);
 // prap1->SetRightMargin(0.03);
 // prap1->SetLeftMargin(0.16);
 // prap1->SetLogy();
 // prap1->Draw();
 // prap1->cd();
 TF1 *f4Rapaa = new TF1("f4Rapaa","10",0,2.4);
 f4Rapaa->SetLineWidth(0);
 // f4Rapaa->GetYaxis()->SetTitleOffset(1.5);
 // f4Rapaa->GetYaxis()->SetTitleSize(0.035);
 f4Rapaa->GetYaxis()->SetRangeUser(0.01,1.);
 f4Rapaa->GetXaxis()->SetTitle("|y|");
 f4Rapaa->GetYaxis()->SetTitle("#frac{1}{T_{AA}} #frac{dN}{dy} [nb]");
 f4Rapaa->GetXaxis()->CenterTitle(kTRUE);
 f4Rapaa->GetXaxis()->SetNdivisions(6,8,0,kFALSE);
 f4Rapaa->GetYaxis()->SetTitleOffset(f4Rapaa->GetYaxis()->GetTitleOffset()*0.85);
 f4Rapaa->Draw();
 gRap1syst->Draw("2");
 grap1TNP->Draw("pe");
 grap1TNPcircle->Draw("p");
 TGraphErrors *gRap2syst = new TGraphErrors(nRapBins_2010,rap2010,CS2S_aa_tnp_rap,rap2010e,CS2S_aa_tnp_raps);
 gRap2syst->SetLineColor(kOrange+4);
 gRap2syst->SetFillStyle(0);
 gRap2syst->SetLineWidth(2);
 gRap2syst->SetMarkerSize(0);
 gRap2syst->Draw("2");
 TGraphErrors *grap2TNP = new TGraphErrors(nRapBins_2010,rap2010,CS2S_aa_tnp_rap,0,CS2S_aa_tnp_rape);
 grap2TNP->SetMarkerColor(kOrange+4);
 grap2TNP->SetMarkerStyle(20);
 grap2TNP->SetMarkerSize(1);
 TGraphErrors *grap2TNPcircle = new TGraphErrors(nRapBins_2010,rap2010,CS2S_aa_tnp_rap,0,CS2S_aa_tnp_rape);
 grap2TNPcircle->SetMarkerStyle(24);
 grap2TNPcircle->SetMarkerSize(1);
 grap2TNPcircle->SetLineColor(kBlack);
 grap2TNP->Draw("pe");
 grap2TNPcircle->Draw("p");
 gPad->RedrawAxis();
 TLegend *legendB = new TLegend(0.23,0.44,0.46,0.56);
 legendB->SetTextSize(0.035);
 legendB->SetFillStyle(0);
 legendB->SetFillColor(0);
 legendB->SetBorderSize(0);
 legendB->SetTextFont(42);
 if(!plotTNP){legendB->AddEntry(grap1,"#varUpsilon(1S) PbPb ","lp");
   legendB->AddEntry(grap2TNP,"#varUpsilon(2S) PbPb ","lp");}
 if(plotTNP){
   legendB->AddEntry(grap1TNP,"#varUpsilon(1S) ","lp");
   legendB->AddEntry(grap2TNP,"#varUpsilon(2S) ","lp");
 }
 legendB->Draw();
 crapaa->cd();

    CMS_lumi(gPad,101,33);
    gPad->Update();
    gPad->RedrawAxis();
    gPad->GetFrame()->Draw();

    TLatex latexrapaa;
    latexrapaa.SetTextSize(gTextSize);
    latexrapaa.SetTextFont(42);
    latexrapaa.DrawLatex(1.6,0.1,"Cent. 0-100%");

 crapaa->SaveAs("~/Documents/PR/forTWiki/CSandRAA/CS_AA_Rap.pdf");
 crapaa->SaveAs("~/Desktop/Xsection_AA_1S2S_Rap.png");
 //////////////////////////////////////////////
 TCanvas *crappp = new TCanvas("crappp","crappp"); 
 crappp->SetLogy();
 crappp->cd();
 // TPad *prap1 = new TPad("prap1","prap1",0.0,0.0,1.0,0.91);
 // prap1->SetBottomMargin(0.12);
 // prap1->SetTopMargin(0.03);
 // prap1->SetRightMargin(0.03);
 // prap1->SetLeftMargin(0.16);
 // prap1->SetLogy();
 // prap1->Draw();
 // prap1->cd();
 TF1 *f4Rap = new TF1("f4Rap","10",0,2.4);
 f4Rap->SetLineWidth(0);
 // f4Rap->GetYaxis()->SetTitleOffset(1.5);
 // f4Rap->GetYaxis()->SetTitleSize(0.035);
 f4Rap->GetYaxis()->SetRangeUser(0.01,5);
 f4Rap->GetXaxis()->SetTitle("|y|");
 f4Rap->GetYaxis()->SetTitle("#frac{d#sigma}{dy}   [nb]");
 f4Rap->GetXaxis()->CenterTitle(kTRUE);
 f4Rap->GetXaxis()->SetNdivisions(6,8,0,kFALSE);
 f4Rap->GetYaxis()->SetTitleOffset(f4Rap->GetYaxis()->GetTitleOffset()*0.9);
 f4Rap->Draw();
 if(!plotTNP){
   //pp data
   TGraphErrors *grap2pp = new TGraphErrors(nRapBins_2014,rap2014,CS2S_pp_rap2014,0,CS2S_pp_rap2014e);
   grap2pp->SetMarkerColor(1);
   grap2pp->SetMarkerStyle(20);
   grap2pp->SetMarkerSize(1.2);
   TGraphErrors *grap3pp = new TGraphErrors(nRapBins_2014,rap2014,CS3S_pp_rap2014,0,CS3S_pp_rap2014e);
   grap3pp->SetMarkerColor(1);
   grap3pp->SetMarkerStyle(22);
   grap3pp->SetMarkerSize(1.2);
   grap2pp->Draw("pe");
   g2rapcircle->Draw("p");
   TGraphErrors *g3rapcircle = new TGraphErrors(nRapBins_2014,rap2014,CS3S_pp_rap2014,rap2014e,CS3S_pp_rap2014e);
   g3rapcircle->SetMarkerStyle(25);
   g3rapcircle->SetMarkerSize(1.3);
   g3rapcircle->SetLineColor(kBlack);
   grap3pp->Draw("pe");
   g3rapcircle->Draw("p");
   TGraphErrors *grap1pp = new TGraphErrors(nRapBins_2014,rap2014,CS1S_pp_rap2014,0,CS1S_pp_rap2014e);
   grap1pp->SetMarkerColor(1);
   grap1pp->SetMarkerStyle(21);
   grap1pp->SetMarkerSize(1.2);
   TGraphErrors *grap1circlepp = new TGraphErrors(nRapBins_2014,rap2014,CS1S_pp_rap2014,0,CS1S_pp_rap2014e);
   grap1circlepp->SetMarkerStyle(25);
   grap1circlepp->SetMarkerSize(1.22);
   grap1circlepp->SetLineColor(kBlack);
   grap1pp->Draw("pe");
   grap1circlepp->Draw("p");
 }else{
   TGraphErrors *gRap1ppsyst = new TGraphErrors(nRapBins_2014,rap2014,CS1S_pp_tnp_rap2014,rap2014e,CS1S_pp_tnp_rap2014s);
   gRap1ppsyst->SetLineColor(kAzure+1);
   gRap1ppsyst->SetFillStyle(0);
   gRap1ppsyst->SetLineWidth(2);
   gRap1ppsyst->SetMarkerSize(0);
   gRap1ppsyst->Draw("2");
   TGraphErrors *grap1TNPpp = new TGraphErrors(nRapBins_2014,rap2014,CS1S_pp_tnp_rap2014,0,CS1S_pp_tnp_rap2014e);
   grap1TNPpp->SetMarkerColor(1);
   grap1TNPpp->SetMarkerStyle(20);
   grap1TNPpp->SetMarkerSize(1);
   TGraphErrors *grap1TNPcirclepp = new TGraphErrors(nRapBins_2014,rap2014,CS1S_pp_tnp_rap2014,0,CS1S_pp_tnp_rap2014e);
   grap1TNPcirclepp->SetMarkerStyle(24);
   grap1TNPcirclepp->SetMarkerSize(1);
   grap1TNPcirclepp->SetLineColor(kBlack);
   grap1TNPpp->Draw("pe");
   grap1TNPcirclepp->Draw("p");
   f4Rap->Draw("same");
   TGraphErrors *grap2ppTNP = new TGraphErrors(nRapBins_2014,rap2014,CS2S_pp_tnp_rap2014,0,CS2S_pp_tnp_rap2014e);
   grap2ppTNP->SetMarkerColor(1);
   grap2ppTNP->SetMarkerStyle(20);
   grap2ppTNP->SetMarkerSize(1.2);
   TGraphErrors *grap3ppTNP = new TGraphErrors(nRapBins_2014,rap2014,CS3S_pp_tnp_rap2014,0,CS3S_pp_tnp_rap2014e);
   grap3ppTNP->SetMarkerColor(1);
   grap3ppTNP->SetMarkerStyle(22);
   grap3ppTNP->SetMarkerSize(1.2);
   TGraphErrors *g2rapcircleTNP = new TGraphErrors(nRapBins_2014,rap2014,CS2S_pp_tnp_rap2014,0,CS2S_pp_tnp_rap2014e);
   g2rapcircleTNP->SetMarkerStyle(24);
   g2rapcircleTNP->SetMarkerSize(1.);
   g2rapcircleTNP->SetLineColor(kBlack);
   TGraphErrors *g3rapcircleTNP = new TGraphErrors(nRapBins_2014,rap2014,CS3S_pp_tnp_rap2014,0,CS3S_pp_tnp_rap2014e);
   g3rapcircleTNP->SetMarkerStyle(26);
   g3rapcircleTNP->SetMarkerSize(1.);
   g3rapcircleTNP->SetLineColor(kBlack);
   TGraphErrors *gRap2ppsyst = new TGraphErrors(nRapBins_2014,rap2014,CS2S_pp_tnp_rap2014,rap2014e,CS2S_pp_tnp_rap2014s);
   gRap2ppsyst->SetLineColor(kAzure+1);
   gRap2ppsyst->SetFillStyle(0);
   gRap2ppsyst->SetLineWidth(2);
   gRap2ppsyst->SetMarkerSize(0);
   gRap2ppsyst->Draw("2");
   grap2ppTNP->Draw("pe");
   g2rapcircleTNP->Draw("p");
   TGraphErrors *gRap3ppsyst = new TGraphErrors(nRapBins_2014,rap2014,CS3S_pp_tnp_rap2014,rap2014e,CS3S_pp_tnp_rap2014s);
   gRap3ppsyst->SetLineColor(kAzure+1);
   gRap3ppsyst->SetFillStyle(0);
   gRap3ppsyst->SetLineWidth(2);
   gRap3ppsyst->SetMarkerSize(0);
   gRap3ppsyst->Draw("2");
   grap3ppTNP->Draw("pe");
   g3rapcircleTNP->Draw("p");
   TGraphErrors *gRap1ppsyst = new TGraphErrors(nRapBins_2014,rap2014,CS1S_pp_tnp_rap2014,rap2014e,CS1S_pp_tnp_rap2014s);
   gRap1ppsyst->SetLineColor(kAzure+1);
   gRap1ppsyst->SetFillStyle(0);
   gRap1ppsyst->SetLineWidth(2);
   gRap1ppsyst->SetMarkerSize(0);
   gRap1ppsyst->Draw("2");
   grap1TNPpp->Draw("pe");
   grap1TNPcirclepp->Draw("p");
 
 }
 // f4Rap->Draw("same");


 // TLatex *l1CMSpt = new TLatex(0.15,6, "CMS Internal #sqrt{s} = 2.76 TeV");
 // l1CMSpt->SetTextFont(42);
 // l1CMSpt->SetTextSize(0.038);
 // l1CMSpt->Draw();

 
 // TLatex *lyL= new TLatex();//0.15,3,"L_{PbPb} = 166 #mub^{-1}; |y| < 2.4");
 
 // lyL->SetTextSize(0.029);
 // lyL->DrawLatex(0.15,2,"L_{pp} = 5.4 pb^{-1}; |y| < 2.4");
 // lyL->Draw();

 TLegend *legendB = new TLegend(0.22,0.18,0.40,0.37);
 legendB->SetTextSize(gTextSize);
 legendB->SetFillStyle(0);
 legendB->SetFillColor(0);
 legendB->SetBorderSize(0);
 legendB->SetTextFont(42);
 if(!plotTNP){
   legendB->AddEntry(grap1pp,"#varUpsilon(1S) ","pe");
   legendB->AddEntry(grap2pp,"#varUpsilon(2S) ","pe");
   legendB->AddEntry(grap3pp,"#varUpsilon(3S) ","pe");
 }else{
   legendB->AddEntry(grap1TNPpp,"#varUpsilon(1S) ","pe");
   legendB->AddEntry(grap2ppTNP,"#varUpsilon(2S) ","pe");
   legendB->AddEntry(grap3ppTNP,"#varUpsilon(3S) ","pe");
 } legendB->Draw();

 gPad->RedrawAxis();


    CMS_lumi(gPad,102,33);
    gPad->Update();
    gPad->RedrawAxis();
    gPad->GetFrame()->Draw();

 crappp->SaveAs("~/Documents/PR/forTWiki/CSandRAA/CS1S_ppRap.pdf"); 
 crappp->SaveAs("~/Desktop/Xsection_pp_1S_Rap.png");
 //////////////////////////////////////////////////////////////////
 }

if(plotRAA){
  TCanvas *cRaarap = new TCanvas("cRaarap","cRaarap"); 
  cRaarap->cd();
  // TPad *prap2 = new TPad("prap2","prap2",0.0,0.0,0.98,0.92);
  // // prap2->SetBottomMargin(0.12);
  // // prap2->SetTopMargin(0.03);
  // // prap2->SetRightMargin(0.03);
  // // prap2->SetLeftMargin(0.12);
  // // prap2->Draw();
  // prap2->cd();
  //one pad to draw RaaRap!
  TF1 *f4RaaRap = new TF1("f4RaaRap","1",0.0,2.4);
  f4RaaRap->SetLineWidth(0);
  f4RaaRap->SetLineColor(kBlack);
  f4RaaRap->GetXaxis()->SetTitle("|y|");
  f4RaaRap->GetYaxis()->SetTitle("R_{AA}");
  // f4RaaRap->GetYaxis()->SetTitleOffset(1.1);
  // f4RaaRap->GetYaxis()->SetTitleSize(0.05);
  f4RaaRap->GetYaxis()->SetRangeUser(0.,1.4);
  f4RaaRap->GetXaxis()->CenterTitle(kTRUE);
  f4RaaRap->GetXaxis()->SetNdivisions(6,8,0,kFALSE);
  f4RaaRap->Draw();
  TGraphErrors *gRaaRap1 = new TGraphErrors(nRapBins_2014,rap2014,RAA_1S_rap,rap2014e,RAA_1S_rape);
  gRaaRap1->SetMarkerColor(8);
  gRaaRap1->SetMarkerStyle(21);
  gRaaRap1->SetMarkerSize(1);
  TGraphErrors *gRaaRap1circle = new TGraphErrors(nRapBins_2014,rap2014,RAA_1S_rap,rap2014e,RAA_1S_rape);
  gRaaRap1circle->SetMarkerStyle(25);
  gRaaRap1circle->SetMarkerSize(1);
  gRaaRap1circle->SetLineColor(kBlack);
  if(!plotTNP){ gRaaRap1->Draw("pe");
    gRaaRap1circle->Draw("p");
    f4RaaRap->Draw("same");}
  gPad->RedrawAxis();
  if(plotTNP)
    {
      TGraphErrors *gRaaRap1syst = new TGraphErrors(nRapBins_2014,rap2014,RAA_1S_tnp_rap,rap2014e,RAA_1S_tnp_raps);
      gRaaRap1syst->SetLineColor(kOrange+1);
      gRaaRap1syst->SetFillStyle(0);
      gRaaRap1syst->SetLineWidth(2);
      gRaaRap1syst->SetMarkerSize(0);
      gRaaRap1syst->Draw("2");
      TGraphErrors *gRaaRap1TNP = new TGraphErrors(nRapBins_2014,rap2014,RAA_1S_tnp_rap,0,RAA_1S_tnp_rape);
      gRaaRap1TNP->SetMarkerColor(kOrange+1);
      gRaaRap1TNP->SetMarkerStyle(21);
      gRaaRap1TNP->SetMarkerSize(1);
      TGraphErrors *gRaaRap1TNPcircle = new TGraphErrors(nRapBins_2014,rap2014,RAA_1S_tnp_rap,0,RAA_1S_tnp_rape);
      gRaaRap1TNPcircle->SetMarkerStyle(25);
      gRaaRap1TNPcircle->SetMarkerSize(1);
      gRaaRap1TNPcircle->SetLineColor(kBlack);
      gRaaRap1TNP->Draw("pe");
      gRaaRap1TNPcircle->Draw("p");
      f4RaaRap->Draw("same");
      gPad->RedrawAxis();
      if(plotTight){
	TGraphErrors *gRaaRap1syst4 = new TGraphErrors(nRapBins_2014,rap2014,RAA_1S_tnp_rap4,rap2014e,RAA_1S_tnp_rap4s);
	gRaaRap1syst4->SetLineColor(kGreen+1);
	gRaaRap1syst4->SetFillStyle(0);
	gRaaRap1syst4->SetLineWidth(2);
	gRaaRap1syst4->SetMarkerSize(0);
	gRaaRap1syst4->Draw("2");
	TGraphErrors *gRaaRap1TNP4 = new TGraphErrors(nRapBins_2014,rap2014Shift,RAA_1S_tnp_rap4,0,RAA_1S_tnp_rap4e);
	gRaaRap1TNP4->SetMarkerColor(kGreen+1);
	gRaaRap1TNP4->SetMarkerStyle(21);
	gRaaRap1TNP4->SetMarkerSize(1);
	TGraphErrors *gRaaRap1TNPcircle4 = new TGraphErrors(nRapBins_2014,rap2014Shift,RAA_1S_tnp_rap4,0,RAA_1S_tnp_rap4e);
	gRaaRap1TNPcircle4->SetMarkerStyle(25);
	gRaaRap1TNPcircle4->SetMarkerSize(1);
	gRaaRap1TNPcircle4->SetLineColor(kBlack);
	gRaaRap1TNP4->Draw("pe");
	gRaaRap1TNPcircle4->Draw("p");
	f4RaaRap->Draw("same");
	gPad->RedrawAxis(); 
      }
      else{
	TGraphErrors *gRaaRap2TNP = new TGraphErrors(nRapBins_2010,rap2010,RAA_2S_tnp_rap,0,RAA_2S_tnp_rape);
	gRaaRap2TNP->SetMarkerColor(kOrange+4);
	gRaaRap2TNP->SetMarkerStyle(20);
	gRaaRap2TNP->SetMarkerSize(1);
	TGraphErrors *gRaaRap2TNPcircle = new TGraphErrors(nRapBins_2010,rap2010,RAA_2S_tnp_rap,0,RAA_2S_tnp_rape);
	gRaaRap2TNPcircle->SetMarkerStyle(24);
	gRaaRap2TNPcircle->SetMarkerSize(1);
	gRaaRap2TNPcircle->SetLineColor(kBlack);
	TGraphErrors *gRaaRap2syst = new TGraphErrors(nRapBins_2010,rap2010,RAA_2S_tnp_rap,rap2010e,RAA_2S_tnp_raps);
	gRaaRap2syst->SetLineColor(kOrange+4);
	gRaaRap2syst->SetFillStyle(0);
	gRaaRap2syst->SetLineWidth(2);
	gRaaRap2syst->SetMarkerSize(0);
	gRaaRap2syst->Draw("2");
	gRaaRap2TNP->Draw("pe");
	gRaaRap2TNPcircle->Draw("p");
	f4RaaRap->Draw("same");
	gPad->RedrawAxis();
      }
    }
  TBox *box = new TBox(2.27,1-syst1S_raa_global,2.4,1+syst1S_raa_global);
  box->SetFillColor(kGray);//kOrange+1);
  box->Draw();
  // TBox *box2 = new TBox(2.27,1-syst2S_raa_global,2.4,1+syst2S_raa_global);
  // box2->SetFillColor(kOrange+4);
  // box2->Draw();
  if(plotTight){
    TBox *box1S4 = new TBox(2.14,1-syst1S_pp_glob,2.27,1+syst1S_pp_glob);
    box1S4->SetFillColor(kGreen+1);
    box1S4->Draw();
  }
  // TLatex *l1CMSrap = new TLatex(0.2,1.45, "CMS Internal #sqrt{s_{NN}} = 2.76 TeV");
  // l1CMSrap->SetTextFont(42);
  // l1CMSrap->SetTextSize(0.038);
  // l1CMSrap->Draw();
  // TLatex *lyLRAP= new TLatex(0.2,1.25,"2011 L_{int}^{PbPb} = 166 #mub^{-1}; 2013 L_{int}^{pp} = 5.4 pb^{-1};");
  // lyLRAP->SetTextFont(42);
  // lyLRAP->SetTextSize(0.027);
  // lyLRAP->Draw();
  // if(plot2010) {lyLRAP->DrawLatex(0.2,1.35,"2010 L_{int}^{PbPb} = 7.28 #mub^{-1}; L_{int}^{pp} = 231 nb^{-1};");}
  prap2->Update();
  TLegend *legend = new TLegend(0.23,0.50,0.39,0.65);
  legend->SetTextSize(gTextSize);
  legend->SetFillStyle(0);
  legend->SetFillColor(0);
  legend->SetBorderSize(0);
  legend->SetTextFont(42);
  if(plot2010){
    TGraphErrors *grap2010 = new TGraphErrors(nRapBins_2010,rap2010,raaRap2010,rap2010e,raaRap2010e);
    grap2010->SetMarkerColor(kTeal+3);
    grap2010->SetMarkerStyle(33);
    grap2010->SetMarkerSize(2);
  
    TGraphErrors *grap2010s = new TGraphErrors(nRapBins_2010,rap2010,raaRap2010,centnoErr,raaRap2010s);
    grap2010s->SetLineColor(8);
    grap2010s->SetLineWidth(18);
    grap2010s->SetMarkerSize(0);
    grap2010s->Draw("e");
  
    grap2010->Draw("pe");
  
    TGraphErrors *grap2010circle = new TGraphErrors(nRapBins_2010,rap2010,raaRap2010,rap2010e,raaRap2010e);
    grap2010circle->SetMarkerStyle(27);
    grap2010circle->SetMarkerSize(2);
    grap2010circle->SetLineColor(kBlack);
    grap2010circle->Draw("p");
    legend->AddEntry(grap2010,"#varUpsilon(1S) JHEP 05 (2012) 063","lp");
    f4RaaRap->Draw("same");
  }
  gPad->RedrawAxis(); 
    TLegend *leg2= new TLegend(0.57,0.54,0.73,0.62);
    leg2->SetBorderSize(0);
    leg2->SetTextSize(gTextSize);
    leg2->SetTextFont(42);
    leg2->SetLineColor(0);
    leg2->SetLineStyle(1);
    leg2->SetLineWidth(0.4);
    leg2->SetFillColor(0);
    leg2->SetFillStyle(0);
    leg2->AddEntry(box,"global syst.","f");
    //  leg2->AddEntry(box2,"#varUpsilon(2S) global syst.","f");
    leg2->Draw();
 
    // Cent. 0-100 %
    TLatex latexrap;
    latexrap.SetTextSize(gTextSize);
    latexrap.SetTextFont(42);
    latexrap.DrawLatex(0.15,1.2,"Cent. 0-100%");
   
  if(!plotTNP) {legend->AddEntry(gRaaRap1,"#varUpsilon(1S)","pe");
    legend->AddEntry(gRaaRap2TNP,"#varUpsilon(2S)","pe");}
  if(plotTNP) {
    legend->AddEntry(gRaaRap1TNP,"#varUpsilon(1S)","pe");
    if(plotTight){
      legend->AddEntry(gRaaRap1TNP4,"#varUpsilon(1S) 'tight'","lp");
    }else{
      legend->AddEntry(gRaaRap2TNP,"#varUpsilon(2S)","pe");
    }
  }
  legend->Draw();

  gPad->RedrawAxis();
    cRaarap->cd();

    CMS_lumi(cRaarap,103,33);
    cRaarap->Update();
    cRaarap->RedrawAxis();
    cRaarap->GetFrame()->Draw();

  if(plotTight){
    cRaarap->SaveAs("~/Documents/PR/forTWiki/CSandRAA/RAA_Rap4.pdf");
    cRaarap->SaveAs("~/Desktop/RAA_Rap4.png");
  }else{
    cRaarap->SaveAs("~/Documents/PR/forTWiki/CSandRAA/RAA_Rap.pdf");
    cRaarap->SaveAs("~/Desktop/RAA_Rap.png");
  }
 }

 plot2010();
 plotRAA_uncorr();
 if(plotPA) plotDoubleRatios();
 if(plotEffOrAcc){
  TCanvas *cAccComp1 = new TCanvas("cAccComp1","cAccComp1"); 
  cAccComp1->cd();
  TPad *pComp1 = new TPad("pComp1","pComp1",0.0,0.0,1.0,1.0);
  pComp1->SetBottomMargin(0.12);
  pComp1->SetTopMargin(0.03);
  pComp1->SetRightMargin(0.03);
  pComp1->SetLeftMargin(0.16);
  pComp1->Draw();
  pComp1->cd();
  TF1 *f4CompRap = new TF1("f4CompRap","1",0,2.45);
  f4CompRap->SetLineWidth(0);
  f4CompRap->GetXaxis()->SetTitle("|y|");
  f4CompRap->GetYaxis()->SetTitle("#frac{A_{pp}}{A_{PbPb}}");
  f4CompRap->GetYaxis()->SetTitleOffset(1.8);
  f4CompRap->GetYaxis()->SetTitleSize(0.028);
  f4CompRap->GetYaxis()->SetRangeUser(0.,2);
  f4CompRap->GetXaxis()->CenterTitle(kTRUE);
  f4CompRap->Draw();
  TGraphErrors *gCompRap1 = new TGraphErrors(nRapBins_2014,rap2014,R_A_1S_rap,rap2014e,R_A_1S_rape);
  gCompRap1->SetMarkerColor(kRed);
  gCompRap1->SetMarkerStyle(21);
  gCompRap1->SetMarkerSize(1.2);
  TGraphErrors *gCompRap1circle = new TGraphErrors(nRapBins_2014,rap2014,R_A_1S_rap,rap2014e,R_A_1S_rape);
  gCompRap1circle->SetMarkerStyle(25);
  gCompRap1circle->SetMarkerSize(1.2);
  gCompRap1circle->SetLineColor(kBlack);
  gCompRap1->Draw("pe");
  gCompRap1circle->Draw("p");
  f4CompRap->Draw("same");
  gPad->RedrawAxis();
  TLegend *legend = new TLegend(0.482,0.84,0.88,0.7);
  legend->SetTextSize(0.029);
  legend->SetFillStyle(0);
  legend->SetFillColor(0);
  legend->SetBorderSize(0);
  legend->SetTextFont(42);
  legend->AddEntry(gCompRap1,"#varUpsilon(1S) A_{pp}/A_{PbPb} ","lp");
  legend->Draw();


  TCanvas *cAccComp2 = new TCanvas("cAccComp2","cAccComp2"); 
  cAccComp2->cd();
  TPad *pComp2 = new TPad("pComp2","pComp2",0.0,0.0,1.0,1.0);
  pComp2->SetBottomMargin(0.12);
  pComp2->SetTopMargin(0.03);
  pComp2->SetRightMargin(0.03);
  pComp2->SetLeftMargin(0.16);
  pComp2->Draw();
  pComp2->cd();
  TF1 *f4CompPt = new TF1("f4CompPt","1",0,20);
  f4CompPt->SetLineWidth(0);
  f4CompPt->GetXaxis()->SetTitle("p_{T}^{#varUpsilon}");
  f4CompPt->GetYaxis()->SetTitle("#frac{A_{pp}}{A_{PbPb}}");
  f4CompPt->GetYaxis()->SetTitleOffset(1.8);
  f4CompPt->GetYaxis()->SetTitleSize(0.028);
  f4CompPt->GetYaxis()->SetRangeUser(0.,2.);
  f4CompPt->GetXaxis()->CenterTitle(kTRUE);
  f4CompPt->Draw();
  TGraphErrors *gCompPt1 = new TGraphErrors(nPtBins_2013,pt,R_A_1S_pt,pte,R_A_1S_pte);
  gCompPt1->SetMarkerColor(kRed);
  gCompPt1->SetMarkerStyle(21);
  gCompPt1->SetMarkerSize(1.2);
  TGraphErrors *gCompPt1circle = new TGraphErrors(nPtBins_2013,pt,R_A_1S_pt,pte,R_A_1S_pte);
  gCompPt1circle->SetMarkerStyle(25);
  gCompPt1circle->SetMarkerSize(1.2);
  gCompPt1circle->SetLineColor(kBlack);
  gCompPt1->Draw("pe");
  gCompPt1circle->Draw("p");
  f4CompPt->Draw("same");
  gPad->RedrawAxis();
  TLegend *legend = new TLegend(0.482,0.84,0.88,0.7);
  legend->SetTextSize(0.029);
  legend->SetFillStyle(0);
  legend->SetFillColor(0);
  legend->SetBorderSize(0);
  legend->SetTextFont(42);
  legend->AddEntry(gCompPt1,"#varUpsilon(1S) A_{pp}/A_{PbPb} ","lp");
  legend->Draw();

  TCanvas *cAccEffComp1 = new TCanvas("cAccEffComp1","cAccEffComp1"); 
  cAccEffComp1->cd();
  TPad *pAccEffComp1 = new TPad("pAccEffComp1","pAccEffComp1",0.0,0.0,1.0,1.0);
  pAccEffComp1->SetBottomMargin(0.12);
  pAccEffComp1->SetTopMargin(0.03);
  pAccEffComp1->SetRightMargin(0.03);
  pAccEffComp1->SetLeftMargin(0.16);
  pAccEffComp1->Draw();
  pAccEffComp1->cd();
  TF1 *f4CompRap = new TF1("f4CompRap","1",0,2.45);
  f4CompRap->SetLineWidth(0);
  f4CompRap->GetXaxis()->SetTitle("|y|");
  f4CompRap->GetYaxis()->SetTitle("A #times #varepsilon_{pp,AA}");
  f4CompRap->GetYaxis()->SetTitleOffset(1.8);
  f4CompRap->GetYaxis()->SetTitleSize(0.028);
  f4CompRap->GetYaxis()->SetRangeUser(0.,0.5);
  f4CompRap->GetXaxis()->CenterTitle(kTRUE);
  f4CompRap->Draw();
  TGraphErrors *gCompAccEffRap1 = new TGraphErrors(nRapBins_2014,rap2014,Ae_1S_pythia_rap2014,rap2014e,Ae_1S_pythia_rap2014e);
  gCompAccEffRap1->SetMarkerColor(kRed);
  gCompAccEffRap1->SetMarkerStyle(23);
  gCompAccEffRap1->SetMarkerSize(1.2);
  TGraphErrors *gCompAccEffRap1circle = new TGraphErrors(nRapBins_2014,rap2014,Ae_1S_pythia_rap2014,rap2014e,Ae_1S_pythia_rap2014e);
  gCompAccEffRap1circle->SetMarkerStyle(32);
  gCompAccEffRap1circle->SetMarkerSize(1.2);
  gCompAccEffRap1circle->SetLineColor(kBlack);
  gCompAccEffRap1->Draw("pe");
  gCompAccEffRap1circle->Draw("p");
  f4CompRap->Draw("same");
  gPad->RedrawAxis();

  TGraphErrors *gCompAccEffRap1aa = new TGraphErrors(nRapBins_2014,rap2014,Ae_1S_pyquen_rap2014,rap2014e,Ae_1S_pyquen_rap2014e);
  gCompAccEffRap1aa->SetMarkerColor(kRed-7);
  gCompAccEffRap1aa->SetMarkerStyle(23);
  gCompAccEffRap1aa->SetMarkerSize(1.2);
  TGraphErrors *gCompAccEffRap1aacircle = new TGraphErrors(nRapBins_2014,rap2014,Ae_1S_pyquen_rap2014,rap2014e,Ae_1S_pyquen_rap2014e);
  gCompAccEffRap1aacircle->SetMarkerStyle(32);
  gCompAccEffRap1aacircle->SetMarkerSize(1.2);
  gCompAccEffRap1aacircle->SetLineColor(kBlack);
  gCompAccEffRap1aa->Draw("pe");
  gCompAccEffRap1aacircle->Draw("p");
  f4CompRap->Draw("same");
  gPad->RedrawAxis();
  ///2S

  TCanvas *cAccEffComp2 = new TCanvas("cAccEffComp2","cAccEffComp2"); 
  cAccEffComp2->cd();
  TPad *pAccEffComp1 = new TPad("pAccEffComp1","pAccEffComp1",0.0,0.0,1.0,1.0);
  pAccEffComp1->SetBottomMargin(0.12);
  pAccEffComp1->SetTopMargin(0.03);
  pAccEffComp1->SetRightMargin(0.03);
  pAccEffComp1->SetLeftMargin(0.16);
  pAccEffComp1->Draw();
  pAccEffComp1->cd();
  TF1 *f4CompRap = new TF1("f4CompRap","1",0,2.42);
  f4CompRap->SetLineWidth(0);
  f4CompRap->GetXaxis()->SetTitle("|y|");
  f4CompRap->GetYaxis()->SetTitle("A #times #varepsilon_{pp,AA}");
  f4CompRap->GetYaxis()->SetTitleOffset(1.8);
  f4CompRap->GetYaxis()->SetTitleSize(0.028);
  f4CompRap->GetYaxis()->SetRangeUser(0.,0.5);
  f4CompRap->GetXaxis()->CenterTitle(kTRUE);
  f4CompRap->Draw();
  pAccEffComp1->Draw();
  pAccEffComp1->cd();
  f4CompRap->Draw();
  TGraphErrors *gCompAccEffRap2 = new TGraphErrors(nRapBins_2014,rap2014,Ae_2S_pythia_rap2014,rap2014e,Ae_2S_pythia_rap2014e);
  gCompAccEffRap2->SetMarkerColor(kAzure+1);
  gCompAccEffRap2->SetMarkerStyle(21);
  gCompAccEffRap2->SetMarkerSize(1.2);
  TGraphErrors *gCompAccEffRap2circle = new TGraphErrors(nRapBins_2014,rap2014,Ae_2S_pythia_rap2014,rap2014e,Ae_2S_pythia_rap2014e);
  gCompAccEffRap2circle->SetMarkerStyle(25);
  gCompAccEffRap2circle->SetMarkerSize(1.2);
  gCompAccEffRap2circle->SetLineColor(kBlack);
  gCompAccEffRap2->Draw("pe");
  gCompAccEffRap2circle->Draw("p");
  f4CompRap->Draw("same");
  gPad->RedrawAxis();

  TGraphErrors *gCompAccEffRap2aa = new TGraphErrors(nRapBins2S,rap2010,Ae_2S_pyquen_rap2010,rap2010e,Ae_2S_pyquen_rap2010e);
  gCompAccEffRap2aa->SetMarkerColor(kAzure+1);
  gCompAccEffRap2aa->SetMarkerStyle(21);
  gCompAccEffRap2aa->SetMarkerSize(1.2);
  TGraphErrors *gCompAccEffRap2aacircle = new TGraphErrors(nRapBins2S,rap2010,Ae_2S_pyquen_rap2010,rap2010e,Ae_2S_pyquen_rap2010e);
  gCompAccEffRap2aacircle->SetMarkerStyle(25);
  gCompAccEffRap2aacircle->SetMarkerSize(1.2);
  gCompAccEffRap2aacircle->SetLineColor(kBlack);
  gCompAccEffRap2aa->Draw("pe");
  gCompAccEffRap2aacircle->Draw("p");
  f4CompRap->Draw("same");
  gPad->RedrawAxis();




  TCanvas *cEffComp1 = new TCanvas("cEffComp1","cEffComp1"); 
  cEffComp1->cd();
  TPad *pComp1 = new TPad("pComp1","pComp1",0.0,0.0,1.0,1.0);
  pComp1->SetBottomMargin(0.12);
  pComp1->SetTopMargin(0.03);
  pComp1->SetRightMargin(0.03);
  pComp1->SetLeftMargin(0.16);
  pComp1->Draw();
  pComp1->cd();
  TF1 *f4CompRap = new TF1("f4CompRap","1",0,2.45);
  f4CompRap->SetLineWidth(0);
  f4CompRap->GetXaxis()->SetTitle("|y|");
  f4CompRap->GetYaxis()->SetTitle("#frac{#epsilon_{pp}}{#epsilon_{PbPb}}");
  f4CompRap->GetYaxis()->SetTitleOffset(1.8);
  f4CompRap->GetYaxis()->SetTitleSize(0.028);
  f4CompRap->GetYaxis()->SetRangeUser(0.,1.5);
  f4CompRap->GetXaxis()->CenterTitle(kTRUE);
  f4CompRap->Draw();
  TGraphErrors *gCompRap1 = new TGraphErrors(nRapBins_2014,rap2014,R_e_1S_rap,rap2014e,R_e_1S_rape);
  gCompRap1->SetMarkerColor(kRed);
  gCompRap1->SetMarkerStyle(21);
  gCompRap1->SetMarkerSize(1.2);
  TGraphErrors *gCompRap1circle = new TGraphErrors(nRapBins_2014,rap2014,R_e_1S_rap,rap2014e,R_e_1S_rape);
  gCompRap1circle->SetMarkerStyle(25);
  gCompRap1circle->SetMarkerSize(1.2);
  gCompRap1circle->SetLineColor(kBlack);
  gCompRap1->Draw("pe");
  gCompRap1circle->Draw("p");
  f4CompRap->Draw("same");
  gPad->RedrawAxis();
  TLegend *legend = new TLegend(0.482,0.84,0.88,0.7);
  legend->SetTextSize(0.029);
  legend->SetFillStyle(0);
  legend->SetFillColor(0);
  legend->SetBorderSize(0);
  legend->SetTextFont(42);
  legend->AddEntry(gCompRap1,"#varUpsilon(1S) #epsilon_{pp}/#epsilon_{PbPb} ","lp");
  legend->Draw();
  // now vs pt
  
 TCanvas *cEffCompPt = new TCanvas("cEffCompPt","cEffCompPt"); 
  cEffCompPt->cd();
  TPad *pCompPt = new TPad("pCompPt","pCompPt",0.0,0.0,1.0,1.0);
  pCompPt->SetBottomMargin(0.12);
  pCompPt->SetTopMargin(0.03);
  pCompPt->SetRightMargin(0.03);
  pCompPt->SetLeftMargin(0.16);
  pCompPt->Draw();
  pCompPt->cd();  
 
  TF1 *f4CompPt = new TF1("f4CompPt","1",0,20.5);
  f4CompPt->SetLineWidth(0);
  f4CompPt->GetXaxis()->SetTitle("|p_{T}^{#varUpsilon}|");
  f4CompPt->GetYaxis()->SetTitle("#frac{#epsilon_{pp}}{#epsilon_{PbPb}}");
  f4CompPt->GetYaxis()->SetTitleOffset(1.8);
  f4CompPt->GetYaxis()->SetTitleSize(0.028);
  f4CompPt->GetYaxis()->SetRangeUser(0.,1.);
  f4CompPt->GetXaxis()->CenterTitle(kTRUE);
  f4CompPt->Draw();

  for(int i = 0; i<nPtBins_2013; i++){
    e_1S_pythia_pt3p5[i]*=t_1S_pythia_pt3p5[i];
    e_1S_pyquen_pt[i]*=t_1S_pyquen_pt3p5[i];
  }

  TGraphErrors *gCompPt1 = new TGraphErrors(nPtBins_2013,pt,e_1S_pythia_pt3p5,pte,e_1S_pythia_pt3p5e);
  gCompPt1->SetMarkerColor(kRed);
  gCompPt1->SetMarkerStyle(21);
  gCompPt1->SetMarkerSize(1.2);
  TGraphErrors *gCompPt1circle = new TGraphErrors(nPtBins_2013,pt,e_1S_pythia_pt3p5,pte,e_1S_pythia_pt3p5e);
  gCompPt1circle->SetMarkerStyle(25);
  gCompPt1circle->SetMarkerSize(1.2);
  gCompPt1circle->SetLineColor(kBlack);
  gCompPt1->Draw("pe");
  gCompPt1circle->Draw("p");
  f4CompPt->Draw("same");
  gPad->RedrawAxis();
 TGraphErrors *gCompPt_pbpb = new TGraphErrors(nPtBins_2013,pt,e_1S_pyquen_pt,pte,e_1S_pyquen_pte);
  gCompPt_pbpb->SetMarkerColor(kBlue);
  gCompPt_pbpb->SetMarkerStyle(21);
  gCompPt_pbpb->SetMarkerSize(1.2);
  TGraphErrors *gCompPt_pbpbcircle = new TGraphErrors(nPtBins_2013,pt,e_1S_pyquen_pt,pte,e_1S_pyquen_pte);
  gCompPt_pbpbcircle->SetMarkerStyle(25);
  gCompPt_pbpbcircle->SetMarkerSize(1.2);
  gCompPt_pbpbcircle->SetLineColor(kBlack);
  gCompPt_pbpb->Draw("pe");
  gCompPt_pbpbcircle->Draw("p");
  f4CompPt->Draw("same");
  gPad->RedrawAxis();
  TLegend *legend = new TLegend(0.482,0.4,0.88,0.7);
  legend->SetTextSize(0.05);
  legend->SetFillStyle(0);
  legend->SetFillColor(0);
  legend->SetBorderSize(0);
  legend->SetTextFont(42);
  legend->AddEntry(gCompPt1,"#varUpsilon(1S) #epsilon_{pp} vs. p_{T}^{#mu#mu}","lp");
  legend->AddEntry(gCompPt_pbpb,"#varUpsilon(1S) #epsilon_{PbPb} vs. p_{T}^{#mu#mu}","lp"); 
  legend->Draw();
  cEffCompPt->SaveAs("~/Desktop/effcomp.pdf");
  //tnp
  TCanvas *cTnpCompPt = new TCanvas("cTnpCompPt","cTnpCompPt"); 
  cTnpCompPt->cd();
  TPad *pCompPt = new TPad("pCompPt","pCompPt",0.0,0.0,1.0,1.0);
  pCompPt->SetBottomMargin(0.12);
  pCompPt->SetTopMargin(0.03);
  pCompPt->SetRightMargin(0.03);
  pCompPt->SetLeftMargin(0.16);
  pCompPt->Draw();
  pCompPt->cd();  
 
  TF1 *f4CompPt = new TF1("f4CompPt","1",0,20.5);
  f4CompPt->SetLineWidth(0);
  f4CompPt->GetXaxis()->SetTitle("|p_{T}^{#varUpsilon}|");
  f4CompPt->GetYaxis()->SetTitle("SF_{pp,PbPb}");
  f4CompPt->GetYaxis()->SetTitleOffset(1.8);
  f4CompPt->GetYaxis()->SetTitleSize(0.028);
  f4CompPt->GetYaxis()->SetRangeUser(0.7,1.3);
  f4CompPt->GetXaxis()->CenterTitle(kTRUE);
  f4CompPt->Draw();

  TGraphErrors *gtnpPt1 = new TGraphErrors(nPtBins_2013,pt,t_1S_pythia_pt3p5,pte,0);
  gtnpPt1->SetMarkerColor(kBlue);
  gtnpPt1->SetMarkerStyle(21);
  gtnpPt1->SetMarkerSize(1.2);
  TGraphErrors *gtnpPt1circle = new TGraphErrors(nPtBins_2013,pt,t_1S_pythia_pt3p5,pte,0);
  gtnpPt1circle->SetMarkerStyle(25);
  gtnpPt1circle->SetMarkerSize(1.2);
  gtnpPt1circle->SetLineColor(kBlack);
  gtnpPt1->Draw("pe");
  gtnpPt1circle->Draw("p");
  f4CompPt->Draw("same");
  gPad->RedrawAxis();
  TGraphErrors *gtnpPt_pbpb = new TGraphErrors(nPtBins_2013,pt,t_1S_pyquen_pt3p5,pte,0);
  gtnpPt_pbpb->SetMarkerColor(kRed);
  gtnpPt_pbpb->SetMarkerStyle(21);
  gtnpPt_pbpb->SetMarkerSize(1.2);
  TGraphErrors *gtnpPt_pbpbcircle = new TGraphErrors(nPtBins_2013,pt,t_1S_pyquen_pt3p5,pte,0);
  gtnpPt_pbpbcircle->SetMarkerStyle(25);
  gtnpPt_pbpbcircle->SetMarkerSize(1.2);
  gtnpPt_pbpbcircle->SetLineColor(kBlack);
  gtnpPt_pbpb->Draw("pe");
  gtnpPt_pbpbcircle->Draw("p");
  f4CompPt->Draw("same");
  gPad->RedrawAxis();

  TLegend *legend = new TLegend(0.482,0.3,0.9,0.5);
  //  legend->SetTextSize(0);
  legend->SetFillStyle(0);
  legend->SetFillColor(0);
  legend->SetBorderSize(0);
  legend->SetTextFont(42);
  legend->AddEntry(gtnpPt1,"#varUpsilon(1S) SF_{pp} vs. p_{T}^{#mu#mu}","lp");
  legend->AddEntry(gtnpPt_pbpb,"#varUpsilon(1S) SF_{PbPb} vs. p_{T}^{#mu#mu}","lp"); 
  legend->Draw();
  cTnpCompPt->SaveAs("~/Desktop/Tnp_SFcomp.pdf");
  //now 2S

  TCanvas *cEffComp2 = new TCanvas("cEffComp2","cEffComp2"); 
  cEffComp2->cd();
  TPad *pComp2 = new TPad("pComp2","pComp2",0.0,0.0,1.0,1.0);
  pComp2->SetBottomMargin(0.12);
  pComp2->SetTopMargin(0.03);
  pComp2->SetRightMargin(0.03);
  pComp2->SetLeftMargin(0.16);
  pComp2->Draw();
  pComp2->cd();
  TF1 *f4CompPt = new TF1("f4CompPt","1",0,20);
  f4CompPt->SetLineWidth(0);
  f4CompPt->GetXaxis()->SetTitle("p_{T}^{#varUpsilon}");
  f4CompPt->GetYaxis()->SetTitle("#frac{#epsilon_{pp}}{#epsilon_{PbPb}}");
  f4CompPt->GetYaxis()->SetTitleOffset(1.8);
  f4CompPt->GetYaxis()->SetTitleSize(0.028);
  f4CompPt->GetYaxis()->SetRangeUser(0.,1.5);
  f4CompPt->GetXaxis()->CenterTitle(kTRUE);
  f4CompPt->Draw();
  TGraphErrors *gCompPt1 = new TGraphErrors(nPtBins_2013,pt,R_e_1S_pt,pte,R_e_1S_pte);
  gCompPt1->SetMarkerColor(kRed);
  gCompPt1->SetMarkerStyle(21);
  gCompPt1->SetMarkerSize(1.2);
  TGraphErrors *gCompPt1circle = new TGraphErrors(nPtBins_2013,pt,R_e_1S_pt,pte,R_e_1S_pte);
  gCompPt1circle->SetMarkerStyle(25);
  gCompPt1circle->SetMarkerSize(1.2);
  gCompPt1circle->SetLineColor(kBlack);
  gCompPt1->Draw("pe");
  gCompPt1circle->Draw("p");
  f4CompPt->Draw("same");
  gPad->RedrawAxis();
  TLegend *legend = new TLegend(0.482,0.84,0.88,0.7);
  legend->SetTextSize(gTextSize);
  legend->SetFillStyle(0);
  legend->SetFillColor(0);
  legend->SetBorderSize(0);
  legend->SetTextFont(42);
  legend->AddEntry(gCompPt1,"#varUpsilon(1S) #epsilon_{pp}/#epsilon_{PbPb} ","lp");
  legend->Draw();
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


float plot2010()
{
  float deltaPt_2010[nPtBins_2010]   = {5,7,8};
  float deltaRap2010[nRapBins_2010] = {2.4,2.4};
  float CS1S_pp_tot;
  float CS1S_pp_tot4;
  float CS1S_pp_tote;
  float CS1S_pp_tot4e;
  float CS1S_pp_tots;
  float CS1S_pp_tot4s;
  float CS1S_aa_tot;
  float CS1S_aa_tote;
  float CS1S_aa_tots;
  float CS1S_aa_cent[nCentBins_2014] = {}; 
  float CS1S_aa_cente[nCentBins_2014] = {};
  float CS1S_aa_cents[nCentBins_2014] = {};
  float RAA_1S_cent[nCentBins_2014]={};
  float RAA_1S_cente[nCentBins_2014]={};
  float RAA_1S_cents[nCentBins_2014]={};
  float RAA_1S_centsT[nCentBins_2014]={};
  //  float RAA_1S_centsg[nCentBins_2014]={};
  //  float RAA_1S_centsglob;
  float CS1S_aa_cent4[nCentBins_2014] = {};
  float CS1S_aa_cent4e[nCentBins_2014] = {};
  float CS1S_aa_cent4s[nCentBins_2014] = {};
  float RAA_1S_cent4[nCentBins_2014]={};
  float RAA_1S_cent4e[nCentBins_2014]={};
  float RAA_1S_cent4s[nCentBins_2014]={};
  float RAA_1S_cent4sT[nCentBins_2014]={};
  //  float RAA_1S_cents4g[nCentBins_2014-1]={};
  //  float RAA_1S_cents4glob;


  float RAA_1S_tot;
  float RAA_1S_tote;
  float RAA_1S_tots;
  float RAA_2S_tot;
  float RAA_2S_tote;
  float RAA_2S_tots;
  float RAA_3S_tot;
  float RAA_3S_UL;
  float RAA_3S_tote;
  float CS2S_pp_tot;
  float CS2S_pp_tote;
  float CS2S_pp_tots;
  float CS2S_pp_tote;
  float CS2S_aa_tot;
  float CS2S_aa_tots;
  float CS2S_aa_tote;
  float CS3S_pp_tot;
  float CS3S_pp_tote;
  float CS3S_aa_tot;
  float CS3S_aa_tote;
  float CS3S_aa_UL;
  float CS2S_aa_cent[nCentBins2S] = {};
  float CS2S_aa_cente[nCentBins2S] = {};
  float CS2S_aa_cents[nCentBins2S] = {};
  float CS2S_aa_4bin[nCentBins2S] = {};
  float CS2S_aa_4bine[nCentBins2S] = {};
  float CS2S_aa_4bins[nCentBins2S] = {};
  float RAA_2S_cent[nCentBins2S]={};
  float RAA_2S_cente[nCentBins2S]={};
  float RAA_2S_4bin[nCentBins2S]={};
  float RAA_2S_4bine[nCentBins2S]={};
  float RAA_2S_cents[nCentBins2S]={};
  float RAA_2S_centsT[nCentBins2S]={};

  //fit syst.
  float syst1S_aa_Cent[nCentBins_2014]={};
  float syst1S_aa_Cent4[nCentBins_2014]={};
  float syst2S_aa_Cent[nCentBins2S]={};
  float fit_syst2S_aa_Cent[nCentBins2S]={};
  float bkg_syst2S_aa_Cent[nCentBins2S]={};
  // tnp syst.
  float syst1S_aatnp_Cent[nCentBins_2014]={};
  float syst1S_aatnp_Cent4[nCentBins_2014]={};
  float syst2S_aatnp_Cent[nCentBins2S]={};
  //global syst for all!
  float systAA_glob2 = sqrt(N_MB_e*N_MB_e+(0.057*0.057)+(N2S_aa_tot4s*N2S_aa_tot4s));
  float systAA_glob1 = sqrt(N_MB_e*N_MB_e+(0.057*0.057)+(N1S_aa_tot3p5s*N1S_aa_tot3p5s));
  // syst1S_aa_Cent4[i]+=(t_1S_pythia_tot3p5-1)*(t_1S_pythia_tot3p5-1)+(N1S_pp_tot3p5e/N1S_pp_tot3p5)*(N1S_pp_tot3p5e/N1S_pp_tot3p5)+N1S_pp_tot3p5s*N1S_pp_tot3p5s+L_pp_e*L_pp_e+N_MB_e*N_MB_e;
  float syst1S_pp_centGlob=sqrt((L_pp_e*L_pp_e)+(N1S_pp_tot3p5e*N1S_pp_tot3p5e)/(N1S_pp_tot3p5*N1S_pp_tot3p5)+(t_1S_pythia_tot3p5e*t_1S_pythia_tot3p5e)/(t_1S_pythia_tot3p5*t_1S_pythia_tot3p5)+N1S_pp_tot3p5s*N1S_pp_tot3p5s); //L_pp + stat_pp tot(1S) + tnp_pp1S + syst_tot(1S)
  float syst2S_pp_centGlob4=sqrt((L_pp_e*L_pp_e)+(N2S_pp_tot4s*N2S_pp_tot4s)+(N2S_pp_tot4e*N2S_pp_tot4e)/(N2S_pp_tot4*N2S_pp_tot4)+(t_2S_pythia_tote/t_2S_pythia_tot)*(t_2S_pythia_tote/t_2S_pythia_tot)+N1S_pp_tot4s*N1S_pp_tot4s); //L_pp + stat_pp tot(2S) + tnp_pp2S 
  float syst1S_pp_centGlob4=sqrt((L_pp_e*L_pp_e)+(N1S_pp_tot4e*N1S_pp_tot4e)/(N1S_pp_tot4*N1S_pp_tot4)+pow(t_1S_pythia_tot4e/t_1S_pythia_tot4,2)); //L_pp + stat_pp tot(1S)pt4 + tnp_pp1S pt4 +
  //taa-point-to-point syst.
  float syst1S_taa_cent[nCentBins_2014]={};
  float syst2S_taa_cent[nCentBins_2014-1]={};
  //point-to-point syst for all
  float syst2S_raa_pointCent[nCentBins2S]={};
  float syst1S_raa_pointCent4[nCentBins_2014]={};
  float syst1S_raa_pointCent[nCentBins_2014]={};
  //total syst for tables
  float syst2S_raa_cent[nCentBins2S]={};
  float syst1S_raa_cent[nCentBins_2014]={}; 
  float syst1S_raa_cent4[nCentBins_2014]={};
  //cross section pt to pt syst.
  float syst2S_csaa_cent[nCentBins2S]={};
  float syst1S_csaa_cent4[nCentBins_2014]={};
  float syst1S_csaa_cent[nCentBins_2014]={}

  //DOUBLE DIFFERENTIAL STUFF
  // float CS1S_aa_y120[nCentBins_2010]={};
  // float CS1S_aa_y120e[nCentBins_2010]={};
  float CS1S_aa_y240[nCentBins_2010]={};
  float CS1S_aa_y240e[nCentBins_2010]={};
  float CS1S_aa_pt5[nCentBins_2010]={};
  float CS1S_aa_pt5e[nCentBins_2010]={};
  float CS1S_aa_pt12[nCentBins_2010]={};
  float CS1S_aa_pt12e[nCentBins_2010]={};
  float CS1S_aa_pt20[nCentBins_2010]={};
  float CS1S_aa_pt20e[nCentBins_2010]={};
  // float RAA_1S_y120[nCentBins_2010]={};
  // float RAA_1S_y120e[nCentBins_2010]={};
  float RAA_1S_y240[nCentBins_2010]={};
  float RAA_1S_y240e[nCentBins_2010]={};
  float RAA_1S_pt5[nCentBins_2010]={};
  float RAA_1S_pt5e[nCentBins_2010]={};
  float RAA_1S_pt12[nCentBins_2010]={};
  float RAA_1S_pt12e[nCentBins_2010]={};
  float RAA_1S_pt20[nCentBins_2010]={};
  float RAA_1S_pt20e[nCentBins_2010]={};
  //large things
  float CS1S_pp_ptLarge[nPtBins_2010] = {};
  float CS1S_pp_ptLargee[nPtBins_2010] = {};


  //large things
  float CS1S_pp_rapLarge[nRapBins_2010] = {};
  float CS1S_pp_rapLargee[nRapBins_2010] = {};
  ofSyst.open(outSyst.c_str(), ios_base::out | ios_base::app);  

  syst1S_aa_Cent[7]= sqrt (pow(RMS(N1S_aa_cent3p5[7],N1S_aa_cents_5,nfitvars),2)+  pow(maxDeviation(N1S_aa_cent3p5[7],N1B_aa_cents_5,nbkgdvars),2)) ;
  syst1S_aa_Cent[6]= sqrt (pow(RMS(N1S_aa_cent3p5[6],N1S_aa_cents_10,nfitvars),2)+ pow(maxDeviation(N1S_aa_cent3p5[6],N1B_aa_cents_10,nbkgdvars),2)) ;
  syst1S_aa_Cent[5]= sqrt (pow(RMS(N1S_aa_cent3p5[5],N1S_aa_cents_20,nfitvars),2)+ pow(maxDeviation(N1S_aa_cent3p5[5],N1B_aa_cents_20,nbkgdvars),2)) ;
  syst1S_aa_Cent[4]= sqrt (pow(RMS(N1S_aa_cent3p5[4],N1S_aa_cents_30,nfitvars),2)+ pow(maxDeviation(N1S_aa_cent3p5[4],N1B_aa_cents_30,nbkgdvars),2)) ;
  syst1S_aa_Cent[3]= sqrt (pow(RMS(N1S_aa_cent3p5[3],N1S_aa_cents_40,nfitvars),2)+ pow(maxDeviation(N1S_aa_cent3p5[3],N1B_aa_cents_40,nbkgdvars),2)) ;
  syst1S_aa_Cent[2]= sqrt (pow(RMS(N1S_aa_cent3p5[2],N1S_aa_cents_50,nfitvars),2)+ pow(maxDeviation(N1S_aa_cent3p5[2],N1B_aa_cents_50,nbkgdvars),2)) ;
  syst1S_aa_Cent[1]= sqrt (pow(RMS(N1S_aa_cent3p5[1],N1S_aa_cents_70,nfitvars),2)+ pow(maxDeviation(N1S_aa_cent3p5[1],N1B_aa_cents_70,nbkgdvars),2)) ;
  syst1S_aa_Cent[0]= sqrt (pow(RMS(N1S_aa_cent3p5[0],N1S_aa_cents_100,nfitvars),2)+ pow(maxDeviation(N1S_aa_cent3p5[0],N1B_aa_cents_100,nbkgdvars),2)) ;

  syst1S_aa_Cent4[7]= sqrt (pow(RMS(N1S_aa_cent4[7],N1S_aa_cent4s_5,nfitvars),2)+  pow(maxDeviation(N1S_aa_cent4[7],N1B_aa_cent4s_5,nbkgdvars),2)) ;
  syst1S_aa_Cent4[6]= sqrt (pow(RMS(N1S_aa_cent4[6],N1S_aa_cent4s_10,nfitvars),2)+ pow(maxDeviation(N1S_aa_cent4[6],N1B_aa_cent4s_10,nbkgdvars),2)) ;
  syst1S_aa_Cent4[5]= sqrt (pow(RMS(N1S_aa_cent4[5],N1S_aa_cent4s_20,nfitvars),2)+ pow(maxDeviation(N1S_aa_cent4[5],N1B_aa_cent4s_20,nbkgdvars),2)) ;
  syst1S_aa_Cent4[4]= sqrt (pow(RMS(N1S_aa_cent4[4],N1S_aa_cent4s_30,nfitvars),2)+ pow(maxDeviation(N1S_aa_cent4[4],N1B_aa_cent4s_30,nbkgdvars),2)) ;
  syst1S_aa_Cent4[3]= sqrt (pow(RMS(N1S_aa_cent4[3],N1S_aa_cent4s_40,nfitvars),2)+ pow(maxDeviation(N1S_aa_cent4[3],N1B_aa_cent4s_40,nbkgdvars),2)) ;
  syst1S_aa_Cent4[2]= sqrt (pow(RMS(N1S_aa_cent4[2],N1S_aa_cent4s_50,nfitvars),2)+ pow(maxDeviation(N1S_aa_cent4[2],N1B_aa_cent4s_50,nbkgdvars),2)) ;
  syst1S_aa_Cent4[1]= sqrt (pow(RMS(N1S_aa_cent4[1],N1S_aa_cent4s_70,nfitvars),2)+ pow(maxDeviation(N1S_aa_cent4[1],N1B_aa_cent4s_70,nbkgdvars),2)) ;
  syst1S_aa_Cent4[0]= sqrt (pow(RMS(N1S_aa_cent4[0],N1S_aa_cent4s_100,nfitvars),2)+ pow(maxDeviation(N1S_aa_cent4[0],N1B_aa_cent4s_100,nbkgdvars),2)) ;
  //CENT 2S	
  syst2S_aa_Cent[3]= sqrt (pow(RMS( N2S_aa_cent4Large[3],N2S_aa_cent4Larges_10,nfitvars),2)+ pow(maxDeviation( N2S_aa_cent4Large[3],N2B_aa_cent4Larges_10,nbkgdvars),2)) ;
  syst2S_aa_Cent[2]= sqrt (pow(RMS( N2S_aa_cent4Large[2],N2S_aa_cent4Larges_30,nfitvars),2)+ pow(maxDeviation( N2S_aa_cent4Large[2],N2B_aa_cent4Larges_30,nbkgdvars),2)) ;
  syst2S_aa_Cent[1]= sqrt (pow(RMS( N2S_aa_cent4Large[1],N2S_aa_cent4Larges_50,nfitvars),2)+ pow(maxDeviation( N2S_aa_cent4Large[1],N2B_aa_cent4Larges_50,nbkgdvars),2)) ;
  syst2S_aa_Cent[0]= sqrt (pow(RMS( N2S_aa_cent4Large[0],N2S_aa_cent4Larges_100,nfitvars),2)+ pow(maxDeviation( N2S_aa_cent4Large[0],N2B_aa_cent4Larges_100,nbkgdvars),2))  ;


  // 1S
  for(int i=0; i<nCentBins_2014;i++){
    /////////////////////////////////////////////////////////////////////////////
    // point-to-point systematics : syst(fit)_aa + tnp_aa + T_aa + AccEff_syst //
    // global systematics: syst_pp + L_pp + tnp_pp + unf_pp,AA + stat_pp       //
    /////////////////////////////////////////////////////////////////////////////
    syst1S_aatnp_Cent[i]=(t_1S_pyquen_cent3p5e[i]/t_1S_pyquen_cent3p5[i]);
    syst1S_taa_cent[i]=taa2014e[i]/taa2014[i];
    syst1S_raa_pointCent[i]=sqrt(syst1S_taa_cent[i]*syst1S_taa_cent[i]+syst1S_aatnp_Cent[i]*syst1S_aatnp_Cent[i]+syst1S_aa_Cent[i]*syst1S_aa_Cent[i]+pow(Aet_1S_pyquen_cent2014s[i]/Aet_1S_pyquen_cent2014[i],2));
    syst1S_raa_cent[i]=sqrt(syst1S_pp_centGlob*syst1S_pp_centGlob+syst1S_raa_pointCent[i]*syst1S_raa_pointCent[i]+pow(Aet_1S_pythia_tote/Aet_1S_pythia_tot,2));
    //pt4!
    syst1S_aatnp_Cent4[i]=t_1S_pyquen_cent4e[i]/t_1S_pyquen_cent4[i];
    syst1S_raa_pointCent4[i]=sqrt(syst1S_taa_cent[i]*syst1S_taa_cent[i]+syst1S_aatnp_Cent4[i]*syst1S_aatnp_Cent4[i]+syst1S_aa_Cent4[i]*syst1S_aa_Cent4[i]+pow(Aet_1S_pyquen_cent2014s[i]/Aet_1S_pyquen_cent2014[i],2));
    syst1S_raa_cent4[i]=sqrt(syst1S_pp_centGlob4*syst1S_pp_centGlob4+syst1S_raa_pointCent4[i]*syst1S_raa_pointCent4[i]+pow(Aet_1S_pythia_tote/Aet_1S_pythia_tot,2));
   
  
  }

  for(int i=0; i<nCentBins2S;i++){
    syst2S_aatnp_Cent[i]= t_2S_pyquen_cent4e[i]/t_2S_pyquen_cent4[i];   
    syst2S_taa_cent[i]=(taa2Se[i]/taa2S[i]);//same for 2S and 1Spt4
  
    syst2S_raa_pointCent[i]=sqrt(syst2S_taa_cent[i]*syst2S_taa_cent[i]+syst2S_aatnp_Cent[i]*syst2S_aatnp_Cent[i]+syst2S_aa_Cent[i]*syst2S_aa_Cent[i]+Aet_2S_pyquen_cent2014s[i]/Aet_2S_pyquen_cent2014[i]);
    syst2S_raa_cent[i]=sqrt(syst2S_pp_centGlob4*syst2S_pp_centGlob4+syst2S_raa_pointCent[i]*syst2S_raa_pointCent[i]+pow(Aet_2S_pythia_tote/Aet_2S_pythia_tot,2));
  }

  cout << "---------------------1S cent---------------------" <<endl;
  for(int i=nCentBins_2014-1; i>=0;i--){
    ofSyst<< "syst1S_aa_Cent_"<<i << " "<< 100*syst1S_aa_Cent[i]<< " %"<<endl;
    cout << (binsCent[i]).c_str() <<setprecision(3)<< " " << syst1S_aa_Cent[i] << " " << syst1S_aatnp_Cent[i] <<" "<< syst1S_taa_cent[i] <<" "<< syst1S_pp_centGlob <<" "<< syst1S_raa_pointCent[i] <<" "<< syst1S_raa_cent[i]<< endl;
  }
  cout << "---------------------1S cent pt4---------------------" <<endl;
  for(int i=nCentBins_2014-1; i>=0;i--){
    //   ofSyst<< "syst1S_aa_Cent_pt4"<<i << " "<< 100*syst1S_aa_Cent4[i]<< " %"<<endl;
    cout << (binsCent[i]).c_str() <<setprecision(3)<< " " << syst1S_aa_Cent4[i] << " " << syst1S_aatnp_Cent4[i] <<" "<< syst1S_taa_cent[i] <<" "<< syst1S_pp_centGlob4 <<" "<< syst1S_raa_pointCent4[i] <<" "<< syst1S_raa_cent4[i]<< endl; 
  }
  cout << "---------------------2S-cent--------------------" <<endl;
  for(int i=4-1; i>=0;i--){
    //  ofSyst<< "syst2S_aa_Cent_"<<i << " "<< 100*syst2S_aa_Cent[i]<< " %"<<endl;
    cout << (bins4Bin[i]).c_str() <<setprecision(3)<< " " << syst2S_aa_Cent[i] << " " << syst2S_aatnp_Cent[i] <<" "<< syst2S_taa_cent[i] <<" "<< syst2S_pp_centGlob4 <<" "<< syst2S_raa_pointCent[i] <<" "<< syst2S_raa_cent[i]<< endl;
  }
  for(int centi =0 ; centi<nCentBins2S ; centi++)
    {
      taa[centi]=taa[centi]*1000;
      CS2S_aa_cent[centi]= computeRatio( N2S_aa_cent4[centi] , Aet_2S_pyquen_cent2014[centi] );
      CS2S_aa_cente[centi] = computeRatioError( N2S_aa_cent4[centi] , Aet_2S_pyquen_cent2014[centi], N2S_aa_cent4e[centi] , 0); // Aet_2S_pyquen_cent2014e[centi]
      CS2S_aa_cent[centi]=CS2S_aa_cent[centi]/(mb_percentage2S[centi]*N_MB_corr * taa2S[centi]);
      CS2S_aa_cente[centi]=CS2S_aa_cente[centi]/(mb_percentage2S[centi]*N_MB_corr * taa2S[centi]);
      CS2S_aa_cents[centi]=N2S_aa_cent4[centi]*syst2S_raa_pointCent[centi]/(mb_percentage2S[centi]*N_MB_corr * taa2S[centi]);
      ///changed
      if(centi==0){
	CS2S_pp_tot = computeRatio(N2S_pp_tot4,Aet_2S_pythia_tot);
	CS2S_pp_tote = computeRatioError(N2S_pp_tot4,Aet_2S_pythia_tot,N2S_pp_tot4e,Aet_2S_pythia_tote);
	CS2S_pp_tot = CS2S_pp_tot/(L_pp_invNb);
	CS2S_pp_tote=CS2S_pp_tote/(L_pp_invNb);
	CS3S_pp_tot = computeRatio(N3S_pp_tot4,Aet_3S_pythia_tot);
	CS3S_pp_tote = computeRatioError(N3S_pp_tot4,Aet_3S_pythia_tot,N3S_pp_tot4e,Aet_3S_pythia_tote);
	CS3S_pp_tot = CS3S_pp_tot/(L_pp_invNb);
	CS3S_pp_tote=CS3S_pp_tote/(L_pp_invNb);
      }
      RAA_2S_cent[centi]= computeRatio( CS2S_aa_cent[centi] , CS2S_pp_tot);
      RAA_2S_cente[centi]= computeRatioError( CS2S_aa_cent[centi] , CS2S_pp_tot,  CS2S_aa_cente[centi] ,0);
    }

  ///4bins of centrality for 2S !
  for (int i=0;i<4;i++)
    {
      taa2S[i]=taa2S[i]*1000;
      CS2S_aa_4bin[i]= computeRatio( N2S_aa_cent4Large[i] , Aet_2S_pyquen_cent2014[i] );
      CS2S_aa_4bine[i] = computeRatioError( N2S_aa_cent4Large[i] ,  Aet_2S_pyquen_cent2014[i], N2S_aa_cent4Largee[i] , 0.002);
      CS2S_aa_4bin[i]=CS2S_aa_4bin[i]/(mb_percentage2S[i]*N_MB_corr * taa2S[i]);
      CS2S_aa_4bine[i]=CS2S_aa_4bine[i]/(mb_percentage2S[i]*N_MB_corr * taa2S[i]);
      RAA_2S_4bin[i]= computeRatio( CS2S_aa_4bin[i] , CS2S_pp_tot);
      RAA_2S_4bine[i]= computeRatioError( CS2S_aa_4bin[i] , CS2S_pp_tot,  CS2S_aa_4bine[i] ,0);
      RAA_2S_cents[i]=RAA_2S_4bin[i]*syst2S_raa_pointCent[i];//computeRatioError(CS2S_aa_cent[centi], CS2S_pp_tot, CS2S_aa_cents[centi], 0);
      RAA_2S_centsT[i]=RAA_2S_4bin[i]*syst2S_raa_cent[i];
      CS2S_aa_4bins[i]=CS2S_aa_4bin[i]*syst2S_raa_cent[i];
      
    }
 cout << "wow!"<< endl;
  for(int centi =0 ; centi<nCentBins_2014; centi++){ //for fun
    taa2014[centi]=taa2014[centi]*1000;
    taa2015[centi]=taa2015[centi]*1000;
    CS1S_aa_cent[centi]= computeRatio( N1S_aa_cent3p5[centi] , Aet_1S_pyquen_cent2014[centi] );
    CS1S_aa_cente[centi] = computeRatioError( N1S_aa_cent3p5[centi] , Aet_1S_pyquen_cent2014[centi], N1S_aa_cent3p5e[centi] ,0); // Aet_1S_pyquen_cent2014e[centi]
    CS1S_aa_cent[centi]=CS1S_aa_cent[centi]/(mb_percentage2014[centi]*N_MB_corr * taa2014[centi]);
    CS1S_aa_cente[centi]=CS1S_aa_cente[centi]/(mb_percentage2014[centi]*N_MB_corr * taa2014[centi]);
    CS1S_aa_cents[centi]=N1S_aa_cent3p5[centi]*syst1S_raa_pointCent[centi]/(mb_percentage2014[centi]*N_MB_corr * taa2014[centi]);
    //pt4
    CS1S_aa_cent4[centi]= computeRatio( N1S_aa_cent4[centi] , Aet_1S_pyquen_cent2014[centi] );//
    CS1S_aa_cent4e[centi] = computeRatioError( N1S_aa_cent4[centi] , Aet_1S_pyquen_cent2014[centi], N1S_aa_cent4e[centi] , 0);
    CS1S_aa_cent4[centi]=CS1S_aa_cent4[centi]/(mb_percentage2014[centi]*N_MB_corr*taa2014[centi]);//huh; 
    CS1S_aa_cent4e[centi]=CS1S_aa_cent4e[centi]/(mb_percentage2014[centi]*N_MB_corr*taa2014[centi]);//huh; ;//huh
    CS1S_aa_cent4s[centi]=(N1S_aa_cent4[centi]*syst1S_raa_pointCent4[centi])/(mb_percentage2014[centi]*N_MB_corr*taa2014[centi]);
  
    if(centi==0){       
      CS1S_pp_tot = computeRatio(N1S_pp_tot3p5,Aet_1S_pythia_tot)/(L_pp_invNb);
      CS1S_pp_tots = N1S_pp_tot3p5*syst1S_pp_centGlob;
      CS1S_aa_tots = N1S_aa_tot3p5*systAA_glob1;
      CS2S_pp_tots = N2S_pp_tot3p5*syst2S_pp_centGlob4;
      CS2S_aa_tots = N2S_aa_tot3p5*systAA_glob2;
      CS1S_pp_tote = computeRatioError(N1S_pp_tot3p5,Aet_1S_pythia_tot,N1S_pp_tot3p5e,Aet_1S_pythia_tote);
      CS1S_pp_tote =CS1S_pp_tote/(L_pp_invNb);
      CS1S_pp_tots =CS1S_pp_tots/(L_pp_invNb);
      CS2S_pp_tots =CS2S_pp_tots/(L_pp_invNb);
      CS1S_pp_tot4 = computeRatio(N1S_pp_tot4,Aet_1S_pythia_tot4)/(L_pp_invNb);
      CS1S_pp_tot4s = N1S_pp_tot4*N1S_pp_tot4s;
      float CS1S_aa_tot4s = N1S_aa_tot4*N1S_aa_tot4s;
      CS1S_pp_tot4e = computeRatioError(N1S_pp_tot4,Aet_1S_pythia_tot4,N1S_pp_tot4e,Aet_1S_pythia_tot4e);
      CS1S_pp_tot4e =CS1S_pp_tot4e/(L_pp_invNb);
      CS1S_pp_tot4s =CS1S_pp_tot4s/(L_pp_invNb);//huh
    } 
    RAA_1S_cent[centi]= computeRatio( CS1S_aa_cent[centi] , CS1S_pp_tot);
    RAA_1S_cente[centi]= computeRatioError( CS1S_aa_cent[centi] , CS1S_pp_tot,  CS1S_aa_cente[centi] ,0);// CS1S_pp_tote
    RAA_1S_cents[centi]=RAA_1S_cent[centi]*syst1S_raa_pointCent[centi];//computeRatioError(CS1S_aa_cent[centi], CS1S_pp_tot, CS1S_aa_cents[centi], 0)+RAA_1S_centsg[centi]; // OK!!
    RAA_1S_centsT[centi]=RAA_1S_cent[centi]*syst1S_raa_cent[centi];
    RAA_1S_cent4[centi]= computeRatio( CS1S_aa_cent4[centi] , CS1S_pp_tot4);
    RAA_1S_cent4e[centi]= computeRatioError( CS1S_aa_cent4[centi] , CS1S_pp_tot4,  CS1S_aa_cent4e[centi] ,0);// CS1S_pp_tote
    RAA_1S_cent4s[centi]=RAA_1S_cent4[centi]*syst1S_raa_pointCent4[centi];
    RAA_1S_cent4sT[centi]=RAA_1S_cent4[centi]*syst1S_raa_cent4[centi];
  }

  CS1S_aa_tot = computeRatio(N1S_aa_tot3p5,Aet_1S_pyquen_tot);
  CS1S_aa_tote = computeRatioError(N1S_aa_tot3p5,Aet_1S_pyquen_tot,N1S_aa_tot3p5e,Aet_1S_pyquen_tote);
  CS1S_aa_tot = CS1S_aa_tot/(N_MB_corr*T_AA_b);
  CS1S_aa_tote= CS1S_aa_tote/(N_MB_corr*T_AA_b);
  CS1S_aa_tots= CS1S_aa_tots/(N_MB_corr*T_AA_b);
  CS2S_aa_tots= CS2S_aa_tots/(N_MB_corr*T_AA_b);
  CS2S_aa_tot = computeRatio(N2S_aa_tot4,Aet_2S_pyquen_tot); // changed here 3p5
  CS2S_aa_tote = computeRatioError(N2S_aa_tot4,Aet_2S_pyquen_tot,N2S_aa_tot4e,Aet_2S_pyquen_tote);
  CS2S_aa_tot = CS2S_aa_tot/(N_MB_corr*T_AA_b);
  CS2S_aa_tote = CS2S_aa_tote/(N_MB_corr*T_AA_b);
  CS3S_aa_tot = computeRatio(N3S_aa_tot4,Aet_3S_pyquen_tot); // careful here
  //UPPER LIMIT
  CS3S_aa_UL=computeRatio(N3S_aa_tot4,Aet_3S_pyquen_tot);
  CS3S_aa_tote = computeRatioError(N3S_aa_tot4,Aet_3S_pyquen_tot,N3S_aa_tot4e,Aet_3S_pyquen_tote);
  CS3S_aa_tot = CS3S_aa_tot/(N_MB_corr*T_AA_b);
  CS3S_aa_UL=CS3S_aa_UL/(N_MB_corr*T_AA_b);
  CS3S_aa_tote=CS3S_aa_tote/(N_MB_corr*T_AA_b);
 float RAA_2S_tote;
  RAA_1S_tot = computeRatio(CS1S_aa_tot,CS1S_pp_tot);
  RAA_1S_tote = computeRatioError(CS1S_aa_tot,CS1S_pp_tot,CS1S_aa_tote,CS1S_pp_tote);
  RAA_1S_tots = RAA_1S_tot*sqrt(syst1S_pp_centGlob*syst1S_pp_centGlob+systAA_glob1*systAA_glob1); //computeRatioError(CS1S_aa_tot,CS1S_pp_tot,CS1S_aa_tots,CS1S_pp_tots);
  RAA_2S_tot = computeRatio(CS2S_aa_tot,CS2S_pp_tot);
  RAA_2S_tote = computeRatioError(CS2S_aa_tot,CS2S_pp_tot,CS2S_aa_tote,CS2S_pp_tote);
  RAA_2S_tots = RAA_2S_tot*sqrt(syst2S_pp_centGlob4*syst2S_pp_centGlob4+systAA_glob2*systAA_glob2);//computeRatioError(CS2S_aa_tot,CS2S_pp_tot,CS2S_aa_tots,CS2S_pp_tots);
  RAA_3S_tot = computeRatio(CS3S_aa_tot,CS3S_pp_tot);
  RAA_3S_UL= computeRatio(CS3S_aa_UL,CS3S_pp_tot); //upper limit
  RAA_3S_tote = computeRatioError(CS3S_aa_tot,CS3S_pp_tot,CS3S_aa_tote,CS3S_pp_tote);

  cout << "  --- Cross section 1S in PbPb vs. nPart ---" << endl;//for fun
  // for(int j =nCentBins_2014-1 ; j>=0 ; j--) 
  //   {
  //     cout << (binsCent[j]).c_str() << " "<< CS1S_aa_cent[j] <<" \\pm "<<CS1S_aa_cente[j]<<" \\pm "<< CS1S_aa_cents[j]<<" \\" << endl;
  //   }
  for(int j =nCentBins_2014-1 ; j>=0 ; j--) 
    {
      cout << (binsCent[j]).c_str() << " "<< CS1S_aa_cent[j] <<" \\pm "<<CS1S_aa_cente[j]<< " \\pm "<< CS1S_aa_cents[j]<<" \\" << endl;
    }

  cout << "  --- 1S RAA vs. nPart ---" << endl;
  // for(int j =nCentBins_2014-1 ; j>=0 ; j--)
  //   {
  //     cout << (binsCent[j]).c_str() << " "<< RAA_1S_cent[j] <<" \\pm "<< RAA_1S_cente[j]<< " \\pm "<< RAA_1S_centsT[j]<< endl;
  //   }
  for(int j =nCentBins_2014-1 ; j>=0 ; j--)
    {
      cout << (binsCent[j]).c_str() << " "<< RAA_1S_cent[j] <<" \\pm "<< RAA_1S_cente[j]<< " \\pm "<< RAA_1S_centsT[j]<< endl;
    }

  cout << "  ---1S pt 4 Cross section in PbPb vs. nPart ---" << endl;
  for(int j =7 ; j>=0 ; j--)
    {
      cout << (binsCent[j]).c_str() << " "<< CS1S_aa_cent4[j] <<" \\pm "<< CS1S_aa_cent4e[j]<< " \\pm "<< CS1S_aa_cent4s[j]<<" (glob.))"<< endl;
    }
  cout << "  --- 1S pt 4 RAA vs. nPart ---" << endl;
  for(int j =7 ; j>=0 ; j--)
    {
      cout << (binsCent[j]).c_str() << " "<<  RAA_1S_cent4[j] <<" \\pm "<< RAA_1S_cent4e[j]<< " \\pm "<< RAA_1S_cent4sT[j]<< endl;
    }
  std::cout << std::fixed;
  cout << "  --- 2S Cross section in PbPb vs. nPart ---" << endl;
  for(int j =4-1 ; j>=0 ; j--)
    {
      cout<<setprecision(3) << (bins4Bin[j]).c_str() << " "<< CS2S_aa_4bin[j] <<" \\pm "<<CS2S_aa_4bine[j]<<" \\pm"<<CS2S_aa_4bins[j] << " \\" << endl;
    }

  cout << "  --- 2S RAA vs. nPart ---" << endl;
  for(int j =4-1 ; j>=0 ; j--)
    {
      cout << (bins4Bin[j]).c_str() << " "<< RAA_2S_cent[j] <<" \\pm "<< RAA_2S_cente[j]<< " \\pm "<< RAA_2S_centsT[j]<< endl;
    }

  cout << "  --- 2S RAA vs. nPart in 4 bins ---" << endl;
  for(int j =3 ; j>=0 ; j--)
    {
      cout << (bins4Bin[j]).c_str() << " "<< RAA_2S_4bin[j] <<" \\pm "<< RAA_2S_4bine[j]<<" \\pm "<< RAA_2S_centsT[j]<< endl; endl;
    }

  cout << setprecision(3)<<" total_sigma(1S)_pp = "<<CS1S_pp_tot <<" \\pm " <<CS1S_pp_tote  <<" \\pm " <<CS1S_pp_tots<<endl;
  cout << setprecision(3)<<" total_sigma(2S)_pp = "<<CS2S_pp_tot <<" \\pm " <<CS2S_pp_tote<<" \\pm " <<CS2S_pp_tots<<endl;
  cout << setprecision(3)<<" total_sigma(3S)_pp = "<<CS3S_pp_tot <<" \\pm " <<CS3S_pp_tote<< endl;
  cout << setprecision(3)<<" total_sigma(1S)_AA = "<<CS1S_aa_tot <<" \\pm " <<CS1S_aa_tote  <<" \\pm " <<CS1S_aa_tots<<endl;
  cout << setprecision(3)<<" total_sigma(2S)_AA = "<<CS2S_aa_tot <<" \\pm " <<CS2S_aa_tote <<" \\pm " <<CS2S_aa_tots<<endl;
  cout << setprecision(3)<<" total_sigma(3S)_AA = "<<CS3S_aa_tot <<" \\pm " <<CS3S_aa_tote<<endl;
  cout  << setprecision(3)<< "Raa_1S = "<<RAA_1S_tot<<" \\pm "<<RAA_1S_tote<<"  \\pm " << RAA_1S_tots <<" syst." << endl;
  cout << setprecision(3)<< "Raa_2S = "<<RAA_2S_tot<<" \\pm "<<RAA_2S_tote<<"  \\pm " << RAA_2S_tots <<" syst." << endl;
  cout<< setprecision(3) << "Raa_3S = "<<RAA_3S_tot<<" \\pm "<<RAA_3S_tote << endl;
  cout<<" FC 95% Confidence on upper limit sigma(3S)_AA = "<<CS3S_aa_UL <<" nb "<<endl;
  cout << " FC 95% Confidence on upper limit Raa_3S = "<<RAA_3S_UL<<endl;

  if(plotRAA){
    TCanvas *c1 = new TCanvas("c1", "c1",423,55,600,600);
    // gStyle->SetOptStat(0);
    // gStyle->SetOptTitle(0);
    // c1->SetFillColor(0);
    // c1->SetBorderMode(0);
    // c1->SetBorderSize(0);
    // c1->SetTickx(1);
    // c1->SetTicky(1);
    // c1->SetFrameBorderMode(0);
    // c1->SetFrameBorderMode(0);
    c1->cd();

    TF1 *f4 = new TF1("f4","1",0,400);
    f4->SetLineWidth(1);
    f4->GetYaxis()->SetRangeUser(0.0,1.4);
    f4->GetXaxis()->SetTitle("N_{Part}");
    f4->GetXaxis()->CenterTitle(true);
    // f4->GetXaxis()->SetLabelFont(42);
    // f4->GetXaxis()->SetTitleSize(0.05);
    // f4->GetXaxis()->SetTitleOffset(1.1);
    // f4->GetYaxis()->SetTitleOffset(1.1);
    // f4->GetYaxis()->SetTitleFont(42);
    f4->GetYaxis()->SetTitle("R_{AA}");
    // f4->GetYaxis()->SetTitleSize(0.05);
    f4->SetLineColor(kBlack);
    f4->Draw();
    TGraphErrors *gcent2syst = new TGraphErrors(4,cent,RAA_2S_cent,centErr2014,RAA_2S_cents);
    gcent2syst->SetLineColor(kOrange+4);
    gcent2syst->SetFillStyle(0);
    gcent2syst->SetLineWidth(2);
    gcent2syst->SetMarkerSize(0);
    gcent2syst->Draw("2");
    if(!plotTight){

      TGraphErrors *gcent1syst = new TGraphErrors(nCentBins_2014,nPart2014,RAA_1S_cent,centErr2014,RAA_1S_cents); //for fun
      gcent1syst->SetLineColor(kOrange+1);
      gcent1syst->SetFillStyle(0);
      gcent1syst->SetLineWidth(2);
      gcent1syst->SetMarkerSize(0);
      gcent1syst->Draw("2");
      TGraphErrors *gcent1 = new TGraphErrors(nCentBins_2014,nPart2014,RAA_1S_cent,centnoErr,RAA_1S_cente); //for fun

      gcent1->SetMarkerColor(kOrange+1);
      gcent1->SetMarkerStyle(21);
      gcent1->SetMarkerSize(1.2);

      TGraphErrors *gcent1circle = new TGraphErrors(nCentBins_2014,nPart2014,RAA_1S_cent,centnoErr,RAA_1S_cente);
      gcent1circle->SetMarkerStyle(25);
      gcent1circle->SetMarkerSize(1.2);
      gcent1circle->SetLineColor(kBlack);
      gcent1->Draw("pe");
      gcent1circle->Draw("p");
      f4->Draw("same");
      gPad->RedrawAxis();
    }
    if(plotTight){
 TGraphErrors *gcent1syst = new TGraphErrors(nCentBins_2014,nPart2014,RAA_1S_cent,centErr2014,RAA_1S_cents); //for fun
      gcent1syst->SetLineColor(kOrange+1);
      gcent1syst->SetFillStyle(0);
      gcent1syst->SetLineWidth(2);
      gcent1syst->SetMarkerSize(0);
      gcent1syst->Draw("2");
      TGraphErrors *gcent1 = new TGraphErrors(nCentBins_2014,nPart2014,RAA_1S_cent,centnoErr,RAA_1S_cente); //for fun

      gcent1->SetMarkerColor(kOrange+1);
      gcent1->SetMarkerStyle(21);
      gcent1->SetMarkerSize(1.2);

      TGraphErrors *gcent1circle = new TGraphErrors(nCentBins_2014,nPart2014,RAA_1S_cent,centnoErr,RAA_1S_cente);
      gcent1circle->SetMarkerStyle(25);
      gcent1circle->SetMarkerSize(1.2);
      gcent1circle->SetLineColor(kBlack);
      gcent1->Draw("pe");
      gcent1circle->Draw("p");
      f4->Draw("same");
      gPad->RedrawAxis();
      //TGraphErrors RAA_1S 2014 (pt4) 
      TGraphErrors *gcent1syst4 = new TGraphErrors(nCentBins_2014,nPart2014,RAA_1S_cent4,centErr2014,RAA_1S_cent4s);
      gcent1syst4->SetLineColor(kGreen+1);
      gcent1syst4->SetFillStyle(0);
      gcent1syst4->SetLineWidth(2);
      gcent1syst4->SetMarkerSize(0);
      gcent1syst4->Draw("2");
      TGraphErrors *gcent14 = new TGraphErrors(nCentBins_2014,nPart2014,RAA_1S_cent4,centnoErr,RAA_1S_cent4e);
      gcent14->SetMarkerColor(kGreen+1);
      gcent14->SetMarkerStyle(21);
      gcent14->SetMarkerSize(1.2);
      TGraphErrors *gcent1circle4 = new TGraphErrors(nCentBins_2014,nPart2014,RAA_1S_cent4,centnoErr,RAA_1S_cent4e);
      gcent1circle4->SetMarkerStyle(25);
      gcent1circle4->SetMarkerSize(1.2);
      gcent1circle4->SetLineColor(kBlack);
      gcent14->Draw("pe");
      gcent1circle4->Draw("p");
      f4->Draw("same");
      gPad->RedrawAxis();
      //TGraphErrors RAA_1S_2011 (pt4)
      TGraphErrors *gcent2011syst = new TGraphErrors(nCentBins_2014-1,cent,RAA_1S_2011,centErr2014,RAA_1S_2011s);
      gcent2011syst->SetLineColor(kGreen+4);
      gcent2011syst->SetFillStyle(0);
      gcent2011syst->SetLineWidth(2);
      gcent2011syst->SetMarkerSize(0);
      // gcent2011syst->Draw("2");
      TGraphErrors *gcent2011 = new TGraphErrors(nCentBins_2014-1,cent,RAA_1S_2011,centnoErr,RAA_1S_2011e);
      gcent2011->SetMarkerColor(kGreen+4);
      gcent2011->SetMarkerStyle(20);
      gcent2011->SetMarkerSize(1.2);
      TGraphErrors *gcent2011circle = new TGraphErrors(nCentBins_2014-1,cent,RAA_1S_2011,centnoErr,RAA_1S_2011e);
      gcent2011circle->SetMarkerStyle(24);
      gcent2011circle->SetMarkerSize(1.2);
      gcent2011circle->SetLineColor(kBlack);
      // gcent2011->Draw("pe");
      // gcent2011circle->Draw("p");
      f4->Draw("same");
      gPad->RedrawAxis();
    }else{
    
      if(!FourBins){
	//TGraphErrors RAA_2S 2014  
	TGraphErrors *gcent2syst = new TGraphErrors(4,cent,RAA_2S_cent,centErr2014,RAA_2S_cents);
	gcent2syst->SetLineColor(kOrange+4);
	gcent2syst->SetFillStyle(0);
	gcent2syst->SetLineWidth(2);
	gcent2syst->SetMarkerSize(0);
	gcent2syst->Draw("2");
	TGraphErrors *gcent2 = new TGraphErrors(4,cent,RAA_2S_cent,centnoErr,RAA_2S_cente);
	gcent2->SetMarkerColor(kOrange+4);
	gcent2->SetMarkerStyle(20);
	gcent2->SetMarkerSize(1.2);
	TGraphErrors *gcent2circle = new TGraphErrors(4,cent,RAA_2S_cent,centnoErr,RAA_2S_cente);
	gcent2circle->SetMarkerStyle(24);
	gcent2circle->SetMarkerSize(1.2);
	gcent2circle->SetLineColor(kBlack);
	gcent2->Draw("pe");
	gcent2circle->Draw("p");
	f4->Draw("same");
	gPad->RedrawAxis();
      }
      else {
	TGraphErrors *gcent2 = new TGraphErrors(4,nPart2,RAA_2S_4bin,centnoErr,RAA_2S_4bine);
	gcent2->SetMarkerColor(kOrange+4);
	gcent2->SetMarkerStyle(20);
	gcent2->SetMarkerSize(1.2);
	TGraphErrors *gcent2syst = new TGraphErrors(4,nPart2,RAA_2S_4bin,centErr2014,RAA_2S_cents);
	gcent2syst->SetLineColor(kOrange+4);
	gcent2syst->SetFillStyle(0);
	gcent2syst->SetLineWidth(2);
	gcent2syst->SetMarkerSize(0);
	gcent2syst->Draw("2");
	TGraphErrors *gcent2circle = new TGraphErrors(4,nPart2,RAA_2S_4bin,centnoErr,RAA_2S_4bine);
	gcent2circle->SetMarkerStyle(24);
	gcent2circle->SetMarkerSize(1.2);
	gcent2circle->SetLineColor(kBlack);
	gcent2->Draw("pe");
	gcent2circle->Draw("p");
	f4->Draw("same");
	gPad->RedrawAxis();
      }
    }
    //legends
    // L^{pp}_{int}=5.4 /nb
    TLegend *leg = new TLegend(0.30,0.53,0.71,0.68);
    leg->SetBorderSize(0);
    leg->SetTextSize(gTextSize);
    leg->SetLineColor(1);
    leg->SetLineStyle(1);
    leg->SetLineWidth(0.4);
    leg->SetFillColor(0);
    leg->SetFillStyle(0);
    leg->AddEntry(gcent1,"#varUpsilon(1S)","pe");
    if(!plotTight)  leg->AddEntry(gcent2,"#varUpsilon(2S) ","pe");
    // Internal #sqrt{s_{NN}} = 2.76 TeV
    //  if(!plotTight){ TLegendEntry *}
      // TLegendEntry *entry=leg->AddEntry(gcent1syst,"#varUpsilon(1S)","pe");}
    if(plotTight){ TLegendEntry *entry=leg->AddEntry(gcent14,"#varUpsilon(1S) tight","lp");
      // entry=leg->AddEntry(gcent2011,"#varUpsilon(1S) 2011","p");    
    }


    leg->SetTextFont(42);
    leg->Draw();

    // |y|<2.4
    TLatex latexrap;
    latexrap.SetTextSize(gTextSize);
    latexrap.SetTextFont(42);
    latexrap.DrawLatex(30,1.2,"|y|<2.4");
   
    if(!plotTight){TBox *box1S = new TBox(370,1-syst1S_pp_centGlob,385,1+syst1S_pp_centGlob);
      box1S->SetFillColor(kOrange+1);
      box1S->Draw();
      TBox *box2S = new TBox(385,1-syst2S_pp_centGlob4,400,1+syst2S_pp_centGlob4);
      box2S->SetFillColor(kOrange+4);
      box2S->Draw();
    }
    if(plotTight){
      TBox *box1S4 = new TBox(385,1-syst1S_pp_centGlob4,400,1+syst1S_pp_centGlob4);
      box1S4->SetFillColor(kGreen+1);
      box1S4->Draw();
      TBox *box1S = new TBox(370,1-syst1S_pp_centGlob,385,1+syst1S_pp_centGlob);
      box1S->SetFillColor(kOrange+1);
      box1S->Draw();
      // TBox *box1S2011 = new TBox(385,1-RAA_1S_2011sg,400,1+RAA_1S_2011sg);
      // box1S2011->SetFillColor(kBlack);
      // box1S2011->Draw();
    }
    TLegend *leg2= new TLegend(0.58,0.53,0.74,0.68);
    leg2->SetBorderSize(0);
    leg2->SetTextSize(gTextSize);
    leg2->SetTextFont(42);
    leg2->SetLineColor(0);
    leg2->SetLineStyle(1);
    leg2->SetLineWidth(0.4);
    leg2->SetFillColor(0);
    leg2->SetFillStyle(0);
    if(!plotTight){    leg2->AddEntry(box1S,"#varUpsilon(1S) global syst.","f");
      leg2->AddEntry(box2S,"#varUpsilon(2S) global syst.","f");}
    if(plotTight){ leg2->AddEntry(box1S,"#varUpsilon(1S) syst. unc. p_{T} > 3.5 + 4","f");
      //      leg2->AddEntry(box1S2011,"#varUpsilon(1S) 2011 global syst. 2011","f");}
      leg2->AddEntry(box1S4,"#varUpsilon(1S) syst. unc. p_{T} > 4","f");}
    leg2->Draw();
    // TBox *box = new TBox(385,0.864,400,1.136);

    // ci = TColor::GetColor("#99ff99");
    // box->SetFillColor(ci);
    // box->Draw();
    //MB stuff
    c1->cd();
    CMS_lumi(c1,103,33);
    c1->Update();
    c1->RedrawAxis();
    c1->GetFrame()->Draw();
    if(plotTight){
      c1->SaveAs("~/Documents/PR/forTWiki/CSandRAA/RAA_nPart_Tight.pdf");
      c1->SaveAs("~/Desktop/RAA_nPart_Tight.png");
      cout << "CHANGE FILE NAME !?!?!?!?! "<<endl;
    }else if(!FourBins)
      {
	c1->SaveAs("~/Documents/PR/forTWiki/CSandRAA/RAA_nPart.pdf");
	c1->SaveAs("~/Desktop/RAA_nPart.png");
	cout << "CHANGE FILE NAME!!!!!" << endl;
      }						
    else if (FourBins)
      {
	c1->SaveAs("~/Documents/PR/forTWiki/CSandRAA/RAA_nPart_4bins.pdf");
	c1->SaveAs("~/Desktop/RAA_nPart_4bins.png");
      }
  }
  //=========Macro generated from canvas: c1/c1
  //=========  (Mon Apr 28 03:36:31 2014) by ROOT version5.34/02
  if(plotRAA){continue;
   
   
    TGraphErrors *gre = new TGraphErrors(7);
    // gre->SetName("Graph");
    // gre->SetTitle("Graph");
    gre->SetFillColor(1);

    Int_t ci;   // for color index setting
    ci = TColor::GetColor("#99ff99");
    gre->SetLineColor(ci);
    gre->SetLineWidth(25);
    gre->SetMarkerStyle(20);
    gre->SetMarkerSize(0);
    gre->SetPoint(0,22.1,1.005);
    gre->SetPointError(0,0,0.176);
    gre->SetPoint(1,86.3,0.59);
    gre->SetPointError(1,0,0.086);
    gre->SetPoint(2,130,0.681);
    gre->SetPointError(2,0,0.085);
    gre->SetPoint(3,187.1,0.614);
    gre->SetPointError(3,0,0.075);
    gre->SetPoint(4,261.4,0.484);
    gre->SetPointError(4,0,0.049);
    gre->SetPoint(5,329.4,0.432);
    gre->SetPointError(5,0,0.046);
    gre->SetPoint(6,381.3,0.411);
    gre->SetPointError(6,0,0.048);
   
    TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","Graph_Graph1",100,0,417.22);
    // Graph_Graph1->SetMinimum(0.2812);
    // Graph_Graph1->SetMaximum(1.2628);
    Graph_Graph1->SetDirectory(0);
    Graph_Graph1->SetStats(0);
    Graph_Graph1->SetMarkerStyle(20);
    Graph_Graph1->SetMarkerSize(0.8);
    Graph_Graph1->GetXaxis()->SetLabelFont(42);
    Graph_Graph1->GetXaxis()->SetTitleSize(0.048);
    Graph_Graph1->GetXaxis()->SetTitleOffset(1.15);
    Graph_Graph1->GetXaxis()->SetTitleFont(42);
    Graph_Graph1->GetYaxis()->SetLabelFont(42);
    Graph_Graph1->GetYaxis()->SetTitleSize(0.048);
    Graph_Graph1->GetYaxis()->SetTitleOffset(1.2);
    Graph_Graph1->GetYaxis()->SetTitleFont(42);
    Graph_Graph1->GetZaxis()->SetLabelFont(42);
    Graph_Graph1->GetZaxis()->SetTitleSize(0.048);
    Graph_Graph1->GetZaxis()->SetTitleFont(42);
    gre->SetHistogram(Graph_Graph1);
   
    gre->Draw("e");
   
    gre = new TGraphErrors(7);
    gre->SetName("Graph_Graph1");
    gre->SetTitle("Graph_Graph1");
    gre->SetFillColor(1);

    ci = TColor::GetColor("#009900");
    gre->SetMarkerColor(ci);
    gre->SetMarkerStyle(33);
    gre->SetMarkerSize(2);
    gre->SetPoint(0,20.1,1.005);
    gre->SetPointError(0,0,0.121);
    gre->SetPoint(1,84.3,0.59);
    gre->SetPointError(1,0,0.096);
    gre->SetPoint(2,128,0.681);
    gre->SetPointError(2,0,0.069);
    gre->SetPoint(3,185.1,0.614);
    gre->SetPointError(3,0,0.053);
    gre->SetPoint(4,259.4,0.484);
    gre->SetPointError(4,0,0.04);
    gre->SetPoint(5,327.4,0.432);
    gre->SetPointError(5,0,0.048);
    gre->SetPoint(6,379.3,0.411);
    gre->SetPointError(6,0,0.043);
   
    TH1F *Graph_Graph2 = new TH1F("Graph_Graph2","Graph_Graph2",100,0,417.22);
    // Graph_Graph2->SetMinimum(0.2922);
    // Graph_Graph2->SetMaximum(1.6);
    Graph_Graph2->SetDirectory(0);
    Graph_Graph2->SetStats(0);
    Graph_Graph2->SetMarkerStyle(20);
    Graph_Graph2->SetMarkerSize(0.8);
    Graph_Graph2->GetXaxis()->SetLabelFont(42);
    Graph_Graph2->GetXaxis()->SetTitleSize(0.048);
    Graph_Graph2->GetXaxis()->SetTitleOffset(1.15);
    Graph_Graph2->GetXaxis()->SetTitleFont(42);
    Graph_Graph2->GetYaxis()->SetLabelFont(42);
    Graph_Graph2->GetYaxis()->SetTitleSize(0.048);
    Graph_Graph2->GetYaxis()->SetTitleOffset(1.2);
    Graph_Graph2->GetYaxis()->SetTitleFont(42);
    Graph_Graph2->GetZaxis()->SetLabelFont(42);
    Graph_Graph2->GetZaxis()->SetTitleSize(0.048);
    Graph_Graph2->GetZaxis()->SetTitleFont(42);
    gre->SetHistogram(Graph_Graph2);
   
    gre->Draw("pe");
   
    gre = new TGraphErrors(7);
    gre->SetName("Graph_Graph2");
    gre->SetTitle("Graph_Graph2");
    gre->SetFillColor(1);
    gre->SetMarkerStyle(27);
    gre->SetMarkerSize(2);
    gre->SetPoint(0,20.1,1.005);
    gre->SetPointError(0,0,0.121);
    gre->SetPoint(1,84.3,0.59);
    gre->SetPointError(1,0,0.096);
    gre->SetPoint(2,128,0.681);
    gre->SetPointError(2,0,0.069);
    gre->SetPoint(3,185.1,0.614);
    gre->SetPointError(3,0,0.053);
    gre->SetPoint(4,259.4,0.484);
    gre->SetPointError(4,0,0.04);
    gre->SetPoint(5,327.4,0.432);
    gre->SetPointError(5,0,0.048);
    gre->SetPoint(6,379.3,0.411);
    gre->SetPointError(6,0,0.043);
   
    TH1F *Graph_Graph3 = new TH1F("Graph_Graph3","Graph_Graph3",100,0,417.22);
    // Graph_Graph3->SetMinimum(0.2922);
    // Graph_Graph3->SetMaximum(1.2018);
    Graph_Graph3->SetDirectory(0);
    Graph_Graph3->SetStats(0);
    Graph_Graph3->SetMarkerStyle(20);
    Graph_Graph3->SetMarkerSize(0.8);
    Graph_Graph3->GetXaxis()->SetLabelFont(42);
    Graph_Graph3->GetXaxis()->SetTitleSize(0.048);
    Graph_Graph3->GetXaxis()->SetTitleOffset(1.15);
    Graph_Graph3->GetXaxis()->SetTitleFont(42);
    Graph_Graph3->GetYaxis()->SetLabelFont(42);
    Graph_Graph3->GetYaxis()->SetTitleSize(0.048);
    Graph_Graph3->GetYaxis()->SetTitleOffset(1.2);
    Graph_Graph3->GetYaxis()->SetTitleFont(42);
    Graph_Graph3->GetZaxis()->SetLabelFont(42);
    Graph_Graph3->GetZaxis()->SetTitleSize(0.048);
    Graph_Graph3->GetZaxis()->SetTitleFont(42);
    gre->SetHistogram(Graph_Graph3);
   
    gre->Draw("p");
   
    gre = new TGraphErrors(3);
    gre->SetName("Graph_Graph3");
    gre->SetTitle("Graph_Graph3");
    gre->SetFillColor(1);

    ci = TColor::GetColor("#ff99ff");
    gre->SetLineColor(ci);
    gre->SetLineWidth(25);
    gre->SetMarkerStyle(20);
    gre->SetMarkerSize(0);
    gre->SetPoint(0,64.2184,0.677);
    gre->SetPointError(0,0,0.107);
    gre->SetPoint(1,261.4178,0.842);
    gre->SetPointError(1,0,0.13);
    gre->SetPoint(2,355.3528,0.454);
    gre->SetPointError(2,0,0.079);
   

   
 

    TBox *box = new TBox(385,0.864,400,1.136);

    ci = TColor::GetColor("#99ff99");
    box->SetFillColor(ci);
    box->Draw();

   
    TF1 *f4 = new TF1("f4","1",0,400);
    f4->SetFillColor(19);
    f4->SetFillStyle(0);
    f4->SetMarkerStyle(20);
    f4->SetMarkerSize(0.8);
    f4->SetLineWidth(1);
    f4->GetXaxis()->SetTitle("N_{part}");
    f4->GetXaxis()->CenterTitle(true);
    f4->GetXaxis()->SetLabelFont(42);
    f4->GetXaxis()->SetTitleSize(0.048);
    f4->GetXaxis()->SetTitleOffset(1.15);
    f4->GetXaxis()->SetTitleFont(42);
    f4->GetYaxis()->SetTitle("R_{AA}");
    f4->GetYaxis()->SetLabelFont(42);
    f4->GetYaxis()->SetTitleSize(0.048);
    f4->GetYaxis()->SetTitleFont(42);
    f4->Draw("same");
   
    TH1F *Graph = new TH1F("Graph","Graph",100,0,417.22);
    // Graph->SetMinimum(0.2812);
    // Graph->SetMaximum(1.2628);
    Graph->SetDirectory(0);
    Graph->SetStats(0);
    Graph->SetMarkerStyle(20);
    Graph->SetMarkerSize(0.8);
    Graph->GetXaxis()->SetLabelFont(42);
    Graph->GetXaxis()->SetTitleSize(0.048);
    Graph->GetXaxis()->SetTitleOffset(1.15);
    Graph->GetXaxis()->SetTitleFont(42);
    Graph->GetYaxis()->SetLabelFont(42);
    Graph->GetYaxis()->SetTitleSize(0.048);
    Graph->GetYaxis()->SetTitleOffset(1.2);
    Graph->GetYaxis()->SetTitleFont(42);
    Graph->GetZaxis()->SetLabelFont(42);
    Graph->GetZaxis()->SetTitleSize(0.048);
    Graph->GetZaxis()->SetTitleFont(42);
    Graph->Draw("sameaxis");
    TLatex *   tex = new TLatex(170,1.45,"CMS PbPb  #sqrt{s_{NN}} = 2.76 TeV");
    tex->SetTextSize(0.04);
    tex->SetTextFont(42);
    tex->SetLineWidth(2);
    tex->Draw();
 

    //x axis for old points is good-2.
    TGraphErrors *gre = new TGraphErrors(7);
    gre->SetName("Graph");
    gre->SetTitle("Graph");
    gre->SetFillColor(1);

    gre = new TGraphErrors(7);
    gre->SetName("Graph_2S");
    gre->SetTitle("Graph_2S");
    gre->SetFillColor(1);
    gre->SetMarkerStyle(24);
    gre->SetMarkerSize(1.2);
    gre->SetPoint(0,20.1,0.3);
    gre->SetPointError(0,0,0.157);
    gre->SetPoint(1,84.3,0.251);
    gre->SetPointError(1,0,0.138);
    gre->SetPoint(2,128,0.237);
    gre->SetPointError(2,0,0.098);
    gre->SetPoint(3,185.1,0.26);
    gre->SetPointError(3,0,0.079);
    gre->SetPoint(4,259.4,0.068);
    gre->SetPointError(4,0,0.053);
    gre->SetPoint(5,327.4,0.044);
    gre->SetPointError(5,0,0.06);
    gre->SetPoint(6,379.3,0.111);
    gre->SetPointError(6,0,0.061);
   
    TH1F *Graph_Graph6 = new TH1F("Graph_Graph6","Graph",100,0,417.22);
    Graph_Graph6->SetMinimum(-0.0633);
    Graph_Graph6->SetMaximum(0.5043);
    Graph_Graph6->SetDirectory(0);
    Graph_Graph6->SetStats(0);
    Graph_Graph6->SetMarkerStyle(20);
    Graph_Graph6->SetMarkerSize(0.8);
    Graph_Graph6->GetXaxis()->SetLabelFont(42);
    Graph_Graph6->GetXaxis()->SetTitleSize(0.048);
    Graph_Graph6->GetXaxis()->SetTitleOffset(1.15);
    Graph_Graph6->GetXaxis()->SetTitleFont(42);
    Graph_Graph6->GetYaxis()->SetLabelFont(42);
    Graph_Graph6->GetYaxis()->SetTitleSize(0.048);
    Graph_Graph6->GetYaxis()->SetTitleOffset(1.2);
    Graph_Graph6->GetYaxis()->SetTitleFont(42);
    Graph_Graph6->GetZaxis()->SetLabelFont(42);
    Graph_Graph6->GetZaxis()->SetTitleSize(0.048);
    Graph_Graph6->GetZaxis()->SetTitleFont(42);
    gre->SetHistogram(Graph_Graph6);
    gre->GetYaxis()->SetRangeUser(0,1.8);
    gre->Draw("p");
   
  
    entry=leg->AddEntry("Graph_Graph1","#varUpsilon(1S) L^{pp}_{int}=231 /nb, p_{T}^{#mu} > 4 GeV","p");
    entry->SetLineColor(1);
    entry->SetLineStyle(1);
    entry->SetLineWidth(1);

    ci = TColor::GetColor("#cc00cc");
    entry->SetMarkerColor(ci);
    entry->SetMarkerStyle(20);
    entry->SetMarkerSize(1.2);

    entry=leg->AddEntry("Graph_2S","#varUpsilon(2S)","p");
    entry->SetLineColor(1);
    entry->SetLineStyle(1);
    entry->SetLineWidth(3);

    leg->Draw();



  }
  ofSyst.close();

}
//only for 1S - > uncorrected RAA
void plotRAA_uncorr(){

  float pt [nPtBins_2013] = {1.25, 3.75, 6.5, 10., 16.};
  float pte[nPtBins_2013] = {1.25, 1.25, 1.5, 2., 4.};
  float deltaPt[nPtBins_2013]   = {2.5,2.5,3,4,8};
  
  float deltaRapEven[nRapBins_2014] = {0.8,0.8,0.8,0.8,0.8,0.8};

  float uncorrRAA_1S_pt[nPtBins_2013] = {};
  float uncorrRAA_1S_pte[nPtBins_2013] = {};
  float uncorrRAA_1S_ptU[nPtBins_2013] = {};
  float uncorrRAA_1S_pteU[nPtBins_2013] = {};
  float uncorrRAA_1S_rap2014[nPtBins_2013] = {};
  float uncorrRAA_1S_rap2014e[nPtBins_2013] = {};
  float CS1S_pp_pt[nPtBins_2013] = {};
  float CS1S_pp_pte[nPtBins_2013] = {};
  float CS1S_pp_ptU[nPtBins_2013] = {};
  float CS1S_pp_pteU[nPtBins_2013] = {};
  float CS1S_pp_rap2014[nRapBins_2014] = {};
  float CS1S_pp_rap2014e[nRapBins_2014] = {};

  float CS1S_aa_pt[nPtBins_2013] = {};
  float CS1S_aa_pte[nPtBins_2013] = {};

  float CS1S_aa_ptU[nPtBins_2013] = {};
  float CS1S_aa_pteU[nPtBins_2013] = {};
  float CS1S_aa_rap2014[nRapBins_2014] = {};
  float CS1S_aa_rap2014e[nRapBins_2014] = {};


  if (plotUncorrected){

      for(int i=0; i<nRapBins_2014;i++)
	{
	  CS1S_aa_rap2014[i]=N1S_aa_rap3p5_2014[i]/(N_MB_corr * T_AA_b * deltaRapEven[i]);
	  CS1S_aa_rap2014e[i]=N1S_aa_rap3p5_2014e[i]/(N_MB_corr * T_AA_b * deltaRapEven[i]);
	  CS1S_pp_rap2014[i]=N1S_pp_rap3p5_2014[i]/(L_pp_invNb*deltaRapEven[i]);
	  CS1S_pp_rap2014e[i]=N1S_pp_rap3p5_2014e[i]/(L_pp_invNb*deltaRapEven[i]);
	  uncorrRAA_1S_rap2014[i]=computeRatio(CS1S_aa_rap2014[i] , CS1S_pp_rap2014[i]);
	  uncorrRAA_1S_rap2014e[i]=computeRatioError(CS1S_aa_rap2014[i],CS1S_pp_rap2014[i], CS1S_aa_rap2014e[i], CS1S_pp_rap2014e[i]);
	}

      for(int i = 0; i<nPtBins_2013 ; i++)
	{
	  CS1S_pp_pt[i]=N1S_pp_pt3p5[i]/(L_pp_invNb*deltaPt[i]*RapBinWidth);
	  CS1S_pp_pte[i]=N1S_pp_pt3p5e[i]/(L_pp_invNb*deltaPt[i]*RapBinWidth);
	  CS1S_aa_pt[i]=N1S_aa_pt3p5[i]/(N_MB_corr * T_AA_b * deltaPt[i]*RapBinWidth);
	  CS1S_aa_pte[i]=N1S_aa_pt3p5e[i]/(N_MB_corr * T_AA_b * deltaPt[i]*RapBinWidth);
      
	  CS1S_pp_ptU[i]=N1S_pp_pt3p5U[i]/(L_pp_invNb*deltaPt[i]);
	  CS1S_pp_pteU[i]=N1S_pp_pt3p5eU[i]/(L_pp_invNb*deltaPt[i]);
	  CS1S_aa_ptU[i]=N1S_aa_pt3p5U[i]/(N_MB_corr * T_AA_b * deltaPt[i]);
	  CS1S_aa_pteU[i]=N1S_aa_pt3p5eU[i]/(N_MB_corr * T_AA_b * deltaPt[i]);
      
	  uncorrRAA_1S_pt[i]=computeRatio(CS1S_aa_pt[i] , CS1S_pp_pt[i]);
	  uncorrRAA_1S_pte[i]=computeRatioError(CS1S_aa_pt[i],CS1S_pp_pt[i], CS1S_aa_pte[i], CS1S_pp_pte[i]);
	  uncorrRAA_1S_ptU[i]=computeRatio(CS1S_aa_ptU[i] , CS1S_pp_ptU[i]);
	  uncorrRAA_1S_pteU[i]=computeRatioError(CS1S_aa_ptU[i],CS1S_pp_ptU[i], CS1S_aa_pteU[i], CS1S_pp_pteU[i]);
	}
 
      //drawing cross sections

      TCanvas *cptu = new TCanvas("cptu","cptu"); 
      cptu->cd();
      TPad *ppt1 = new TPad("ppt1","ppt1",0.0,0.0,1.0,1.0);
      ppt1->SetBottomMargin(0.12);
      ppt1->SetTopMargin(0.03);
      ppt1->SetRightMargin(0.03);
      ppt1->SetLeftMargin(0.16);
      ppt1->SetLogy();
      ppt1->Draw();
      ppt1->cd();
      TF1 *f4Pt = new TF1("f4Pt","0.000000001",0,21);
      f4Pt->SetLineWidth(0);
      f4Pt->GetYaxis()->SetTitleOffset(2);
      f4Pt->GetXaxis()->SetTitle("p_{T}^{#varUpsilon} (GeV/c)");		
      f4Pt->GetYaxis()->SetTitle("#frac{1}{L_{pp,PbPb}}#frac{dN}{dp_{T}} (b/(GeV/c))");


      f4Pt->GetYaxis()->SetTitleSize(0.028);
      //f4Pt->GetYaxis()->SetRangeUser(0.01,.09);
      f4Pt->GetXaxis()->CenterTitle(kTRUE);
      f4Pt->Draw();
      //one pad to draw PbPb yields,
      TGraphErrors *gpt1 = new TGraphErrors(nPtBins_2013,pt,CS1S_aa_pt,pte,CS1S_aa_pte);
      gpt1->SetMarkerColor(8);
      gpt1->SetMarkerStyle(33);
      gpt1->SetMarkerSize(2);



      TGraphErrors *gpt1circle = new TGraphErrors(nPtBins_2013,pt,CS1S_aa_pt,pte,CS1S_aa_pte);
      gpt1circle->SetMarkerStyle(27);
      gpt1circle->SetMarkerSize(2);
      gpt1circle->SetLineColor(kBlack);
      gpt1->Draw("pe");
      gpt1circle->Draw("p");
      f4Pt->Draw("same");
      gPad->RedrawAxis();
    
      TGraphErrors *gpt1pp = new TGraphErrors(nPtBins_2013,pt,CS1S_pp_pt,pte,CS1S_pp_pte);
      gpt1pp->SetMarkerColor(kAzure+1);
      gpt1pp->SetMarkerStyle(21);
      gpt1pp->SetMarkerSize(1.2);
      TGraphErrors *gpt1circlepp = new TGraphErrors(nPtBins_2013,pt,CS1S_pp_pt,pte,CS1S_pp_pte);
      gpt1circlepp->SetMarkerStyle(25);
      gpt1circlepp->SetMarkerSize(1.22);
      gpt1circlepp->SetLineColor(kBlack);

      gpt1pp->Draw("pe");
      gpt1circlepp->Draw("p");
      f4Pt->Draw("same");
      gPad->RedrawAxis();

      TLegend *legend = new TLegend(0.482,0.84,0.88,0.7);
      legend->SetTextSize(0.029);
      legend->SetFillStyle(0);
      legend->SetFillColor(0);
      legend->SetBorderSize(0);
      legend->SetTextFont(42);
      legend->AddEntry(gpt1pp,"#varUpsilon(1S), pp ","lp");
      legend->AddEntry(gpt1,"#varUpsilon(1S), PbPb ","lp");

      legend->Draw();
      TLatex *l1CMSpt = new TLatex(8,0.0000000008, "CMS Internal #sqrt{s_{NN}} = 2.76 TeV");
      l1CMSpt->SetTextFont(42);
      l1CMSpt->SetTextSize(0.032);
      l1CMSpt->Draw();

 
      TLatex *lyL= new TLatex(2,0.0000000008,"L_{PbPb} = 166 #mub^{-1}; |y| < 2.4");
 
      lyL->SetTextSize(0.029);
      lyL->DrawLatex(2,0.0000000005,"L_{pp} = 5.4 pb^{-1}; |y| < 2.4");
      lyL->SetTextSize(0.029);
      lyL->DrawLatex(2,0.000000002,"Raw Yields");
      lyL->Draw();
    }

    if(plotRAA && plotUncorrected){
      TCanvas *cRaaptu = new TCanvas("cRaaptu","cRaaptu"); 
      cRaaptu->cd();
      // TPad *ppt2 = new TPad("ppt2","ppt2",0.0,0.0,1.0,1.0);
      // ppt2->SetBottomMargin(0.12);
      // ppt2->SetTopMargin(0.03);
      // ppt2->SetRightMargin(0.03);
      // ppt2->SetLeftMargin(0.16);
      // ppt2->Draw();
      // ppt2->cd();
      //one pad to draw RaaPt!
      TF1 *f4RaaPt = new TF1("f4RaaPt","1",0,21);
      f4RaaPt->SetLineWidth(0);
      f4RaaPt->SetLineColor(kBlack);
      f4RaaPt->GetXaxis()->SetTitle("p_{T}^{#varUpsilon} ");
      f4RaaPt->GetYaxis()->SetTitle("uncorrected R_{AA}");
      f4RaaPt->GetYaxis()->SetTitleOffset(1.8);
      f4RaaPt->GetYaxis()->SetTitleSize(0.028);
      f4RaaPt->GetYaxis()->SetRangeUser(0.,1);
      f4RaaPt->GetXaxis()->CenterTitle(kTRUE);
      f4RaaPt->Draw();
      TGraphErrors *gRaaPt1 = new TGraphErrors(nPtBins_2013,pt,uncorrRAA_1S_pt,pte,uncorrRAA_1S_pte);
      gRaaPt1->SetMarkerColor(8);
      gRaaPt1->SetMarkerStyle(33);
      gRaaPt1->SetMarkerSize(2);
      TGraphErrors *gRaaPt1circle = new TGraphErrors(nPtBins_2013,pt,uncorrRAA_1S_pt,pte,uncorrRAA_1S_pte);
      gRaaPt1circle->SetMarkerStyle(27);
      gRaaPt1circle->SetMarkerSize(2);
      gRaaPt1circle->SetLineColor(kBlack);
      gRaaPt1->Draw("pe");
      gRaaPt1circle->Draw("p");
      f4RaaPt->Draw("same");
      TLatex *l1CMSpt = new TLatex(10,0.8, "CMS Internal #sqrt{s_{NN}} = 2.76 TeV");
      l1CMSpt->SetTextFont(42);
      l1CMSpt->SetTextSize(0.032);
      l1CMSpt->Draw();
      TLatex *lyLPT= new TLatex(10,0.6,"L_{int}^{PbPb} = 166 #mub^{-1}; L_{int}^{pp} = 5.4 pb^{-1};");
      lyLPT->SetTextSize(0.032);
      lyLPT->Draw();
      lyLPT->SetTextSize(0.04);
      lyLPT->DrawLatex(7,0.15,"Uncorrected");
      // ppt2->Update();
      gPad->RedrawAxis();

      TCanvas *cRaaptUnfold = new TCanvas("cRaaptUnfold","cRaaptUnfold"); 
      cRaaptUnfold->cd();
      // TPad *ppt2 = new TPad("ppt2","ppt2",0.0,0.0,1.0,1.0);
      // ppt2->SetBottomMargin(0.12);
      // ppt2->SetTopMargin(0.03);
      // ppt2->SetRightMargin(0.03);
      // ppt2->SetLeftMargin(0.16);
      // ppt2->Draw();
      // ppt2->cd();
      TF1 *f4RaaPt = new TF1("f4RaaPt","1",0,21);
      f4RaaPt->SetLineWidth(0);
      f4RaaPt->SetLineColor(kBlack);
      f4RaaPt->GetXaxis()->SetTitle("p_{T}^{#varUpsilon} ");
      f4RaaPt->GetYaxis()->SetTitle("uncorrected, but unfolded R_{AA}");
      f4RaaPt->GetYaxis()->SetTitleOffset(1.8);
      f4RaaPt->GetYaxis()->SetTitleSize(0.028);
      f4RaaPt->GetYaxis()->SetRangeUser(0.,1.3);
      f4RaaPt->GetXaxis()->CenterTitle(kTRUE);
      f4RaaPt->Draw();
      TGraphErrors *gRaaPt1 = new TGraphErrors(nPtBins_2013,pt,uncorrRAA_1S_pt,pte,uncorrRAA_1S_pte);
      gRaaPt1->SetMarkerColor(8);
      gRaaPt1->SetMarkerStyle(33);
      gRaaPt1->SetMarkerSize(2);
      TGraphErrors *gRaaPt1circle = new TGraphErrors(nPtBins_2013,pt,uncorrRAA_1S_pt,pte,uncorrRAA_1S_pte);
      gRaaPt1circle->SetMarkerStyle(27);
      gRaaPt1circle->SetMarkerSize(2);
      gRaaPt1circle->SetLineColor(kBlack);
      gRaaPt1->Draw("pe");
      gRaaPt1circle->Draw("p");

      TGraphErrors *gRaaPt1U = new TGraphErrors(nPtBins_2013,pt,uncorrRAA_1S_ptU,pte,uncorrRAA_1S_pteU);
      gRaaPt1U->SetMarkerColor(kBlue-3);
      gRaaPt1U->SetMarkerStyle(33);
      gRaaPt1U->SetMarkerSize(2);
      TGraphErrors *gRaaPt1Ucircle = new TGraphErrors(nPtBins_2013,pt,uncorrRAA_1S_ptU,pte,uncorrRAA_1S_pteU);
      gRaaPt1Ucircle->SetMarkerStyle(27);
      gRaaPt1Ucircle->SetMarkerSize(2);
      gRaaPt1Ucircle->SetLineColor(kBlack);
      gRaaPt1U->Draw("pe");
      gRaaPt1Ucircle->Draw("p");
      f4RaaPt->Draw("same");
      TLatex *l1CMSpt = new TLatex(10,0.8, "CMS Internal #sqrt{s_{NN}} = 2.76 TeV");
      l1CMSpt->SetTextFont(42);
      l1CMSpt->SetTextSize(0.032);
      l1CMSpt->Draw();
      TLatex *lyLPT= new TLatex(10,0.6,"L_{int}^{PbPb} = 166 #mub^{-1}; L_{int}^{pp} = 5.4 pb^{-1};");
      lyLPT->SetTextSize(0.032);
      lyLPT->Draw();
      lyLPT->SetTextSize(0.04);
      lyLPT->DrawLatex(7,0.15,"Uncorrected");
      // ppt2->Update();
      TLegend *legend = new TLegend(0.2,0.65,0.4,0.75);
      legend->SetTextSize(0.029);
      legend->SetFillStyle(0);
      legend->SetFillColor(0);
      legend->SetBorderSize(0);
      legend->SetTextFont(42);
      legend->AddEntry(gRaaPt1U,"#varUpsilon(1S) unfolded","lp");
      legend->AddEntry(gRaaPt1,"#varUpsilon(1S) raw","lp");
      legend->Draw();
      gPad->RedrawAxis();
  

    }


    if(plotUncorrected){
      TCanvas *crapu = new TCanvas("crapu","crapu"); 
      crapu->cd();
      TPad *prap1 = new TPad("prap1","prap1",0.0,0.0,1.0,1.0);
      prap1->SetBottomMargin(0.12);
      prap1->SetTopMargin(0.03);
      prap1->SetRightMargin(0.03);
      prap1->SetLeftMargin(0.16);
      prap1->SetLogy();
      prap1->Draw();
      prap1->cd();
      TF1 *f4Rap = new TF1("f4Rap","0.000000001",0,2.45);
      f4Rap->SetLineWidth(0);
      f4Rap->GetYaxis()->SetTitleOffset(2);
      f4Rap->GetXaxis()->SetTitle("|y|");		
      f4Rap->GetYaxis()->SetTitle("#frac{1}{L_{pp,PbPb}}#frac{N}{#Delta_{y}} (b/(GeV/c))");


      f4Rap->GetYaxis()->SetTitleSize(0.028);
      //f4Rap->GetYaxis()->SetRangeUser(0.01,.09);
      f4Rap->GetXaxis()->CenterTitle(kTRUE);
      f4Rap->Draw();
      //one pad to draw PbPb yields,
      TGraphErrors *grap1 = new TGraphErrors(nRapBins_2013,rap,CS1S_aa_rap2014,rape,CS1S_aa_rap2014e);
      grap1->SetMarkerColor(8);
      grap1->SetMarkerStyle(33);
      grap1->SetMarkerSize(2);



      TGraphErrors *grap1circle = new TGraphErrors(nRapBins_2013,rap,CS1S_aa_rap2014,rape,CS1S_aa_rap2014e);
      grap1circle->SetMarkerStyle(27);
      grap1circle->SetMarkerSize(2);
      grap1circle->SetLineColor(kBlack);
      grap1->Draw("pe");
      grap1circle->Draw("p");
      f4Rap->Draw("same");
      gPad->RedrawAxis();
    
      TGraphErrors *grap1pp = new TGraphErrors(nRapBins_2014,rap,CS1S_pp_rap2014,rape,CS1S_pp_rap2014e);
      grap1pp->SetMarkerColor(kAzure+1);
      grap1pp->SetMarkerStyle(21);
      grap1pp->SetMarkerSize(1.2);
      TGraphErrors *grap1circlepp = new TGraphErrors(nRapBins_2014,rap,CS1S_pp_rap2014,rape,CS1S_pp_rap2014e);
      grap1circlepp->SetMarkerStyle(25);
      grap1circlepp->SetMarkerSize(1.22);
      grap1circlepp->SetLineColor(kBlack);
      grap1pp->Draw("pe");
      grap1circlepp->Draw("p");
      f4Rap->Draw("same");
      gPad->RedrawAxis();

      TLegend *legend = new TLegend(0.482,0.84,0.88,0.7);
      legend->SetTextSize(0.029);
      legend->SetFillStyle(0);
      legend->SetFillColor(0);
      legend->SetBorderSize(0);
      legend->SetTextFont(42);
      legend->AddEntry(grap1pp,"#varUpsilon(1S), pp ","lp");
      legend->AddEntry(grap1,"#varUpsilon(1S), PbPb ","lp");

      legend->Draw();
      TLatex *l1CMSrap = new TLatex(0.8,0.0000000008, "CMS Internal #sqrt{s_{NN}} = 2.76 TeV");
      l1CMSrap->SetTextFont(42);
      l1CMSrap->SetTextSize(0.032);
      l1CMSrap->Draw();

 
      TLatex *lyL= new TLatex(1.2,0.0000000008,"L_{PbPb} = 166 #mub^{-1}; |y| < 2.4");
 
      lyL->SetTextSize(0.029);
      lyL->DrawLatex(1.2,0.0000000005,"L_{pp} = 5.4 pb^{-1}; |y| < 2.4");
      lyL->SetTextSize(0.029);
      lyL->DrawLatex(1.2,0.000000002,"Raw Yields");
      lyL->Draw();
    }


    if (plotUncorrected && plotRAA){
      // Uncorrected ratio of Rapidity-binned Cross-Sections
   
      TCanvas *cRaarapu = new TCanvas("cRaarapu","cRaarapu"); 
      cRaarapu->cd();
      TPad *prap2 = new TPad("prap2","prap2",0.0,0.0,1.0,1.0);
      prap2->SetBottomMargin(0.12);
      prap2->SetTopMargin(0.03);
      prap2->SetRightMargin(0.03);
      prap2->SetLeftMargin(0.16);
      prap2->Draw();
      prap2->cd();
      //one pad to draw RaaRap!
      TF1 *f4RaaRap = new TF1("f4RaaRap","1",0,2.45);
      f4RaaRap->SetLineWidth(0);
      f4RaaRap->GetXaxis()->SetTitle("|y| ");
      f4RaaRap->GetYaxis()->SetTitle("uncorrected R_{AA}");
      f4RaaRap->GetYaxis()->SetTitleOffset(1.8);
      f4RaaRap->GetYaxis()->SetTitleSize(0.028);
      f4RaaRap->GetYaxis()->SetRangeUser(0.,1);
      f4RaaRap->GetXaxis()->CenterTitle(kTRUE);
      f4RaaRap->Draw();
      TGraphErrors *gRaaRap1 = new TGraphErrors(nRapBins_2014,rap2014,uncorrRAA_1S_rap2014,rap2014e,uncorrRAA_1S_rap2014e);
      gRaaRap1->SetMarkerColor(8);
      gRaaRap1->SetMarkerStyle(33);
      gRaaRap1->SetMarkerSize(2);
      TGraphErrors *gRaaRap1circle = new TGraphErrors(nRapBins_2014,rap2014,uncorrRAA_1S_rap2014,rap2014e,uncorrRAA_1S_rap2014e);
      gRaaRap1circle->SetMarkerStyle(27);
      gRaaRap1circle->SetMarkerSize(2);
      gRaaRap1circle->SetLineColor(kBlack);
      gRaaRap1->Draw("pe");
      gRaaRap1circle->Draw("p");
      f4RaaRap->Draw("same");
      TLatex *l1CMSrap = new TLatex(1,0.8, "CMS Internal PbPb #sqrt{s_{NN}} = 2.76 TeV");
      l1CMSrap->SetTextFont(42);
      l1CMSrap->SetTextSize(0.032);
      l1CMSrap->Draw();
      TLatex *lyLRAP= new TLatex(1,0.6,"L_{int}^{PbPb} = 166 #mub^{-1}; L_{int}^{pp} = 5.4 pb^{-1};");
      lyLRAP->SetTextSize(0.032);
      lyLRAP->Draw();
      lyLRAP->SetTextSize(0.04);
      lyLRAP->DrawLatex(0.7,0.15,"Uncorrected");
      prap2->Update();
   
      gPad->RedrawAxis();
    }


  }





void plotDoubleRatios()
{
  float pt2014 [nPtBins_2014] = {1.25, 3.75, 6.5, 10., 16.,30};
  float pt2014e[nPtBins_2014] = {1.25, 1.25, 1.5, 2., 4.,10.};
  float doubleRatio3S1S[nPtBins_2014];
  float doubleRatio3S1Se[nPtBins_2014];
  float doubleRatio2S1S[nPtBins_2014];
  float doubleRatio2S1Se[nPtBins_2014];
  float ppSingleRatio3S1S[nPtBins_2014];
  float ppSingleRatio3S1Se[nPtBins_2014];
  float ppSingleRatio2S1S[nPtBins_2014];
  float ppSingleRatio2S1Se[nPtBins_2014];
  float paSingleRatio3S1S[nPtBins_2014];
  float paSingleRatio3S1Se[nPtBins_2014];
  float paSingleRatio2S1S[nPtBins_2014];
  float paSingleRatio2S1Se[nPtBins_2014];
    
  for(int i=0 ; i<nPtBins_2014 ; i++){
    ppSingleRatio2S1S[i]=computeRatio(N2S_pp_m146p239pt3p5[i],N1S_pp_m146p239pt3p5[i]);
    paSingleRatio2S1S[i]=computeRatio(N2S_pa_pt3p5[i],N1S_pa_pt3p5[i]);
    ppSingleRatio3S1S[i]=computeRatio(N3S_pp_m146p239pt3p5[i],N1S_pp_m146p239pt3p5[i]);
    paSingleRatio3S1S[i]=computeRatio(N3S_pa_pt3p5[i],N1S_pa_pt3p5[i]);
   
    ppSingleRatio2S1Se[i]=    computeRatioError(N2S_pp_m146p239pt3p5[i],N1S_pp_m146p239pt3p5[i],N2S_pp_m146p239pt3p5e[i],N1S_pp_m146p239pt3p5e[i]);
    paSingleRatio2S1Se[i]=    computeRatioError(N2S_pa_pt3p5[i],N1S_pa_pt3p5[i],N2S_pa_pt3p5e[i],N1S_pa_pt3p5e[i]);
    ppSingleRatio3S1Se[i]=    computeRatioError(N3S_pp_m146p239pt3p5[i],N1S_pp_m146p239pt3p5[i],N3S_pp_m146p239pt3p5e[i],N1S_pp_m146p239pt3p5e[i]);
    paSingleRatio3S1Se[i]=    computeRatioError(N3S_pa_pt3p5[i],N1S_pa_pt3p5[i],N3S_pa_pt3p5e[i],N1S_pa_pt3p5e[i]);
 
    doubleRatio2S1S[i]= computeRatio(paSingleRatio2S1S[i],ppSingleRatio2S1S[i]);
    doubleRatio3S1S[i]= computeRatio(paSingleRatio3S1S[i],ppSingleRatio3S1S[i]);
    doubleRatio2S1Se[i]= computeRatioError(paSingleRatio2S1S[i],ppSingleRatio2S1S[i],paSingleRatio2S1Se[i],ppSingleRatio2S1Se[i]);
    doubleRatio3S1Se[i]= computeRatioError(paSingleRatio3S1S[i],ppSingleRatio3S1S[i],paSingleRatio3S1Se[i],ppSingleRatio3S1Se[i]);

    cout <<"pA/pp 2s/1s = "<< doubleRatio2S1S[i] <<" \\pm "<< doubleRatio2S1Se[i]<< endl;
    cout <<"pA/pp 3s/1s = "<< doubleRatio3S1S[i] <<" \\pm   "<< doubleRatio3S1Se[i]<< endl;
  }
  TCanvas *cDRpt = new TCanvas("cDRpt","cDRpt"); 
  cDRpt->cd();
  // TPad *ppt2 = new TPad("ppt2","ppt2",0.0,0.0,1.0,1.0);
  // ppt2->SetBottomMargin(0.12);
  // ppt2->SetTopMargin(0.03);
  // ppt2->SetRightMargin(0.03);
  // ppt2->SetLeftMargin(0.16);
  // ppt2->Draw();
  // ppt2->cd();
  //one pad to draw RaaPt!
  TF1 *f4DRPt = new TF1("f4DRPt","1",0,40.5);
  f4DRPt->SetLineWidth(0);
  f4DRPt->GetXaxis()->SetTitle("p_{T}^{#varUpsilon} (GeV/c)");
  f4DRPt->GetYaxis()->SetTitle("DOUBLE RATIOS");
  f4DRPt->GetYaxis()->SetTitleOffset(1.8);
  f4DRPt->GetYaxis()->SetTitleSize(0.028);
  f4DRPt->GetYaxis()->SetRangeUser(0.,1.4);
  f4DRPt->GetXaxis()->CenterTitle(kTRUE);
  f4DRPt->Draw();
  TGraphErrors *gDRPt2 = new TGraphErrors(nPtBins_2014,pt2014,doubleRatio2S1S,pt2014e,doubleRatio2S1Se);
  gDRPt2->SetMarkerColor(kBlue+7);
  gDRPt2->SetMarkerStyle(33);
  gDRPt2->SetMarkerSize(2);
  TGraphErrors *gDRPt2circle = new TGraphErrors(nPtBins_2014,pt2014,doubleRatio2S1S,pt2014e,doubleRatio2S1Se);
  gDRPt2circle->SetMarkerStyle(27);
  gDRPt2circle->SetMarkerSize(2);
  gDRPt2circle->SetLineColor(kBlack);
  gDRPt2->Draw("pe");
  gDRPt2circle->Draw("p");
  f4DRPt->Draw("same");
  TGraphErrors *gDRPt3 = new TGraphErrors(nPtBins_2014,pt2014,doubleRatio3S1S,pt2014e,doubleRatio3S1Se);
  gDRPt3->SetMarkerColor(kBlue+2);
  gDRPt3->SetMarkerStyle(33);
  gDRPt3->SetMarkerSize(2);
  TGraphErrors *gDRPt3circle = new TGraphErrors(nPtBins_2014,pt2014,doubleRatio3S1S,pt2014e,doubleRatio3S1Se);
  gDRPt3circle->SetMarkerStyle(27);
  gDRPt3circle->SetMarkerSize(2);
  gDRPt3circle->SetLineColor(kBlack);
  gDRPt3->Draw("pe");
  gDRPt3circle->Draw("p");
  f4DRPt->Draw("same");
  TLatex *l1CMSpt = new TLatex(2,1.32, "CMS - Work in progress");
  l1CMSpt->SetTextFont(42);
  l1CMSpt->SetTextSize(0.032);
  l1CMSpt->Draw();
  l1CMSpt->DrawLatex(2,1.25,"#sqrt{s} = 2.76 TeV, #sqrt{s_{NN}} = 5.02 TeV");
  l1CMSpt->DrawLatex(2,1.18,"-1.47 < |y_{C.M.}| < 2.4");
  TLatex *lyLPT= new TLatex(2,1.1,"2013 L_{int}^{pPb} = 18.4 nb^{-1}, 2013 L_{int}^{pp} = 5.4 pb^{-1}"); // 
  lyLPT->SetTextFont(42);
  lyLPT->SetTextSize(0.027);
  lyLPT->Draw();
  gPad->RedrawAxis();

  TLegend *legend = new TLegend(0.6,0.21,0.8,0.4);
  legend->SetTextSize(0.029);
  legend->SetFillStyle(0);
  legend->SetFillColor(0);
  legend->SetBorderSize(0);
  legend->SetTextFont(42);
  legend->AddEntry(gDRPt2,"#varUpsilon(2S)/#varUpsilon(1S) pPb/pp","lp");
  legend->AddEntry(gDRPt3,"#varUpsilon(3S)/#varUpsilon(1S) pPb/pp","lp");
  legend->Draw();

 gPad->RedrawAxis();
 cDRpt->SaveAs("~/Project/ups2013/code/pdfOutput/DoubleRatiosPA.pdf");
 /////////////// pPb vs,RATIOS
 
 TCanvas *cSRpt = new TCanvas("cSRpt","cSRpt"); 
 cSRpt->cd();
 // TPad *ppt2 = new TPad("ppt2","ppt2",0.0,0.0,1.0,1.0);
 // ppt2->SetBottomMargin(0.12);
 // ppt2->SetTopMargin(0.03);
 // ppt2->SetRightMargin(0.03);
 // ppt2->SetLeftMargin(0.16);
 // ppt2->Draw();
 // ppt2->cd();

  //one pad to draw RaaPt!
  TF1 *f4SRPt = new TF1("f4SRPt","1",0,40.5);
  f4SRPt->SetLineWidth(0);
  f4SRPt->GetXaxis()->SetTitle("p_{T}^{#varUpsilon} (GeV/c)");
  f4SRPt->GetYaxis()->SetTitle("SINGLE ratios");
  f4SRPt->GetYaxis()->SetTitleOffset(1.8);
  f4SRPt->GetYaxis()->SetTitleSize(0.028);
  f4SRPt->GetYaxis()->SetRangeUser(0.,1.);
  f4SRPt->GetXaxis()->CenterTitle(kTRUE);
  f4SRPt->Draw();
  TGraphErrors *gSRPt2pa = new TGraphErrors(nPtBins_2014,pt2014,paSingleRatio2S1S,pt2014e,paSingleRatio2S1Se);
  gSRPt2pa->SetMarkerColor(kAzure+1);
  gSRPt2pa->SetMarkerStyle(20);
  gSRPt2pa->SetMarkerSize(1.2);
  TGraphErrors *gSRPt2pacircle = new TGraphErrors(nPtBins_2014,pt2014,paSingleRatio2S1S,pt2014e,paSingleRatio2S1Se);
  gSRPt2pacircle->SetMarkerStyle(24);
  gSRPt2pacircle->SetMarkerSize(1.2);
  gSRPt2pacircle->SetLineColor(kBlack);
  gSRPt2pa->Draw("pe");
  gSRPt2pacircle->Draw("p");
  f4SRPt->Draw("same");
  TGraphErrors *gSRPt3pa = new TGraphErrors(nPtBins_2014,pt2014,paSingleRatio3S1S,pt2014e,paSingleRatio3S1Se);
  gSRPt3pa->SetMarkerColor(kGreen);
  gSRPt3pa->SetMarkerStyle(21);
  gSRPt3pa->SetMarkerSize(1.2);
  TGraphErrors *gSRPt3pacircle = new TGraphErrors(nPtBins_2014,pt2014,paSingleRatio3S1S,pt2014e,paSingleRatio3S1Se);
  gSRPt3pacircle->SetMarkerStyle(25);
  gSRPt3pacircle->SetMarkerSize(1.2);
  gSRPt3pacircle->SetLineColor(kBlack);
  gSRPt3pa->Draw("pe");
  gSRPt3pacircle->Draw("p");
  f4SRPt->Draw("same");


  TGraphErrors *gSRPt2pp = new TGraphErrors(nPtBins_2014,pt2014,ppSingleRatio2S1S,pt2014e,ppSingleRatio2S1Se);
  gSRPt2pp->SetMarkerColor(kViolet);
  gSRPt2pp->SetMarkerStyle(20);
  gSRPt2pp->SetMarkerSize(1.2);
  TGraphErrors *gSRPt2ppcircle = new TGraphErrors(nPtBins_2014,pt2014,ppSingleRatio2S1S,pt2014e,ppSingleRatio2S1Se);
  gSRPt2ppcircle->SetMarkerStyle(24);
  gSRPt2ppcircle->SetMarkerSize(1.2);
  gSRPt2ppcircle->SetLineColor(kBlack);
  gSRPt2pp->Draw("pe");
  gSRPt2ppcircle->Draw("p");
  f4SRPt->Draw("same");
  TGraphErrors *gSRPt3pp = new TGraphErrors(nPtBins_2014,pt2014,ppSingleRatio3S1S,pt2014e,ppSingleRatio3S1Se);
  gSRPt3pp->SetMarkerColor(kOrange+1);
  gSRPt3pp->SetMarkerStyle(21);
  gSRPt3pp->SetMarkerSize(1.2);
  TGraphErrors *gSRPt3ppcircle = new TGraphErrors(nPtBins_2014,pt2014,ppSingleRatio3S1S,pt2014e,ppSingleRatio3S1Se);
  gSRPt3ppcircle->SetMarkerStyle(25);
  gSRPt3ppcircle->SetMarkerSize(1.2);
  gSRPt3ppcircle->SetLineColor(kBlack);
  gSRPt3pp->Draw("pe");
  gSRPt3ppcircle->Draw("p");
  f4SRPt->Draw("same");
  TLatex *l1CMSpt = new TLatex(2,0.92, "CMS - Work in progress");
  l1CMSpt->SetTextFont(42);
  l1CMSpt->SetTextSize(0.032);
  l1CMSpt->Draw();
  l1CMSpt->DrawLatex(2,0.87,"#sqrt{s} = 2.76 TeV, #sqrt{s_{NN}} = 5.02 TeV");
  l1CMSpt->DrawLatex(2,0.81,"-1.47 < |y_{C.M.}| < 2.4");
  TLatex *lyLPT= new TLatex(2,0.75,"2013 L_{int}^{pPb} = 18.4 nb^{-1}, 2013 L_{int}^{pp} = 5.4 pb^{-1}"); // 
  lyLPT->SetTextFont(42);
  lyLPT->SetTextSize(0.027);
  lyLPT->Draw();
  gPad->RedrawAxis();

  TLegend *legend = new TLegend(0.2,0.5,0.5,0.7);
  legend->SetTextSize(0.029);
  legend->SetFillStyle(0);
  legend->SetFillColor(0);
  legend->SetBorderSize(0);
  legend->SetTextFont(42);
  legend->AddEntry(gSRPt2pp,"#varUpsilon(2S)/#varUpsilon(1S) pp","lp");
  legend->AddEntry(gSRPt2pa,"#varUpsilon(2S)/#varUpsilon(1S) pPb ","lp");
  legend->AddEntry(gSRPt3pp,"#varUpsilon(3S)/#varUpsilon(1S) pp","lp");
  legend->AddEntry(gSRPt3pa,"#varUpsilon(3S)/#varUpsilon(1S) pPb","lp");
  legend->Draw();

 gPad->RedrawAxis();
cSRpt->SaveAs("~/Project/ups2013/code/pdfOutput/SingleRatiosPPandPA.pdf");
}

void combine_blue(double val1, double err1, double val2, double err2)
{
   double w1 = err2*err2/(err1*err1+err2*err2);
   double w2 = err1*err1/(err1*err1+err2*err2);

   cout << w1*val1+w2*val2 << "\\pm" << err1*err2/sqrt(err1*err1+err2*err2) << endl;
}



