void fitAndDraw(RooWorkspace& w, TString figname_, TString outDatDir ,  TString outFigDir, int chooseFitParams){
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
  data0_fit->plotOn(frame) ;// drawing data pts over pdf line (looks best).
  frame->SetTitle("");
  frame->GetXaxis()->SetTitle("m_{#mu^{+}#mu^{-}} (GeV/c^{2})");
  frame->GetXaxis()->CenterTitle(kTRUE);
  frame->GetYaxis()->SetTitleOffset(1.3);
  //Draw stuff!
  TCanvas cm("cm","cm");
  cm.cd();
  TPad *pPad1 = new TPad("pPad1","pPad1",0.01,0.3-0.03,0.96,0.96);
  pPad1->SetBottomMargin(0.03);
  pPad1->Draw();
  pPad1->cd();
  pdf->paramOn(frame,Layout(0.6,0.935,0.97));
  pPad1->Update();
  frame->Draw();
  cm.SaveAs("_pulls.pdf");
  // output file names 
  string outParameters = outDatDir+"/"+figname_+".txt";
  //string outParameters_forNote = outDatsDir+"/"+figname_+"forNote.txt";
  cout<<"Output file: " << outParameters<<endl;
  ofstream outfileFitResults;
  outfileFitResults.open(outParameters.c_str(), ios_base::out);  
  // redefinition of variables //
  RooRealVar *nsig1f   =(RooRealVar*) w.var("N_{#Upsilon(1S)}");
  RooRealVar *nsig2f   =(RooRealVar*) w.var("N_{#Upsilon(2S)}");
  RooRealVar *nsig3f   =(RooRealVar*) w.var("N_{#Upsilon(3S)}");
  RooRealVar *mean   =(RooRealVar*) w.var("m_{#mu#mu;fit}");
  RooRealVar *sigma1   =(RooRealVar*) w.var("#sigma_{CB1}");
  RooRealVar *alpha    =(RooRealVar*) w.var("#alpha_{CB}");
  RooRealVar *npow     =(RooRealVar*) w.var("n_{CB}");
  RooRealVar *sigmaFraction = (RooRealVar*) w.var("sigmaFraction");
  RooRealVar *scaleWidth    = (RooRealVar*) w.var("#sigma_{CB2}/#sigma_{CB1}");
  RooRealVar *f2Svs1S       = (RooRealVar*) w.var("R_{#frac{2S}{1S}}");
  RooRealVar *f3Svs1S       = (RooRealVar*) w.var("R_{#frac{3S}{1S}}");
  switch(chooseFitParams) {
  case 0:
    outfileFitResults<<figname_<<" "<<nsig1f->getVal()<<" "<<nsig1f->getError()<<" "<<nsig2f->getVal()<<" "<<nsig2f->getError()<<" "<<nsig3f->getVal()<<" "<<nsig3f->getError()<<" "<<npow->getVal()<<" "<<npow->getError()<<" "<<alpha->getVal()<<" "<<alpha->getError()<<" "<<sigma1->getVal()<<" "<<sigma1->getError()<<" "<<scaleWidth->getVal()<<" "<<scaleWidth->getError()<<" "<<sigmaFraction->getVal()<<" "<< sigmaFraction->getError()<<" "<<(mean->getVal())-M1S<<" "<<mean->getError()<<" "<<baseNll<< endl;
    // <<2*nFitParam+2*baseNll<<" "<<fit_2nd->edm()<<" "<<UnNormChi2<<" "<<UnNormChi2/Dof<<" "<<TMath::Prob(UnNormChi2,Dof)<<" "<<Dof<<" "<<nFitParam<<" "
    break;
  case 1 :
    cout << "option needs fixing." << endl;
    outfileFitResults<<figname_<<" "<<nsig1f->getVal()<<" "<<nsig1f->getError()<<" "<<f2Svs1S->getVal()<<" "<<f2Svs1S->getError()<<" "<<f3Svs1S->getVal()<<" "<<f3Svs1S->getError()<<" "<<npow->getVal()<<" "<<npow->getError()<<" "<<alpha->getVal()<<" "<<alpha->getError()<<" "<<sigma1->getVal()<<" "<<sigma1->getError()<<" "<<baseNll<<endl;
    //<<2*nFitParam+2*baseNll<<" "<<fit_2nd->edm()<<" "<<UnNormChi2<<" "<<UnNormChi2/Dof<<" "<<TMath::Prob(UnNormChi2,Dof)<<" "<<Dof<<" "<<nFitParam<<" "
    break;
  case 2 :
    cout << "option needs fixing." << endl;
    outfileFitResults<<figname_<<" "<<nsig1f->getVal()<<" "<<nsig1f->getError()<<" "<<f2Svs1S->getVal()<<" "<<f2Svs1S->getError()<<" "<<f23vs1S->getVal()<<" "<<f23vs1S->getError()<<" "<<npow->getVal()<<" "<<npow->getError()<<" "<<alpha->getVal()<<" "<<alpha->getError()<<" "<<sigma1->getVal()<<" "<<sigma1->getError()<<" "<<baseNll<< endl;
    //<<2*nFitParam+2*baseNll<<" "<<fit_2nd->edm()<<" "<<UnNormChi2<<" "<<UnNormChi2/Dof<<" "<<TMath::Prob(UnNormChi2,Dof)<<" "<<Dof<<" "<<nFitParam<<" "
    break;
  case 3 :
    cout << "option needs fixing." << endl;
    outfileFitResults<<figname_<<" "<<nsig1f->getVal()<<" "<<nsig1f->getError()<<" "<<f2Svs1S->getVal()<<" "<<f2Svs1S->getError()<<" "<<f3Svs1S->getVal()<<" "<<f3Svs1S->getError()<<" "<<f3Svs2S->getVal()<<" "<<f3Svs2S->getError()<<" "<<alpha->getVal()<<" "<<alpha->getError()<<" "<<sigma1->getVal()<<" "<<sigma1->getError()<<" "<<baseNll<<  endl;
    //<<2*nFitParam+2*baseNll<<" "<<fit_2nd->edm()<<" "<<UnNormChi2<<" "<<UnNormChi2/Dof<<" "<<TMath::Prob(UnNormChi2,Dof)<<" "<<Dof<<" "<<nFitParam<<" "
    break;
  default : break;
  }
  outfileFitResults.close();
}

