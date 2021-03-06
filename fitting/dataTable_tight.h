#define ptBinsDone 10
#define rapBinsDone 9

double ptBinEdgeMin[ptBinsDone]={0,2.5,5,8,12,20,0,6.5,10,0};
double ptBinsEdgeMax[ptBinsDone]={2.5,5,8,12,20,50,6.5,10,20,50};

double rapBinEdgeMin[rapBinsDone]={0,0.4,0.8,1.2,1.6,2.0,0.,1.2,0.};
double rapBinsEdgeMax[rapBinsDone]={0.4,0.8,1.2,1.6,2.0,2.4,1.2,2.4,2.4};

/* double alpha_data_cent[14] = {1.56,1.56,1.56,1.56,1.56,1.56,1.56,1.56,1.56,1.56,1.56,1.56,1.56,1.56}; */
/* double npow_data_cent[14]={4.65,4.65,4.65,4.65,4.65,4.65,4.65,4.65,4.65,4.65,4.65,4.65,4.65,4.65}; */
/* double sigma1_data_cent[14]={0.065,0.065,0.065,0.065,0.065,0.065,0.065,0.065,0.065,0.065,0.065,0.065,0.065,0.065}; */
/* double scale_data_cent[14]={1.84,1.84,1.84,1.84,1.84,1.84,1.84,1.84,1.84,1.84,1.84,1.84,1.84,1.84}; */
/* double pdFrac_data_cent[14]={0.582,0.582,0.582,0.582,0.582,0.582,0.582,0.582,0.582,0.582,0.582,0.582,0.582,0.582}; */


// signal parameters from MC

//pt bins
/* double alpha_ptBins[ptBinsDone]={1.32,1.31,1.19,1.41,1.16,1.23,1.28,1.25,1.60,1.65};  */
/* double sigma1_ptBins[ptBinsDone]={0.065,0.065,0.069,0.067,0.068,0.066,0.066,0.066,0.070,0.067}; */
/* double scale_ptBins[ptBinsDone]={1.76,1.79,1.74,1.66,1.82,1.85,1.83,1.86,1.58,1.85}; */
/* double npow_ptBins[ptBinsDone]={11.87,17.39,28.63,21.35,40.29,26.90,28.31,25.04,3.09,2.45}; */
/* double pdFrac_ptBins[ptBinsDone]={0.55,0.56,0.65,0.54,0.66,0.56,0.62,0.63,0.57,0.60}; */

/* for tight muons ---- */
double npow_ptBins[ptBinsDone] = {7.99742,8.21716,33.4837,6.08413,3.25248,3.09764,6.12404,2.71926,3.87982};
double alpha_ptBins[ptBinsDone]={1.49136,1.38054,1.24598,1.292,1.37332,1.62119,1.40955,1.65807,1.54629};
double  sigma1_ptBins[ptBinsDone]={0.0662822,0.0658946,0.0675937,0.0648447,0.0544457,0.0666369,0.0658452,0.0684712,0.0660578};
double  scale_ptBins[ptBinsDone]={1.80818,1.78552,1.84594,1.78349,1.79412,1.8322,1.81121,1.84833,1.87149};
double  pdFrac_ptBins[ptBinsDone]={0.59622,0.587062,0.638873,0.58302,0.284746,0.526318,0.596058,0.640236,0.611476};

/* //rap bins */
/* double alpha_rapBins[rapBinsDone]={1.33,1.89,1.63,1.72,1.93,1.40,1.32,1.66,1.65};   */
/* double sigma1_rapBins[rapBinsDone]={0.044,0.069,0.0769,0.087,0.127,0.144,0.055,0.102,0.067}; */
/* double scale_rapBins[rapBinsDone]={1.472,2.16,1.41,1.49,2.03,1.22,1.66,1.51,1.85}; */
/* double npow_rapBins[rapBinsDone]={7.43,1.44,3.048,8.799,2.51,36.89,13.44,11.87,2.45}; */
/* double pdFrac_rapBins[rapBinsDone]={0.44,0.96,0.56,0.51,0.99,0.69,0.58,0.65,0.60}; */
//for tight muons ----
double npow_rapBins[rapBinsDone] = {3.91714,1.14248,13.717,2.5633,2.31458,26.8843,4.33494,24.7037,3.87982};
double alpha_rapBins[rapBinsDone]={1.45357,2.04277,1.29262,1.71256,1.86699,1.49638,1.54253,1.5762,1.54629};
double  sigma1_rapBins[rapBinsDone]={0.0485193,0.0617833,0.0802824,0.09259,0.127959,0.143151,0.0543828,0.0966265,0.0660578};
double  scale_rapBins[rapBinsDone]={1.59983,1.50193,1.66172,1.26853,1,1.28486,1.66269,1.48906,1.87149};
double  pdFrac_rapBins[rapBinsDone]={0.742197,0.694313,0.842165,0.457664,0.11248,0.696893,0.517559,0.513243,0.611476};

/* double alpha_MB3p5=1.65; */
/* double npow_MB3p5=2.45; */
/* double sigma1_MB3p5=0.067; */
/* double scale_MB3p5=1.85; */
/* double pdFrac_MB3p5=0.60; */

/* double alpha_MB4=1.55; */
/* double npow_MB4=4.65; */
/* double sigma1_MB4=0.065; */
/* double scale_MB4=1.83; */
/* double pdFrac_MB4=0.58; */

/* Bin & n$_{CB}$ & $\alpha_{CB}$ & $\sigma_{1}$(MeV) & $x$ (scale) & $f$ (norm) \\   */
/*       \hline                                                                                                    */
/*       11.8655  & 1.32273  & 0.0651892  & 1.76617  & 0.552857 \\  */
/*       17.3908  & 1.31288  & 0.0654127  & 1.79801  & 0.56282 \\  */
/*       28.6303  & 1.19791  & 0.0691783  & 1.74751  & 0.655152 \\  */
/*       21.3489  & 1.4183   & 0.0675906  & 1.66454  & 0.541865 \\  */
/*       40.2866  & 1.16514  & 0.0679808  & 1.82434  & 0.661521 \\  */

/*       26.9085  & 1.23173  & 0.0663134  & 1.85312  & 0.561308 \\   */

/*       28.3087  & 1.28079  & 0.0662253  & 1.8338  & 0.619117\\ */
/*       25.0396  & 1.25749  & 0.0664975  & 1.86022  & 0.637619 \\  */
/*       3.09223  & 1.60523  & 0.0706083  & 1.58852  & 0.57504 \\  */

/* pt3p5 2.4522   & 1.65063  & 0.0670203  & 1.8546  & 0.603875 \\  */
/* -------------------------------------------------------------------- */
/*       7.43317  & 1.33941  & 0.044515   & 1.47231  & 0.448933 \\  */
/*       1.44959  & 1.89549  & 0.0694212  & 2.16025  & 0.964385 \\  */
/*       3.04847  & 1.6317   & 0.0769274  & 1.41065  & 0.559068 \\  */
/*       8.79913  & 1.72586  & 0.0871425  & 1.49667  & 0.512059 \\  */
/*       2.51221  & 1.93032  & 0.127293   & 2.03325  & 0.991352 \\ */
/*       36.8961  & 1.4088   & 0.144839   & 1.22359  & 0.69829 \\  */
  
/*       13.4437  & 1.3236   & 0.0556029  & 1.66244  & 0.57749 \\  */
/*       11.8737  & 1.66783  & 0.102053   & 1.51504  & 0.647893 \\  */

/*  pt4  4.65145  & 1.55936  & 0.0655685  & 1.83726  & 0.582259 \\  */
      
		   //pt mass dep
double massPtFits[5]={9.45567,9.45811,9.45549,9.45426,9.45679};//first bins
double massPtFitse[5]={0.0006,0.0006,0.00060,0.00045,0.00038};//error
double massRapFits[6]={9.45896,9.4578,9.45442,9.4480,9.44186,9.4386};//first bins
double massRapFitse[6]={0.00025,0.00030,0.00041,0.00052,0.00073,0.0019};//error
//errors on MC pars, vs pt
double sigma1_ptBinse[5]={0.0013,0.0014,0.0013,0.00098,0.00086};
double alpha_ptBinse[5]={0.056,0.060,0.074,0.050,0.048};
double scale_ptBinse[5]={0.03,0.0014,0.0013,0.024,0.021};
double pdFrac_ptBinse[5]={0.027,0.028,0.027,0.022,0.019};
double npow_ptBinse[5]={2.2,1.6,0.76,0.37,0.33};
//errors on MC pars, vs rap
double sigma1_rapBinse[6]={0.00053,0.00072,0.0015,0.0022,0.005,0.015};
double alpha_rapBinse[6]={0.035,0.041,0.050,0.068,0.14,0.37};
double scale_rapBinse[6]={0.046,0.051,0.052,0.096,0.10,0.079};
double pdFrac_rapBinse[6]={0.018,0.024,0.050,0.061,0.14,0.23};
double npow_rapBinse[6]={0.075,0.11,0.26,0.58,1.1,3.};//wow
  /* //pt bins */
  /* double sigma1_ptBins[ptBinsDone]={}; */
  /* douu
  /* double npow_ptBins[ptBinsDone]={}; */
  /* double alpha_ptBins[ptBinsDone]={}; */
  /* double pdFrac_ptBins[ptBinsDone]={}; */
  /* //rap bins */
  /* double sigma1_rapBins[rapBinsDone]={}; */
  /* double scale_rapBins[rapBinsDone]={}; */
  /* double npow_rapBins[rapBinsDone]={}; */
  /* double alpha_rapBins[rapBinsDone]={}; */
  /* double pdFrac_ptBins[rapBinsDone]={}; */

