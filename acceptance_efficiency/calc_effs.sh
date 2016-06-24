#!/bin/bash

# dir="effs_1S_pbpb_0"
# mkdir $dir
# root -l -b -q calc_effs.C'("trees/Upsi_Histos_Pyquen1SPbPbMC_Pt*",1,true,0)'
# mv hnum* results.txt eff_output.root $dir

# dir="effs_1S_pbpb_1"
# mkdir $dir
# root -l -b -q calc_effs.C'("trees/Upsi_Histos_Pyquen1SPbPbMC_Pt*",1,true,1)'
# mv hnum* results.txt eff_output.root $dir

dir="effs_1S_pbpb_2"
mkdir $dir
root -l -b -q calc_effs.C'("trees/Upsi_Histos_Pyquen1SPbPbMC_Pt*",1,true,2)'
mv hnum* results.txt eff_output.root $dir

# dir="effs_1S_pbpb_3"
# mkdir $dir
# root -l -b -q calc_effs.C'("trees/Upsi_Histos_Pyquen1SPbPbMC_Pt*",1,true,3)'
# mv hnum* results.txt eff_output.root $dir

# dir="effs_2S_pbpb_0"
# mkdir $dir
# root -l -b -q calc_effs.C'("trees/Upsi_Histos_Pyquen2SPbPbMC_Pt*",2,true,0)'
# mv hnum* results.txt eff_output.root $dir

# dir="effs_2S_pbpb_1"
# mkdir $dir
# root -l -b -q calc_effs.C'("trees/Upsi_Histos_Pyquen2SPbPbMC_Pt*",2,true,1)'
# mv hnum* results.txt eff_output.root $dir

dir="effs_2S_pbpb_2"
mkdir $dir
root -l -b -q calc_effs.C'("trees/Upsi_Histos_Pyquen2SPbPbMC_Pt*",2,true,2)'
mv hnum* results.txt eff_output.root $dir

# dir="effs_2S_pbpb_3"
# mkdir $dir
# root -l -b -q calc_effs.C'("trees/Upsi_Histos_Pyquen2SPbPbMC_Pt*",2,true,3)'
# mv hnum* results.txt eff_output.root $dir

dir="effs_1S_pp_2"
mkdir $dir
root -l -b -q calc_effs.C'("trees/Upsi_Histos_ppNoCutMC1S_fixedFSR.root",1,false,2)'
mv hnum* results.txt eff_output.root $dir

dir="effs_2S_pp_2"
mkdir $dir
root -l -b -q calc_effs.C'("trees/Upsi_Histos_ppNoCutMC2S_ok.root",2,false,2)'
mv hnum* results.txt eff_output.root $dir

dir="effs_3S_pp_2"
mkdir $dir
root -l -b -q calc_effs.C'("trees/Upsi_Histos_ppNoCutMC3S_ok.root",3,false,2)'
mv hnum* results.txt eff_output.root $dir
