# for the list of used tags please see:
# https://twiki.cern.ch/twiki/bin/view/CMS/Onia2MuMuSamples

import FWCore.ParameterSet.Config as cms

# set up process
process = cms.Process("Onia2MuMuPAT")

# setup 'analysis'  options
#options = VarParsing.VarParsing ('analysis')

# setup any defaults you want
# root://xrootd.unl.edu
#options.inputFiles = '/store/himc/HiWinter13/PYTHIA6_Upsilon1SWithFSR_tuneD6T_2TeV76/GEN-SIM-RECO/STARTHI53_V26-v1/20000/04AE8671-B278-E211-94FA-008CFA001B18.root'
#options.outputFile = 'onia2MuMuPAT_MC_td.root'

#options.maxEvents = -1 # -1 means all events

# get and parse the command line arguments
#options.parseArguments()

process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load("Configuration.StandardSequences.Reconstruction_cff")
process.load("Configuration.StandardSequences.MagneticField_cff")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
process.GlobalTag.globaltag = 'STARTHI53_V28::All'

# Common offline event selection
process.load("HeavyIonsAnalysis.Configuration.collisionEventSelection_cff")

# pile up rejection
process.load('Appeltel.RpPbAnalysis.PAPileUpVertexFilter_cff')

# Centrality for pPb
process.load('RecoHI.HiCentralityAlgos.HiCentrality_cfi')

# HLT dimuon trigger
import HLTrigger.HLTfilters.hltHighLevel_cfi
process.hltOniaHI = HLTrigger.HLTfilters.hltHighLevel_cfi.hltHighLevel.clone()
process.hltOniaHI.HLTPaths = ["HLT_PAL1DoubleMuOpen_v*",
                              "HLT_PAL1DoubleMu0_HighQ_v*",
                              "HLT_PAL2DoubleMu3_v*",
                              "HLT_PAMu3_v*",
                              "HLT_PAMu7_v*",
                              "HLT_PAMu12_v*"
                              ]
process.hltOniaHI.throw = False
process.hltOniaHI.andOr = True
process.hltOniaHI.TriggerResultsTag = cms.InputTag("TriggerResults","","HLT")

from HiSkim.HiOnia2MuMu.onia2MuMuPAT_cff import *
onia2MuMuPAT(process, GlobalTag=process.GlobalTag.globaltag, MC=True, HLT="HLT", Filter=True)

process.patMuonSequence = cms.Sequence(
    process.hltOniaHI *
#    process.PAcollisionEventSelection *
#    process.pileupVertexFilterCutGplus * 
    process.genMuons *
    process.patMuonsWithTriggerSequence
    )



#process.onia2MuMuPatTrkTrk.addMuonlessPrimaryVertex = False
process.onia2MuMuPatGlbGlb.addMuonlessPrimaryVertex = False
#process.onia2MuMuPatTrkTrk.resolvePileUpAmbiguity = False



process.source.duplicateCheckMode = cms.untracked.string('noDuplicateCheck')
process.source.fileNames = cms.untracked.vstring(
    '/store/himc/HiWinter13/PYTHIA6_Upsilon1SWithFSR_tuneD6T_2TeV76/GEN-SIM-RECO/STARTHI53_V28-v1/00000/048C7532-0245-E311-B328-008CFA00879C.root'
    )

# filter on lumisections
#from HiSkim.HiOnia2MuMu.goodLumiSectionListHI_cfi import *
#process.source.lumisToProcess = goodLumisToProcess

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
process.outOnia2MuMu.fileName = cms.untracked.string( 'onia2MuMuPAT_MC_pythia1S.root' )

process.e = cms.EndPath(process.outOnia2MuMu)

process.schedule = cms.Schedule(process.Onia2MuMuPAT,
                                process.e)
