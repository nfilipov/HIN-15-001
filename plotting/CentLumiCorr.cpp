float CentLumiCorr (int State, int Bin)
{
  float lumicorr;
  if(State==1){
    lumicorr = L_pp_invNb/(1000*taa1S[Bin]*N_MB_corr*mb_percentage1S[Bin]);
  }
  else if (State==2){
    lumicorr = L_pp_invNb/(1000*taa2S[Bin]*N_MB_corr*mb_percentage2S[Bin]);
  }
  return lumicorr;
}
