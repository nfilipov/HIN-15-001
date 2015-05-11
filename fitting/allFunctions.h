#include <iostream.h>
const double mass_l =  7.0;
const double mass_h = 14.0;
const double binw   = 0.1;    //bin width of the histogram
const double M1S = 9.46;   //upsilon 1S pgd mass value
const double M2S = 10.023;  //upsilon 2S pgd mass value
const double M3S = 10.355;  //upsilon 3S pgd mass value
RooWorkspace makeWorkspace(RooWorkspace& w, int chooseSample ,float muonEtaMin, float muonEtaMax , float muonPtMin, float muonPtMax , float upsRapStart, float upsRapEnd, float upsPtStart, float upsPtEnd, int upsCentralityStart, int upsCentralityEnd);
void buildModel(RooWorkspace& w,int chooseFitParams, int chooseSample, int whatBin, int signalModel, int bkgModel, int doRap, int doPt,int doCent,int useRef,float muonPtMin,int fsr);
//int whatBin(float upsPtMin, float upsPtMax, float upsRapMin, float upsRapMax, int centStart, int centEnd, int doRap,int doPt, int doCent);
void fitAndDraw(RooWorkspace& w);
pair<double, double> ConfidencInterval(float CI, RooRealVar *fnll, RooDataSet *data, RooAbsPdf *pdf);
double computeSingleError(RooRealVar& x, RooRealVar& y, double correlation );
double computeSingle(RooRealVar& x, RooRealVar& y);



