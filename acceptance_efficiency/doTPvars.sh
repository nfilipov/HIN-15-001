#!/bin/bash

basedir=/home/llr/cms/chapon/data_CMS/upsilon/effs/effs_20160307
macro=/home/llr/cms/chapon/data_CMS/upsilon/effs/doEff.C

coll=pbpb

for ns in 1 2; do
   for binning in 1 2; do
      dirname="effs_Y${ns}S_bins${binning}_${coll}"

      for i in `seq 0 100`; do
         echo $i
         sleep 1
         while [ `ps aux | grep root.exe | grep chapon | wc -l` -gt 25 ] ; do
            sleep 1
         done
         dirnamefull=${basedir}/${dirname}/results_muidtrg_$i
         mkdir -p $dirnamefull
         cd ${dirnamefull}
         if [ $ns -eq 1 ]; then
            nice root -l -b -q ${macro}'("/home/llr/cms/chapon/data_CMS/upsilon/effs/trees/Upsi_Histos_Pyquen1SPbPbMC_*.root",1,true,2,'$binning','$i',0)' 2>&1 >/dev/null &
         else 
            nice root -l -b -q ${macro}'("/home/llr/cms/chapon/data_CMS/upsilon/effs/trees/Upsi_Histos_Pyquen2SPbPbMC_*.root",2,true,2,'$binning','$i',0)' 2>&1 >/dev/null &
         fi
         cd -
      done

      for i in `seq 0 100`; do
         echo $i
         sleep 1
         while [ `ps aux | grep root.exe | grep chapon | wc -l` -gt 25 ] ; do
            sleep 1
         done
         dirnamefull=${basedir}/${dirname}/results_sta_$i
         mkdir -p $dirnamefull
         cd ${dirnamefull}
         if [ $ns -eq 1 ]; then
            nice root -l -b -q ${macro}'("/home/llr/cms/chapon/data_CMS/upsilon/effs/trees/Upsi_Histos_Pyquen1SPbPbMC_*.root",1,true,2,'$binning',0,'$i')' 2>&1 >/dev/null &
         else 
            nice root -l -b -q ${macro}'("/home/llr/cms/chapon/data_CMS/upsilon/effs/trees/Upsi_Histos_Pyquen2SPbPbMC_*.root",2,true,2,'$binning',0,'$i')' 2>&1 >/dev/null &
         fi
         cd -
      done
   done
done

coll=pp

for ns in 1 2 3; do
   for binning in 1 2; do
      dirname="effs_Y${ns}S_bins${binning}_${coll}"

      for i in `seq 0 100`; do
         echo $i
         sleep 1
         while [ `ps aux | grep root.exe | grep chapon | wc -l` -gt 25 ] ; do
            sleep 1
         done
         dirnamefull=${basedir}/${dirname}/results_muidtrg_$i
         mkdir -p $dirnamefull
         cd ${dirnamefull}
         if [ $ns -eq 1 ]; then
            nice root -l -b -q ${macro}'("/home/llr/cms/chapon/data_CMS/upsilon/effs/trees/Upsi_Histos_ppNoCutMC1S_fixedFSR.root",1,false,2,'$binning','$i',0)' 2>&1 >/dev/null &
         elif [ $ns -eq 2 ]; then
            nice root -l -b -q ${macro}'("/home/llr/cms/chapon/data_CMS/upsilon/effs/trees/Upsi_Histos_ppNoCutMC2S_full.root",2,false,2,'${binning}','$i',0)' 2>&1 >/dev/null &
         else 
            nice root -l -b -q ${macro}'("/home/llr/cms/chapon/data_CMS/upsilon/effs/trees/Upsi_Histos_ppNoCutMC3S_full.root",3,false,2,'${binning}','$i',0)' 2>&1 >/dev/null &
         fi
         cd -
      done

      for i in `seq 0 100`; do
         echo $i
         sleep 1
         while [ `ps aux | grep root.exe | grep chapon | wc -l` -gt 25 ] ; do
            sleep 1
         done
         dirnamefull=${basedir}/${dirname}/results_sta_$i
         mkdir -p $dirnamefull
         cd ${dirnamefull}
         if [ $ns -eq 1 ]; then
            nice root -l -b -q ${macro}'("/home/llr/cms/chapon/data_CMS/upsilon/effs/trees/Upsi_Histos_ppNoCutMC1S_fixedFSR.root",1,false,2,'$binning',0,'$i')' 2>&1 >/dev/null &
         elif [ $ns -eq 2 ]; then
            nice root -l -b -q ${macro}'("/home/llr/cms/chapon/data_CMS/upsilon/effs/trees/Upsi_Histos_ppNoCutMC2S_full.root",2,false,2,'${binning}',0,'$i')' 2>&1 >/dev/null &
         else 
            nice root -l -b -q ${macro}'("/home/llr/cms/chapon/data_CMS/upsilon/effs/trees/Upsi_Histos_ppNoCutMC3S_full.root",3,false,2,'${binning}',0,'$i')' 2>&1 >/dev/null &
         fi
         cd -
      done
   done
done
