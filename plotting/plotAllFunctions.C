//#include "headerForTNP.h"
#include "headerForTNP_extended.h"
 double myFunc(double *x, double *par){
   Float_t xx =x[0];
   double f; 
   // par[0] is the normalisation;
   // par[1] is the mu_data;
   // par[2] is the sigma_data;
   // par[3] is the index in the array : 0 is the nominal case, 1-101 are the 100 variations.
   // par[4] is the Abs(eta) region : 0 is barrel, 1 is endcap muons.
   // par[5] is the collision type : 0 is pp, 1 is pbpb.

   ///let's go:
   if(par[5]>0){ //doing pbpb first,
     if(par[4]<1) { // barrel,
       if(par[3]<1) { // nominal 
	 f = (par[0]*TMath::Erf((xx-par[1])/par[2]))/ (0.9576*TMath::Erf((xx-1.7883)/2.6583)); //(TMath::Erf((xx-1.7960)/2.5160)); //OK!
       }
       if(par[3]>0){ // variations
       	 f =   (par[0]*TMath::Erf((xx-par[1])/par[2])/(0.9576*TMath::Erf((xx-1.7883)/2.6583)));  ///OK! 
       }
     }
     if(par[4]>0){// endcap,
       if(par[3]<1) { // nominal case
     	 f = (par[0]*TMath::Erf((xx-par[1])/par[2]))/(0.7948*TMath::Erf((xx-1.3091)/2.2783)); //(0.7810*TMath::Erf((xx-1.3609)/2.1231));
       }
       if(par[3]>0){ // variations
       	 f =   (par[0]*TMath::Erf((xx-par[1])/par[2])/(0.7948*TMath::Erf((xx-1.3091)/2.2783))); ///  (0.7948*TMath::Erf((xx-1.3091)/2.2783))); //  should check why the variations had this numerator.
       }
     }
   }
   if(par[5]<1){ //doing pp now,
     if(par[4]<1) { // barrel,
       if(par[3]<1) { // nominal 
	 f =   (par[0]*TMath::Erf((xx-par[1])/par[2]))/(0.9604*TMath::Erf((xx-2.0586)/2.1567));// (TMath::Erf((xx-1.7960)/2.5160)); //OK!
       }
       if(par[3]>0){ // variations
       	 f =   (par[0]*TMath::Erf((xx-par[1])/par[2]))/ (0.9604*TMath::Erf((xx-2.0586)/2.1567));  /// new one matches what dongho had in the variations.
       }
     }
     if(par[4]>0){// endcap,
       if(par[3]<1) { // nominal case
     	 f = (par[0]*TMath::Erf((xx-par[1])/par[2]))/(0.7364*TMath::Erf((xx-1.2149)/2.3352));//(0.7364*TMath::Erf((xx-1.2538)/2.2530)); this is the old one...
       }
       if(par[3]>0){ // variations
       	 f =   (par[0]*TMath::Erf((xx-par[1])/par[2]))/ (0.7364*TMath::Erf((xx-1.2149)/2.3352));  ///
       }
     }
   }
   return f;
   
   //pbpb midrap
   //
   //
   
   //pbpb fwdrap
   //j>0  (0.7810*TMath::Erf((x-1.3609)/2.1231))
   //j=0  (0.8299*TMath::Erf((pt-1.2785)/1.8833))/(0.7810*TMath::Erf((pt-1.3609)/2.1231)  
   
   //pp midrap
   //j>0  (0.9604*TMath::Erf((x-2.0583)/2.1573))
   //j=0  (0.998474*TMath::Erf((pt-1.63555)/(0.797933))/TMath::Erf((pt-0.222866)/(2.95593)))

   //pp fwd
   //j>0 (0.7364*TMath::Erf((x-1.2149)/2.3352))
   //j=0 (0.7788*TMath::Erf((pt-1.1903)/1.9880))/(0.7364*TMath::Erf((pt-1.2538)/2.2530))
 }

double myNumerator( double *x, double *par){
  double f;
  double xx = x[0];
    ///let's go:
   if(par[5]>0){ //doing pbpb first,
     if(par[4]<1) { // barrel,
       if(par[3]<1) { // nominal 
	 f = (par[0]*TMath::Erf((xx-par[1])/par[2]));
       }
       if(par[3]>0){ // variations
       	 f =   (par[0]*TMath::Erf((xx-par[1])/par[2]));  /// 
       }
     }
     if(par[4]>0){// endcap,
       if(par[3]<1) { // nominal case
     	 f = (par[0]*TMath::Erf((xx-par[1])/par[2]));
       }
       if(par[3]>0){ // variations
       	 f =   (par[0]*TMath::Erf((xx-par[1])/par[2]));  /// 
       }
     }
   }
   if(par[5]<1){ //doing pp now,
     if(par[4]<1) { // barrel,
       if(par[3]<1) { // nominal 
	 f =   (par[0]*TMath::Erf((xx-par[1])/par[2]));
       }
       if(par[3]>0){ // variations
       	 f =   (par[0]*TMath::Erf((xx-par[1])/par[2]));  /// 
       }
     }
     if(par[4]>0){// endcap,
       if(par[3]<1) { // nominal case
     	 f = (par[0]*TMath::Erf((xx-par[1])/par[2]));
       }
       if(par[3]>0){ // variations
       	 f =   (par[0]*TMath::Erf((xx-par[1])/par[2]));  /// 
       }
     }
   }
  return f;
}
void plotAllFunctions()
{
  double pbpb=1;  // if pbpb=0, you're doing pp.
  double endcap=0;//if endcap=0, you're doing barrel ;)
  int j=0;     // cool increment.
  bool doOnlyNumerator= true;
  // /// ...the classic ones... // ///
  TCanvas *cBarrel_pbpb = new TCanvas ("cBarrel_pbpb","cBarrel_pbpb",1400,700);
  cBarrel_pbpb->Divide(2);
  cBarrel_pbpb->cd(1);
  TF1 *f1 = new TF1("Tag and Probe and variations",myFunc,0,20,6);
  if (doOnlyNumerator){ f1= new TF1("myFunk",myNumerator,0,20,6);}
  cout << j << endl;
  cout << endcap << endl;
  f1->SetParameters(alpha_pbpb_midrap[j],mu_data_pbpb_midrap[j],sigma_data_pbpb_midrap[j],j,endcap,pbpb);
  f1->SetRange(3.5,20);
  if(!doOnlyNumerator){ f1->GetYaxis()->SetRangeUser(0.6,1.8); }
  else if(doOnlyNumerator){   f1->GetYaxis()->SetRangeUser(0.0,1.5); }
  f1->Draw();
  std::cout << "NOMINAL pbpb midrap" << std::endl; 
  std::cout << alpha_pbpb_midrap[j] <<"*TMath::Erf((x-"<< mu_data_pbpb_midrap[j] <<")/"<<sigma_data_pbpb_midrap[j]<<") / (0.9576*TMath::Erf((x-1.7883)/2.6583))"<<std::endl;

  //systematic variations on top
  j=0;
  TF1 *fS1 = new TF1("Systematic variations",myFunc,0,20,6);
  if (doOnlyNumerator){ fS1= new TF1("myFunk",myNumerator,0,20,6);}
  cout << j << endl;
  cout << endcap << endl;
  fS1->SetParameters(alpha_pbpb_midrap_syst[j],mu_data_pbpb_midrap_syst[j],sigma_data_pbpb_midrap_syst[j],j,endcap,pbpb);
  fS1->SetRange(3.5,20);//midrapidity pt limit >3.4 GeV
  if(!doOnlyNumerator){ fS1->GetYaxis()->SetRangeUser(0.6,1.8); }
  else if(doOnlyNumerator){   fS1->GetYaxis()->SetRangeUser(0.0,1.5); }
  fS1->SetLineColor(kBlack);
  //  fS1->Draw();
  std::cout << "SYSTEMATICS pbpb midrap" << std::endl; 
  std::cout << alpha_pbpb_midrap_syst[j] <<"*TMath::Erf((x-"<< mu_data_pbpb_midrap_syst[j] <<")/"<<sigma_data_pbpb_midrap_syst[j]<<") / (0.9576*TMath::Erf((x-1.7885)/2.6587))"<<std::endl;
  std::cout << "Systematic variations on the pbpb midrap" << std::endl; 
  for(j=1;j< 101;j++){
    fSb = new TF1("Tag and Probe and variations",myFunc,0,20,6);
    if (doOnlyNumerator){ fSb= new TF1("myFunk",myNumerator,0,20,6);}
    //  fSb->SetRange(0,20);
    std::cout <<alpha_pbpb_midrap_syst[j] <<"*TMath::Erf((x-"<< mu_data_pbpb_midrap_syst[j] <<"/"<<sigma_data_pbpb_midrap_syst[j]<<")) / (0.9576*TMath::Erf((x-1.7883)/2.6583))"<<std::endl;
    fSb->SetParameters(alpha_pbpb_midrap_syst[j],mu_data_pbpb_midrap_syst[j],sigma_data_pbpb_midrap_syst[j],j,endcap,pbpb);
    fSb->SetLineColor(kOrange+1);
    fSb->Draw("same");
   }

  for(j=1;j< 101;j++){
    //reminder:
    // p[0] is the normalisation;
    // p[1] is the mu_data;
    // p[2] is the sigma_data;
    // p[3] is the index in the array : 0 is the nominal case, 1-101 are the 100 variations.
    // p[4] is the Abs(eta) region : 0 is barrel, 1 is endcap muons.
    // p[5] is the collision type : 0 is pp, 1 is pbpb.
    fb = new TF1("myfunc",myFunc,0,20,6);
    if (doOnlyNumerator){ fb= new TF1("myFunk",myNumerator,0,20,6);}
    //  fb->SetRange(0,20);
    std::cout << j << alpha_pbpb_midrap[j] <<"*TMath::Erf((x-"<< mu_data_pbpb_midrap[j] <<"/"<<sigma_data_pbpb_midrap[j]<<")) / (0.9576*TMath::Erf((x-1.7883)/2.6583))"<<std::endl;
    fb->SetParameters(alpha_pbpb_midrap[j],mu_data_pbpb_midrap[j],sigma_data_pbpb_midrap[j],j,endcap,pbpb);
    fb->SetLineColor(kAzure+1);
    fb->Draw("same");
  }
  if (doOnlyNumerator){ f1->GetYaxis()->SetTitle("#epsilon^{#mu}_{DATA}"); }
 else { f1->GetYaxis()->SetTitle("Scale Factor");}
  f1->GetYaxis()->SetTitleOffset(1.3);
  f1->GetXaxis()->SetTitle("Probe p_{T} [GeV/c]");
  f1->GetXaxis()->CenterTitle(kTRUE);
  f1->GetXaxis()->SetTitleOffset(1.3);
  fS1->Draw("same");
  f1->Draw("same");
  TLegend *legend = new TLegend(0.2,0.66,0.9,0.88);
  legend->SetTextSize(0.038);
  legend->SetFillStyle(0);
  legend->SetFillColor(0);
  legend->SetBorderSize(0);
  legend->SetTextFont(42);
  if(!doOnlyNumerator){ 
  legend->AddEntry(f1,"PbPb |#eta^{#mu}| < 1.6 ","");
  legend->AddEntry(f1,"Nominal T&P function  ","lp");
  legend->AddEntry(fb,"100 stat. variations","lp");
  legend->AddEntry(fS1,"Nominal function, 'new' settings ","lp");
  legend->AddEntry(fSb,"100 stat.+syst. variations ","lp");
  }
  
  else{
  legend->AddEntry(f1,"PbPb  |#eta^{#mu}| < 1.6","");
  legend->AddEntry(f1," #varepsilon^{DATA}_{#mu},nominal","lp");
  legend->AddEntry(fb,"100 stat. variations ","lp");
  legend->AddEntry(fS1,"Nominal function, 'new' settings ","lp");
  legend->AddEntry(fSb,"100 stat.+syst. variations ","lp");
  }
  legend->Draw();

  //endcap pbpb:  (0.8299*TMath::Erf((pt-1.2785)/1.8833))/(0.7810*TMath::Erf((pt-1.3609)/2.1231))
  cBarrel_pbpb->cd(2);
  endcap=1;
  TF1 *f2 = new TF1("Tag and Probe and variations",myFunc,0,20,6);
  if (doOnlyNumerator){ f2= new TF1("myFunk",myNumerator,0,20,6);}
  j=0; // reset!
  f2->SetParameters(alpha_pbpb_fwdrap[j],mu_data_pbpb_fwdrap[j],sigma_data_pbpb_fwdrap[j],j,endcap,pbpb);
  f2->SetRange(3.5,20);
  if(!doOnlyNumerator){   f2->GetYaxis()->SetRangeUser(0.8,1.5); }
  else if(doOnlyNumerator){   f2->GetYaxis()->SetRangeUser(0.0,1.5); }
  f2->Draw();
  std::cout << "NOMINAL pbpb fwdrap" << std::endl; 
  std::cout << alpha_pbpb_fwdrap[j] <<"*TMath::Erf((x-"<< mu_data_pbpb_fwdrap[j] <<"/"<<sigma_data_pbpb_fwdrap[j]<<")) /(0.7948*TMath::Erf((x-1.3091)/2.2783))"<<std::endl;

 //systematic variations on top
  j=0; 
  TF1 *fs2 = new TF1("Systematic variations",myFunc,0,20,6);
  if (doOnlyNumerator){ fs2= new TF1("myFunk",myNumerator,0,20,6);}
  cout << j << endl;
  cout << endcap << endl;
  fs2->SetParameters(alpha_data_pbpb_fwdrap_syst[j],mu_data_pbpb_fwdrap_syst[j],sigma_data_pbpb_fwdrap_syst[j],j,endcap,pbpb);
  fs2->SetRange(3.5,20);//fwdrapidity pt limit >3.4 GeV
  if(!doOnlyNumerator){ fs2->GetYaxis()->SetRangeUser(0.6,1.8); }
  else if(doOnlyNumerator){   fs2->GetYaxis()->SetRangeUser(0.0,1.8); }
  fs2->SetLineColor(kBlack);
  fs2->Draw();
  std::cout << "SYSTEMATICS pbpb fwdrap" << std::endl; 
  std::cout << alpha_data_pbpb_fwdrap_syst[j] <<"*TMath::Erf((x-"<< mu_data_pbpb_fwdrap_syst[j] <<")/"<<sigma_data_pbpb_fwdrap_syst[j]<<") / (0.9576*TMath::Erf((x-1.7885)/2.6587))"<<std::endl;
  std::cout << "Systematic variations on the pbpb fwdrap" << std::endl; 
  for(j=1;j< 101;j++){
    fSe = new TF1("Tag and Probe and variations",myFunc,0,20,6);
    if (doOnlyNumerator){ fSe= new TF1("myFunk",myNumerator,0,20,6);}
    //  fSe->SetRange(0,20);
    std::cout <<alpha_data_pbpb_fwdrap_syst[j] <<"*TMath::Erf((x-"<< mu_data_pbpb_fwdrap_syst[j] <<"/"<<sigma_data_pbpb_fwdrap_syst[j]<<")) / (0.9576*TMath::Erf((x-1.7883)/2.6583))"<<std::endl;
    fSe->SetParameters(alpha_data_pbpb_fwdrap_syst[j],mu_data_pbpb_fwdrap_syst[j],sigma_data_pbpb_fwdrap_syst[j],j,endcap,pbpb);
    fSe->SetLineColor(kOrange+1);
    fSe->Draw("same");
   }

  std::cout << "variations on the pbpb fwdrap" << std::endl; 
  for(j=1;j< 101;j++){
    //reminder:
    // p[0] is the normalisation;
    // p[1] is the mu_data;
    // p[2] is the sigma_data;
    // p[3] is the index in the array : 0 is the nominal case, 1-101 are the 100 variations.
    // p[4] is the Abs(eta) region : 0 is barrel, 1 is endcap muons.
    // p[5] is the collision type : 0 is pp, 1 is pbpb.
    fe = new TF1("Tag and Probe and variations",myFunc,0,20,6);
    if (doOnlyNumerator){ fe= new TF1("myFunk",myNumerator,0,20,6);}
    fe->SetRange(3.5,20);
    std::cout  << alpha_pbpb_fwdrap[j] <<"*TMath::Erf((x-"<< mu_data_pbpb_fwdrap[j] <<"/"<<sigma_data_pbpb_fwdrap[j]<<")) /(0.7948*TMath::Erf((x-1.3091)/2.2783))"<<std::endl;
    // cout << f << endl;
    fe->SetParameters(alpha_pbpb_fwdrap[j],mu_data_pbpb_fwdrap[j],sigma_data_pbpb_fwdrap[j],j,endcap,pbpb);
    fe->SetLineColor(kAzure+1);
    fe->Draw("same");
  }

  if (doOnlyNumerator){ fs2->GetYaxis()->SetTitle("#epsilon^{#mu}_{DATA}"); }
  else{  fs2->GetYaxis()->SetTitle("Scale Factor");}
  fs2->GetYaxis()->SetTitleOffset(1.3);
  fs2->GetXaxis()->SetTitle("Probe p_{T} [GeV/c]");
  f2->GetXaxis()->CenterTitle(kTRUE);
  fs2->GetXaxis()->SetTitleOffset(1.3);
  fs2->Draw("same");
  f2->Draw("same");
  TLegend *leg2 = new TLegend(0.2,0.66,0.9,0.88);
  leg2->SetTextSize(0.038);
  leg2->SetFillStyle(0);
  leg2->SetFillColor(0);
  leg2->SetBorderSize(0);
  leg2->SetTextFont(42);
  if(!doOnlyNumerator){ 
    leg2->AddEntry(f2,"PbPb 1.6 < |#eta^{#mu}| < 2.4  ","");
    leg2->AddEntry(f2,"Nominal T&P function  ","lp");
    leg2->AddEntry(fe,"100 stat. variations","lp");
    leg2->AddEntry(fs2,"Nominal function, 'new' settings ","lp");
    leg2->AddEntry(fSe,"100 stat.+syst. variations ","lp");
  }
  else{
    leg2->AddEntry(f2,"PbPb 1.6 < |#eta^{#mu}| < 2.4","");
    leg2->AddEntry(f2,"#varepsilon^{DATA}_{#mu}","lp");
    leg2->AddEntry(fe,"100 T&P stat. variations","lp");
    leg2->AddEntry(fs2,"Nominal function, 'new' settings ","lp");
    leg2->AddEntry(fSe,"100 stat.+syst. variations ","lp");
  }
  leg2->Draw();

  if(!doOnlyNumerator){  cBarrel_pbpb->SaveAs("~/Desktop/Grenelle/TNP_pbpb_100variations_newSettings_15-001.pdf");}
  else{ cBarrel_pbpb->SaveAs("~/Desktop/Grenelle/numerator_variations_15-001.pdf");}

 
 
  pbpb=0;
  endcap=0;
  j=0;
 
  TCanvas *cBarrel_pp = new TCanvas ("cBarrel_pp","cBarrel_pp",1400,700);
  cBarrel_pp->Divide(2);
  cBarrel_pp->cd(1);
  TF1 *g1 = new TF1("Tag and Probe and variations",myFunc,0,20,6);
  if (doOnlyNumerator){ g1= new TF1("myFunk",myNumerator,0,20,6);}
  cout << j << endl;
  cout << endcap << endl;
  g1->SetParameters(alpha_pp_midrap[j],mu_data_pp_midrap[j],sigma_data_pp_midrap[j],j,endcap,pbpb);
  g1->SetRange(3.5,20);
  if(!doOnlyNumerator){   g1->GetYaxis()->SetRangeUser(0.8,1.5); }
  else if(doOnlyNumerator){   g1->GetYaxis()->SetRangeUser(0.0,1.5); }
  g1->Draw();
  std::cout << "NOMINAL pp midrap" << std::endl; 
  std::cout << alpha_pp_midrap[j] <<"*TMath::Erf((x-"<< mu_data_pp_midrap[j] <<"/"<<sigma_data_pp_midrap[j]<<")) / (0.9604*TMath::Erf((x-2.0586)/2.1567))"<<std::endl;

 //systematic variations on top
  j=0;
  TF1 *fS1_pp = new TF1("Systematic variations",myFunc,0,20,6);
  if (doOnlyNumerator){ fS1_pp= new TF1("myFunk",myNumerator,0,20,6);}
  cout << j << endl;
  cout << endcap << endl;
  fS1_pp->SetParameters(alpha_data_pp_midrap_syst[j],mu_data_pp_midrap_syst[j],sigma_data_pp_midrap_syst[j],j,endcap,pbpb);
  fS1_pp->SetRange(3.5,20);//midrapidity pt limit >3.4 GeV
  if(!doOnlyNumerator){ fS1_pp->GetYaxis()->SetRangeUser(0.8,1.5); }
  else if(doOnlyNumerator){   fS1_pp->GetYaxis()->SetRangeUser(0.0,1.5); }
  fS1_pp->SetLineColor(kBlack);
  fS1_pp->Draw();
  std::cout << "SYSTEMATICS pp midrap" << std::endl; 
  std::cout << alpha_data_pp_midrap_syst[j] <<"*TMath::Erf((x-"<< mu_data_pp_midrap_syst[j] <<")/"<<sigma_data_pp_midrap_syst[j]<<") / (0.9576*TMath::Erf((x-1.7885)/2.6587))"<<std::endl;
  std::cout << "Systematic variations on the pp midrap" << std::endl; 
  for(j=1;j< 101;j++){
    fSb_pp = new TF1("Tag and Probe and variations",myFunc,0,20,6);
    if (doOnlyNumerator){ fSb_pp= new TF1("myFunk",myNumerator,0,20,6);}
    //  fSb_pp->SetRange(0,20);
    std::cout <<alpha_data_pp_midrap_syst[j] <<"*TMath::Erf((x-"<< mu_data_pp_midrap_syst[j] <<"/"<<sigma_data_pp_midrap_syst[j]<<")) / (0.9576*TMath::Erf((x-1.7883)/2.6583))"<<std::endl;
    fSb_pp->SetParameters(alpha_data_pp_midrap_syst[j],mu_data_pp_midrap_syst[j],sigma_data_pp_midrap_syst[j],j,endcap,pbpb);
    fSb_pp->SetLineColor(kOrange+1);
    fSb_pp->Draw("same");
   }



  std::cout << "variations on the pp midrap" << std::endl; 
  for(j=1;j< 101;j++){
    //reminder:
    // p[0] is the normalisation;
    // p[1] is the mu_data;
    // p[2] is the sigma_data;
    // p[3] is the index in the array : 0 is the nominal case, 1-101 are the 100 variations.
    // p[4] is the Abs(eta) region : 0 is barrel, 1 is endcap muons.
    // p[5] is the collision type : 0 is pp, 1 is pp.
    gb = new TF1("Tag and Probe and variations",myFunc,0,20,6);
    if (doOnlyNumerator){ gb= new TF1("myFunk",myNumerator,0,20,6);}
    //  gb->SetRange(0,20);
    std::cout  << alpha_pp_midrap[j] <<"*TMath::Erf((x-"<< mu_data_pp_midrap[j] <<"/"<<sigma_data_pp_midrap[j]<<")) / (0.9604*TMath::Erf((x-2.0586)/2.1567))"<<std::endl;
    gb->SetParameters(alpha_pp_midrap[j],mu_data_pp_midrap[j],sigma_data_pp_midrap[j],j,endcap,pbpb);
    gb->SetLineColor(kAzure+1);
    gb->Draw("same");
   }


  if (doOnlyNumerator){ fS1_pp->GetYaxis()->SetTitle("#epsilon^{#mu}_{DATA}"); }
  else{  fS1_pp->GetYaxis()->SetTitle("Scale Factor");}
  fS1_pp->GetYaxis()->SetTitleOffset(1.3);
  fS1_pp->GetXaxis()->SetTitle("Probe p_{T} [GeV/c]");
  fS1_pp->GetXaxis()->CenterTitle(kTRUE);
  fS1_pp->GetXaxis()->SetTitleOffset(1.3);
  g1->Draw("same");
  fS1_pp->Draw("same");
  TLegend *legend = new TLegend(0.2,0.66,0.9,0.88);
  legend->SetTextSize(0.038);
  legend->SetFillStyle(0);
  legend->SetFillColor(0);
  legend->SetBorderSize(0);
  legend->SetTextFont(42);
  if(!doOnlyNumerator){ 
    // legend->AddEntry(g1,"pp ","");
    // legend->AddEntry(g1,"Nominal T&P scaling: |#eta^{#mu}| < 1.6 ","lp");
    // legend->AddEntry(gb,"100 T&P stat. variations: |#eta^{#mu}| < 1.6 ","lp");

    legend->AddEntry(g1,"pp  |#eta^{#mu}| < 1.6  ","");
    legend->AddEntry(g1,"Nominal T&P function  ","lp");
    legend->AddEntry(gb,"100 stat. variations","lp");
    legend->AddEntry(fS1_pp,"Nominal function, 'new' settings ","lp");
    legend->AddEntry(fSb_pp,"100 stat.+syst. variations ","lp");

  }
  else{
    legend->AddEntry(g1,"pp  |#eta^{#mu}| < 1.6 ","");
    legend->AddEntry(g1,"#varepsilon^{DATA}_{#mu} ","lp");
    legend->AddEntry(gb,"100 stat. variations ","lp");
    legend->AddEntry(fS1_pp,"Nominal function, 'new' settings ","lp");
    legend->AddEntry(fSb_pp,"100 stat.+syst. variations ","lp");
  } 
  legend->Draw();

  //endcap pp:  (0.8299*TMath::Erf((pt-1.2785)/1.8833))/(0.7810*TMath::Erf((pt-1.3609)/2.1231))
  cBarrel_pp->cd(2);
  endcap=1;
  TF1 *g2 = new TF1("Tag and Probe and variations",myFunc,0,20,6);
  if (doOnlyNumerator){ g2= new TF1("myFunk",myNumerator,0,20,6);}
  j=0; // reset!
  g2->SetParameters(alpha_pp_fwdrap[j],mu_data_pp_fwdrap[j],sigma_data_pp_fwdrap[j],j,endcap,pbpb);
  g2->SetRange(3.5,20);
  if(!doOnlyNumerator){   g2->GetYaxis()->SetRangeUser(0.8,1.5); }
  else if(doOnlyNumerator){   g2->GetYaxis()->SetRangeUser(0.0,1.5); }
  g2->Draw();
  std::cout << "NOMINAL pp fwdrap" << std::endl; 
  std::cout << alpha_pp_fwdrap[j] <<"*TMath::Erf((x-"<< mu_data_pp_fwdrap[j] <<"/"<<sigma_data_pp_fwdrap[j]<<")) / (0.7364*TMath::Erf((x-1.2149)/2.3352)) "<<std::endl;

 //systematic variations on top
  j=0;
  TF1 *f21_pp = new TF1("Systematic variations",myFunc,0,20,6);
  if (doOnlyNumerator){ f21_pp= new TF1("myFunk",myNumerator,0,20,6);}
  cout << j << endl;
  cout << endcap << endl;
  f21_pp->SetParameters(alpha_data_pp_fwdrap_syst[j],mu_data_pp_fwdrap_syst[j],sigma_data_pp_fwdrap_syst[j],j,endcap,pbpb);
  f21_pp->SetRange(3.5,20);//fwdrapidity pt limit >3.4 GeV
  if(!doOnlyNumerator){ f21_pp->GetYaxis()->SetRangeUser(0.8,1.5); }
  else if(doOnlyNumerator){   f21_pp->GetYaxis()->SetRangeUser(0.0,1.5); }
  f21_pp->SetLineColor(kBlack);
  f21_pp->Draw();
  std::cout << "SYSTEMATICS pp fwdrap" << std::endl; 
  std::cout << alpha_data_pp_fwdrap_syst[j] <<"*TMath::Erf((x-"<< mu_data_pp_fwdrap_syst[j] <<")/"<<sigma_data_pp_fwdrap_syst[j]<<") / (0.9576*TMath::Erf((x-1.7885)/2.6587))"<<std::endl;
  std::cout << "Systematic variations on the pp fwdrap" << std::endl; 
  for(j=1;j< 101;j++){
    f2b_pp = new TF1("Tag and Probe and variations",myFunc,0,20,6);
    if (doOnlyNumerator){ f2b_pp= new TF1("myFunk",myNumerator,0,20,6);}
    //  f2b_pp->SetRange(0,20);
    std::cout <<alpha_data_pp_fwdrap_syst[j] <<"*TMath::Erf((x-"<< mu_data_pp_fwdrap_syst[j] <<"/"<<sigma_data_pp_fwdrap_syst[j]<<")) / (0.9576*TMath::Erf((x-1.7883)/2.6583))"<<std::endl;
    f2b_pp->SetParameters(alpha_data_pp_fwdrap_syst[j],mu_data_pp_fwdrap_syst[j],sigma_data_pp_fwdrap_syst[j],j,endcap,pbpb);
    f2b_pp->SetLineColor(kOrange+1);
    f2b_pp->Draw("same");
   }


  std::cout << "variations on the pp fwdrap" << std::endl; 
  for(j=1;j< 101;j++){
    //reminder:
    // p[0] is the normalisation;
    // p[1] is the mu_data;
    // p[2] is the sigma_data;
    // p[3] is the index in the array : 0 is the nominal case, 1-101 are the 100 variations.
    // p[4] is the Abs(eta) region : 0 is barrel, 1 is endcap muons.
    // p[5] is the collision type : 0 is pp, 1 is pp.
    ge = new TF1("Tag and Probe and variations",myFunc,0,20,6);
    if (doOnlyNumerator){ ge= new TF1("myFunk",myNumerator,0,20,6);}
    ge->SetRange(3.5,20);
    std::cout  << alpha_pp_fwdrap[j] <<"*TMath::Erf((x-"<< mu_data_pp_fwdrap[j] <<"/"<<sigma_data_pp_fwdrap[j]<<")) / (0.7364*TMath::Erf((x-1.2149)/2.3352))"<<std::endl;
    // cout << f << endl;
    ge->SetParameters(alpha_pp_fwdrap[j],mu_data_pp_fwdrap[j],sigma_data_pp_fwdrap[j],j,endcap,pbpb);
    ge->SetLineColor(kAzure+1);
    ge->Draw("same");
  }

  if (doOnlyNumerator){ f21_pp->GetYaxis()->SetTitle("#epsilon^{#mu}_{DATA}"); }
  else{  f21_pp->GetYaxis()->SetTitle("Scale Factor");}
  f21_pp->GetYaxis()->SetTitleOffset(1.3);
  f21_pp->GetXaxis()->SetTitle("Probe p_{T} [GeV/c]");
  f21_pp->GetXaxis()->CenterTitle(kTRUE);
  f21_pp->GetXaxis()->SetTitleOffset(1.3);
  g2->Draw("same");
  f21_pp->Draw("same");
  TLegend *leg2 = new TLegend(0.2,0.66,0.9,0.88);
  leg2->SetTextSize(0.038);
  leg2->SetFillStyle(0);
  leg2->SetFillColor(0);
  leg2->SetBorderSize(0);
  leg2->SetTextFont(42);
    if(!doOnlyNumerator)
      { 
	leg2->AddEntry(g2,"pp 1.6 < |#eta^{#mu}| < 2.4  ","");
	leg2->AddEntry(g2,"Nominal T&P function  ","lp");
	leg2->AddEntry(ge,"100 stat. variations","lp");
	leg2->AddEntry(f21_pp,"Nominal function, 'new' settings ","lp");
	leg2->AddEntry(f2b_pp,"100 stat.+syst. variations ","lp");

      }
    else{ 
      leg2->AddEntry(g2,"pp 1.6 < |#eta^{#mu}| < 2.4","");
      leg2->AddEntry(g2,"#varepsilon^{DATA}_{#mu} ","lp");
      leg2->AddEntry(ge,"100 stat. variations ","lp");
      leg2->AddEntry(f21_pp,"Nominal function, 'new' settings ","lp");
      leg2->AddEntry(f2b_pp,"100 stat.+syst. variations ","lp");
    }
    leg2->Draw();
    
     if(!doOnlyNumerator)
       {    cBarrel_pp->SaveAs("~/Desktop/Grenelle/TNP_pp_100variations_newSettings_15-001.pdf");}
     else{	 cBarrel_pp->SaveAs("~/Desktop/Grenelle/numerator_variations_pp_15-001.pdf");}
 
}

