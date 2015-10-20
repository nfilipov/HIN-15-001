#!/bin/bash

for i in `seq 0 100`; do
   echo $i
   sleep 1
   while [ `ps aux | grep root.exe | grep chapon | wc -l` -gt 25 ] ; do
      sleep 1
   done
   mkdir results_muidtrg_$i
   cd results_muidtrg_$i
   # nice root -l -b -q /home/llr/cms/chapon/data_CMS/upsilon/effs/doEff.C'("/home/llr/cms/chapon/data_CMS/upsilon/effs/trees/Upsi_Histos_Pyquen*2S*",2,true,2,1,'$i')' >/dev/null &
   nice root -l -b -q /home/llr/cms/chapon/data_CMS/upsilon/effs/doEff.C'("/home/llr/cms/chapon/data_CMS/upsilon/effs/trees/Upsi_Histos_ppNoCutMC1S_fixedFSR.root",1,false,2,2,'$i',0)' >/dev/null &
   cd -
done

for i in `seq 0 100`; do
   echo $i
   sleep 1
   while [ `ps aux | grep root.exe | grep chapon | wc -l` -gt 25 ] ; do
      sleep 1
   done
   mkdir results_sta_$i
   cd results_sta_$i
   # nice root -l -b -q /home/llr/cms/chapon/data_CMS/upsilon/effs/doEff.C'("/home/llr/cms/chapon/data_CMS/upsilon/effs/trees/Upsi_Histos_Pyquen*2S*",2,true,2,1,'$i')' >/dev/null &
   nice root -l -b -q /home/llr/cms/chapon/data_CMS/upsilon/effs/doEff.C'("/home/llr/cms/chapon/data_CMS/upsilon/effs/trees/Upsi_Histos_ppNoCutMC1S_fixedFSR.root",1,false,2,2,0,'$i')' >/dev/null &
   cd -
done
