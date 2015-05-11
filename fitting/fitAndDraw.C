void fitAndDraw(RooWorkspace& w){
  RooRealVar* mass =(RooRealVar*) w.var("invariantMass"); //
  RooDataSet* data0_fit =(RooDataSet*) w.data("data");
  RooAbsPdf* pdf = (RooAbsPdf*) w.pdf("pdf");
  int nbins = ceil((mass_h-mass_l)/binw); // all of which are 'globally' defined in the .h header
  RooPlot* frame = mass->frame(Bins(nbins),Range(mass_l,mass_h));  
  data0_fit->plotOn(frame);
  pdf->plotOn(frame,Name("thePdf"));
  frame->Draw();

  // frame->SetTitle("");
  // frame->GetXaxis()->SetTitle("m_{#mu^{+}#mu^{-}} (GeV/c^{2})");
  // frame->GetXaxis()->CenterTitle(kTRUE);
  // frame->GetYaxis()->SetTitleOffset(1.3);
  // //Draw stuff!
  // TCanvas cm("cm","cm");
  // cm.cd();
  // TPad *pPad1 = new TPad("pPad1","pPad1",0.01,0.3-0.03,0.96,0.96);
  // pPad1->SetBottomMargin(0.03);
  // pPad1->Draw();
  // pPad1->cd();
  // _ws::pdf.paramOn(frame,Layout(0.6,0.935,0.97));
  // pPad1->Update();
  // frame->Draw();
  // cm.SaveAs("_pulls.pdf");
}
