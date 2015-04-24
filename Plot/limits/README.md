
Draw:

    r00t Toys.higgsCombineTest.MultiDimFit.0j.GammaAndRF.root
    limit->Draw("2*deltaNLL:CMS_zz4l_GGsm:RF","deltaNLL<10 && deltaNLL>0");
    
    limit->Draw("2*deltaNLL:R","deltaNLL<10 && deltaNLL>0");
 
    r00t DrawLimit.cxx

    
    r99t   tests/higgsCombineTest.MultiDimFit.2j.root \
           tests/Observed.higgsCombineTest.MultiDimFit.2j.root \
           drawExpObs.cxx    

    r99t   tests/Observed.higgsCombineTest.MultiDimFit.0j.root \
           tests/Observed.higgsCombineTest.MultiDimFit.1j.root \
           tests/Observed.higgsCombineTest.MultiDimFit.2j.root \
           tests/Observed.higgsCombineTest.MultiDimFit.012j.root \
           drawCombined.cxx
       
       
    scp amassiro@lxplus.cern.ch:/afs/cern.ch/user/a/amassiro/work/Latinos/Limit/CMSSW_6_1_1/src/LimitCombine/
    r00t tests2/Asimov.higgsCombineTest.MultiDimFit.0j.root  Draw3D.cxx
    r00t tests2/Asimov.higgsCombineTest.MultiDimFit.1j.root  Draw3D.cxx
    r00t tests2/Asimov.higgsCombineTest.MultiDimFit.2j.root  Draw3D.cxx
    r00t tests2/Observed.higgsCombineTest.MultiDimFit.0j.root  Draw3D.cxx
    r00t tests2/Observed.higgsCombineTest.MultiDimFit.1j.root  Draw3D.cxx
    r00t tests2/Observed.higgsCombineTest.MultiDimFit.2j.root  Draw3D.cxx
       
    r00t tests2/Asimov.higgsCombineTest.MultiDimFit.0j.root  Draw2D.cxx
    r00t tests2/Asimov.higgsCombineTest.MultiDimFit.1j.root  Draw2D.cxx
    r00t tests2/Asimov.higgsCombineTest.MultiDimFit.2j.root  Draw2D.cxx
    r00t tests2/Observed.higgsCombineTest.MultiDimFit.0j.root  Draw2D.cxx
    r00t tests2/Observed.higgsCombineTest.MultiDimFit.1j.root  Draw2D.cxx
    r00t tests2/Observed.higgsCombineTest.MultiDimFit.2j.root  Draw2D.cxx
    
    r00t tests2/Observed.higgsCombineTest.MultiDimFit.0j.rf.g.root  Draw2D.cxx
    r00t tests2/Observed.higgsCombineTest.MultiDimFit.1j.rf.g.root  Draw2D.cxx
    r00t tests2/Observed.higgsCombineTest.MultiDimFit.2j.rf.g.root  Draw2D.cxx
    
    r00t tests2/Asimov.higgsCombineTest.MultiDimFit.0j.RandG.root  Draw2D.cxx
    r00t tests2/Asimov.higgsCombineTest.MultiDimFit.1j.RandG.root  Draw2D.cxx
    r00t tests2/Asimov.higgsCombineTest.MultiDimFit.2j.RandG.root  Draw2D.cxx
    r00t tests2/Observed.higgsCombineTest.MultiDimFit.0j.RandG.root  Draw2D.cxx
    r00t tests2/Observed.higgsCombineTest.MultiDimFit.1j.RandG.root  Draw2D.cxx
    r00t tests2/Observed.higgsCombineTest.MultiDimFit.2j.RandG.root  Draw2D.cxx
    
    
    
copy:

    scp amassiro@lxplus.cern.ch:/afs/cern.ch/user/a/amassiro/work/Latinos/Limit/CMSSW_6_1_1/src/LimitCombine/Asimov.higgsCombineTest.MultiDimFit.*j.Gonly.root    tests3/
    scp amassiro@lxplus.cern.ch:/afs/cern.ch/user/a/amassiro/work/Latinos/Limit/CMSSW_6_1_1/src/LimitCombine/Observed.higgsCombineTest.MultiDimFit.*j.Gonly.root  tests3/
    scp amassiro@lxplus.cern.ch:/afs/cern.ch/user/a/amassiro/work/Latinos/Limit/CMSSW_6_1_1/src/LimitCombine/*.higgsCombineTest.MultiDimFit.*j.StandardModel.root  tests3/
    
run:

    r99t   tests3/Asimov.higgsCombineTest.MultiDimFit.0j.Gonly.root \
           tests3/Observed.higgsCombineTest.MultiDimFit.0j.Gonly.root \
           drawExpObs.cxx

    r99t   tests3/Asimov.higgsCombineTest.MultiDimFit.1j.Gonly.root \
           tests3/Observed.higgsCombineTest.MultiDimFit.1j.Gonly.root \
           drawExpObs.cxx

    r99t   tests3/Asimov.higgsCombineTest.MultiDimFit.2j.Gonly.root \
           tests3/Observed.higgsCombineTest.MultiDimFit.2j.Gonly.root \
           drawExpObs.cxx

    r99t   tests3/Asimov.higgsCombineTest.MultiDimFit.01j.Gonly.root \
           tests3/Observed.higgsCombineTest.MultiDimFit.01j.Gonly.root \
           drawExpObs.cxx
           
    r99t   tests3/Asimov.higgsCombineTest.MultiDimFit.012j.Gonly.root \
           tests3/Observed.higgsCombineTest.MultiDimFit.012j.Gonly.root \
           drawExpObs.cxx


           
           
    r99t   tests3/Asimov.higgsCombineTest.MultiDimFit.0j.StandardModel.root \
           tests3/Observed.higgsCombineTest.MultiDimFit.0j.StandardModel.root \
           drawExpObs.cxx

    r99t   tests3/Asimov.higgsCombineTest.MultiDimFit.1j.StandardModel.root \
           tests3/Observed.higgsCombineTest.MultiDimFit.1j.StandardModel.root \
           drawExpObs.cxx

    r99t   tests3/Asimov.higgsCombineTest.MultiDimFit.2j.StandardModel.root \
           tests3/Observed.higgsCombineTest.MultiDimFit.2j.StandardModel.root \
           drawExpObs.cxx

    r99t   tests3/Asimov.higgsCombineTest.MultiDimFit.01j.StandardModel.root \
           tests3/Observed.higgsCombineTest.MultiDimFit.01j.StandardModel.root \
           drawExpObs.cxx
           
    r99t   tests3/Asimov.higgsCombineTest.MultiDimFit.012j.StandardModel.root \
           tests3/Observed.higgsCombineTest.MultiDimFit.012j.StandardModel.root \
           drawExpObs.cxx
           
           
           
Where:

    /home/amassiro/Cern/Code/VBF/qqHWW/AnalysisPackage_qqHWWlnulnu/test/HWidth/Plot/limits


    