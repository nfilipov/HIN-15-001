#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif

#include "RooAbsPdf.h"
#include "RooAddPdf.h"
#include "RooCBShape.h"
#include "RooChebychev.h"
#include "RooConstVar.h"
#include "RooDataSet.h"
#include "RooFitResult.h"
#include "RooGaussian.h"
#include "RooGenericPdf.h"
#include "RooHist.h"
#include "RooHistPdf.h"
#include "RooDataHist.h"
#include "RooKeysPdf.h"
#include "RooProdPdf.h"
#include "RooMCStudy.h"
#include "RooPolynomial.h"
#include "RooRealVar.h"
#include "RooPlot.h"
#include "RooWorkspace.h"
#include "RooChi2Var.h"

#include "RooStats/ModelConfig.h"
#include "RooStats/ProfileLikelihoodCalculator.h"
#include "RooStats/LikelihoodInterval.h"
#include "RooStats/LikelihoodIntervalPlot.h"

// Root stuff
#include "TROOT.h"
#include "TAxis.h"
#include "TCanvas.h"
#include "TDirectory.h"
#include "TFile.h"
#include "TLatex.h"
#include "TCut.h"

#include "TMath.h"
#include "TPaveLabel.h"
#include "TPaveText.h"
#include "TStyle.h"
#include "TText.h"

using namespace std;
using namespace ROOT; 
using namespace RooFit;
///macro to make efficiencies .


void cutChecker()
{
  int kCut =2 ;//1:vProb, 2:dca, 3:MatchedStations, 4:ctau/ctauErr
  int pbpb=false;
  gROOT->Macro("./cm/logon.C+");//it all looks much nicer with this.  
  // TString fname2011="../dimuonTree_HI2011_fulldataset_trkRot.root";
  // TFile *_file0 = TFile::Open(fname2011);
  // TTree *upsi2011    = (TTree*)_file0->Get("UpsilonTree");
 
  
  if(pbpb) { TString fname2013=" ../dimuonTree_upsiMiniTree_AA2p76tev_WithIDCuts_RunHIN-15-001_trigBit1_allTriggers0.root";//../dimuonTree_upsiMiniTree_aa276tev_regitreco_glbglb_Runa_trigBit1_allTriggers0_pt4.root";
  }else if(!pbpb){
  TString fname2013=" ../dimuonTree_upsiMiniTree_pp2p76tev_noIDVars_GlbGlb_RunHIN-15-001_trigBit2_allTriggers0.root";
  }
  //TString fname2013="../upsiMiniTree_pyquen1S_noMuonPtCuts_QQtrigbit1_Trig_analysisOK_20140729_cuts10-006.root";
  TFile *_file1 = TFile::Open(fname2013);
  TTree *upsi2013 = (TTree*)_file1->Get("UpsilonTree");
  RooRealVar* upsPt      = new RooRealVar("upsPt","p_{T}(#Upsilon)",0,60,"GeV");
  //  RooRealVar* upsEta     = new RooRealVar("upsEta",  "upsEta"  ,-10,10);
  RooRealVar* upsRapidity= new RooRealVar("upsRapidity",  "upsRapidity",-1000, 1000);
  RooRealVar* vProb      = new RooRealVar("vProb",  "vProb"  ,0.01,1.00);
  RooRealVar* _dca      = new RooRealVar("_dca",  "_dca"  ,0.0,5.00);
  RooRealVar* _ctau     = new RooRealVar("_ctau",  "_ctau"  ,-100,100,"cm");
  RooRealVar* _ctauErr     = new RooRealVar("_ctauErr",  "_ctauErr"  ,-100,100,"cm");
  RooRealVar* muPlusPt   = new RooRealVar("muPlusPt","muPlusPt",3.5,100);
  RooRealVar* muMinusPt  = new RooRealVar("muMinusPt","muMinusPt",3.5,100);
  RooRealVar* muPlusEta  = new RooRealVar("muPlusEta","muPlusEta",  -2.4,2.4);
  RooRealVar* muMinusEta = new RooRealVar("muMinusEta","muMinusEta",-2.4,2.4);
  RooRealVar* _mupl_StationsMatched  = new RooRealVar("_mupl_StationsMatched","_mupl_StationsMatched",0,5);
  RooRealVar* _mumi_StationsMatched  = new RooRealVar("_mumi_StationsMatched","_mumi_StationsMatched",0,5);
  RooRealVar* muMinusEta = new RooRealVar("muMinusEta","muMinusEta",-2.4,2.4);
  RooRealVar* mass = new RooRealVar("invariantMass","#mu#mu mass",7,14,"GeV/c^{2}"); 
  TCut cut_acc = " ((muPlusPt >3.5 && muMinusPt>4)||(muPlusPt>4 &&muMinusPt>3.5))  && abs(upsRapidity)<2.4 && (invariantMass<14 && invariantMass>7)"; //  
  cout << "cut: "<< cut_acc.Print() << endl;
  //  TCut cut_add(cutList(1,1));
  //cout << "cut: "<< cut_add.Print() << endl;
 
  switch (kCut){
  case 1: //vProb]   
    RooDataSet *data0 = new RooDataSet("data0","data0",upsi2013,
				       RooArgSet(*mass,*muPlusPt,*muMinusPt,*upsRapidity,*vProb));
    string cut[4]={"vProb>0.01",// very loose
		   "vProb>0.05",
		   "vProb>0.1",
		   "vProb>0.2"};//very tight
    // for plotting purposes...
    break;
  case 2: //dca
    RooDataSet *data0 = new RooDataSet("data0","data0",upsi2013,
				       RooArgSet(*mass,*muPlusPt,*muMinusPt,*upsRapidity,*_dca));
    string cut[4]={"_dca<0.004", //very tight
		   "_dca<0.006",
		   "_dca<0.008",
		   "_dca<0.01"}; // very loose
    break;
  case 3: // number of matched Stations
    RooDataSet *data0 = new RooDataSet("data0","data0",upsi2013,
				       RooArgSet(*mass,*muPlusPt,*muMinusPt,*upsRapidity,*_mupl_StationsMatched,*_mumi_StationsMatched));
    string cut[4]={  "_mumi_StationsMatched>0&&_mupl_StationsMatched>0",  
		     "_mumi_StationsMatched>1&&_mupl_StationsMatched>1",
		     "_mumi_StationsMatched>2&&_mupl_StationsMatched>2",
		     "_mumi_StationsMatched>3&&_mupl_StationsMatched>3"};
    string cutname[4]={  "at least one",  
			 "more than 1",
			 "more than 2",
			 "more than 3"};
    break;
  case 4: ///fabs(ctau/ctau_err)
    RooDataSet *data0 = new RooDataSet("data0","data0",upsi2013,
				       RooArgSet(*mass,*muPlusPt,*muMinusPt,*upsRapidity,*_ctau,*_ctauErr));
    
    string cut[4]={"abs(_ctau/_ctauErr)<5",//very loose
		   "abs(_ctau/_ctauErr)<4" ,
		   "abs(_ctau/_ctauErr)<3" ,
		   "abs(_ctau/_ctauErr)<2" }; //tighter
    string cutname[4]={"|c#tau/#sigma(c#tau)| < 5",  
		       "|c#tau/#sigma(c#tau)| < 4",
		       "|c#tau/#sigma(c#tau)| < 3",
		       "|c#tau/#sigma(c#tau)| < 2"};
    break;
  default:
    cout<< "no Cut Variable specified!"<<endl; break;
  }
  TCut cut_add1((cut[0]).c_str());
  TCut cut_add2((cut[1]).c_str());  
  TCut cut_add3((cut[2]).c_str());
  TCut cut_add4((cut[3]).c_str());
  TString figName_(Form("%s",(cut[0]).c_str()));
    figName_.ReplaceAll(">","_gt");
    figName_.ReplaceAll("<","_lt");
    figName_.ReplaceAll(".","p");
    figName_.ReplaceAll("&&","_AND_");
    figName_.ReplaceAll("||","_OR_");
    figName_.ReplaceAll("(","");
    figName_.ReplaceAll("/","-");
    figName_.ReplaceAll(")","");
    
    cout << "hello"<< endl;
  // cut_add.Print();

  int nt = data0->sumEntries();
  redData1 =  ( RooDataSet*) data0->reduce(Cut(cut_acc+cut_add1));
  redData1->Print();
  TH1D *MReco1;
  MReco1 = new TH1D("MReco1","Reco di-muon mass",70,7,14);
  MReco1 = (TH1D*) redData1->createHistogram("invariantMass",*mass);
  redData2 =  ( RooDataSet*) data0->reduce(Cut(cut_acc+cut_add2));
  redData2->Print();
  TH1D *MReco2;
  MReco2 = new TH1D("MReco2","Reco di-muon mass",70,7,14);
  MReco2 = (TH1D*) redData2->createHistogram("invariantMass",*mass);
  redData3 =  ( RooDataSet*) data0->reduce(Cut(cut_acc+cut_add3));
  redData3->Print();
  TH1D *MReco3;
  MReco3 = new TH1D("MReco3","Reco di-muon mass",70,7,14);
  MReco3 = (TH1D*) redData3->createHistogram("invariantMass",*mass);
  redData4 =  ( RooDataSet*) data0->reduce(Cut(cut_acc+cut_add4));
  redData4->Print();
  TH1D *MReco4;
  MReco4 = new TH1D("MReco4","Reco di-muon mass",70,7,14);
  MReco4 = (TH1D*) redData4->createHistogram("invariantMass",*mass);
  const double M1S = 9.46;   //upsilon 1S pgd mass value
  const double M2S = 10.023;  //upsilon 2S pgd mass value
  const double M3S = 10.355;  //upsilon 3S pgd mass value
  RooRealVar *nsig1f   = new RooRealVar("N_{#Upsilon(1S)}","nsig1S",0,nt*10);
  RooRealVar *nsig2f  = new RooRealVar("N_{#Upsilon(2S)}","nsig2S",   nt*0.25,-1*nt,10*nt);
  RooRealVar *nsig3f  = new RooRealVar("N_{#Upsilon(3S)}","nsig3S",   nt*0.25,-1*nt,10*nt);
  RooRealVar  *mean = new RooRealVar("mass1S","#Upsilon mean",M1S,M1S-0.1,M1S+0.1);
  RooConstVar *rat2 = new RooConstVar("rat2", "rat2", M2S/M1S);
  RooConstVar *rat3 = new RooConstVar("rat3", "rat3", M3S/M1S);
  // scale mean and resolution by mass ratio
  RooFormulaVar *mean1S = new RooFormulaVar("mean1S","@0",RooArgList(*mean));
  RooFormulaVar *mean2S = new RooFormulaVar("mean2S","@0*@1", RooArgList(*mean,*rat2));
  RooFormulaVar *mean3S = new RooFormulaVar("mean3S","@0*@1", RooArgList(*mean,*rat3));
  
  //detector resolution ?? where is this coming from?
  RooRealVar    *sigma1  = new RooRealVar("#sigma_{CB1}","#sigma_{CB1}",0,0.5); // 
  RooFormulaVar *sigma1S = new RooFormulaVar("sigma1S","@0"   ,RooArgList(*sigma1));
  RooFormulaVar *sigma2S = new RooFormulaVar("sigma2S","@0*@1",RooArgList(*sigma1,*rat2));
  RooFormulaVar *sigma3S = new RooFormulaVar("sigma3S","@0*@1",RooArgList(*sigma1,*rat3));
  RooRealVar *alpha  = new RooRealVar("#alpha_{CB}","tail shift",0.01,8);    // MC 5tev 1S pol2 
  RooRealVar *npow   = new RooRealVar("npow","power order",1,60);    // MC 5tev 1S pol2 
  RooRealVar *sigmaFraction = new RooRealVar("sigmaFraction","Sigma Fraction",0.,1.);
  // scale the sigmaGaus with sigma1S*scale=sigmaGaus now.
  RooRealVar    *scaleWidth = new RooRealVar("#sigma_{CB2}/#sigma_{CB1}","scaleWidth",1.,2.7);
  RooFormulaVar *sigmaGaus = new RooFormulaVar("sigmaGaus","@0*@1", RooArgList(*sigma1,*scaleWidth));
  RooFormulaVar *sigmaGaus2 = new RooFormulaVar("sigmaGaus","@0*@1*@2", RooArgList(*sigma1,*scaleWidth,*rat2));
  RooFormulaVar *sigmaGaus3 = new RooFormulaVar("sigmaGaus","@0*@1*@2", RooArgList(*sigma1,*scaleWidth,*rat3));
  RooCBShape  *cb1S_1    = new RooCBShape ("cb1S_1", "FSR cb 1s",
					   *mass,*mean1S,*sigma1,*alpha,*npow);
  
  RooCBShape  *cb1S_2    = new RooCBShape ("cb1S_2", "FSR cb 1s",
					   *mass,*mean1S,*sigmaGaus,*alpha,*npow);
  RooAddPdf      *sig1S  = new RooAddPdf  ("cbcb","1S mass pdf",
					   RooArgList(*cb1S_1,*cb1S_2),*sigmaFraction);
  // /// Upsilon 2S
  RooCBShape  *cb2S_1    = new RooCBShape ("cb2S_1", "FSR cb 2s", 
					   *mass,*mean2S,*sigma2S,*alpha,*npow); 
  RooCBShape  *cb2S_2    = new RooCBShape ("cb2S_2", "FSR cb 2s", 
					   *mass,*mean2S,*sigmaGaus2,*alpha,*npow); 
  RooAddPdf      *sig2S  = new RooAddPdf  ("sig2S","2S mass pdf",
					   RooArgList(*cb2S_1,*cb2S_2),*sigmaFraction);
    
  // /// Upsilon 3S
  RooCBShape  *cb3S_1    = new RooCBShape ("cb3S_1", "FSR cb 3s", 
					   *mass,*mean3S,*sigma3S,*alpha,*npow); 
  RooCBShape  *cb3S_2    = new RooCBShape ("cb3S_2", "FSR cb 3s", 
					   *mass,*mean3S,*sigmaGaus3,*alpha,*npow); 
  RooAddPdf      *sig3S  = new RooAddPdf  ("sig3S","3S mass pdf",
					   RooArgList(*cb3S_1,*cb3S_2),*sigmaFraction);
  // bkg Chebychev
  RooRealVar *nbkgd   = new RooRealVar("n_{Bkgd}","nbkgd",0,nt);
  RooRealVar *bkg_a1  = new RooRealVar("a1_bkg", "bkg_{a1}", 0, -5, 5);
  RooRealVar *bkg_a2  = new RooRealVar("a2_Bkg", "bkg_{a2}", 0, -5, 5);
  RooRealVar *bkg_a3  = new RooRealVar("a3_Bkg", "bkg_{a3}", 0, -2, 2);
  RooAbsPdf  *pdf_combinedbkgd  = new RooChebychev("bkgPdf","bkgPdf",
						   *mass, RooArgList(*bkg_a1,*bkg_a2));
  RooRealVar turnOn("turnOn","turnOn",2.,8.6);
  RooRealVar width("width","width",0.3,8.5);// MB 2.63
  RooRealVar decay("decay","decay",1,18);// MB: 3.39
  RooGenericPdf *ErrPdf     = new  RooGenericPdf("ErrPdf","ErrPdf",
						 "exp(-@0/decay)*(TMath::Erf((@0-turnOn)/width)+1)",
						 RooArgList(*mass,turnOn,width,decay));
  

  // bkg_a2->setVal(0);
  // bkg_a2->setConstant();
  RooDataHist binnedData1 ("binnedData1","binnedData1",*mass,Import(*MReco1));  
  RooDataHist binnedData2 ("binnedData2","binnedData2",*mass,Import(*MReco2));
  RooDataHist binnedData3 ("binnedData3","binnedData3",*mass,Import(*MReco3));
  RooDataHist binnedData4 ("binnedData4","binnedData4",*mass,Import(*MReco4));
  RooAbsPdf  *pdf             = new RooAddPdf ("pdf","total p.d.f.",
					       RooArgList(*sig1S,*sig2S,*sig3S,*ErrPdf),
					       RooArgList(*nsig1f,*nsig2f,*nsig3f,*nbkgd));
  npow->setVal(2);
  npow->setConstant();
  //for the plots!
  TCanvas c; c.cd();  
  TPad phead("phead","phead",0.05,0.9,1.,1.,0,0,0); 
  phead.Draw(); phead.cd();
  TLatex *cms = new TLatex (0.1,0.1,"CMS Internal");
  cms->SetTextFont(40);
  cms->SetTextSize(0.4);
  cms->SetTextColor(kBlack);
  cms->Draw();  
  if(pbpb){  TLatex *pbpb = new TLatex (0.6,0.1,"PbPb #sqrt{s_{NN}} = 2.76 TeV");
  pbpb->SetTextFont(42);
  pbpb->SetTextSize(0.35);
  pbpb->SetTextColor(kBlack);
  pbpb->Draw(); 
  }else if(!pbpb){
  TLatex *pp = new TLatex (0.6,0.1,"pp #sqrt{s} = 2.76 TeV");
  pp->SetTextFont(42);
  pp->SetTextSize(0.35);
  pp->SetTextColor(kBlack);
  pp->Draw();    
  }
  TPad pbody("pbody","pbody",0.0,0.0,1.,0.9,0,0,0);
  c.cd();
  pbody.SetLeftMargin(0.15);
  pbody.Draw(); pbody.cd();
  RooPlot* frame = mass->frame(Bins(70),Range(7,14));
  // 1st round
    RooAbsReal* nll1 = pdf->createNLL(binnedData1,NumCPU(4)) ;
    RooMinuit(*nll1).migrad();
    RooMinuit(*nll1).hesse();
    binnedData1.plotOn(frame,Name("theData"),MarkerSize(0.6),MarkerStyle(20),MarkerColor(kBlue));   
    pdf->plotOn(frame,Name("thePdf"),LineColor(kBlue)); 
    double signif1 = nsig1f->getVal()/nsig1f->getError();
    double signif1_2s = nsig2f->getVal()/nsig2f->getError();
    double signif1_3s = nsig3f->getVal()/nsig3f->getError();
    MReco1->SetMarkerSize(1.0);
    MReco1->SetMarkerStyle(20);
    MReco1->SetMarkerColor(kBlue);
    MReco1->Draw("esame");  
    // 2nd round
    RooAbsReal* nll2 = pdf->createNLL(binnedData2,NumCPU(4)) ;
    RooMinuit(*nll2).migrad();
    RooMinuit(*nll2).hesse();
    binnedData2.plotOn(frame,Name("theData"),MarkerSize(0.6),MarkerStyle(20),MarkerColor(kRed));   
    pdf->plotOn(frame,Name("thePdf"),LineColor(kRed)); 
    double signif2 = nsig1f->getVal()/nsig1f->getError();
    double signif2_2s = nsig2f->getVal()/nsig2f->getError();
    double signif2_3s = nsig3f->getVal()/nsig3f->getError();
    MReco2->SetMarkerSize(1.0);
    MReco2->SetMarkerStyle(20);
    MReco2->SetMarkerColor(kRed);
    MReco2->Draw("esame");  
    // 3rd round
    RooAbsReal* nll3 = pdf->createNLL(binnedData3,NumCPU(4)) ;
    RooMinuit(*nll3).migrad();
    RooMinuit(*nll3).hesse();
    binnedData3.plotOn(frame,Name("theData"),MarkerSize(0.6),MarkerStyle(20),MarkerColor(8));   
    pdf->plotOn(frame,Name("thePdf"),LineColor(8)); 
    double signif3 = nsig1f->getVal()/nsig1f->getError();
    double signif3_2s = nsig2f->getVal()/nsig2f->getError();
    double signif3_3s = nsig3f->getVal()/nsig3f->getError();
    MReco3->SetMarkerSize(1.0);
    MReco3->SetMarkerStyle(20);
    MReco3->SetMarkerColor(8);
    MReco3->Draw("esame");  
    // 4th round
    RooAbsReal* nll4 = pdf->createNLL(binnedData4,NumCPU(4)) ;
    RooMinuit(*nll4).migrad();
    RooMinuit(*nll4).hesse();
    binnedData4.plotOn(frame,Name("theData"),MarkerSize(0.6),MarkerStyle(20),MarkerColor(28));   
    pdf->plotOn(frame,Name("thePdf"),LineColor(28)); 
    double signif4 = nsig1f->getVal()/nsig1f->getError();
    double signif4_2s = nsig2f->getVal()/nsig2f->getError();
    double signif4_3s = nsig3f->getVal()/nsig3f->getError();
    // pdf->paramOn(frame,Layout(0.5,0.95,0.9),Parameters(RooArgSet(signif)),Format("N",AutoPrecision(1)));
    MReco4->SetMarkerSize(1.0);
    MReco4->SetMarkerStyle(20);
    MReco4->SetMarkerColor(28);
    MReco4->Draw("esame");  
    // and all that.
    frame->SetTitle("");
    frame->GetXaxis()->SetTitle("m_{#mu^{+}#mu^{-}} (GeV/c^{2})");
    frame->GetXaxis()->CenterTitle(kTRUE);
    frame->GetYaxis()->SetTitleOffset(2);
    frame->GetXaxis()->SetTitleOffset(1.5);
    frame->Draw();
    TLegend *legend = new TLegend(0.5,0.6,0.95,0.9);
    legend->SetTextSize(0.034);
    legend->SetFillStyle(0);
    legend->SetFillColor(0);
    legend->SetBorderSize(0);
    legend->SetTextFont(42);
    legend->AddEntry(MReco1,"1S significance, #Sigma","");
    switch (kCut){
    case 1: //vProb]   
      legend->AddEntry(MReco1,"Vertex Probability","");
      legend->AddEntry(MReco1,Form("%s, #Sigma = %0.2f",cut[0].c_str(),signif1),"p");
      legend->AddEntry(MReco2,Form("%s, #Sigma = %0.2f",cut[1].c_str(),signif2),"p");
      legend->AddEntry(MReco3,Form("%s, #Sigma = %0.2f",cut[2].c_str(),signif3),"p");
      legend->AddEntry(MReco4,Form("%s, #Sigma = %0.2f",cut[3].c_str(),signif4),"p");
      break;
    case 2:   
      legend->AddEntry(MReco1,"Dist. of closest approach","");
      legend->AddEntry(MReco1,Form("%s, #Sigma = %0.2f",cut[0].c_str(),signif1),"p");
      legend->AddEntry(MReco2,Form("%s, #Sigma = %0.2f",cut[1].c_str(),signif2),"p");
      legend->AddEntry(MReco3,Form("%s, #Sigma = %0.2f",cut[2].c_str(),signif3),"p");
      legend->AddEntry(MReco4,Form("%s, #Sigma = %0.2f",cut[3].c_str(),signif4),"p");
      break;
    case 3:
      legend->AddEntry(MReco1,"Stations matched to each track","");
      legend->AddEntry(MReco1,Form("%s, #Sigma = %0.2f",cutname[0].c_str(),signif1),"p");
      legend->AddEntry(MReco2,Form("%s, #Sigma = %0.2f",cutname[1].c_str(),signif2),"p");
      legend->AddEntry(MReco3,Form("%s, #Sigma = %0.2f",cutname[2].c_str(),signif3),"p");
      legend->AddEntry(MReco4,Form("%s, #Sigma = %0.2f",cutname[3].c_str(),signif4),"p");
      break;
    case 4:
      legend->AddEntry(MReco1,"Pseudo-proper decay length","");
      legend->AddEntry(MReco1,Form("%s, #Sigma = %0.2f",cutname[0].c_str(),signif1),"p");
      legend->AddEntry(MReco2,Form("%s, #Sigma = %0.2f",cutname[1].c_str(),signif2),"p");
      legend->AddEntry(MReco3,Form("%s, #Sigma = %0.2f",cutname[2].c_str(),signif3),"p");
      legend->AddEntry(MReco4,Form("%s, #Sigma = %0.2f",cutname[3].c_str(),signif4),"p");
      break;
    default: break;
    }
    legend->Draw();
    //    legend->AddEntry(MReco1,Form(",),"f");
    // TLatex latex1;
    // latex1.SetNDC();
    // latex1.SetTextSize(0.032);
    // latex1.DrawLatex(0.35,1.-0.05*2.,Form("significance: #Sigma vs %s",cut[0].c_str()));
    // latex1.DrawLatex(0.55,1.-0.05*3.,Form(" #Sigma = %f",signif1));
    // latex1.DrawLatex(0.55,1.-0.05*4.,Form(" #Sigma = %f",signif2));
    // latex1.DrawLatex(0.55,1.-0.05*5.,Form(" #Sigma = %f",signif3));
    // latex1.DrawLatex(0.55,1.-0.05*6.,Form(" #Sigma = %f",signif4));
    c.Draw();
    if(pbpb){
      c.SaveAs("~/Desktop/Grenelle/"+figName_+".pdf");
    }
    else if(!pbpb){
      c.SaveAs("~/Desktop/Grenelle/"+figName_+"_pp.pdf");
    }
   
    cout <<" SIGNIFICANCES \\Sigma OF ALL STATES:" << endl;
    cout << "xxxx - \\Sigma(1S) \&  \\Sigma(2S) \& \\Sigma(3S) " <<endl;
    cout << cut[0].c_str() <<" & "<< signif1 << " &"<< signif1_2s << " & "<< signif1_3s << endl;
    cout << cut[1].c_str() <<" & "<< signif2 << " &"<< signif2_2s << " & "<< signif2_3s << endl;
    cout << cut[2].c_str() <<" & "<< signif3 << " &"<< signif3_2s << " & "<< signif3_3s << endl;
    cout << cut[3].c_str() <<" & "<< signif4 << " &"<< signif4_2s << " & "<< signif4_3s << endl;
}
