#!/bin/bash
########################################## AA  ############################################
########################################## pt  ############################################
txtDir_aa_3_3_pt=(
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3_3/Pt/Pt_0_2p5"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3_3/Pt/Pt_2p5_5" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3_3/Pt/Pt_5_8" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3_3/Pt/Pt_8_12"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3_3/Pt/Pt_12_20"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3_3/Pt/Pt_20_40")
txtDir_aa_3_3p5_pt=(
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3_3p5/Pt/Pt_0_2p5"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3_3p5/Pt/Pt_2p5_5" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3_3p5/Pt/Pt_5_8" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3_3p5/Pt/Pt_8_12"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3_3p5/Pt/Pt_12_20"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3_3p5/Pt/Pt_20_40")
txtDir_aa_3_4_pt=(
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3_4/Pt/Pt_0_2p5"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3_4/Pt/Pt_2p5_5" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3_4/Pt/Pt_5_8" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3_4/Pt/Pt_8_12"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3_4/Pt/Pt_12_20"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3_4/Pt/Pt_20_40")
txtDir_aa_3_4p5_pt=(
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3_4p5/Pt/Pt_0_2p5"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3_4p5/Pt/Pt_2p5_5" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3_4p5/Pt/Pt_5_8" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3_4p5/Pt/Pt_8_12"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3_4p5/Pt/Pt_12_20"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3_4p5/Pt/Pt_20_40")
txtDir_aa_3p5_3p5_pt=(
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3p5_3p5/Pt/Pt_0_2p5"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3p5_3p5/Pt/Pt_2p5_5" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3p5_3p5/Pt/Pt_5_8" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3p5_3p5/Pt/Pt_8_12"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3p5_3p5/Pt/Pt_12_20"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3p5_3p5/Pt/Pt_20_40")
txtDir_aa_3p5_4_pt=(
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3p5_4/Pt/Pt_0_2p5"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3p5_4/Pt/Pt_2p5_5" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3p5_4/Pt/Pt_5_8" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3p5_4/Pt/Pt_8_12"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3p5_4/Pt/Pt_12_20"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3p5_4/Pt/Pt_20_40")
txtDir_aa_3p5_4p5_pt=(
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3p5_4p5/Pt/Pt_0_2p5"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3p5_4p5/Pt/Pt_2p5_5" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3p5_4p5/Pt/Pt_5_8" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3p5_4p5/Pt/Pt_8_12"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3p5_4p5/Pt/Pt_12_20"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3p5_4p5/Pt/Pt_20_40")
txtDir_aa_4_4_pt=(
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_4_4/Pt/Pt_0_2p5"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_4_4/Pt/Pt_2p5_5" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_4_4/Pt/Pt_5_8" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_4_4/Pt/Pt_8_12"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_4_4/Pt/Pt_12_20"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_4_4/Pt/Pt_20_40")
txtDir_aa_4_4p5_pt=(
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_4_4p5/Pt/Pt_0_2p5"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_4_4p5/Pt/Pt_2p5_5" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_4_4p5/Pt/Pt_5_8" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_4_4p5/Pt/Pt_8_12"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_4_4p5/Pt/Pt_12_20"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_4_4p5/Pt/Pt_20_40")
txtDir_aa_4p5_4p5_pt=(
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_4p5_4p5/Pt/Pt_0_2p5"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_4p5_4p5/Pt/Pt_2p5_5" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_4p5_4p5/Pt/Pt_5_8" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_4p5_4p5/Pt/Pt_8_12"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_4p5_4p5/Pt/Pt_12_20"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_4p5_4p5/Pt/Pt_20_40")
########################################## rap ############################################
txtDir_aa_3p5_3p5_rap=(
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3p5_3p5/Rap/Rap_0_0p4"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3p5_3p5/Rap/Rap_0p4_0p8" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3p5_3p5/Rap/Rap_0p8_1p2" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3p5_3p5/Rap/Rap_1p2_1p6"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3p5_3p5/Rap/Rap_1p6_2"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3p5_3p5/Rap/Rap_2_2p4"
)
#    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3p5_3p5/Rap/Rap_0_1p2"
#    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3p5_3p5/Rap/Rap_1p2_2p4"
txtDir_aa_3p5_4_rap=(
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3p5_4/Rap/Rap_0_0p4"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3p5_4/Rap/Rap_0p4_0p8" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3p5_4/Rap/Rap_0p8_1p2" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3p5_4/Rap/Rap_1p2_1p6"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3p5_4/Rap/Rap_1p6_2"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3p5_4/Rap/Rap_2_2p4"
)
txtDir_aa_3p5_4p5_rap=(
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3p5_4p5/Rap/Rap_0_0p4"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3p5_4p5/Rap/Rap_0p4_0p8" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3p5_4p5/Rap/Rap_0p8_1p2" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3p5_4p5/Rap/Rap_1p2_1p6"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3p5_4p5/Rap/Rap_1p6_2"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3p5_4p5/Rap/Rap_2_2p4"
)
txtDir_aa_4_4_rap=(
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_4_4/Rap/Rap_0_0p4"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_4_4/Rap/Rap_0p4_0p8" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_4_4/Rap/Rap_0p8_1p2" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_4_4/Rap/Rap_1p2_1p6"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_4_4/Rap/Rap_1p6_2"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_4_4/Rap/Rap_2_2p4"
)
txtDir_aa_4_4p5_rap=(
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_4_4p5/Rap/Rap_0_0p4"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_4_4p5/Rap/Rap_0p4_0p8" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_4_4p5/Rap/Rap_0p8_1p2" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_4_4p5/Rap/Rap_1p2_1p6"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_4_4p5/Rap/Rap_1p6_2"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_4_4p5/Rap/Rap_2_2p4"
)
txtDir_aa_4p5_4p5_rap=(
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_4p5_4p5/Rap/Rap_0_0p4"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_4p5_4p5/Rap/Rap_0p4_0p8" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_4p5_4p5/Rap/Rap_0p8_1p2" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_4p5_4p5/Rap/Rap_1p2_1p6"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_4p5_4p5/Rap/Rap_1p6_2"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_4p5_4p5/Rap/Rap_2_2p4"
)

########################################## pp  ############################################
########################################## pt  ############################################
txtDir_pp_3_3_pt=(
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3_3/Pt/Pt_0_2p5"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3_3/Pt/Pt_2p5_5" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3_3/Pt/Pt_5_8" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3_3/Pt/Pt_8_12"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3_3/Pt/Pt_12_20"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3_3/Pt/Pt_20_40")
txtDir_pp_3_3p5_pt=(
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3_3p5/Pt/Pt_0_2p5"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3_3p5/Pt/Pt_2p5_5" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3_3p5/Pt/Pt_5_8" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3_3p5/Pt/Pt_8_12"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3_3p5/Pt/Pt_12_20"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/PbPb/pt_3_3p5/Pt/Pt_20_40")
txtDir_pp_3_4_pt=(
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3_4/Pt/Pt_0_2p5"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3_4/Pt/Pt_2p5_5" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3_4/Pt/Pt_5_8" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3_4/Pt/Pt_8_12"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3_4/Pt/Pt_12_20"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3_4/Pt/Pt_20_40")
txtDir_pp_3_4p5_pt=(
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3_4p5/Pt/Pt_0_2p5"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3_4p5/Pt/Pt_2p5_5" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3_4p5/Pt/Pt_5_8" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3_4p5/Pt/Pt_8_12"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3_4p5/Pt/Pt_12_20"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3_4p5/Pt/Pt_20_40")
txtDir_pp_3p5_3p5_pt=(
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3p5_3p5/Pt/Pt_0_2p5"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3p5_3p5/Pt/Pt_2p5_5" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3p5_3p5/Pt/Pt_5_8" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3p5_3p5/Pt/Pt_8_12"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3p5_3p5/Pt/Pt_12_20"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3p5_3p5/Pt/Pt_20_40")
txtDir_pp_3p5_4_pt=(
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3p5_4/Pt/Pt_0_2p5"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3p5_4/Pt/Pt_2p5_5" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3p5_4/Pt/Pt_5_8" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3p5_4/Pt/Pt_8_12"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3p5_4/Pt/Pt_12_20"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3p5_4/Pt/Pt_20_40")
txtDir_pp_3p5_4p5_pt=(
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3p5_4p5/Pt/Pt_0_2p5"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3p5_4p5/Pt/Pt_2p5_5" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3p5_4p5/Pt/Pt_5_8" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3p5_4p5/Pt/Pt_8_12"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3p5_4p5/Pt/Pt_12_20"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3p5_4p5/Pt/Pt_20_40")
txtDir_pp_4_4_pt=(
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_4_4/Pt/Pt_0_2p5"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_4_4/Pt/Pt_2p5_5" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_4_4/Pt/Pt_5_8" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_4_4/Pt/Pt_8_12"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_4_4/Pt/Pt_12_20"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_4_4/Pt/Pt_20_40")
txtDir_pp_4_4p5_pt=(
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_4_4p5/Pt/Pt_0_2p5"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_4_4p5/Pt/Pt_2p5_5" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_4_4p5/Pt/Pt_5_8" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_4_4p5/Pt/Pt_8_12"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_4_4p5/Pt/Pt_12_20"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_4_4p5/Pt/Pt_20_40")
txtDir_pp_4p5_4p5_pt=(
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_4p5_4p5/Pt/Pt_0_2p5"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_4p5_4p5/Pt/Pt_2p5_5" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_4p5_4p5/Pt/Pt_5_8" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_4p5_4p5/Pt/Pt_8_12"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_4p5_4p5/Pt/Pt_12_20"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_4p5_4p5/Pt/Pt_20_40")
########################################## rap ############################################
txtDir_pp_3p5_3p5_rap=(
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3p5_3p5/Rap/Rap_0_0p4"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3p5_3p5/Rap/Rap_0p4_0p8" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3p5_3p5/Rap/Rap_0p8_1p2" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3p5_3p5/Rap/Rap_1p2_1p6"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3p5_3p5/Rap/Rap_1p6_2"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3p5_3p5/Rap/Rap_2_2p4"
)
#    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3p5_3p5/Rap/Rap_0_1p2"
#    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3p5_3p5/Rap/Rap_1p2_2p4"
txtDir_pp_3p5_4_rap=(
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3p5_4/Rap/Rap_0_0p4"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3p5_4/Rap/Rap_0p4_0p8" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3p5_4/Rap/Rap_0p8_1p2" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3p5_4/Rap/Rap_1p2_1p6"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3p5_4/Rap/Rap_1p6_2"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3p5_4/Rap/Rap_2_2p4"
)
txtDir_pp_3p5_4p5_rap=(
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3p5_4p5/Rap/Rap_0_0p4"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3p5_4p5/Rap/Rap_0p4_0p8" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3p5_4p5/Rap/Rap_0p8_1p2" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3p5_4p5/Rap/Rap_1p2_1p6"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3p5_4p5/Rap/Rap_1p6_2"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_3p5_4p5/Rap/Rap_2_2p4"
)
txtDir_pp_4_4_rap=(
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_4_4/Rap/Rap_0_0p4"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_4_4/Rap/Rap_0p4_0p8" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_4_4/Rap/Rap_0p8_1p2" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_4_4/Rap/Rap_1p2_1p6"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_4_4/Rap/Rap_1p6_2"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_4_4/Rap/Rap_2_2p4"
)
txtDir_pp_4_4p5_rap=(
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_4_4p5/Rap/Rap_0_0p4"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_4_4p5/Rap/Rap_0p4_0p8" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_4_4p5/Rap/Rap_0p8_1p2" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_4_4p5/Rap/Rap_1p2_1p6"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_4_4p5/Rap/Rap_1p6_2"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_4_4p5/Rap/Rap_2_2p4"
)
txtDir_pp_4p5_4p5_rap=(
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_4p5_4p5/Rap/Rap_0_0p4"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_4p5_4p5/Rap/Rap_0p4_0p8" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_4p5_4p5/Rap/Rap_0p8_1p2" 
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_4p5_4p5/Rap/Rap_1p2_1p6"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_4p5_4p5/Rap/Rap_1p6_2"
    "/Users/nicolas/Project/ups2013/code2015/txtOutput/04-2015/pp/pt_4p5_4p5/Rap/Rap_2_2p4"
)

#aa
aa_1S_3_3_pt=()
aa_1S_3_3p5_pt=()
aa_1S_3_4_pt=()
aa_1S_3_4p5_pt=()
aa_1S_3p5_3p5_pt=()
aa_1S_3p5_4_pt=()
aa_1S_3p5_4p5_pt=()
aa_1S_4_4_pt=()
aa_1S_4_4p5_pt=()
aa_1S_4p5_4p5_pt=()
#pp
pp_1S_3_3_pt=()
pp_1S_3_3p5_pt=()
pp_1S_3_4_pt=()
pp_1S_3_4p5_pt=()
pp_1S_3p5_3p5_pt=()
pp_1S_3p5_4_pt=()
pp_1S_3p5_4p5_pt=()
pp_1S_4_4_pt=()
pp_1S_4_4p5_pt=()
pp_1S_4p5_4p5_pt=()
##### signif loops
## aa
# for i in ${txtDir_aa_3_3_pt[@]}
# do
#     # echo "cat $i/*_1_ref2_mass8p511p5.txt | awk '{print $21}'"
#     aa_1S_3_3_pt+=(`cat $i/*_1_ref2_mass8p511p5.txt | awk '{print $21}'`)
# done
# ( IFS=,; echo "float aa_1S_3_3_pt[nPtBins_2014] = {${aa_1S_3_3_pt[*]}};")
# #
# for i in ${txtDir_aa_3_3p5_pt[@]}
# do
#     # echo "cat $i/*_1_ref2_mass8p511p5.txt | awk '{print $21}'"
#     aa_1S_3_3p5_pt+=(`cat $i/*_1_ref2_mass8p511p5.txt | awk '{print $21}'`)
# done
# ( IFS=,; echo "float aa_1S_3_3p5_pt[nPtBins_2014] = {${aa_1S_3_3p5_pt[*]}};")
# #
# for i in ${txtDir_aa_3_4_pt[@]}
# do 
#     # echo "cat $i/*_1_ref2_mass8p511p5.txt | awk '{print $21}'"
#     aa_1S_3_4_pt+=(`cat $i/*_1_ref2_mass8p511p5.txt | awk '{print $21}'`)
# done
# ( IFS=,; echo "float aa_1S_3_4_pt[nPtBins_2014] = {${aa_1S_3_4_pt[*]}};")
# #
# for i in ${txtDir_aa_3_4p5_pt[@]}
# do
#     # echo "cat $i/*_1_ref2_mass8p511p5.txt | awk '{print $21}'"
#     aa_1S_3_4p5_pt+=(`cat $i/*_1_ref2_mass8p511p5.txt | awk '{print $21}'`)
# done
# ( IFS=,; echo "float aa_1S_3_4p5_pt[nPtBins_2014] = {${aa_1S_3_4p5_pt[*]}};")#
for i in ${txtDir_aa_3p5_3p5_pt[@]}
do
    # echo "cat $i/*_1_ref2_mass8p511p5.txt | awk '{print $21}'"
    aa_1S_3p5_3p5_pt+=(`cat $i/*0100*_1_ref2_mass8p511p5.txt | awk '{print $21}'`)
done
( IFS=,; echo "float aa_1S_3p5_3p5_pt[nPtBins_2014] = {${aa_1S_3p5_3p5_pt[*]}};")
#
for i in ${txtDir_aa_3p5_4_pt[@]}
do
    # echo "cat $i/*_1_ref2_mass8p511p5.txt | awk '{print $21}'"
    aa_1S_3p5_4_pt+=(`cat $i/*0100*_1_ref2_mass8p511p5.txt | awk '{print $21}'`)
done
( IFS=,; echo "float aa_1S_3p5_4_pt[nPtBins_2014] = {${aa_1S_3p5_4_pt[*]}};")
#
for i in ${txtDir_aa_3p5_4p5_pt[@]}
do
#    echo "cat $i/*_1_ref2_mass8p511p5.txt | awk '{print \$21}'"
    aa_1S_3p5_4p5_pt+=(`cat $i/*0100*_1_ref2_mass8p511p5.txt | awk '{print $21}'`)
done
( IFS=,; echo "float aa_1S_3p5_4p5_pt[nPtBins_2014] = {${aa_1S_3p5_4p5_pt[*]}};")
#
for i in ${txtDir_aa_4_4_pt[@]}
do
#    echo "cat $i/*_1_ref2_mass8p511p5.txt | awk '{print \$21}'"
    aa_1S_4_4_pt+=(`cat $i/*0100*_1_ref2_mass8p511p5.txt | awk '{print $21}'`)
done
( IFS=,; echo "float aa_1S_4_4_pt[nPtBins_2014] = {${aa_1S_4_4_pt[*]}};")
#
for i in ${txtDir_aa_4_4p5_pt[@]}
do
#    echo "cat $i/*_1_ref2_mass8p511p5.txt | awk '{print \$21}'"
    aa_1S_4_4p5_pt+=(`cat $i/*0100*_1_ref2_mass8p511p5.txt | awk '{print $21}'`)
done
( IFS=,; echo "float aa_1S_4_4p5_pt[nPtBins_2014] = {${aa_1S_4_4p5_pt[*]}};")
#
for i in ${txtDir_aa_4p5_4p5_pt[@]}
do
#    echo "cat $i/*_1_ref2_mass8p511p5.txt | awk '{print \$21}'"
    aa_1S_4p5_4p5_pt+=(`cat $i/*0100*_1_ref2_mass8p511p5.txt | awk '{print $21}'`)
done
( IFS=,; echo "float aa_1S_4p5_4p5_pt[nPtBins_2014] = {${aa_1S_4p5_4p5_pt[*]}};")
## rap
for i in ${txtDir_aa_3p5_3p5_rap[@]}
do
    # echo "cat $i/*_1_ref2_mass8p511p5.txt | awk '{print $21}'"
    aa_1S_3p5_3p5_rap+=(`cat $i/*0100*_1_ref2_mass8p511p5.txt | awk '{print $21}'`)
done
( IFS=,; echo "float aa_1S_3p5_3p5_rap[nRapBins_2014] = {${aa_1S_3p5_3p5_rap[*]}};")
#
for i in ${txtDir_aa_3p5_4_rap[@]}
do
    # echo "cat $i/*_1_ref2_mass8p511p5.txt | awk '{print $21}'"
    aa_1S_3p5_4_rap+=(`cat $i/*0100*_1_ref2_mass8p511p5.txt | awk '{print $21}'`)
done
( IFS=,; echo "float aa_1S_3p5_4_rap[nRapBins_2014] = {${aa_1S_3p5_4_rap[*]}};")
#
for i in ${txtDir_aa_3p5_4p5_rap[@]}
do
#    echo "cat $i/*_1_ref2_mass8p511p5.txt | awk '{print \$21}'"
    aa_1S_3p5_4p5_rap+=(`cat $i/*0100*_1_ref2_mass8p511p5.txt | awk '{print $21}'`)
done
( IFS=,; echo "float aa_1S_3p5_4p5_rap[nRapBins_2014] = {${aa_1S_3p5_4p5_rap[*]}};")
#
for i in ${txtDir_aa_4_4_rap[@]}
do
#    echo "cat $i/*_1_ref2_mass8p511p5.txt | awk '{print \$21}'"
    aa_1S_4_4_rap+=(`cat $i/*0100*_1_ref2_mass8p511p5.txt | awk '{print $21}'`)
done
( IFS=,; echo "float aa_1S_4_4_rap[nRapBins_2014] = {${aa_1S_4_4_rap[*]}};")
#
for i in ${txtDir_aa_4_4p5_rap[@]}
do
#    echo "cat $i/*_1_ref2_mass8p511p5.txt | awk '{print \$21}'"
    aa_1S_4_4p5_rap+=(`cat $i/*0100*_1_ref2_mass8p511p5.txt | awk '{print $21}'`)
done
( IFS=,; echo "float aa_1S_4_4p5_rap[nRapBins_2014] = {${aa_1S_4_4p5_rap[*]}};")
#
for i in ${txtDir_aa_4p5_4p5_rap[@]}
do
#    echo "cat $i/*_1_ref2_mass8p511p5.txt | awk '{print \$21}'"
    aa_1S_4p5_4p5_rap+=(`cat $i/*0100*_1_ref2_mass8p511p5.txt | awk '{print $21}'`)
done
( IFS=,; echo "float aa_1S_4p5_4p5_rap[nRapBins_2014] = {${aa_1S_4p5_4p5_rap[*]}};")
## pp
# for i in ${txtDir_pp_3_3_pt[@]}
# do
# #    echo "cat $i/*_1_ref2_mass8p511p5.txt | awk '{print \$21}'"
#     pp_1S_3_3_pt+=(`cat $i/*0100*_1_ref2_mass8p511p5.txt | awk '{print $21}'`)
# done
# ( IFS=,; echo "float pp_1S_3_3_pt[nPtBins_2014] = {${pp_1S_3_3_pt[*]}};")
# #
# for i in ${txtDir_pp_3_3p5_pt[@]}
# do
# #    echo "cat $i/*_1_ref2_mass8p511p5.txt | awk '{print \$21}'"
#     pp_1S_3_3p5_pt+=(`cat $i/*0100*_1_ref2_mass8p511p5.txt | awk '{print $21}'`)
# done
# ( IFS=,; echo "float pp_1S_3_3p5_pt[nPtBins_2014] = {${pp_1S_3_3p5_pt[*]}};")
# #
# for i in ${txtDir_pp_3_4_pt[@]}
# do
# #    echo "cat $i/*_1_ref2_mass8p511p5.txt | awk '{print \$21}'"
#     pp_1S_3_4_pt+=(`cat $i/*0100*_1_ref2_mass8p511p5.txt | awk '{print $21}'`)
# done
# ( IFS=,; echo "float pp_1S_3_4_pt[nPtBins_2014] = {${pp_1S_3_4_pt[*]}};")
# #
# for i in ${txtDir_pp_3_4p5_pt[@]}
# do
# #    echo "cat $i/*_1_ref2_mass8p511p5.txt | awk '{print \$21}'"
#     pp_1S_3_4p5_pt+=(`cat $i/*0100*_1_ref2_mass8p511p5.txt | awk '{print $21}'`)
# done
# ( IFS=,; echo "float pp_1S_3_4p5_pt[nPtBins_2014] = {${pp_1S_3_4p5_pt[*]}};")
for i in ${txtDir_pp_3p5_3p5_pt[@]}
do
#    echo "cat $i/*_1_ref2_mass8p511p5.txt | awk '{print \$21}'"
    pp_1S_3p5_3p5_pt+=(`cat $i/*0100*_1_ref2_mass8p511p5.txt | awk '{print $21}'`)
done
( IFS=,; echo "float pp_1S_3p5_3p5_pt[nPtBins_2014] = {${pp_1S_3p5_3p5_pt[*]}};")
#
for i in ${txtDir_pp_3p5_4_pt[@]}
do
#    echo "cat $i/*_1_ref2_mass8p511p5.txt | awk '{print \$21}'"
    pp_1S_3p5_4_pt+=(`cat $i/*0100*_1_ref2_mass8p511p5.txt | awk '{print $21}'`)
done
( IFS=,; echo "float pp_1S_3p5_4_pt[nPtBins_2014] = {${pp_1S_3p5_4_pt[*]}};")
#
for i in ${txtDir_pp_3p5_4p5_pt[@]}
do
#    echo "cat $i/*_1_ref2_mass8p511p5.txt | awk '{print \$21}'"
    pp_1S_3p5_4p5_pt+=(`cat $i/*0100*_1_ref2_mass8p511p5.txt | awk '{print $21}'`)
done
( IFS=,; echo "float pp_1S_3p5_4p5_pt[nPtBins_2014] = {${pp_1S_3p5_4p5_pt[*]}};")
#
for i in ${txtDir_pp_4_4_pt[@]}
do
#     echo "cat $i/*_1_ref2_mass8p511p5.txt | awk '{print \$21}'"
    pp_1S_4_4_pt+=(`cat $i/*0100*_1_ref2_mass8p511p5.txt | awk '{print $21}'`)
done
( IFS=,; echo "float pp_1S_4_4_pt[nPtBins_2014] = {${pp_1S_4_4_pt[*]}};")
#
for i in ${txtDir_pp_4_4p5_pt[@]}
do
#    echo "cat $i/*_1_ref2_mass8p511p5.txt | awk '{print \$21}'"
     pp_1S_4_4p5_pt+=(`cat $i/*0100*_1_ref2_mass8p511p5.txt | awk '{print $21}'`)
done
( IFS=,; echo "float pp_1S_4_4p5_pt[nPtBins_2014] = {${pp_1S_4_4p5_pt[*]}};")
#
for i in ${txtDir_pp_4p5_4p5_pt[@]}
do
#    echo "cat $i/*_1_ref2_mass8p511p5.txt | awk '{print \$21}'"
    pp_1S_4p5_4p5_pt+=(`cat $i/*0100*_1_ref2_mass8p511p5.txt | awk '{print $21}'`)
done
( IFS=,; echo "float pp_1S_4p5_4p5_pt[nPtBins_2014] = {${pp_1S_4p5_4p5_pt[*]}};")
## rap
for i in ${txtDir_pp_3p5_3p5_rap[@]}
do
    # echo "cat $i/*_1_ref2_mass8p511p5.txt | awk '{print $21}'"
    pp_1S_3p5_3p5_rap+=(`cat $i/*0100*_1_ref2_mass8p511p5.txt | awk '{print $21}'`)
done
( IFS=,; echo "float pp_1S_3p5_3p5_rap[nRapBins_2014] = {${pp_1S_3p5_3p5_rap[*]}};")
#
for i in ${txtDir_pp_3p5_4_rap[@]}
do
    # echo "cat $i/*_1_ref2_mass8p511p5.txt | awk '{print $21}'"
    pp_1S_3p5_4_rap+=(`cat $i/*0100*_1_ref2_mass8p511p5.txt | awk '{print $21}'`)
done
( IFS=,; echo "float pp_1S_3p5_4_rap[nRapBins_2014] = {${pp_1S_3p5_4_rap[*]}};")
#
for i in ${txtDir_pp_3p5_4p5_rap[@]}
do
#    echo "cat $i/*_1_ref2_mass8p511p5.txt | awk '{print \$21}'"
    pp_1S_3p5_4p5_rap+=(`cat $i/*0100*_1_ref2_mass8p511p5.txt | awk '{print $21}'`)
done
( IFS=,; echo "float pp_1S_3p5_4p5_rap[nRapBins_2014] = {${pp_1S_3p5_4p5_rap[*]}};")
#
for i in ${txtDir_pp_4_4_rap[@]}
do
#    echo "cat $i/*_1_ref2_mass8p511p5.txt | awk '{print \$21}'"
    pp_1S_4_4_rap+=(`cat $i/*0100*_1_ref2_mass8p511p5.txt | awk '{print $21}'`)
done
( IFS=,; echo "float pp_1S_4_4_rap[nRapBins_2014] = {${pp_1S_4_4_rap[*]}};")
#
for i in ${txtDir_pp_4_4p5_rap[@]}
do
#    echo "cat $i/*_1_ref2_mass8p511p5.txt | awk '{print \$21}'"
    pp_1S_4_4p5_rap+=(`cat $i/*0100*_1_ref2_mass8p511p5.txt | awk '{print $21}'`)
done
( IFS=,; echo "float pp_1S_4_4p5_rap[nRapBins_2014] = {${pp_1S_4_4p5_rap[*]}};")
#
for i in ${txtDir_pp_4p5_4p5_rap[@]}
do
#    echo "cat $i/*_1_ref2_mass8p511p5.txt | awk '{print \$21}'"
    pp_1S_4p5_4p5_rap+=(`cat $i/*0100*_1_ref2_mass8p511p5.txt | awk '{print $21}'`)
done
( IFS=,; echo "float pp_1S_4p5_4p5_rap[nRapBins_2014] = {${pp_1S_4p5_4p5_rap[*]}};")
