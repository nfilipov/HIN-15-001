void calc_effs(const char* thefiles, int YS=1, bool ispbpb=true, int strategy=0)
   // YS = N for NS
   // ispbpb = true for PbPb, false for pp
   // strategy = 0 for fit + reco quantities
   //            1 for fit + truth quantities
   //            2 for count + reco quantities
   //            3 for count + reco quantities
{
   gROOT->LoadMacro("dimueff.C+");
   TChain *tch = new TChain("myTree"); tch->Add(thefiles);
   dimueff toto(tch); toto.Loop();
}
