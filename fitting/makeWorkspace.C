
void makeWorkspace(RooWorkspace& ws, int ChooseSample,float muonEtaMin, float muonEtaMax, float muonPtMin, float muonPtMax, float upsRapMin, float upsRapMax, float upsPtMin,float upsPtMax, int upsCentralityStart, int upsCentralityEnd){
  double mass_l =  7.0;
  double mass_h = 14.0;
 
  cout<< "You're in makeWorkspace!" << endl;
  std::string finput;
  switch (ChooseSample) 
    {
    case 1: // pp @ 7TeV - dimuon0-v1
      finput   = "../dimuonTree_upsiMiniTree_pp7tev_dimu0v1_Runa_trigBit1_allTriggers0_pt4.root";
      mass_l = 8.5;
      mass_h = 11.5;
      binw=0.05;
      break;
    case 2://pp @ 7TeV - non dimuon0-v1 (GG)
      finput   = "../dimuonTree_upsiMiniTree_pp7tev_glbglb_Runa_trigBit1_allTriggers0_pt4.root";
      mass_l = 8.5;
      mass_h = 11.5;
      binw=0.05;
      break;
    case 3://PbPb @ 2.76TeV pp reco trk-trk
      // finput   = "../dimuonTree_upsiMiniTree_aa276tev_50100ppreco__Runa_trigBit1_allTriggers0_pt4.root";
      // break;
      finput   = "../dimuonTree_upsiMiniTree_aa276tevC50100_ppofficial_trktrk_ptmu4_Runa_trigBit1_allTriggers0.root";
      break;
    case 4://PbPb @ 2.76TeV pp reco glbglb
      finput   = "../dimuonTree_upsiMiniTree_aa276tev_50100ppreco_glbglb_Runa_trigBit1_allTriggers0_pt4.root";
      break;
    case 5://PbPb @ 2.76TeV Zhen's tree glbglb
      //finput   = "../dimuonTree_upsiMiniTree_AA276tevC0100_regit_ptmu4_Run210498-211631_trigBit1_allTriggers0.root";
      finput   = "../dimuonTree_HI2011_fulldataset_trkRot.root";
      break;
    case 6://PbPb @ 2.76TeV regit
      gROOT->LoadMacro("bkgTable_PbPb.h");
      // finput   = "../dimuonTree_upsiMiniTree_aa276tev_regitreco_glbglb_Runa_trigBit1_allTriggers0_pt4.root"; // cent 0-40 "cm" but doesnt have all the muons!
      // finput = "../dimuonTree_upsiMiniTree_AA2p76tev_ptmu3_july09_Run2011-2011_trigBit1_allTriggers0.root";// cent0-40 "td"
      // finput = "../dimuonTree_upsiMiniTree_AA276tevC0100_regit_ptmu4_Run210498-211631_trigBit1_allTriggers0.root"; // cent0-40 "nf"
      finput = "../dimuonTree_upsiMiniTree_AA2p76tev_ptmuSpecial_nov25_2013_trigBit1_allTriggers1_testNoCut.root"; // no cuts , so it has all the muons.
      // finput = "../dimuonTree_upsiMiniTree_AA2p76tev_WithIDCuts_RunHIN-15-001_trigBit1_allTriggers0.root";//bold as can be : my tree!
      break;
    case 7://pp @ 2.76TeV
      gROOT->LoadMacro("bkgTable_pp.h");
      // finput   = "../dimuonTree_upsiMiniTree_pp276tev_5p41_Run211739-211831_trigBit1_allTriggers0_pt4.root"; //trk muons!
      //      finput   = "../dimuonTree_upsiMiniTree_pp276tev_5p41_ptmu2_Run211739-211831_GlbGlb_trigBit1_allTriggers0.root"; // Glb muons, all above 2!
      ///finput = "../upsiMiniTree_ppData_QQtrigbit1_Trig_analysisOK_noSingleMu.root"; // new tree (2014, I did it...and there are nore events !?)
     
  	//finput   = "../dimuonTree_upsiMiniTree_pp276tev_5p41_ptmu2_Run211739-211831_GlbGlb_trigBit1_allTriggers0.root";} // Glb muons, all above 2 GeV, HLT_PAL1DoubleMuOpen
  	//finput = "../dimuonTree_upsiMiniTree_pp276tev_5p41_ptmu3_Run211739-211831_trigBit2_allTriggers0_testNoCut.root"; }// HLT_PAL1DoubleMu0HighQ triggered events
  	finput = "../upsiMiniTree_ppData_GLBGLB_QQtrigbit2_Trig_analysisOK_20140729_cuts10-006.root"; //HLT_PAL1DoubleMu0_HighQ triggered events AND GlbGlb muons pairs matched to it!
      // if(isPA) { finput = "../dimuonTree_upsiMiniTree_pA5tev_18p4nb__Run210498-211256_trigBit1_allTriggers0_pt4.root";} //// pPb
      break;
    case 8:
      // finput = "../upsiMiniTree_pythia1S_QQtrigbit1_Trig_analysisOK_20140729_cuts10-006.root";
      finput = "~/Project/ups2013/upsiMiniTree_Pyquen1S_QQtrigbit1_Trig_Unfolding_postCut_deltaRmatched_withCentrality.root";
      // finput ="../upsiMiniTree_pythia1S_QQtrigbit1_Trig_analysisOK_20140729.root" ;
      mass_l = 8.;
      mass_h = 10.5;
      binw=0.05;
      break;
    case 9:
      gROOT->LoadMacro("bkgTable_pp.h");
      finput = "../dimuonTree_upsiMiniTree_pA5tev_18p4nb__Run210498-211256_trigBit1_allTriggers0_pt4.root";
      isPA=true;
      break;
    default:
      cout<<"You don't know what you are doing! Pick one of the available datasets in the choseSampleCases[] array"<<endl;
      break;
    }
  cout << finput << endl;
  //  TFile f(finput,"read");
  TFile *f = new TFile(finput.c_str());
  TTree* theTree       = (TTree*)gROOT->FindObject("UpsilonTree"); // OS --- all mass
  //  //RooWorkspace* ws = new RooWorkspace("ws","Upsilon Mass Fitting");
  //ws.var("invariantMass");	
  RooRealVar* mass       = new RooRealVar("invariantMass","#mu#mu mass",mass_l,mass_h,"GeV/c^{2}");	
  //  ws.import(*mass);
  RooRealVar* upsPt      = new RooRealVar("upsPt","p_{T}(#Upsilon)",0,60,"GeV/c");
  RooRealVar* upsRapidity= new RooRealVar("upsRapidity",  "upsRapidity",-2.4, 2.4);
  RooRealVar* vProb      = new RooRealVar("vProb",  "vProb"  ,0.01,1.00);
  RooRealVar* QQsign     = new RooRealVar("QQsign",  "QQsign"  ,-1,5);
  RooRealVar* Centrality = new RooRealVar("Centrality","Centrality",0,100);
  RooRealVar* muPlusPt   = new RooRealVar("muPlusPt","muPlusPt",muonPtMin,1000);
  RooRealVar* muMinusPt  = new RooRealVar("muMinusPt","muMinusPt",muonPtMin,1000);
  RooRealVar* muPlusEta  = new RooRealVar("muPlusEta","muPlusEta",  muonEtaMin,muonEtaMax);
  RooRealVar* muMinusEta = new RooRealVar("muMinusEta","muMinusEta",muonEtaMin,muonEtaMax);
  RooDataSet* data0, *data;
  RooArgSet cols(*mass,*upsPt,*upsRapidity,*Centrality,*muPlusPt,*muMinusPt,*muPlusEta,*muMinusEta);
  data0 = new RooDataSet("data","data",theTree,cols); 
  data0->Print();
  // //  }
  // //data = ( RooDataSet*) data0->reduce(EventRange(0,100000));//,Cut("invariantMass<11"));
  TString cut_ap(Form("(%d<=Centrality && Centrality<%d) && (%.2f<muPlusEta && muPlusEta < %.2f) && (%.2f<muMinusEta && muMinusEta < %.2f) && (%.2f<upsPt && upsPt<%.2f) &&(abs(upsRapidity)>%.2f && abs(upsRapidity)<%.2f)  &&((muPlusPt > %.2f && muMinusPt > %.2f) || (muPlusPt > %.2f && muMinusPt > %.2f))",upsCentralityStart,upsCentralityEnd,muonEtaMin,muonEtaMax,muonEtaMin,muonEtaMax,upsPtMin,upsPtMax,upsRapMin,upsRapMax,muonPtMin,muonPtMax,muonPtMax,muonPtMin));
  cout << cut_ap << endl;
  data =  ( RooDataSet*) data0->reduce(Cut(cut_ap));
  ws.import(*data);
  data->Print();
  f->Close();
}
