
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
    scp amassiro@lxplus.cern.ch:/afs/cern.ch/user/a/amassiro/work/Latinos/Limit/CMSSW_6_1_1/src/LimitCombine/*.higgsCombineTest.MultiDimFit.*j.StandardModel.MuScan.root  tests3/
    scp amassiro@lxplus.cern.ch:/afs/cern.ch/user/a/amassiro/work/Latinos/Limit/CMSSW_6_1_1/src/LimitCombine/*.higgsCombineTest.MultiDimFit.*j.StandardModel.fineGrid.root  tests3/
    scp amassiro@lxplus.cern.ch:/afs/cern.ch/user/a/amassiro/work/Latinos/Limit/CMSSW_6_1_1/src/LimitCombine/Toys.higgsCombineTest.MultiDimFit.0j.StandardModel.root ./

    toys 0+1+2 jet 7+8 TeV
    scp amassiro@lxplus.cern.ch:/afs/cern.ch/user/a/amassiro/work/Latinos/Limit/CMSSW_6_1_1/src/LimitCombine/grid_7TeV-8TeV-toysScan.root ./
    scp amassiro@lxplus.cern.ch:/afs/cern.ch/user/a/amassiro/work/Latinos/Limit/CMSSW_6_1_1/src/LimitCombine/gridScan1_*.root  toys-0/


    
run:

    --- toys for coverage test ---
    Gamma = 1
    Gamma = 5
    Gamma = 10
    Gamma = 20
    
    r99t DrawLimit.cxx\(\"grid_7TeV-8TeV-toysScan.root\"\)
    
    r99t -q -b DrawLimit.cxx\(\"toys-0/gridScan1_10_1_32J.root\"\)
    mv newDelta.root newDelta.1.root
    r99t -q -b DrawLimit.cxx\(\"toys-0/gridScan1_1_1_t4d.root\"\)
    mv newDelta.root newDelta.2.root
    r99t -q -b DrawLimit.cxx\(\"toys-0/gridScan1_3_1_DpA.root\"\)
    mv newDelta.root newDelta.3.root
    r99t -q -b DrawLimit.cxx\(\"toys-0/gridScan1_6_1_L5b.root\"\)
    mv newDelta.root newDelta.4.root
    r99t -q -b DrawLimit.cxx\(\"toys-0/gridScan1_7_1_7cz.root\"\)
    mv newDelta.root newDelta.5.root
    
    rm newDelta.root
    hadd newDelta.root newDelta.*.root
    
    r99t newDelta.root
    DeltaAtDefault->Draw()
    DeltaAtDefault->Integral(-1,-1)
    DeltaAtDefault->Integral( DeltaAtDefault->GetXaxis()->FindBin(3.84) ,-1)
    DeltaAtDefault->Integral( DeltaAtDefault->GetXaxis()->FindBin(3.84) ,-1) / DeltaAtDefault->Integral(-1,-1)
    sqrt(DeltaAtDefault->Integral( DeltaAtDefault->GetXaxis()->FindBin(3.84) ,-1)) / DeltaAtDefault->Integral(-1,-1)
    
    value and +/- error

    r99t DrawDelta.cxx\(\"newDelta.root\"\)
    
    
    
    scp amassiro@lxplus.cern.ch:/afs/cern.ch/user/a/amassiro/work/Latinos/Limit/CMSSW_6_1_1/src/LimitCombine/gridScan2_*.root  toys-5/
    scp amassiro@lxplus.cern.ch:/afs/cern.ch/user/a/amassiro/work/Latinos/Limit/CMSSW_6_1_1/src/LimitCombine/gridScan3_*.root  toys-10/
    scp amassiro@lxplus.cern.ch:/afs/cern.ch/user/a/amassiro/work/Latinos/Limit/CMSSW_6_1_1/src/LimitCombine/gridScan4_*.root  toys-20/

    r99t -q -b DrawLimit.cxx\(\"toys-0/gridScan1_10_1_32J.root\",5\)
    r99t -q -b DrawLimit.cxx\(\"toys-0/gridScan1_10_1_32J.root\",10\)
    r99t -q -b DrawLimit.cxx\(\"toys-0/gridScan1_10_1_32J.root\",20\)


    
    r99t -q -b DrawLimit.cxx\(\"toys-5/gridScan2_10_1_xMJ.root\",5\)
    mv newDelta.root newDelta_5.1.root
    r99t -q -b DrawLimit.cxx\(\"toys-5/gridScan2_2_1_ygG.root\",5\)
    mv newDelta.root newDelta_5.2.root
    r99t -q -b DrawLimit.cxx\(\"toys-5/gridScan2_5_1_4zM.root\",5\)
    mv newDelta.root newDelta_5.3.root
    r99t -q -b DrawLimit.cxx\(\"toys-5/gridScan2_9_1_MHY.root\",5\)
    mv newDelta.root newDelta_5.4.root
    r99t -q -b DrawLimit.cxx\(\"toys-5/gridScan2_1_1_WzN.root\",5\)
    mv newDelta.root newDelta_5.5.root
    r99t -q -b DrawLimit.cxx\(\"toys-5/gridScan2_3_1_kAZ.root\",5\)
    mv newDelta.root newDelta_5.6.root
    r99t -q -b DrawLimit.cxx\(\"toys-5/gridScan2_8_1_e5M.root\",5\)
    mv newDelta.root newDelta_5.7.root
    
    rm newDelta_5.root
    hadd newDelta_5.root  newDelta_5.*.root
    r99t DrawDelta.cxx\(\"newDelta_5.root\"\)

    
    r99t -q -b DrawLimit.cxx\(\"toys-10/gridScan3_1_1_sCW.root\",10\)  
    mv newDelta.root newDelta_10.1.root
    r99t -q -b DrawLimit.cxx\(\"toys-10/gridScan3_3_1_U40.root\",10\)  
    mv newDelta.root newDelta_10.2.root
    r99t -q -b DrawLimit.cxx\(\"toys-10/gridScan3_6_1_VLL.root\",10\)  
    mv newDelta.root newDelta_10.3.root
    r99t -q -b DrawLimit.cxx\(\"toys-10/gridScan3_8_1_7Uf.root\",10\)
    mv newDelta.root newDelta_10.4.root
    r99t -q -b DrawLimit.cxx\(\"toys-10/gridScan3_2_1_Pi3.root\",10\)  
    mv newDelta.root newDelta_10.5.root
    r99t -q -b DrawLimit.cxx\(\"toys-10/gridScan3_4_1_Nif.root\",10\)  
    mv newDelta.root newDelta_10.6.root
    r99t -q -b DrawLimit.cxx\(\"toys-10/gridScan3_7_1_pdx.root\",10\)  
    mv newDelta.root newDelta_10.7.root
    r99t -q -b DrawLimit.cxx\(\"toys-10/gridScan3_9_1_5ws.root\",10\)
    mv newDelta.root newDelta_10.8.root
    
    rm  newDelta_10.root
    hadd newDelta_10.root  newDelta_10.*.root
    r99t DrawDelta.cxx\(\"newDelta_10.root\"\)

    
    r99t -q -b DrawLimit.cxx\(\"toys-20/gridScan4_10_1_YX3.root\",20\) 
    mv newDelta.root newDelta_20.1.root
    r99t -q -b DrawLimit.cxx\(\"toys-20/gridScan4_2_1_Gf5.root\",20\)  
    mv newDelta.root newDelta_20.2.root
    r99t -q -b DrawLimit.cxx\(\"toys-20/gridScan4_4_1_1Xa.root\",20\)  
    mv newDelta.root newDelta_20.3.root
    r99t -q -b DrawLimit.cxx\(\"toys-20/gridScan4_6_1_NpA.root\",20\)  
    mv newDelta.root newDelta_20.4.root
    r99t -q -b DrawLimit.cxx\(\"toys-20/gridScan4_9_1_dUf.root\",20\)
    mv newDelta.root newDelta_20.5.root
    r99t -q -b DrawLimit.cxx\(\"toys-20/gridScan4_1_1_AG1.root\",20\)   
    mv newDelta.root newDelta_20.6.root
    r99t -q -b DrawLimit.cxx\(\"toys-20/gridScan4_3_1_gBg.root\",20\)  
    mv newDelta.root newDelta_20.7.root
    r99t -q -b DrawLimit.cxx\(\"toys-20/gridScan4_5_1_SHQ.root\",20\)  
    mv newDelta.root newDelta_20.8.root
    r99t -q -b DrawLimit.cxx\(\"toys-20/gridScan4_7_1_gYc.root\",20\)
    mv newDelta.root newDelta_20.9.root
    
    rm newDelta_20.root
    hadd newDelta_20.root  newDelta_20.*.root
    r99t DrawDelta.cxx\(\"newDelta_20.root\"\)
    
    
    --- coverage test 2 ----
    
    
    r99t -q -b DrawLimitCoverage.cxx\(\"toys-0/gridScan1_10_1_32J.root\",15\)
    r99t -q -b DrawLimitCoverage.cxx\(\"toys-0/gridScan1_1_1_t4d.root\",15\)
    r99t -q -b DrawLimitCoverage.cxx\(\"toys-0/gridScan1_3_1_DpA.root\",15\)
    r99t -q -b DrawLimitCoverage.cxx\(\"toys-0/gridScan1_6_1_L5b.root\",15\)
    r99t -q -b DrawLimitCoverage.cxx\(\"toys-0/gridScan1_7_1_7cz.root\",15\)

    1 - 1.*(4+3+3+7+4) / (100*5) = 96%
 
    r99t -q -b DrawLimitCoverage.cxx\(\"toys-5/gridScan2_10_1_xMJ.root\",15\)
    r99t -q -b DrawLimitCoverage.cxx\(\"toys-5/gridScan2_2_1_ygG.root\",15\)
    r99t -q -b DrawLimitCoverage.cxx\(\"toys-5/gridScan2_5_1_4zM.root\",15\)
    r99t -q -b DrawLimitCoverage.cxx\(\"toys-5/gridScan2_9_1_MHY.root\",15\)
    r99t -q -b DrawLimitCoverage.cxx\(\"toys-5/gridScan2_1_1_WzN.root\",15\)
    r99t -q -b DrawLimitCoverage.cxx\(\"toys-5/gridScan2_3_1_kAZ.root\",15\)
    r99t -q -b DrawLimitCoverage.cxx\(\"toys-5/gridScan2_8_1_e5M.root\",15\)
    
    1.* (81 + 85 + 82 + 86 + 87 + 87 + 88) / (100 * 7) ~ 85%
    
    r99t -q -b DrawLimitCoverage.cxx\(\"toys-10/gridScan3_1_1_sCW.root\",15\) 
    r99t -q -b DrawLimitCoverage.cxx\(\"toys-10/gridScan3_3_1_U40.root\",15\) 
    r99t -q -b DrawLimitCoverage.cxx\(\"toys-10/gridScan3_6_1_VLL.root\",15\) 
    r99t -q -b DrawLimitCoverage.cxx\(\"toys-10/gridScan3_8_1_7Uf.root\",15\)
    r99t -q -b DrawLimitCoverage.cxx\(\"toys-10/gridScan3_2_1_Pi3.root\",15\) 
    r99t -q -b DrawLimitCoverage.cxx\(\"toys-10/gridScan3_4_1_Nif.root\",15\) 
    r99t -q -b DrawLimitCoverage.cxx\(\"toys-10/gridScan3_7_1_pdx.root\",15\) 
    r99t -q -b DrawLimitCoverage.cxx\(\"toys-10/gridScan3_9_1_5ws.root\",15\)

    1.* (63 + 59 + 63 + 56 + 62 + 55 + 63 + 63) / (100 * 8) ~ 61%
    
    r99t -q -b DrawLimitCoverage.cxx\(\"toys-20/gridScan4_10_1_YX3.root\",15\) 
    r99t -q -b DrawLimitCoverage.cxx\(\"toys-20/gridScan4_2_1_Gf5.root\",15\)  
    r99t -q -b DrawLimitCoverage.cxx\(\"toys-20/gridScan4_4_1_1Xa.root\",15\)  
    r99t -q -b DrawLimitCoverage.cxx\(\"toys-20/gridScan4_6_1_NpA.root\",15\)  
    r99t -q -b DrawLimitCoverage.cxx\(\"toys-20/gridScan4_9_1_dUf.root\",15\)
    r99t -q -b DrawLimitCoverage.cxx\(\"toys-20/gridScan4_1_1_AG1.root\",15\)   
    r99t -q -b DrawLimitCoverage.cxx\(\"toys-20/gridScan4_3_1_gBg.root\",15\)  
    r99t -q -b DrawLimitCoverage.cxx\(\"toys-20/gridScan4_5_1_SHQ.root\",15\)  
    r99t -q -b DrawLimitCoverage.cxx\(\"toys-20/gridScan4_7_1_gYc.root\",15\)

    1.* (22 + 10 + 12 + 7 +14 + 11 + 9 + 19) / (100 * 8) ~ 13%
    
    

    --- plots ---
    
    r99t DrawLimit.cxx\(\"toys-0/gridScan1_10_1_32J.root\"\)
    
    
    r99t DrawLimitDeltaDistribution.cxx\(\"toys-0/gridScan1_10_1_32J.root\"\)
    
    
    

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
           
           
           
    r99t   tests3/Asimov.higgsCombineTest.MultiDimFit.01j.StandardModel.fineGrid.root \
           tests3/Observed.higgsCombineTest.MultiDimFit.01j.StandardModel.fineGrid.root \
           drawExpObs.cxx
           
    r99t   tests3/Asimov.higgsCombineTest.MultiDimFit.012j.StandardModel.fineGrid.root \
           tests3/Observed.higgsCombineTest.MultiDimFit.012j.StandardModel.fineGrid.root \
           drawExpObs.cxx


           
    r99t   forPaper/Asimov.higgsCombineTest.MultiDimFit.012j.StandardModel-7TeV-8TeV.root \
           forPaper/Observed.higgsCombineTest.MultiDimFit.012j.StandardModel-7TeV-8TeV.magicOptions.root \
           drawExpObs.cxx
       
           

    scp amassiro@lxplus.cern.ch:/afs/cern.ch/user/a/amassiro/work/Latinos/Limit/CMSSW_6_1_1/src/LimitCombine/*.higgsCombineTest.MultiDimFit.012j.StandardModel-7TeV-8TeV.MuScan.root forPaper/       
    r99t   forPaper/Asimov.higgsCombineTest.MultiDimFit.012j.StandardModel-7TeV-8TeV.MuScan.root \
           forPaper/Observed.higgsCombineTest.MultiDimFit.012j.StandardModel-7TeV-8TeV.MuScan.root \
           drawExpObsMu.cxx
           
           
           
    r99t   tests3/Asimov.higgsCombineTest.MultiDimFit.0j.StandardModel.MuScan.root \
           tests3/Observed.higgsCombineTest.MultiDimFit.0j.StandardModel.MuScan.root \
           drawExpObsMu.cxx

    r99t   tests3/Asimov.higgsCombineTest.MultiDimFit.1j.StandardModel.MuScan.root \
           tests3/Observed.higgsCombineTest.MultiDimFit.1j.StandardModel.MuScan.root \
           drawExpObsMu.cxx

    r99t   tests3/Asimov.higgsCombineTest.MultiDimFit.2j.StandardModel.MuScan.root \
           tests3/Observed.higgsCombineTest.MultiDimFit.2j.StandardModel.MuScan.root \
           drawExpObsMu.cxx

    r99t   tests3/Asimov.higgsCombineTest.MultiDimFit.01j.StandardModel.MuScan.root \
           tests3/Observed.higgsCombineTest.MultiDimFit.01j.StandardModel.MuScan.root \
           drawExpObsMu.cxx
           
    r99t   tests3/Asimov.higgsCombineTest.MultiDimFit.012j.StandardModel.MuScan.root \
           tests3/Observed.higgsCombineTest.MultiDimFit.012j.StandardModel.MuScan.root \
           drawExpObsMu.cxx
           

           
           
    r99t  new*
    TH1F* one = (TH1F*) _file0->Get("TwoSigma")
    TH1F* two = (TH1F*) _file1->Get("TwoSigma")
    one -> Add (two)
    one->Draw()
           
           
           
    scp amassiro@lxplus.cern.ch:/afs/cern.ch/user/a/amassiro/work/Latinos/Limit/CMSSW_6_1_1/src/LimitCombine/*.higgsCombineTest.MultiDimFit.*j.StandardMod*.MuScan.root     forARC11May/       

    r99t   forARC11May/Asimov.higgsCombineTest.MultiDimFit.012j.StandardModel-8TeV.MuScan.root \
           forARC11May/Observed.higgsCombineTest.MultiDimFit.012j.StandardModel-8TeV.MuScan.root \
           drawExpObsMu.cxx\(2\)
          
    r99t   forARC11May/Asimov.higgsCombineTest.MultiDimFit.0j.StandardModel-8TeV.MuScan.root \
           forARC11May/Observed.higgsCombineTest.MultiDimFit.0j.StandardModel-8TeV.MuScan.root \
           drawExpObsMu.cxx\(2\)

    r99t   forARC11May/Asimov.higgsCombineTest.MultiDimFit.1j.StandardModel-8TeV.MuScan.root \
           forARC11May/Observed.higgsCombineTest.MultiDimFit.1j.StandardModel-8TeV.MuScan.root \
           drawExpObsMu.cxx\(2\)

    r99t   forARC11May/Asimov.higgsCombineTest.MultiDimFit.2j.StandardModel-8TeV.MuScan.root \
           forARC11May/Observed.higgsCombineTest.MultiDimFit.2j.StandardModel-8TeV.MuScan.root \
           drawExpObsMu.cxx\(2\)

    r99t   forARC11May/Asimov.higgsCombineTest.MultiDimFit.01j.StandardModel-8TeV.MuScan.root \
           forARC11May/Observed.higgsCombineTest.MultiDimFit.01j.StandardModel-8TeV.MuScan.root \
           drawExpObsMu.cxx\(2\)

    r99t   forARC11May/Asimov.higgsCombineTest.MultiDimFit.012j.StandardModel-7-8TeV.MuScan.root \
           forARC11May/Observed.higgsCombineTest.MultiDimFit.012j.StandardModel-7-8TeV.MuScan.root \
           drawExpObsMu.cxx\(1\)
           
    r99t   forARC11May/Asimov.higgsCombineTest.MultiDimFit.0j.StandardModel-7-8TeV.MuScan.root \
           forARC11May/Observed.higgsCombineTest.MultiDimFit.0j.StandardModel-7-8TeV.MuScan.root \
           drawExpObsMu.cxx\(1\)           

    r99t   forARC11May/Asimov.higgsCombineTest.MultiDimFit.1j.StandardModel-7-8TeV.MuScan.root \
           forARC11May/Observed.higgsCombineTest.MultiDimFit.1j.StandardModel-7-8TeV.MuScan.root \
           drawExpObsMu.cxx\(1\)           

    r99t   forARC11May/Asimov.higgsCombineTest.MultiDimFit.2j.StandardModel-7-8TeV.MuScan.root \
           forARC11May/Observed.higgsCombineTest.MultiDimFit.2j.StandardModel-7-8TeV.MuScan.root \
           drawExpObsMu.cxx\(1\)           


           
    ---- HWW paper ----
           
    r99t   forARC11May/Asimov.higgsCombineTest.MultiDimFit.012j.StandardModel-PaperHWW-8TeV.MuScan.root \
           forARC11May/Observed.higgsCombineTest.MultiDimFit.012j.StandardModel-PaperHWW-8TeV.MuScan.root \
           drawExpObsMu.cxx\(2\)
          
    r99t   forARC11May/Asimov.higgsCombineTest.MultiDimFit.0j.StandardModel-PaperHWW-8TeV.MuScan.root \
           forARC11May/Observed.higgsCombineTest.MultiDimFit.0j.StandardModel-PaperHWW-8TeV.MuScan.root \
           drawExpObsMu.cxx\(2\)

    r99t   forARC11May/Asimov.higgsCombineTest.MultiDimFit.1j.StandardModel-PaperHWW-8TeV.MuScan.root \
           forARC11May/Observed.higgsCombineTest.MultiDimFit.1j.StandardModel-PaperHWW-8TeV.MuScan.root \
           drawExpObsMu.cxx\(2\)

    r99t   forARC11May/Asimov.higgsCombineTest.MultiDimFit.2j.StandardModel-PaperHWW-8TeV.MuScan.root \
           forARC11May/Observed.higgsCombineTest.MultiDimFit.2j.StandardModel-PaperHWW-8TeV.MuScan.root \
           drawExpObsMu.cxx\(2\)

    r99t   forARC11May/Asimov.higgsCombineTest.MultiDimFit.01j.StandardModel-PaperHWW-8TeV.MuScan.root \
           forARC11May/Observed.higgsCombineTest.MultiDimFit.01j.StandardModel-PaperHWW-8TeV.MuScan.root \
           drawExpObsMu.cxx\(2\)

    r99t   forARC11May/Asimov.higgsCombineTest.MultiDimFit.012j.StandardModel-PaperHWW-7-8TeV.MuScan.root \
           forARC11May/Observed.higgsCombineTest.MultiDimFit.012j.StandardModel-PaperHWW-7-8TeV.MuScan.root \
           drawExpObsMu.cxx\(1\)
           
    r99t   forARC11May/Asimov.higgsCombineTest.MultiDimFit.0j.StandardModel-PaperHWW-7-8TeV.MuScan.root \
           forARC11May/Observed.higgsCombineTest.MultiDimFit.0j.StandardModel-PaperHWW-7-8TeV.MuScan.root \
           drawExpObsMu.cxx\(1\)           

    r99t   forARC11May/Asimov.higgsCombineTest.MultiDimFit.1j.StandardModel-PaperHWW-7-8TeV.MuScan.root \
           forARC11May/Observed.higgsCombineTest.MultiDimFit.1j.StandardModel-PaperHWW-7-8TeV.MuScan.root \
           drawExpObsMu.cxx\(1\)           

    r99t   forARC11May/Asimov.higgsCombineTest.MultiDimFit.2j.StandardModel-PaperHWW-7-8TeV.MuScan.root \
           forARC11May/Observed.higgsCombineTest.MultiDimFit.2j.StandardModel-PaperHWW-7-8TeV.MuScan.root \
           drawExpObsMu.cxx\(1\)           
           
           
           
Where:

    /home/amassiro/Cern/Code/VBF/qqHWW/AnalysisPackage_qqHWWlnulnu/test/HWidth/Plot/limits



    
    
    
    
    