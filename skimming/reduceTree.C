#include "TFile.h"
#include "TTree.h"
#include "TEventList.h"

void makeList() {
  TFile *f1 = new TFile("../dimuonTree_upsiMiniTree_AA2p76tev_noIDCuts_RunHIN-15-001_trigBit1_allTriggers0.root");
  TTree *myTree = (TTree*) f1->Get("UpsilonTree");
  TCut cut("(_mupl_dxy <3 && _mupl_dz <15 && _mupl_nTrkHits>10 && _mupl_nTrkWMea >0 && _mupl_normChi2_inner < 4 && _mupl_normChi2_global < 4 && _mupl_TrkMuArb==1) && (_mumi_dxy <3 && _mumi_dz <15 && _mumi_nTrkHits>10 && _mumi_nTrkWMea >0 && _mumi_normChi2_inner < 4 && _mumi_normChi2_global < 4 && _mumi_TrkMuArb==1)");  
  myTree->Draw(">>elist",cut);
  //      track.numberOfValidHits > 10 && track.normalizedChi2 < 4 && track.hitPattern.pixelLayersWithMeasurement > 0 
  //      && abs(track.dxy) < 3 && abs(track.dz) < 15
  //      && isGlobalMuon && isTrackerMuon
  //      globalTrack.normalizedChi2 < 20 && muonID('TrackerMuonArbitrated')"
  TEventList *elist = (TEventList*)gDirectory->Get("elist");
  TFile ef("../elist.root","recreate");                       
  elist->Write();
  ef.Close();
}

void makeSmall() {
  TFile *f = new TFile("../elist.root");
  TEventList *elist = (TEventList*)f->Get("elist");
  TFile *f1 = new TFile("../dimuonTree_upsiMiniTree_AA2p76tev_noIDCuts_RunHIN-15-001_trigBit1_allTriggers0.root");
  TTree *myTree = (TTree*) f1->Get("UpsilonTree");
  myTree->SetEventList(elist);
  TFile *f2 = new TFile("../dimuonTree_upsiMiniTree_AA2p76tev_WithIDCuts_RunHIN-15-001_trigBit1_allTriggers0.root","recreate");
  TTree *mySmallTree = myTree->CopyTree("");
  mySmallTree->Write();
  mySmallTree->Print();
  f2->Close();
}



