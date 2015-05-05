#include <iostream>     // std::cout
#include <algorithm>    // std::max
using namespace std;
int plotSimpleDistributions(){

  TFile *_file0 = TFile::Open("../dimuonTree_upsiMiniTree_AA2p76tev_ptmuSpecial_nov25_2013_trigBit1_allTriggers1_testNoCut.root");
  gROOT->Macro("cm/logon.C+");
  int rapidityBinStart=0; 
  int rapidityBinStop=2; 
  int ptCutStart =1;
  int ptCutStop  =3;
  float pta_init[4] = {0,3.5,4,4.5};
  float ptb_init[4] = {0,3.5,4,4.5};
  float rapa_init[4]={0,0.8,1.6,2.4};
  float rapb_init[4]={0,0.8,1.6,2.4};
  float pta,ptb;
  float rapa,rapb;
  bool option=false;
 
  TCut cut_0p8("abs(upsRapidity)<0.8");
  TCut cut_1p6("abs(upsRapidity)>0.8 && abs(upsRapidity)<1.6 ");
  TCut cut_2p4("abs(upsRapidity)>1.6");
  //linear pt cuts
  TCut cut3p53p5("(muPlusPt>3.5 && muMinusPt>3.5)");
  TCut cut44("(muPlusPt>4 && muMinusPt>4)");
  TCut cut4p54p5("(muPlusPt>4.5 && muMinusPt>4.5)");
  //asymmetric pt cuts
  TCut cut3p54("((muPlusPt>3.5 && muMinusPt>4)||(muPlusPt>4 && muMinusPt>3.5))");
  TCut cut34("((muPlusPt>3 && muMinusPt>4)||(muPlusPt>4 && muMinusPt>3))"); // can work out of barrel only.
  TCut cut3p54p5("((muPlusPt>3.5 && muMinusPt>4.5)||(muPlusPt>4.5 && muMinusPt>3.5))");
  TCut cut44p5("((muPlusPt>4 && muMinusPt>4.5)||(muPlusPt>4.5 && muMinusPt>4))");
  TCut cutFuture("(muPlusPt>4 && ((muMinusPt>3.5 && abs(muMinusEta)>1.2) || (muMinusPt>4.5 && abs(muMinusEta)<1.2))) || (muMinusPt>4 && ((muPlusPt>3.5 && abs(muPlusEta)>1.2) || (muPlusPt>4.5 && abs(muPlusEta)<1.2))) ");


  TCanvas *c1 = new TCanvas("c1_name","c1_title",800,800);
  c1->cd();
  UpsilonTree->Draw("invariantMass>>e34(70,7,14)",cut_2p4+cut34,"");
  e34->SetFillColor(kViolet);  
  float N_BLS_34_e= e34->Integral(0,22); //Nb of Bkg in Left Sideband, with a pt cut of 3p5 and 3p5, in the |y_ups| > 1.6 "endcap" region. 
  float N_BRS_34_e= e34->Integral(28,70); //Nb of Bkg in Left Sideband, with a pt cut of 3p5 and 3p5, in the |y_ups| > 1.6 "endcap" region. 
  UpsilonTree->Draw("invariantMass>>e3p53p5(70,7,14)",cut_2p4+cut3p53p5,"same");
  e3p53p5->SetFillColor(kOrange);  
  float N_BLS_3p53p5_e= e3p53p5->Integral(0,22); //Nb of Bkg in Left Sideband, with a pt cut of 3p5 and 3p5, in the |y_ups| > 1.6 "endcap" region. 
  float N_BRS_3p53p5_e= e3p53p5->Integral(28,70); //Nb of Bkg in Left Sideband, with a pt cut of 3p5 and 3p5, in the |y_ups| > 1.6 "endcap" region. 
  UpsilonTree->Draw("invariantMass>>e3p54(70,7,14)",cut_2p4+cut3p54,"same");
  e3p54->SetFillColor(kBlue);    
  float N_BLS_3p54_e= e3p54->Integral(0,22);
  float N_BRS_3p54_e= e3p54->Integral(28,70);
  UpsilonTree->Draw("invariantMass>>e3p54p5(70,7,14)",cut_2p4+cut3p54p5,"same");
  e3p54p5->SetFillColor(kGreen+1);     
  float N_BLS_3p54p5_e= e3p54p5->Integral(0,22);
  float N_BRS_3p54p5_e= e3p54p5->Integral(28,70);
  UpsilonTree->Draw("invariantMass>>e44(70,7,14)",cut_2p4+cut44,"same");
  e44->SetFillColor(kRed);  
  float N_BLS_44_e= e44->Integral(0,22);
  float N_BRS_44_e= e44->Integral(28,70);

  // UpsilonTree->Draw("invariantMass>>eFuture(70,7,14)",cut_2p4+cutFuture,"same");
  // eFuture->SetFillColor(kTeal-2); 

  cout <<" pt4 pt4 " << N_BLS_44_e << ", " << N_BRS_44_e << endl; 
  cout <<" pt3 pt4 " << N_BLS_34_e << ", " << N_BRS_34_e << endl; 
  // computing added values:
  float avl_3p53p5_e = 100*(N_BLS_3p53p5_e-N_BLS_44_e)/N_BLS_44_e;
  float avl_34_e = 100*(N_BLS_34_e-N_BLS_44_e)/N_BLS_44_e;
  float avl_3p54_e = 100*(N_BLS_3p54_e-N_BLS_44_e)/N_BLS_44_e;
  float avl_3p54p5_e = 100*(N_BLS_3p54p5_e-N_BLS_44_e)/N_BLS_44_e;

  float avr_3p53p5_e = 100*(N_BRS_3p53p5_e-N_BRS_44_e)/N_BRS_44_e;
  float avr_34_e = 100*(N_BRS_34_e-N_BRS_44_e)/N_BRS_44_e;
  float avr_3p54_e = 100*(N_BRS_3p54_e-N_BRS_44_e)/N_BRS_44_e;
  float avr_3p54p5_e = 100*(N_BRS_3p54p5_e-N_BRS_44_e)/N_BRS_44_e;

  cout <<" Added Values at |y| > 1.6: " << endl;
  std::cout<<setprecision(3)<<endl;
  cout <<" 3 + 4 -     " << avl_34_e     << " % (left SB) -- and " << avr_34_e     << " % (right SB)" << endl;
  cout <<" 3.5 + 4 -   " << avl_3p54_e   << " % (left SB) -- and " << avr_3p54_e   << " % (right SB)"<< endl;
  cout <<" 3.5 + 3.5 - " << avl_3p53p5_e << " % (left SB) -- and " << avr_3p53p5_e << " % (right SB)"<< endl;
  cout <<" 3.5 + 4.5 - " << avl_3p54p5_e << " % (left SB) -- and " << avr_3p54p5_e << " % (right SB)"<< endl;
 
  e34->Draw();
  e3p53p5->Draw("same");
  e3p54->Draw("same");
  e3p54p5->Draw("same");
  e44->Draw("same");
  leg3 = new TLegend(0.5,0.6,0.93,0.93);
  leg3->SetFillStyle(0);
  leg3->SetFillColor(0);
  leg3->SetBorderSize(0);
  leg3->SetTextFont(42);
  leg3->SetTextSize(0.03);
  leg3->SetHeader("PbPb, 1.6 < |y| < 2.4");
  leg3->AddEntry(e34,"p_{T}(#mu_{1},#mu_{2}) > 3, 4 GeV/c","f");
  leg3->AddEntry(e3p53p5,"p_{T}(#mu_{1},#mu_{2}) > 3.5, 3.5 GeV/c","f");
  leg3->AddEntry(e3p54,"p_{T}(#mu_{1},#mu_{2}) > 3.5, 4 GeV/c","f");
  leg3->AddEntry(e3p54p5,"p_{T}(#mu_{1},#mu_{2}) > 3.5, 4.5 GeV/c","f");
  leg3->AddEntry(e44,"p_{T}(#mu_{1},#mu_{2}) > 4, 4 GeV/c","f");
  leg3->Draw();
  //c1->Draw();
  c1->SaveAs("~/Desktop/Grenelle/EndcapMassPlotsMoreCuts.pdf");
  TCanvas *c2 = new TCanvas("c2_name","c2_title",800,800);
  c2->cd();
  //  UpsilonTree->Draw("invariantMass>>e3p53p5(70,7,14)",cut_2p4+cut3p53p5,"");
  // e3p53p5->SetFillColor(kRed+2);  
  UpsilonTree->Draw("invariantMass>>be34(70,7,14)",cut_1p6+cut34,"");
  be34->SetFillColor(kViolet);  
  float N_BLS_34_be= be34->Integral(0,22); //Nb of Bkg in Left Sideband, with a pt cut of 3p5 and 3p5, in the |y_ups| > 1.6 "endcap" region. 
  float N_BRS_34_be= be34->Integral(28,70); //Nb of Bkg in Left Sideband, with a pt cut of 3p5 and 3p5, in the |y_ups| > 1.6 "endcap" region. 
  UpsilonTree->Draw("invariantMass>>be3p53p5(70,7,14)",cut_1p6+cut3p53p5,"same");
  be3p53p5->SetFillColor(kOrange);  
  float N_BLS_3p53p5_be= be3p53p5->Integral(0,22); //Nb of Bkg in Left Sideband, with a pt cut of 3p5 and 3p5, in the |y_ups| > 1.6 "endcap" region. 
  float N_BRS_3p53p5_be= be3p53p5->Integral(28,70); //Nb of Bkg in Left Sideband, with a pt cut of 3p5 and 3p5, in the |y_ups| > 1.6 "endcap" region. 
  UpsilonTree->Draw("invariantMass>>be3p54(70,7,14)",cut_1p6+cut3p54,"same");
  be3p54->SetFillColor(kBlue);    
  float N_BLS_3p54_be= be3p54->Integral(0,22);
  float N_BRS_3p54_be= be3p54->Integral(28,70);
  UpsilonTree->Draw("invariantMass>>be3p54p5(70,7,14)",cut_1p6+cut3p54p5,"same");
  be3p54p5->SetFillColor(kGreen+1);     
  float N_BLS_3p54p5_be= be3p54p5->Integral(0,22);
  float N_BRS_3p54p5_be= be3p54p5->Integral(28,70);
  UpsilonTree->Draw("invariantMass>>be44(70,7,14)",cut_1p6+cut44,"same");
  be44->SetFillColor(kRed);  
  float N_BLS_44_be= be44->Integral(0,22);
  float N_BRS_44_be= be44->Integral(28,70);
  //  c2->Draw();
  cout <<" pt4 pt4 " << N_BLS_44_be << ", " << N_BRS_44_be << endl; 
  cout <<" pt3 pt4 " << N_BLS_34_be << ", " << N_BRS_34_be << endl; 
  // computing added values:
  float avl_3p53p5_be = 100*(N_BLS_3p53p5_be-N_BLS_44_be)/N_BLS_44_be;
  float avl_34_be = 100*(N_BLS_34_be-N_BLS_44_be)/N_BLS_44_be;
  float avl_3p54_be = 100*(N_BLS_3p54_be-N_BLS_44_be)/N_BLS_44_be;
  float avl_3p54p5_be = 100*(N_BLS_3p54p5_be-N_BLS_44_be)/N_BLS_44_be;

  float avr_3p53p5_be = 100*(N_BRS_3p53p5_be-N_BRS_44_be)/N_BRS_44_be;
  float avr_34_be = 100*(N_BRS_34_be-N_BRS_44_be)/N_BRS_44_be;
  float avr_3p54_be = 100*(N_BRS_3p54_be-N_BRS_44_be)/N_BRS_44_be;
  float avr_3p54p5_be = 100*(N_BRS_3p54p5_be-N_BRS_44_be)/N_BRS_44_be;

  cout <<" Added Values at 0.8 < |y| < 1.6: " << endl;
  std::cout<<setprecision(3)<<endl;
  cout <<" 3 + 4 -     " << avl_34_be     << " % (left SB) -- and " << avr_34_be     << " % (right SB)" << endl;
  cout <<" 3.5 + 4 -   " << avl_3p54_be   << " % (left SB) -- and " << avr_3p54_be   << " % (right SB)"<< endl;
  cout <<" 3.5 + 3.5 - " << avl_3p53p5_be << " % (left SB) -- and " << avr_3p53p5_be << " % (right SB)"<< endl;
  cout <<" 3.5 + 4.5 - " << avl_3p54p5_be << " % (left SB) -- and " << avr_3p54p5_be << " % (right SB)"<< endl;
 
  be34->Draw();
  be3p53p5->Draw("same");
  be3p54->Draw("same");
  be3p54p5->Draw("same");
  be44->Draw("same");
  leg3 = new TLegend(0.5,0.6,0.93,0.93);
  leg3->SetFillStyle(0);
  leg3->SetFillColor(0);
  leg3->SetBorderSize(0);
  leg3->SetTextFont(42);
  leg3->SetTextSize(0.03);
  leg3->SetHeader("PbPb, 0.8 < |y| < 1.6");
  leg3->AddEntry(be34,"p_{T}(#mu_{1},#mu_{2}) > 3, 4 GeV/c","f");
  leg3->AddEntry(be3p53p5,"p_{T}(#mu_{1},#mu_{2}) > 3.5, 3.5 GeV/c","f");
  leg3->AddEntry(be3p54,"p_{T}(#mu_{1},#mu_{2}) > 3.5, 4 GeV/c","f");
  leg3->AddEntry(be3p54p5,"p_{T}(#mu_{1},#mu_{2}) > 3.5, 4.5 GeV/c","f");
  leg3->AddEntry(be44,"p_{T}(#mu_{1},#mu_{2}) > 4, 4 GeV/c","f");
  leg3->Draw();
  c2->SaveAs("~/Desktop/Grenelle/intermediateRapidityMassPlotsMoreCuts.pdf");


  TCanvas *c3 = new TCanvas("c3_name","c3_title",800,800);
  c3->cd();

  UpsilonTree->Draw("invariantMass>>b34(70,7,14)",cut_0p8+cut34,"");
  b34->SetFillColor(kViolet);  
  float N_BLS_34_b= b34->Integral(0,22); //Nb of Bkg in Left Sideband, with a pt cut of 3p5 and 3p5, in the |y_ups| > 1.6 "endcap" region. 
  float N_BRS_34_b= b34->Integral(28,70); //Nb of Bkg in Left Sideband, with a pt cut of 3p5 and 3p5, in the |y_ups| > 1.6 "endcap" region. 
  UpsilonTree->Draw("invariantMass>>b3p53p5(70,7,14)",cut_0p8+cut3p53p5,"same");
  b3p53p5->SetFillColor(kOrange);  
  float N_BLS_3p53p5_b= b3p53p5->Integral(0,22); //Nb of Bkg in Left Sideband, with a pt cut of 3p5 and 3p5, in the |y_ups| > 1.6 "endcap" region. 
  float N_BRS_3p53p5_b= b3p53p5->Integral(28,70); //Nb of Bkg in Left Sideband, with a pt cut of 3p5 and 3p5, in the |y_ups| > 1.6 "endcap" region. 
  UpsilonTree->Draw("invariantMass>>b3p54(70,7,14)",cut_0p8+cut3p54,"same");
  b3p54->SetFillColor(kBlue);    
  float N_BLS_3p54_b= b3p54->Integral(0,22);
  float N_BRS_3p54_b= b3p54->Integral(28,70);
  UpsilonTree->Draw("invariantMass>>b3p54p5(70,7,14)",cut_0p8+cut3p54p5,"same");
  b3p54p5->SetFillColor(kGreen+1);     
  float N_BLS_3p54p5_b= b3p54p5->Integral(0,22);
  float N_BRS_3p54p5_b= b3p54p5->Integral(28,70);
  UpsilonTree->Draw("invariantMass>>b44(70,7,14)",cut_0p8+cut44,"same");
  b44->SetFillColor(kRed);  
  float N_BLS_44_b= b44->Integral(0,22);
  float N_BRS_44_b= b44->Integral(28,70);
  c3->Draw();
  cout <<" pt4 pt4 " << N_BLS_44_b << ", " << N_BRS_44_b << endl; 
  cout <<" pt3 pt4 " << N_BLS_34_b << ", " << N_BRS_34_b << endl; 
  // computing added values:
  float avl_3p53p5_b = 100*(N_BLS_3p53p5_b-N_BLS_44_b)/N_BLS_44_b;
  float avl_34_b = 100*(N_BLS_34_b-N_BLS_44_b)/N_BLS_44_b;
  float avl_3p54_b = 100*(N_BLS_3p54_b-N_BLS_44_b)/N_BLS_44_b;
  float avl_3p54p5_b = 100*(N_BLS_3p54p5_b-N_BLS_44_b)/N_BLS_44_b;

  float avr_3p53p5_b = 100*(N_BRS_3p53p5_b-N_BRS_44_b)/N_BRS_44_b;
  float avr_34_b = 100*(N_BRS_34_b-N_BRS_44_b)/N_BRS_44_b;
  float avr_3p54_b = 100*(N_BRS_3p54_b-N_BRS_44_b)/N_BRS_44_b;
  float avr_3p54p5_b = 100*(N_BRS_3p54p5_b-N_BRS_44_b)/N_BRS_44_b;

  cout <<" Added Values at |y| < 0.8: " << endl;
  std::cout<<setprecision(3)<<endl;
  cout <<" 3 + 4 -     " << avl_34_b     << " % (left SB) -- and " << avr_34_b     << " % (right SB)" << endl;
  cout <<" 3.5 + 4 -   " << avl_3p54_b   << " % (left SB) -- and " << avr_3p54_b   << " % (right SB)"<< endl;
  cout <<" 3.5 + 3.5 - " << avl_3p53p5_b << " % (left SB) -- and " << avr_3p53p5_b << " % (right SB)"<< endl;
  cout <<" 3.5 + 4.5 - " << avl_3p54p5_b << " % (left SB) -- and " << avr_3p54p5_b << " % (right SB)"<< endl;
 
  b34->Draw();
  b3p53p5->Draw("same");
  b3p54->Draw("same");
  b3p54p5->Draw("same");
  b44->Draw("same");
  leg3 = new TLegend(0.5,0.6,0.93,0.93);
  leg3->SetFillStyle(0);
  leg3->SetFillColor(0);
  leg3->SetBorderSize(0);
  leg3->SetTextFont(42);
  leg3->SetTextSize(0.03);
  leg3->SetHeader("PbPb,  |y| < 0.8");
  leg3->AddEntry(b34,"p_{T}(#mu_{1},#mu_{2}) > 3, 4 GeV/c","f");
  leg3->AddEntry(b3p53p5,"p_{T}(#mu_{1},#mu_{2}) > 3.5, 3.5 GeV/c","f");
  leg3->AddEntry(b3p54,"p_{T}(#mu_{1},#mu_{2}) > 3.5, 4 GeV/c","f");
  leg3->AddEntry(b3p54p5,"p_{T}(#mu_{1},#mu_{2}) > 3.5, 4.5 GeV/c","f");
  leg3->AddEntry(b44,"p_{T}(#mu_{1},#mu_{2}) > 4, 4 GeV/c","f");
  leg3->Draw();
  c3->SaveAs("~/Desktop/Grenelle/BarrelMassPlotsMoreBins.pdf");

  TFile *_file1 = TFile::Open("../upsiMiniTree_pyquen1S_noMuonPtCuts_QQtrigbit1_Trig_analysisOK_20140729_cuts10-006.root");//upsiMiniTree_Pyquen1S_QQtrigbit1_Trig_Unfolding_postCut_deltaRmatched_withCentrality.root");
  TCut cutMC_0p8("abs(upsRapidity)<0.8");
  TCut cutMC_1p6("abs(upsRapidity)>0.8 && abs(upsRapidity)<1.6 ");
  TCut cutMC_2p4("abs(upsRapidity)>1.6");
  //linear pt cuts
  TCut cutMC3p53p5("(muPlusPt>3.5 && muMinusPt>3.5)");
  TCut cutMC44("(muPlusPt>4 && muMinusPt>4)");
  TCut cutMC4p54p5("(muPlusPt>4.5 && muMinusPt>4.5)");
  //asymmetric pt cuts
  TCut cutMC3p54("((muPlusPt>3.5 && muMinusPt>4)||(muPlusPt>4 && muMinusPt>3.5))");
  TCut cutMC34("((muPlusPt>3 && muMinusPt>4)||(muPlusPt>4 && muMinusPt>3))"); // can work out of barrel only.
  TCut cutMC3p54p5("((muPlusPt>3.5 && muMinusPt>4.5)||(muPlusPt>4.5 && muMinusPt>3.5))");
  TCut cutMC44p5("((muPlusPt>4 && muMinusPt>4.5)||(muPlusPt>4.5 && muMinusPt>4))");
  TCut cutMCFuture("(muPlusPt>4 && ((muMinusPt>3.5 && abs(muMinusEta)>1.2) || (muMinusPt>4.5 && abs(muMinusEta)<1.2))) || (muMinusPt>4 && ((muPlusPt>3.5 && abs(muPlusEta)>1.2) || (muPlusPt>4.5 && abs(muPlusEta)<1.2))) ");

  TCanvas *cMC1 = new TCanvas("cMC1_name","cMC1_title",800,800);
  cMC1->cd();
  UpsilonTree->Draw("invariantMass>>kk(70,7,14)",cutMC44,"");
  //  b34->SetFillColor(kViolet);  
  float k = (3485)/kk->Integral(22,27); 
  cout << "K = "<< k << endl; 
  UpsilonTree->Draw("invariantMass>>eMC34(70,7,14)",cutMC_2p4+cutMC34,"");
  eMC34->SetFillColor(kViolet);  
  float N_SIG_34_e= eMC34->Integral(22,27); //Nb of Bkg in Left Sideband, with a pt cut of 3p5 and 3p5, in the |y_ups| > 1.6 "endcap" region. 
 
  UpsilonTree->Draw("invariantMass>>eMC3p53p5(70,7,14)",cutMC_2p4+cutMC3p53p5,"same");
  eMC3p53p5->SetFillColor(kOrange);  
  float N_SIG_3p53p5_e= eMC3p53p5->Integral(22,27); //Nb of Bkg in Left Sideband, with a pt cut of 3p5 and 3p5, in the |y_ups| > 1.6 "endcap" region. 
 
  UpsilonTree->Draw("invariantMass>>eMC3p54(70,7,14)",cutMC_2p4+cutMC3p54,"same");
  eMC3p54->SetFillColor(kBlue);    
  float N_SIG_3p54_e= eMC3p54->Integral(22,27);
 
  UpsilonTree->Draw("invariantMass>>eMC3p54p5(70,7,14)",cutMC_2p4+cutMC3p54p5,"same");
  eMC3p54p5->SetFillColor(kGreen+1);     
  float N_SIG_3p54p5_e= eMC3p54p5->Integral(22,27);
 
  UpsilonTree->Draw("invariantMass>>eMC44(70,7,14)",cutMC_2p4+cutMC44,"same");
  eMC44->SetFillColor(kRed);  
  float N_SIG_44_e= eMC44->Integral(22,27);

  cout <<" pt4 pt4 " << N_SIG_44_e << ", " << N_SIG_34_e << endl; 
  // cMC1->GetPad(0)->SetLogy();
  // computing added values:
  float avs_3p53p5_e = 100*(N_SIG_3p53p5_e-N_SIG_44_e)/N_SIG_44_e;
  float avs_34_e = 100*(N_SIG_34_e-N_SIG_44_e)/N_SIG_44_e;
  float avs_3p54_e = 100*(N_SIG_3p54_e-N_SIG_44_e)/N_SIG_44_e;
  float avs_3p54p5_e = 100*(N_SIG_3p54p5_e-N_SIG_44_e)/N_SIG_44_e;

  cout <<" Added Values for Signal at |y| > 1.6: " << endl;
  std::cout<<setprecision(3)<<endl;
  cout <<" 3 + 4 -     " << avs_34_e     << endl;
  cout <<" 3.5 + 4 -   " << avs_3p54_e   << endl;
  cout <<" 3.5 + 3.5 - " << avs_3p53p5_e << endl;
  cout <<" 3.5 + 4.5 - " << avs_3p54p5_e << endl;
 
  eMC34->Draw();
  eMC3p53p5->Draw("same");
  eMC3p54->Draw("same");
  eMC3p54p5->Draw("same");
  eMC44->Draw("same");


  legMC1 = new TLegend(0.5,0.6,0.93,0.93);
  legMC1->SetFillStyle(0);
  legMC1->SetFillColor(0);
  legMC1->SetBorderSize(0);
  legMC1->SetTextFont(42);
  legMC1->SetTextSize(0.03);
  legMC1->SetHeader("MC, 1.6 < |y| < 2.4");
  legMC1->AddEntry(eMC34,"p_{T}(#mu_{1},#mu_{2}) > 3, 4 GeV/c","f");
  legMC1->AddEntry(eMC3p53p5,"p_{T}(#mu_{1},#mu_{2}) > 3.5, 3.5 GeV/c","f");
  legMC1->AddEntry(eMC3p54,"p_{T}(#mu_{1},#mu_{2}) > 3.5, 4 GeV/c","f");
  legMC1->AddEntry(eMC3p54p5,"p_{T}(#mu_{1},#mu_{2}) > 3.5, 4.5 GeV/c","f");
  legMC1->AddEntry(eMC44,"p_{T}(#mu_{1},#mu_{2}) > 4, 4 GeV/c","f");
  legMC1->Draw();


  TCanvas *cMC2 = new TCanvas("cMC2_name","cMC2_title",800,800);
  cMC2->cd();

  UpsilonTree->Draw("invariantMass>>beMC34(70,7,14)",cutMC_1p6+cutMC34,"");
  beMC34->SetFillColor(kViolet);  
  float N_SIG_34_be= beMC34->Integral(22,27); //Nb of Bkg in Left Sideband, with a pt cut of 3p5 and 3p5, in the |y_ups| > 1.6 "endcap" region. 
 
  UpsilonTree->Draw("invariantMass>>beMC3p53p5(70,7,14)",cutMC_1p6+cutMC3p53p5,"same");
  beMC3p53p5->SetFillColor(kOrange);  
  float N_SIG_3p53p5_be= beMC3p53p5->Integral(22,27); //Nb of Bkg in Left Sideband, with a pt cut of 3p5 and 3p5, in the |y_ups| > 1.6 "endcap" region. 
 
  UpsilonTree->Draw("invariantMass>>beMC3p54(70,7,14)",cutMC_1p6+cutMC3p54,"same");
  beMC3p54->SetFillColor(kBlue);    
  float N_SIG_3p54_be= beMC3p54->Integral(22,27);
 
  UpsilonTree->Draw("invariantMass>>beMC3p54p5(70,7,14)",cutMC_1p6+cutMC3p54p5,"same");
  beMC3p54p5->SetFillColor(kGreen+1);     
  float N_SIG_3p54p5_be= beMC3p54p5->Integral(22,27);
 
  UpsilonTree->Draw("invariantMass>>beMC44(70,7,14)",cutMC_1p6+cutMC44,"same");
  beMC44->SetFillColor(kRed);   
 float N_SIG_44_be= beMC44->Integral(22,27);

  cout <<" pt4 pt4 " << N_SIG_44_be << ", " << N_SIG_34_be << endl; 
  // cMC1->GetPad(0)->SetLogy();
  // computing added values:
  float avs_3p53p5_be = 100*(N_SIG_3p53p5_be-N_SIG_44_be)/N_SIG_44_be;
  float avs_34_be = 100*(N_SIG_34_be-N_SIG_44_be)/N_SIG_44_be;
  float avs_3p54_be = 100*(N_SIG_3p54_be-N_SIG_44_be)/N_SIG_44_be;
  float avs_3p54p5_be = 100*(N_SIG_3p54p5_be-N_SIG_44_be)/N_SIG_44_be;

  cout <<" Added Values for Signal at |y| > 1.6: " << endl;
  std::cout<<setprecision(3)<<endl;
  cout <<" 3 + 4 -     " << avs_34_be     << endl;
  cout <<" 3.5 + 4 -   " << avs_3p54_be   << endl;
  cout <<" 3.5 + 3.5 - " << avs_3p53p5_be << endl;
  cout <<" 3.5 + 4.5 - " << avs_3p54p5_be << endl;
 
  beMC34->Draw();
  beMC3p53p5->Draw("same");
  beMC3p54->Draw("same");
  beMC3p54p5->Draw("same");
  beMC44->Draw("same");

  legMC2 = new TLegend(0.5,0.6,0.93,0.93);
  legMC2->SetFillStyle(0);
  legMC2->SetFillColor(0);
  legMC2->SetBorderSize(0);
  legMC2->SetTextFont(42); 
  legMC2->SetTextSize(0.03);
  legMC2->SetHeader("MC, 0.8 < |y| < 1.6");
  legMC2->AddEntry(beMC34,"p_{T}(#mu_{1},#mu_{2}) > 3, 4 GeV/c","f");
  legMC2->AddEntry(beMC3p53p5,"p_{T}(#mu_{1},#mu_{2}) > 3.5, 3.5 GeV/c","f");
  legMC2->AddEntry(beMC3p54,"p_{T}(#mu_{1},#mu_{2}) > 3.5, 4 GeV/c","f");
  legMC2->AddEntry(beMC3p54p5,"p_{T}(#mu_{1},#mu_{2}) > 3.5, 4.5 GeV/c","f");
  legMC2->AddEntry(beMC44,"p_{T}(#mu_{1},#mu_{2}) > 4, 4 GeV/c","f");
  legMC2->Draw();

  TCanvas *cMC3 = new TCanvas("cMC3_name","cMC3_title",800,800);
  cMC3->cd();

  UpsilonTree->Draw("invariantMass>>b34(70,7,14)",cutMC_0p8+cutMC34,"");
  b34->SetFillColor(kViolet);  
  float N_SIG_34_b= b34->Integral(22,27); //Nb of Bkg in Left Sideband, with a pt cut of 3p5 and 3p5, in the |y_ups| > 1.6 "endcap" region. 
 
  UpsilonTree->Draw("invariantMass>>b3p53p5(70,7,14)",cutMC_0p8+cutMC3p53p5,"same");
  b3p53p5->SetFillColor(kOrange);  
  float N_SIG_3p53p5_b= b3p53p5->Integral(22,27); //Nb of Bkg in Left Sideband, with a pt cut of 3p5 and 3p5, in the |y_ups| > 1.6 "endcap" region. 
 
  UpsilonTree->Draw("invariantMass>>b3p54(70,7,14)",cutMC_0p8+cutMC3p54,"same");
  b3p54->SetFillColor(kBlue);    
  float N_SIG_3p54_b= b3p54->Integral(22,27);
 
  UpsilonTree->Draw("invariantMass>>b3p54p5(70,7,14)",cutMC_0p8+cutMC3p54p5,"same");
  b3p54p5->SetFillColor(kGreen+1);     
  float N_SIG_3p54p5_b= b3p54p5->Integral(22,27);
 
  UpsilonTree->Draw("invariantMass>>b44(70,7,14)",cutMC_0p8+cutMC44,"same");
  b44->SetFillColor(kRed);  
  float N_SIG_44_b= b44->Integral(22,27);

  cout <<" pt4 pt4 " << N_SIG_44_b << ", " << N_SIG_34_b << endl; 
  //  cMC3->GetPad(0)->SetLogy(); 
  // computing added values:
  float avs_3p53p5_b = 100*(N_SIG_3p53p5_b-N_SIG_44_b)/N_SIG_44_b;
  float avs_34_b = 100*(N_SIG_34_b-N_SIG_44_b)/N_SIG_44_b;
  float avs_3p54_b = 100*(N_SIG_3p54_b-N_SIG_44_b)/N_SIG_44_b;
  float avs_3p54p5_b = 100*(N_SIG_3p54p5_b-N_SIG_44_b)/N_SIG_44_b;

  cout <<" Added Values for Signal at |y| < 0.8: " << endl;
  std::cout<<setprecision(3)<<endl;
  cout <<" 3 + 4 -     " << avs_34_b     << endl;
  cout <<" 3.5 + 4 -   " << avs_3p54_b   << endl;
  cout <<" 3.5 + 3.5 - " << avs_3p53p5_b << endl;
  cout <<" 3.5 + 4.5 - " << avs_3p54p5_b << endl;
 
  b34->Draw();
  b3p53p5->Draw("same");
  b3p54->Draw("same");
  b3p54p5->Draw("same");
  b44->Draw("same");
  legMC3 = new TLegend(0.5,0.6,0.93,0.93);
  legMC3->SetFillStyle(0);
  legMC3->SetFillColor(0);
  legMC3->SetBorderSize(0);
  legMC3->SetTextFont(42); 
  legMC3->SetTextSize(0.03);
  legMC3->SetHeader("MC,|y| < 0.8");
  legMC3->AddEntry(b34,"p_{T}(#mu_{1},#mu_{2}) > 3, 4 GeV/c","f");
  legMC3->AddEntry(b3p53p5,"p_{T}(#mu_{1},#mu_{2}) > 3.5, 3.5 GeV/c","f");
  legMC3->AddEntry(b3p54,"p_{T}(#mu_{1},#mu_{2}) > 3.5, 4 GeV/c","f");
  legMC3->AddEntry(b3p54p5,"p_{T}(#mu_{1},#mu_{2}) > 3.5, 4.5 GeV/c","f");
  legMC3->AddEntry(b44,"p_{T}(#mu_{1},#mu_{2}) > 4, 4 GeV/c","f");
  legMC3->Draw();
  cout << " 3.5, 3.5 "  <<"& Gain in left SB, m_{\mu\mu} \in [7,9.2[ & " << " & Gain in MC Signal, m_{\mu\mu} \in [9.2,9.7] &" << "&Gain in right SB, m_{\mu\mu} \in [9.7,14] &" << endl;
  cout << "|y| < 0.8 &" << avl_3p53p5_b << " & " <<avs_3p53p5_b << " & " <<avr_3p53p5_b << " & " << endl; 
  cout << "0.8 < |y| < 1.6 &" << avl_3p53p5_be << " & " <<avs_3p53p5_be << " & " <<avr_3p53p5_be << " & " << endl; 
  cout << "1.6 < |y| < 2.4&" << avl_3p53p5_b << " & " <<avs_3p53p5_b << " & " <<avr_3p53p5_b << " & " << endl; 
  cout << " 3.5, 4 "  <<"& Gain in left SB, m_{\mu\mu} \in [7,9.2] & " << " & Gain in SB, m_{\mu\mu} \in [7,9.2] &" << "&Gain in SB, m_{\mu\mu} \in [7,9.2] &" << endl;
  cout << "|y| < 0.8 &" << avl_3p54_b << " & " <<avs_3p54_b << " & " <<avr_3p54_b << " & " << endl; 
  cout << "0.8 < |y| < 1.6 &" << avl_3p54_be << " & " <<avs_3p54_be << " & " <<avr_3p54_be << " & " << endl; 
  cout << "1.6 < |y| < 2.4&" << avl_3p54_b << " & " <<avs_3p54_b << " & " <<avr_3p54_b << " & " << endl; 
  cout << " 3.5, 4.5 "  <<"& Gain in left SB, m_{\mu\mu} \in [7,9.2] & " << " & Gain in SB, m_{\mu\mu} \in [7,9.2] &" << "&Gain in SB, m_{\mu\mu} \in [7,9.2] &" << endl;
  cout << "|y| < 0.8 &" << avl_3p54p5_b << " & " <<avs_3p54p5_b << " & " <<avr_3p54p5_b << " & " << endl; 
  cout << "0.8 < |y| < 1.6 &" << avl_3p54p5_be << " & " <<avs_3p54p5_be << " & " <<avr_3p54p5_be << " & " << endl; 
  cout << "1.6 < |y| < 2.4&" << avl_3p54p5_b << " & " <<avs_3p54p5_b << " & " <<avr_3p54p5_b << " & " << endl; 
  cout << " 3., 4, "  <<"& Gain in left SB, m_{\mu\mu} \in [7,9.2] & " << " & Gain in SB, m_{\mu\mu} \in [7,9.2] &" << "&Gain in SB, m_{\mu\mu} \in [7,9.2] &" << endl;
  cout << "|y| < 0.8 &" << avl_34_b << " & " <<avs_34_b << " & " <<avr_34_b << " & " << endl; 
  cout << "0.8 < |y| < 1.6 &" << avl_34_be << " & " <<avs_34_be << " & " <<avr_34_be << " & " << endl; 
  cout << "1.6 < |y| < 2.4&" << avl_34_b << " & " <<avs_34_b << " & " <<avr_34_b << " & " << endl; 
  //return ;

  float signif44_0p8 = computeSignificance(N_SIG_44_b,N_BLS_44_b,N_BRS_44_b);    //k*N_SIG_44_b/sqrt(N_SIG_44_b+0.5*(N_BLS_44_b+N_BRS_44_b));
  float signif44_1p6 = computeSignificance(N_SIG_44_be,N_BLS_44_be,N_BRS_44_be); //k*N_SIG_44_be/sqrt(N_SIG_44_be+0.5*(N_BLS_44_be+N_BRS_44_be));
  float signif44_2p4 = computeSignificance(N_SIG_44_e,N_BLS_44_e,N_BRS_44_e);    //k*N_SIG_44_e/sqrt(N_SIG_44_e+0.5*(N_BLS_44_e+N_BRS_44_e));

  float signif3p54_0p8   = computeSignificance(N_SIG_3p54_b,N_BLS_3p54_b,N_BRS_3p54_b); 
  float signif3p54_1p6   = computeSignificance(N_SIG_3p54_be,N_BLS_3p54_be,N_BRS_3p54_be); 
  float signif3p54_2p4   = computeSignificance(N_SIG_3p54_e,N_BLS_3p54_e,N_BRS_3p54_e); 

  float signif3p53p5_0p8 = computeSignificance(N_SIG_3p53p5_b,N_BLS_3p53p5_b,N_BRS_3p53p5_b); 
  float signif3p53p5_1p6 = computeSignificance(N_SIG_3p53p5_be,N_BLS_3p53p5_be,N_BRS_3p53p5_be); 
  float signif3p53p5_2p4 = computeSignificance(N_SIG_3p53p5_e,N_BLS_3p53p5_e,N_BRS_3p53p5_e); 

  float signif3p54p5_0p8 =  computeSignificance(N_SIG_3p54p5_b,N_BLS_3p54p5_b,N_BRS_3p54p5_b); 
  float signif3p54p5_1p6 =  computeSignificance(N_SIG_3p54p5_be,N_BLS_3p54p5_be,N_BRS_3p54p5_be); 
  float signif3p54p5_2p4 =  computeSignificance(N_SIG_3p54p5_e,N_BLS_3p54p5_e,N_BRS_3p54p5_e); 

  float signif34_0p8     =  computeSignificance(N_SIG_34_b,N_BLS_34_b,N_BRS_34_b); 
  float signif34_1p6     =  computeSignificance(N_SIG_34_be,N_BLS_34_be,N_BRS_34_be); 
  float signif34_2p4     =  computeSignificance(N_SIG_34_e,N_BLS_34_e,N_BRS_34_e); 
  // float signif3p54p5_0p8 =  computeSignificance(N_SIG_44_b,N_BLS_44_b,N_BRS_44_b); 
  // float signif3p54p5_1p6 =  computeSignificance(N_SIG_44_b,N_BLS_44_b,N_BRS_44_b); 
  // float signif3p54p5_2p4 =  computeSignificance(N_SIG_44_b,N_BLS_44_b,N_BRS_44_b); 

  // float signif3p54p5_0p8 =  computeSignificance(N_SIG_44_b,N_BLS_44_b,N_BRS_44_b); 
  // float signif3p54p5_1p6 =  computeSignificance(N_SIG_44_b,N_BLS_44_b,N_BRS_44_b); 
  // float signif3p54p5_2p4 =  computeSignificance(N_SIG_44_b,N_BLS_44_b,N_BRS_44_b); 
  cout << "significances in the 4GeV4GeV sample:"<<endl;
  cout << signif44_0p8<<"; "<<signif44_1p6<<"; "<<signif44_2p4<<endl;

  cout << "significances in the better 3p5GeV4GeV sample:"<<endl;
  cout << signif3p54_0p8<<"; "<<signif3p54_1p6<<"; "<<signif3p54_2p4<<endl;

  cout << "significances in the good 3p5GeV3p5GeV sample:"<<endl;
  cout << signif3p53p5_0p8<<"; "<<signif3p53p5_1p6<<"; "<<signif3p53p5_2p4<<endl;

  cout << "significances in the nice 3p5GeV4p5GeV sample:"<<endl;
  cout << signif3p54p5_0p8<<"; "<<signif3p54p5_1p6<<"; "<<signif3p54p5_2p4<<endl;

  cout << "significances in the fair 3GeV4GeV sample:"<<endl;
  cout << signif34_0p8<<"; "<<signif34_1p6<<"; "<<signif34_2p4<<endl;

  cout << "ratios of significance" << endl;

  float _3p53p5_0p8 = 100*(signif3p53p5_0p8-signif44_0p8)/signif44_0p8;
  float _34_0p8     = 100*(signif34_0p8-signif44_0p8)    /signif44_0p8;
  float _3p54_0p8   = 100*(signif3p54_0p8-signif44_0p8)  /signif44_0p8;
  float _3p54p5_0p8 = 100*(signif3p54p5_0p8-signif44_0p8)/signif44_0p8;

  float _3p53p5_1p6 = 100*(signif3p53p5_1p6-signif44_1p6)/signif44_1p6;
  float _34_1p6     = 100*(signif34_1p6-signif44_1p6)    /signif44_1p6;
  float _3p54_1p6   = 100*(signif3p54_1p6-signif44_1p6)  /signif44_1p6;
  float _3p54p5_1p6 = 100*(signif3p54p5_1p6-signif44_1p6)/signif44_1p6;

  float _3p53p5_2p4 = 100*(signif3p53p5_2p4-signif44_2p4)/signif44_2p4;
  float _34_2p4     = 100*(signif34_2p4-signif44_2p4)    /signif44_2p4;
  float _3p54_2p4   = 100*(signif3p54_2p4-signif44_2p4)  /signif44_2p4;
  float _3p54p5_2p4 = 100*(signif3p54p5_2p4-signif44_2p4)/signif44_2p4;

  cout << "    RAPIDITY REGION--  cut 3p5+3p5       -----  cut 3p5+4      -----  cut 3p5+4p5 " << endl;
  cout << "      |y| < 0.8 & " << _3p53p5_0p8 << " & " << _3p54_0p8 << " & " <<_3p54p5_0p8 << " & "  <<_34_0p8 << " & " << endl; 
  cout << "0.8 < |y| < 1.6 & " << _3p53p5_1p6 << " & " << _3p54_1p6 << " & " <<_3p54p5_1p6 << " & "  <<_34_1p6 << " & " << endl; 
  cout << "1.6 < |y| < 2.4 & " << _3p53p5_2p4 << " & " << _3p54_2p4 << " & " <<_3p54p5_2p4 << " & "  <<_34_2p4 << " & " << endl; 
}




void plotMoreDistributions(){
 //// third sector
  gROOT->Macro("cm/logon.C+");
  TCut OutMassUps("(invariantMass>7&&invariantMass<9.2)||(invariantMass>9.7&&invariantMass<14)");
  TCut MassUps("invariantMass>9.2 && invariantMass<9.7");
  
  
  TFile *_file0 = TFile::Open("../dimuonTree_upsiMiniTree_AA2p76tev_ptmuSpecial_nov25_2013_trigBit1_allTriggers1_testNoCut.root");
  TH1F defaultStuff("defaultStuff","initialisation stuff",70,7,14);
  UpsilonTree->Draw("invariantMass>>defaultStuff","","");
  //oh yeah!
  TCanvas *c2D = new TCanvas("c2D_name","c2D_title",900,900);
  c2D->Divide(3,3);
  c2D->cd(1);
  UpsilonTree->Draw("muPlusPt:muMinusPt>>a1(100,0,10,100,0,10)",OutMassUps,"colz");
  a1->GetXaxis()->SetTitle("p_{T}#mu^{+} [GeV/c]");
  a1->GetYaxis()->SetTitle("p_{T}#mu^{-} [GeV/c]");
  c2D->cd(2);
  UpsilonTree->Draw("muLeadingPt:muSubLeadingPt>>a2(100,0,10,100,0,10)",OutMassUps,"colz");
  a2->GetXaxis()->SetTitle("Subleading p_{T} [GeV/c]");
  a2->GetYaxis()->SetTitle("Leading p_{T} [GeV/c]");
  c2D->cd(3);
  UpsilonTree->Draw("muAsymmetryPt>>a3(100,0,1)",OutMassUps,"");
  a3->GetXaxis()->SetTitle("#frac{p^{1}_{T}-p^{2}_{T}}{p^{1}_{T}+p^{2}_{T}}");
  a3->GetYaxis()->SetTitle("#frac{p^{1}_{T}-p^{2}_{T}}{p^{1}_{T}+p^{2}_{T}}");

  TFile *_file1 = TFile::Open("../upsiMiniTree_pyquen1S_noMuonPtCuts_QQtrigbit1_Trig_analysisOK_20140729_cuts10-006.root");//upsiMiniTree_Pyquen1S_QQtrigbit1_Trig_Unfolding_postCut_deltaRmatched_withCentrality.root");

  c2D->cd(4);
  UpsilonTree->Draw("muPlusPt:muMinusPt>>a4(100,0,10,100,0,10)",MassUps,"colz");
  a4->GetXaxis()->SetTitle("p_{T}#mu^{+} [GeV/c]");
  a4->GetYaxis()->SetTitle("p_{T}#mu^{-} [GeV/c]");
  c2D->cd(5);
  UpsilonTree->Draw("muLeadingPt:muSubLeadingPt>>a5(100,0,10,100,0,10)",MassUps,"colz");
  a5->GetXaxis()->SetTitle("Subleading p_{T} [GeV/c]");
  a5->GetYaxis()->SetTitle("Leading p_{T} [GeV/c]");
  c2D->cd(6);
  UpsilonTree->Draw("muAsymmetryPt>>a6(100,0,1)",MassUps,"");
  a6->GetXaxis()->SetTitle("#frac{p^{1}_{T}-p^{2}_{T}}{p^{1}_{T}+p^{2}_{T}}");
  a6->GetYaxis()->SetTitle("#frac{p^{1}_{T}-p^{2}_{T}}{p^{1}_{T}+p^{2}_{T}}");

  c2D->cd(7);
  UpsilonTree->Draw("muPlusPt_gen:muMinusPt_gen>>a7(100,0,10,100,0,10)",MassUps,"colz");
  a7->GetXaxis()->SetTitle("Gen p_{T}#mu^{+} [GeV/c]");
  a7->GetYaxis()->SetTitle("Gen p_{T}#mu^{-} [GeV/c]");
  c2D->cd(8);
  UpsilonTree->Draw("muLeadingPt_gen:muSubLeadingPt_gen>>a8(100,0,10,100,0,10)",MassUps,"colz");
  a8->GetXaxis()->SetTitle("Gen Subleading p_{T} [GeV/c]");
  a8->GetYaxis()->SetTitle("Gen Leading p_{T} [GeV/c]");
  c2D->cd(9);
  UpsilonTree->Draw("muAsymmetryPt_gen>>a9(100,0,1)",MassUps,"");
  a9->GetXaxis()->SetTitle("Gen-level #frac{p^{1}_{T}-p^{2}_{T}}{p^{1}_{T}+p^{2}_{T}}");
  a9->GetYaxis()->SetTitle("Gen-level #frac{p^{1}_{T}-p^{2}_{T}}{p^{1}_{T}+p^{2}_{T}}");
  
  c2D->SaveAs("~/Desktop/Grenelle/2DplotsAndAsymmetry.pdf");
}

float computeSignificance(float nsig, float nbkgL, float nbkgR){
  float k = 4977./nsig;
  float sizeL = 2.2/7.;
  float sizeR = 4.3/7.;
  float signif = (k*nsig)/sqrt(k*nsig+0.5*(nbkgL*sizeL+nbkgR*sizeR));
  return signif;
}

  // for(int r=rapidityBinStart;r<rapidityBinStop;r++){
  //   switch r{
  //     case 0:
  // 	TCanvas *cb = new TCanvas("cb","cb",1200,800);
  // 	cb->cd();
  // 	break;
  //     case 1:
  // 	TCanvas *cbe = new TCanvas("cbe","cbe",1200,800);
  // 	cbe->cd();
  // 	break;
  //     case 2:
  // 	TCanvas *ce = new TCanvas("ce","ce",1200,800);
  // 	ce->cd();
  // 	break;
  //     default: break;
  //     }
    // rapa=rapa_init[r];
    // rapb=rapb_init[r+1];
    
    // cout <<"----- list of pt cuts done -----"<< endl;
    // for(int p1=ptCutStart; p1<=ptCutStop; p1++)
    //   {
    // 	for(int p2=ptCutStart; p2<=ptCutStop; p2++){
    // 	  if( p2< p1) continue;
    // 	  cout << p1 << " " << p2 <<endl;
    // 	  pta=pta_init[p1];
    // 	  ptb=ptb_init[p2];
    // 	  cout << "pT(1) > "<< pta <<" and pT(2) > "<< ptb <<endl;
	
    // 	  if( rapa==rapidityBinStart && pta==ptCutStart && ptb==ptCutStart ){option=true;}
    // 	  cout << rapa << " " << rapb << " " << pta << " " << ptb << " " << option << endl;
    // 	  plotSimple(rapa,rapb,pta,ptb,option);
    // 	}
    //   }
    // switch r
    //   {
    //   case 0:
    // 	cb->Draw();
    // 	break;
    //   case 1:
    // 	cbe->Draw();
    // 	break;
    //   case 2:
    // 	ce->Draw();
    // 	break;
    //   default: break;
    //   }
    //}
  


// void plotSimple(float rapCut0, float rapCut1, float ptCut0, float ptCut1,bool opt){
  
//   string drawSame;
//   TCut cutter(Form("(abs(upsRapidity)>%.1f && abs(upsRapidity)<%.1f) && ((muPlusPt>%.1f && muMinusPt>%.1f)||(muPlusPt>%.1f && muMinusPt>%.1f))",rapCut0,rapCut1,ptCut0,ptCut1,ptCut1,ptCut0));
//    if(!opt){drawSame = "same";}
//   // cout << cutter.Print() <<endl;
//    UpsilonTree->Draw("invariantMass>>tmp(70,7,14)",cutter,drawSame);



//   TCut cutter();
//   if (rapidityBin==1){cutter=cut_0p8;}else if (rapidityBin==2){cutter=cut_1p6 ;}else if (rapidityBin==3){cutter=cut_2p4 ;}
//   switch rapidityBin{
//     case 1:
//       cutter=cut_0p8;
//       break;
//     case 2:
//       cutter=cut_1p6;
//       break;
//     case 3:
//       cutter=cut_2p4;
//       break;
//     default:
//       cutter=0;
//       break;
//     }
  
//   // barrel: |y| < 0.8 

//  
//   b3p53p5->SetFillColor(kRed+2);  
//   float sbl_b3p53p5 =  b3p53p5->Integral("invariantMass<9.2 && invariantMass > 7");
//   cout << sbl_b3p53p5 << endl;
//   UpsilonTree->Draw("invariantMass>>b3p54(70,7,14)",cut_0p8+cut3p54,"same");
//   b3p54->SetFillColor(kBlue);    
//   UpsilonTree->Draw("invariantMass>>b3p54p5(70,7,14)",cut_0p8+cut3p54p5,"same");
//   b3p54p5->SetFillColor(kGreen+1);     
//   UpsilonTree->Draw("invariantMass>>b44(70,7,14)",cut_0p8+cut44,"same");
//   b44->SetFillColor(kRed);  

//   UpsilonTree->Draw("invariantMass>>b4p54p5(70,7,14)",cut_0p8+cut4p54p5,"same");
//   b4p54p5->SetFillColor(kOrange);  

//   c1->Draw();

//   // barrel+endcap : 0.8 < |y| < 1.6
//   TCanvas *c2 = new TCanvas("c2_name","c2_title",1200,800);
//   c2->cd();
//   UpsilonTree->Draw("invariantMass>>be3p53p5(70,7,14)",cut_1p6+cut3p53p5,"");
//   be3p53p5->SetFillColor(kRed+2);  
//   UpsilonTree->Draw("invariantMass>>be3p54(70,7,14)",cut_1p6+cut3p54,"same");
//   be3p54->SetFillColor(kBlue);    
//   UpsilonTree->Draw("invariantMass>>be3p54p5(70,7,14)",cut_1p6+cut3p54p5,"same");
//   be3p54p5->SetFillColor(kGreen+1);     
//   UpsilonTree->Draw("invariantMass>>be44(70,7,14)",cut_1p6+cut44,"same");
//   be44->SetFillColor(kRed);  

//   UpsilonTree->Draw("invariantMass>>be4p54p5(70,7,14)",cut_1p6+cut4p54p5,"same");
//   be4p54p5->SetFillColor(kOrange);  

//   c2->Draw();

//   // endcap : |y| > 1.6
//   TCanvas *c3 = new TCanvas("c3_name","c3_title",1200,800);
//   c3->cd(); 
//   UpsilonTree->Draw("invariantMass>>e3p53p5(70,7,14)",cut_2p4+cut3p53p5,"");
//   e3p53p5->SetFillColor(kRed+2);  
//   UpsilonTree->Draw("invariantMass>>e3p54(70,7,14)",cut_2p4+cut3p54,"same");
//   e3p54->SetFillColor(kBlue);    
//   UpsilonTree->Draw("invariantMass>>e3p54p5(70,7,14)",cut_2p4+cut3p54p5,"same");
//   e3p54p5->SetFillColor(kGreen+1);     
//   UpsilonTree->Draw("invariantMass>>e44(70,7,14)",cut_2p4+cut44,"same");
//   e44->SetFillColor(kRed);  

//   UpsilonTree->Draw("invariantMass>>e4p54p5(70,7,14)",cut_2p4+cut4p54p5,"same");
//   e4p54p5->SetFillColor(kOrange);  

//   c3->Draw();

//}
