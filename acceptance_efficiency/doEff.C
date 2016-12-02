#include "dimueff.C"

void doEff(const char* filepath, int YS, bool ispbpb, int strategy, int binningYS, int var1, int var2)
{
   // gROOT->LoadMacro("/home/llr/cms/chapon/data_CMS/upsilon/effs/dimueff.C+");
   TChain *tch = new TChain("myTree"); tch->Add(filepath);
   dimueff toto(tch); toto.Loop(YS,ispbpb,strategy,binningYS,var1,var2);
}
