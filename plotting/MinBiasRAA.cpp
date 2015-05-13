
void MinBiasRAA ()
{
  Upsilon Y1S_pp_tot, Y1S_aa_tot, R1S_aa_tot, R1S_aa_tote;
  float CS1S_pp_tot, CS1S_aa_tot, RAA_1S_tot, CS1S_pp_tote, CS1S_aa_tote, RAA_1S_tote;
  Y1S_pp_tot.SetVariables (N1S_pp_tot3p5, Aet_1S_pythia_tot);
  Y1S_pp_tot.SetErrors    (N1S_pp_tot3p5e, Aet_1S_pythia_tote);
  Y1S_aa_tot.SetErrors    (N1S_aa_tot3p5e, Aet_1S_pyquen_tote);
  Y1S_aa_tot.SetVariables (N1S_aa_tot3p5, Aet_1S_pyquen_tot)  ;
  CS1S_pp_tot = Y1S_pp_tot.Ratio()/L_pp_invNb;
  CS1S_aa_tot = Y1S_aa_tot.Ratio()/(N_MB_corr*T_AA_b);
  CS1S_aa_tote = Y1S_aa_tot.RatioError()/L_pp_invNb;
  CS1S_pp_tote = Y1S_pp_tot.RatioError()/(N_MB_corr*T_AA_b);
  cout << "total CS1S_pp=  " << Y1S_pp_tot.Ratio() << " +/- " << Y1S_pp_tot.RatioError() << endl;
  cout << "total CS1S_aa=  " << Y1S_aa_tot.Ratio() << " +/- " << Y1S_aa_tot.RatioError() << endl;
  R1S_aa_tot.SetVariables(CS1S_aa_tot,CS1S_pp_tot);
  RAA_1S_tot = R1S_aa_tot.Ratio();
  R1S_aa_tot.SetErrors(CS1S_aa_tote,CS1S_pp_tote);
  RAA_1S_tote = R1S_aa_tot.RatioError();
  cout<< " uncorrected RAA (1S)  = "  <<RAA_1S_tot <<  " +/- " << RAA_1S_tote << endl;
}
