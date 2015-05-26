void fitAndDraw(RooWorkspace& w, int chooseSample , TString figname_, TString outDatDir ,  TString outFigDir, int chooseFitParams,int bkgdModel,float muonPt1, float muonPt2,int centMin, int centMax, float upsPtStart, float upsPtEnd, float upsRapStart, float upsRapEnd, int doRap, int doPt,int doCent ){
  double ycms = 0.28;// for header cms legend, and pull sometimes
  double xcms = 0.04;
  double deltay = 0.03;
  RooRealVar* mass =(RooRealVar*) w.var("invariantMass"); //
  RooDataSet* data0_fit =(RooDataSet*) w.data("data");
  RooAbsPdf* pdf = (RooAbsPdf*) w.pdf("pdf");
  RooFitResult* fitObject = pdf->fitTo(*data0_fit,Save()); // Fit gets 
  pdf->Print();
  Double_t baseNll = fitObject->minNll();
  // RooMinuit m(*nll);
  // m.migrad();
  // m.hesse();
  //  m.minos(w.var("nsig3f"));
  // RooFitResult* fitRes = m.save();
  RooArgSet allvars = w.allVars();
  int npars= allvars.getSize() ;
  int nbins = ceil((mass_h-mass_l)/binw); // all of which are 'globally' defined in the .h header
  RooPlot* frame = mass->frame(Bins(nbins),Range(mass_l,mass_h));  
  data0_fit->plotOn(frame);// data drawn first for pdf object to pick the proper normalisation
  pdf->plotOn(frame,Name("thePdf"));
  switch(bkgdModel){
    case 1:
      pdf->plotOn(frame,Components("ChebPdf"),Name("theBkg"),VisualizeError(*fitObject,1),FillColor(kBlue));
      pdf->plotOn(frame,Components("ErrPdf"),Name("theBkg"),VisualizeError(*fitObject,1),FillColor(kOrange));// ErrFunction bkg
      pdf->plotOn(frame,Components("bkgPdf"),Name("theBkg"),LineStyle(kDashed));
      RooArgSet * pars = ErrPdf->getParameters(likesignData);
      break;
    case 2:
      pdf->plotOn(frame,Components("ChebPdf"),Name("theBkg"),VisualizeError(*fitObject,1),FillColor(kBlue));
      pdf->plotOn(frame,Components("KeysPdf"),Name("theBkg"),VisualizeError(*fitObject,1),FillColor(kOrange));// ErrFunction bk
      RooArgSet * pars = KeysPdf->getParameters(likesignData);
      pdf->plotOn(frame,Components("bkgPdf"),Name("theBkg"),LineStyle(kDashed));
      break;
    case 3:
      pdf->plotOn(frame,Components("bkgPdf"),Name("theBkg"),VisualizeError(*fitObject,1),LineStyle(kDashed));
      pdf->plotOn(frame,Components("bkgPdf"),Name("theBkg"),LineStyle(kDashed));
      break;
    case 4:
      pdf->plotOn(frame,Components("bkgPdf"),Name("theBkg"),VisualizeError(*fitObject,1));
      pdf->plotOn(frame,Components("bkgPdf"),Name("theBkg"),LineStyle(kDashed));
      break;
    case 5:
      pdf->plotOn(frame,Components("ChebPdf"),Name("theBkg"),VisualizeError(*fitObject,1),FillColor(kBlue));
      pdf->plotOn(frame,Components("ErrPdf"),Name("theBkg"),VisualizeError(*fitObject,1),FillColor(kOrange));// ErrFunction bk
      pdf->plotOn(frame,Components("bkgPdf"),Name("theBkg"),LineStyle(kDashed));
      break;
    case 6:
      pdf->plotOn(frame,Components("bkgPdf"),Name("theBkg"),VisualizeError(*fitObject,1));
      break;
    default:
      break;
    }
  data0_fit->plotOn(frame) ;// drawing data pts over pdf line (looks best).
  pdf->plotOn(frame,Name("thePdf")); // signal + bkg pdf
  frame->SetTitle("");
  frame->GetXaxis()->SetTitle("m_{#mu^{+}#mu^{-}} (GeV/c^{2})");
  frame->GetXaxis()->CenterTitle(kTRUE);
  frame->GetYaxis()->SetTitleOffset(1.4);
  frame->GetYaxis()->SetTitleSize(0.04);
  //Draw stuff!
  TCanvas cm("cm","cm");
  cm.cd();
  TPad *pPad1 = new TPad("pPad1","pPad1",xcms,ycms-1.9*deltay,0.98,0.92);
  //  pPad1->SetBottomMargin(0.03);
  pPad1->Draw();
  pPad1->cd();
  pdf->paramOn(frame,Layout(0.6,0.935,0.97),Format("NEAU",AutoPrecision(1)));
  pPad1->Update();
  frame->Draw();
  TLatex latex1;
  latex1.SetNDC();
  latex1.SetTextSize(0.035);
  latex1.DrawLatex(xcms*4,1.-0.05*5.6,Form("p_{T}^{#mu_{1}} > %.1f GeV/c",muonPt1));
  latex1.DrawLatex(xcms*4,1.-0.05*6.8,Form("p_{T}^{#mu_{2}} > %.1f GeV/c",muonPt2));
  if(doPt){
    if(upsPtEnd<3){
      latex1.DrawLatex(xcms*4,1.-0.05*2,Form("p_{T} < %.1f",upsPtEnd));
    }else{
      latex1.DrawLatex(xcms*4,1.-0.05*2,Form("%.1f < p_{T} < %.1f",upsPtStart,upsPtEnd));
    }
    latex1.DrawLatex(xcms*4,1.-0.05*3.2,"|y| < 2.4");
  }
  if(doRap){
    if(upsRapStart<0.1){
      if(((upsRapEnd>1.1&&upsRapEnd<1.3)||upsRapEnd>2.3) || upsRapEnd<0.5)
	{
	  latex1.DrawLatex(xcms*4,1.-0.05*2,Form("|y| < %.1f",upsRapEnd));
	}
      else{    latex1.DrawLatex(xcms*4,1.-0.05*2,Form("%.1f < |y| < %.1f",upsRapStart,upsRapEnd));}
    }else{
      latex1.DrawLatex(xcms*4,1.-0.05*2,Form("%.1f < |y| < %.1f",upsRapStart,upsRapEnd));}
  }
  if(doCent){
    latex1.DrawLatex(xcms*4,1.-0.05*2,Form("Cent. %d-%d%%",centMin,centMax));
    latex1.DrawLatex(xcms*4,1.-0.05*3.2,"p_{T} > 0");
    latex1.DrawLatex(xcms*4,1.-0.05*4.4,"|y| < 2.4");
  }
  cm.cd();
  TPad *pPad2 = new TPad("pPad2","pPad2",xcms,0,0.98,ycms+deltay/1.3);
  pPad2->SetTopMargin(0.0);
  pPad2->SetBottomMargin(0.4);
  pPad2->Draw();
  pPad2->cd();
  // **************** create pulls; change the chi2 calculation also
  double chi2FromRoo = frame->chiSquare(fitObject->floatParsFinal().getSize());
  cout<<"!!!!!!!! chi2 from simple pull= "<<frame->chiSquare()<<"\t chi2 from RooFit= "<<chi2FromRoo <<endl;
  RooHist *phPullm = frame->pullHist(0,0,true); // this calcualtes the pulls taking the integral of the fit in each bin, instead of the value in the middle of the bid
  phPullm->SetName("phPullm");
  double *ypull     = phPullm->GetY();
  
  TH1 *phData      = data0_fit->createHistogram("invariantMass",nbins);
  double Chi2       = 0;
  int nFullBinsPull = 0;
  for (int i=0; i < nbins; i++) 
    {
      if (phData->GetBinContent(i) == 0) continue;
      nFullBinsPull++;
      Chi2 = Chi2 + pow(ypull[i],2);
    }
  
  // for writing on canvas
  int nFitParam     = fitObject->floatParsFinal().getSize();
  int Dof           = nFullBinsPull - nFitParam;
  double UnNormChi2 = Chi2;
  Chi2             /= (nFullBinsPull - nFitParam);
  
  cout<<"!!!!! nFullBinsPull="<<nFullBinsPull<<"\tnFitParam="<<nFitParam<<endl;
  // draw pulls
  pPad2->cd();
  double mFrameMax = 0;
  RooPlot* prpFramePull = mass->frame(Title("Pull"),Bins(nbins),Range(mass_l,mass_h));
  prpFramePull->GetYaxis()->CenterTitle(kTRUE);
  prpFramePull->GetYaxis()->SetTitleOffset(0.4);
  prpFramePull->GetYaxis()->SetTitleSize(0.1);
  prpFramePull->GetYaxis()->SetLabelSize(0.1);
  prpFramePull->GetYaxis()->SetTitle("Pull");
  prpFramePull->GetXaxis()->CenterTitle(kTRUE);
  prpFramePull->GetXaxis()->SetTitleOffset(1);
  prpFramePull->GetXaxis()->SetTitleSize(0.12);
  prpFramePull->GetXaxis()->SetLabelSize(0.1);
  prpFramePull->GetXaxis()->SetTitle("m_{#mu^{+}#mu^{-}} (GeV/c^{2})");
  prpFramePull->addPlotable(phPullm,"PX");
 
  // if (prpFramePull->GetMinimum()*-1 > prpFramePull->GetMaximum()) mFrameMax = prpFramePull->GetMinimum()*-1;
  // else mFrameMax = prpFramePull->GetMaximum();
  // prpFramePull->SetMaximum(mFrameMax); 
  // prpFramePull->SetMinimum(-1*mFrameMax); 
  prpFramePull->Draw();
  //plot parameters

  latex1.SetTextSize(0.085);
  double myChi2 = chi2FromRoo*Dof;
  latex1.DrawLatex(0.7,1.-ycms/3,Form("#chi^{2}/ndf = %2.1f/%d",myChi2,Dof));
  //Drawing the title
  cm.cd();
  TPad phead("phead","phead",xcms,0.91,1.,1.,0,0,0); 
  phead.Draw(); phead.cd();  
  TLatex *cms = new TLatex (xcms*3,ycms/3,"CMS");
  cms->SetTextFont(62);
  cms->SetTextSize(0.7);
  cms->Draw();
  TLatex *prelim =new TLatex(xcms*6.5,ycms/3,"Preliminary");
  prelim->SetTextFont(52);
  prelim->SetTextSize(0.4);
  prelim->Draw();
  if(chooseSample==6){  
    TLatex *sqrtS = new TLatex (xcms*14,ycms/3,"PbPb 166 #mub^{-1} (2.76 TeV)"); 
  }else if(chooseSample==7){
    TLatex *sqrtS = new TLatex (xcms*15,ycms/3,"pp 5.4 pb^{-1} (2.76 TeV)"); 
  }else{    
  }
  sqrtS->SetTextFont(42); //#sqrt{s} = 2.76 TeV
  sqrtS->SetTextSize(0.4);
  sqrtS->SetTextColor(kBlack);
  sqrtS->Draw(); 
  cm.cd();
  TPad pfoot("pfoot","pfoot",0,0,1,ycms/3,0,0,0); 
  pfoot.Draw(); pfoot.cd();  
  TLatex *mmumu = new TLatex (xcms*10,ycms*1.2,"m_{#mu#mu} [GeV/c^{2}]");
  mmumu->SetTextFont(42);
  mmumu->SetTextSize(0.5);
  mmumu->Draw();
    // output file names 
  string outPdf = outFigDir+"/"+figname_+".pdf";
  cm.SaveAs(outPdf.c_str());
  string outParameters = outDatDir+"/"+figname_+".txt";
  //string outParameters_forNote = outDatsDir+"/"+figname_+"forNote.txt";
  cout<<"Output file: " << outParameters<<endl;
  ofstream outfileFitResults;
  outfileFitResults.open(outParameters.c_str(), ios_base::out);  
  // redefinition of variables //
  RooRealVar *nsig1f   =(RooRealVar*) w.var("N_{ #varUpsilon(1S)}");
  RooRealVar *nsig2f   =(RooRealVar*) w.var("N_{ #varUpsilon(2S)}");
  RooRealVar *nsig3f   =(RooRealVar*) w.var("N_{ #varUpsilon(3S)}");
  RooRealVar *mean   =(RooRealVar*) w.var("m_{ #varUpsilon(1S)}");
  RooRealVar *sigma1   =(RooRealVar*) w.var("#sigma_{CB1}");
  RooRealVar *alpha    =(RooRealVar*) w.var("#alpha_{CB}");
  RooRealVar *npow     =(RooRealVar*) w.var("n_{CB}");
  RooRealVar *sigmaFraction = (RooRealVar*) w.var("sigmaFraction");
  RooRealVar *scaleWidth    = (RooRealVar*) w.var("#sigma_{CB2}/#sigma_{CB1}");
  RooRealVar *f2Svs1S       = (RooRealVar*) w.var("R_{#frac{2S}{1S}}");
  RooRealVar *f3Svs1S       = (RooRealVar*) w.var("R_{#frac{3S}{1S}}");
  switch(chooseFitParams) {
  case 0:
    outfileFitResults<<figname_<<" "<<nsig1f->getVal()<<" "<<nsig1f->getError()<<" "<<nsig2f->getVal()<<" "<<nsig2f->getError()<<" "<<nsig3f->getVal()<<" "<<nsig3f->getError()<<" "<<npow->getVal()<<" "<<npow->getError()<<" "<<alpha->getVal()<<" "<<alpha->getError()<<" "<<sigma1->getVal()<<" "<<sigma1->getError()<<" "<<scaleWidth->getVal()<<" "<<scaleWidth->getError()<<" "<<sigmaFraction->getVal()<<" "<< sigmaFraction->getError()<<" "<<(mean->getVal())-M1S<<" "<<mean->getError()<<" ,signif= "<<nsig1f->getVal()/nsig1f->getError()<<" "<<baseNll<< endl;
    // <<2*nFitParam+2*baseNll<<" "<<fit_2nd->edm()<<" "<<UnNormChi2<<" "<<UnNormChi2/Dof<<" "<<TMath::Prob(UnNormChi2,Dof)<<" "<<Dof<<" "<<nFitParam<<" "
    break;
  case 1 :
    cout << "option needs fixing." << endl;
    outfileFitResults<<figname_<<" "<<nsig1f->getVal()<<" "<<nsig1f->getError()<<" "<<f2Svs1S->getVal()<<" "<<f2Svs1S->getError()<<" "<<f3Svs1S->getVal()<<" "<<f3Svs1S->getError()<<" "<<npow->getVal()<<" "<<npow->getError()<<" "<<alpha->getVal()<<" "<<alpha->getError()<<" "<<sigma1->getVal()<<" "<<sigma1->getError()<<" "<<scaleWidth->getVal()<<" "<<scaleWidth->getError()<<" "<<sigmaFraction->getVal()<<" "<< sigmaFraction->getError()<<" "<<(mean->getVal())-M1S<<" "<<mean->getError()<<" ,signif= "<<nsig1f->getVal()/nsig1f->getError()<<" "<<baseNll<< endl;
    //<<2*nFitParam+2*baseNll<<" "<<fit_2nd->edm()<<" "<<UnNormChi2<<" "<<UnNormChi2/Dof<<" "<<TMath::Prob(UnNormChi2,Dof)<<" "<<Dof<<" "<<nFitParam<<" "
    break;
  case 2 :
    cout << "option needs fixing." << endl;
    outfileFitResults<<figname_<<" "<<nsig1f->getVal()<<" "<<nsig1f->getError()<<" "<<f2Svs1S->getVal()<<" "<<f2Svs1S->getError()<<" "<<f23vs1S->getVal()<<" "<<f23vs1S->getError()<<" "<<npow->getVal()<<" "<<npow->getError()<<" "<<alpha->getVal()<<" "<<alpha->getError()<<" "<<sigma1->getVal()<<" "<<sigma1->getError()<<" "<<scaleWidth->getVal()<<" "<<scaleWidth->getError()<<" "<<sigmaFraction->getVal()<<" "<< sigmaFraction->getError()<<" "<<(mean->getVal())-M1S<<" "<<mean->getError()<<" ,signif= "<<nsig1f->getVal()/nsig1f->getError()<<" "<<baseNll<< endl;
    //<<2*nFitParam+2*baseNll<<" "<<fit_2nd->edm()<<" "<<UnNormChi2<<" "<<UnNormChi2/Dof<<" "<<TMath::Prob(UnNormChi2,Dof)<<" "<<Dof<<" "<<nFitParam<<" "
    break;
  case 3 :
    cout << "option needs fixing." << endl;
    outfileFitResults<<figname_<<" "<<nsig1f->getVal()<<" "<<nsig1f->getError()<<" "<<f2Svs1S->getVal()<<" "<<f2Svs1S->getError()<<" "<<f3Svs1S->getVal()<<" "<<f3Svs1S->getError()<<" "<<f3Svs2S->getVal()<<" "<<f3Svs2S->getError()<<" "<<alpha->getVal()<<" "<<alpha->getError()<<" "<<sigma1->getVal()<<" "<<sigma1->getError()<<" "<<scaleWidth->getVal()<<" "<<scaleWidth->getError()<<" "<<sigmaFraction->getVal()<<" "<< sigmaFraction->getError()<<" "<<(mean->getVal())-M1S<<" "<<mean->getError()<<" ,signif= "<<nsig1f->getVal()/nsig1f->getError()<<" "<<baseNll<< endl;
    //<<2*nFitParam+2*baseNll<<" "<<fit_2nd->edm()<<" "<<UnNormChi2<<" "<<UnNormChi2/Dof<<" "<<TMath::Prob(UnNormChi2,Dof)<<" "<<Dof<<" "<<nFitParam<<" "
    break;
  default : break;
  }
  outfileFitResults.close();
}

