#include "tnp_weight.h"

double denominator_pbpb(double x, double eta);
double denominator_pp(double x, double eta);

void toy_summary(int ieta, bool ispbpb, double nsigma=-1) {
   // ieta = 0 (0-0.9), 1 (0.9-1.6), 2 (1.6-2.1), 3 (2.1-2.4)
   // ispbpb = true for PbPb, false for pp
   // nsigma should typically be +1 or -1

   const int npoints = 100;
   double eta;
   double ptmin = 0;
   if (ieta==0) {ptmin = 3.4; eta=0.3;}
   else if (ieta==1) {ptmin = 2.1; eta=1.2;}
   else if (ieta==2) {ptmin = 1.7; eta=1.9;}
   else {ptmin = 1.5; eta=2.3;}
   double ptmax = 30;
   double ptstep = (ptmax-ptmin)/npoints;

   double* xpoints = new double[100];
   double* ypoints = new double[100];

   for (int i=0; i<100; i++) {
      xpoints[i] = ptmin + i*ptstep;

      double sumy=0, sumy2=0;
      double den= ispbpb ? denominator_pbpb(xpoints[i],eta) : denominator_pp(xpoints[i],eta);
      double nominal = den*(ispbpb ? tnp_weight_muidtrg_pbpb(xpoints[i],eta,0) : tnp_weight_muidtrg_pp(xpoints[i],eta,0));
      for (int j=0; j<100; j++) {
         double num = den*(ispbpb ? tnp_weight_muidtrg_pbpb(xpoints[i],eta,j+1) : tnp_weight_muidtrg_pp(xpoints[i],eta,j+1));
         sumy += num;
         sumy2 += num*num;
      }
      double mean = sumy/100.;
      double rms = sqrt(sumy2*100. - sumy*sumy)/100.;
      // ypoints[i] = nominal + rms;
      ypoints[i] = nominal + nsigma * rms;

      if (i<10) cout << xpoints[i] << " " << ypoints[i] <<  " " << sumy << " " << sumy2 << " " << mean << " " << rms << endl;
   }

   TGraph *tg = new TGraph(npoints,xpoints,ypoints);
   TF1 *tf = new TF1("tf","[0]*TMath::Erf((x-[1])/[2])",ptmin,ptmax);
   tf->SetParameters(ypoints[npoints-1],0.1,1.0);
   tf->SetParLimits(0,0,1);
   tf->SetParLimits(1,0.,10.);
   tf->SetParLimits(2,0,10.);
   tg->Fit(tf);
   tg->Draw("AP");

   cout << Form("%.4f*TMath::Erf((x-%.4f)/%.4f)",tf->GetParameter(0),tf->GetParameter(1),tf->GetParameter(2)) << endl;
}

double denominator_pbpb(double x, double eta) {
   // denominator (from MC)
   double den=1;
   if (fabs(eta)<0.9) den = 0.9724*TMath::Erf((x-0.4114)/3.3775);
   else if (fabs(eta)<1.6) den = 0.9502*TMath::Erf((x-1.3857)/2.0757);
   else if (fabs(eta)<2.1) den = 0.8971*TMath::Erf((x-1.0984)/2.3510);
   else den = 0.7763*TMath::Erf((x-0.8419)/1.6742);
   return den;
}

double denominator_pp(double x, double eta) {
   // denominator (from MC)
   double den=1;
   if (fabs(eta)<0.9) den = 0.9547*TMath::Erf((x-1.7776)/2.0497);
   else if (fabs(eta)<1.6) den = 0.9150*TMath::Erf((x-1.8502)/1.6651);
   else if (fabs(eta)<2.1) den = 0.8721*TMath::Erf((x-1.1449)/2.5504);
   else den = 0.6137*TMath::Erf((x-1.0202)/1.0729);
   return den;
}
