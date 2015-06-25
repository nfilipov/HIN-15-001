#define L_pp_invNb 5400
#define L_pp_invNbe 199.8
#define N_MB_uncorr 1.126653312	
//#define N_MB_corr   1.138033648
#define T_AA_b 5662
#define T_AA_mb 5.662     
#define RapBinWidth 4.8
#define L_pp_e 0.027
#define N_MB_e 0.034

#define nPtBins_2013  5
#define nPtBins_2014 6
#define nPtBins_2010  3
#define nPtBins2015 6
#define nCentBins2015 8
#define nRapBins2015 6
#define nRapBins_2013 5
#define nRapBins_2010 2
#define nRapBins_2014 6
#define nCentBins_2014 8
#define nCentBins_2010 2
#define nCentBins2S 4
#define nPtBins2S 3
#define nRapBins2S 2
#define nRapBins_pPb 9

#define nfitvars 6
#define nbkgdvars 2
float  N_MB_corr= N_MB_uncorr/0.97;
float pt15 [6] = {1.25, 3.75, 6.5, 10., 16.,30};
float pt15e[6] = {1.25, 1.25, 1.5, 2., 4.,10};
   float pt2010 [3] = {2.7,8.7,16.2};
   float pt2010e[3] = {2.5,3.5,4};

float massRatio = 10.02/9.460;
   float rap2010[2]={0.63,1.83};
   float rap2010e[2]={0.6,0.6};
float cent2010[5]={308.6,64.24,261.3,355.7};//0-20,20-100,10-20,0-10
float nPart1[nCentBins_2014] ={8.75,42.02, 86.3, 130.1, 187.3, 261.4, 330.3, 381.2}; // with 70-100, 50-70, 40-50, 30-40, 20-30, 10-20, 5-10, 0-5
float nPart2[nCentBins2S] ={22.059352,108.1915,224.30475,355.7875};

float nPart2014[nCentBins_2014]  ={8.75, 42.02, 86.23, 130.06, 187.35, 261.49, 329.48, 381.41}; //from 2012_246_v5
//float nPart2015[nCentBins_2014+1]  ={8.75, 42.02, 86.23, 130.06, 187.35, 261.49, 329.48, 368, 393}; //from 2012_246_v5
float nPart2014e[nCentBins_2014] ={1.13,3.48,4.35,4.60,4.44,3.96,3.53,2.21}; //from 2012_246_v5

string binsPt[nPtBins2015]={"\pt [{\\rm GeV}/c] $<$ 2.5",
			     "2.5 $<$ \pt [{\\rm GeV}/c] $<$ 5",
			     "5 $<$ \pt [{\\rm GeV}/c] $<$ 8",
			     "8 $<$ \pt [{\\rm GeV}/c] $<$ 12",
			     "12 $<$ \pt [{\\rm GeV}/c] $<$ 20",
			     "20 $<$ \pt [{\\rm GeV}/c] $<$ 40"};
string binsPt2010[nPtBins2S]={"\pt [{\\rm GeV}/c] $<$ 5",
				   "5 $<$ \pt [{\\rm GeV}/c] $<$ 12",
				 "12 $<$ \pt [{\\rm GeV}/c] $<$ 40"};
   
string binsRap[nRapBins2015]={"$|y| <$ 0.4",
			       "0.4 $< |y| <$ 0.8  ",
			       "0.8 $< |y| <$ 1.2 ",
			       "1.2 $< |y| <$ 1.6 ",
			       "1.6 $< |y| <$ 2   ",
			       "2 $< |y| <$ 2.4   "};
string binsRap2010[nRapBins2S]={"$|y| <$ 1.2 ",
				   "1.2 $< |y| <$ 2.4   "};
string binsCent[nCentBins2015]={"70-100","50-70","40-50","30-40","20-30","10-20","5-10","0-5"};
//string binsCent4[nCentBins2S]={"50-100","30-50","10-30","0-10"};
string binsCent4[7]={"50-100","40-50","30-40","20-30","10-20","5-10","0-5"};
string bins2Bin[2]={"20-100","0-20"};
string bins4Bin[4]={"50-100","30-50","10-30","0-10"};
float centErr[7]={6,6,6,6,6,6,6};
float cent[7]  ={22.05, 86.3, 130.0, 187.1, 261.4, 330.4, 381.3}; // with 40-50 and 50-100 //and the 5-10 bin was 329.5, which is inconsistent with a few lines below.
float centErr2014[nCentBins_2014]={6,6,6,6,6,6,6,6};
float centnoErr[nCentBins_2014+1]={0,0,0,0,0,0,0,0,0};
float rap2014[6] = {0.2 , 0.6, 1.0, 1.4, 1.8,2.2}; // for the moment with bins of ∆y =0.8 except the last one which is 1.6-2.4
float rap2014Shift[6] = {0.3 , 0.7, 1.1, 1.5, 1.9,2.3}; // for the moment with bins of ∆y =0.8 except the last one which is 1.6-2.4
float rap2014e[6] = {0.2,0.2,0.2,0.2,0.2,0.2}; // for the moment with bins of ∆y =0.8 except the last one which is 1.6-2.4
float taa[7] = {0.486,2.748,5.089,8.782,14.477,20.47,25.901}; // taa of 40-50, 50-100
float taae[7]= {0.073,0.30 , 0.43,0.58 ,0.76  , 0.94, 1.06};
float taaDD[nCentBins_2010]={2.37,18.83171875};
float taa2014[nCentBins_2014]   = {0.13,0.985,2.75,5.089,8.80,14.48,20.48,25.91}; //taa of 50-70, 70-100
float taa2015[nCentBins_2014+1] = {0.13,0.985,2.75,5.089,8.80,14.48,20.48,24.5,27.3}; //taa of 50-70, 70-100
float taa2014e[nCentBins_2014] = {0.02,0.145,0.30,0.43,0.58,0.76,0.94,1.06};

float mb_percentage2014[nCentBins_2014] = {0.3,0.2,0.1,0.1,0.1,0.1,0.05,0.05};
float mb_percentage2015[nCentBins_2014+1] = {0.3,0.2,0.1,0.1,0.1,0.1,0.05,0.025,0.025};
float mb_percentage[7] = {0.5,0.1,0.1,0.1,0.1,0.05,0.05};
float mb_percentageDD[2]={0.8,0.2};
//////
float taa1S[nCentBins_2014]={0.13,0.985,2.75,5.089,8.80,14.48,20.48,25.91}; //taa of  70-100, 50-70, 40-50, 30-40, 20-30, 10-20, 5-10, 0-5
float taa2S[nCentBins2S]={0.486,3.918791,11.63034,23.18574}; // taa of 50-100, 30-50, 10-30, 0-10.
float taa2Se[nCentBins2S]={0.073,0.365   ,0.67    ,0.99}; // taa of 50-100, 30-50, 10-30, 0-10.
float mb_percentage1S[nCentBins_2014] = {0.3,0.2,0.1,0.1,0.1,0.1,0.05,0.05};
float mb_percentage2S[nCentBins2S] = {0.5,0.2,0.2,0.1};
/* ------------------------------------------- */
/* ------------------------------------------- */
/* ------------------------------------------- */
/*                      pp                     */
/* ------------------------------------------- */
/* ------------------------------------------- */
/* ------------------------------------------- */
/*          1S,2S,3S loose TOTAL YIELDS        */
/* ------------------------------------------- */
float N1S_pp_tot3p5 = 5014;
float N1S_pp_tot3p5e = 86;
// from fitting.
float N1S_pp_tot3p5s=0.0328;
float N2S_pp_tot3p5 = 1580;
float N2S_pp_tot3p5e = 59;
float N3S_pp_tot3p5 = 770;
float N3S_pp_tot3p5e = 49;
/* 1s2s3s tight TOTAL YIELDS */
float N1S_pp_tot4 = 3511;
float N1S_pp_tot4e = 71;
float N2S_pp_tot4 = 1208;
float N2S_pp_tot4e = 49;
float N3S_pp_tot4 = 619;
float N3S_pp_tot4e =41;
///more
float N2S_pp_tot4s=0.0209;
float N3S_pp_tot4s=0.03;
/* ------------------------------------------- */
/*                      pT                     */
/* ------------------------------------------- */
//yields
float N1S_pp_pt3p5[nPtBins_2014] = {1572.28,1440.07,992.326,612.793,338.412,55.6856};
float N1S_pp_pt3p5e[nPtBins_2014] = {53.2972,46.4318,33.5469,28.211,20.3223,8.69662};
float N2S_pp_pt3p5[nPtBins_2014] = {412.999,497.748,330.417,226.209,129.059,23.4591};
float N2S_pp_pt3p5e[nPtBins_2014] = {34.4374,32.6445,21.9493,19.3717,13.7052,5.95562};
float N3S_pp_pt3p5[nPtBins_2014] = {189.666,265.604,150.147,108.087,76.0109,16.7739};
float N3S_pp_pt3p5e[nPtBins_2014] = {28.3509,27.8029,17.4917,15.3469,11.2657,5.08771};
//misc.
float Sigma1SFixed_pp_pt3p5[nPtBins_2014] = {0.0657715,0.0651465,0.0635358,0.0638514,0.0658883,0.0576341};
float Sigma1SFree_pp_pt3p5[nPtBins_2014] = {0.0777315,0.0688134,0.068241,0.0722102,0.0695429,0.0659652};
float dM1S_pp_pt3p5[nPtBins_2014] = {-0.0132216,-0.0115218,-0.0144488,-0.012444,-0.000414656,-0.0150734};
float MassErr1S_pp_pt3p5[nPtBins_2014] = {0.00302903,0.0028209,0.00288863,0.00417897,0.0050552,0.0124403};
float N1S_ppSignif_pt[nPtBins_2014] = {29.5003,31.0147,29.5803,21.7218,16.6522,6.40313};
//systematics.
float N1S_pp_pt3p5s_2p5[nfitvars] = {1572.28,1503,1514,1717.16,1718.91,1688.36};
float N1S_pp_pt3p5s_5[nfitvars] = {1440.07,1374.54,1384.48,1468.58,1455.24,1467.65};
float N1S_pp_pt3p5s_8[nfitvars] = {992.326,1014.78,1066.19,1013.33,1013.83,1008.14};
float N1S_pp_pt3p5s_12[nfitvars] = {612.793,624.069,611.245,630.537,629.392,627.079};
float N1S_pp_pt3p5s_20[nfitvars] = {338.412,338.653,341.578,341.94,340.284,341.826};
float N1S_pp_pt3p5s_40[nfitvars] = {55.6856,58.9917,60.6328,58.5708,60.121,56.5051};
float N1B_pp_pt3p5s_2p5[nbkgdvars] = {1570.19,1611.77};
float N1B_pp_pt3p5s_5[nbkgdvars] = {1437.28,1498.7};
float N1B_pp_pt3p5s_8[nbkgdvars] = {987.619,983.463};
float N1B_pp_pt3p5s_12[nbkgdvars] = {612.943,617.179};
float N1B_pp_pt3p5s_20[nbkgdvars] = {338.397,338.405};
float N1B_pp_pt3p5s_40[nbkgdvars] = {55.6887,56.4811};
//more.
float N1S_pp_pt3p5Large[nPtBins_2010] = {2910.91,1587.86,336.5};
float N1S_pp_pt3p5Largee[nPtBins_2010] = {68.0454,46.7507,20.1515};

/* ------------------------------------------- */
/*                     pT4                     */
/* ------------------------------------------- */
 // from fitting.
float N1S_pp_tot4s=0.0160;

//yields
float N1S_pp_pt4[nPtBins_2014] = {967.076,801.956,722.227,524.345,307.016,51.733};
float N1S_pp_pt4e[nPtBins_2014] = {40.405,34.7426,30.7759,25.761,19.2917,8.43246};
float N2S_pp_pt4_2013[nPtBins_2014] = {299.481,253.659,246.08,197.06,118.733,22.1581};
float N2S_pp_pt4_2013e[nPtBins_2014] = {28.8896,23.993,20.3471,17.631,13.0047,5.85791};
float N3S_pp_pt4_2013[nPtBins_2014] = {130.857,165.947,113.379,90.3393,69.2384,16.8328};
float N3S_pp_pt4_2013e[nPtBins_2014] = {24.1252,21.8497,16.246,13.6638,10.6224,5.10678};
//misc.
float Sigma1SFixed_pp_pt4[nPtBins_2014] = {0.0621682,0.0643807,0.064376,0.0634238,0.0653103,0.0581102};
float Sigma1SFree_pp_pt4[nPtBins_2014] = {0.0648966,0.0648226,0.0716781,0.0742675,0.0664395,0.0670607};
float dM1S_pp_pt4[nPtBins_2014] = {-0.0122481,-0.0129691,-0.015045,-0.0127823,-0.00127519,-0.0144875};
float MassErr1S_pp_pt4[nPtBins_2014] = {0.00356131,0.00365256,0.00370633,0.00442942,0.00514867,0.0127577};
float N1S_ppSignif_pt[nPtBins_2014] = {23.9346,23.0828,23.4673,20.3542,15.9144,6.13498};
///1S systematics
float N1S_pp_pt4s_2p5[nfitvars] = {967.076,925.014,939.307,985.641,963.681,985.252};
float N1S_pp_pt4s_5[nfitvars] = {801.956,766.787,772.959,804.004,797.791,808.687};
float N1S_pp_pt4s_8[nfitvars] = {722.227,750.712,742.475,745.214,745.665,740.642};
float N1S_pp_pt4s_12[nfitvars] = {524.345,539.766,527.976,542.903,542.416,538.966};
float N1S_pp_pt4s_20[nfitvars] = {307.016,305.411,305.093,307.989,306.175,307.66};
float N1S_pp_pt4s_40[nfitvars] = {51.733,55.3958,56.3865,54.7651,56.8332,52.6591};

float N1B_pp_pt4s_2p5[nbkgdvars] = {966.184,1003.09};
float N1B_pp_pt4s_5[nbkgdvars] = {801.84,811.765};
float N1B_pp_pt4s_8[nbkgdvars] = {728.955,731.011};
float N1B_pp_pt4s_12[nbkgdvars] = {524.969,525.264};
float N1B_pp_pt4s_20[nbkgdvars] = {306.683,306.058};
float N1B_pp_pt4s_40[nbkgdvars] = {53.625,51.3628};
//2S systematic
float N2S_pp_pt4s_2p5[nfitvars] = {299.481,285.167,290.297,308.478,298.025,307.944};
float N2S_pp_pt4s_5[nfitvars] = {253.659,240.143,242.571,254.516,251.973,256.565};
float N2S_pp_pt4s_8[nfitvars] = {246.08,259.18,255.399,255.219,253.714,253.398};
float N2S_pp_pt4s_12[nfitvars] = {197.06,204.618,199.021,204.788,202.664,203.947};
float N2S_pp_pt4s_20[nfitvars] = {118.733,118.098,117.772,119.023,118.552,118.906};
float N2S_pp_pt4s_40[nfitvars] = {22.1581,24.5352,25.1789,23.0142,23.7023,22.4007};

float N2B_pp_pt4s_2p5[nbkgdvars] ={298.337,331.234};
float N2B_pp_pt4s_5[nbkgdvars] = {253.598,261.386};
float N2B_pp_pt4s_8[nbkgdvars] = {242.459,249.863};
float N2B_pp_pt4s_12[nbkgdvars] = {197.324,197.94};
float N2B_pp_pt4s_20[nbkgdvars] = {118.29,117.695};
float N2B_pp_pt4s_40[nbkgdvars] = {23.2067,21.9707};
//3S systematics.
float N3S_pp_pt4s_2p5[nfitvars] = {130.857,121.57,125.258,136.023,130.142,135.79};
float N3S_pp_pt4s_5[nfitvars] = {165.947,154.872,156.919,166.536,165.085,167.687};
float N3S_pp_pt4s_8[nfitvars] = {113.379,122.587,119.106,117.862,115.657,116.694};
float N3S_pp_pt4s_12[nfitvars] = {90.3393,96.2695,91.577,93.4984,91.4455,93.3789};
float N3S_pp_pt4s_20[nfitvars] = {69.2384,68.4687,68.4538,69.4091,69.1698,69.34};
float N3S_pp_pt4s_40[nfitvars] = {16.8328,19.127,19.5848,17.2849,17.3378,16.9902};

float N3B_pp_pt4s_2p5[nbkgdvars] ={130.222,149.699};
float N3B_pp_pt4s_5[nbkgdvars] = {165.938,171.081};
float N3B_pp_pt4s_8[nbkgdvars] = {113.7,115.271};
float N3B_pp_pt4s_12[nbkgdvars] = {90.5161,91.1822};
float N3B_pp_pt4s_20[nbkgdvars] = {68.7015,68.0293};
float N3B_pp_pt4s_40[nbkgdvars] = {17.4342,16.7705};
//yields in LARGE bins
float N1S_pp_pt4Large[nPtBins_2014] = {1815.31,1252.94,307.016};
float N1S_pp_pt4Largee[nPtBins_2014] = {53.4371,40.4498,19.2917};
float N2S_pp_pt4_2013Large[nPtBins_2014] = {561.816,445.58,118.733};
float N2S_pp_pt4_2013Largee[nPtBins_2014] = {37.3096,27.3261,13.0047};
float N3S_pp_pt4Large[nPtBins_2014] = {291.071,205.639,69.2384};
float N3S_pp_pt4Largee[nPtBins_2014] = {32.5092,21.6674,10.6224};
//misc.
float Sigma1SFixed_pp_pt4Large[nPtBins_2014] = {0.0619747,0.0639804,0.0653103};
float Sigma1SFree_pp_pt4Large[nPtBins_2014] = {0.0660476,0.073671,0.0664395};
float dM1S_pp_pt4Large[nPtBins_2014] = {-0.0131041,-0.0141875,-0.00127519};
float MassErr1S_pp_pt4Large[nPtBins_2014] = {0.0025199,0.00283435,0.00514867};
float N1S_ppSignif_pt4Large[nPtBins_2014] = {33.9709,30.9751,15.9144};
//systematics.
float N1S_pp_pt4Larges_5[nfitvars] = {1815.31,1786.71,1758.78,1864.13,1855.15,1863.3};
float N1S_pp_pt4Larges_12[nfitvars] = {1252.94,1298.77,1290.79,1304.05,1304.53,1294.3};
float N1S_pp_pt4Larges_20[nfitvars] = {307.016,305.411,305.093,307.989,306.175,307.66};
float N1B_pp_pt4Larges_5[nbkgdvars] = {1885.52,1804.3};
float N1B_pp_pt4Larges_12[nbkgdvars] = {1253.22,1256};
float N1B_pp_pt4Larges_20[nbkgdvars] = {306.683,306.058};

float N2S_pp_pt4Larges_5[nfitvars] = {561.816,550.472,539.35,583.442,577.834,582.982};
float N2S_pp_pt4Larges_12[nfitvars] = {445.58,468.876,464.988,468.763,464.449,465.366};
float N2S_pp_pt4Larges_20[nfitvars] = {118.733,118.098,117.772,119.023,118.552,118.906};
float N2B_pp_pt4Larges_5[nbkgdvars] = {572.742,551.631};
float N2B_pp_pt4Larges_12[nbkgdvars] = {445.828,447.347};
float N2B_pp_pt4Larges_20[nbkgdvars] = {118.29,117.695};

float N3S_pp_pt4Larges_5[nfitvars] = {291.071,283.473,276.443,303.336,298.002,303.115};
float N3S_pp_pt4Larges_12[nfitvars] = {205.639,224.195,218.427,219.163,214.063,216.928};
float N3S_pp_pt4Larges_20[nfitvars] = {69.2384,68.4687,68.4538,69.4091,69.1698,69.34};
float N3B_pp_pt4Larges_5[nbkgdvars] = {328.256,284.495};
float N3B_pp_pt4Larges_12[nbkgdvars] = {205.917,206.851};
float N3B_pp_pt4Larges_20[nbkgdvars] = {68.7015,68.0293};
/* ------------------------------------------- */
/*                     rap                     */
/* ------------------------------------------- */
//yields.
float N1S_pp_rap3p5_2014[nRapBins_2014] = {1092.5,1128.57,995.542,918.941,645.336,251.364};
float N1S_pp_rap3p5_2014e[nRapBins_2014] = {37.8835,39.7245,38.7406,38.4787,33.6877,19.9065};
float N2S_pp_rap3p5_2014[nRapBins_2014] = {354.108,344.231,314.176,319.549,214.78,49.3066};
float N2S_pp_rap3p5_2014e[nRapBins_2014] = {25.3405,25.6201,26.5923,27.7139,24.2527,12.8926};
float N3S_pp_rap3p5_2014[nRapBins_2014] = {164.683,170.879,169.927,122.821,85.7292,56.1713};
float N3S_pp_rap3p5_2014e[nRapBins_2014] = {20.271,21.4023,23.1257,22.8193,19.8861,12.4869};
//misc.
float Sigma1SFixed_pp_rap3p5[nRapBins_2014] = {0.0596087,0.0614638,0.0781951,0.0863752,0.125475,0.128811};
float Sigma1S_pt3p5_rap[nRapBins_2014]={ 0.0527233, 0.0599054, 0.0773693, 0.104566, 0.125792, 0.133793};//MC
float Sigma1SFree_pp_rap3p5[nRapBins_2014] = {0.0634828,0.0663536,0.0810865,0.0948662,0.145678,0.119366};
float dM1S_pp_rap3p5[nRapBins_2014] = {-0.0100056,-0.0106375,-0.0119218,-0.0157293,-0.0279727,-0.0242207};
float MassErr1S_pp_rap3p5[nRapBins_2014] = {0.00212303,0.00256095,0.00364298,0.00490568,0.007465,0.013407};
float N1S_ppSignif_rap3p5[nRapBins_2014] = {28.8383,28.41,25.6976,23.8818,19.1564,12.6272};
//systematics.
float N1S_pp_rap3p5s_0p4[nfitvars] = {1092.5,1147.32,1115.91,1112.04,1107.18,1092.56};
float N1S_pp_rap3p5s_0p8[nfitvars] = {1128.57,1145.9,1153.83,1158.07,1168.04,1159.09};
float N1S_pp_rap3p5s_1p2[nfitvars] = {995.542,1021.59,1038.82,1008.55,1000.56,1007.17};
float N1S_pp_rap3p5s_1p6[nfitvars] = {918.941,934.622,886.425,955.587,974.04,943.41};
float N1S_pp_rap3p5s_2p0[nfitvars] = {645.336,625.537,632.476,693.879,695.068,645.393};
float N1S_pp_rap3p5s_2p4[nfitvars] = {251.364,247.976,257.355,244.761,241.562,243.88};
float N1B_pp_rap3p5s_0p4[nfitvars] = {1080.73,1077.41};
float N1B_pp_rap3p5s_0p8[nfitvars] = {1119.78,1130.05};
float N1B_pp_rap3p5s_1p2[nfitvars] = {966.039,965.755};
float N1B_pp_rap3p5s_1p6[nfitvars] = {901.186,920.154};
float N1B_pp_rap3p5s_2p0[nfitvars] = {637.555,643.355};
float N1B_pp_rap3p5s_2p4[nfitvars] = {270.787,252.685};
//more !
float Sigma2S_pt3p5_rap[6]={ 0.0538801, 0.0653175, 0.0776217, 0.115183, 0.130717, 0.15466};
float Sigma2S_pt3p5_rapLarge[2]={0.0611883,0.127322};
float Sigma2S_pt3p5_mb= 0.0692664;

float Sigma1S_pt3p5_rapLarge[2]={0.0595051,0.119058};
float Sigma1S_pt3p5_mb=0.0627095;

float Sigma2S_pt4_rap[6]={0.0512988,0.0598307,0.0856582,0.105473,0.13179,0.145594};
float Sigma2S_pt4_rapLarge[2]={0.060022,0.128939};
float Sigma2S_pt4_mb= 0.0689469;

float Sigma1S_pt4_rap[6]={ 0.045297 ,0.0614344 ,0.0719728 ,0.10143 ,0.126482 ,0.138467};
float Sigma1S_pt4_rapLarge[2]={0.0552385,0.118975};
float Sigma1S_pt4_mb=0.0623872;

/* ------------------------------------------- */
/*                     rap4                    */
/* ------------------------------------------- */
///yields.
float N1S_pp_rap4_2014[nRapBins_2014] = {782.23,802.491,699.794,614.806,437.486,176.401};
float N1S_pp_rap4_2014e[nRapBins_2014] = {31.2266,32.6484,31.6465,30.3664,26.5538,16.3107};
float N2S_pp_rap4_2014[nRapBins_2014] = {264.55,262.829,240.499,231.739,180.187,43.742};
float N2S_pp_rap4_2014e[nRapBins_2014] = {20.8445,21.3374,21.6577,22.3763,19.9133,11.4295};
float N3S_pp_rap4_2014[nRapBins_2014] = {132.828,129.687,140.47,102.722,77.4439,45.8224};
float N3S_pp_rap4_2014e[nRapBins_2014] = {16.786,17.5355,18.7523,18.7354,16.117,11.2161};
//misc.
float Sigma1SFixed_pp_rap4[nRapBins_2014] = {0.058396,0.061831,0.0785538,0.0873738,0.125342,0.132376};
float Sigma1SFree_pp_rap4[nRapBins_2014] = {0.0638302,0.0693133,0.0853293,0.0966755,0.151849,0.133359};
float dM1S_pp_rap4[nRapBins_2014] = {-0.0103058,-0.0106436,-0.0114406,-0.0153713,-0.0247878,-0.0269885};
float MassErr1S_pp_rap4[nRapBins_2014] = {0.00234122,0.00290341,0.00417545,0.0057725,0.0085887,0.0158849};
float N1S_ppSignif_rap4[nRapBins_2014] = {25.0501,24.5798,22.1129,20.2462,16.4755,10.8151};
///systematics.
float N1S_pp_rap4s_0p4[nfitvars] = {782.23,791.331,768.114,800.862,806.702,782.548};
float N1S_pp_rap4s_0p8[nfitvars] = {802.491,826.824,801.51,832.931,851.088,831.352};
float N1S_pp_rap4s_1p2[nfitvars] = {699.794,722.315,734.578,720.927,722.009,720.942};
float N1S_pp_rap4s_1p6[nfitvars] = {614.806,611.519,599.937,639.456,650.434,632.723};
float N1S_pp_rap4s_2p0[nfitvars] = {437.486,454.616,431.229,475.955,479.004,437.34};
float N1S_pp_rap4s_2p4[nfitvars] = {176.401,171.655,180.384,176.903,176.532,177.016};
float N1B_pp_rap4s_0p4[nbkgdvars] = {771.599,777.605};
float N1B_pp_rap4s_0p8[nbkgdvars] = {802.583,819.781};
float N1B_pp_rap4s_1p2[nbkgdvars] = {668.54,725.711};
float N1B_pp_rap4s_1p6[nbkgdvars] = {618.827,582.859};
float N1B_pp_rap4s_2p0[nbkgdvars] = {437.871,382.089};
float N1B_pp_rap4s_2p4[nbkgdvars] = {176.464,174.99};

float N2S_pp_rap4s_0p4[nfitvars] = {264.55,269.149,257.818,276.679,278.327,265.797};
float N2S_pp_rap4s_0p8[nfitvars] = {262.829,273.691,262.38,275.834,280.118,274.266};
float N2S_pp_rap4s_1p2[nfitvars] = {240.499,250.657,256.287,249.234,248.889,248.693};
float N2S_pp_rap4s_1p6[nfitvars] = {231.739,229.78,222.941,244.43,247.04,240.781};
float N2S_pp_rap4s_2p0[nfitvars] = {180.187,193.069,175.966,196.342,195.777,183.446};
float N2S_pp_rap4s_2p4[nfitvars] = {43.742,42.1703,45.0893,43.798,43.727,43.7081};
float N2B_pp_rap4s_0p4[nbkgdvars] = {252.117,256.357};
float N2B_pp_rap4s_0p8[nbkgdvars] = {262.837,269.042};
float N2B_pp_rap4s_1p2[nbkgdvars] = {217.481,258.927};

float N2B_pp_rap4s_1p6[nbkgdvars] = {230.016,214.243};
float N2B_pp_rap4s_2p0[nbkgdvars] = {180.656,158.104};
float N2B_pp_rap4s_2p4[nbkgdvars] = {43.7351,42.9345};

float N3S_pp_rap4s_0p4[nfitvars] = {132.828,136.015,128.241,140.925,141.839,133.968};
float N3S_pp_rap4s_0p8[nfitvars] = {129.687,138.295,129.38,140.393,140.146,138.597};
float N3S_pp_rap4s_1p2[nfitvars] = {140.47,148.607,151.712,145.317,144.174,144.651};
float N3S_pp_rap4s_1p6[nfitvars] = {102.722,101.418,96.8322,107.871,108.841,106.541};
float N3S_pp_rap4s_2p0[nfitvars] = {77.4439,86.2675,74.3712,79.7068,79.6769,77.3836};
float N3S_pp_rap4s_2p4[nfitvars] = {45.8224,43.9244,47.2746,45.8833,45.8811,45.891};
float N3B_pp_rap4s_0p4[nbkgdvars] = {124.293,125.137};
float N3B_pp_rap4s_0p8[nbkgdvars] = {129.717,128.145};
float N3B_pp_rap4s_1p2[nbkgdvars] = {127.27,154.577};
float N3B_pp_rap4s_1p6[nbkgdvars] = {104.78,93.1205};
float N3B_pp_rap4s_2p0[nbkgdvars] = {78.0999,76.3731};
float N3B_pp_rap4s_2p4[nbkgdvars] = {45.7994,45.3594};



///yields in LARGE bins.
float N1S_pp_rap4_2014Large[nRapBins_2014] = {2295.59,1213.29};
float N1S_pp_rap4_2014Largee[nRapBins_2014] = {55.6207,43.0243};
float N2S_pp_rap4_2014Large[nRapBins_2014] = {769.055,450.75};
float N2S_pp_rap4_2014Largee[nRapBins_2014] = {37.0785,31.4276};
float N3S_pp_rap4_2014Large[nRapBins_2014] = {397.339,221.937};
float N3S_pp_rap4_2014Largee[nRapBins_2014] = {30.9002,26.4746};
//misc.in LARGE bins
float Sigma1SFixed_pp_rap4Large[nRapBins_2014] = {0.0565126,0.119036};
float Sigma1SFree_pp_rap4Large[nRapBins_2014] = {0.0631154,0.135731};
float dM1S_pp_rap4Large[nRapBins_2014] = {-0.0107215,-0.0197704};
float MassErr1S_pp_rap4Large[nRapBins_2014] = {0.00175129,0.00474189};
float N1S_ppSignif_rap4Large[nRapBins_2014] = {41.2722,28.2001};
/// systematics. in LARGE bins
float N1S_pp_rap4Larges_1p2[nfitvars] = {2295.59,2369.09,2331.89,2377.68,2388.33,2365.31};
float N1S_pp_rap4Larges_2p4[nfitvars] = {1213.29,1249.33,1199.55,1280.75,1281.26,1213.99};
float N2S_pp_rap4Larges_1p2[nfitvars] = {769.055,804.49,785.79,810.184,809.883,803.095};
float N2S_pp_rap4Larges_2p4[nfitvars] = {450.75,474.197,442.327,481.679,481.71,461.855};
float N3S_pp_rap4Larges_1p2[nfitvars] = {397.339,425.207,408.55,427.253,422.246,421.938};
float N3S_pp_rap4Larges_2p4[nfitvars] = {221.937,238.665,215.493,232.363,232.424,224.642};
float N1B_pp_rap4Larges_1p2[nbkgdvars] = {2243.22,2243.13};
float N1B_pp_rap4Larges_2p4[nbkgdvars] = {1185.71,1221.01};
float N2B_pp_rap4Larges_1p2[nbkgdvars] = {733.512,728.42};
float N2B_pp_rap4Larges_2p4[nbkgdvars] = {430.634,454.998};
float N3B_pp_rap4Larges_1p2[nbkgdvars] = {377.964,371.546};
float N3B_pp_rap4Larges_2p4[nbkgdvars] = {209.785,227.897};
/* ------------------------------------------- */
/* ------------------------------------------- */
/* ------------------------------------------- */
/*                      AA                     */
/* ------------------------------------------- */
/* ------------------------------------------- */
/* ------------------------------------------- */
/* 1S,2S,3S loose TOTAL YIELDS*/
/* ------------------------------------------- */
float N1S_aa_tot3p5 = 2540;
float N1S_aa_tot3p5e = 79;
float N2S_aa_tot3p5 = 158;
float N2S_aa_tot3p5e = 54;
float N3S_aa_tot3p5 = 0;
float N3S_aa_tot3p5e = 35;
/* 1s2s3s tight TOTAL YIELDS */
float N1S_aa_tot4 = 1793;
float N1S_aa_tot4e = 61;
float N2S_aa_tot4 = 173;
float N2S_aa_tot4e = 41;
float N3S_aa_tot4 = 7;
float N3S_aa_tot4e =9;
///more
float N2S_aa_tot4s=0.0712;
float N1S_aa_tot3p5s=0.0470;
float N1S_aa_tot4s=0.0281;

/* float N1S_pp_tot3p5s[nfitvars] = {5013.93,5132.63,5069.73,5185.89,5187.98,5158.67}; */
/* float N1S_pp_tot4s[nfitvars] = {3511.4,3683.83,3621.77,3694.21,3722.78,3659.11}; */
/* float N1S_aa_tot3p5s[nfitvars] = {2533.78,2858.08,3020.9,2626.89,2656.25,2627.41}; */
/* float N1S_aa_tot4s[nfitvars] = {1792.67,2141.8,2133.84,1963.26,1984.24,1921.01}; */
/* float N2S_pp_tot3p5s[nfitvars] = {1580.16,1630.17,1603.36,1657.93,1645.53,1645.52}; */
/* float N2S_pp_tot4s[nfitvars] = {1208.15,1297.9,1263.07,1292.82,1287.31,1278.4}; */
/* float N2S_aa_tot3p5s[nfitvars] = {155.425,215.334,231.992,170.413,171.442,174.193}; */
/* float N2S_aa_tot4s[nfitvars] = {172.85,267.091,244.92,211.387,207.03,201.746}; */
/* float N3S_pp_tot3p5s[nfitvars] = {769.791,806.327,784.602,816.081,802.08,807.586}; */
/* float N3S_pp_tot4s[nfitvars] = {618.65,688.795,656.044,669.956,657.858,660.307}; */
/* float N3S_aa_tot3p5s[nfitvars] = {-34.5042,-5.64183,-3.96734,-28.359,-26.7918,-24.7919}; */
/* float N3S_aa_tot4s[nfitvars] = {6.5409,50.1639,37.9764,12.7675,15.0923,8.01297}; */
/* float N1B_pp_tot3p5s[nbkgdvars] = {5013.89,4927.13}; */
/* float N1B_pp_tot4s[nbkgdvars] = {3380.34,3362.59}; */
/* float N1B_aa_tot3p5s[nbkgdvars] = {2527.41,2819.72}; */
/* float N1B_aa_tot4s[nbkgdvars] = {1822.57,1694.81}; */
/* float N2B_pp_tot3p5s[nbkgdvars] = {1580.29,1519.38}; */
/* float N2B_pp_tot4s[nbkgdvars] = {1098.98,1094.82}; */
/* float N2B_aa_tot3p5s[nbkgdvars] = {135.759,241.787}; */
/* float N2B_aa_tot4s[nbkgdvars] = {174.694,129.872}; */
/* float N3B_pp_tot3p5s[nbkgdvars] = {769.787,735.609}; */
/* float N3B_pp_tot4s[nbkgdvars] = {548.971,555.266}; */
/* float N3B_aa_tot3p5s[nbkgdvars] = {-3.30886,0.822784}; */
/* float N3B_aa_tot4s[nbkgdvars] = {-5.73496,-7.69648}; */
/* ------------------------------------------- */
/*                      pT                     */
/* ------------------------------------------- */
//yields
float N1S_aa_pt3p5[nPtBins_2014] = {760.933,678.866,530.796,361.6,177.961,46.192};
float N1S_aa_pt3p5e[nPtBins_2014] = {43.4236,41.5262,35.1437,26.8422,16.4929,7.67069};
float N2S_aa_pt3p5[nPtBins_2014] = {38.5345,61.0967,19.4428,32.9812,21.0261,5.90805};
float N2S_aa_pt3p5e[nPtBins_2014] = {27.8995,29.7666,24.5745,19.2152,9.39404,3.73998};
float N3S_aa_pt3p5[nPtBins_2014] = {-24.894,-43.8698,-3.42538,41.9194,17.6632,4.64569};
float N3S_aa_pt3p5e[nPtBins_2014] = {25.0188,26.6804,23.6922,19.1594,9.48789,3.51349};
//misc.
float Sigma1SFixed_aa_pt3p5[nPtBins_2014] = {0.0656364,0.0618933,0.0659009,0.0623484,0.0686772,0.0667923};
float Sigma1SFree_aa_pt3p5[nPtBins_2014] = {0.0733402,0.0714295,0.0581046,0.0700393,0.0685762,0.0658703};
float dM1S_aa_pt3p5[nPtBins_2014] = {-0.0134142,-0.00394025,-0.0155896,-0.0189322,-0.0114653,-0.00609381};
float MassErr1S_aa_pt3p5[nPtBins_2014] = {0.00584566,0.00632672,0.00662793,0.00764481,0.00904496,0.0159101};
float N1S_aaSignif_pt3p5[nPtBins_2014] = {17.5235,16.3479,14.8494,13.4713,10.7902,6.02189};
//systematics.
float N1S_aa_pt3p5s_2p5[nfitvars] = {760.933,876.441,794.776,806.189,837.578,796.411};
float N1S_aa_pt3p5s_5[nfitvars] = {678.866,722.796,684.599,729.472,721.26,725.775};
float N1S_aa_pt3p5s_8[nfitvars] = {530.796,576.185,563.111,493.397,570.754,504.789};
float N1S_aa_pt3p5s_12[nfitvars] = {361.6,342.497,355.803,380.584,368.237,381.336};
float N1S_aa_pt3p5s_20[nfitvars] = {177.961,179.252,176.682,177.875,179.029,178.8};
float N1S_aa_pt3p5s_40[nfitvars] = {46.192,46.3489,45.9434,46.0589,45.2119,45.8102};
float N1B_aa_pt3p5s_2p5[nbkgdvars] = {760.737,755.709};
float N1B_aa_pt3p5s_5[nbkgdvars] = {678.898,693.515};
float N1B_aa_pt3p5s_8[nbkgdvars] = {525.072,534.274};
float N1B_aa_pt3p5s_12[nbkgdvars] = {362.858,362.077};
float N1B_aa_pt3p5s_20[nbkgdvars] = {184.693,181.525};
float N1B_aa_pt3p5s_40[nbkgdvars] = {18.5629,48.3119};
// more.
float N1S_aa_pt3p5Large[nPtBins_2010] = {1842,466,311}; // ,53
float N1S_aa_pt3p5eLarge[nPtBins_2010] = {110,67,24}; //,8.9   // wowowowow 2nd bin was 107, tricked it :) for unimportant reasons.

/* ------------------------------------------- */
/*                     pT4                     */
/* ------------------------------------------- */
//yields
float N1S_aa_pt4[nPtBins_2014] = {433.283,384.967,346.047,300.326,159.695,45.065};
float N1S_aa_pt4e[nPtBins_2014] = {33.7162,30.0662,27.4315,25.3158,15.3784,7.5391};
float N2S_aa_pt4[nPtBins_2014] = {48.7338,29.3859,7.77242,29.4405,21.5532,5.27905};
float N2S_aa_pt4e[nPtBins_2014] = {24.4006,20.9108,17.7383,17.6174,8.64076,3.49062};
float N3S_aa_pt4[nPtBins_2014] = {-7.84042,-38.9282,12.6483,28.0485,13.6672,4.66497};
float N3S_aa_pt4e[nPtBins_2014] = {21.2706,18.4735,17.6898,17.2649,8.30698,3.42729};
//misc.
float Sigma1SFixed_aa_pt4[nPtBins_2014] = {0.0669886,0.0647348,0.0644703,0.0691862,0.0669463,0.0670985};
float Sigma1SFree_aa_pt4[nPtBins_2014] = {0.056516,0.0751985,0.0581788,0.0783052,0.0682196,0.06802};
float dM1S_aa_pt4[nPtBins_2014] = {-0.00709436,-0.00471441,-0.0131285,-0.0139764,-0.00944243,-0.00612074};
float MassErr1S_aa_pt4[nPtBins_2014] = {0.0068624,0.00804628,0.0076398,0.00912405,0.00910543,0.0166445};
float N1S_aaSignif_pt4[nPtBins_2014] = {12.8509,12.804,12.6149,11.8632,10.3844,5.97751};
//systematics
float N1S_aa_pt4s_2p5[nfitvars] = {433.283,414.404,423.064,397.864,381.754,376.1};
float N1S_aa_pt4s_5[nfitvars] = {384.967,380.278,377.777,413.72,389.548,416.801};
float N1S_aa_pt4s_8[nfitvars] = {346.047,384.377,368.683,330.862,372.875,335.985};
float N1S_aa_pt4s_12[nfitvars] = {300.326,297.676,300.929,318.959,306.348,319.321};
float N1S_aa_pt4s_20[nfitvars] = {159.695,164.284,162.328,160.665,161.643,161.326};
float N1S_aa_pt4s_40[nfitvars] = {45.065,45.5177,45.0431,45.1683,44.348,45.1709};
float N1B_aa_pt4s_2p5[nbkgdvars] = {425.519,418.276};
float N1B_aa_pt4s_5[nbkgdvars] = {384.957,404.756};
float N1B_aa_pt4s_8[nbkgdvars] = {346.134,340.555};
float N1B_aa_pt4s_12[nbkgdvars] = {301.573,302.477};
float N1B_aa_pt4s_20[nbkgdvars] = {163.28,162.274};
float N1B_aa_pt4s_40[nbkgdvars] = {45.0806,45.0653};
//yields in LARGE bins
float N1S_aa_pt4Large[nPtBins_2014] = {846.135,645.789,159.695};
float N1S_aa_pt4Largee[nPtBins_2014] = {44.1422,37.618,15.3784};
float N2S_aa_pt4_2013Large[nPtBins_2014] = {54.2752,36.4798,21.5532};
float N2S_aa_pt4_2013Largee[nPtBins_2014] = {30.9272,25.3085,8.64076};
float N3S_aa_pt4Large[nPtBins_2014] = {-78.4035,40.7143,13.6672};
float N3S_aa_pt4Largee[nPtBins_2014] = {27.6608,25.0584,8.30698};
///misc. in LARGE bins
float Sigma1SFixed_aa_pt4Large[nPtBins_2014] = {0.0667507,0.0681378,0.0669463};
float Sigma1SFree_aa_pt4Large[nPtBins_2014] = {0.0707061,0.0692729,0.0682196};
float dM1S_aa_pt4Large[nPtBins_2014] = {-0.0086259,-0.0133301,-0.00944243};
float MassErr1S_aa_pt4Large[nPtBins_2014] = {0.0051213,0.0058627,0.00910543};
float N1S_aaSignif_pt4Large[nPtBins_2014] = {19.1684,17.167,10.3844};
//systematics in LARGE bins

float N1S_aa_pt4Larges_5[nfitvars] = {846.135,872.958,955.15,869.414,849.177,868.041};
float N1S_aa_pt4Larges_12[nfitvars] = {645.789,668.411,689.387,650.751,670.729,655.77};
float N1S_aa_pt4Larges_20[nfitvars] = {159.695,164.284,162.328,160.665,161.643,161.326};
float N2S_aa_pt4Larges_5[nfitvars] = {54.2752,61.1702,73.1438,59.1765,54.753,58.9672};
float N2S_aa_pt4Larges_12[nfitvars] = {36.4798,40.0178,42.106,37.3944,39.0083,38.2637};
float N2S_aa_pt4Larges_20[nfitvars] = {21.5532,21.8526,21.8926,21.5896,21.6613,21.6157};
float N3S_aa_pt4Larges_5[nfitvars] = {-78.4035,-77.9421,-82.581,-79.204,-78.5031,-77.9699};
float N3S_aa_pt4Larges_12[nfitvars] = {40.7143,45.4306,46.0164,41.6891,44.8673,42.6112};
float N3S_aa_pt4Larges_20[nfitvars] = {13.6672,14.3737,14.0585,13.8429,13.8907,13.9273};

float N1B_aa_pt4Larges_5[nbkgdvars] = {827.386,845.978};
float N1B_aa_pt4Larges_12[nbkgdvars] = {648.484,644.828};
float N1B_aa_pt4Larges_20[nbkgdvars] = {163.28,162.274};
float N2B_aa_pt4Larges_5[nbkgdvars] = {47.9794,54.19};
float N2B_aa_pt4Larges_12[nbkgdvars] = {36.9826,39.1056};
float N2B_aa_pt4Larges_20[nbkgdvars] = {24.113,23.6487};
float N3B_aa_pt4Larges_5[nbkgdvars] = {-78.2856,-78.5648};
float N3B_aa_pt4Larges_12[nbkgdvars] = {42.4352,44.4381};
float N3B_aa_pt4Larges_20[nbkgdvars] = {16.4182,16.0991};
/* ------------------------------------------- */
/*                     rap                     */
/* ------------------------------------------- */
//yields
float N1S_aa_rap3p5_2014[nRapBins_2014] = {501.933,505.446,559.22,533.105,364.85,113.75};
float N1S_aa_rap3p5_2014e[nRapBins_2014] = {31.9277,34.4893,38.0134,39.2303,29.0945,17.2147};
float N2S_aa_rap3p5[nRapBins_2014] = {25.7154,47.789,25.3167,-1.02024,33.9907,4.00955};
float N2S_aa_rap3p5e[nRapBins_2014] = {21.3964,24.589,27.1056,28.3258,19.3551,11.1802};
float N3S_aa_rap3p5_2014[nRapBins_2014] = {-2.4566,6.87048e-05,-1.04105,-3.33196,-39.127,-12.2435};
float N3S_aa_rap3p5_2014e[nRapBins_2014] = {20.2548,2.72889,25.5479,27.2737,16.0976,9.24833};
//misc.
float Sigma1SFixed_aa_rap3p5[nRapBins_2014] = {0.0527233,0.0599054,0.0773693,0.104566,0.125792,0.133793};
float Sigma1SFree_aa_rap3p5[nRapBins_2014] = {0.0535277,0.0606161,0.079676,0.116666,0.129474,0.169339};
float dM1S_aa_rap3p5[nRapBins_2014] = {-0.000811592,-0.0164258,-0.0112044,-0.0327148,-0.0298901,-0.0033971};
float MassErr1S_aa_rap3p5[nRapBins_2014] = {0.00447293,0.00592714,0.00752893,0.0100597,0.0123124,0.0287447};
float N1S_aaSignif_rap3p5[nRapBins_2014] = {15.7209,14.6369,14.7111,13.5891,11.8003,6.60771};
//systematics
float N1S_aa_rap3p5s_0p4[nfitvars] = {501.933,557.704,523.917,505.072,500.089,506.965};
float N1S_aa_rap3p5s_0p8[nfitvars] = {505.446,469.686,530.623,508.514,581.509,509.544};
float N1S_aa_rap3p5s_1p2[nfitvars] = {559.22,588.658,584.116,567.594,606.676,563.445};
float N1S_aa_rap3p5s_1p6[nfitvars] = {533.105,506.185,509.8,565.431,528.332,579.452};
float N1S_aa_rap3p5s_2p0[nfitvars] = {364.85,414.25,395.939,365.404,367.594,373.51};
float N1S_aa_rap3p5s_2p4[nfitvars] = {113.75,127.982,128.931,130.198,126.061,128.281};
float N1B_aa_rap3p5s_0p4[nfitvars] = {501.877,497.065};
float N1B_aa_rap3p5s_0p8[nfitvars] = {496.218,504.323};
float N1B_aa_rap3p5s_1p2[nfitvars] = {590.888,569.043};
float N1B_aa_rap3p5s_1p6[nfitvars] = {557.894,493.28};
float N1B_aa_rap3p5s_2p0[nfitvars] = {347.845,354.127};
float N1B_aa_rap3p5s_2p4[nfitvars] = {109.87,115.382};
/* ------------------------------------------- */
/*                     rap4                    */
/* ------------------------------------------- */
//yields
float N1S_aa_rap4_2014[nRapBins_2014] = {315.4,355.349,415.457,390.112,260.004,82.5953};
float N1S_aa_rap4_2014e[nRapBins_2014] = {24.4578,26.1104,28.5403,29.2065,23.5313,14.2299};
float N2S_aa_rap4_2014[nRapBins_2014] = {15.4477,46.3563,42.8718,20.0568,48.7863,13.513};
float N2S_aa_rap4_2014e[nRapBins_2014] = {15.6473,17.6678,19.3013,19.2523,16.6316,10.2389};
float N3S_aa_rap4_2014[nRapBins_2014] = {3.20679,-1.17089,8.70614,13.5345,-13.8146,-17.4124};
float N3S_aa_rap4_2014e[nRapBins_2014] = {15.0704,16.2453,17.7942,18.7001,14.2255,7.57694};
//misc.
float Sigma1SFixed_aa_rap4[nRapBins_2014] = {0.045297,0.0614344,0.0719728,0.10143,0.126482,0.138467};
float Sigma1SFree_aa_rap4[nRapBins_2014] = {0.048086,0.0615164,0.071554,0.123385,0.144575,0.221781};
float dM1S_aa_rap4[nRapBins_2014] = {-0.00491885,-0.0147612,-0.008586,-0.0208951,-0.0259933,-0.001434};
float MassErr1S_aa_rap4[nRapBins_2014] = {0.0054081,0.00604569,0.00714609,0.0101958,0.0135545,0.0329942};
float N1S_aaSignif_rap4[nRapBins_2014] = {12.8957,13.6095,14.5569,13.357,11.0493,5.80433};
//systematics.
float N1S_aa_rap4s_0p4[nfitvars] = {315.4,318.086,308.796,322.98,327.084,320.5};
float N1S_aa_rap4s_0p8[nfitvars] = {355.349,389.565,393.977,355.544,357.455,356.292};
float N1S_aa_rap4s_1p2[nfitvars] = {415.457,418.177,414.525,414.529,425.312,413.503};
float N1S_aa_rap4s_1p6[nfitvars] = {390.112,466.382,409.873,433.094,402.555,438.621};
float N1S_aa_rap4s_2p0[nfitvars] = {260.004,304.554,327.95,279.866,260.003,259.917};
float N1S_aa_rap4s_2p4[nfitvars] = {82.5953,130.803,97.9972,111.163,88.6033,103.25};
float N1B_aa_rap4s_0p4[nbkgdvars] = {352.981,307.475};
float N1B_aa_rap4s_0p8[nbkgdvars] = {355.261,376.219};
float N1B_aa_rap4s_1p2[nbkgdvars] = {466.599,422.476};
float N1B_aa_rap4s_1p6[nbkgdvars] = {379.41,428.79};
float N1B_aa_rap4s_2p0[nbkgdvars] = {228.164,211.173};
float N1B_aa_rap4s_2p4[nbkgdvars] = {76.7772,95.3631};

//yields in LARGE bins
float N1S_aa_rap4_2014Large[nRapBins_2014] = {1089.75,729.382};
float N1S_aa_rap4_2014Largee[nRapBins_2014] = {46.3686,39.8931};
float N2S_aa_rap4_2014Large[nRapBins_2014] = {104.241,76.9046};
float N2S_aa_rap4_2014Largee[nRapBins_2014] = {30.7392,27.3069};
float N3S_aa_rap4_2014Large[nRapBins_2014] = {11.312,-11.1267};
float N3S_aa_rap4_2014Largee[nRapBins_2014] = {28.6748,25.0645};
//misc. in large bins.
float Sigma1SFixed_aa_rap4Large[nRapBins_2014] = {0.0552385,0.118975};
float Sigma1SFree_aa_rap4Large[nRapBins_2014] = {0.0569407,0.139554};
float dM1S_aa_rap4Large[nRapBins_2014] = {-0.01003,-0.023409};
float MassErr1S_aa_rap4Large[nRapBins_2014] = {0.00354532,0.00804737};
float N1S_aaSignif_rap4Large[nRapBins_2014] = {23.5018,18.2834};
//systematics in LARGE bins
float N1S_aa_rap4Larges_1p2[nfitvars] = {1089.75,1152.79,1186.84,1103.54,1122.33,1100.02};
float N1S_aa_rap4Larges_2p4[nfitvars] = {729.382,889.347,768.479,794.173,733.6,729.372};
float N2S_aa_rap4Larges_1p2[nfitvars] = {104.241,118.227,121.971,107.585,112.466,106.724};
float N2S_aa_rap4Larges_2p4[nfitvars] = {76.9046,128.006,87.3887,89.7671,77.0601,76.9121};
float N3S_aa_rap4Larges_1p2[nfitvars] = {11.312,18.1969,18.6623,12.9559,16.3165,12.6207};
float N3S_aa_rap4Larges_2p4[nfitvars] = {-11.1267,14.8977,-7.15973,-4.10369,-10.8712,-11.2122};
float N1B_aa_rap4Larges_1p2[nbkgdvars] = {1090.46,1055.59};
float N1B_aa_rap4Larges_2p4[nbkgdvars] = {713.159,676.353};
float N2B_aa_rap4Larges_1p2[nbkgdvars] = {97.4046,75.5631};
float N2B_aa_rap4Larges_2p4[nbkgdvars] = {70.6606,44.6696};
float N3B_aa_rap4Larges_1p2[nbkgdvars] = {4.6086,-11.0344};
float N3B_aa_rap4Larges_2p4[nbkgdvars] = {-12.7046,-27.942};

/* ------------------------------------------- */
/*                     cent                    */
/* ------------------------------------------- */
//yields
float N1S_aa_cent3p5[nCentBins_2014] = {48.87,164.79,169.581,282.606,424.526,637.248,409.62,406.692}; //406.692   // 439
float N1S_aa_cent3p5e[nCentBins_2014] = {8.78835,16.7766,18.335,24.5124,31.438,40.1154,33.2798,36.1903};
float N2S_aa_cent3p5[nCentBins_2014] = {3.63483,11.9237,24.6331,33.7225,-9.60813,22.7562,9.77396,60.1736};
float N2S_aa_cent3p5e[nCentBins_2014] = {5.12946,9.98449,12.0474,16.2646,20.4581,27.5692,22.6811,27.4915};
float N3S_aa_cent3p5[nCentBins_2014] = {0.467209,-8.21439,23.4819,-7.91134,-14.8149,-45.7341,9.25746,9.54258};
float N3S_aa_cent3p5e[nCentBins_2014] = {4.48587,8.10209,11.7908,14.4,19.7355,25.1138,21.7463,25.2985};
//misc.
float Sigma1SFixed_aa_cent3p5[nCentBins_2014] = {0.0627095,0.0627095,0.0627095,0.0627095,0.0627095,0.0627095,0.0627095,0.0627095};
float Sigma1SFree_aa_cent3p5[nCentBins_2014] = {0.0416768,0.0708734,0.0739884,0.0739101,0.0615255,0.0668554,0.0700363,0.0638495};
float dM1S_aa_cent3p5[nCentBins_2014] = {0.000913915,-0.0203463,-0.0127969,-0.0247916,-0.0125163,-0.00588438,-0.0247968,-0.00628748};
float MassErr1S_aa_cent3p5[nCentBins_2014] = {0.0166454,0.0107545,0.0110112,0.00889553,0.00745974,0.00620451,0.00837207,0.00886604};
float N1S_aaSignif_cent3p5[nCentBins_2014] = {5.56077,9.8226,9.24903,11.5291,13.5036,15.8854,12.3084,11.2376};
//systematics
float N1S_aa_cents_5[nfitvars] = {406.692,508.64,488.531,410.473,413.124,411.917};
float N1S_aa_cents_10[nfitvars] = {409.62,487.614,476.497,432.839,419.594,432.098};
float N1S_aa_cents_20[nfitvars] = {637.248,670.063,762.869,657.761,699.936,647.846};
float N1S_aa_cents_30[nfitvars] = {424.526,420.107,418.868,420.736,420.12,421.746};
float N1S_aa_cents_40[nfitvars] = {282.606,317.154,337.779,305.732,303.567,303.977};
float N1S_aa_cents_50[nfitvars] = {169.581,210.614,204.257,183.736,184.357,181.254};
float N1S_aa_cents_70[nfitvars] = {164.79,166.874,159.122,173.014,166.994,173.816};
float N1S_aa_cents_100[nfitvars] = {48.87,44.8103,58.0023,42.0601,42.9389,42.9267};
float N1B_aa_cents_5[nbkgdvars] = {406.074,405.844};
float N1B_aa_cents_10[nbkgdvars] = {417.388,400.412};
float N1B_aa_cents_20[nbkgdvars] = {635.134,639.905};
float N1B_aa_cents_30[nbkgdvars] = {424.679,460.487};
float N1B_aa_cents_40[nbkgdvars] = {280.429,279.573};
float N1B_aa_cents_50[nbkgdvars] = {162.288,173.644};
float N1B_aa_cents_70[nbkgdvars] = {162.067,171.241};
float N1B_aa_cents_100[nbkgdvars] = {57.0847,48.8709};
/* ------------------------------------------- */
/*                    cent4                    */
/* ------------------------------------------- */
//yields
float N1S_aa_cent4[nCentBins_2014] = {33.2888,112.052,93.5296,213.995,316.259,448.461,282.16,301.154};
float N1S_aa_cent4e[nCentBins_2014] = {7.84892,13.3818,13.4246,19.3737,24.5797,30.7238,25.1464,27.5512};
float N2S_aa_cent4[nCentBins_2014] = {3.64245,11.4297,22.9896,37.6962,28.1178,25.558,7.18424,35.3889};
float N2S_aa_cent4e[nCentBins_2014] = {5.12202,7.96805,9.9309,12.7613,15.8288,20.4766,16.1108,19.9771};
float N3S_aa_cent4[nCentBins_2014] = {-3.78399,1.56689,30.5372,-3.00961,7.39577,-21.1506,-11.8085,6.07284};
float N3S_aa_cent4e[nCentBins_2014] = {3.782,6.68384,10.5372,10.5259,14.8632,18.3509,15.2818,18.923};
//misc.
float Sigma1SFixed_aa_cent4[nCentBins_2014] = {0.0623872,0.0623872,0.0623872,0.0623872,0.0623872,0.0623872,0.0623872,0.0623872};
float Sigma1SFree_aa_cent4[nCentBins_2014] = {0.0740696,0.0663977,0.0732918,0.0779497,0.0713302,0.071721,0.0717966,0.0657269};
float dM1S_aa_cent4[nCentBins_2014] = {-0.0114651,-0.0101231,-0.0177223,-0.0156515,-0.0107832,-0.00142174,-0.0233709,-0.00635702};
float MassErr1S_aa_cent4[nCentBins_2014] = {0.0236682,0.0120659,0.0133182,0.00912898,0.00820536,0.0067153,0.00924875,0.00900262};
float N1S_aaSignif_cent4[nCentBins_2014] = {4.24119,8.37349,6.967,11.0457,12.8667,14.5966,11.2207,10.9307};
//systematics.
float N1S_aa_cent4s_5[nfitvars] = {301.154,387.26,364.763,309.165,329.552,306.358};
float N1S_aa_cent4s_10[nfitvars] = {282.16,321.074,294.176,298.301,288.027,298.261};
float N1S_aa_cent4s_20[nfitvars] = {448.461,522.784,537.108,479.676,491.314,462.504};
float N1S_aa_cent4s_30[nfitvars] = {316.259,378.944,364.731,335.675,324.373,332.393};
float N1S_aa_cent4s_40[nfitvars] = {213.995,232.581,236.588,235.664,230.973,230.899};
float N1S_aa_cent4s_50[nfitvars] = {93.5296,109.975,101.521,101.336,102.967,96.3729};
float N1S_aa_cent4s_70[nfitvars] = {112.052,117.206,111.947,114.684,114.099,115.052};
float N1S_aa_cent4s_100[nfitvars] = {33.2888,35.4785,40.2084,36.1328,32.1786,38.5779};
float N1B_aa_cent4s_5[nfitvars] = {289.327,283.477};
float N1B_aa_cent4s_10[nfitvars] = {278.802,278.048};
float N1B_aa_cent4s_20[nfitvars] = {422.644,415.772};
float N1B_aa_cent4s_30[nfitvars] = {315.275,301.474};
float N1B_aa_cent4s_40[nfitvars] = {225.704,218.397};
float N1B_aa_cent4s_50[nfitvars] = {88.3544,86.3598};
float N1B_aa_cent4s_70[nfitvars] = {112.066,112.101};
float N1B_aa_cent4s_100[nfitvars] = {32.5484,37.8724};
//yields in LARGE bins
float N1S_aa_cent4Large[nCentBins_2014] = {147.828,309.251,761.396,579.417};
float N1S_aa_cent4Largee[nCentBins_2014] = {15.4987,23.8851,39.3732,37.2924};
float N2S_aa_cent4Large[nCentBins_2014] = {14.4119,59.8303,54.8011,43.7287};
float N2S_aa_cent4Largee[nCentBins_2014] = {9.51969,16.1589,25.9163,25.6763};
float N3S_aa_cent4Large[nCentBins_2014] = {-3.96433,25.214,-11.7562,-2.86086};
float N3S_aa_cent4Largee[nCentBins_2014] = {7.70754,14.8221,23.7306,24.4938};
//misc.
float Sigma1SFixed_aa_cent4Large[nCentBins_2014] = {0.0623872,0.0623872,0.0623872,0.0623872};
float Sigma1SFree_aa_cent4Large[nCentBins_2014] = {0.0687727,0.0772424,0.0713647,0.0695623};
float dM1S_aa_cent4Large[nCentBins_2014] = {-0.010173,-0.01943,-0.00459972,-0.0137324};
float MassErr1S_aa_cent4Large[nCentBins_2014] = {0.0104926,0.00755168,0.00521728,0.0065958};
float N1S_aaSignif_cent4Large[nCentBins_2014] = {9.5381,12.9475,19.3379,15.5371};
//systematics.
float N1S_aa_cent4Larges_10[nfitvars] = {579.417,751.249,698.138,611.056,624.446,605.937};
float N1S_aa_cent4Larges_30[nfitvars] = {761.396,827.798,912.261,811.088,829.17,792.113};
float N1S_aa_cent4Larges_50[nfitvars] = {309.251,349.508,370.74,343.593,340.331,334.361};
float N1S_aa_cent4Larges_100[nfitvars] = {147.828,168.931,175.348,151.76,150.98,152.816};
float N2S_aa_cent4Larges_10[nfitvars] = {43.7287,79.4405,64.1804,46.5991,48.816,46.1545};
float N2S_aa_cent4Larges_30[nfitvars] = {54.8011,73.83,85.1074,69.5413,68.2131,64.3907};
float N2S_aa_cent4Larges_50[nfitvars] = {59.8303,72.9272,80.3426,71.3829,68.4123,69.1213};
float N2S_aa_cent4Larges_100[nfitvars] = {14.4119,22.2242,20.7699,17.1622,16.0551,17.135};
float N1B_aa_cent4Larges_10[nbkgdvars] = {565.119,566.534};
float N1B_aa_cent4Larges_30[nbkgdvars] = {701.206,742.546};
float N1B_aa_cent4Larges_50[nbkgdvars] = {288.814,319.804};
float N1B_aa_cent4Larges_100[nfitvars] = {139.219,144.616};
float N2B_aa_cent4Larges_10[nbkgdvars] = {49.1681,51.155};
float N2B_aa_cent4Larges_30[nbkgdvars] = {15.9666,30.576};
float N2B_aa_cent4Larges_50[nbkgdvars] = {42.9183,67.2421};
float N2B_aa_cent4Larges_100[nfitvars] = {11.267,10.3624};
/* ------------------------------------------- */
/* ------------------------------------------- */
/* ------------------------------------------- */
/*                  PYTHIA                     */
/* ------------------------------------------- */
/* ------------------------------------------- */
/* ------------------------------------------- */
/*            1S loose TOTAL E,A,T             */
/* ------------------------------------------- */
//CAREFUL : ERRORS FOR TAG AND PROBE ARE ONLY STAT FOR THE MOMENT
//Acc*eff
float Ae_1S_pythia_tot= 0.239;//new
float Ae_1S_pythia_tote=0.001;///stat. err.
float Ae_1S_pythia_tots=0.007;///syst.: shape vars
//eff
float e_1S_pythia_tot= 0.679;//new
float e_1S_pythia_tote=0.001;///stat. unc
float e_1S_pythia_tots=0.007;///stat. unc
//sf from tag and probe = eff_corr/eff_noCorr
float t_1S_pythia_tot3p5 = 1.095;
float t_1S_pythia_tot3p5e = 0.006;
//total
float Aet_1S_pythia_tot=0.257;// 
float Aet_1S_pythia_tote = Aet_1S_pythia_tot*sqrt(pow(t_1S_pythia_tot3p5e/t_1S_pythia_tot3p5,2)+Ae_1S_pythia_tote*Ae_1S_pythia_tote);
/* ------------------------------------------- */
/*                     1S pT                   */
/* ------------------------------------------- */
//eff., Acc., Acc*eff,
float e_1S_pythia_pt3p5[nPtBins2015]={0.659,0.648,0.686,0.716,0.757,0.77}; //last bin fake
float e_1S_pythia_pt3p5e[nPtBins2015]={0.002,0.002,0.003,0.004,0.005,0.008};//last bin fake
float A_1S_pythia_pt3p5[nPtBins2015]={0.456,0.298,0.277,0.374,0.513,0.62};
float A_1S_pythia_pt3p5e[nPtBins2015]={0.0002,0.0001,0.0001,0.002,0.005,0.01};
float Ae_1S_pythia_pt[nPtBins2015] = {0.301,0.193,0.190,0.267,0.388,0.5};//wrong
float Ae_1S_pythia_pte[nPtBins2015] = {0.001,0.001,0.001,0.002,0.004,0.008};//fake
//tnp. + uncertainty
float t_1S_pythia_pt3p5[nPtBins2015]= {1.119,   1.112,   1.087,   1.06287,  1.040,  1.02923};
float t_1S_pythia_pt3p5e[nPtBins2015]={0.01,0.01,0.009,0.009,0.009,0.00698397};
//A*e*t
float Aet_1S_pythia_pt[nPtBins_2014]={0.339,0.214,0.207,0.284,0.404,0.41};
float Aet_1S_pythia_pte[nPtBins_2014]={0.001,0.001,0.001,0.002,0.004,0.007};
float Aet_1S_pythia_pts[nPtBins_2014]={0.008,0.004,0.006,0.008,0.011,0.012};
/* ------------------------------------------- */
/*                   1S rap                    */
/* ------------------------------------------- */
float e_1S_pythia_rap3p5[nRapBins2015]={0.709,0.711,0.713,0.674,0.615,0.500};
float e_1S_pythia_rap3p5e[nRapBins2015]={0.003,0.003,0.003,0.003,0.003,0.003};
float A_1S_pythia_rap3p5[nRapBins2015]={0.393,0.392,0.393,0.389,0.338,0.145};
float A_1S_pythia_rap3p5e[nRapBins2015]={0.002,0.002,0.002,0.002,0.002,0.001};
float Ae_1S_pythia_rap2014[nRapBins2015]={0.279,0.278,0.280,0.262,0.208,0.073};
float Ae_1S_pythia_rap2014e[nRapBins2015]={0.002,0.002,0.002,0.002,0.001,0.001};
float t_1S_pythia_rap3p5[nRapBins2015]={1.076,1.077,1.083,1.104,1.142,1.163};
float t_1S_pythia_rap3p5e[nRapBins2015]={0.006, 0.006, 0.006, 0.010, 0.019,0.025};
//A*e*t
float Aet_1S_pythia_rap2014[nRapBins_2014]={0.300,0.299,0.303,0.289,0.238,0.085};
float Aet_1S_pythia_rap2014e[nRapBins_2014]={0.002,0.002,0.002,0.002,0.002,0.001};
float Aet_1S_pythia_rap2014s[nRapBins_2014]={0.003,0.003,0.002,0.003,0.003,0.002};
/* ------------------------------------------- */
/*                     1S pT4                  */
/* ------------------------------------------- */
float Ae_1S_pythia_tot4= 0.166;//new
float Ae_1S_pythia_tot4e=0.001;///shape vars
float e_1S_pythia_tot4= 0.733;//new
float e_1S_pythia_tot4e=0.002;///shape vars
float t_1S_pythia_tot4 = 1.095;
float t_1S_pythia_tot4e = 0.009;
float Aet_1S_pythia_tot4=t_1S_pythia_tot4*Ae_1S_pythia_tot;// 
float Aet_1S_pythia_tot4e = Aet_1S_pythia_tot4*sqrt(pow(t_1S_pythia_tot4e/t_1S_pythia_tot4,2)+Ae_1S_pythia_tot4e*Ae_1S_pythia_tot4e);
//dont care
//eff., Acc., Acc*eff, 
float e_1S_pythia_pt4[nPtBins2015]={0.705,0.716,0.738,0.753,0.779,0.8}; //last bin fake
float e_1S_pythia_pt4e[nPtBins2015]={0.003,0.003,0.003,0.004,0.006,0.008};//last bin fake
float A_1S_pythia_pt4[nPtBins2015]={0.267,0.158,0.187,0.294,0.457,0.6};
float A_1S_pythia_pt4e[nPtBins2015]={0.001,0.001,0.001,0.002,0.004,0.01};
float Ae_1S_pythia_pt4[nPtBins2015] = {0.189,0.113,0.138,0.221,0.356,0.48};//wrong
float Ae_1S_pythia_pt4e[nPtBins2015] = {0.001,0.001,0.001,0.002,0.004,0.01};//fake
//tnp. + uncertainty
float t_1S_pythia_pt4[nPtBins2015]= {1.125,1.112,1.087,1.063,1.040,1.03};
float t_1S_pythia_pt4e[nPtBins2015]={0.007,0.007,0.006,0.007,0.007,0.007};
//A*e*t
float Aet_1S_pythia_pt4[nPtBins_2014]={0.213,0.126,0.150,0.235,0.370};
float Aet_1S_pythia_pt4e[nPtBins_2014]={0.001,0.001,0.001,0.002,0.004};
float Aet_1S_pythia_pt4s[nPtBins_2014]={0.001,0.001,0.001,0.001,0.002};
/* ------------------------------------------- */
/*                   1S rap 4                  */
/* ------------------------------------------- */
float e_1S_pythia_rap4[nRapBins2015]={0.780,0.786,0.774,0.716,0.639,0.507};
float e_1S_pythia_rap4e[nRapBins2015]={0.004,0.004,0.004,0.004,0.004,0.005};
float A_1S_pythia_rap4[nRapBins2015]={0.250,0.250,0.250,0.247,0.223,0.102};
float A_1S_pythia_rap4e[nRapBins2015]={0.001,0.001,0.001,0.001,0.001,0.001};
float Ae_1S_pythia_rap4[nRapBins2015] ={0.195,0.197,0.193,0.177,0.142,0.052};
float Ae_1S_pythia_rap4e[nRapBins2015]={0.001,0.001,0.001,0.001,0.001,0.001};
//tnp. + uncertainty
float t_1S_pythia_rap4[nRapBins2015]= {1.076,1.077,1.083,1.104,1.142,1.163};
float t_1S_pythia_rap4e[nRapBins2015]={0.006,0.006,0.006,0.010,0.019,0.025};
//A*e*t
float Aet_1S_pythia_rap4[nRapBins_2014] ={0.210,0.212,0.209,0.195,0.192,0.060};
float Aet_1S_pythia_rap4e[nRapBins_2014]={0.001,0.001,0.001,0.001,0.001,0.001};
float Aet_1S_pythia_rap4s[nRapBins_2014]={0.001,0.001,0.001,0.001,0.002,0.001};
/* ------------------------------------------- */
/*                     2S pT                   */
/* ------------------------------------------- */
/// TOTAL
//CAREFUL : ERRORS FOR TAG AND PROBE ARE ONLY STAT FOR THE MOMENT
//Acc*eff
float Ae_2S_pythia_tot= 0.279;//new
float Ae_2S_pythia_tote=0.001;///stat. err.
float Ae_2S_pythia_tots=0.006;///syst.: shape vars
//eff
float e_2S_pythia_tot= 0.743;//new
float e_2S_pythia_tote=0.002;///stat. unc
float e_2S_pythia_tots=0.006;///stat. unc
//sf from tag and probe = eff_corr/eff_noCorr
float t_2S_pythia_tot = 1.055;
float t_2S_pythia_tote = 0.007;
//total
float Aet_2S_pythia_tot=0.218;// 
float Aet_2S_pythia_tote = Aet_2S_pythia_tot*sqrt(t_2S_pythia_tote*t_2S_pythia_tote+Ae_2S_pythia_tote*Ae_2S_pythia_tote);
//eff., Acc., Acc*eff, 
float e_2S_pythia_pt2013[nPtBins_2013]= {0.721,0.729,0.744,0.758,0.784};
float e_2S_pythia_pt2013e[nPtBins_2013]={0.002,0.003,0.004,0.005,0.007};
float A_2S_pythia_pt2013[nPtBins_2013]= {0.375,0.217,0.218,0.309,0.467};
float A_2S_pythia_pt2013e[nPtBins_2013]={0.002,0.001,0.002,0.003,0.007};
float Ae_2S_pythia_pt2013[nPtBins_2013]={0.270,0.159,0.162,0.234,0.366};
float Ae_2S_pythia_pt2013e[nPtBins_2013]={0.0010,0.006,0.0008,0.0018,0.0043};
//tnp. + uncertainty
float t_2S_pythia_pt4[nPtBins2015]={1.08342 ,1.07619 ,1.06259 ,1.04968 ,1.03585 ,1.02531};
float t_2S_pythia_pt4e[nPtBins2015]={ 0.00642526 ,0.00642385 ,0.00650645 ,0.00674736 ,0.00708275 ,0.0070219 }; 
//A*e*t
float Aet_2S_pythia_pt2013[nPtBins_2013]={0.293,0.171,0.172,0.246,0.379};
float Aet_2S_pythia_pt2013e[nPtBins_2013]={0.002,0.001,0.001,0.003,0.006};
float Aet_2S_pythia_pt2013s[nPtBins_2013]={0.007,0.004,0.005,0.008,0.010};
//a,e,t, large bins
float e_2S_pythia_pt2010[nPtBins2S]= {0.726,0.750,0.784};
float e_2S_pythia_pt2010e[nPtBins2S]={0.002,0.003,0.007};
float A_2S_pythia_pt2010[nPtBins2S]= {0.268,0.250,0.467};
float A_2S_pythia_pt2010e[nPtBins2S]={0.0002,0.0002,0.0041};
float Ae_2S_pythia_pt2010[nPtBins2S]= {0.195,0.187,0.366};
float Ae_2S_pythia_pt2010e[nPtBins2S]={0.001,0.001,0.006};
//tnp+err
float t_2S_pythia_pt2010[nPtBins2S] = {1.079,1.056,1.036};
float t_2S_pythia_pt2010e[nPtBins2S] = {0.006,0.006,0.007};
//total
float Aet_2S_pythia_pt2013Large[nPtBins2S]={0.210,0.197,0.379};
float Aet_2S_pythia_pt2013Largee[nPtBins2S]={0.001,0.001,0.006};
float Aet_2S_pythia_pt2013Larges[nPtBins2S]={0.005,0.006,0.010};
/* ------------------------------------------- */
/*                   2S rap                    */
/* ------------------------------------------- */
//eff., Acc., Acc*eff, 
float e_2S_pythia_rap2014[nRapBins_2014]= {0.791,0.795,0.781,0.726,0.643,0.519};
float e_2S_pythia_rap2014e[nRapBins_2014]={0.004,0.004,0.004,0.004,0.004,0.005};
float A_2S_pythia_rap2014[nRapBins_2014]= {0.310,0.310,0.307,0.308,0.271,0.117};
float A_2S_pythia_rap2014e[nRapBins_2014]={0.002,0.002,0.002,0.002,0.002,0.001};
float Ae_2S_pythia_rap2014[nRapBins_2014]={0.245,0.247,0.240,0.223,0.174,0.060};//bug was here.
float Ae_2S_pythia_rap2014e[nRapBins_2014]={0.002,0.002,0.002,0.002,0.002,0.001};
//tnp. + uncertainty
float t_2S_pythia_rap4[nRapBins2015]={1.03332,1.03325,1.04035,1.06862,1.11817,1.1514};
float t_2S_pythia_rap4e[nRapBins2015]={0.0035896 , 0.00362431 ,0.00452162,0.0083498 ,0.0155529  ,0.0207168};
//A*e*t
float Aet_2S_pythia_rap2014[nRapBins_2014]={0.253,0.255,0.250,0.238,0.195,0.069};
float Aet_2S_pythia_rap2014e[nRapBins_2014]={0.002,0.002,0.002,0.002,0.002,0.001};
float Aet_2S_pythia_rap2014s[nRapBins_2014]={0.004,0.004,0.003,0.004,0.003,0.002};
//a,e,t, large bins
float e_2S_pythia_rap2010[nRapBins2S]= {0.789,0.666};
float e_2S_pythia_rap2010e[nRapBins2S]={0.002,0.002};
float A_2S_pythia_rap2010[nRapBins2S]= {0.309,0.241};
float A_2S_pythia_rap2010e[nRapBins2S]={0.001,0.001};
float Ae_2S_pythia_rap2010[nRapBins2S] = {0.244,0.160};
float Ae_2S_pythia_rap2010e[nRapBins2S] = {0.001,0.001};
float t_2S_pythia_rap2010[nRapBins2S]={1.035,1.095};
float t_2S_pythia_rap2010e[nRapBins2S]={0.004,0.012};
//total
float Aet_2S_pythia_rap2014Large[nRapBins2S]={0.253,0.175};
float Aet_2S_pythia_rap2014Largee[nRapBins2S]={0.001,0.001};
float Aet_2S_pythia_rap2014Larges[nRapBins2S]={0.004,0.005};
/* ------------------------------------------- */
/*                     3S pT                   */
/* ------------------------------------------- */
/// TOTAL
//CAREFUL :  ERRORS FOR TAG AND PROBE ARE ONLY STAT FOR THE MOMENT
//Acc*eff
float Ae_3S_pythia_tot= 0.329;//new
float Ae_3S_pythia_tote=0.001;///stat. err.
float Ae_3S_pythia_tots=0.007;///syst.: shape vars
//eff
float e_3S_pythia_tot= 0.752;//new
float e_3S_pythia_tote=0.001;///stat. unc
float e_3S_pythia_tots=0.007;///stat. unc
//sf from tag and probe = eff_corr/eff_noCorr
float t_3S_pythia_tot = 1.064;
float t_3S_pythia_tote = 0.006;
//total
float Aet_3S_pythia_tot=0.263;// 
float Aet_3S_pythia_tote = Aet_3S_pythia_tot*sqrt(t_3S_pythia_tote*t_3S_pythia_tote+Ae_3S_pythia_tote*Ae_3S_pythia_tote);
//eff., Acc., Acc*eff, 
float e_3S_pythia_pt2013[nPtBins_2013]= {0.731,0.732,0.751,0.769,0.795};
float e_3S_pythia_pt2013e[nPtBins_2013]={0.002,0.002,0.003,0.003,0.004};
float A_3S_pythia_pt2013[nPtBins_2013]= {0.455,0.273,0.249,0.330,0.471};
float A_3S_pythia_pt2013e[nPtBins_2013]={0.001,0.001,0.001,0.001,0.002};
float Ae_3S_pythia_pt2013[nPtBins_2013]={0.333,0.199,0.187,0.254,0.375};
float Ae_3S_pythia_pt2013e[nPtBins_2013]={0.001,0.001,0.001,0.001,0.002};
//tnp. + uncertainty
float t_3S_pythia_pt4[nPtBins2015]={1.08342 ,1.07619 ,1.06259 ,1.04968 ,1.03585 ,1.02531};
float t_3S_pythia_pt4e[nPtBins2015]={ 0.00642526 ,0.00642385 ,0.00650645 ,0.00674736 ,0.00708275 ,0.0070219 }; 
//A*e*t
float Aet_3S_pythia_pt2013[nPtBins_2013]={0.361,0.214,0.199,0.267,0.389};
float Aet_3S_pythia_pt2013e[nPtBins_2013]={0.001,0.001,0.001,0.001,0.002};
float Aet_3S_pythia_pt2013s[nPtBins_2013]={0.009,0.005,0.005,0.008,0.011};
//a,e,t, large bins
float e_3S_pythia_pt2010[nPtBins2S]= {0.732,0.759,0.795};
float e_3S_pythia_pt2010e[nPtBins2S]={0.002,0.002,0.004};
float A_3S_pythia_pt2010[nPtBins2S]= {0.336,0.279,0.471};
float A_3S_pythia_pt2010e[nPtBins2S]={0.0004,0.0004,0.002};
float Ae_3S_pythia_pt2010[nPtBins2S]= {0.246,0.212,0.375};
float Ae_3S_pythia_pt2010e[nPtBins2S]={0.001,0.001,0.002};
//tnp+err
float t_3S_pythia_pt2010[nPtBins2S] = {1.080,1.057,1.036};
float t_3S_pythia_pt2010e[nPtBins2S] = {0.006,0.006,0.007};
//total
float Aet_3S_pythia_pt2013Large[nPtBins2S]={0.266,0.224,0.389};
float Aet_3S_pythia_pt2013Largee[nPtBins2S]={0.001,0.001,0.002};
float Aet_3S_pythia_pt2013Larges[nPtBins2S]={0.006,0.007,0.011};
/* ------------------------------------------- */
/*                   3S rap                   */
/* ------------------------------------------- */
//eff., Acc., Acc*eff, 
float e_3S_pythia_rap2014[nRapBins_2014]= {0.804,0.804,0.787,0.734,0.649,0.522};
float e_3S_pythia_rap2014e[nRapBins_2014]={0.003,0.003,0.003,0.003,0.003,0.003};
float A_3S_pythia_rap2014[nRapBins_2014]= {0.367,0.366,0.366,0.361,0.312,0.136};
float A_3S_pythia_rap2014e[nRapBins_2014]={0.001,0.001,0.001,0.001,0.001,0.001};
float Ae_3S_pythia_rap2014[nRapBins_2014]={0.295,0.294,0.288,0.265,0.203,0.071};//bug was here.
float Ae_3S_pythia_rap2014e[nRapBins_2014]={0.001,0.001,0.001,0.001,0.001,0.001};
//tnp. + uncertainty
float t_3S_pythia_rap4[nRapBins2015]={1.03332,1.03325,1.04035,1.06862,1.11817,1.1514};
float t_3S_pythia_rap4e[nRapBins2015]={0.0035896 , 0.00362431 ,0.00452162,0.0083498 ,0.0155529  ,0.0207168};
//A*e*t
float Aet_3S_pythia_rap2014[nRapBins_2014]= {0.308,0.307,0.302,0.285,0.228,0.082};
float Aet_3S_pythia_rap2014e[nRapBins_2014]={0.001,0.001,0.001,0.001,0.001,0.001};
float Aet_3S_pythia_rap2014s[nRapBins_2014]={0.003,0.003,0.003,0.003,0.003,0.002};
//a,e,t, large bins
float e_3S_pythia_rap2010[nRapBins2S]= {0.798,0.673};
float e_3S_pythia_rap2010e[nRapBins2S]={0.002,0.002};
float A_3S_pythia_rap2010[nRapBins2S]= {0.366,0.281};
float A_3S_pythia_rap2010e[nRapBins2S]={0.001,0.001};
float Ae_3S_pythia_rap2010[nRapBins2S] = {0.292,0.189};
float Ae_3S_pythia_rap2010e[nRapBins2S] ={0.001,0.001};
float t_3S_pythia_rap2010[nRapBins2S]= {1.046,1.101};
float t_3S_pythia_rap2010e[nRapBins2S]={0.004,0.012};
//total
float Aet_3S_pythia_rap2014Large[nRapBins2S]= {0.305,0.208};
float Aet_3S_pythia_rap2014Largee[nRapBins2S]={0.001,0.001};
float Aet_3S_pythia_rap2014Larges[nRapBins2S]={0.003,0.006};
/* ------------------------------------------- */
/* ------------------------------------------- */
/* ------------------------------------------- */
/*                    PYQUEN                   */
/* ------------------------------------------- */
/* ------------------------------------------- */
/* ------------------------------------------- */
/*             1S loose TOTAL E,A,T            */
/* ------------------------------------------- */
float Ae_1S_pyquen_tot=0.223;
float Ae_1S_pyquen_tote=0.005;
float e_1S_pyquen_tot=0.633;
float e_1S_pyquen_tote=0.005;
float t_1S_pyquen_tot3p5= 1.128;
float t_1S_pyquen_tot3p5e=0.065;
float Aet_1S_pyquen_tot=Ae_1S_pyquen_tot*t_1S_pyquen_tot3p5;
float Aet_1S_pyquen_tote=Aet_1S_pyquen_tot*sqrt(Ae_1S_pyquen_tote*Ae_1S_pyquen_tote+pow(t_1S_pyquen_tot3p5e/t_1S_pyquen_tot3p5,2));
float t_1S_pyquen_tot4=1.070; //bof
/* ------------------------------------------- */
/*                    1S pT                    */
/* ------------------------------------------- */
float e_1S_pyquen_pt[nPtBins2015] ={0.589,0.588,0.651,0.712,0.753,0.78};//wrong
float e_1S_pyquen_pte[nPtBins2015]={0.0055,0.0058,0.007,0.006,0.0049,0.1};
float A_1S_pyquen_pt[nPtBins2015] ={0.456,0.298,0.277,0.374,0.513,0.58};
float A_1S_pyquen_pte[nPtBins2015]={0.0009,0.0001,0.0006,0.0012,0.0027,0.03};//fake
float Ae_1S_pyquen_pt[nPtBins2015] ={0.269,0.175,0.181,0.266,0.387,0.51};
float Ae_1S_pyquen_pte[nPtBins2015]={0.0026,0.0017,0.0020,0.0023,0.0032,0.04}; // wrong
//
float t_1S_pyquen_pt3p5[nPtBins2015]= {1.172,  1.154,  1.118, 1.082, 1.048, 1.02826};
float t_1S_pyquen_pt3p5e[nPtBins2015]={0.082,0.074,0.063,0.052, 0.045, 0.0330998};
//
float Aet_1S_pyquen_pt[nPtBins_2013+1]= {0.315,0.202,0.202,0.288,0.406,0.524};//bof
float Aet_1S_pyquen_pte[nPtBins_2013+1]={0.002,0.002,0.002,0.003,0.004,0.01};
float Aet_1S_pyquen_pts[nPtBins_2013+1]={0.022,0.013,0.012,0.016,0.020,0.02};
/* ------------------------------------------- */
/*                    1S rap                   */
/* ------------------------------------------- */
float e_1S_pyquen_rap2014[nRapBins_2014]={0.611,0.639,0.674,0.656,0.611,0.521};
float e_1S_pyquen_rap2014e[nRapBins_2014]={0.005,0.006,0.005,0.005,0.0070,0.01};
float A_1S_pyquen_rap2014[nRapBins_2014]={0.393,0.392,0.393,0.389,0.338,0.145};
float A_1S_pyquen_rap2014e[nRapBins_2014]={0.002,0.002,0.002,0.002,0.002,0.001};
float Ae_1S_pyquen_rap2014[nRapBins_2014]={0.240,0.250,0.265,0.255,0.206,0.076};
float Ae_1S_pyquen_rap2014e[nRapBins_2014]={0.0025,0.0026,0.0028,0.0029,0.0027,0.0018};//,0.003386};

float t_1S_pyquen_rap3p5[nRapBins2015]={1.120 , 1.120 , 1.124, 1.132 , 1.149 , 1.150 };
float t_1S_pyquen_rap3p5e[nRapBins2015]={0.011549,0.011864,0.020660,0.059434,0.124098,0.171624};

float Aet_1S_pyquen_rap2014[nRapBins_2014]={0.269,0.280,0.298,0.289,0.237,0.087};
float Aet_1S_pyquen_rap2014e[nRapBins_2014]={0.002,0.002,0.003,0.003,0.003,0.002};
float Aet_1S_pyquen_rap2014s[nRapBins_2014]={0.012,0.012,0.014,0.019,0.023,0.011};
/* ------------------------------------------- */
/*                    1S cent                  */
/* ------------------------------------------- */
float e_1S_pyquen_cent2014[nCentBins_2014]={0.656,0.657,0.651,0.648,0.646,0.636,0.626,0.606};
float e_1S_pyquen_cent2014e[nCentBins_2014]={0.0043,0.0046,0.0061,0.0060,0.0060,0.0058,0.0082,0.0070};
float A_1S_pyquen_cent2014[nCentBins_2014]={0.353,0.353,0.353,0.353,0.353,0.353,0.353,0.33};
float A_1S_pyquen_cent2014e[nCentBins_2014]={0.0043,0.0046,0.0061,0.0060,0.0060,0.0058,0.0082,0.0070};
float Ae_1S_pyquen_cent2014[nCentBins_2014]={0.231,0.232,0.230,0.229,0.228,0.224,0.221,0.214};
//starting with peripheral bin!//
float Ae_1S_pyquen_cent2014e[nCentBins_2014]={0.0015,0.0016,0.0021,0.0021,0.0021,0.020,0.0029,0.0024}; // starting with the peripheral value!!!
float t_1S_pyquen_cent3p5[nCentBins_2014]={1.12765,1.12702,1.12665,1.12712, 1.12616,1.12724,1.12681,1.12632}; //,1.12672
float t_1S_pyquen_cent3p5e[nCentBins_2014]={0.064 ,0.065   ,0.065 ,0.066 ,0.066  ,0.066 ,0.066 ,0.066 };

float Aet_1S_pyquen_cent2014[nCentBins_2014]={0.261,0.262,0.259,0.258,0.257,0.253,0.249,0.241};
float Aet_1S_pyquen_cent2014e[nCentBins_2014]={0.002,0.002,0.002,0.002,0.002,0.002,0.003,0.002};
float Aet_1S_pyquen_cent2014s[nCentBins_2014]={0.011,0.011,0.011,0.011,0.011,0.011,0.011,0.010};
/* ------------------------------------------- */
/*                    1S pT4                   */
/* ------------------------------------------- */
/* ---------------needs update...------------- */
/* ------------------------------------------- */
float e_1S_pyquen_pt[nPtBins2015] ={0.638,0.649,0.693,0.729,0.758,0.8};//wrong
float e_1S_pyquen_pte[nPtBins2015]={0.008,0.009,0.009,0.007,0.005,0.1};
float A_1S_pyquen_pt[nPtBins2015] ={0.270,0.158,0.186,0.292,0.453,0.6};
float A_1S_pyquen_pte[nPtBins2015]={0.0009,0.0001,0.0006,0.0012,0.0027,0.03};//fake
float Ae_1S_pyquen_pt[nPtBins2015] ={0.173,0.103,0.129,0.213,0.343,0.48};
float Ae_1S_pyquen_pte[nPtBins2015]={0.002,0.001,0.002,0.003,0.004,0.04}; // wrong
//
float t_1S_pyquen_pt4[nPtBins_2013]={1.093,1.079,1.061,1.045,1.032};
float t_1S_pyquen_pt4e[nPtBins_2013]={0.012,0.013,0.014,0.010,0.008};
//
float Aet_1S_pyquen_pt4[nPtBins_2013]={0.189,0.111,0.136,0.223,0.354};
float Aet_1S_pyquen_pt4e[nPtBins_2013]={0.004,0.002,0.003,0.004,0.005};
float Aet_1S_pyquen_pt4s[nPtBins_2013]={0.004,0.002,0.003,0.004,0.005};
/* ------------------------------------------- */
/*                   1S rap 4                  */
/* ------------------------------------------- */
/* ---------------needs update...------------- */
/* ------------------------------------------- */
float e_1S_pyquen_rap4[nRapBins2015] ={0.668,0.705,0.722,0.692,0.613,0.501};
float e_1S_pyquen_rap4e[nRapBins2015]={0.009,0.090,0.010,0.010,0.010,0.015};
float A_1S_pyquen_rap4[nRapBins2015] ={0.241,0.241,0.241,0.239,0.218,0.102};
float A_1S_pyquen_rap4e[nRapBins2015]={0.001,0.001,0.001,0.001,0.001,0.001};
float Ae_1S_pyquen_rap4[nRapBins2015] ={0.161,0.170,0.174,0.165,0.134,0.051};
float Ae_1S_pyquen_rap4e[nRapBins2015]={0.002,0.002,0.002,0.003,0.002,0.002};
//
float t_1S_pyquen_rap4[nRapBins_2014]={1.048,1.048,1.053,1.079,1.130,1.157};
float t_1S_pyquen_rap4e[nRapBins_2014]={0.013,0.013,0.013,0.014,0.018,0.033};
float Aet_1S_pyquen_rap42014[nRapBins_2014]={0.168,0.178,0.183,0.178,0.151,0.059};
float Aet_1S_pyquen_rap42014e[nRapBins_2014]={0.003,0.004,0.004,0.004,0.004,0.003};
float Aet_1S_pyquen_rap42014s[nRapBins_2014]={0.003,0.004,0.004,0.004,0.004,0.003};
/* ------------------------------------------- */
/*                   1S cent 4                 */
/* ------------------------------------------- */
float e_1S_pyquen_cent4[nCentBins_2014] ={0.705,0.708,0.698,0.698,0.693,0.691,0.666,0.648};
float e_1S_pyquen_cent4e[nCentBins_2014]={0.006,0.006,0.008,0.008,0.008,0.008,0.011,0.010};
float A_1S_pyquen_cent4[nCentBins_2014] ={0.220,0.220,0.220,0.220,0.220,0.220,0.220,0.220};
float A_1S_pyquen_cent4e[nCentBins_2014]={0.001,0.001,0.001,0.001,0.001,0.001,0.001,0.001};
float Ae_1S_pyquen_ra4p[nCentBins_2014] ={0.155,0.155,0.153,0.153,0.152,0.149,0.146,0.142};
float Ae_1S_pyquen_cent4e[nCentBins_2014]={0.001,0.001,0.002,0.002,0.002,0.002,0.002,0.002};
//
float t_1S_pyquen_cent4[nCentBins_2014]= {1.073,1.071,1.070,1.070,1.070,1.070,1.070,1.069};
float t_1S_pyquen_cent4e[nCentBins_2014]={0.001,0.001,0.002,0.002,0.002,0.002,0.002,0.002};
float Aet_1S_pyquen_cent42014[nCentBins_2014]= {0.166,0.166,0.164,0.164,0.163,0.160,0.157,0.152};
float Aet_1S_pyquen_cent42014e[nCentBins_2014]={0.002,0.002,0.003,0.003,0.003,0.004,0.004,0.003};
float Aet_1S_pyquen_cent42014s[nCentBins_2014]={0.002,0.002,0.003,0.003,0.003,0.004,0.004,0.003};
/* ------------------------------------------- */
/*                    2S pT                    */
/* ------------------------------------------- */
/* ------------------------------------------- */
/*             2S tight TOTAL E,A,T            */
/* ------------------------------------------- */
float Ae_2S_pyquen_tot=0.202;
float Ae_2S_pyquen_tote=0.001;
float e_2S_pyquen_tot=0.722;
float e_2S_pyquen_tote=0.003;
float t_2S_pyquen_tot4= 1.092;
float t_2S_pyquen_tot4e=0.041;
float Aet_2S_pyquen_tot=Ae_2S_pyquen_tot*t_2S_pyquen_tot4;
float Aet_2S_pyquen_tote=Aet_2S_pyquen_tot*sqrt(Ae_2S_pyquen_tote*Ae_2S_pyquen_tote+t_2S_pyquen_tot4e*t_2S_pyquen_tot4e);
//float t_2S_pyquen_tot4=1.070; //bof

float e_2S_pyquen_pt2010[nPtBins2S]=   {0.692,0.741,0.789};
float e_2S_pyquen_pt2010e[nPtBins2S]=  {0.005,0.005,0.004};
float A_2S_pyquen_pt2010[nPtBins2S]=   {0.268,0.250,0.467};
float A_2S_pyquen_pt2010e[nPtBins2S]=  {0.001,0.001,0.007};
float Ae_2S_pyquen_pt2010[nPtBins2S]=  {0.186,0.185,0.368};
float Ae_2S_pyquen_pt2010e[nPtBins2S]= {0.001,0.002,0.006};

float t_2S_pyquen_pt2010[nPtBins2S]=   {1.092,1.092,1.092};
float t_2S_pyquen_pt2010e[nPtBins2S]=  {0.043,0.044,0.042};

float Aet_2S_pyquen_pt2013Large[nPtBins2S]= {0.203,0.202,0.402};
float Aet_2S_pyquen_pt2013Largee[nPtBins2S]={0.001,0.002,0.007};
float Aet_2S_pyquen_pt2013Larges[nPtBins2S]={0.009,0.010,0.019};
/* ------------------------------------------- */
/*                    2S rap                   */
/* ------------------------------------------- */
float e_2S_pyquen_rap2010[nRapBins2S]= {0.747,0.681};
float e_2S_pyquen_rap2010e[nRapBins2S]={0.004,0.005};
float A_2S_pyquen_rap2010[nRapBins2S]= {0.309,0.241};
float A_2S_pyquen_rap2010e[nRapBins2S]={0.001,0.001};
float Ae_2S_pyquen_rap2010[nRapBins2S]=  {0.231,0.164};
float Ae_2S_pyquen_rap2010e[nRapBins2S]= {0.002,0.001};

float t_2S_pyquen_rap2010[nRapBins2S]= {1.082,1.108};
float t_2S_pyquen_rap2010e[nRapBins2S]={0.014,0.089};

float Aet_2S_pyquen_rap2014Large[nRapBins2S]= {0.250,0.182};
float Aet_2S_pyquen_rap2014Largee[nRapBins2S]={0.002,0.001};
float Aet_2S_pyquen_rap2014Larges[nRapBins2S]={0.005,0.016};
/* ------------------------------------------- */
/*                    2S cent                  */
/* ------------------------------------------- */
float e_2S_pyquen_cent2014[nCentBins2S]  ={0.742,0.734,0.724,0.698};
float e_2S_pyquen_cent2014e[nCentBins2S] ={0.004,0.005,0.005,0.008};
float A_2S_pyquen_cent2014[nCentBins2S]  ={0.279,0.279,0.279,0.279};
float A_2S_pyquen_cent2014e[nCentBins2S] ={0.001,0.001,0.001,0.001};
float Ae_2S_pyquen_cent2014[nCentBins2S] ={0.207,0.205,0.202,0.195};
float Ae_2S_pyquen_cent2014e[nCentBins2S]={0.001,0.002,0.002,0.002};
float t_2S_pyquen_cent4[nCentBins2S]={1.09128,1.09186, 1.09144, 1.09124};
float t_2S_pyquen_cent4e[nCentBins2S]= { 0.0395394, 0.0395981, 0.0389999, 0.0381379};

float Aet_2S_pyquen_cent2014[nCentBins2S]= {0.226,0.224,0.220,0.213};
float Aet_2S_pyquen_cent2014e[nCentBins2S]={0.001,0.002,0.002,0.002};
float Aet_2S_pyquen_cent2014s[nCentBins2S]={0.010,0.010,0.010,0.010};


////////OTHER STUFF/////////////
////////OTHER STUFF/////////////
////////OTHER STUFF/////////////
////////OTHER STUFF/////////////
////////OTHER STUFF/////////////
///for FUN
float Aet_3S_pyquen_tot=Aet_3S_pythia_tot*Ae_2S_pyquen_tot/Ae_2S_pythia_tot;
float Aet_3S_pyquen_tote=0.02;


float Aet_1S_pyquen_y120[nRapBins2S]= {0.259,0.249}; 
float Aet_1S_pyquen_y120e[nRapBins2S]={0.002,0.003};
float Aet_1S_pyquen_y240[nRapBins2S] ={0.211,0.196};
float Aet_1S_pyquen_y240e[nRapBins2S]={0.003,0.003};
float Aet_1S_pyquen_pt5[nRapBins2S]=   {0.236,0.224};
float Aet_1S_pyquen_pt5e[nRapBins2S]=  {0.002,0.003};
float Aet_1S_pyquen_pt12[nRapBins2S]=  {0.217,0.207};
float Aet_1S_pyquen_pt12e[nRapBins2S]= {0.004,0.004};
float Aet_1S_pyquen_pt20[nRapBins2S]=  {0.395,0.379};
float Aet_1S_pyquen_pt20e[nRapBins2S]= {0.004,0.005};
///BELOW: NOT THE SAME PT BINS....can't be used.
float Ae_1S_pyquen_DD020[nRapBins2S]={0.266,0.305};
float Ae_1S_pyquen_DD20100[nRapBins2S]={0.278,0.328};
float Ae_1S_pyquen_DD020e[nRapBins2S]={0.002,0.0032};
float Ae_1S_pyquen_DD20100e[nRapBins2S]={0.0017,0.0027};
float Aet_1S_pyquen_DDR020[nRapBins2S]={0.249,0.196};
float Aet_1S_pyquen_DDR020e[nRapBins2S]={0.003,0.003};
float Aet_1S_pyquen_DDR20100[nRapBins2S]={0.259,0.211};
float Aet_1S_pyquen_DDR20100e[nRapBins2S]={0.003,0.003};
float Aet_1S_pyquen_DDP020[nPtBins2S]={0.215,0.218,0.341};
float Aet_1S_pyquen_DDP020e[nPtBins2S]={0.003,0.004,0.005};
float Aet_1S_pyquen_DDP20100[nPtBins2S]={0.227,0.228,0.356};
float Aet_1S_pyquen_DDP20100e[nPtBins2S]={0.002,0.004,0.004};
float e_1S_pyquen_DD020[nRapBins2S]={0.596,0.577};
float e_1S_pyquen_DD20100[nRapBins2S]={0.621,0.622};
float e_1S_pyquen_DD020e[nRapBins2S]={0.0051,0.0066};
float e_1S_pyquen_DD20100e[nRapBins2S]={0.0043,0.0057};
float A_1S_pyquen_DD020[nRapBins2S]={0.447,0.530};
float A_1S_pyquen_DD20100[nRapBins2S]={0.449,0.528};
float A_1S_pyquen_DD020e[nRapBins2S]={0.0024,0.0039};
float A_1S_pyquen_DD20100e[nRapBins2S]={0.0020,0.0032};
float t_1S_pyquen_DDR020[nRapBins2S]= {1.067,1.122};
float t_1S_pyquen_DDR20100[nRapBins2S]= {1.067,1.122};
float t_1S_pyquen_DDP020[nPtBins2S]=   {1.099,1.066,1.043};
float t_1S_pyquen_DDP20100[nPtBins2S]=   {1.1,1.066,1.043};


float Aet_1S_pyquen_ptLarge[nPtBins2S]={0.228,0.210,384};   //pyquen, cent. integrated
float Aet_1S_pyquen_ptLargee[nPtBins2S]={0.002,0.003,0.005};
float Aet_1S_pyquen_rapLarge[nRapBins2S]={0.252,0.201};
float Aet_1S_pyquen_rapLargee[nRapBins2S]={0.002,0.003};

float Aet_1S_pythia_ptLarge[nPtBins2S]={0.257,0.222,0.390};
float Aet_1S_pythia_ptLargee[nPtBins2S]={0.001,0.01,0.005};
float Aet_1S_pythia_rapLarge[nRapBins2S]={0.289,0.207};
float Aet_1S_pythia_rapLargee[nRapBins2S]={0.001,0.001};


//raa 2011-011
float RAA_1S_2011sg=0.137/1.005;
float RAA_1S_2011[7]={1.005,0.590,0.681,0.614,0.484,0.432,0.411};
float RAA_1S_2011e[7]={0.121,0.096,0.069,0.053,0.040,0.048,0.043};
float RAA_1S_2011s[7]={0.176,0.080,0.093,0.084,0.066,0.059,0.056};
float RAA_2S_2011sg=0.064/0.300;
float RAA_2S_2011[7]={0.3,0.251,0.237,0.260,0.068,0.044,0.111};
float RAA_2S_2011e[7]={0.157,0.138,0.098,0.079,0.053,0.060,0.061};
float RAA_2S_2011s[7]={0.176,0.138,0.098,0.079,0.053,0.060,0.061};
