
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
       
           
Where:

    /home/amassiro/Cern/Code/VBF/qqHWW/AnalysisPackage_qqHWWlnulnu/test/HWidth/Plot/limits


    