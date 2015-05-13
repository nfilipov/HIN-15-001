#include "InitCanvases.cpp"
#include "data_signif.h"
#include "data_raa.h"
//#include "BinnedRAA.cpp"
void PlotSignificances(int s,int pp,int pbpb,bool pt,bool rap ){
  cout << "hola, welcome to PlotSignificances!" << endl;       
  TCanvas c1; 
  InitCanvases(c1,pt,rap);
  if(pt){
    TGraphErrors *g3p53p5; g3p53p5 = ploTGraphErrors(s,nPtBins_2014,pt15,aa_1S_3p5_3p5_pt,pt15e,0,0,0,1); //pt15 is the one with high pt bin added (20-40)
    TGraphErrors *g3p54;  g3p54  = ploTGraphErrors(s,nPtBins_2014,pt15,aa_1S_3p5_4_pt,pt15e,0,0,0,2); //pt15 is the one with high pt bin added (20-40)
    TGraphErrors *g44; g44  = ploTGraphErrors(s,nPtBins_2014,pt15,aa_1S_4_4_pt,pt15e,0,0,0,4);

    TGraphErrors *gpp3p53p5; gpp3p53p5 = ploTGraphErrors(s,nPtBins_2014,pt15,pp_1S_3p5_3p5_pt,pt15e,0,0,0,11); //pt15 is the one with high pt bin added (20-40)
    TGraphErrors *gpp3p54;  gpp3p54  = ploTGraphErrors(s,nPtBins_2014,pt15,pp_1S_3p5_4_pt,pt15e,0,0,0,12); //pt15 is the one with high pt bin added (20-40)
    TGraphErrors *gpp44; gpp44  = ploTGraphErrors(s,nPtBins_2014,pt15,pp_1S_4_4_pt,pt15e,0,0,0,14);
  }
  if(rap){
    TGraphErrors *g3p53p5; g3p53p5 = ploTGraphErrors(s,nRapBins_2014,rap2014,aa_1S_3p5_3p5_rap,rap2014e,0,0,0,1); //rap2014 is the one with high pt bin added (20-40)
    TGraphErrors *g3p54;  g3p54  = ploTGraphErrors(s,nRapBins_2014,rap2014,aa_1S_3p5_4_rap,rap2014e,0,0,0,2); //pt15 is the one with high rap bin added (20-40)
    TGraphErrors *g44; g44  = ploTGraphErrors(s,nRapBins_2014,rap2014,aa_1S_4_4_rap,rap2014e,0,0,0,4);
    
    TGraphErrors *gpp3p53p5; gpp3p53p5 = ploTGraphErrors(s,nRapBins_2014,rap2014,pp_1S_3p5_3p5_rap,rap2014e,0,0,0,11); //rap2014 is the one with high rap bin added (20-40)
    TGraphErrors *gpp3p54;  gpp3p54  = ploTGraphErrors(s,nRapBins_2014,rap2014,pp_1S_3p5_4_rap,rap2014e,0,0,0,12); //rap2014 is the one with high rap bin added (20-40)
    TGraphErrors *gpp44; gpp44  = ploTGraphErrors(s,nRapBins_2014,rap2014,pp_1S_4_4_rap,rap2014e,0,0,0,14);
  }
  //pt15 is the one with high pt bin added (20-40)
  // g3p54p5.SetMarkerColor(kGreen+3);
  //  ploTGraphErrors(s,nPtBins_2014,pt15,aa_1S_3p5_3p5_pt,pt15e,0,0,0); //pt15 is the one with high pt bin added (20-40)
  legup = new TLegend(0.45,0.8,0.93,0.95);
  legup->SetFillStyle(0);
  legup->SetFillColor(0);
  legup->SetBorderSize(0);
  legup->SetTextFont(42);
  legup->SetTextSize(0.03);
  legup->SetHeader("Significance = #Upsilon(1S)/err(#Upsilon(1S))");
  legup->AddEntry(gpp3p53p5,"pp - p_{T}(#mu_{1},#mu_{2}) > 3.5, 3.5 GeV/c","p");
  legup->AddEntry(gpp3p54,"pp - p_{T}(#mu_{1},#mu_{2}) > 3.5, 4 GeV/c","p");
  legup->AddEntry(gpp44,"pp - p_{T}(#mu_{1},#mu_{2}) > 4 GeV/c","p");
  legup->Draw();
  legdown = new TLegend(0.25,0.15,0.7,0.3);
  legdown->SetFillStyle(0);
  legdown->SetFillColor(0);
  legdown->SetBorderSize(0);
  legdown->SetTextFont(42);
  legdown->SetTextSize(0.03);
  legdown->SetHeader("Significance = #Upsilon(1S)/err(#Upsilon(1S))");
  legdown->AddEntry(g3p53p5,"AA - p_{T}(#mu_{1},#mu_{2}) > 3.5, 3.5 GeV/c","p");
  legdown->AddEntry(g3p54,"AA - p_{T}(#mu_{1},#mu_{2}) > 3.5, 4 GeV/c","p");
  legdown->AddEntry(g44,"AA - p_{T}(#mu_{1},#mu_{2}) >  4 GeV/c","p");
  legdown->Draw();
  c1.Update();
  c1.SaveAs(Form("~/Desktop/signif_pp%d_pbpb%d_pt%d_rap%d.pdf",pp,pbpb,(int)pt,(int)rap));
}
