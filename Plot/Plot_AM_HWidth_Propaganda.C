#include "TString.h"
#include "TH1F.h"
#include "TSystem.h"
#include "TInterpreter.h"
#include "TFile.h"

#include "PlotVHqqHggH.C"



//---- Filter bins ----
TH1F* FilterBins(std::vector<int> binsToSelect, TH1F* inputTH) {
 int numbin = binsToSelect.size();
 
 TString name = Form ("%s_new",inputTH->GetName());
 TString title = Form ("%s",inputTH->GetTitle());
 
 TH1F* newTH = new TH1F (name,title,numbin,0,numbin);
 for (int i=0; i< binsToSelect.size(); i++) {
  newTH->SetBinContent (i+1, inputTH->GetBinContent(binsToSelect.at(i)));
  newTH->SetBinError   (i+1, inputTH->GetBinError(binsToSelect.at(i)));
 }
 
 return newTH;
}

TGraphAsymmErrors* FilterBins(std::vector<int> binsToSelect, TGraphAsymmErrors* inputGR) {
 int numbin = binsToSelect.size();
 
 TString name = Form ("%s_new",inputGR->GetName());
 TString title = Form ("%s",inputGR->GetTitle());
 
 TGraphAsymmErrors* newGR = new TGraphAsymmErrors();
 newGR -> SetName (name);
 
 for (int i=0; i< binsToSelect.size(); i++) {
  
  double X = i+0.5;
  double Y = (inputGR->GetY()) [binsToSelect.at(i)-1];
  
  double errXUp      = inputGR->GetErrorXhigh(binsToSelect.at(i)-1);
  double errXDown    = inputGR->GetErrorXlow(binsToSelect.at(i)-1);
  double errYUp      = inputGR->GetErrorYhigh(binsToSelect.at(i)-1);
  double errYDown    = inputGR->GetErrorYlow(binsToSelect.at(i)-1);
  
  newGR->SetPoint(i, X, Y);
  newGR->SetPointError(i, errXDown, errXUp, errYDown, errYUp);
  
  //     std::cout << " i = " << i << " X = " << X << " Y = " << Y << std::endl;
 }
 
 return newGR;
}



void Plot_AM_HWidth_Propaganda() {
 
 int which = 0;
//  int which = 1;
 
 
 TString nameChannel;
 if   (which == 0)        { nameChannel = Form ("of_0j/"); }       //---- signal injection
 else if (which == 1)     { nameChannel = Form ("of_2jtche05/"); }

 std::cout << " which = " << which << std::endl;
 
 
//  TString folder = Form("sig/");
//  TString cutNameBefore = Form("sig/%shisto_",nameChannel.Data());

 TString folder = Form("init/");
 TString cutNameBefore = Form("init/%shisto_",nameChannel.Data());

 std::cout << " nameChannel   = " << nameChannel.Data() << std::endl;
 std::cout << " cutNameBefore = " << cutNameBefore.Data() << std::endl;
 
 //  TString folder = Form("bkg/");
 //  TString nameChannel = Form ("of_vh2j/");
 //  TString cutNameBefore = Form("bkg/%shisto_",nameChannel.Data());
 
 
 //                            cut_variable 
 TString cutNameAfter  = Form("");
 
 gROOT->LoadMacro("PlotVHqqHggH.C+");
 gInterpreter->ExecuteMacro("LatinoStyle2.C");
 
 TCanvas* c1 = new TCanvas("mll","mll",550,660);

 TFile* f[10];
 bool doSignalInjection;
  
 
 if      (which == 0)   { f[0] = new TFile("postFit/Hwidth-0j-of-error-signalInjection.root");  doSignalInjection = true; }
 else if (which == 1)   { f[0] = new TFile("postFit-WW2jewk-05/Hwidth-error-data.root");  doSignalInjection = false; }
 
 PlotVHqqHggH* hs = new PlotVHqqHggH();
 
 hs->setLabel("mll*");
 
 //  hs->setLumi(20);
 //  hs->setLumi(200);
 //  hs->addLabel("#splitline{      WHSC}{     #sqrt{s} = 13 TeV}");
  
 hs->setLumi(19.4);
 hs->addLabel("#splitline{     Hwidth}{     #sqrt{s} = 8 TeV}");
//  
 TString name;
 
 std::vector<int> vectColourBkg;        
 std::vector<double> vectSystBkg;       
 std::vector<double> vectScaleBkg;      
 std::vector<std::string> vectNameBkg;  
 std::vector<double> vectNormalizationBkg; 
 std::vector<TH1F*> vectTHBkg;          
 
 std::vector<int> vectColourSig;      
 std::vector<double> vectSystSig;       
 std::vector<double> vectScaleSig;      
 std::vector<std::string> vectNameSig;  
 std::vector<double> vectNormalizationSig; 
 std::vector<TH1F*> vectTHSig;          
 
 
 std::vector<int> binsToSelect; 
 
//  int NMAXX = 30;  //---- variable bin
 int NMAXX = 16;  //---- variable bin
 int NMAXY = 6;  
 
 int minNY = 0;
 int minNX = 0;
 
 //---- all ----
 int NX = NMAXX;
 int NY = NMAXY;
 
 
 
 for (int iFile = 0; iFile<1; iFile++) {
  
  std::cout << "iFile = " << iFile << std::endl;
  
  ///---- project along X : sum over Y
  for (int iY=minNY; iY<NY; iY++){
   binsToSelect.clear();
   for (int iX=minNX; iX<NX; iX++){
    binsToSelect.push_back (iX*NMAXY+iY+1);
    std::cout << " iX*NY+iY+1 = " << iX*NY+iY+1 << std::endl;
   }
   
   ///==== signal (begin) ====
   int WHEREAMI = 0;
   std::cout << "I'm here: " << WHEREAMI << std::endl; WHEREAMI++;
      
   int GammaOverGammaSM = 5;
   TString nameSignal   = Form("H off x%d", GammaOverGammaSM);
   TString nameSignalOn = Form("H on  x%d", GammaOverGammaSM);
   
   
   
//    name = Form("%sqqH%s",cutNameBefore.Data(),cutNameAfter.Data());
//    vectTHSig.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
//    vectNameSig.push_back ("H m_{H}=125");
//    vectColourSig.push_back(6);
//    vectSystSig.push_back(0.00);
//    vectScaleSig.push_back(1.0000);
// //    vectNormalizationSig.push_back(2.565);
//    std::cout << "I'm here: " << WHEREAMI << std::endl; WHEREAMI++;
   
   name = Form("%sggH_sbi%s",cutNameBefore.Data(),cutNameAfter.Data());
   vectTHSig.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
   vectNameSig.push_back (nameSignal.Data());
   vectColourSig.push_back(7);
   vectSystSig.push_back(0.00);
   vectScaleSig.push_back(1.0000*sqrt(GammaOverGammaSM));
   //    vectNormalizationSig.push_back(0.719);  
   std::cout << "I'm here: " << WHEREAMI << std::endl; WHEREAMI++;

   name = Form("%sggH_b%s",cutNameBefore.Data(),cutNameAfter.Data());
   vectTHSig.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
   vectNameSig.push_back (nameSignal.Data());
   vectColourSig.push_back(7);
   vectSystSig.push_back(0.00);
   vectScaleSig.push_back(-1.0000*sqrt(GammaOverGammaSM));
   //    vectNormalizationSig.push_back(0.719);  
   std::cout << "I'm here: " << WHEREAMI << std::endl; WHEREAMI++;

   name = Form("%sggH_s%s",cutNameBefore.Data(),cutNameAfter.Data());
   vectTHSig.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
   vectNameSig.push_back (nameSignal.Data());
   vectColourSig.push_back(7);
   vectSystSig.push_back(0.00);
   vectScaleSig.push_back(-1.0000*sqrt(GammaOverGammaSM));
   //    vectNormalizationSig.push_back(0.719);  
   std::cout << "I'm here: " << WHEREAMI << std::endl; WHEREAMI++;
   
  
   
   name = Form("%sggH_s%s",cutNameBefore.Data(),cutNameAfter.Data());
   vectTHSig.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
   vectNameSig.push_back (nameSignal.Data());
   vectColourSig.push_back(7);
   vectSystSig.push_back(0.00);
   vectScaleSig.push_back(1.0000*GammaOverGammaSM);
   //    vectNormalizationSig.push_back(0.719);  
   std::cout << "I'm here: " << WHEREAMI << std::endl; WHEREAMI++;
      
   
   
   ///==== signal (end)  ====
   
   
   
   ///==== background (begin)  ====
   
     
   name = Form("%sVV%s",cutNameBefore.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
   vectNameBkg.push_back ("WZ/ZZ/VVV");
   vectColourBkg.push_back(858);
   vectSystBkg.push_back(0.00);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(0.281);
   std::cout << "I'm here: " << WHEREAMI << std::endl; WHEREAMI++;
   
   name = Form("%sVVV%s",cutNameBefore.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
   vectNameBkg.push_back ("WZ/ZZ/VVV");
   vectColourBkg.push_back(858);
   vectSystBkg.push_back(0.00);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(0.281);
   
   name = Form("%sWJet%s",cutNameBefore.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
   vectNameBkg.push_back ("W+jets");
   vectColourBkg.push_back(921);
   vectSystBkg.push_back(0.00);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(0.667);
   
   name = Form("%sVg%s",cutNameBefore.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
   vectNameBkg.push_back ("V+#gamma/V+#gamma*");
   vectColourBkg.push_back(616+1);
   vectSystBkg.push_back(0.00);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(1.000);
   
   name = Form("%sVgS%s",cutNameBefore.Data(),cutNameAfter.Data());
   if (f[iFile]->GetListOfKeys()->Contains(name)) {
    vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
    vectNameBkg.push_back ("V+#gamma/V+#gamma*");
    vectColourBkg.push_back(616+2);
    vectSystBkg.push_back(0.00);
    vectScaleBkg.push_back(1.0000);
    vectNormalizationBkg.push_back(1.000);
   }
   
   name = Form("%sTop%s",cutNameBefore.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
   vectNameBkg.push_back ("Top");
   vectColourBkg.push_back(400);
   vectSystBkg.push_back(0.10);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(5.654);

   
   name = Form("%sDYTT%s",cutNameBefore.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
   vectNameBkg.push_back ("DYTT");
   vectColourBkg.push_back(418);
   vectSystBkg.push_back(0.00);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(0.377);
   
   name = Form("%sWW%s",cutNameBefore.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
   vectNameBkg.push_back ("WW");
   vectColourBkg.push_back(851);
   vectSystBkg.push_back(0.00);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(2.256);
   
//    name = Form("%sggWW%s",cutNameBefore.Data(),cutNameAfter.Data());
//    if (f[iFile]->GetListOfKeys()->Contains(name)) {
//     vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
//     vectNameBkg.push_back ("WW");
//     vectColourBkg.push_back(853);
//     vectSystBkg.push_back(0.00);
//     vectScaleBkg.push_back(1.0000);
//     vectNormalizationBkg.push_back(2.256);
//    }
   
   
   name = Form("%sggH_b%s",cutNameBefore.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
   vectNameBkg.push_back ("ggWW");
   vectColourBkg.push_back(8);
   vectSystBkg.push_back(0.00);
   vectScaleBkg.push_back(1.0000);
   //    vectNormalizationBkg.push_back(0.719);  
   std::cout << "I'm here: " << WHEREAMI << std::endl; WHEREAMI++;
   
   
   
   
   name = Form("%sggH%s",cutNameBefore.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
   vectNameBkg.push_back (nameSignalOn.Data());
//    vectNameBkg.push_back ("H m_{H}=125 ");
   vectColourBkg.push_back(6);
   vectSystBkg.push_back(0.00);
   vectScaleBkg.push_back(1.0000);
//    vectScaleBkg.push_back(1.0000*sqrt(GammaOverGammaSM));
   //    vectNormalizationBkg.push_back(0.719);  
   std::cout << "I'm here: " << WHEREAMI << std::endl; WHEREAMI++;
   
   
   
   
   
   
   ///==== background (end)  ====
   
   
   
   ///==== data (begin)  ====
      
   if (doSignalInjection == false) {
    name = Form("%sData%s",cutNameBefore.Data(),cutNameAfter.Data());
    hs->setDataHist (FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)));
   }
   else {
    TH1F* tempData = (TH1F*) vectTHBkg.at(0)->Clone();
    for (int iBkg = 1; iBkg < vectTHBkg.size(); iBkg++) {
     tempData->Add((TH1F*) vectTHBkg.at(iBkg)->Clone());
    }
    for (int iSig = 0; iSig < vectTHSig.size(); iSig++) {
     tempData->Add((TH1F*) vectTHSig.at(iSig)->Clone());
    }
    hs->setDataHist (tempData);
   }
   
   ///==== data (end)  ====
   
   
   hs->setBlindBinSx(100);
//    hs->setBlindBinSx(0);
//    hs->setBlindBinDx(10);
   hs->setBlindBinDx(0);
   
   hs->setCutSx(-999,">");
   hs->setCutDx(-999,"<");
   
   name = Form("%s%smodel_errs",folder.Data(),nameChannel.Data()); 
   std::cout << " name = " << name.Data() << std::endl;  
   
   hs->set_ErrorBand( *(FilterBins(binsToSelect, (TGraphAsymmErrors*) f[iFile]->Get(name))) );  
   
  }
 }
 
 std::cout << " * end iFile * " << std::endl;
 
 hs->set_vectTHBkg     (vectTHBkg);      
 hs->set_vectNameBkg   (vectNameBkg);    
 hs->set_vectColourBkg (vectColourBkg);  
//  if (which == 4) hs->set_vectSystBkg   (vectSystBkg);    
 hs->set_vectScaleBkg  (vectScaleBkg);   
 
 hs->set_vectTHSig     (vectTHSig);      
 hs->set_vectNameSig   (vectNameSig);    
 hs->set_vectColourSig (vectColourSig);  
 hs->set_vectScaleSig  (vectScaleSig);   
 
 

//  hs->addWeight(NY-minNY); //---- add S/(S+B) weight ---> used only for propaganda plot and data-background
 hs->addWeight1D(NY-minNY); //---- add S/(S+B) weight ---> used only for propaganda plot and data-background
 
 hs->prepare();
 
 hs->mergeSamples(); //---- merge trees with the same name! ---- to be called after "prepare" !
 
 hs->set_addSignalOnBackground(1); // 1 = signal over background , 0 = signal on its own
 
 hs->set_mergeSignal(0);    // 1 = merge signal in 1 bin, 0 = let different signals as it is
 
 hs->setMass(125); 
 
// hs->set_plotSigAlone(true); //---- false = "do not plot signal not-stacked to the background
 
 
 hs->set_doLabelNumber ( false ) ;
 
 ///==== draw ====
  
 TCanvas* c1bis = new TCanvas("bkgSub","bkgSub",500,500);
 
 hs->setUnits ("GeV");
//  double vedges[] = {0,10,20,30,40,50,60,70,80,90, 100,110,120,130,140,150,160,170,180,190, 200,210,220,230,240,250,260,270,280,290,300 };  //----> analysis
 
 double vedges[] = {-300, -250, -200, -150, -100, -75, -50, -20, 0, 20, 50, 75, 100, 150, 200, 250, 300};
 
//  [-300, -250, -200, -150, -100, -75, -50, -20, 0, 20, 50, 75, 100, 150, 200, 250, 300],[30,60,130,150,200,250,400]
 
 
//   for (int i=0; i<30; i++) {
//    vedges[i] = 0. + 10*i; 
//   }
 
 std::cout << "  vedges + sizeof(vedges) / sizeof(double) = " <<  vedges + sizeof(vedges) / sizeof(double) << std::endl;
 
 
 std::vector<double> vEdges (vedges, vedges + sizeof(vedges) / sizeof(double) );
 hs->set_vectEdges(vEdges);
 hs->set_divide(0); //---- if 1 then divide by bin width
 //   hs->set_divide(1); //---- if 1 then divide by bin width
  
 //----  canvas, rebin, div, shadow, background subtracted canvas ----
 hs->Draw(c1,1,true,true,c1bis);
 
 c1->Print("mll.pdf");
 c1->Print("mll.png");
 c1->Print("mll.eps");
 
 c1bis->Print("bkgSub_mll.pdf");
 c1bis->Print("bkgSub_mll.png");
 c1bis->Print("bkgSub_mll.eps");
 
}




