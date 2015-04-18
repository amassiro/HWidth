Plot
====

propaganda plot for shape analysis
    
    scp amassiro@cmsneu.cern.ch:/home/amassiro/Latinos/Shape/playground/Hwidth/?jetDF?TeV/postFit/Hwidth-*-erro*.root    postFit/
    scp amassiro@lxplus0139.cern.ch:/tmp/amassiro/postFit/Hwidth-*-erro*.root    postFit/
 
 
 
    r00t Plot_AM_HWidth_Propaganda.C+


Copy and plot:
    
    scp amassiro@cmsneu.cern.ch:/home/amassiro/Latinos/Shape/playground/Hwidth/?jetDF8TeV/postFit/Hwidth-*-erro*.root    postFit/ 
    scp amassiro@cmsneu.cern.ch:/home/amassiro/Latinos/Shape/playground/Hwidth/*jetDF8TeV/postFit/Hwidth-*-erro*.root    postFit/ 
    scp amassiro@cmsneu.cern.ch:/home/amassiro/Latinos/Shape/playground/Hwidth/?jetDF8TeVSimple/postFit/Hwidth-*-erro*.root    postFitSimple/ 

    scp amassiro@cmsneu.cern.ch:/home/amassiro/Latinos/Shape/playground/Hwidth/?jetDF7TeVSimple/postFit/Hwidth-*-erro*.root    postFit7TeV/ 
    
    r00t Plot_AM_HWidth_unroll_Propaganda.C+
    r00t Plot_AM_HWidth_unroll_Propaganda.C+\(0\)
    r00t Plot_AM_HWidth_unroll_Propaganda.C+\(0,0,1\)
    r00t Plot_AM_HWidth_unroll_Propaganda.C+\(0,1,1\)
     
     
      which, int energy = 0, int doWeight = 0
    //---- WW control region
    scp amassiro@cmsneu.cern.ch:/home/amassiro/Latinos/Shape/playground/Hwidth/0jetDF8TeVWWcontrolRegion/postFit/Hwidth-*-erro*.root   postFit-WW/
    r00t Plot_AM_HWidth_unroll_Propaganda.C+\(8,0,0\)

    scp amassiro@cmsneu.cern.ch:/home/amassiro/Latinos/Shape/playground/Hwidth/0jetDF8TeVWWcontrolRegionDphill/postFit/Hwidth-*-erro*.root   postFit-WW-dphill/
    r00t Plot_AM_HWidth_unroll_Propaganda.C+\(9,0,0\)

    scp amassiro@cmsneu.cern.ch:/home/amassiro/Latinos/Shape/playground/Hwidth/0jetDF8TeVWWcontrolRegionDphillHighMllRemoved/postFit/Hwidth-*-erro*.root   postFit-WW-dphill-lowmll/
    r00t Plot_AM_HWidth_unroll_Propaganda.C+\(10,0,0\)


    scp amassiro@cmsneu.cern.ch:/home/amassiro/Latinos/Shape/playground/Hwidth/0jetDF8TeV/postFit/Hwidth-*-erro*.root   postFit-HWW-withWeights/
    r00t Plot_AM_HWidth_unroll_Propaganda.C+\(11,0,0\)

    
    scp amassiro@cmsneu.cern.ch:/home/amassiro/Latinos/Shape/playground/Hwidth/0jetDF8TeVWWfixed/postFit/Hwidth-*-erro*.root   postFit-HWW-wwfix/
    r00t Plot_AM_HWidth_unroll_Propaganda.C+\(12,0,0\)

    
    
      
Where:

    /home/amassiro/Cern/Code/VBF/qqHWW/AnalysisPackage_qqHWWlnulnu/test/HWidth/Plot



Prepare for AN: 
 
8 TeV:

    r99t -l -q PrepareForAN.C+\(0,0,0\)
    r99t -l -q PrepareForAN.C+\(0,0,1\)
    r99t -l -q PrepareForAN.C+\(0,0,2\)
    
    r99t -l -q PrepareForAN.C+\(2,0,0\)
    r99t -l -q PrepareForAN.C+\(2,0,1\)
    r99t -l -q PrepareForAN.C+\(2,0,2\)
    
    r99t -l -q PrepareForAN.C+\(3,0,0\)
    r99t -l -q PrepareForAN.C+\(3,0,1\)
    r99t -l -q PrepareForAN.C+\(3,0,2\)
    
    r99t -l -q PrepareForAN.C+\(4,0,0,0,0.01\)
    r99t -l -q PrepareForAN.C+\(4,0,0,0,0.05\)
    r99t -l -q PrepareForAN.C+\(4,0,0,0,0.1\)
    r99t -l -q PrepareForAN.C+\(4,0,0,0,0.2\)
    r99t -l -q PrepareForAN.C+\(4,0,0,0,0.3\)
    r99t -l -q PrepareForAN.C+\(4,0,0,0,0.4\)
    r99t -l -q PrepareForAN.C+\(4,0,0,0,0.5\)
    r99t -l -q PrepareForAN.C+\(4,0,0,0,1\)
    r99t -l -q PrepareForAN.C+\(4,0,0,0,2\)
    r99t -l -q PrepareForAN.C+\(4,0,0,0,3\)
    r99t -l -q PrepareForAN.C+\(4,0,0,0,5\)
    r99t -l -q PrepareForAN.C+\(4,0,0,0,7\)
    r99t -l -q PrepareForAN.C+\(4,0,0,0,10\)
    r99t -l -q PrepareForAN.C+\(4,0,0,0,20\)
    
    
    r99t -l -q PrepareForAN.C+\(4,0,0\)
    r99t -l -q PrepareForAN.C+\(4,0,1\)
    r99t -l -q PrepareForAN.C+\(4,0,2\)
    
    r99t -l -q PrepareForAN.C+\(6,0,0\)
    r99t -l -q PrepareForAN.C+\(6,0,1\)
    r99t -l -q PrepareForAN.C+\(6,0,2\)

7 TeV:

    r99t -l -q PrepareForAN.C+\(0,1,0\)
    r99t -l -q PrepareForAN.C+\(0,1,1\)
    r99t -l -q PrepareForAN.C+\(0,1,2\)
    
    r99t -l -q PrepareForAN.C+\(2,1,0\)
    r99t -l -q PrepareForAN.C+\(2,1,1\)
    r99t -l -q PrepareForAN.C+\(2,1,2\)
    
    r99t -l -q PrepareForAN.C+\(3,1,0\)
    r99t -l -q PrepareForAN.C+\(3,1,1\)
    r99t -l -q PrepareForAN.C+\(3,1,2\)
    

Then move here to prepare the final plots:

    /home/amassiro/Cern/Code/VBF/LatinoPlotTools/WW
    
Run nuisances scan:

    r00t DrawSystematicsVariation.C+\(0\)
    r00t DrawSystematicsVariation.C+\(1\)
    r00t DrawSystematicsVariation.C+\(2\)    
    
    
Plot:

    r00t DrawNjet.cxx
    r00t DrawSignalComposition.cxx
    
    r00t DrawSignalCompositionOnPeak.cxx

    r00t DrawNjet2.cxx
       -> for central jet veto efficiency

    r00t DrawOffShell.cxx
       -> to check off-shell contribution vs Higgs width
       
       
For limit scan:
    
    cd limits
    
    
    
