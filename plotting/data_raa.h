
  //integers for binning.
  //centrality binning in 11-011

#define nfitvars 5
#define nbkgdvars 2
#define nPtBins_2013  5
#define nPtBins_2014 6
#define nPtBins_2010  3
#define nRapBins_2013 5
#define nRapBins_2010 2
#define nRapBins_2014 6
#define nCentBins_2014 8
#define nCentBins_2010 2
#define nCentBins_2S 4
#define nRapBins_pPb 9
#define bin1  7
#define bin 8
#define L_pp_invNb 5400
#define L_pp_invNbe 199.8
#define L_pp 5400000000000
#define L_ppe 199800000000 
#define N_MB_uncorr 1.126653312	
//#define N_MB_corr   1.138033648
#define T_AA_b 5662
#define T_AA_mb 5.662     
#define RapBinWidth 4.8
#define L_pp_e 0.027
#define N_MB_e 0.034
float  N_MB_corr= N_MB_uncorr/0.97;
float cent[bin1]  ={22.05, 86.3, 130.0, 187.1, 261.4, 330.4, 381.3}; // with 40-50 and 50-100 //and the 5-10 bin was 329.5, which is inconsistent with a few lines below.
float nPart2014[nCentBins_2014]  ={8.75, 42.02, 86.23, 130.06, 187.35, 261.49, 329.48, 381.41}; //from 2012_246_v5
float nPart2015[nCentBins_2014+1]  ={8.75, 42.02, 86.23, 130.06, 187.35, 261.49, 329.48, 368, 393}; //from 2012_246_v5
float nPart2014e[nCentBins_2014] ={1.13,3.48,4.35,4.60,4.44,3.96,3.53,2.21}; //from 2012_246_v5
//////
float taa[bin1] = {0.486,2.748,5.089,8.782,14.477,20.47,25.901}; // taa of 40-50, 50-100
float taae[bin1]={0.073,0.30,0.43,0.58,0.76,0.94,1.06};
float taaDD[nCentBins_2010]={2.37,18.83171875};
float taa2014[nCentBins_2014]   = {0.13,0.985,2.75,5.089,8.80,14.48,20.48,25.91}; //taa of 50-70, 70-100
float taa2015[nCentBins_2014+1] = {0.13,0.985,2.75,5.089,8.80,14.48,20.48,24.5,27.3}; //taa of 50-70, 70-100
float taa2014e[nCentBins_2014] = {0.02,0.145,0.30,0.43,0.58,0.76,0.94,1.06};
float mb_percentage2014[nCentBins_2014] = {0.3,0.2,0.1,0.1,0.1,0.1,0.05,0.05};
float mb_percentage2015[nCentBins_2014+1] = {0.3,0.2,0.1,0.1,0.1,0.1,0.05,0.025,0.025};
float mb_percentage[bin1] = {0.5,0.1,0.1,0.1,0.1,0.05,0.05};
float mb_percentageDD[nCentBins_2010]={0.8,0.2};
//////
float taa1S[nCentBins_2014]={0.13,0.985,2.75,5.089,8.80,14.48,20.48,25.91}; //taa of  70-100, 50-70, 40-50, 30-40, 20-30, 10-20, 5-10, 0-5
float taa2S[nCentBins_2S]={0.486,3.918791,11.63034,23.18574}; // taa of 50-100, 30-50, 10-30, 0-10.
float mb_percentage1S[nCentBins_2014] = {0.3,0.2,0.1,0.1,0.1,0.1,0.05,0.05};
float mb_percentage2S[nCentBins_2S] = {0.5,0.2,0.2,0.1};

int binPt = 5;
int binPt2010 = 3;
int binRap = 5;
int binRap2010 = 2;
int bin2010 = 4;

   // float cent1[8] ={14.2, 69.9, 130.0, 187.1, 261.4, 329.4, 381.3}; // with 40-60 and 60-100
   float nPart1[9] ={8.75,42.02, 86.3, 130.1, 187.3, 261.4, 330.3, 381.2}; // with 70-100, 50-70, 40-50, 30-40, 20-30, 10-20, 5-10, 0-5
   float nPart2[7] ={17.8, 69.9, 130.0, 187.1, 261.4, 355.4};//?? 

float cent2010[5]={308.6,64.24,261.3,355.7};//0-20,20-100,10-20,0-10
float nPartDD[nCentBins_2010]={64.24,308.6};
   float pt [5] = {1.25, 3.75, 6.5, 10., 16.};
   float pte[5] = {1.25, 1.25, 1.5, 2., 4.};
float pt15 [6] = {1.25, 3.75, 6.5, 10., 16.,30};
float pt15e[6] = {1.25, 1.25, 1.5, 2., 4.,10};
   float pt2010 [3] = {2.7,8.7,16.2};
   float pt2010e[3] = {2.5,3.5,4};

   float rap2010[2]={0.63,1.83};
   float rap2010e[2]={0.6,0.6};
   float rap2010paper[2]={0.64,1.54};
   float rap2010paperel[2]={0.64,0.34};
   float rap2010papereh[2]={0.56,0.86};
   float rap[5] = {0.2 , 0.55, 0.85, 1.25, 1.95};
   float rape[5]= {0.2, 0.15, 0.15, 0.25, 0.45};
float rap2014[6] = {0.2 , 0.6, 1.0, 1.4, 1.8,2.2}; // for the moment with bins of ∆y =0.8 except the last one which is 1.6-2.4
float rap2014Shift[6] = {0.3 , 0.7, 1.1, 1.5, 1.9,2.3}; // for the moment with bins of ∆y =0.8 except the last one which is 1.6-2.4
float rap2014e[6] = {0.2,0.2,0.2,0.2,0.2,0.2}; // for the moment with bins of ∆y =0.8 except the last one which is 1.6-2.4

float centErr[bin1]={6,6,6,6,6,6,6};
float centErr2014[nCentBins_2014]={6,6,6,6,6,6,6,6};
float centnoErr[nCentBins_2014+1]={0,0,0,0,0,0,0,0,0};


   //CONTROL PLOTS
   // mass resolution on the 1S peak in function of pT/rapidity/centrality bins
   float massRes_AA_pT[5]={72.7,100.6,60.8,88.5,75.8};
   float massRes_AA_pTe[5]={6.2,7.4,8.0,9.4,7.8};
   float massRes_pp_pT[5]={89.7,86.7,91.7,95.1,84.1};
   float massRes_pp_pTe[5]={4.2,4.2,3.9,4.4,4.6};
   float massRes_AA_rap[5]={58.6,61.5,86.,100.3,136.0};
   float massRes_AA_rape[5]={5.9,5.9,9.4,8.7,14.8};
   float massRes_pp_rap[5]={62.8,76.1,68.6,104.4,148.2};
   float massRes_pp_rape[5]={2.3,3.4,4.4,3.,5.9};
   float massRes_AA_npart[7]={65.8,88.7,98.6,89.7,77.6,98.8,67.1};
   float massRes_AA_nparte[7]={14.2,11.2,10.4,8.2,7.7,10.6,10.1};
   // mean mass resolution in AA "MB", and in pp "pp"
   float massRes_MB[1]={83.7};
   float massRes_MBe[1]={4.0};
   float massRes_pp[1]={91.6};
   float massRes_ppe[1]={2.1};
 
string binsPt[nPtBins_2013]={"\pt [{\\rm GeV}/c] $<$ 2.5",
			     "2.5 $<$ \pt [{\\rm GeV}/c] $<$ 5",
			     "5 $<$ \pt [{\\rm GeV}/c] $<$ 8",
			     "8 $<$ \pt [{\\rm GeV}/c] $<$ 12",
			     "12 $<$ \pt [{\\rm GeV}/c] $<$ 20"};
string binsPt2010[nPtBins_2010]={"\pt [{\\rm GeV}/c] $<$ 5",
				 "5 $<$ \pt [{\\rm GeV}/c] $<$ 12",
				 "12 $<$ \pt [{\\rm GeV}/c] $<$ 20"};
   
string binsRap[nRapBins_2014]={"$|y| <$ 0.4",
			       "0.4 $< |y| <$ 0.8  ",
			       "0.8 $< |y| <$ 1.2 ",
			       "1.2 $< |y| <$ 1.6 ",
			       "1.6 $< |y| <$ 2   ",
			       "2 $< |y| <$ 2.4   "};
string binsRap2010[nRapBins_2010]={"$|y| <$ 1.2 ",
				   "1.2 $< |y| <$ 2.4   "};
string binsCent[nCentBins_2014+1]={"70-100","50-70","40-50","30-40","20-30","10-20","5-10","2.5-5","0-2.5"};
string binsCent4[bin1]={"50-100","40-50","30-40","20-30","10-20","5-10","0-5"};
string bins2Bin[2]={"20-100","0-20"};

   //alice shit pT>0 GeV/c 
   #define binA 2

   float centAlice[binA]={72,308}; //20-90, 0-20%
   float centAliceErr[binA]={6,6};
   float centAliceNoErr[binA]={0,0};
   float ratioUpsAlice[binA]    ={0.512,0.351}; // 1S with 'alice' binning
   float ratioUpsAliceStat[binA]={0.036,0.026}; // stat. err.
   float ratioUpsAliceSyst[binA]={0.028,0.029}; // syst. err.

   float ratioUpsAlice2[binA]    ={0.203,0.056}; // 2S with 'alice' binning
   float ratioUpsAliceStat2[binA]={0.055,0.036};
   float ratioUpsAliceSyst2[binA]={0.035,0.050};
 
//raa 2011-011
float RAA_1S_2011sg=0.137/1.005;
float RAA_1S_2011[bin1]={1.005,0.590,0.681,0.614,0.484,0.432,0.411};
float RAA_1S_2011e[bin1]={0.121,0.096,0.069,0.053,0.040,0.048,0.043};
float RAA_1S_2011s[bin1]={0.176,0.080,0.093,0.084,0.066,0.059,0.056};
float RAA_2S_2011sg=0.064/0.300;
float RAA_2S_2011[bin1]={0.3,0.251,0.237,0.260,0.068,0.044,0.111};
float RAA_2S_2011e[bin1]={0.157,0.138,0.098,0.079,0.053,0.060,0.061};
float RAA_2S_2011s[bin1]={0.176,0.138,0.098,0.079,0.053,0.060,0.061};
   //Raa with regit and pp2013

   float ratio1S[bin]       ={1.275,0.699,0.567,0.585,0.418,0.409,0.308,0.387};// with 70-100, 50-70, 40-50, 30-40, 20-30, 10-20, 5-10, 0-5
   float ratio1SstatErr[bin]={0.279,0.081,0.085,0.067,0.045,0.038,0.031,0.049};
   float ratio1SsystErr[bin]={0.186,0.154,0.084,0.037,0.057,0.041,0.050,0.035};
   // float ratio1S[bin1]       ={1.061,0.587,0.585,0.418,0.409,0.308,0.387};// with 60-100, 40-60, 30-40, 20-30, 10-20, 5-10, 0-5 //
   // float ratio1SstatErr[bin1]={0.175,0.079,0.067,0.045,0.038,0.031,0.049}; //
   // float ratio1SsystErr[bin1]={0.   ,0.084,0.037,0.057,0.041,0.050,0.035}; //
   float ratio2S[bin]        ={0.532,0.225,0.353,0.367,0.144,0.130,0.00,0.149};
   float ratio2SstatErr[bin] ={0.333,0.134,0.161,0.109,0.066,0.059,0.00,0.073};
   float ratio2SsystErr[bin] ={  0.0,0.135,0.252,0.043,0.070,0.042,0.038,0.032};
   //  float ratio2S[bin]        ={0.458,0.318,0.367,0.144,0.130,0.00,0.149};// with 60-100, 40-60, 30-40, 20-30, 10-20, 5-10, 0-5 //
   //  float ratio2SstatErr[bin] ={0.280,0.119,0.109,0.066,0.059,0.00,0.073};
   //  float ratio2SsystErr[bin] ={  0.0,0.135,0.043,0.070,0.042,0.038,0.032};

   float ratioJpsi[bin]={0.610, 0.661, 0.506, 0.372, 0.220, 0.202};
   float ratioJpsistatErr[bin]={0.122, 0.131, 0.085, 0.058, 0.037, 0.030};
   float ratioJpsisystErr[bin]={0.097, 0.077, 0.048, 0.029, 0.016, 0.014};

   float tot1SErr[bin];
   float tot2SErr[bin];

   /**/// p_T-BINNED DATA
 
   //------[GeV/c]-----------------0/2.5-2.5/5--5/8--8/12--12/20//	   
   float raaPt1  [nPtBins_2013] = {0.267,0.403,0.385,0.440,0.444};
   float raaPt1e [nPtBins_2013] = {0.022,0.039,0.041,0.053,0.057};
   float raaPt1s [nPtBins_2013] = {0,0,0,0,0};
   //------[GeV/c]-----------------0/6.5-6.5/10-10/20//
   float raaPt2  [nPtBins_2010] = {0.109,0.101,0.143};
   float raaPt2e [nPtBins_2010] = {0.043,0.070,0.068};
   float raaPt2s [nPtBins_2010] = {0,0,0};
   //-------[max.y]-----------------0.4----0.7---1.----1.5---2.4-//
   float raaRap1 [nRapBins_2013] = {0.362,0.384,0.417,0.497,0.414};
   float raaRap1e[nRapBins_2013] = {0.038,0.043,0.055,0.042,0.038};
   float raaRap1s[nRapBins_2013] = {0.039,0.041,0.055,0.026,0.062};
   //-------[max.y]-----------------0.4----0.7---1.----1.5---2.4-//
   float raaRap2 [nRapBins_2013] = {0.071,0.128,0.133,0.09,0.247};
   float raaRap2e[nRapBins_2013] = {0.053,0.060,0.076,0.056,0.069};
   float raaRap2s[nRapBins_2013] = {0.032,0.033,0.038,0.082,0.092};

   float raaPt2010[nPtBins_2010]= {0.43,0.88,1.72}; // 10-006 published this
   float raaPt2010e[nPtBins_2010]={0.1,0.37,0.74};
   float raaPt2010s[nPtBins_2010]={0.07,0.14,0.25};

float raaRap2010 [nRapBins_2010]={0.52,0.83};
float raaRap2010e[nRapBins_2010]={0.12,0.24};
float raaRap2010s[nRapBins_2010]={0.08,0.13};

   //1S data: pp, then PbPb.
   //------[GeV/c]--------------------0/2.5---2.5/5----5/8----8/12----12/20//	   
   float dndyPt1pp [nPtBins_2013] = {0.218  ,0.152  ,0.158  ,0.107  ,0.0583};
   float dndyPt1ppe[nPtBins_2013] = {0.00975,0.00683,0.00667,0.00535,0.00383};
   float dndyPt1pps[nPtBins_2013] = {0,0,0,0,0};
   //------[GeV/c]--------------------0/2.5---2.5/5----5/8----8/12----12/20//	
   float dndyPt1   [nPtBins_2013] = {0.0583 ,0.0615 ,0.0611 ,0.0475 ,0.0259};
   float dndyPt1e  [nPtBins_2013] = {0.00403,0.00541,0.00613,0.00526,0.0029};
   float dndyPt1s  [nPtBins_2013] = {0,0,0,0,0};
   float dndyPt2010[nPtBins_2010] = {0.293,0.093,0.066}; //10-006 published
   float dndyPt2010e[nPtBins_2010]= {0.057,0.028,0.016};
   float dndyPt2010s[nPtBins_2010]= {0.053,0.017,0.012};
   //must make 2S,3S pp yields in both binnings.
   //dndyPt2pp_2013 refers to the *1S* binning of 2013 for *2S* data
   //dndyPt2pp_2010 refers to the *1S* binning of 2010 for *2S* data

/////2S data: pp, in both binnings, then PbPb in the appropriate one.
   //------[GeV/c]------------------------0/2.5---2.5/5----5/8----8/12----12/20//	
   float dndyPt2pp_2013 [nPtBins_2013] = {0.0762 ,0.0454 ,0.0527 ,0.041  ,0.0219};
   float dndyPt2ppe_2013[nPtBins_2013] = {0.00676,0.0044 ,0.00436,0.00366,0.00252};
   float dndyPt2pps_2013[nPtBins_2013] = {0,0,0,0,0};
   //------[GeV/c]------------------------0/6.5---6.5/10--10/20---//	
   float dndyPt2pp_2010 [nPtBins_2010] = {0.15   ,0.054  ,0.0345 };
   float dndyPt2ppe_2010[nPtBins_2010] = {0.00924,0.00425,0.00324};
   float dndyPt2pps_2010[nPtBins_2010] = {0,0,0};
   float dndyPt2        [nPtBins_2010] = {0.0163 ,0.0055 ,0.00497};
   float dndyPt2e       [nPtBins_2010] = {0.00651,0.00378,0.00231};
   float dndyPt2s       [nPtBins_2010] = {0,0,0};

/////3S data: pp, in 2013 *1S* binning
   //------[GeV/c]------------------------0/2.5---2.5/5----5/8----8/12----12/20//	
   float dndyPt3pp_2013 [nPtBins_2013] = {0.033  ,0.0268 ,0.0262 ,0.0204 ,0.0142 };
   float dndyPt3ppe_2013[nPtBins_2013] = {0.00547,0.00386,0.0036 ,0.00298,0.00218};
   float dndyPt3pps_2013[nPtBins_2013] = {0,0,0,0,0};

   /**/// RAPIDITY-BINNED DATA
   float dndyRap1[5]={0.0545,0.04334,0.04645,0.09095,0.0769};
   float dndyRap1e[5]={0.00539,0.00439,0.00574,0.00677,0.00639};
   float dndyRap2[5]={0,0,0,0,0};
   float dndyRap2e[5]={0,0,0,0,0};

  
   //ALice's shit
   float rapAlice[nRapBins_2010]={2.85,3.6};
   float rapAlicee[nRapBins_2010]={0.35,0.4};
   float raaRapAlice [nRapBins_2010]={0.429,0.457};
   float raaRapAlicee[nRapBins_2010]={0.084,0.106};
   float raaRapAlicesup[nRapBins_2010]={0.052,0.100};
   float raaRapAlicesdown[nRapBins_2010]={0.068,0.128};
   float raaRapAliceglob[nRapBins_2010]={0.094,0.1};
   //

   float dndyNP2010[5]={0.468,0.517,0.643,0.347};
   float dndyNP2010e[5]={0.081,0.101,0.144,0.096};
   float dndyNP2010s[5]={0.094,0.101,0.118,0.069};
   
   float dndyNP1[9]={0.989,0.542,0.440,0.454,0.324,0.317,0.238,0.300};
   float dndyNP1e[9]={0.215,0.0625,0.066,0.0515,0.0346,0.0288,0.0238,0.0382};
   float dndyNP1s[9]={0,0,0,0,0,0,0,0};
   float dndyNP2[5]={0.235,0.067,0.0365,0.0183};
   float dndyNP2e[5]={0.0102,0.0147,0.0165,0.0128};
   float dndyNP2s[5]={0,0,0,0};
   

 float dndyRap1pp[5]={0.1533,0.115,0.113,0.186,0.189};
 float dndyRap1ppe[5]={0.0063,0.00569,0.00574,0.00767,0.00776};
 // float dndyRap1pps[5]={};
 float dndyRap2pp[5]={0.0521,0.0408,0.0406,0.0683,0.066};
 float dndyRap2ppe[5]={0.00414,0.0037,0.00394,0.00487,0.00569};
 // float dndyRap2pps[5]={};
 float dndyRap3pp[5]={0.0265,0.0178,0.0247,0.032,0.0383};
 float dndyRap3ppe[5]={0.00333,0.00297,0.00344,0.00389,0.00528};
 // float dndyRap1pps[5]={};
 float dndyRap2010[3]={0.495,0.498};
 float dndyRap2010e[3]={0.091,0.097};
 float dndyRap2010s[3]={0.091,0.092};

 
 // MB stuff !?
  //MB
  
  //pt > 4
  float centMB[1]={0.5};
  float centMB2S[1]={0.3};
  float centMBA[1]={0.4};
  float centMB3S[1]={0.7};
  float cent_limit_err[1]={0.1};
  // float raaMB1S[1]={0.564};
  // float raaMB1SstatErr[1]={0.077};
  // float raaMB1SsystErr[1]={0.071};
  // float raaMB2S[1]={0.120};
  // float raaMB2SstatErr[1]={0.038};
  // float raaMB2SsystErr[1]={0.020};
  // float raaMB3S[1]={0.033};
  // float raaMB3SstatErr[1]={0.035};//{0.035};
  // float raaMB3SsystErr[1]={0.006};
  
  float raaMB1S[1]={0.511};
  float raaMB1SstatErr[1]={0.026};
  float raaMB1SsystErr[1]={0.016};
  float raaMB2S[1]={0.126};
  float raaMB2SstatErr[1]={0.03};
  float raaMB2SsystErr[1]={0.021};
  float raaMB3S[1]={0.033};
//  float raaMB3SstatErr[1]={0.035};//{0.035};
//  float raaMB3SsystErr[1]={0.006};
  
  /// MB result!
  
  float raaMB1 [1]={0.388};
  float raaMB1e[1]={0.018};
  float raaMB1s[1]={0.042};
  
  float raaMB2 [1]={0.106};
  float raaMB2e[1]={0.026};
  float raaMB2s[1]={0.018};
  
  float raaMB3 [1]={0.046};
  float raaMB3e[1]={0.045};
  float raaMB3s[1]={0.028};
  
  float raaMB3Slimit[1]={0.1};
  float raaMBJpsi[1]={0.304};
  float raaMBJpsistatErr[1]={0.025};
  float raaMBJpsisystErr[1]={0.022};
  // float raaMBAlice[1]={0.439};
  // float raaMBAliceStat[1]={0.065};
  // float raaMBAliceSyst[1]={0.028};
  
  float raaMB1StotErr =sqrt(pow(raaMB1e[0],2)+pow(raaMB1s[0],2));
  float raaMB2StotErr =sqrt(pow(raaMB2e[0],2)+pow(raaMB2s[0],2));
  float raaMB3StotErr =sqrt(pow(raaMB3e[0],2)+pow(raaMB3s[0],2));
  
  float ppy[1]={1};
  float ppx[1]={377};
  float ppxEr[1]={0};
  float ppyErSystematic=sqrt(pow(0.06,2)+pow(0.023,2));
  float ppyErSyst[1]={ppyErSystematic};
  float ppyErtol[1]={0}; 

  float Y2Sppx[1]={392};
  float Y2SppyErSystematic=sqrt(pow(0.06,2)+pow(0.033,2));
  float Y2SppyErSyst[1]={Y2SppyErSystematic};
  float Y2SppyErtotal=sqrt(pow(Y2SppyErSystematic,2)+pow(0.202,2));
  float Y2SppyErtol[1]={0};
  float centMBErr[1]={0.15};

// doubledifferential Npart/rapidity
 // !!!! first entry is |y|<1, second entry is 1<|y|<2.4 !!!!
 float raaRN1_c [2] = {0.364,0.407}; // central values
 float raaRN1e_c[2] = {0.036,0.047};
 float raaRN1s_c[2] = {0.033,0.029};

 float raaRN2_c [2] = {0.073,0.127};
 float raaRN2e_c[2] = {0.048,0.061};
 float raaRN2s_c[2] = {0.056,0.058};

 float raaRN3_c [2] = {-0.04,0.108};
 float raaRN3e_c[2] = {0.   ,0.105};
 float raaRN3s_c[2] = {0.   ,0.035};

 float raaRN1_p [2] = {0.423,0.596}; // non-central (20-100) values
 float raaRN1e_p[2] = {0.035,0.047};
 float raaRN1s_p[2] = {0.102,0.033};

 float raaRN2_p [2] = {0.168,0.296};
 float raaRN2e_p[2] = {0.057,0.076};
 float raaRN2s_p[2] = {0.160,0.027};

 float raaRN3_p [2] = {0.145,0.152};
 float raaRN3e_p[2] = {0.107,0.129};
 float raaRN3s_p[2] = {0.064,0.024};

 float rap_short_c[2] = {0.45,1.65};
 float rap_short_p[2] = {0.55,1.75};
 float rap_short_3[2] = {0.58,1.78};
 float rap_shorte[2]= {0.55,0.65};



////EFFICIENCY and acceptance 20th Nov 2014
//A. Pythia sample. 1S //table 6
////JUNE 18th
// total acc*eff 1S = 0.449 +/- 0.0007
float Ae_1S_pythia_pt[nPtBins_2013] = {0.296,0.190,0.185,0.259,0.376};
float Ae_1S_pythia_pte[nPtBins_2013] = {0.001,0.001,0.001,0.002,0.004};
float Ae_1S_pythia_rap2014[nRapBins_2014]={0.267,0.268,0.270,0.255,0.203,0.072};
float Ae_1S_pythia_rap2014e[nRapBins_2014]={0.0011,0.001,0.0012,0.0011,0.0010,0.0006};
 //B. 2S pythia with binning of 2S. with raa_pt-y 2S in mind. //  //tables 16 and 17 of note apr20 /// should be wrong because of the trigger.
///// July 15th - Prashant
float Ae_2S_pythia_pt2010[nPtBins_2010] = {0.199,0.183,0.310};
float Ae_2S_pythia_pt2010e[nPtBins_2010] = {0.0005,0.0012,0.0027};
float Ae_2S_pythia_rap2010[nRapBins_2010] = {0.237,0.161};
float Ae_2S_pythia_rap2010e[nRapBins_2010] = {0.0007,0.0006};
/* float Ae_2S_pythia_pt2010[nPtBins_2010] = {0.231,0.229,0.368}; */
/* float Ae_2S_pythia_pt2010e[nPtBins_2010] = {0.0004,0.0010,0.0022}; */
/* float Ae_2S_pythia_rap2010[nRapBins_2010] = {0.247,0.224}; */
/* float Ae_2S_pythia_rap2010e[nRapBins_2010] = {0.0005,0.0006}; */

//B.2 2S pythia with binning even, and binning of 1S. //tables 16 and 17 of note may 6th
// total acc*eff 2S = 0.375 +/- 0.006
///// July 15th - Prashant
float Ae_2S_pythia_pt2013[nPtBins_2013]={0.269,0.157,0.160,0.229,0.351};
float Ae_2S_pythia_pt2013e[nPtBins_2013]={0.0010,0.006,0.0008,0.0018,0.0043};
float Ae_2S_pythia_rap2014[nRapBins_2014]={0.237,0.239,0.236,0.219,0.175,0.060};//bug was here.
float Ae_2S_pythia_rap2014e[nRapBins_2014]={0.0012,0.0012,0.0012,0.0012,0.0011,0.0005};
/* float Ae_2S_pythia_pt2013[nPtBins_2013]={0.469,0.299,0.323,0.423,0.559}; */
/* float Ae_2S_pythia_pt2013e[nPtBins_2013]={0.0013,0.009,0.0013,0.0024,0.0047}; */
/* float Ae_2S_pythia_rap2014[nRapBins_2014]={0.421,0.392,0.377,0.361,0.347,0.261};//bug was here. */
/* float Ae_2S_pythia_rap2014e[nRapBins_2014]={0.0015,0.0014,0.0014,0.0014,0.0016,0.0021}; */

//B.3 3S pythia with binning even, and binning of 1S. //tables 16 and 17 of note may 6th
//total 3S acc*eff = 0.246
///// July 15th, Prashant
float Ae_3S_pythia_pt2013[nPtBins_2013]={0.333,0.199,0.187,0.253,0.374};
float Ae_3S_pythia_pt2013e[nPtBins_2013]={0.001,0.001,0.001,0.001,0.002};
float Ae_3S_pythia_rap2014[nRapBins_2014]={0.293,0.293,0.286,0.264,0.202,0.071};//,0.1825};//bug is fixed!
float Ae_3S_pythia_rap2014e[nRapBins_2014]={0.001,0.001,0.001,0.001,0.001,0.001};//,0.005149};
/* float Ae_3S_pythia_pt2013[nPtBins_2013]={0.538,0.351,0.357,0.455,0.588}; */
/* float Ae_3S_pythia_pt2013e[nPtBins_2013]={0.0018,0.001,0.0012,0.0018,0.0028}; */
/* float Ae_3S_pythia_rap2014[nRapBins_2014]={0.475,0.450,0.436,0.421,0.394,0.280};//,0.1825};//bug is here */
/* float Ae_3S_pythia_rap2014e[nRapBins_2014]={0.0015,0.0014,0.0014,0.0015,0.0017,0.0022};//,0.005149}; */

//C. Pyquen Sample 1S. //table 18 // updated June13

 // last bin is  good today.  but values are screwed
//float Ae_1S_pyquen_pt[nPtBins_2013] = {0.348,0.228,0.239,0.342,0.486};
//float Ae_1S_pyquen_pte[nPtBins_2013] = {0.0031,0.0020,0.0023,0.027,0.0031}; // 
///// July 15th, Prashant
float Ae_1S_pyquen_pt[nPtBins_2013] = {0.262,0.169,0.174,0.250,0.370};
float Ae_1S_pyquen_pte[nPtBins_2013] = {0.0026,0.0017,0.0020,0.0023,0.0032}; // 
/* float Ae_1S_pyquen_rap[nRapBins_2013] = {0.227,0.252,0.291,0.323,0.299};// table 21 */
float Ae_1S_pyquen_rap2014[nRapBins_2014]={0.223,0.235,0.249,0.243,0.197,0.073};
float Ae_1S_pyquen_rap2014e[nRapBins_2014]={0.0025,0.0026,0.0028,0.0029,0.0027,0.0018};//,0.003386};
//float Ae_1S_pyquen_rap2014[nRapBins_2014]={0.236,0.267,0.314,0.332,0.324,0.220}; // bug is here.
//float Ae_1S_pyquen_rap2014e[nRapBins_2014]={0.0023,0.0026,0.0031,0.0035,0.0041,0.0049};//,0.003386};

//float Ae_1S_pyquen_rape[nRapBins_2013] = {0.0024,0.0031,0.0036,0.0031,0.0031};
/* float Ae_1S_pyquen_cent[bin1] = {0.2,0.280,0.286,0.285,0.279,0.274,0.267}; //starting with peripheral bin!//table 21  */
//float Ae_1S_pyquen_cent2014[nCentBins_2014]={0.299,0.299,0.297,0.295,0.293,0.287,0.280,0.272};//starting with peripheral bin!//table 20 from may 6 (havent changed much.)
float Ae_1S_pyquen_cent2014[nCentBins_2014]={0.222,0.221,0.218,0.217,0.216,0.212,0.207,0.200};//starting with peripheral bin!//table 20 from may 6 (havent changed much.)
/* float Ae_1S_pyquen_cente[bin1] = {0.0017,0.0027,0.0027,0.0027,0.0026,0.0036,0.0031}; */
//float Ae_1S_pyquen_cent2014e[nCentBins_2014]={0.0018,0.0020,0.0026,0.0025,0.0026,0.0025,0.0035,0.0030};
float Ae_1S_pyquen_cent2014e[nCentBins_2014]={0.0015,0.0016,0.0021,0.0021,0.0021,0.020,0.0029,0.0024};


//D. Pyquen sample 2S. with binning of 2S. // with 
// total 2S acc*eff = 0.254 +/- 0.0022
float Ae_2S_pyquen_pt[nPtBins_2010] = {0.185,0.182,0.3051}; //table 25
float Ae_2S_pyquen_pte[nPtBins_2010] = {0.001,0.002,0.004};
float Ae_2S_pyquen_rap[nRapBins_2010] = {0.219,0.159};  //table 26
float Ae_2S_pyquen_rape[nRapBins_2010] = {0.002,0.002};
float Ae_2S_pyquen_cent2014[bin1]={0.200,0.198,0.197,0.195,0.193,0.192,0.185};
float Ae_2S_pyquen_cent2014e[bin1] = {0.0016,0.0022,0.0022,0.0022,0.0021,0.0030,0.0025};
/* float Ae_1S_pyquen_rap2014[nRapBins_2014]= {0.211,0.220,0.225,0.216,0.177,0.062}; */
/* float Ae_1S_pyquen_rap2014e[nRapBins_2014]={0.003,0.003,0.003,0.003,0.0030,0.002};//,0.003386}; */
float Ae_2S_pyquen_rap2014[nRapBins_2014]= {0.211,0.220,0.225,0.216,0.177,0.062};
float Ae_2S_pyquen_rap2014e[nRapBins_2014]={0.003,0.003,0.003,0.003,0.003,0.002};
//float Ae_2S_pyquen_cent2014[nCentBins_2014] ={0.266,0.264,0.265,0.263,0.263,0.255,0.254,0.245};
//float Ae_2S_pyquen_cent2014e[nCentBins_2014]={0.0017,0.0018,0.0024,0.0024,0.0024,0.0023,0.0033,0.0028};

float Ae_1S_pythia_tot= 0.2310;
float Ae_1S_pythia_tote=0.0006;
float Aet_1S_pythia_tot=0.252;
float Aet_1S_pythia_tote = 0.001;
float Aet_1S_pythia_tot4=0.168;
float Aet_1S_pythia_tot4e = 0.001;
float t_1S_pythia_tot3p5 = 1.089;
float t_1S_pythia_tot4 = 1.072;

float Ae_2S_pythia_tot= 0.201;
float Ae_2S_pythia_tote=0.0006;
float Aet_2S_pythia_tot= 0.215;
float Aet_2S_pythia_tote= 0.001;

float Aet_2S_pythia_tot3p5= 0.276;
float Aet_2S_pythia_tot3p5e= 0.001;
float t_2S_pythia_tot= 1.068;

float Aet_3S_pythia_tot= 0.246;
float Aet_3S_pythia_tote=0.001;
float t_3S_pythia_tot = 1.056;

float Ae_1S_pyquen_tot=0.210;
float Ae_1S_pyquen_tote=0.0009;
float Aet_1S_pyquen_tot=0.229;
float Aet_1S_pyquen_tote=0.002;
float t_1S_pyquen_tot3p5=1.087;
float t_1S_pyquen_tot4=1.070;

float Ae_2S_pyquen_tot=0.1918;
float Ae_2S_pyquen_tote=0.0010;
float Aet_2S_pyquen_tot=0.205;
float Aet_2S_pyquen_tote=0.002;
float Aet_2S_pyquen_tot3p5=0.276;
float Aet_2S_pyquen_tot3p5e=0.002;
float t_2S_pyquen_tot=1.067;
///for FUN
float Aet_3S_pyquen_tot=0.2003;
float Aet_3S_pyquen_tote=0.02;

/*

0,1918/0,201=0,954
0,210*0,1918/0,201=0.2003

max. 10%uncertainty on this from varying ratio eff vs pt or rapidity
-> effPyquen3S tot = 0.2003+/-0.02

 */
//June 18th
//fiducial purposes...
/* float A_1S_pythia_pp_pt3p5[nPtBins_2013]={0.56,0.552,0.598,0.637,0.677}; */
/* float A_1S_pythia_pp_pt3p5e[nPtBins_2013]={0.0109,0.0107,0.0142,0.243}; */
//rap in bins called 2014, pt in bins called 2013
//eff tot 1S = 0.656 +/- 0.0011
// acc tot 1S =0.3520 +/- 0.0007
// tnp tot 1S = 1.089 +/- 0.002(?)

float A_1S_pythia_pt3p5[nPtBins_2013]={0.457,0.299,0.277,0.372,0.51};
float A_1S_pythia_pt3p5e[nPtBins_2013]={0.0001,0.0001,0.0001,0.001,0.002};
float e_1S_pythia_pt3p5[nPtBins_2013]={0.646,0.634,0.669,0.697,0.738};
float e_1S_pythia_pt3p5e[nPtBins_2013]={0.0019,0.0019,0.0027,0.0036,0.0051};
float A_1S_pythia_rap3p5[nRapBins_2014]={0.391,0.390,0.392,0.388,0.341,0.147};
float A_1S_pythia_rap3p5e[nRapBins_2014]={0.0001,0.0001,0.0001,0.0001,0.0001,0.0001};
float e_1S_pythia_rap3p5[nRapBins_2014]={0.686,0.689,0.692,0.654,0.598,0.484};
float e_1S_pythia_rap3p5e[nRapBins_2014]={0.0025,0.0025,0.0025,0.0025,0.0027,0.0038};
float t_1S_pythia_pt3p5[nPtBins_2013]={1.108,1.1,1.077,1.057,1.037};
float t_1S_pythia_pt3p5e[nPtBins_2013]={0.004,0.004,0.005,0.006,0.008};
float t_1S_pythia_rap3p5[nRapBins_2014]={1.069,1.069,1.076,1.099,1.138,1.160};
float t_1S_pythia_rap3p5e[nRapBins_2014]={0.004,0.004,0.004,0.005,0.006,0.011};
float t_1S_pythia_pt4[nPtBins_2013]={1.095,1.081,1.062,1.046,1.031};
float t_1S_pythia_pt4e[nPtBins_2013]={0.004,0.004,0.005,0.006,0.008};
float t_1S_pythia_rap4[nRapBins_2014]={1.052,1.052,1.057,1.081,1.125,1.151};
float t_1S_pythia_rap4e[nRapBins_2014]={0.004,0.004,0.004,0.005,0.007,0.013};
//eff tot 2S = 0.718 +/- 0.0013
//acc tot 2S =  0.28 +/- 0.000X
//tnp tot 2S = 1.067 +/- 0.002
float A_2S_pythia_pt2013[nPtBins_2013]=   {0.38,0.22,0.22,0.31,0.46};
float A_2S_pythia_pt2013e[nPtBins_2013]=  {0.0001,0.0001,0.0001,0.0001,0.0001};
float e_2S_pythia_pt2013[nPtBins_2013]=   {0.709,0.716,0.728,0.740,0.765};
float e_2S_pythia_pt2013e[nPtBins_2013]=  {0.0022,0.0024,0.0034,0.0047,0.0069};
float A_2S_pythia_rap2014[nRapBins_2014]= {0.31,0.31,0.31,0.31,0.28,0.12};
float A_2S_pythia_rap2014e[nRapBins_2014]={0.0001,0.0001,0.0001,0.0001,0.0001,0.0001};
float e_2S_pythia_rap2014[nRapBins_2014]= {0.766,0.722,0.761,0.708,0.625,0.503};
float e_2S_pythia_rap2014e[nRapBins_2014]={0.0031,0.0032,0.0032,0.0032,0.0032,0.0045};
float t_2S_pythia_pt4[nPtBins_2013]={1.08,1.072,1.057,1.045,1.031};
float t_2S_pythia_pt4e[nPtBins_2013]={0.004,0.004,0.005,0.007,0.010};
float t_2S_pythia_rap4[nRapBins_2014]={1.049,1.049,1.053,1.077,1.12,1.146};
float t_2S_pythia_rap4e[nRapBins_2014]={0.005,0.005,0.005,0.005,0.006,0.012};

float t_3S_pythia_pt4[nPtBins_2013]={1.072,1.067,1.054,1.043,1.03};
float t_3S_pythia_pt4e[nPtBins_2013]={0.004,0.004,0.005,0.007,0.010};
float t_3S_pythia_rap4[nRapBins_2014]={1.037,1.037,1.043,1.068,1.111,1.139};
float t_3S_pythia_rap4e[nRapBins_2014]={0.005,0.005,0.005,0.005,0.006,0.012};
//eff tot 3S = 0.750 +/- 0.0013
//acc tot 3S = 0.33 +/- 0.004
float A_3S_pythia_pt2013[nPtBins_2013]=   {0.455,0.273,0.249,0.330,0.470};
float A_3S_pythia_pt2013e[nPtBins_2013]=  {0.003,0.002,0.003,0.003,0.004};
float e_3S_pythia_pt2013[nPtBins_2013]=   {0.731,0.731,0.751,0.769,0.795};
float e_3S_pythia_pt2013e[nPtBins_2013]=  {0.0026,0.0024,0.0029,0.0033,0.0041};
float A_3S_pythia_rap2014[nRapBins_2014]= {0.365,0.365,0.364,0.360,0.312,0.136}; // ooh...
float A_3S_pythia_rap2014e[nRapBins_2014]={0.0017,0.0016,0.0016,0.0017,0.002,0.0028}; // oooh
float e_3S_pythia_rap2014[nRapBins_2014]= {0.802,0.803,0.786,0.733,0.647,0.519};
float e_3S_pythia_rap2014e[nRapBins_2014]={0.0029,0.0029,0.003,0.0029,0.0031,0.0044};
//2010 bins ... :/
float A_2S_pythia_rap2010[nRapBins_2010]= {0.31,0.25};
float A_2S_pythia_rap2010e[nRapBins_2010]={0.0005,0.0008};
float e_2S_pythia_rap2010[nRapBins_2010]= {0.767,0.647};
float e_2S_pythia_rap2010e[nRapBins_2010]={0.0016,0.0017};
float t_2S_pythia_rap2010[nRapBins_2010]={1.050,1.101};
float t_2S_pythia_rap2010e[nRapBins_2010]={0.001,0.001};
float A_2S_pythia_pt2010[nPtBins_2010]= {0.28,0.25,0.41};
float A_2S_pythia_pt2010e[nPtBins_2010]={0.0002,0.0002,0.0041};
float e_2S_pythia_pt2010[nPtBins_2010]= {0.714,0.735,0.757};
float e_2S_pythia_pt2010e[nPtBins_2010]={0.0015,0.004,0.0051};
float t_2S_pythia_pt2010[nPtBins_2010] = {1.074,1.050,1.035};
float t_2S_pythia_pt2010e[nPtBins_2010] = {0.001,0.002,0.005};


//Pyquen 1S
float e_1S_pyquen_pt[nPtBins_2013]={0.571,0.565,0.623,0.677,0.726};
float e_1S_pyquen_pte[nPtBins_2013]={0.0055,0.0058,0.007,0.006,0.0049};
float A_1S_pyquen_pt[nPtBins_2013]={0.46,0.30,0.28,0.37,0.51};
float A_1S_pyquen_pte[nPtBins_2013]={0.0009,0.0001,0.0006,0.0012,0.0027};
float e_1S_pyquen_rap2014[nRapBins_2014]={0.572,0.603,0.639,0.625,0.580,0.491};
float e_1S_pyquen_rap2014e[nRapBins_2014]={0.0062,0.0066,0.0071,0.0073,0.0080,0.0121};
float A_1S_pyquen_rap2014[nRapBins_2014]={0.391,0.390,0.392,0.388,0.341,0.147};
float A_1S_pyquen_rap2014e[nRapBins_2014]={0.0009,0.0009,0.0009,0.0009,0.0009,0.0004};
float e_1S_pyquen_cent2014[nCentBins_2014]={0.634,0.632,0.625,0.621,0.618,0.606,0.594,0.572};
float e_1S_pyquen_cent2014e[nCentBins_2014]={0.0043,0.0046,0.0061,0.0060,0.0060,0.0058,0.0082,0.0070};
float A_1S_pyquen_cent2014[nCentBins_2014]={0.35,0.35,0.35,0.35,0.35,0.35,0.35,0.35};
float A_1S_pyquen_cent2014e[nCentBins_2014]={0.0043,0.0046,0.0061,0.0060,0.0060,0.0058,0.0082,0.0070}; // starting with the peripheral value!!!
float t_1S_pyquen_pt3p5[nPtBins_2013]={1.106,1.098,1.077,1.056,1.038};
float t_1S_pyquen_pt3p5e[nPtBins_2013]={0.012,0.013,0.014,0.010,0.008};
float t_1S_pyquen_rap3p5[nRapBins_2014]={1.064,1.064,1.072,1.097,1.143,1.168};
float t_1S_pyquen_rap3p5e[nRapBins_2014]={0.013,0.013,0.013,0.014,0.018,0.033};
float t_1S_pyquen_pt4[nPtBins_2013]={1.093,1.079,1.061,1.045,1.032};
float t_1S_pyquen_pt4e[nPtBins_2013]={0.012,0.013,0.014,0.010,0.008};
float t_1S_pyquen_rap4[nRapBins_2014]={1.048,1.048,1.053,1.079,1.130,1.157};
float t_1S_pyquen_rap4e[nRapBins_2014]={0.013,0.013,0.013,0.014,0.018,0.033};
float t_1S_pyquen_cent2014[nCentBins_2014]={1.090,1.088,1.087,1.087,1.087,1.087,1.087,1.087};
float t_1S_pyquen_cent2014e[nCentBins_2014]={0.008,0.009,0.012,0.012,0.012,0.012,0.017,0.015};
float t_1S_pyquen_cent42014[nCentBins_2014]={1.073,1.071,1.070,1.070,1.070,1.070,1.070,1.069};
float t_1S_pyquen_cent42014e[nCentBins_2014]={0.010,0.010,0.013,0.013,0.014,0.013,0.019,0.017};
/* float e_1S_pyquen_rap[nRapBins_2010]={}; */
/* float e_1S_pyquen_rape[nRapBins_2010]={}; */
/* float A_1S_pyquen_rap[nRapBins_2010]={}; */
/* float A_1S_pyquen_rape[nRapBins_2010]={}; */

float t_2S_pyquen_pt[nPtBins_2013]={1.078,1.071,1.057,1.045,1.032};
float t_2S_pyquen_pte[nPtBins_2013]={0.012,0.014,0.015,0.011,0.007};
float t_2S_pyquen_rap[nRapBins_2014]={1.044,1.044,1.050,1.077,1.125,1.154};
float t_2S_pyquen_rape[nRapBins_2014]={0.013,0.013,0.013,0.014,0.018,0.033};
float t_2S_pyquen_cent2014[bin1]={1.067,1.067,1.067,1.0670,1.067,1.066,1.066};
float t_2S_pyquen_cent2014e[bin1]={0.010,0.013,0.013,0.013,0.013,0.018,0.016};
float e_2S_pyquen_rap2010[nRapBins_2010]= {0.710,0.647};
float e_2S_pyquen_rap2010e[nRapBins_2010]={0.005,0.006};
float A_2S_pyquen_rap2010[nRapBins_2010]= {0.343,0.424};
float A_2S_pyquen_rap2010e[nRapBins_2010]={0.0016,0.0025};
float e_2S_pyquen_pt2010[nPtBins_2010]=   {0.674,0.718,0.749};
float e_2S_pyquen_pt2010e[nPtBins_2010]=  {0.0047,0.0074,0.0049};
float A_2S_pyquen_pt2010[nPtBins_2010]=   {0.28,0.25,0.41};
float A_2S_pyquen_pt2010e[nPtBins_2010]=  {0.0004,0.0009,0.0024};
float t_2S_pyquen_rap2010[nRapBins_2010]= {1.046,1.103};
float t_2S_pyquen_rap2010e[nRapBins_2010]={0.008,0.012};
float t_2S_pyquen_pt2010[nPtBins_2010]=   {1.073,1.05,1.036};
float t_2S_pyquen_pt2010e[nPtBins_2010]=  {0.008,0.012,0.007};



//28th april 2014 
//integrated values!
/* pp Y(1S) */
/* Upsilon eff Total 0.560949 error 0.000954518 */
/* Upsilon Acc*eff Total 0.26641 error 0.000408323 */

/* pp Y(2S) */
/* Upsilon eff Total 0.640482 error 0.00123349 */
/* Upsilon Acc*eff Total 0.239197 error 0.000400378 */

/* PbPb Y(1S) */
/* Upsilon eff Total 0.587255 error 0.0073492 */
/* Upsilon Acc*eff Total 0.274313 error 0.0025024 */

/* PbPb Y(2S) */
/* Upsilon eff Total 0.686029 error 0.00928091 */
/* Upsilon Acc*eff Total 0.254253 error 0.00226777 */

///Tag and probe correction of corrections
float Aet_1S_pythia_pt[nPtBins_2013+1]={0.328,0.209,0.199,0.274,0.390,0.41};
float Aet_1S_pythia_pte[nPtBins_2013+1]={0.002,0.001,0.002,0.003,0.005,0.01};

/* float Aet_1S_pythia_pt[nPtBins_2013]={0.328,0.209,0.199,0.274,0.390}; */
/* float Aet_1S_pythia_pte[nPtBins_2013]={0.002,0.001,0.002,0.003,0.005}; */

float Aet_1S_pythia_rap2014[nRapBins_2014]={0.287,0.287,0.292,0.279,0.232,0.082};
float Aet_1S_pythia_rap2014e[nRapBins_2014]={0.002,0.002,0.002,0.002,0.002,0.001};
//updating now with loose, the 2S (24Feb)
/* float Aet_2S_pythia_pt2013[nPtBins_2013]={0.295,0.168,0.167,0.236,0.363}; */
/* float Aet_2S_pythia_pt2013e[nPtBins_2013]={0.002,0.001,0.002,0.003,0.007}; */
/* float Aet_2S_pythia_rap2014[nRapBins_2014]={0.248,0.249,0.246,0.235,0.197,0.071}; */
/* float Aet_2S_pythia_rap2014e[nRapBins_2014]={0.002,0.002,0.002,0.002,0.002,0.001}; */

float Aet_2S_pythia_pt2013[nPtBins_2013]={0.38,0.274,0.227,0.287,0.401};
float Aet_2S_pythia_pt2013e[nPtBins_2013]={0.002,0.002,0.002,0.004,0.008};
float Aet_2S_pythia_rap2014[nRapBins_2014]={0.345,0.345,0.346,0.334,0.268,0.093};
float Aet_2S_pythia_rap2014e[nRapBins_2014]={0.002,0.002,0.002,0.002,0.002,0.001};

float Aet_3S_pythia_pt2013[nPtBins_2013]={0.357,0.213,0.197,0.264,0.385};
float Aet_3S_pythia_pt2013e[nPtBins_2013]={0.002,0.001,0.001,0.002,0.003};
float Aet_3S_pythia_rap2014[nRapBins_2014]={0.304,0.303,0.299,0.281,0.224,0.081};
float Aet_3S_pythia_rap2014e[nRapBins_2014]={0.002,0.002,0.002,0.002,0.002,0.001};

float Aet_3S_pythia_pt2013Loose[nPtBins_2013]={0.428,0.325,0.263,0.317,0.423};
float Aet_3S_pythia_pt2013Loosee[nPtBins_2013]={0.002,0.001,0.001,0.002,0.003};
float Aet_3S_pythia_rap2014Loose[nRapBins_2014]={0.393,0.392,0.391,0.371,0.286,0.101};
float Aet_3S_pythia_rap2014Loosee[nRapBins_2014]={0.002,0.002,0.002,0.002,0.002,0.001};

/* float Aet_1S_pyquen_pt[nPtBins_2013]={0.289,0.186,0.185,0.266,0.384}; */
/* float Aet_1S_pyquen_pte[nPtBins_2013]={0.004,0.003,0.003,0.004,0.005}; */

float Aet_1S_pyquen_pt[nPtBins_2013+1]={0.289,0.186,0.185,0.266,0.384,0.4};
float Aet_1S_pyquen_pte[nPtBins_2013+1]={0.004,0.003,0.003,0.004,0.005,0.01};

float Aet_1S_pyquen_rap2014[nRapBins_2014]={0.238,0.250,0.269,0.266,0.226,0.084};
float Aet_1S_pyquen_rap2014e[nRapBins_2014]={0.004,0.004,0.005,0.005,0.005,0.003};
float Aet_1S_pyquen_cent2014[nCentBins_2014]={0.243,0.242,0.239,0.238,0.236,0.232,0.227,0.219};
float Aet_1S_pyquen_cent2014e[nCentBins_2014]={0.003,0.003,0.004,0.003,0.004,0.003,0.005,0.004};
float Aet_1S_pyquen_cent2014Super[nCentBins_2014+1]={0.243,0.242,0.239,0.238,0.236,0.232,0.227,0.219,0.219};
float Aet_1S_pyquen_cent2014Supere[nCentBins_2014+1]={0.003,0.003,0.004,0.003,0.004,0.003,0.005,0.004,0.004};

float Aet_2S_pythia_pt2013Large[nPtBins_2010]={0.212,0.196,0.321};
float Aet_2S_pythia_pt2013Largee[nPtBins_2010]={0.001,0.002,0.005};
float Aet_2S_pythia_rap2014Large[nRapBins_2010]={0.249,0.175};
float Aet_2S_pythia_rap2014Largee[nRapBins_2010]={0.001,0.001};

float Aet_2S_pyquen_pt2013Large[nPtBins_2010]={0.208,0.181,0.361};
float Aet_2S_pyquen_pt2013Largee[nPtBins_2010]={0.002,0.003,0.006};
float Aet_2S_pyquen_rap2014Large[nRapBins_2010]={0.229,0.175};
float Aet_2S_pyquen_rap2014Largee[nRapBins_2010]={0.003,0.003};

float Aet_2S_pythia_pt2013LooseLarge[nPtBins_2010]={0.318,0.244,0.401};
float Aet_2S_pythia_pt2013LooseLargee[nPtBins_2010]={0.001,0.002,0.008};
float Aet_2S_pythia_rap2014LooseLarge[nRapBins_2010]={0.345,0.242};
float Aet_2S_pythia_rap2014LooseLargee[nRapBins_2010]={0.002,0.001};

float Aet_2S_pyquen_pt2013LooseLarge[nPtBins_2010]={0.290,0.231,0.394};
float Aet_2S_pyquen_pt2013LooseLargee[nPtBins_2010]={0.002,0.003,0.007};
float Aet_2S_pyquen_rap2014LooseLarge[nRapBins_2010]={0.307,0.238};
float Aet_2S_pyquen_rap2014LooseLargee[nRapBins_2010]={0.003,0.003};
//end of update
float Aet_2S_pyquen_pt2013[nPtBins_2013]={0.275,0.160,0.161,0.232,0.361};
float Aet_2S_pyquen_pt2013e[nPtBins_2013]={0.004,0.003,0.003,0.004,0.006};
float Aet_2S_pyquen_rap2014[nRapBins_2014]={0.220,0.230,0.236,0.233,0.199,0.071};
float Aet_2S_pyquen_rap20104e[nRapBins_2014]={0.004,0.004,0.005,0.005,0.005,0.003};
float Aet_2S_pyquen_cent2014[nCentBins_2014]={0.214,0.213,0.211,0.209,0.206,0.205,0.200,0.198};
float Aet_2S_pyquen_cent2014e[nCentBins_2014]={0.003,0.004,0.004,0.004,0.003,0.005,0.004,0.004};

float Aet_2S_pyquen_cent2bin[nCentBins_2014]={0.205};
float Aet_2S_pyquen_2Scentbins[nCentBins_2S]={0.214,0.212,0.206,0.199};
float Aet_2S_pyquen_2Scentbinse[nCentBins_2S]={0.002,0.002,0.002,0.002};// completely ad-hoc .

///PT 4 stuff
float Aet_1S_pythia_pt4[nPtBins_2013]={0.206,0.120,0.142,0.224,0.355};
float Aet_1S_pythia_pt4e[nPtBins_2013]={0.001,0.001,0.001,0.002,0.005};
float Aet_1S_pythia_rap42014[nRapBins_2014]={0.192,0.195,0.193,0.180,0.154,0.058};
float Aet_1S_pythia_rap42014e[nRapBins_2014]={0.002,0.002,0.002,0.002,0.002,0.001};
float Aet_1S_pyquen_pt4[nPtBins_2013]={0.189,0.111,0.136,0.223,0.354};
float Aet_1S_pyquen_pt4e[nPtBins_2013]={0.004,0.002,0.003,0.004,0.005};
float Aet_1S_pyquen_rap42014[nRapBins_2014]={0.168,0.178,0.183,0.178,0.151,0.059};
float Aet_1S_pyquen_rap42014e[nRapBins_2014]={0.003,0.004,0.004,0.004,0.004,0.003};
float Aet_1S_pyquen_cent42014[nCentBins_2014]={0.166,0.166,0.164,0.164,0.163,0.160,0.157,0.152};
float Aet_1S_pyquen_cent42014e[nCentBins_2014]={0.003,0.004,0.003,0.003,0.003,0.003,0.002,0.002};

//// Double differential // Large Bins
float Aet_1S_pythia_ptLarge[nPtBins_2010]={0.257,0.222,0.390};
float Aet_1S_pythia_ptLargee[nPtBins_2010]={0.001,0.01,0.005};
float Aet_1S_pythia_rapLarge[nRapBins_2010]={0.289,0.207};
float Aet_1S_pythia_rapLargee[nRapBins_2010]={0.001,0.001};
float Aet_1S_pyquen_ptLarge[nPtBins_2010]={0.228,0.210,384};   //pyquen, cent. integrated
float Aet_1S_pyquen_ptLargee[nPtBins_2010]={0.002,0.003,0.005};
float Aet_1S_pyquen_rapLarge[nRapBins_2010]={0.252,0.201};
float Aet_1S_pyquen_rapLargee[nRapBins_2010]={0.002,0.003};
//////////////////////////////////////YIELDS//////////////////////////////////////
////yields in the note
/* /\* float N1S_aa_pt3p5[nPtBins_2013] = {863,929,572,346,184}; // ,53 *\///prior to Oct 20! */
/* /\* float N1S_aa_pt3p5e[nPtBins_2013] = {92,75,66,32,21}; //,8.9 *\/ */
/* /\* float N1S_aa_pt3p5[nPtBins_2013] = {691,686,507,343,175}; // ,53 *\/ */
/* /\* float N1S_aa_pt3p5e[nPtBins_2013] = {42,41,66,32,21}; //,8.9 *\/ */
/* float N1S_aa_pt3p5[nPtBins_2013]={725.578,700.694,515.951,349.402,182.037}; */
/* float N1S_aa_pt3p5e[nPtBins_2013]={43.222,41.8636,36.5595,40.0363,16.6537}; */
float N1S_aa_pt3p5Large[nPtBins_2010] = {1842,466,311}; // ,53
float N1S_aa_pt3p5eLarge[nPtBins_2010] = {110,67,24}; //,8.9   // wowowowow 2nd bin was 107, tricked it :) for unimportant reasons.
/* float N1S_aa_pt4[nPtBins_2013] = {440.993,398.654,349.214,290.442,162.54}; */
/* float N1S_aa_pt4e[nPtBins_2013] = {33.4403,29.9976,27.5772,24.5429,15.4982}; */

/* float N1S_aa_rap3p5[nRapBins_2013] = {492,388,403,694,677}; */
/* float N1S_aa_rap3p5e[nRapBins_2013] = {57,43,48,57,79}; */
/* //float N1S_aa_cent3p5[bin1] = {269,241,375,520,620,452,477}; */
/* // new values from july 2014, with 70-100 bin included! */
/* /\* float N1S_aa_cent3p5[nCentBins_2014] = {57,176,228,330,439,636,441,499}; // 70-100 bin, with pol2 *\/ */
/* /\* float N1S_aa_cent3p5e[nCentBins_2014] ={10, 20, 31, 41, 45, 60, 53, 74}; *\/ */
/* float N1S_aa_cent3p5[nCentBins_2014] = {48.2829,173.952,172.083,288.917,438.602,646.191,411.335,412.229}; */
/* float N1S_aa_cent3p5e[nCentBins_2014] = {9.00598,17.2041,18.5096,24.7382,31.9025,40.348,33.3496,36.3436}; */
float N1S_aa_pt3p5U[nPtBins_2013] = {862,945,574,329,180};//,54};
float N1S_aa_pt3p5eU[nPtBins_2013] = {94.4,78.9,69.8,33.6,21.9}; //,8.9 9.3

/* float N2S_aa_pt3p5[nPtBins_2010] = {65,53,9}; //2010 binning */
/* float N2S_aa_pt3p5e[nPtBins_2010] = {59,24,13}; //and their errors. */
/* float N2S_aa_rap3p5[nPtBins_2010] = {112,61}; //2010 binning */
/* float N2S_aa_rap3p5e[nPtBins_2010]= {46,38}; //and their errors. */
/* //float N2S_aa_cent3p5[bin1] = {38,40,55,16,28,28,76}; //2011 binning */
/* //float N2S_aa_cent3p5e[bin1]= {15,17,21,23,30,29,34}; //and their errors. */
/* /\* float N2S_aa_cent3p5[bin1] = {10.8,16,34,37,1.,22,12,74}; //2014 binning ! *\/ */
/* /\* float N2S_aa_cent3p5e[bin1]= {6.9,11,16,20,22,30,26,36}; //and their errors. *\/ */
/* /\* float N2S_aa_cent4[bin1] = {26,30,48,39,43,0.9,47}; //2011 binning ! *\/ */
/* /\* float N2S_aa_cent4e[bin1]= {9,13,15,19,28,23,27}; //and their errors. *\/ */
/* float N2S_aa_cent4[bin1] = {26,21.7397,36.0665,30.8685,24.8739,2.59681,29.2158}; // */
/* float N2S_aa_cent4e[bin1] = {9,9.76781,13.8025,15.7822,20.1582,15.5757,19.4574};// careful first bin crazy */


float N1S_aa_tot4=1784;
float N1S_aa_tot4e=62;
float N1S_aa_tot3p5=2538;
//float N1S_aa_tot3p5=2759;
//float N1S_aa_tot3p5e=135;
float N1S_aa_tot3p5e=80;
float N2S_aa_tot4=142;
float N2S_aa_tot4e=42;
float N2S_aa_tot3p5=162;//227;
float N2S_aa_tot3p5e=55;//66;
float N3S_aa_tot4=0;
float N3S_aa_tot4e=39;
float N3S_aa_tot3p5=37;
float N3S_aa_tot3p5e=59;

//upper limit:
float N3S_aa_UL4=97.8;

///test bench
/* float N1S_aa_tot4=2042; */
/* float N1S_aa_tot4e=105; */
/* float N1S_aa_tot3p5=2762; */
/* float N1S_aa_tot3p5e=143; */
/* float N2S_aa_tot4=233; */
/* float N2S_aa_tot4e=53; */
/* float N2S_aa_tot3p5=225; */
/* float N2S_aa_tot3p5e=72; */
/* float N3S_aa_tot4=58; */
/* float N3S_aa_tot4e=46; */
/* float N3S_aa_tot3p5=39; */
/* float N3S_aa_tot3p5e=63; */

//LEAD LEAD
/* // yields from francois May 5th */
/* /\* float N1S_aa_rap3p5_2014[nRapBins_2014] = {486,520,623,532,464,113};// large bin=540} *\/ */
/* /\* float N1S_aa_rap3p5_2014e[nRapBins_2014]= {40.6,51.7,69.3,44.3,76.2,30.3}; //largebin=78.6 *\/ */

float N1S_aa_rap3p5_2014Large[nRapBins_2010] = {1610,970};
float N1S_aa_rap3p5_2014Largee[nRapBins_2010]= {91.3,64.7};

float N1S_aa_rap4_2014[nRapBins_2014]={312,320,397,388,334,59.6};
float N1S_aa_rap4_2014e[nRapBins_2014]={26.9,26.9,30.9,33.6,53.7,16.3};
/* float N1S_aa_rap4_2014Large[nRapBins_2010]={1080,665}; */
/* float N1S_aa_rap4_2014Largee[nRapBins_2010]={69.7,47.2}; */

/* float N2S_aa_rap3p5_2014Large[nRapBins_2010]={111,61.7}; */
/* float N2S_aa_rap3p5_2014Largee[nRapBins_2010]={45.4,38.2}; */
/* /\* float N2S_aa_rap4_2014Large[nRapBins_2010]={84.3,58.8}; *\/ */
/* /\* float N2S_aa_rap4_2014Largee[nRapBins_2010]={32.6,28.2}; *\/ */
/* float N2S_aa_rap4_2014Large[nRapBins_2010]={83.0694,52.3694}; */
/* float N2S_aa_rap4_2014Largee[nRapBins_2010]={29.9647,27.1147}; */
//from me
/* float N2S_aa_pt4_2013Large[nPtBins_2010]={71.,43.,20}; */
/* float N2S_aa_pt4_2013Largee[nPtBins_2010]={39.,26.,13}; */
/* float N1S_aa_rap3p5_2014[nRapBins_2014] = {490.817,506.78,570.804,512.765,375.383,118.497}; */
/* float N1S_aa_rap3p5_2014e[nRapBins_2014] = {31.3657,35.0903,38.568,37.6318,31.452,18.1268}; */
/* float N2S_aa_rap3p5[nRapBins_2014] = {19.8274,54.0754,31.1618,-8.478,41.2374,5.71804}; */
/* float N2S_aa_rap3p5e[nRapBins_2014] = {20.8224,26.0765,26.9882,24.9951,20.1535,11.255}; */
/* float N2S_aa_rap4_2014Large[nRapBins_2010] = {83.0694,52.3694}; */
/* float N2S_aa_rap4_2014Largee[nRapBins_2010] = {29.9647,27.1147}; */
/* float N1S_aa_rap4_2014Large[nRapBins_2010] = {1054.52,693.517}; */
/* float N1S_aa_rap4_2014Largee[nRapBins_2010] = {45.4284,40.0771}; */
/* float N1S_aa_pt3p5[nPtBins_2013] = {725.578,700.694,515.951,349.402,182.037}; */
/* float N1S_aa_pt3p5e[nPtBins_2013] = {43.222,41.8636,36.5595,40.0363,16.6537}; */
/* float N2S_aa_pt3p5[nPtBins_2013] = {11.3525,56.9485,13.9029,29.1776,22.4181}; */
/* float N2S_aa_pt3p5e[nPtBins_2013] = {27.4325,29.1529,25.457,28.8449,9.47339}; */
/* float N1S_aa_pt4[nPtBins_2013] = {440.993,398.654,349.214,290.442,162.54}; */
/* float N1S_aa_pt4e[nPtBins_2013] = {33.4403,29.9976,27.5772,24.5429,15.4982}; */
/* /\* float N2S_aa_pt4_2013Large[nPtBins_2010] = {62.5574,18.8922,21.8201}; *\/ */
/* /\* float N2S_aa_pt4_2013Largee[nPtBins_2010] = {33.4764,18.9991,12.3811}; *\/ */
/* float N2S_aa_pt4_2013Large[nPtBins_2010] = {47.2699,31.7819,22.5695}; */
/* float N2S_aa_pt4_2013Largee[nPtBins_2010] = {30.785,20.3283,8.14638}; */
/* float N1S_aa_pt4_2013Large[nPtBins_2010] = {1054.77,304.952,293.117}; */
/* float N1S_aa_pt4_2013Largee[nPtBins_2010] = {48.3581,27.4976,21.5473}; */
/* float N1S_aa_cent3p5[nCentBins_2014] = {48.2829,173.952,172.083,288.917,438.602,646.191,411.335,412.229}; */
/* float N1S_aa_cent3p5e[nCentBins_2014] = {9.00598,17.2041,18.5096,24.7382,31.9025,40.348,33.3496,36.3436}; */
/* float N1S_aa_cent3p5Super[nCentBins_2014+1] = {48.2829,173.952,172.083,288.917,438.602,646.191,411.335,188,223}; //for fun, splitting 0-5 into 0-2.5, 2.5-5 */
/* float N1S_aa_cent3p5Supere[nCentBins_2014+1] = {9.00598,17.2041,18.5096,24.7382,31.9025,40.348,33.3496,25,26}; */
/* float N1S_aa_cent4[nCentBins_2014-1] = {160,107,215.137,315.578,440.382,277.322,302.788}; //149.497,89.9569 */
/* float N1S_aa_cent4e[nCentBins_2014-1] = {15.5456,13.1752,20.3204,24.2413,30.1667,24.6636,27.1465}; */
/* float N2S_aa_cent4[bin1] = {12.5547,21.7397,36.0665,30.8685,24.8739,2.59681,29.2158}; */
/* float N2S_aa_cent2bin[2] = {98,50}; */
/* float N2S_aa_cent2bine[2] = {24,32}; */
float N2S_aa_cent4e[bin1] = {9.27443,9.76781,13.8025,15.7822,20.1582,15.5757,19.4574};
float N2S_aa_cent4_4bins[4]={12.2,57,49,29}; //50-100, 30-50, 10-30, 0-10
float N2S_aa_cent4_4binse[4]={9.2,16,25,25};//50-100, 30-50, 10-30, 0-10
float N2S_aa_rap3p5_2014Large[nRapBins_2010] = {98.3172,49.8434};
float N2S_aa_rap3p5_2014Largee[nRapBins_2010] = {41.4689,38.937};
float N2S_aa_pt3p5_2013Large[nPtBins_2010] = {64.3019,44.5793,23.1759};
float N2S_aa_pt3p5_2013Largee[nPtBins_2010] = {41.8096,32.9534,9.47136};



/* float N1S_aa_y120[2] = {628.687,896.043}; */
/* float N1S_aa_y120e[2] = {34.5313,46.832}; */
/* float N1S_aa_y240[2] = {482.051,512.908}; */
/* float N1S_aa_y240e[2] = {32.7068,40.6259}; */
/* float N1S_aa_pt5[2] = {621.513,811.318}; */
/* float N1S_aa_pt5e[2] = {37.7155,48.8599}; */
/* float N1S_aa_pt12[2] = {398.64,496.135}; */
/* float N1S_aa_pt12e[2] = {28.3544,38.1232}; */
/* float N1S_aa_pt20[2] = {64.1709,113.79}; */
/* float N1S_aa_pt20e[2] = {9.6791,13.3602}; */


/* //PROTON PROTON */
/* /\* float N1S_pp_rap3p5_2014[nRapBins_2014] = {1110,1130,1010,988,830,359}; //largebin=1289 *\/ */
/* /\* float N1S_pp_rap3p5_2014e[nRapBins_2014]= {44.7,49.7,47.6,43.6,41.2,23.8}; // largebin=51.7 *\/ */
/* /\* float N1S_pp_rap3p5_2014[nRapBins_2014]={1043.5,1124.69,1007.1,967.16,808.658,372.962}; *\///Open trigger */
/* /\* float N1S_pp_rap3p5_2014e[nRapBins_2014]={36.6026,39.9872,39.123,39.7542,37.6477,23.2556}; *\/ */
/* float N1S_pp_rap3p5_2014[nRapBins_2014] = {1045.8,1114.99,971.794,892.208,655.377,249.099}; //highQ */
/* float N1S_pp_rap3p5_2014e[nRapBins_2014] = {36.732,39.9483,38.4188,37.9055,32.4348,19.3658}; */
/* float N1S_pp_rap4_2014[nRapBins_2014]={785,836,699,660,601,265};  ///largebin 830};// */  // OOOOLD trig!
/* float N1S_pp_rap4_2014e[nRapBins_2014]={35.6,38,41.4,33.9,70.9,23}; //largebin = 36.9 */
float N1S_pp_rap4_2014[nRapBins_2014] = {755.141,797.298,678.897,595.653,434.373,173.238};
float N1S_pp_rap4_2014e[nRapBins_2014] = {30.6288,33.0107,31.3006,30.3759,27.4019,16.486};

/* /\* float N2S_pp_rap3p5_2014[nRapBins_2014]= {360,347,315,341,276,63.9}; //open *\/ */
/* /\* float N2S_pp_rap3p5_2014e[nRapBins_2014]={27.1,27.9,29.3,30,28.6,14.3}; *\/ */
/* float N2S_pp_rap3p5_2014[nRapBins_2014] = {316.234,338.689,308.931,305.157,229.726,50.7125}; //highQ */
/* float N2S_pp_rap3p5_2014e[nRapBins_2014] = {24.0715,25.9207,26.8278,27.3601,23.4638,12.9031}; */
/* /\* float N2S_pp_rap4_2014[nRapBins_2014]={265,277,239,241,254,62.3}; //open *\/ */
/* /\* float N2S_pp_rap4_2014e[nRapBins_2014]={22.9,24.3,24,24.9,47.4,13.9}; *\/ */
/* float N2S_pp_rap4_2014[nRapBins_2014] = {241.004,257.264,229.192,218.071,179.066,45.9916}; //highQ */
/* float N2S_pp_rap4_2014e[nRapBins_2014] = {19.9981,21.644,21.2744,22.3079,20.8062,11.7197}; */
/* /\* float N2S_pp_rap4_2014Large[nRapBins_2010]={2290,1470}; *\/ */
/* /\* float N2S_pp_rap4_2014Largee[nRapBins_2010]={67.9,63.6}; *\/ */
/* /\* float N2S_pp_rap4_2014Large[nRapBins_2010]={714.061,497.992}; *\/ //open */
/* /\* float N2S_pp_rap4_2014Largee[nRapBins_2010]={36,37.8979}; *\/ */
/* float N2S_pp_rap4_2014Large[nRapBins_2010] = {706.144,435.857}; //highQ */
/* float N2S_pp_rap4_2014Largee[nRapBins_2010] = {35.7708,36.5077}; */
/* /\* float N3S_pp_rap3p5_2014[nRapBins_2013]={170,175,179,121,189};//,111,74.9}; //open *\/ */
/* /\* float N3S_pp_rap3p5_2014e[nRapBins_2013]={21.2,23.3,25.7,24.9,28.2};//;,24.1,14.3}; *\/ */
/* float N3S_pp_rap3p5_2014[nRapBins_2014] = {140.577,167.214,165.89,113.125,87.8148,56.0211}; //highQ */
/* float N3S_pp_rap3p5_2014e[nRapBins_2014] = {19.0652,21.8788,23.189,22.6344,19.3827,12.5086}; */
/* /\* float N3S_pp_rap4_2014[nRapBins_2014]={134,138,138,96,108,67.3}; //175} *\/ */
/* /\* float N3S_pp_rap4_2014e[nRapBins_2014]={18.1,20.7,20.5,20.7,37,14.5}; // 23.4 *\/ */
/* /\* float N3S_pp_rap4_2014[nRapBins_2014]={117.8,126.87,131.51,95.9781,92.4825,67.7779}; //open *\/ */
/* /\* float N3S_pp_rap4_2014e[nRapBins_2014]={15.9977,17.7523,18.5524,19.0335,31.3553,13.4012}; *\/ */
/* float N3S_pp_rap4_2014[nRapBins_2014] = {115.373,128.482,135.999,85.7138,71.7167,46.4221}; //highQ */
/* float N3S_pp_rap4_2014e[nRapBins_2014] = {16.0236,17.9384,18.4957,18.3729,17.3947,11.4625}; */
/* float N3S_pp_rap4_2014Large[nRapBins_2010] = {360.713,196.843}; */
/* float N3S_pp_rap4_2014Largee[nRapBins_2010] = {29.9762,31.3335}; */
/* float N2S_pp_pt3p5_2013[nPtBins_2013] = {433,529,378,266,144};//31.2 */
/* float N2S_pp_pt3p5_2013e[nPtBins_2013] = {45,41,28,23,15};//7.6 */
/* /\* float N2S_pp_pt4_2013[nPtBins_2013]={372.739,250.364,251.718,200.114,124.341}; *\/ //open */
/* /\* float N2S_pp_pt4_2013e[nPtBins_2013]={28.082,23.514,21.9586,17.523,13.319}; *\/ */
/* float N2S_pp_pt4_2013[nPtBins_2013] = {301.791,257.089,243.196,188.89,113.466};//highQ */
/* float N2S_pp_pt4_2013e[nPtBins_2013] = {28.9903,23.9729,20.3855,17.0605,12.7171}; */
/* /\* float N2S_pp_pt4_2013[nPtBins_2013] = {318,302,274,230,131};//31.7 *\/ */
/* /\* float N2S_pp_pt4_2013e[nPtBins_2013] = {34,30,22,21,15};//8.0 *\/ */
/* /\* float N2S_pp_pt4_2013Large[nPtBins_2010]={827,287,200}; *\/ */
/* /\* float N2S_pp_pt4_2013Largee[nPtBins_2010]={168,23,31}; *\/ */
/* /\* float N2S_pp_pt4_2013Large[nPtBins_2010]={725.214,248.916,189.512};//open *\/ */
/* /\* float N2S_pp_pt4_2013Largee[nPtBins_2010]={40.9265,20.2315,16.7928}; *\/ */
/* float N2S_pp_pt4_2013Large[nPtBins_2010] = {695.703,234.325,173.997};//highQ */
/* float N2S_pp_pt4_2013Largee[nPtBins_2010] = {39.8716,19.732,16.0895}; */
/* /\* float N3S_pp_pt4_2013[nPtBins_2013] = {141,199,134,108,75};//23.4 *\/ */
/* /\* float N3S_pp_pt4_2013e[nPtBins_2013] = {27,28,18,16,12};//7.2 *\/ */
/* /\* float N3S_pp_pt4_2013[nPtBins_2013]={186.882,165.105,118.457,89.0954,71.8379}; //open *\/ */
/* /\* float N3S_pp_pt4_2013e[nPtBins_2013]={23.4312,21.1747,17.7216,13.491,10.8839}; *\/ */
/* float N3S_pp_pt4_2013[nPtBins_2013] = {128.482,168.485,112.074,84.2136,69.3291}; //highQ */
/* float N3S_pp_pt4_2013e[nPtBins_2013] = {24.0888,21.6864,16.513,13.1443,10.6023}; */
float N3S_pp_pt3p5_2013[nPtBins_2013] = {203,282,184,130,83};//21
float N3S_pp_pt3p5_2013e[nPtBins_2013] = {36,34,23,17,13};//6.5
/* float N3S_pp_pt4_2013Large[nPtBins_2010] = {358.951,91.1538,99.0478}; */
/* float N3S_pp_pt4_2013Largee[nPtBins_2010] = {34.5618,15.0331,13.0713}; */


/* ////yields in the note */
/* //trying now with yields from plots, waiting for the Arleo ones. 25th apr. 2014 */
/* /\* float N1S_pp_pt3p5[nPtBins_2013] = {1717,1550,1107,691,352}; // ,62.5 *\/ */
/* /\* float N1S_pp_pt3p5e[nPtBins_2013] = {80,64,43,43,23}; // ,9.9 *\/ */
/* /\* float N1S_pp_pt3p5[nPtBins_2013]={1623.31,1520.25,1023.34,633.098,344.566}; *\/ //open */
/* /\* float N1S_pp_pt3p5e[nPtBins_2013]={50.737,47.6386,36.7225,28.3172,20.396}; *\/ */
/* float N1S_pp_pt3p5[nPtBins_2013] = {1499.27,1418.6,972.688,602.121,337.012}; //highQ */
/* float N1S_pp_pt3p5e[nPtBins_2013] = {49.2967,45.7898,28.4194,27.578,20.1226}; */
/* float N1S_pp_pt4[nPtBins_2013] = {954.099,806.429,719.354,515.821,304.747}; */
/* float N1S_pp_pt4e[nPtBins_2013] = {39.8429,34.6068,30.325,25.261,19.0581}; */

float N1S_pp_pt3p5U[nPtBins_2013] = {1718,1546.18,1109.26,692.5,350}; // ,62.8
float N1S_pp_pt3p5eU[nPtBins_2013]= {81,65,44,44,23}; // ,9.9,10
/* /\* float N1S_pp_pt3p5Large[nPtBins_2010]={3856,910,586}; *\/ // 0-6p5-10-20 */
/* /\* float N1S_pp_pt3p5eLarge[nPtBins_2010]={97,37,29}; *\/ */
/* float N1S_pp_pt3p5Large[nPtBins_2010] = {3440.53,798.368,558.817}; */
/* float N1S_pp_pt3p5Largee[nPtBins_2010] = {72.8418,32.1636,26.1766}; */
/* float N1S_pp_rap3p5[nRapBins_2013] = {1102,844,795,1198,1427};  */
/* float N1S_pp_rap3p5e[nRapBins_2013] = {47,42,37,47,49}; */

/* float N2S_pp_pt3p5Large[nPtBins_2010] = {1166,335,227}; // for CS2S_pp_ptLarge */
/* float N2S_pp_pt3p5Largee[nPtBins_2010]= {64,26,35}; */
/* float N2S_pp_pt3p5[nPtBins_2013] = {372.615,491.722,318.957,218.694,123.526}; */
/* float N2S_pp_pt3p5e[nPtBins_2013] = {32.2694,32.2999,19.49,18.7975,13.4272}; */
/* float N2S_pp_rap3p5[nRapBins_2010] = {1033,697}; // for CS2S_pp_rapLarge */
/* float N2S_pp_rap3p5e[nRapBins_2010]= {51,41}; */


/* float N1S_pp_pt3p5[nPtBins_2013+1] = {1499.27,1418.6,972.688,602.121,337.012,56.5}; */
/* float N1S_pp_pt3p5e[nPtBins_2013+1] = {49.2967,45.7898,28.4194,27.578,20.1226.8.6}; */
/* float N1S_pp_pt3p5Large[nPtBins_2010] = {2970.5,1600.85,337.012}; */
/* float N1S_pp_pt3p5Largee[nPtBins_2010] = {69.3649,46.0042,20.1226}; */
/* float N1S_pp_pt4[nPtBins_2013] = {954.099,806.429,719.354,515.821,304.747}; */
/* float N1S_pp_pt4e[nPtBins_2013] = {39.8429,34.6068,30.325,25.261,19.0581}; */
/* float N2S_pp_pt3p5_2013[nPtBins_2013] = {372.615,491.722,318.957,218.694,123.526}; */
/* float N2S_pp_pt3p5_2013e[nPtBins_2013] = {32.2694,32.2999,19.49,18.7975,13.4272}; */
/* float N1S_pp_rap3p5_2014[nRapBins_2014] = {1045.8,1114.99,971.794,892.208,655.377,249.099}; */
/* float N1S_pp_rap3p5_2014e[nRapBins_2014] = {36.732,39.9483,38.4188,37.9055,32.4348,19.3658}; */
/* float N2S_pp_rap3p5_2014[nRapBins_2014] = {316.234,338.689,308.931,305.157,229.726,50.7125}; */
/* float N2S_pp_rap3p5_2014e[nRapBins_2014] = {24.0715,25.9207,26.8278,27.3601,23.4638,12.9031}; */
/* float N3S_pp_rap3p5_2014[nRapBins_2014] = {140.577,167.214,165.89,113.125,87.8148,56.0211}; */
/* float N3S_pp_rap3p5_2014e[nRapBins_2014] = {19.0652,21.8788,23.189,22.6344,19.3827,12.5086}; */
/* float N2S_pp_pt4_2013Large[nPtBins_2010] = {554.655,424.227,114.736}; */
/* float N2S_pp_pt4_2013Largee[nPtBins_2010] = {36.8627,27.0866,12.6896}; */
/* float N3S_pp_pt4_2013Large[nPtBins_2010] = {358.951,91.1538,99.0478}; */
/* float N3S_pp_pt4_2013Largee[nPtBins_2010] = {34.5618,15.0331,13.0713}; */
/* float N1S_pp_pt4_2013Large[nPtBins_2010] = {2193.61,630.642,503.002}; */
/* float N1S_pp_pt4_2013Largee[nPtBins_2010] = {57.4966,28.895,24.7048}; */
/* float N2S_pp_rap4_2014Large[nRapBins_2010] = {706.144,435.857}; */
/* float N2S_pp_rap4_2014Largee[nRapBins_2010] = {35.7708,36.5077}; */
/* float N3S_pp_rap4_2014Large[nRapBins_2010] = {360.713,196.843}; */
/* float N3S_pp_rap4_2014Largee[nRapBins_2010] = {29.9762,31.3335}; */
/* float N2S_pp_pt4_2013[nPtBins_2013] = {301.791,257.089,243.196,188.89,113.466}; */
/* float N2S_pp_pt4_2013e[nPtBins_2013] = {28.9903,23.9729,20.3855,17.0605,12.7171}; */
/* float N2S_pp_rap4_2014[nRapBins_2014] = {241.004,257.264,229.192,218.071,179.066,45.9916}; */
/* float N2S_pp_rap4_2014e[nRapBins_2014] = {19.9981,21.644,21.2744,22.3079,20.8062,11.7197}; */
/* float N3S_pp_pt4_2013[nPtBins_2013] = {128.482,168.485,112.074,84.2136,69.3291}; */
/* float N3S_pp_pt4_2013e[nPtBins_2013] = {24.0888,21.6864,16.513,13.1443,10.6023}; */
/* float N3S_pp_rap4_2014[nRapBins_2014] = {115.373,128.482,135.999,85.7138,71.7167,46.4221}; */
/* float N3S_pp_rap4_2014e[nRapBins_2014] = {16.0236,17.9384,18.4957,18.3729,17.3947,11.4625}; */
/* float N2S_pp_pt3p5_2013Large[nPtBins_2010] = {841.174,542.792,124.24}; */
/* float N2S_pp_pt3p5_2013Largee[nPtBins_2010] = {46.9503,31.5481,13.3937}; */
/* float N2S_pp_rap3p5_2014Large[nRapBins_2010] = {939.403,596.22}; */
/* float N2S_pp_rap3p5_2014Largee[nRapBins_2010] = {43.4312,40.3201}; */



////// TO REARRANGE LATER !
/////// MARCH 3rd, 2015
float N1S_aa_rap3p5_2014[nRapBins_2014] = {487.985,481.623,552.197,506.573,370.098,113.521};
float N1S_aa_rap3p5_2014e[nRapBins_2014] = {31.7992,33.6653,37.786,38.1144,31.1878,17.9019};
float N2S_aa_rap3p5_2014[nRapBins_2014] = {18.1589,49.5771,26.9589,-6.69349,42.3796,5.01174};
float N2S_aa_rap3p5_2014e[nRapBins_2014] = {21.4446,24.5011,26.3246,25.2182,20.0286,11.1522};
float N2S_aa_rap3p5_2014Large[nRapBins_2010] = {98.3172,49.8434};
float N2S_aa_rap3p5_2014Largee[nRapBins_2010] = {41.4689,38.937};
float N1S_aa_pt3p5[nPtBins_2013+1] = {726.745,703.115,513.002,352.598,184.801,50.1};
float N1S_aa_pt3p5e[nPtBins_2013+1] = {43.2643,41.9908,35.285,25.1122,16.6317,8.0};
float N2S_aa_pt3p5[nPtBins_2013] = {11.6496,57.2783,12.2122,28.8976,23.1759};
float N2S_aa_pt3p5e[nPtBins_2013] = {27.4737,29.247,24.7455,14.2242,9.47136};
float N2S_aa_pt3p5_2013Large[nPtBins_2010] = {64.3019,44.5793,23.1759};
float N2S_aa_pt3p5_2013Largee[nPtBins_2010] = {41.8096,32.9534,9.47136};
float N1S_aa_cent3p5[nCentBins_2014] = {47.244,171.376,170.003,284.299,429.589,631.211,406.453,399.242};
float N1S_aa_cent3p5e[nCentBins_2014] = {8.9428,17.1378,18.4118,24.5916,31.6842,40.0692,33.2336,36.1182};
float N2S_aa_cent3p5[nCentBins_2014-1] = {14.3905,23.9882,32.4851,-7.2273,15.7701,2.37886,54.2902};
float N2S_aa_cent3p5e[nCentBins_2014-1] = {11.4856,12.2367,16.3199,20.7843,27.8194,22.6046,27.5036};


float N1S_pp_pt3p5[nPtBins_2013+1] = {1485.18,1419.09,971.544,610.443,336.5,56.5};
float N1S_pp_pt3p5e[nPtBins_2013+1] = {50.7757,45.8785,34.6759,29.4951,20.1515,8.0};
float N1S_pp_pt3p5Large[nPtBins_2010] = {2910.91,1587.86,336.5};
float N1S_pp_pt3p5Largee[nPtBins_2010] = {68.0454,46.7507,20.1515};
float N2S_pp_pt3p5[nPtBins_2013] = {364.578,492.106,317.137,221.604,124.24};
float N2S_pp_pt3p5e[nPtBins_2013] = {33.8442,32.357,23.4275,20.3839,13.3937};
float N1S_pp_rap3p5_2014[nRapBins_2014] = {1056.22,1059.2,950.541,898.831,647.123,242.356};
float N1S_pp_rap3p5_2014e[nRapBins_2014] = {37.2745,38.0325,36.7018,38.381,34.3541,19.0884};
float N2S_pp_rap3p5_2014[nRapBins_2014] = {321.749,312.107,304.862,305.043,231.578,48.0034};
float N2S_pp_rap3p5_2014e[nRapBins_2014] = {24.5519,24.5002,25.1158,27.6449,25.1545,12.5694};
float N3S_pp_rap3p5_2014[nRapBins_2014] = {149.423,150.038,160.414,113.702,85.6271,53.2686};
float N3S_pp_rap3p5_2014e[nRapBins_2014] = {19.687,20.5616,21.5392,22.7516,20.3233,12.2139};
float N2S_pp_pt3p5_2013Large[nPtBins_2010] = {841.174,542.792,124.24};
float N2S_pp_pt3p5_2013Largee[nPtBins_2010] = {46.9503,31.5481,13.3937};
float N2S_pp_rap3p5_2014Large[nRapBins_2010] = {939.403,596.22};
float N2S_pp_rap3p5_2014Largee[nRapBins_2010] = {43.4312,40.3201};

// DOUBLE DIFFERENTIAL STUFF
// arrays for nPart dep pt/y-binned data
float N1S_pp_pt3p5_2010[nPtBins_2010] = {2971,1601,337};
float N1S_pp_pt3p5_2010e[nPtBins_2010] = {69,46,20};
float N1S_pp_rap3p5_2010[nRapBins_2010] = {3068,1772};
float N1S_pp_rap3p5_2010e[nRapBins_2010] = {65,54};
float N1S_aa_y120[2] = {628.687,896.043};
float N1S_aa_y120e[2] = {34.5313,46.832};
float N1S_aa_y240[2] = {482.051,512.908};
float N1S_aa_y240e[2] = {32.7068,40.6259};
float N1S_aa_pt5[2] = {621.513,811.318};
float N1S_aa_pt5e[2] = {37.7155,48.8599};
float N1S_aa_pt12[2] = {398.64,496.135};
float N1S_aa_pt12e[2] = {28.3544,38.1232};
float N1S_aa_pt20[2] = {64.1709,113.79};
float N1S_aa_pt20e[2] = {9.6791,13.3602};
//other way to bin: pt/y-dependent nPart-binned
//20-100,then 0-20 
//commented ones - for ptMu>4 GeV, should be updated.
/* float Aet_1S_pyquen_y120[nRapBins_2010]= {0.181,0.174}; */
/* float Aet_1S_pyquen_y120e[nRapBins_2010]={0.002,0.003}; */
/* float Aet_1S_pyquen_y240[nRapBins_2010] ={0.132,0.142}; */
/* float Aet_1S_pyquen_y240e[nRapBins_2010]={0.003,0.003}; */
/* float Aet_1S_pyquen_pt5[nRapBins_2010]=   {0.227,0.215}; */
/* float Aet_1S_pyquen_pt5e[nRapBins_2010]=  {0.002,0.003}; */
/* float Aet_1S_pyquen_pt12[nRapBins_2010]=  {0.228,0.218}; */
/* float Aet_1S_pyquen_pt12e[nRapBins_2010]= {0.004,0.004}; */
/* float Aet_1S_pyquen_pt20[nRapBins_2010]=  {0.356,0.341}; */
/* float Aet_1S_pyquen_pt20e[nRapBins_2010]= {0.004,0.005}; */
//20-100,then 0-20 
float Aet_1S_pyquen_y120[nRapBins_2010]= {0.259,0.249}; 
float Aet_1S_pyquen_y120e[nRapBins_2010]={0.002,0.003};
float Aet_1S_pyquen_y240[nRapBins_2010] ={0.211,0.196};
float Aet_1S_pyquen_y240e[nRapBins_2010]={0.003,0.003};
float Aet_1S_pyquen_pt5[nRapBins_2010]=   {0.236,0.224};
float Aet_1S_pyquen_pt5e[nRapBins_2010]=  {0.002,0.003};
float Aet_1S_pyquen_pt12[nRapBins_2010]=  {0.217,0.207};
float Aet_1S_pyquen_pt12e[nRapBins_2010]= {0.004,0.004};
float Aet_1S_pyquen_pt20[nRapBins_2010]=  {0.395,0.379};
float Aet_1S_pyquen_pt20e[nRapBins_2010]= {0.004,0.005};
///BELOW: NOT THE SAME PT BINS....can't be used.
float Ae_1S_pyquen_DD020[nRapBins_2010]={0.266,0.305};
float Ae_1S_pyquen_DD20100[nRapBins_2010]={0.278,0.328};
float Ae_1S_pyquen_DD020e[nRapBins_2010]={0.002,0.0032};
float Ae_1S_pyquen_DD20100e[nRapBins_2010]={0.0017,0.0027};
float Aet_1S_pyquen_DDR020[nRapBins_2010]={0.249,0.196};
float Aet_1S_pyquen_DDR020e[nRapBins_2010]={0.003,0.003};
float Aet_1S_pyquen_DDR20100[nRapBins_2010]={0.259,0.211};
float Aet_1S_pyquen_DDR20100e[nRapBins_2010]={0.003,0.003};
float Aet_1S_pyquen_DDP020[nPtBins_2010]={0.215,0.218,0.341};
float Aet_1S_pyquen_DDP020e[nPtBins_2010]={0.003,0.004,0.005};
float Aet_1S_pyquen_DDP20100[nPtBins_2010]={0.227,0.228,0.356};
float Aet_1S_pyquen_DDP20100e[nPtBins_2010]={0.002,0.004,0.004};
float e_1S_pyquen_DD020[nRapBins_2010]={0.596,0.577};
float e_1S_pyquen_DD20100[nRapBins_2010]={0.621,0.622};
float e_1S_pyquen_DD020e[nRapBins_2010]={0.0051,0.0066};
float e_1S_pyquen_DD20100e[nRapBins_2010]={0.0043,0.0057};
float A_1S_pyquen_DD020[nRapBins_2010]={0.447,0.530};
float A_1S_pyquen_DD20100[nRapBins_2010]={0.449,0.528};
float A_1S_pyquen_DD020e[nRapBins_2010]={0.0024,0.0039};
float A_1S_pyquen_DD20100e[nRapBins_2010]={0.0020,0.0032};
float t_1S_pyquen_DDR020[nRapBins_2010]= {1.067,1.122};
float t_1S_pyquen_DDR20100[nRapBins_2010]= {1.067,1.122};
float t_1S_pyquen_DDP020[nPtBins_2010]=   {1.099,1.066,1.043};
float t_1S_pyquen_DDP20100[nPtBins_2010]=   {1.1,1.066,1.043};

/// INTEGRATED STUFF
/* float N1S_pp_tot3p5=5512; */
/* float N1S_pp_tot3p5e=116; */

/* float N2S_pp_tot3p5=1770; */
/* float N2S_pp_tot3p5e=72; */
/* float N2S_pp_tot4=1404; */
/* float N2S_pp_tot4e=65; */

/* float N3S_pp_tot3p5=906; */
/* float N3S_pp_tot3p5e=60; */
/* float N3S_pp_tot4= 755; */
/* float N3S_pp_tot4e=53; */


// test bench
float N1S_pp_tot3p5=4919;
float N1S_pp_tot3p5e=86;
float N1S_pp_tot4=3485;
float N1S_pp_tot4e=72;
float N2S_pp_tot3p5=1541;
float N2S_pp_tot3p5e=59;
float N2S_pp_tot4=1183;
float N2S_pp_tot4e=49;
float N3S_pp_tot3p5=737;
float N3S_pp_tot3p5e=50;
float N3S_pp_tot4= 601;
float N3S_pp_tot4e=41;


///p-Pb (1st part of the run)
float N1S_pa_pt3p5[nPtBins_2014]={1182,1010,940,659,381,77};
float N1S_pa_pt3p5e[nPtBins_2014]={136,37,49,40,23,10};
float N2S_pa_pt3p5[nPtBins_2014]={181,218,220,191,77,37.1};
float N2S_pa_pt3p5e[nPtBins_2014]={62,30,29,26,13,7.9};
float N3S_pa_pt3p5[nPtBins_2014]={37,71,48,46,74,27.2};
float N3S_pa_pt3p5e[nPtBins_2014]={40,27,23,19,12,7.2};

float N1S_pp_m146p239pt3p5[nPtBins_2014]={1766,1518,1091,664,347,62.2};
float N1S_pp_m146p239pt3p5e[nPtBins_2014]={57,48,42,26,23,9.6};
float N2S_pp_m146p239pt3p5[nPtBins_2014]={432,512,370,251,139,31.4};
float N2S_pp_m146p239pt3p5e[nPtBins_2014]={35,37,27,16,15,7.6};
float N3S_pp_m146p239pt3p5[nPtBins_2014]={192,266,176,118,79,21.4};
float N3S_pp_m146p239pt3p5e[nPtBins_2014]={28,37,22,13,13,6.4};


/* float N1S_pa_pt4[nPtBins_2014]={647,}; */
/* float N1S_pa_pt4e[nPtBins_2014]={50}; */
/* float N2S_pa_pt4[nPtBins_2014]={647,}; */
/* float N2S_pa_pt4e[nPtBins_2014]={50}; */
/* float N3S_pa_pt4[nPtBins_2014]={647,}; */
/* float N3S_pa_pt4e[nPtBins_2014]={50}; */

/* float N1S_pa_rap3p5[nRapBins_pPb]={647,}; */
/* float N1S_pa_rap3p5e[nRapBins_pPb]={50}; */
/* float N2S_pa_rap3p5[nRapBins_pPb]={647,}; */
/* float N2S_pa_rap3p5e[nRapBins_pPb]={50}; */
/* float N3S_pa_rap3p5[nRapBins_pPb]={647,}; */
/* float N3S_pa_rap3p5e[nRapBins_pPb]={50}; */

/* float N1S_pa_rap4[nRapBins_pPb]={647,}; */
/* float N1S_pa_rap4e[nRapBins_pPb]={50}; */
/* float N2S_pa_rap4[nRapBins_pPb]={647,}; */
/* float N2S_pa_rap4e[nRapBins_pPb]={50}; */
/* float N3S_pa_rap4[nRapBins_pPb]={647,}; */
/* float N3S_pa_rap4e[nRapBins_pPb]={50}; */



//// systematics

float N1S_pp_pt3p5s[nPtBins_2013]={0.134,0.0827,0.1236,0.0811,0.0345};
float N1S_aa_pt3p5s[nPtBins_2013]={0.316,0.1742,0.3831,0.0555,0.0410};

float N1S_pp_rap3p5s[nRapBins_2014]={0.0873,0.0630,0.0522,0.0962,0.0629,0.0436};
float N1S_aa_rap3p5s[nRapBins_2014]={0.1122,0.0746,0.1883,0.2029,0.4291,0.3936};

// from fitting.
float N1S_pp_tot3p5s=0.0135;
float N1S_aa_tot3p5s=0.0291;
 // from fitting.
float N1S_pp_tot4s=0.0160;
float N1S_aa_tot4s=0.0281;

float N2S_pp_tot4s=0.0209;
float N2S_aa_tot4s=0.0712;

//fit+bkg vars
float N1S_pp_pt3p5s_2p5[nfitvars] = {1551.36,1503.74,1591.1,1612.99,1575.85};
float N1S_pp_pt3p5s_5[nfitvars] = {1412.04,1416.2,1455.97,1460.41,1455.03};
float N1S_pp_pt3p5s_8[nfitvars] = {977.022,987.61,988.759,990.138,989.837};
float N1S_pp_pt3p5s_12[nfitvars] = {627.401,624.418,626.702,629.589,623.676};
float N1S_pp_pt3p5s_20[nfitvars] = {339.209,340.552,344.76,340.984,344.943};
float N2S_pp_pt4s_2p5[nfitvars] = {288.91,296.194,306.122,302.192,306.058};
float N2S_pp_pt4s_5[nfitvars] = {244.648,253.123,260.315,258.962,262.363};
float N2S_pp_pt4s_8[nfitvars] = {248.689,242.467,252.112,250.518,251.855};
float N2S_pp_pt4s_12[nfitvars] = {200.189,199.4,201.114,198.357,200.519};
float N2S_pp_pt4s_20[nfitvars] = {114.985,114.688,115.522,115.277,115.705};
float N3S_pp_pt4s_2p5[nfitvars] = {119.497,124.473,130.36,127.857,130.264};
float N3S_pp_pt4s_5[nfitvars] = {158.476,165.395,170.991,169.847,172.143};
float N3S_pp_pt4s_8[nfitvars] = {116.39,112.12,116.914,114.537,116.036};
float N3S_pp_pt4s_12[nfitvars] = {94.5617,92.0486,91.3734,88.1354,91.048};
float N3S_pp_pt4s_20[nfitvars] = {69.8923,69.6733,70.4469,70.2467,70.6038};
float N1S_pp_rap3p5s_0p4[nfitvars] = {1094.01,1070.82,1094.08,1114.94,1090.31};
float N1S_pp_rap3p5s_0p8[nfitvars] = {1075.09,1072.27,1094.71,1109.02,1088.28};
float N1S_pp_rap3p5s_1p2[nfitvars] = {923.127,946.509,960.264,949.721,960.566};
float N1S_pp_rap3p5s_1p6[nfitvars] = {910.987,898.813,935.788,947.661,928.601};
float N1S_pp_rap3p5s_2p0[nfitvars] = {630.664,644.029,705.655,647.458,647.212};
float N1S_pp_rap3p5s_2p4[nfitvars] = {236.822,258.277,237.745,264.77,239.334};
float N2S_pp_rap4s_0p4[nfitvars] = {244.696,236.591,256.466,248.127,255.583};
float N2S_pp_rap4s_0p8[nfitvars] = {255.035,240.272,263.379,267.218,262.022};
float N2S_pp_rap4s_1p2[nfitvars] = {216.76,220.338,228.537,223.939,228.701};
float N2S_pp_rap4s_1p6[nfitvars] = {224.748,210.839,230.596,234.257,226.498};
float N2S_pp_rap4s_2p0[nfitvars] = {167.509,169.966,190.421,190.231,176.025};
float N2S_pp_rap4s_2p4[nfitvars] = {42.7718,45.0044,43.45,39.4499,43.4222};
float N3S_pp_rap4s_0p4[nfitvars] = {122.665,116.789,129.98,123.985,128.838};
float N3S_pp_rap4s_0p8[nfitvars] = {125.799,115.323,132.831,131.94,131.162};
float N3S_pp_rap4s_1p2[nfitvars] = {124.273,127.287,132.772,129.462,131.916};
float N3S_pp_rap4s_1p6[nfitvars] = {91.2884,82.4691,92.5832,93.7583,90.8004};
float N3S_pp_rap4s_2p0[nfitvars] = {64.358,65.7561,68.9296,68.8838,68.8031};
float N3S_pp_rap4s_2p4[nfitvars] = {43.8436,46.7949,44.7065,52.6079,44.8781};
float N1S_aa_pt3p5s_2p5[nfitvars] = {865.4,920.556,755.096,752.253,751.415};
float N1S_aa_pt3p5s_5[nfitvars] = {776.272,741.245,769.536,755.469,766.697};
float N1S_aa_pt3p5s_8[nfitvars] = {541.646,554.063,472.835,561.686,485.975};
float N1S_aa_pt3p5s_12[nfitvars] = {343.795,352.41,376.698,361.884,369.617};
float N1S_aa_pt3p5s_20[nfitvars] = {186.607,182.43,185.841,187.157,187.692};
float N2S_ppLarge_pt4s_6p5[nfitvars] = {530.876,548.597,576.439,574.572,578.215};
float N2S_ppLarge_pt4s_10[nfitvars] = {458.448,455.72,459.89,452.989,457.641};
float N2S_ppLarge_pt4s_20[nfitvars] = {114.985,114.688,115.522,115.277,115.705};
float N2S_aa_pt4s_6p5[nfitvars] = {48.1304,79.3716,50.0611,46.173,49.7512};
float N2S_aa_pt4s_10[nfitvars] = {39.5245,33.7405,33.6895,36.3003,34.9376};
float N2S_aa_pt4s_20[nfitvars] = {22.7953,23.1498,22.3989,22.5072,22.4754};
float N2S_aa_pt3p5s_6p5[nfitvars] = {95.1672,85.0276,80.7046,73.2944,81.1674};
float N2S_aa_pt3p5s_10[nfitvars] = {46.3699,46.4382,46.161,52.2496,44.0908};
float N2S_aa_pt3p5s_20[nfitvars] = {23.1528,22.5957,22.9837,23.1469,23.1199};
float N2S_ppLarge_rap4s_1p2[nfitvars] = {719.068,705.292,738.948,736.799,733.355};
float N2S_ppLarge_rap4s_2p4[nfitvars] = {446.498,424.807,456.757,451.73,454.113};
float N1S_aa_rap3p5s_0p4[nfitvars] = {480.944,526.746,494.066,486.577,492.865};
float N1S_aa_rap3p5s_0p8[nfitvars] = {486.08,521.988,479.078,474.525,479.831};
float N1S_aa_rap3p5s_1p2[nfitvars] = {568.145,588.133,570.918,616.665,566.662};
float N1S_aa_rap3p5s_1p6[nfitvars] = {584.312,506.526,566.485,530.188,566.889};
float N1S_aa_rap3p5s_2p0[nfitvars] = {440.689,432.897,372.857,370.168,370.377};
float N1S_aa_rap3p5s_2p4[nfitvars] = {134.967,130.051,126.072,127.257,122.025};
float N2S_aa_rap4s_1p2[nfitvars] = {77.8093,80.3815,77.799,77.3153,77.279};
float N2S_aa_rap4s_2p4[nfitvars] = {85.0798,57.5761,61.9214,56.7595,61.8921};
float N1S_aa_cents_5[nfitvars] = {527.304,458.996,405.846,411.635,411.202};
float N1S_aa_cents_10[nfitvars] = {483.06,464.257,425.934,415.773,426.373};
float N1S_aa_cents_20[nfitvars] = {650.328,719.946,629.763,680.176,633.984};
float N1S_aa_cents_30[nfitvars] = {432.813,428.049,432.383,428.356,433.643};
float N1S_aa_cents_40[nfitvars] = {324.049,323.075,312.315,300.72,313.053};
float N1S_aa_cents_50[nfitvars] = {211.899,194.82,183.42,178.791,182.47};
float N1S_aa_cents_70[nfitvars] = {167.479,165.024,181.598,172.38,181.077};
float N1S_aa_cents_100[nfitvars] = {62.6612,54.6863,42.2366,50.5082,42.6462};
float N1S_aa_cent4s_5[nfitvars] = {377.189,357.846,301.991,317.525,301.862};
float N1S_aa_cent4s_10[nfitvars] = {300.966,276.627,290.614,281.101,290.808};
float N1S_aa_cent4s_20[nfitvars] = {469.922,507.147,439.833,465.253,435.299};
float N1S_aa_cent4s_30[nfitvars] = {317.146,317.622,327.676,317.721,324.273};
float N1S_aa_cent4s_40[nfitvars] = {229.149,222.712,232.974,227.307,229.832};
float N1S_aa_cent4s_50[nfitvars] = {103.047,106.075,96.6576,95.9218,93.4448};
float N1S_aa_cent4s_100[nfitvars] = {170.936,176.605,152.93,151.306,152.246};
float N2S_aa_cents_5[nfitvars] = {46.9266,39.568,27.7429,29.9068,27.7613};
float N2S_aa_cents_10[nfitvars] = {6.62404,4.0587,2.76191,3.99787,3.01325};
float N2S_aa_cents_20[nfitvars] = {35.3114,37.1553,25.3579,28.4838,23.7721};
float N2S_aa_cents_30[nfitvars] = {30.7702,30.3883,35.1904,30.7266,34.2485};
float N2S_aa_cents_40[nfitvars] = {43.2605,40.4087,44.8406,41.1941,43.7008};
float N2S_aa_cents_50[nfitvars] = {22.9744,26.4398,23.7966,22.4121,23.0766};
float N2S_aa_cents_100[nfitvars] = {19.6807,17.901,14.8746,13.3663,14.8582};
float N1B_pp_pt3p5s_2p5[nbkgdvars] = {1526.43,1488.72};
float N1B_pp_pt3p5s_5[nbkgdvars] = {1415.74,1419};
float N1B_pp_pt3p5s_8[nbkgdvars] = {963.603,962.357};
float N1B_pp_pt3p5s_12[nbkgdvars] = {606.6,606.449};
float N1B_pp_pt3p5s_20[nbkgdvars] = {339.866,340.617};
float N2B_pp_pt4s_2p5[nbkgdvars] = {280.102,289.126};
float N2B_pp_pt4s_5[nbkgdvars] = {262.007,257.338};
float N2B_pp_pt4s_8[nbkgdvars] = {237.535,239.8};
float N2B_pp_pt4s_12[nbkgdvars] = {191.502,191.389};
float N2B_pp_pt4s_20[nbkgdvars] = {113.999,114.572};
float N3B_pp_pt4s_2p5[nbkgdvars] = {115.893,120.403};
float N3B_pp_pt4s_5[nbkgdvars] = {172.566,168.988};
float N3B_pp_pt4s_8[nbkgdvars] = {108.971,110.285};
float N3B_pp_pt4s_12[nbkgdvars] = {86.2309,86.1362};
float N3B_pp_pt4s_20[nbkgdvars] = {68.8344,69.5204};
float N1B_pp_rap3p5s_0p4[nbkgdvars] = {1042.88,1048.55};
float N1B_pp_rap3p5s_0p8[nbkgdvars] = {1060.11,1056.56};
float N1B_pp_rap3p5s_1p2[nbkgdvars] = {925.617,929.916};
float N1B_pp_rap3p5s_1p6[nbkgdvars] = {894.436,893.83};
float N1B_pp_rap3p5s_2p0[nbkgdvars] = {656.061,641.497};
float N1B_pp_rap3p5s_2p4[nbkgdvars] = {240.706,233.369};
float N2B_pp_rap4s_0p4[nbkgdvars] = {239.264,238.869};
float N2B_pp_rap4s_0p8[nbkgdvars] = {250.362,249.438};
float N2B_pp_rap4s_1p2[nbkgdvars] = {210.617,216.568};
float N2B_pp_rap4s_1p6[nbkgdvars] = {215.938,220.341};
float N2B_pp_rap4s_2p0[nbkgdvars] = {175.566,173.867};
float N2B_pp_rap4s_2p4[nbkgdvars] = {42.4619,41.0886};
float N2B_ppLarge_pt4s_6p5[nbkgdvars] = {557.721,559.339};
float N2B_ppLarge_pt4s_10[nbkgdvars] = {434.568,437.118};
float N2B_ppLarge_pt4s_20[nbkgdvars] = {113.999,114.572};
float N2B_ppLarge_rap4s_1p2[nbkgdvars] = {681.923,686.676};
float N2B_ppLarge_rap4s_2p4[nbkgdvars] = {415.591,418.387};
float N3B_pp_rap4s_0p4[nbkgdvars] = {118.81,118.667};
float N3B_pp_rap4s_0p8[nbkgdvars] = {121.223,121.614};
float N3B_pp_rap4s_1p2[nbkgdvars] = {124.162,129.691};
float N3B_pp_rap4s_1p6[nbkgdvars] = {87.8692,86.4333};
float N3B_pp_rap4s_2p0[nbkgdvars] = {68.636,68.8069};
float N3B_pp_rap4s_2p4[nbkgdvars] = {44.3264,44.1482};
float N1B_aa_pt3p5s_2p5[nbkgdvars] = {719.236,714.063};
float N1B_aa_pt3p5s_5[nbkgdvars] = {701.647,700.585};
float N1B_aa_pt3p5s_8[nbkgdvars] = {541.604,545.933};
float N1B_aa_pt3p5s_12[nbkgdvars] = {356.408,354.699};
float N1B_aa_pt3p5s_20[nbkgdvars] = {186.325,189.371};
float N2B_aa_pt4s_6p5[nbkgdvars] = {45.9799,50.3596};
float N2B_aa_pt4s_10[nbkgdvars] = {36.8167,37.7405};
float N2B_aa_pt4s_20[nbkgdvars] = {24.0949,24.6774};
float N2B_aa_pt3p5s_6p5[nbkgdvars] = {65.1113,64.2125};
float N2B_aa_pt3p5s_10[nbkgdvars] = {58.2009,49.4513};
float N2B_aa_pt3p5s_20[nbkgdvars] = {24.5437,25.8653};
float N1B_aa_rap3p5s_0p4[nbkgdvars] = {480.545,488.964};
float N1B_aa_rap3p5s_0p8[nbkgdvars] = {487.651,481.64};
float N1B_aa_rap3p5s_1p2[nbkgdvars] = {554.208,558.021};
float N1B_aa_rap3p5s_1p6[nbkgdvars] = {544.545,546.067};
float N1B_aa_rap3p5s_2p0[nbkgdvars] = {357.161,356.25};
float N1B_aa_rap3p5s_2p4[nbkgdvars] = {111.675,111.439};
float N2B_aa_rap4s_1p2[nbkgdvars] = {75.651,72.8381};
float N2B_aa_rap4s_2p4[nbkgdvars] = {36.8759,54.0287};
float N1B_aa_cents_5[nbkgdvars] = {399.859,399.24};
float N1B_aa_cents_10[nbkgdvars] = {400.114,402.335};
float N1B_aa_cents_20[nbkgdvars] = {608.513,634.87};
float N1B_aa_cents_30[nbkgdvars] = {420.117,419.81};
float N1B_aa_cents_40[nbkgdvars] = {282.073,282.267};
float N1B_aa_cents_50[nbkgdvars] = {165.174,164.831};
float N1B_aa_cents_70[nbkgdvars] = {170.652,171.036};
float N1B_aa_cents_100[nbkgdvars] = {43.9433,45.0969};
float N1B_aa_cent4s_5[nbkgdvars] = {280.602,277.947};
float N1B_aa_cent4s_10[nbkgdvars] = {270.861,271.235};
float N1B_aa_cent4s_20[nbkgdvars] = {426.771,405.645};
float N1B_aa_cent4s_30[nbkgdvars] = {291.442,295.678};
float N1B_aa_cent4s_40[nbkgdvars] = {205.947,204.602};
float N1B_aa_cent4s_50[nbkgdvars] = {81.5316,81.3344};
float N1B_aa_cent4s_100[nbkgdvars] = {145.321,145.301};
float N2B_aa_cents_5[nbkgdvars] = {17.5189,28.5617};
float N2B_aa_cents_10[nbkgdvars] = {2.15618,2.69943};
float N2B_aa_cents_20[nbkgdvars] = {22.6711,12.2695};
float N2B_aa_cents_30[nbkgdvars] = {17.1753,23.1775};
float N2B_aa_cents_40[nbkgdvars] = {32.8176,31.9632};
float N2B_aa_cents_50[nbkgdvars] = {16.2227,16.763};
float N2B_aa_cents_100[nbkgdvars] = {14.7194,15.122};
float N1S_pp_pt4s_2p5[nfitvars] = {919.354,938.642,960.939,953.814,961.452};
float N1S_pp_pt4s_5[nfitvars] = {777.223,797.31,813.437,810.764,818.061};
float N1S_pp_pt4s_8[nfitvars] = {732.436,717.384,740.247,742.262,739.746};
float N1S_pp_pt4s_12[nfitvars] = {541.724,537.933,545.765,544.536,543.358};
float N1S_pp_pt4s_20[nfitvars] = {306.258,305.741,308.078,307.306,308.459};
float N1B_pp_pt4s_2p5[nbkgdvars] = {958.366,939.811};
float N1B_pp_pt4s_5[nbkgdvars] = {811.33,806.999};
float N1B_pp_pt4s_8[nbkgdvars] = {707.977,710.258};
float N1B_pp_pt4s_12[nbkgdvars] = {522.925,522.901};
float N1B_pp_pt4s_20[nbkgdvars] = {305.868,306.233};
float N1S_pp_rap4s_0p4[nfitvars] = {759.933,743.57,776.503,766.534,777.307};
float N1S_pp_rap4s_0p8[nfitvars] = {795.284,763.65,814.936,831.548,814.184};
float N1S_pp_rap4s_1p2[nfitvars] = {643.733,655.127,677.463,666.583,679.759};
float N1S_pp_rap4s_1p6[nfitvars] = {607.866,585.223,619.926,630.089,614.12};
float N1S_pp_rap4s_2p0[nfitvars] = {415.212,418.697,462.576,462.825,427.87};
float N1S_pp_rap4s_2p4[nfitvars] = {168.473,174.339,170.652,190.257,171.11};
float N1B_pp_rap4s_0p4[nbkgdvars] = {749.19,748.418};
float N1B_pp_rap4s_0p8[nbkgdvars] = {788.856,782.969};
float N1B_pp_rap4s_1p2[nbkgdvars] = {640.436,642.753};
float N1B_pp_rap4s_1p6[nbkgdvars] = {585.497,599.01};
float N1B_pp_rap4s_2p0[nbkgdvars] = {427.292,423.927};
float N1B_pp_rap4s_2p4[nbkgdvars] = {168.797,164.293};
float N1S_aa_pt4s_2p5[nfitvars] = {430.166,443.247,420.696,411.079,411.803};
float N1S_aa_pt4s_5[nfitvars] = {403.16,396.608,426.023,411.094,427.04};
float N1S_aa_pt4s_8[nfitvars] = {378.56,448.12,323.332,315.504,331.11};
float N1S_aa_pt4s_12[nfitvars] = {293.283,290.63,307.638,300.843,305.861};
float N1S_aa_pt4s_20[nfitvars] = {168.534,168.108,163.857,164.872,164.913};
float N1B_aa_pt4s_2p5[nbkgdvars] = {454.634,443.996};
float N1B_aa_pt4s_5[nbkgdvars] = {439.921,449.319};
float N1B_aa_pt4s_8[nbkgdvars] = {347.759,346.262};
float N1B_aa_pt4s_12[nbkgdvars] = {293.764,293.804};
float N1B_aa_pt4s_20[nbkgdvars] = {165.32,166.89};
float N1S_aa_rap4s_0p4[nfitvars] = {307.504,306.424,311.204,310.091,311.177};
float N1S_aa_rap4s_0p8[nfitvars] = {384.879,356.467,342.608,337.701,339.681};
float N1S_aa_rap4s_1p2[nfitvars] = {405.502,402.718,403.355,421.328,407.013};
float N1S_aa_rap4s_1p6[nfitvars] = {482.011,357.876,414.577,405.619,392.567};
float N1S_aa_rap4s_2p0[nfitvars] = {344.989,266.14,237.868,248.315,248.19};
float N1S_aa_rap4s_2p4[nfitvars] = {124.988,85.2752,83.6531,82.0845,81.2377};
float N1B_aa_rap4s_0p4[nbkgdvars] = {302.747,304.347};
float N1B_aa_rap4s_0p8[nbkgdvars] = {351.02,351.061};
float N1B_aa_rap4s_1p2[nbkgdvars] = {403.031,416.146};
float N1B_aa_rap4s_1p6[nbkgdvars] = {376.116,368.669};
float N1B_aa_rap4s_2p0[nbkgdvars] = {211.752,226.566};
float N1B_aa_rap4s_2p4[nbkgdvars] = {67.6028,67.8271};

//NCOLL Weights

float NcollMean[40]=
  {1747.49
   ,1566.92
   ,1393.97
   ,1237.02
   ,1095.03
   ,979.836
   ,863.228
   ,765.968
   ,677.894
   ,594.481
   ,522.453
   ,456.049
   ,399.178
   ,347.174
   ,299.925
   ,258.411
   ,221.374
   ,188.676
   ,158.896
   ,135.117
   ,112.481
   ,93.5697
   ,77.9192
   ,63.2538
   ,52.0938
   ,42.3553
   ,33.7461
   ,27.3213
   ,21.8348
   ,17.1722
   ,13.5661
   ,10.6604
   ,8.31383
   ,6.37662
   ,5.12347
   ,3.73576
   ,3.07268
   ,2.41358
   ,2.10707
   ,1.76851};
