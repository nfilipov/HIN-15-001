
#define nData  9
 char* choseSampleLegend[nData] = {"",
					"pp #sqrt{s} = 7 TeV",
					"pp #sqrt{s} = 7 TeV",
					"PbPb #sqrt{s_{NN}} = 2.76 TeV (pp reco TT)",
					"PbPb #sqrt{s_{NN}} = 2.76 TeV (pp reco GG)",
					"PbPb #sqrt{s_{NN}} = 2.76 TeV (HI reco GG)",
					"PbPb #sqrt{s_{NN}} = 2.76 TeV (Regit)", //was #3 is now #6
					"pp #sqrt{s} = 2.76 TeV", ////	"", pPb #sqrt{s_{NN}} = 5.02 TeV
					"Pythia+EvtGen+PHOTOS"}; //CMS simulation, pp #sqrt{s} = 2.76 TeV

 char* choseSampleLumi[nData] = {"",
				      "L_{int} = 621 pb^{-1}",
				      "L_{int} = 966 pb^{-1}",
				      "L_{int} = xxx #mub^{-1}",
				      "L{int} = xxx #mub^{-1}",
				      "L_{int} = 150 #mub^{-1}",
				      "L_{int} = 166 #mub^{-1}",
				      "L_{int} = 5.41 pb^{-1} ",  ///////L_{int} = 18.4 pb^{-1}
				      ""};


// for pbpb!
float turnOn_minPt[10]={0,0,6,1.4,3,0,0,1.5,0,0};
float width_minPt[10]= {0.2,1.,0.7,3.2,7,2.51,0.6,0.,1,0.8};
float decay_minPt[10]= {0,0,3,6,0,0,0,0,0,0};
float turnOn_maxPt[10]={8.6,7.5,9,2.8,9,9,9,8.9,8.6,8.6};
float width_maxPt[10]= {3.,9.,4,7.2,18,9,15,6,10,7.};
float decay_maxPt[10]= {8.,8.,8,9.,25,10,10,14,10,10.};
/* //pt4 */
/* float turnOn_minPt[10]={0,0,0,1.4,3,0,0,1.5,0,0}; */
/* float width_minPt[10]= {0.2,0.2,0.7,3.2,7,2.51,0.6,0.,5,0.8}; */
/* float decay_minPt[10]= {0,0,0,6,0,0,0,0,0,0}; */
/* float turnOn_maxPt[10]={9.2,9,9,2.8,9,9,9,8.9,5,8.6}; */
/* float width_maxPt[10]= {3.,9.3,9,7.2,18,9,15,6,50,7.}; */
/* float decay_maxPt[10]= {8.,12.5,8,9.,25,10,10,14,35,10.}; */

float turnOn_minRap[9]={0,0,0,0,0,0,0,1.5,0.5};
float width_minRap[9]= {0.2,0.2,0.2,0.8,0.8,0.5,0.6,1.2,0.4};
float decay_minRap[9]= {0,0,0,0.5,0.5,0.5,0,0,0};
float turnOn_maxRap[9]={8.6,8.5,8.8,8.8,8.8,8.8,8.8,8.8,8.8};
float width_maxRap[9]= {3.,9.,9,9,4,9,15,6,20};
float decay_maxRap[9]= {13.,10.,10,8,8,10,13,14,8};


float turnOn_minCent[13]={0,0,0,0,0,0,0,1.5,0.5,0,0,0,0};
float width_minCent[13]= {0.2,0.2,1,1,1,1.5,0.6,0.8,0.,0.8,0.8,0.8,0.8};
float decay_minCent[13]= {0,0,0,0,0,0,0,0,0,0,0,0,0};
float turnOn_maxCent[13]={8,8.5,8.5,8.5,8.5,8.5,9,8,8.6,8.6,8.6,8.6,8.6};
float width_maxCent[13]= {8.,9.,9,9,9,9,15,6,6,8.,6.,7,8};
float decay_maxCent[13]= {12.,8.,8,8,8,10,10,14,25,10.,8.,8,8};

float npow_min[13]={1,1,3,1.01,1.01,1.01,1,3.02,1,1,1,1,1};
float alpha_min[13]= {0.05,0.2,0.15,0.15,0.79,0.15,0.15,0.2,0.2,0.2,0.2,0.2,0.15};
float sigma_min[13]= {0.02,0.02,0.02,0.02,0.02,0.02,0.02,0.02,0.02,0.02,0.02,0.02,0.02};


float npow_max[13]={55,55,55,12,12,6,55,55,55,55,55,55,55};
float alpha_max[13]= {10.,10.,10,10,10,10,5,20,7,10,10,10,10};
float sigma_max[13]= {0.3,0.3,0.3,0.3,0.3,0.3,0.3,0.3,0.3,0.3,0.3,0.3,0.3};
 
   
