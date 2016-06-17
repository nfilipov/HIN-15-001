#!/bin/bash

basedir=/home/llr/cms/chapon/data_CMS/upsilon/effs/effs_20160617_syst
macro=/home/llr/cms/chapon/data_CMS/upsilon/effs/doEff.C
batchscript=/home/llr/cms/chapon/data_CMS/upsilon/effs/runbatch.sh

coll=pbpb

for ns in 1 2; do
   for binning in 1 2; do
      dirname="effs_Y${ns}S_bins${binning}_${coll}"

      # for i in `seq 0 100` -1 -2; do
      for i in -1 -2; do
         echo $i
         sleep 1
         dirnamefull=${basedir}/${dirname}/results_muidtrg_$i
         mkdir -p $dirnamefull
         cd ${dirnamefull}
         if [ $ns -eq 1 ]; then
            thefiles="/home/llr/cms/chapon/data_CMS/upsilon/effs/trees/Upsi_Histos_Pyquen1SPbPbMC_*.root"
         else 
            thefiles="/home/llr/cms/chapon/data_CMS/upsilon/effs/trees/Upsi_Histos_Pyquen2SPbPbMC_*.root"
         fi
         # prepare for batch
         export dirnamefull=$dirnamefull
         export macro=$macro
         export thefiles=$thefiles
         export ns=$ns
         export ispbpb="true"
         export binning=$binning
         export imuidtrg=$i
         export ista=0
         qsub -k oe -q cms@llrt3 -N ${dirname}_results_muidtrg_$i -V -o $dirnamefull -v dirnamefull,macro,thefiles,ns,ispbpb,binning,imuidtrg,ista $batchscript
         cd -

         dirnamefull=${basedir}/${dirname}/results_sta_$i
         mkdir -p $dirnamefull
         cd ${dirnamefull}
         export imuidtrg=0
         export ista=$i
         export dirnamefull=$dirnamefull
         qsub -k oe -q cms@llrt3 -N ${dirname}_results_sta_$i -V -o $dirnamefull -v dirnamefull,macro,thefiles,ns,ispbpb,binning,imuidtrg,ista $batchscript
         cd -
      done
   done
done

coll=pp

for ns in 1 2 3; do
   for binning in 1 2; do
      dirname="effs_Y${ns}S_bins${binning}_${coll}"

      # for i in `seq 0 100` -1 -2; do
      for i in -1 -2; do
         echo $i
         sleep 1
         dirnamefull=${basedir}/${dirname}/results_muidtrg_$i
         mkdir -p $dirnamefull
         cd ${dirnamefull}
         if [ $ns -eq 1 ]; then
            thefiles="/home/llr/cms/chapon/data_CMS/upsilon/effs/trees/Upsi_Histos_ppNoCutMC1S_fixedFSR.root"
         elif [ $ns -eq 2 ]; then
            thefiles="/home/llr/cms/chapon/data_CMS/upsilon/effs/trees/Upsi_Histos_ppNoCutMC2S_ok.root"
         else 
            thefiles="/home/llr/cms/chapon/data_CMS/upsilon/effs/trees/Upsi_Histos_ppNoCutMC3S_ok.root"
         fi
         # prepare for batch
         export dirnamefull=$dirnamefull
         export macro=$macro
         export thefiles=$thefiles
         export ns=$ns
         export ispbpb="false"
         export binning=$binning
         export imuidtrg=$i
         export ista=0
         qsub -k oe -q cms@llrt3 -N ${dirname}_results_muidtrg_$i -V -o $dirnamefull -v dirnamefull,macro,thefiles,ns,ispbpb,binning,imuidtrg,ista $batchscript
         cd -

         dirnamefull=${basedir}/${dirname}/results_sta_$i
         mkdir -p $dirnamefull
         cd ${dirnamefull}
         export imuidtrg=0
         export ista=$i
         export dirnamefull=$dirnamefull
         qsub -k oe -q cms@llrt3 -N ${dirname}_results_sta_$i -V -o $dirnamefull -v dirnamefull,macro,thefiles,ns,ispbpb,binning,imuidtrg,ista $batchscript
         cd -
      done
   done
done
