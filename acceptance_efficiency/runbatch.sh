#!/bin/bash

# source /data_CMS/cms/chapon/root/bin/thisroot.sh
source /opt/exp_soft/llr/root/v6.06.00-el6-gcc48/etc/init.sh

cd ${dirnamefull}
pwd

root -l -b -q ${macro}'("'${thefiles}'",'$ns','${ispbpb}',2,'$binning','$imuidtrg','$ista')' 2>&1 >/dev/null

echo "ok, I'm done"
