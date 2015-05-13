//#include <iostream.h>
#include "raaFunctions.h"
#include "data_signif.h"

class Upsilon {
  float Num, Denom;
  float Num_err, Denom_err, err;
  float ratio, ratio_err;
 public:
  void SetVariables (float,float);
  void SetErrors (float,float);
  float Ratio () {ratio=Num/Denom; return ratio;}
  float RatioError()
  {
    err = (Num_err*Num_err)/(Num*Num) + (Denom_err*Denom_err)/(Denom*Denom);
    // + 2.*(x.getError()*y.getError())/(x.getVal()*y.getVal())*correlation; // can be needed in case of correlations.
    ratio_err = fabs(ratio)*sqrt(err);
    return ratio_err;
  }
 protected:
   
  {bool pt=true;
    bool rap=true;}
};
void Upsilon::SetVariables (float x, float y) {
  Num= x;
  Denom = y;
}

void Upsilon::SetErrors(float x, float y) {
  Num_err = x;
  Denom_err= y ;
}

void InitCanvases(TCanvas& c, bool pt, bool rap);
float PropUnc(Upsilon a,Upsilon b);
void BinnedRAA (int s, float x[], float xe[], float y[], float ye[], float x_eff[], float x_effe[], float y_eff[], float y_effe[], const int NumberOfBins, float graph_xbins[], float graph_xbins_err[]);
void BinnedNpartRAA (int s, float x[], float xe[], float y, float ye, float x_eff[], float x_effe[], float y_eff, float y_effe,  const int NumberOfBins, float graph_xbins[], float graph_xbins_err[]);
void MinBiasRAA(float y1, float y1e, float y2, float y2e, float eff1, float eff1e, float eff2, float eff2e);
float CentLumiCorr(int s, int b);
void plotSignificances(int s,int pp,int pbpb,bool ,bool);
