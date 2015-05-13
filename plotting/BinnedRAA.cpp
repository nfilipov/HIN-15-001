void BinnedRAA (int state, float n_aa[], float n_aae[], float n_pp[], float n_ppe[], float e_aa[], float e_aae[],  float e_pp[],float e_ppe[], const int NumberOfBins, float graph_xbins[], float graph_xbins_err[])
// example: (1, 1s_pbpb, 1s_pbpbe, 1s_pp, 1s_ppe, eff1s_pbpb, eff1s_pbpbe, eff1s_pp, eff1s_ppe, NumberOfBins=5 , pt, pte)
{
  if (doControlPlots==true){cout << "hey ! we'll do some control plots" << endl; 
    PlotSignificances(state,1,1,true,false); // pt and rap could have been protected members...
    PlotSignificances(state,1,1,false,true); // pt and rap could have been protected members...
    //cout << "control plots done!" << endl;
    }
  float RAA[NumberOfBins]={};
  float RAAe[NumberOfBins]={};
  float RAAs[NumberOfBins]={}; // placeholder for systematics.
  //Upsilon csaa, cspp, raa, raaerr; //these are objects!
  Upsilon raa;                  
  Upsilon yield_ratio;        
  Upsilon efficiency_ratio;   
  // 
  // equation: raa = N_aa/N_pp * e_pp/e_pbpb * L_pp/(N_MB*TAA)
  //
  for(int ibin=0; ibin<NumberOfBins; ibin++)
    {
      yield_ratio.SetVariables (n_aa[ibin],n_pp[ibin]);
      yield_ratio.SetErrors (n_aae[ibin],n_ppe[ibin]);
      efficiency_ratio.SetVariables (e_pp[ibin],e_aa[ibin]);   // this ratio is inverted from the beginning.
      efficiency_ratio.SetErrors (e_ppe[ibin],e_aae[ibin]);
      
      // do the raa = ratio_sig * ratio_efficiency * global scale;
      
      RAA[ibin]= (yield_ratio.Ratio()) * (efficiency_ratio.Ratio()) * (L_pp_invNb/(T_AA_b*N_MB_corr));
      
      // prop. uncertainty = RAA*sqrt((unc.npp/npp)2+Error2+...+ErrorN);
      
      RAAe[ibin] = RAA[ibin]*PropUnc(yield_ratio,efficiency_ratio);
      RAAs[ibin] = RAAe[ibin]*sqrt(2);
      std::cout<<setprecision(3);
      cout << ibin << " "<<  RAA[ibin] <<" \\pm "<< RAAe[ibin]<< " \\pm "<< RAAs[ibin]<< endl;
    }
  // TGraphErrors g; g=(TGraphErrors) ploTGraphErrors(state,NumberOfBins,graph_xbins,RAA,graph_xbins_err,RAAe,true,RAAs,1);
  
}
// alternate version , is with n_pp not an array (for npart dependent results)
void BinnedNpartRAA (int state, float n_aa[], float n_aae[], float n_pp, float n_ppe, float e_aa[],float e_aae[], float e_pp, float e_ppe, const int NumberOfBins,float graph_xbins[], float graph_xbins_err[])
{
  float RAA[NumberOfBins]={};
  float RAAe[NumberOfBins]={};
  float RAAs[NumberOfBins]={}; // placeholder for systematics. 
  //Upsilon csaa, cspp, raa, raaerr; //these are objects!
  Upsilon raa;
  Upsilon yield_ratio;
  Upsilon efficiency_ratio;
  //
  // equation: raa = N_aa/N_pp * e_pp/e_pbpb * L_pp/(N_MB*TAA)
  //
  for(int ibin=0; ibin<NumberOfBins; ibin++)
     {
       yield_ratio.SetVariables (n_aa[ibin],n_pp[ibin]);
       yield_ratio.SetErrors (n_aae[ibin],n_ppe[ibin]);
       efficiency_ratio.SetVariables (e_pp[ibin],e_aa[ibin]);
       efficiency_ratio.SetErrors (e_ppe[ibin],e_aae[ibin]);

       // do the raa = ratio_sig * ratio_efficiency * global scale;

       RAA[ibin] = (yield_ratio.Ratio()) * (efficiency_ratio.Ratio()) * CentLumiCorr(state,ibin);

       // prop. uncertainty = RAA*sqrt((unc.npp/npp)2+Error2+...+ErrorN);

       RAAe[ibin] = RAA[ibin]*PropUnc(yield_ratio,efficiency_ratio);
       std::cout<<setprecision(3);
       cout << ibin << " "<<  RAA[ibin] <<" \\pm "<< RAAe[ibin]<< " \\pm "<< endl;
     }
  
}

TGraphErrors* ploTGraphErrors(int iState, const int NumberOfBins, float graph_x[],float graph_y[], float graph_x_err[],float graph_y_err[],bool doSyst, float graph_y_err_syst[],int it){
  // example>> (style=1,5,TransverseMomentum,RAA 
  //  float x = Object_x.GetObs();
  Float_t mSize=1.;
  Int_t mStyle=24;
  //  bool isStyle_1S,isStyle_2S;
  TGraphErrors *tmp = new TGraphErrors(NumberOfBins,graph_x,graph_y,0,graph_y_err);
  if (doSyst){
    TGraphErrors *tmpSyst = new TGraphErrors(NumberOfBins,graph_x,graph_y,graph_x_err,graph_y_err_syst);
  }
  if(!doControlPlots){
    if(iState == 1 ){
      tmp->SetMarkerColor(it);  
      if(doSyst){  tmpSyst->SetLineColor(kOrange+1);  }
      mStyle = 21;
    }
    else if(iState == 2){
      tmp->SetMarkerColor(kOrange+4);
      tmpSyst->SetLineColor(kOrange+4);  
      mStyle= 20;
    }
    else if(iState == 3  || iState == 0){ //3S or pp in general.
      tmp->SetMarkerColor(kAzure+1);
      tmpSyst->SetLineColor(kAzure+1);     
      mStyle = 22;
    }
  }
  tmp->SetMarkerSize(mSize*2);
  tmp->SetMarkerStyle(20+it); 
  tmp->SetFillStyle(3001);
  tmp->SetMarkerColor(it);  
  if(doSyst){ 
    tmpSyst->SetFillStyle(0);
    tmpSyst->SetLineWidth(2);
    tmpSyst->SetMarkerSize(0);
    tmpSyst->Draw("2");
    tmp->Draw("pe");
  }
  tmp->Draw("pe");
  return tmp;
}
