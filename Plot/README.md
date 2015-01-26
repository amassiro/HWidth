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
    

    
Run nuisances scan:

    r00t DrawSystematicsVariation.C+\(0\)
    r00t DrawSystematicsVariation.C+\(1\)
    r00t DrawSystematicsVariation.C+\(2\)    
    
