Training
====

source of root, needed for the GUI later

    source /afs/cern.ch/sw/lcg/app/releases/ROOT/5.34.00/x86_64-slc5-gcc46-opt/root/bin/thisroot.sh

Train:

ggH vs off-shell
    r99t Train.cxx\(\"BDTG\"\)

bkg vs off-shell
    r99t TrainBkg.cxx\(\"BDTG\"\)


Test:

    r99t TMVAGui.C\(\"TMVA.root\"\)




