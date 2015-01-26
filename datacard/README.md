# Hwidth

Prepare

    /afs/cern.ch/user/a/amassiro/work/Latinos/Limit/datacards/HIG-14-032

    svn co  svn+ssh://amassiro@svn.cern.ch/reps/cmshcg/trunk/cadi/HIG-14-032/

    rm -rf 125/* 125/shapes/* 125.6/* 125.6/shapes/*

    mkdir 125
    mkdir 125/shapes/

    cp ../../CMSSW_6_1_1/src/LimitCombine/datacards-0j/shapes/*.root 125/shapes/
    cp ../../CMSSW_6_1_1/src/LimitCombine/datacards-1j/shapes/*.root 125/shapes/
    cp ../../CMSSW_6_1_1/src/LimitCombine/datacards-2j/shapes/*.root 125/shapes/

    cp ../../CMSSW_6_1_1/src/LimitCombine/datacards-0j-7TeV/shapes/*.root 125/shapes/
    cp ../../CMSSW_6_1_1/src/LimitCombine/datacards-1j-7TeV/shapes/*.root 125/shapes/
    cp ../../CMSSW_6_1_1/src/LimitCombine/datacards-2j-7TeV/shapes/*.root 125/shapes/

    cp ../../CMSSW_6_1_1/src/LimitCombine/datacards-0j/*.txt ./125/
    cp ../../CMSSW_6_1_1/src/LimitCombine/datacards-1j/*.txt ./125/
    cp ../../CMSSW_6_1_1/src/LimitCombine/datacards-2j/*.txt ./125/

    cp ../../CMSSW_6_1_1/src/LimitCombine/datacards-0j-7TeV/*.txt ./125/
    cp ../../CMSSW_6_1_1/src/LimitCombine/datacards-1j-7TeV/*.txt ./125/
    cp ../../CMSSW_6_1_1/src/LimitCombine/datacards-2j-7TeV/*.txt ./125/

    
    
from 125 to 125.6


    git clone https://github.com/amassiro/ModificationDatacards.git
    
    cd /afs/cern.ch/user/a/amassiro/work/Latinos/Limit/datacards/ModificationDatacards
    
    ls ../HIG-14-032/125/hww*19*.txt   | awk '{print "python ScaleOneSample.py  -d "$1"    -i examples/inputScale8TeV_125_125.6.py"}' | /bin/sh
    ls ../HIG-14-032/125/hww*4*.txt    | awk '{print "python ScaleOneSample.py  -d "$1"    -i examples/inputScale7TeV_125_125.6.py"}' | /bin/sh

    ## move the folder and copy back the original
    mv  ../HIG-14-032/125/  ../HIG-14-032/125.6/
    cd     /afs/cern.ch/user/a/amassiro/work/Latinos/Limit/datacards/HIG-14-032
    
    mkdir 125
    mkdir 125/shapes/

    cp ../../CMSSW_6_1_1/src/LimitCombine/datacards-0j/shapes/*.root 125/shapes/
    cp ../../CMSSW_6_1_1/src/LimitCombine/datacards-1j/shapes/*.root 125/shapes/
    cp ../../CMSSW_6_1_1/src/LimitCombine/datacards-2j/shapes/*.root 125/shapes/

    cp ../../CMSSW_6_1_1/src/LimitCombine/datacards-0j-7TeV/shapes/*.root 125/shapes/
    cp ../../CMSSW_6_1_1/src/LimitCombine/datacards-1j-7TeV/shapes/*.root 125/shapes/
    cp ../../CMSSW_6_1_1/src/LimitCombine/datacards-2j-7TeV/shapes/*.root 125/shapes/

    cp ../../CMSSW_6_1_1/src/LimitCombine/datacards-0j/*.txt ./125/
    cp ../../CMSSW_6_1_1/src/LimitCombine/datacards-1j/*.txt ./125/
    cp ../../CMSSW_6_1_1/src/LimitCombine/datacards-2j/*.txt ./125/

    cp ../../CMSSW_6_1_1/src/LimitCombine/datacards-0j-7TeV/*.txt ./125/
    cp ../../CMSSW_6_1_1/src/LimitCombine/datacards-1j-7TeV/*.txt ./125/
    cp ../../CMSSW_6_1_1/src/LimitCombine/datacards-2j-7TeV/*.txt ./125/

    
    
Combine and run:

    cd /afs/cern.ch/user/a/amassiro/work/Latinos/Limit/CMSSW_6_1_1/src/LimitCombine

    diff  /afs/cern.ch/user/a/amassiro/work/Latinos/Limit/datacards/HIG-14-032/125/hww-4.94fb.mH125.of_0j_shape.txt  /afs/cern.ch/user/a/amassiro/work/Latinos/Limit/datacards/HIG-14-032/125.6/hww-4.94fb.mH125.of_0j_shape.txt
    
    combineCards.py   of0j7TeV=/afs/cern.ch/user/a/amassiro/work/Latinos/Limit/datacards/HIG-14-032/125.6/hww-4.94fb.mH125.of_0j_shape.txt \
                  of1j7TeV=/afs/cern.ch/user/a/amassiro/work/Latinos/Limit/datacards/HIG-14-032/125.6/hww-4.94fb.mH125.of_1j_shape.txt \
                  of2j7TeV=/afs/cern.ch/user/a/amassiro/work/Latinos/Limit/datacards/HIG-14-032/125.6/hww-4.94fb.mH125.of_2j_shape.txt \
                  of0j=/afs/cern.ch/user/a/amassiro/work/Latinos/Limit/datacards/HIG-14-032/125.6/hww-19.36fb.mH125.of_0j_shape.txt \
                  of1j=/afs/cern.ch/user/a/amassiro/work/Latinos/Limit/datacards/HIG-14-032/125.6/hww-19.36fb.mH125.of_1j_shape.txt \
                  of2j=/afs/cern.ch/user/a/amassiro/work/Latinos/Limit/datacards/HIG-14-032/125.6/hww-19.36fb.mH125.of_2j_shape.txt \
                  >   hwidth_125.6.txt

    combineCards.py   of0j7TeV=/afs/cern.ch/user/a/amassiro/work/Latinos/Limit/datacards/HIG-14-032/125.6/hww-4.94fb.mH125.of_0j_shape.txt \
                  >   hwidth_125.6.txt

    combineCards.py   of0j7TeV=/afs/cern.ch/user/a/amassiro/work/Latinos/Limit/datacards/HIG-14-032/125/hww-4.94fb.mH125.of_0j_shape.txt \
                  >   hwidth_125.6.txt
              
    text2workspace.py -m 125.6 hwidth_125.6.txt -P LimitCombine.HiggsWidth.HiggsWidthStandalone:higgswidth  --PO=is2l2nu  -o      model_hwwlvlv_012j_7TeV_8TeV_125.6.root

    combine -M MultiDimFit model_hwwlvlv_012j_7TeV_8TeV_125.6.root  --algo=grid --points 120  -m 125.6   -t -1 --expectSignal=1 --saveToys                  --setPhysicsModelParameterRanges CMS_zz4l_GGsm=0.000001,60          --verbose -1
    mv higgsCombineTest.MultiDimFit.mH125.6.123456.root      higgsCombineTest.MultiDimFit.0j.7TeV.root


Combine and run tests:

    /afs/cern.ch/user/a/amassiro/work/Latinos/Limit/CMSSW_6_1_1/src/LimitCombine

    
    combineCards.py   of0j7TeV=datacards-0j-7TeV/hww-4.94fb.mH125.of_0j_shape.txt \
                  of1j7TeV=datacards-1j-7TeV/hww-4.94fb.mH125.of_1j_shape.txt \
                  of2j7TeV=datacards-2j-7TeV/hww-4.94fb.mH125.of_2j_shape.txt \
                  of0j=datacards-0j/hww-19.36fb.mH125.of_0j_shape.txt \
                  of1j=datacards-1j/hww-19.36fb.mH125.of_1j_shape.txt \
                  of2j=datacards-2j/hww-19.36fb.mH125.of_2j_shape.txt \
                  >   test.txt

    combineCards.py \
                  of0j=datacards-0j/hww-19.36fb.mH125.of_0j_shape.txt \
                  of1j=datacards-1j/hww-19.36fb.mH125.of_1j_shape.txt \
                  of2j=datacards-2j/hww-19.36fb.mH125.of_2j_shape.txt \
                  >   test.txt
                  
    combineCards.py   of1j=datacards-1j/hww-19.36fb.mH125.of_1j_shape.txt \
                  of2j=datacards-2j/hww-19.36fb.mH125.of_2j_shape.txt \
                  >   test.txt
                  
                  
    combineCards.py   of0j7TeV=datacards-0j-7TeV/hww-4.94fb.mH125.of_0j_shape.txt \
                  of1j7TeV=datacards-1j-7TeV/hww-4.94fb.mH125.of_1j_shape.txt \
                  of2j7TeV=datacards-2j-7TeV/hww-4.94fb.mH125.of_2j_shape.txt \
                  of0j=datacards-0j/hww-19.36fb.mH125.of_0j_shape.txt \
                  of2j=datacards-2j/hww-19.36fb.mH125.of_2j_shape.txt \
                  >   test.txt

    combineCards.py   of0j7TeV=datacards-0j-7TeV/hww-4.94fb.mH125.of_0j_shape.txt \
                  of1j7TeV=datacards-1j-7TeV/hww-4.94fb.mH125.of_1j_shape.txt \
                  of0j=datacards-0j/hww-19.36fb.mH125.of_0j_shape.txt \
                  of1j=datacards-1j/hww-19.36fb.mH125.of_1j_shape.txt \
                  of2j=datacards-2j/hww-19.36fb.mH125.of_2j_shape.txt \
                  >   test.txt
                  
    combineCards.py  \
                  of0j=datacards-0j/hww-19.36fb.mH125.of_0j_shape.txt \
                  of1j=datacards-1j/hww-19.36fb.mH125.of_1j_shape.txt \
                  of2j=datacards-2j/hww-19.36fb.mH125.of_2j_shape.txt \
                  >   test.txt                  

    combineCards.py  \
                  of0j=datacards-0j/hww-19.36fb.mH125.of_0j_shape.txt \
                  of1j=datacards-1j/hww-19.36fb.mH125.of_1j_shape.txt \
                  >   test.txt                  
                  
    combineCards.py  \
                  of0j=datacards-0j/hww-19.36fb.mH125.of_0j_shape.txt \
                  of2j=datacards-2j/hww-19.36fb.mH125.of_2j_shape.txt \
                  >   test.txt                  
 
    combineCards.py  \
                  of1j=datacards-1j/hww-19.36fb.mH125.of_1j_shape.txt \
                  of2j=datacards-2j/hww-19.36fb.mH125.of_2j_shape.txt \
                  >   test.txt                  
 
    combineCards.py   of1j7TeV=datacards-1j-7TeV/hww-4.94fb.mH125.of_1j_shape.txt \
                  of2j7TeV=datacards-2j-7TeV/hww-4.94fb.mH125.of_2j_shape.txt \
                  of1j=datacards-1j/hww-19.36fb.mH125.of_1j_shape.txt \
                  of2j=datacards-2j/hww-19.36fb.mH125.of_2j_shape.txt \
                  >   test.txt

    combineCards.py   of0j7TeV=datacards-0j-7TeV/hww-4.94fb.mH125.of_0j_shape.txt \
                  of2j7TeV=datacards-2j-7TeV/hww-4.94fb.mH125.of_2j_shape.txt \
                  of0j=datacards-0j/hww-19.36fb.mH125.of_0j_shape.txt \
                  of2j=datacards-2j/hww-19.36fb.mH125.of_2j_shape.txt \
                  >   test.txt
                  

    combineCards.py   of0j7TeV=datacards-0j-7TeV/hww-4.94fb.mH125.of_0j_shape.txt \
                  of1j7TeV=datacards-1j-7TeV/hww-4.94fb.mH125.of_1j_shape.txt \
                  of2j7TeV=datacards-2j-7TeV/hww-4.94fb.mH125.of_2j_shape.txt \
                  of0j=datacards-0j/hww-19.36fb.mH125.of_0j_shape.txt \
                  of1j=datacards-1j/hww-19.36fb.mH125.of_1j_shape.txt \
                  >   test.txt

    combineCards.py   of0j7TeV=datacards-0j-7TeV/hww-4.94fb.mH125.of_0j_shape.txt \
                  of1j7TeV=datacards-1j-7TeV/hww-4.94fb.mH125.of_1j_shape.txt \
                  of2j7TeV=datacards-2j-7TeV/hww-4.94fb.mH125.of_2j_shape.txt \
                  of0j=datacards-0j/hww-19.36fb.mH125.of_0j_shape.txt \
                  >   test.txt

    combineCards.py   of0j7TeV=datacards-0j-7TeV/hww-4.94fb.mH125.of_0j_shape.txt \
                  of1j7TeV=datacards-1j-7TeV/hww-4.94fb.mH125.of_1j_shape.txt \
                  of2j7TeV=datacards-2j-7TeV/hww-4.94fb.mH125.of_2j_shape.txt \
                  >   test.txt

    combineCards.py   of0j7TeV=datacards-0j-7TeV/hww-4.94fb.mH125.of_0j_shape.txt \
                  of1j7TeV=datacards-1j-7TeV/hww-4.94fb.mH125.of_1j_shape.txt \
                  of0j=datacards-0j/hww-19.36fb.mH125.of_0j_shape.txt \
                  of1j=datacards-1j/hww-19.36fb.mH125.of_1j_shape.txt \
                  >   test.txt

    combineCards.py   of0j=datacards-0j/hww-19.36fb.mH125.of_0j_shape.txt \
                  of1j=datacards-1j/hww-19.36fb.mH125.of_1j_shape.txt \
                  of2j=datacards-2j/hww-19.36fb.mH125.of_2j_shape.txt \
                  >   test.txt

    combineCards.py   of0j7TeV=datacards-0j-7TeV/hww-4.94fb.mH125.of_0j_shape.txt \
                  of1j7TeV=datacards-1j-7TeV/hww-4.94fb.mH125.of_1j_shape.txt \
                  of0j=datacards-0j/hww-19.36fb.mH125.of_0j_shape.txt \
                  of1j=datacards-1j/hww-19.36fb.mH125.of_1j_shape.txt \
                  of2j=datacards-2j/hww-19.36fb.mH125.of_2j_shape.txt \
                  >   test.txt

    combineCards.py   of1j7TeV=datacards-1j-7TeV/hww-4.94fb.mH125.of_1j_shape.txt \
                  of2j7TeV=datacards-2j-7TeV/hww-4.94fb.mH125.of_2j_shape.txt \
                  of1j=datacards-1j/hww-19.36fb.mH125.of_1j_shape.txt \
                  of2j=datacards-2j/hww-19.36fb.mH125.of_2j_shape.txt \
                  >   test.txt

    combineCards.py   of1j7TeV=datacards-1j-7TeV/hww-4.94fb.mH125.of_1j_shape.txt \
                  of1j=datacards-1j/hww-19.36fb.mH125.of_1j_shape.txt \
                  >   test.txt


    combineCards.py   of0j7TeV=datacards-0j-7TeV/hww-4.94fb.mH125.of_0j_shape.txt \
                  of0j=datacards-0j/hww-19.36fb.mH125.of_0j_shape.txt \
                  >   test.txt


    combineCards.py   of2j7TeV=datacards-2j-7TeV/hww-4.94fb.mH125.of_2j_shape.txt \
                  of2j=datacards-2j/hww-19.36fb.mH125.of_2j_shape.txt \
                  >   test.txt

    combineCards.py   of2j7TeV=datacards-2j-7TeV/hww-4.94fb.mH125.of_2j_shape.txt \
                  >   test.txt

    combineCards.py   of0j7TeV=datacards-0j-7TeV/hww-4.94fb.mH125.of_0j_shape.txt \
                  of1j7TeV=datacards-1j-7TeV/hww-4.94fb.mH125.of_1j_shape.txt \
                  of0j=datacards-0j/hww-19.36fb.mH125.of_0j_shape.txt \
                  of1j=datacards-1j/hww-19.36fb.mH125.of_1j_shape.txt \
                  >   test.txt

Run 
                  
    text2workspace.py -m 125.6 datacards-2j/hww-19.36fb.mH125.of_2j_shape.txt                              -P LimitCombine.HiggsWidth.HiggsWidthStandalone:higgswidth  --PO=is2l2nu  -o    test.root
    text2workspace.py -m 125.6 datacards-2j/test2j.txt                              -P LimitCombine.HiggsWidth.HiggsWidthStandalone:higgswidth  --PO=is2l2nu  -o    test.root


    text2workspace.py -m 125.6 test.txt                               -P LimitCombine.HiggsWidth.HiggsWidthStandalone:higgswidth  --PO=is2l2nu  -o    test.root

    text2workspace.py -m 125.6 datacards-2j/test2j.txt                              -P LimitCombine.HiggsWidth.HiggsWidthStandalone:higgswidth  --PO=is2l2nu  -o    test.root

    text2workspace.py -m 125.6 datacards-2j/test2j.txt   -o test.root

    text2workspace.py -m 125.6 test.txt                               -P LimitCombine.HiggsWidth.HiggsWidthStandalone:higgswidth  --PO=is2l2nu  -o    test.root
    combine -M MaxLikelihoodFit -t -1 --expectSignal 1  test.root
    python diffNuisances.py -a  mlfit.root -g plots.root   -p CMS_zz4l_GGsm
    
    
    python diffNuisances.py -a  mlfit.root -g plots.root   -p R
    


    sh RunCombineTest.sh


