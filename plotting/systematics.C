#include "data_raa2015.h"
using namespace std;
float maxDeviation(float yieldRef,float yield[], int nvars){
  float diff;
  float tmp=0; //
  for (int i=0; i<nvars;i++){
    //  cout << " tested "<< yield[i] <<endl;
    diff=(yield[i]-yieldRef)/yieldRef;
    //  cout << diff << " is the relative deviation" << endl;
    if ( fabs(diff)>tmp) {tmp=diff; cout << 100*tmp  << " % relative deviation kept" <<endl;}else {}
  }
  return tmp;
}

float RMS(float yieldRef, float yieldVars[],int nvars){
  float RMS;
  float MS=0; 
  for (int i=0; i<nvars;i++){
    //  cout << MS << endl;
    MS += pow((yieldRef-yieldVars[i]),2);
  }
  RMS = sqrt(MS/(nvars-1))/yieldRef;
  // cout << RMS << endl;
  return RMS;
}
float  systematics(){
  float fitvar, bkgdvar;
  float  syst1S_aa_Cent_test;
  fitvar =RMS(N1S_aa_cent3p5[0],N1S_aa_cents_5,nfitvars);
  bkgdvar =maxDeviation(N1S_aa_cent3p5[0],N1B_aa_cents_100,nbkgdvars);
  syst1S_aa_Cent_test=sqrt(fitvar*fitvar+bkgdvar*bkgdvar);

  return  syst1S_aa_Cent_test;
}
