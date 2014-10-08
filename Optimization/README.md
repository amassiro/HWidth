Training
====

source of root, needed for the GUI later

    cmsenv of a CMSSW release  CMSSW_5_3_11_patch6
    source /afs/cern.ch/sw/lcg/app/releases/ROOT/5.34.21/x86_64-slc5-gcc47-opt/root/bin/thisroot.sh

Train:

ggH vs off-shell
    r99t Train.cxx\(\"BDTG\"\)

bkg vs off-shell
    r99t TrainBkg.cxx\(\"BDTG\"\)


Test:

    r99t TMVAGui.C\(\"TMVA.root\"\)






where:

    cmsneu
    /home/amassiro/Latinos/ForGammaHiggsWW/HWidth/Optimization

