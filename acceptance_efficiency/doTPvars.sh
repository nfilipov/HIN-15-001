#!/bin/bash

for i in `seq 0 100`; do
   echo $i
   sleep 1
   while [ `ps aux | grep root.exe | grep chapon | wc -l` -gt 25 ] ; do
      sleep 1
   done
   mkdir results_$i
   cd results_$i
   # nice root -l -b -q /home/llr/cms/chapon/data_CMS/upsilon/effs/doEff.C'("/home/llr/cms/chapon/data_CMS/upsilon/effs/trees/Upsi_Histos_Pyquen*1S*",1,true,2,'$i')' >/dev/null &
   nice root -l -b -q /home/llr/cms/chapon/data_CMS/upsilon/effs/doEff.C'("/home/llr/cms/chapon/data_CMS/upsilon/effs/trees/Upsi_Histos_ppNoCutMC3S_ok.root",3,false,2,'$i')' >/dev/null &
   cd -
done
