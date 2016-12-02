#include <iostream>
//#include "data_raa2015.h"


float Deviation(float yieldRef,float yield){
  return (yield-yieldRef)/yieldRef;
}

float MaxDeviation(float yieldRef,float yield[], int var0, int nvars){
  float diff;
  float maxdeviation=0; //
  for (int i=var0; i<=nvars;i++){
    //  cout << " tested "<< yield[i] <<endl;
    diff= Deviation(yieldRef,yield[i]);
    // cout << diff << " is the relative deviation" << endl;
    if ( fabs(diff)>maxdeviation) {
      maxdeviation=diff; //cout << 100*tmp  << " % relative deviation kept" <<endl;
    }else {}
  }
  return maxdeviation;
}

float MaxSyst(float yieldRef, float VarS[], float VarB[], int nvars, int nvarb){
  //take max of all
  float maxsig = MaxDeviation(yieldRef,VarS,1,nvars);
  float maxbkg = MaxDeviation(yieldRef,VarB,0,nvarb-1);
  float maxsyst=0;
  if ( fabs(maxsig)>fabs(maxbkg) ){ maxsyst = maxsig;}
  else   if ( fabs(maxsig)<fabs(maxbkg) ){ maxsyst = maxbkg;}  
  return maxsyst;
}

float OlafSyst(float yieldRef, float VarS[], float VarB[]){
  //compute max tail + max gaus + max bkgd as a systematic
  float s1, s2, s3;
  s1= MaxDeviation(yieldRef,VarS,1,2);//variations 1,2
  s2= MaxDeviation(yieldRef,VarS,3,5);// variations 3,4,5
  s3= MaxDeviation(yieldRef,VarB,0,1);//bkgd vars 0,1! tricky 
  cout<<setprecision(3)<< 100*s1 << "\\% & "<< 100*s2<<"\\% & "<<100*s3<<"\\% & "<< 100*MaxSyst(yieldRef,VarS,VarB,5,2)<< "\\% & ";
  return sqrt(pow(s1,2)+pow(s2,2)+pow(s3,2));
}

float ppAlphaSyst(float yieldRef, float VarS[], float VarB[],float ppyieldRef,float ppyield){
  //compute (max tail,gaus + max bkgd) as a systematic
  // substitute alpha_pbpb with alpha_pp
  
  float s1, s2, s3;
  s1= Deviation(ppyieldRef,ppyield);//variations 1,2
  s2= MaxDeviation(yieldRef,VarS,2,5);// variations 2,3,4,5
  if (s1<s2){s1=s2;}
  s3= MaxDeviation(yieldRef,VarB,0,1);//bkgd vars 0,1! tricky 
  //cout<<setprecision(3)<< 100*s1 << "\\% & "<< 100*s3<<"\\% & "<< 100*MaxSyst(yieldRef,VarS,VarB,5,2)<< "\\% & ";
  //  return sqrt(pow(s1,2)+pow(s2,2)+pow(s3,2));
  return sqrt(pow(s1,2)+pow(s3,2));
  
}
void recomputeSyst(){
  
  //  Checking the table's validity on the first row:
  //cout << "nom-nom    alpha    npow    sigma    w2/w1    f\n";
 
  // cout <<"  Bin pp (1S) & Tail variations & Resolution variations & Background variations & Maximum & Quadratic sum \\\\ "<<endl;
  // cout << (binsPt[0]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N1S_pp_pt3p5[0],N1S_pp_pt3p5s_2p5,N1B_pp_pt3p5s_2p5,N1S_pp_pt3p5[0],N1S_pp_pt3p5s_2p5[1])<< "\\% \\\\"<<endl;   
  // cout << (binsPt[1]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N1S_pp_pt3p5[1],N1S_pp_pt3p5s_5,N1B_pp_pt3p5s_5,N1S_pp_pt3p5[1],N1S_pp_pt3p5s_5[1])<< "\\% \\\\"<<endl;	   
  // cout << (binsPt[2]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N1S_pp_pt3p5[2],N1S_pp_pt3p5s_8,N1B_pp_pt3p5s_8,N1S_pp_pt3p5[2],N1S_pp_pt3p5s_8[1])<< "\\% \\\\"<<endl;	   
  // cout << (binsPt[3]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N1S_pp_pt3p5[3],N1S_pp_pt3p5s_12,N1B_pp_pt3p5s_12,N1S_pp_pt3p5[3],N1S_pp_pt3p5s_12[1])<< "\\% \\\\"<<endl;	   
  // cout << (binsPt[4]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N1S_pp_pt3p5[4],N1S_pp_pt3p5s_20,N1B_pp_pt3p5s_20,N1S_pp_pt3p5[4],N1S_pp_pt3p5s_20[1])<< "\\% \\\\"<<endl<<endl;


  // cout << (binsRap[0]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N1S_pp_rap3p5_2014[0],N1S_pp_rap3p5s_0p4,N1B_pp_rap3p5s_0p4,N1S_pp_rap3p5_2014[0],N1S_pp_rap3p5s_0p4[1])<< "\\% \\\\"<<endl;
  // cout << (binsRap[1]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N1S_pp_rap3p5_2014[1],N1S_pp_rap3p5s_0p8,N1B_pp_rap3p5s_0p8,N1S_pp_rap3p5_2014[1],N1S_pp_rap3p5s_0p8[1])<< "\\% \\\\"<<endl;
  // cout << (binsRap[2]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N1S_pp_rap3p5_2014[2],N1S_pp_rap3p5s_1p2,N1B_pp_rap3p5s_1p2,N1S_pp_rap3p5_2014[2],N1S_pp_rap3p5s_1p2[1])<< "\\% \\\\"<<endl;
  // cout << (binsRap[3]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N1S_pp_rap3p5_2014[3],N1S_pp_rap3p5s_1p6,N1B_pp_rap3p5s_1p6,N1S_pp_rap3p5_2014[3],N1S_pp_rap3p5s_1p6[1])<< "\\% \\\\"<<endl;
  // cout << (binsRap[4]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N1S_pp_rap3p5_2014[4],N1S_pp_rap3p5s_2p0,N1B_pp_rap3p5s_2p0,N1S_pp_rap3p5_2014[4],N1S_pp_rap3p5s_2p0[1])<< "\\% \\\\"<<endl;
  // cout << (binsRap[5]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N1S_pp_rap3p5_2014[5],N1S_pp_rap3p5s_2p4,N1B_pp_rap3p5s_2p4,N1S_pp_rap3p5_2014[5],N1S_pp_rap3p5s_2p4[1])<< "\\% \\\\"<<endl<<endl;

  // cout <<"  Bin pp (2S) & Tail variations & Resolution variations & Background variations & Maximum & Quadratic sum \\\\ "<<endl;
  // cout << (binsPt[0]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N2S_pp_pt4_2013[0],N2S_pp_pt4s_2p5,N2B_pp_pt4s_2p5,N2S_pp_pt4_2013[0],N2S_pp_pt4s_2p5[1])<< "\\% \\\\"<<endl;   
  // cout << (binsPt[1]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N2S_pp_pt4_2013[1],N2S_pp_pt4s_5,N2B_pp_pt4s_5,N2S_pp_pt4_2013[1],N2S_pp_pt4s_5[1])<< "\\% \\\\"<<endl;	   
  // cout << (binsPt[2]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N2S_pp_pt4_2013[2],N2S_pp_pt4s_8,N2B_pp_pt4s_8,N2S_pp_pt4_2013[2],N2S_pp_pt4s_8[1])<< "\\% \\\\"<<endl;	   
  // cout << (binsPt[3]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N2S_pp_pt4_2013[3],N2S_pp_pt4s_12,N2B_pp_pt4s_12,N2S_pp_pt4_2013[3],N2S_pp_pt4s_12[1])<< "\\% \\\\"<<endl;	   
  // cout << (binsPt[4]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N2S_pp_pt4_2013[4],N2S_pp_pt4s_20,N2B_pp_pt4s_20,N2S_pp_pt4_2013[4],N2S_pp_pt4s_20[1])<< "\\% \\\\"<<endl<<endl;
  
  // cout << (binsRap[0]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N2S_pp_rap4_2014[0],N2S_pp_rap4s_0p4,N2B_pp_rap4s_0p4,N2S_pp_rap4_2014[0],N2S_pp_rap4s_0p4[1])<< "\\% \\\\"<<endl;
  // cout << (binsRap[1]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N2S_pp_rap4_2014[1],N2S_pp_rap4s_0p8,N2B_pp_rap4s_0p8,N2S_pp_rap4_2014[1],N2S_pp_rap4s_0p8[1])<< "\\% \\\\"<<endl;
  // cout << (binsRap[2]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N2S_pp_rap4_2014[2],N2S_pp_rap4s_1p2,N2B_pp_rap4s_1p2,N2S_pp_rap4_2014[2],N2S_pp_rap4s_1p2[1])<< "\\% \\\\"<<endl;
  // cout << (binsRap[3]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N2S_pp_rap4_2014[3],N2S_pp_rap4s_1p6,N2B_pp_rap4s_1p6,N2S_pp_rap4_2014[3],N2S_pp_rap4s_1p6[1])<< "\\% \\\\"<<endl;
  // cout << (binsRap[4]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N2S_pp_rap4_2014[4],N2S_pp_rap4s_2p0,N2B_pp_rap4s_2p0,N2S_pp_rap4_2014[4],N2S_pp_rap4s_2p0[1])<< "\\% \\\\"<<endl;
  // cout << (binsRap[5]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N2S_pp_rap4_2014[5],N2S_pp_rap4s_2p4,N2B_pp_rap4s_2p4,N2S_pp_rap4_2014[5],N2S_pp_rap4s_2p4[1])<< "\\% \\\\"<<endl<<endl;

  // cout <<"  Bin pp (3S) & Tail variations & Resolution variations & Background variations & Maximum & Quadratic sum \\\\ "<<endl;
  // cout << (binsPt[0]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N3S_pp_pt4_2013[0],N3S_pp_pt4s_2p5,N3B_pp_pt4s_2p5,N3S_pp_pt4_2013[0],N3S_pp_pt4s_2p5[1])<< "\\% \\\\"<<endl;
  // cout << (binsPt[1]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N3S_pp_pt4_2013[1],N3S_pp_pt4s_5,N3B_pp_pt4s_5,N3S_pp_pt4_2013[1],N3S_pp_pt4s_5[1])<< "\\% \\\\"<<endl;
  // cout << (binsPt[2]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N3S_pp_pt4_2013[2],N3S_pp_pt4s_8,N3B_pp_pt4s_8,N3S_pp_pt4_2013[2],N3S_pp_pt4s_8[1])<< "\\% \\\\"<<endl;
  // cout << (binsPt[3]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N3S_pp_pt4_2013[3],N3S_pp_pt4s_12,N3B_pp_pt4s_12,N3S_pp_pt4_2013[3],N3S_pp_pt4s_12[1])<< "\\% \\\\"<<endl;
  // cout << (binsPt[4]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N3S_pp_pt4_2013[4],N3S_pp_pt4s_20,N3B_pp_pt4s_20,N3S_pp_pt4_2013[4],N3S_pp_pt4s_20[1])<< "\\% \\\\"<<endl<<endl;
  
  // cout << (binsRap[0]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N3S_pp_rap4_2014[0],N3S_pp_rap4s_0p4,N3B_pp_rap4s_0p4,N3S_pp_rap4_2014[0],N3S_pp_rap4s_0p4[1])<< "\\% \\\\"<<endl;
  // cout << (binsRap[1]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N3S_pp_rap4_2014[1],N3S_pp_rap4s_0p8,N3B_pp_rap4s_0p8,N3S_pp_rap4_2014[1],N3S_pp_rap4s_0p8[1])<< "\\% \\\\"<<endl;
  // cout << (binsRap[2]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N3S_pp_rap4_2014[2],N3S_pp_rap4s_1p2,N3B_pp_rap4s_1p2,N3S_pp_rap4_2014[2],N3S_pp_rap4s_1p2[1])<< "\\% \\\\"<<endl;
  // cout << (binsRap[3]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N3S_pp_rap4_2014[3],N3S_pp_rap4s_1p6,N3B_pp_rap4s_1p6,N3S_pp_rap4_2014[3],N3S_pp_rap4s_1p6[1])<< "\\% \\\\"<<endl;
  // cout << (binsRap[4]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N3S_pp_rap4_2014[4],N3S_pp_rap4s_2p0,N3B_pp_rap4s_2p0,N3S_pp_rap4_2014[4],N3S_pp_rap4s_2p0[1])<< "\\% \\\\"<<endl;
  // cout << (binsRap[5]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N3S_pp_rap4_2014[5],N3S_pp_rap4s_2p4,N3B_pp_rap4s_2p4,N3S_pp_rap4_2014[5],N3S_pp_rap4s_2p4[1])<< "\\% \\\\"<<endl<<endl;
 
  // cout <<"  Bin PbPb (1S) & Signal variations & Background variations & Maximum & Quadratic sum \\\\ "<<endl;
  // cout << (binsPt[0]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N1S_aa_pt3p5[0],N1S_aa_pt3p5s_2p5,N1B_aa_pt3p5s_2p5,N1S_pp_pt3p5[0],N1S_pp_pt3p5s_2p5[1])<< "\\% \\\\"<<endl;
  // cout << (binsPt[1]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N1S_aa_pt3p5[1],N1S_aa_pt3p5s_5,N1B_aa_pt3p5s_5,N1S_pp_pt3p5[1],N1S_pp_pt3p5s_5[1])<< "\\% \\\\"<<endl;
  // cout << (binsPt[2]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N1S_aa_pt3p5[2],N1S_aa_pt3p5s_8,N1B_aa_pt3p5s_8,N1S_pp_pt3p5[2],N1S_pp_pt3p5s_8[1])<< "\\% \\\\"<<endl;
  // cout << (binsPt[3]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N1S_aa_pt3p5[3],N1S_aa_pt3p5s_12,N1B_aa_pt3p5s_12,N1S_pp_pt3p5[3],N1S_pp_pt3p5s_12[1])<< "\\% \\\\"<<endl;
  // cout << (binsPt[4]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N1S_aa_pt3p5[4],N1S_aa_pt3p5s_20,N1B_aa_pt3p5s_20,N1S_pp_pt3p5[4],N1S_pp_pt3p5s_20[1])<< "\\% \\\\"<<endl<<endl;

  // cout << (binsRap[0]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N1S_aa_rap3p5_2014[0],N1S_aa_rap3p5s_0p4,N1B_aa_rap3p5s_0p4,N1S_pp_rap3p5_2014[0],N1S_pp_rap3p5s_0p4[1])<< "\\% \\\\"<<endl;
  // cout << (binsRap[1]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N1S_aa_rap3p5_2014[1],N1S_aa_rap3p5s_0p8,N1B_aa_rap3p5s_0p8,N1S_pp_rap3p5_2014[1],N1S_pp_rap3p5s_0p8[1])<< "\\% \\\\"<<endl;
  // cout << (binsRap[2]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N1S_aa_rap3p5_2014[2],N1S_aa_rap3p5s_1p2,N1B_aa_rap3p5s_1p2,N1S_pp_rap3p5_2014[2],N1S_pp_rap3p5s_1p2[1])<< "\\% \\\\"<<endl;
  // cout << (binsRap[3]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N1S_aa_rap3p5_2014[3],N1S_aa_rap3p5s_1p6,N1B_aa_rap3p5s_1p6,N1S_pp_rap3p5_2014[3],N1S_pp_rap3p5s_1p6[1])<< "\\% \\\\"<<endl;
  // cout << (binsRap[4]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N1S_aa_rap3p5_2014[4],N1S_aa_rap3p5s_2p0,N1B_aa_rap3p5s_2p0,N1S_pp_rap3p5_2014[4],N1S_pp_rap3p5s_2p0[1])<< "\\% \\\\"<<endl;
  // cout << (binsRap[5]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N1S_aa_rap3p5_2014[5],N1S_aa_rap3p5s_2p4,N1B_aa_rap3p5s_2p4,N1S_pp_rap3p5_2014[5],N1S_pp_rap3p5s_2p4[1])<< "\\% \\\\"<<endl<<endl;
  
  // cout << (binsCent[0]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N1S_aa_cent3p5[0],N1S_aa_cents_100,N1B_aa_cents_100,N1S_pp_rap4_2014Large[0],N1S_pp_rap4Larges_1p2[1])<< "\\% \\\\"<<endl;
  // cout << (binsCent[1]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N1S_aa_cent3p5[1],N1S_aa_cents_70,N1B_aa_cents_70,N1S_pp_rap4_2014Large[0],N1S_pp_rap4Larges_1p2[1])<< "\\% \\\\"<<endl;
  // cout << (binsCent[2]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N1S_aa_cent3p5[2],N1S_aa_cents_50,N1B_aa_cents_50,N1S_pp_rap4_2014Large[0],N1S_pp_rap4Larges_1p2[1])<< "\\% \\\\"<<endl;
  // cout << (binsCent[3]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N1S_aa_cent3p5[3],N1S_aa_cents_40,N1B_aa_cents_40,N1S_pp_rap4_2014Large[0],N1S_pp_rap4Larges_1p2[1])<< "\\% \\\\"<<endl;
  // cout << (binsCent[4]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N1S_aa_cent3p5[4],N1S_aa_cents_30,N1B_aa_cents_30,N1S_pp_rap4_2014Large[0],N1S_pp_rap4Larges_1p2[1])<< "\\% \\\\"<<endl;
  // cout << (binsCent[5]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N1S_aa_cent3p5[5],N1S_aa_cents_20,N1B_aa_cents_20,N1S_pp_rap4_2014Large[0],N1S_pp_rap4Larges_1p2[1])<< "\\% \\\\"<<endl;
  // cout << (binsCent[6]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N1S_aa_cent3p5[6],N1S_aa_cents_10,N1B_aa_cents_10,N1S_pp_rap4_2014Large[0],N1S_pp_rap4Larges_1p2[1])<< "\\% \\\\"<<endl;
  // cout << (binsCent[7]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N1S_aa_cent3p5[7],N1S_aa_cents_5,N1B_aa_cents_5,N1S_pp_rap4_2014Large[0],N1S_pp_rap4Larges_1p2[1])<< "\\% \\\\"<<endl<<endl;

  // cout <<"  Bin PbPb (2S) & Tail variations & Resolution variations & Background variations & Maximum & Quadratic sum \\\\ "<<endl;
  // cout << (binsPt2010[0]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N2S_aa_pt4_2013Large[0],N2S_aa_pt4Larges_5,N2B_aa_pt4Larges_5,N2S_pp_pt4_2013Large[0],N2S_pp_pt4Larges_5[1])<< "\\% \\\\"<<endl;
  // cout << (binsPt2010[1]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N2S_aa_pt4_2013Large[1],N2S_aa_pt4Larges_12,N2B_aa_pt4Larges_12,N2S_pp_pt4_2013Large[1],N2S_pp_pt4Larges_12[1])<< "\\% \\\\"<<endl;
  // cout << (binsPt2010[2]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N2S_aa_pt4_2013Large[2],N2S_aa_pt4Larges_20,N2B_aa_pt4Larges_20,N2S_pp_pt4_2013Large[2],N2S_pp_pt4Larges_20[1])<< "\\% \\\\"<<endl<<endl;

  // cout << (binsRap2010[0]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N2S_aa_rap4_2014Large[0],N2S_aa_rap4Larges_1p2,N2B_aa_rap4Larges_1p2,N2S_pp_rap4_2014Large[0],N2S_pp_rap4Larges_1p2[1])<< "\\% \\\\"<<endl;
  // cout << (binsRap2010[1]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N2S_aa_rap4_2014Large[1],N2S_aa_rap4Larges_2p4,N2B_aa_rap4Larges_2p4,N2S_pp_rap4_2014Large[1],N2S_pp_rap4Larges_2p4[1])<< "\\% \\\\"<<endl<<endl;
  
  
  // cout << (bins4Bin[0]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N2S_aa_cent4Large[0],N2S_aa_cent4Larges_100,N2B_aa_cent4Larges_100,N2S_pp_rap4_2014Large[0],N2S_pp_rap4Larges_1p2[1])<< "\\% \\\\"<<endl;
  // cout << (bins4Bin[1]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N2S_aa_cent4Large[1],N2S_aa_cent4Larges_50,N2B_aa_cent4Larges_50,N2S_pp_rap4_2014Large[0],N2S_pp_rap4Larges_1p2[1])<< "\\% \\\\"<<endl;
  // cout << (bins4Bin[2]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N2S_aa_cent4Large[2],N2S_aa_cent4Larges_30,N2B_aa_cent4Larges_30,N2S_pp_rap4_2014Large[0],N2S_pp_rap4Larges_1p2[1])<< "\\% \\\\"<<endl;
  // cout << (bins4Bin[3]).c_str() << " & "<<setprecision(3) << 100*ppAlphaSyst(N2S_aa_cent4Large[3],N2S_aa_cent4Larges_10,N2B_aa_cent4Larges_10,N2S_pp_rap4_2014Large[0],N2S_pp_rap4Larges_1p2[1])<< "\\% \\\\"<<endl;
  cout << "\n end of story"<< endl;
}
