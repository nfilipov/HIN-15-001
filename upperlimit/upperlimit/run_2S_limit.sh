#!/bin/bash

# dir
dir=ws_2S_04mar2015/

# pt fits
dir2=$dir/ptFits
for cat in dimuPt000500 dimuPt12002000 dimuPt5001200; do 
   nice root -l -b -q runLimit_RaaNS_Workspace.C'("'${dir2}'/WS_combo2S_'${cat}'.root","raa2")'
   mv results.txt $dir2/results_2S_${cat}.txt
   mv c1.pdf $dir2/c1_2S_${cat}.pdf
   mv c1.root $dir2/c1_2S_${cat}.root
   mv c2.pdf $dir2/c2_2S_${cat}.pdf
   mv c2.root $dir2/c2_2S_${cat}.root
done

# rapidity fits
dir2=$dir/rapidityFits
for cat in dimuY000120 dimuY120240; do 
   nice root -l -b -q runLimit_RaaNS_Workspace.C'("'${dir2}'/WS_combo2S_'${cat}'.root","raa2")'
   mv results.txt $dir2/results_2S_${cat}.txt
   mv c1.pdf $dir2/c1_2S_${cat}.pdf
   mv c1.root $dir2/c1_2S_${cat}.root
   mv c2.pdf $dir2/c2_2S_${cat}.pdf
   mv c2.root $dir2/c2_2S_${cat}.root
done

# rapidity fits
dir2=$dir/centralityFits
for cat in cent0M5 cent5M10 cent10M20 cent20M30 cent30M40 cent40M50 cent50M100; do 
   nice root -l -b -q runLimit_RaaNS_Workspace.C'("'${dir2}'/WS_combo2S_'${cat}'.root","raa2")'
   mv results.txt $dir2/results_2S_${cat}.txt
   mv c1.pdf $dir2/c1_2S_${cat}.pdf
   mv c1.root $dir2/c1_2S_${cat}.root
   mv c2.pdf $dir2/c2_2S_${cat}.pdf
   mv c2.root $dir2/c2_2S_${cat}.root
done
