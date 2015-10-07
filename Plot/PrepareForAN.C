#include "TString.h"
#include "TH1F.h"
#include "TSystem.h"
#include "TInterpreter.h"
#include "TFile.h"

#include "PlotVHqqHggH.C"

#include <sstream>


//---- Filter bins ----
TH1F* FilterBins(std::vector<int> binsToSelect, TH1F* inputTH) {
 int numbin = binsToSelect.size();
 
 TString name;

 name = Form ("%s_new",inputTH->GetName());
 TObject* isItFound = gROOT->FindObject(name.Data());
 int icounter = 0;
 while (isItFound != 0x0) {
  name = Form ("%s_new_%d",inputTH->GetName(), icounter); 
  isItFound = gROOT->FindObject(name.Data());
  icounter++;
 }
 
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


//----                                                              doBlind = 0 -> show me data!
void PrepareForAN(int which, int energy = 0, int doWeight = 0, int doBlind = 0, float GammaOverGammaSM = 30) {
 
//  int which = 0;  //---- mth:mll 0 jet
//  int which = 2;  //---- mth:mll 1 jet
//  int which = 3;   //---- mth:mll 2 jet
//  int which = 4;  //---- mva 0 jet
//  int which = 6;  //---- mva 1 jet
//  int which = 7;  //---- mva 0+1 jet
 
 
 TString nameChannel;
 if   (which == 0)        { nameChannel = Form ("of_0j/"); }       //---- signal injection
 else if (which == 1)     { nameChannel = Form ("of_0j/"); }
 else if (which == 2)     { nameChannel = Form ("of_1j/"); }
 else if (which == 3)     { nameChannel = Form ("of_2j/"); }
 else if (which == 4)     { nameChannel = Form ("of_0j/"); }
 else if (which == 5)     { nameChannel = Form ("of_0j/"); }
 else if (which == 6)     { nameChannel = Form ("of_1j/"); }
 else if (which == 7)     { nameChannel = Form ("of_01j/"); }
 
 std::cout << " which = " << which << std::endl;
 
 
 TString folderSig = Form("sig/");
 TString cutNameBeforeSig = Form("sig/%shisto_",nameChannel.Data());

 TString folderBkg = Form("bkg/");
 TString cutNameBeforeBkg = Form("bkg/%shisto_",nameChannel.Data());
 
 TString folder = Form("init/");
 TString cutNameBefore = Form("init/%shisto_",nameChannel.Data());
//  TString cutNameBefore = Form("sig/%shisto_",nameChannel.Data());
 
 
 
 std::cout << " nameChannel   = " << nameChannel.Data() << std::endl;
 std::cout << " cutNameBefore = " << cutNameBefore.Data() << std::endl;
 
 //  TString folder = Form("bkg/");
 //  TString nameChannel = Form ("of_vh2j/");
 //  TString cutNameBefore = Form("bkg/%shisto_",nameChannel.Data());
 
 
 //                            cut_variable 
 TString cutNameAfter  = Form("");
 
//  gROOT->LoadMacro("PlotVHqqHggH.C+");
 gInterpreter->ExecuteMacro("LatinoStyle2.C");
 
//  TCanvas* c1 = new TCanvas("mll","mll",550,660);
 TCanvas* c1 = new TCanvas("mll","mll",800,660);
 
 TFile* f[10];
 bool doSignalInjection;
  
 
//  if (energy == 0) {
//   if      (which == 0)   { f[0] = new TFile("postFitSimple/Hwidth-0j-of-error-data.root");  doSignalInjection = false; }
//   else if (which == 1)   { f[0] = new TFile("postFitSimple/Hwidth-0j-of-error-signalInjection.root");  doSignalInjection = true; }
//   else if (which == 2)   { f[0] = new TFile("postFitSimple/Hwidth-1j-of-error-data.root");  doSignalInjection = false; }
//   else if (which == 3)   { f[0] = new TFile("postFit/Hwidth-2j-of-error-data.root");  doSignalInjection = false; }
//   
//   if      (which == 4)   { f[0] = new TFile("postFit/Hwidth-0j-of-error-data.root");  doSignalInjection = false; }
//   else if (which == 5)   { f[0] = new TFile("postFit/Hwidth-0j-of-error-signalInjection.root");  doSignalInjection = true; }
//   else if (which == 6)   { f[0] = new TFile("postFit/Hwidth-1j-of-error-data.root");  doSignalInjection = false; }
//   else if (which == 7)   { f[0] = new TFile("postFit/Hwidth-01j-of-error-data.root");  doSignalInjection = false; }
//  }
//  else {
//   if      (which == 0)   { f[0] = new TFile("postFit7TeV/Hwidth-0j-of-error-data.root");  doSignalInjection = false; }
//   else if (which == 1)   { f[0] = new TFile("postFit7TeV/Hwidth-0j-of-error-signalInjection.root");  doSignalInjection = true; }
//   else if (which == 2)   { f[0] = new TFile("postFit7TeV/Hwidth-1j-of-error-data.root");  doSignalInjection = false; }
//   else if (which == 3)   { f[0] = new TFile("postFit7TeV/Hwidth-2j-of-error-data.root");  doSignalInjection = false; }
//   
//   if      (which == 4)   { f[0] = new TFile("postFit7TeV/Hwidth-0j-of-error-data.root");  doSignalInjection = false; }
//   else if (which == 5)   { f[0] = new TFile("postFit7TeV/Hwidth-0j-of-error-signalInjection.root");  doSignalInjection = true; }
//   else if (which == 6)   { f[0] = new TFile("postFit7TeV/Hwidth-1j-of-error-data.root");  doSignalInjection = false; }
//   else if (which == 7)   { f[0] = new TFile("postFit7TeV/Hwidth-01j-of-error-data.root");  doSignalInjection = false; }
//  }
//  
//    
   
   
   
   
   
 
 
 if (energy == 0) {
  if      (which == 0)   { f[0] = new TFile("postFitSimple/Hwidth-0j-of-error-data.root");  doSignalInjection = false; }
  else if (which == 1)   { f[0] = new TFile("postFitSimple/Hwidth-0j-of-error-signalInjection.root");  doSignalInjection = true; }
  else if (which == 2)   { f[0] = new TFile("postFitSimple/Hwidth-1j-of-error-data.root");  doSignalInjection = false; }
  else if (which == 3)   { f[0] = new TFile("postFit_USED_FOR_PAPER/Hwidth-2j-of-error-data.root");  doSignalInjection = false; }
  
  if      (which == 4)   { f[0] = new TFile("postFit_USED_FOR_PAPER/Hwidth-0j-of-error-data.root");  doSignalInjection = false; }
  else if (which == 5)   { f[0] = new TFile("postFit_USED_FOR_PAPER/Hwidth-0j-of-error-signalInjection.root");  doSignalInjection = true; }
  else if (which == 6)   { f[0] = new TFile("postFit_USED_FOR_PAPER/Hwidth-1j-of-error-data.root");  doSignalInjection = false; }
  else if (which == 7)   { f[0] = new TFile("postFit_USED_FOR_PAPER/Hwidth-01j-of-error-data.root");  doSignalInjection = false; }
 }
 else {
  if      (which == 0)   { f[0] = new TFile("postFit7TeV/Hwidth-0j-of-error-data.root");  doSignalInjection = false; }
  else if (which == 1)   { f[0] = new TFile("postFit7TeV/Hwidth-0j-of-error-signalInjection.root");  doSignalInjection = true; }
  else if (which == 2)   { f[0] = new TFile("postFit7TeV/Hwidth-1j-of-error-data.root");  doSignalInjection = false; }
  else if (which == 3)   { f[0] = new TFile("postFit7TeV/Hwidth-2j-of-error-data.root");  doSignalInjection = false; }
  
  if      (which == 4)   { f[0] = new TFile("postFit7TeV/Hwidth-0j-of-error-data.root");  doSignalInjection = false; }
  else if (which == 5)   { f[0] = new TFile("postFit7TeV/Hwidth-0j-of-error-signalInjection.root");  doSignalInjection = true; }
  else if (which == 6)   { f[0] = new TFile("postFit7TeV/Hwidth-1j-of-error-data.root");  doSignalInjection = false; }
  else if (which == 7)   { f[0] = new TFile("postFit7TeV/Hwidth-01j-of-error-data.root");  doSignalInjection = false; }
 }
 
 
 PlotVHqqHggH* hs = new PlotVHqqHggH();
 
//  hs->setLabel("mll*");
 hs->setLabel("mll");
 
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
 
 std::vector<TH1F*> vectTHData;
 std::vector<std::string> vectNameData;
 
 
 
 std::vector<int> binsToSelect; 
 
 
 int NMAXX = 6*(7);  //---- variable bin
 int NMAXY = 1;  
 int minNY = 0;
 int minNX = 0;
 
 
 //  int which = 0;  //---- mth:mll 0 jet
 //  int which = 2;  //---- mth:mll 1 jet
 //  int which = 3;   //---- mth:mll 2 jet
 //  int which = 4;  //---- mva 0 jet
 //  int which = 6;  //---- mva 1 jet
 //  int which = 7;  //---- mva 0+1 jet
 
 
 
 
 if (energy == 0) { //---- 8 TeV
  if ((which == 0) || (which == 2)) {
   NMAXY = 7*(11);  //---- variable bin
   NMAXX = 1;
   
   
   if (doWeight == 1) { //---- on-shell
    NMAXY = 11;  //---- variable bin
    minNX = 0; 
    NMAXX = 3;
   }
   else if (doWeight == 2) { //---- off-shell
    NMAXY = 11;  //---- variable bin
    minNX = 3; 
    NMAXX = 7;
   }
   
  }
  
  if (which == 3) {
   NMAXY = 2*(5);  //---- variable bin
   NMAXX = 1;
   
   
   if (doWeight == 1) { //---- on-shell
    NMAXY = 5;  //---- variable bin
    minNX = 0; 
    NMAXX = 1;
   }
   else if (doWeight == 2) { //---- off-shell
    NMAXY = 5;  //---- variable bin
    minNX = 1; 
    NMAXX = 2;
   }
   
  }
  
  if (which == 4) {
   NMAXY = 6*(17);  //---- variable bin
   NMAXX = 1;
   
   
   if (doWeight == 1) { //---- on-shell
    NMAXY = 17;  //---- variable bin
    minNX = 0; 
    NMAXX = 4;
   }
   else if (doWeight == 2) { //---- off-shell
    NMAXY = 17;  //---- variable bin
    minNX = 4; 
    NMAXX = 6;
   }
   
  }
  
  
  if (which == 6) {
   NMAXY = 4*(15);  //---- variable bin
   NMAXX = 1;
   
   
   if (doWeight == 1) { //---- on-shell
    NMAXY = 15;  //---- variable bin
    minNX = 0; 
    NMAXX = 3;
   }
   else if (doWeight == 2) { //---- off-shell
    NMAXY = 15;  //---- variable bin
    minNX = 3; 
    NMAXX = 4;
   }
   
  }
  
  
  
  //    if (which == 6) NMAXX = 4*(19-2-1-1);  //---- variable bin
  if (which == 7) NMAXX = 6*(19-2);  //---- variable bin
 }
 else { //---- 7 TeV
  
  
  if ((which == 0) || (which == 2)) {
   NMAXY = 7*(7);  //---- variable bin
   NMAXX = 1;
   
   
   if (doWeight == 1) { //---- on-shell
    NMAXY = 7;  //---- variable bin
    minNX = 0; 
    NMAXX = 3;
   }
   else if (doWeight == 2) { //---- off-shell
    NMAXY = 7;  //---- variable bin
    minNX = 3; 
    NMAXX = 7;
   }
   
  }
  
  if (which == 3) {
   NMAXY = 2*(3);  //---- variable bin
   NMAXX = 1;
   
   
   if (doWeight == 1) { //---- on-shell
    NMAXY = 3;  //---- variable bin
    minNX = 0; 
    NMAXX = 1;
   }
   else if (doWeight == 2) { //---- off-shell
    NMAXY = 3;  //---- variable bin
    minNX = 1; 
    NMAXX = 2;
   }
   
  }
  
 }
 
 
 
 //---- all ----
 
 int NX = NMAXX;
 int NY = NMAXY;
 
//  int GammaOverGammaSM = 30;
//  int GammaOverGammaSM = 1;
 
 
 for (int iFile = 0; iFile<1; iFile++) {
  
  std::cout << "iFile = " << iFile << std::endl;
  
//   ///---- project along X : sum over Y
//   for (int iY=minNY; iY<NY; iY++){
//    binsToSelect.clear();
//    for (int iX=minNX; iX<NX; iX++){
//     binsToSelect.push_back (iX*NMAXY+iY+1);
//     std::cout << " iX*NY+iY+1 = " << iX*NY+iY+1 << std::endl;
//    }
   
  ///---- project along Y : sum over X
  for (int iX=minNX; iX<NX; iX++){
   binsToSelect.clear();
   for (int iY=minNY; iY<NY; iY++){
    binsToSelect.push_back (iX*NMAXY+iY+1);
    std::cout << " iX*NY+iY+1 = " << iX*NY+iY+1 << std::endl;
   }
   
   ///==== signal (begin) ====
   int WHEREAMI = 0;
   std::cout << "I'm here: " << WHEREAMI << std::endl; WHEREAMI++;
      
    TString nameSignal   = Form("H off %d #Gamma", int(GammaOverGammaSM));
   //    TString nameSignalOn = Form("H on x%d" , GammaOverGammaSM);
   TString nameSignalOn = Form("H on shell");
   
   
   
   
   if (doWeight != 1) { 
    
    name = Form("%sggH_sbi%s",cutNameBefore.Data(),cutNameAfter.Data());
    vectTHSig.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
    std::cout << " >>>> integral = " << vectTHSig.at(vectTHSig.size()-1) -> Integral () << std::endl;;
//     vectNameSig.push_back (nameSignal.Data());
       vectNameSig.push_back ("ggHoff");
    vectColourSig.push_back(2);
    vectSystSig.push_back(0.00);
    vectScaleSig.push_back(1.0000*sqrt(GammaOverGammaSM));
    //    vectNormalizationSig.push_back(0.719);  
    std::cout << "I'm here: " << WHEREAMI << std::endl; WHEREAMI++;
    
    name = Form("%sggH_b%s",cutNameBefore.Data(),cutNameAfter.Data());
    vectTHSig.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
//     vectNameSig.push_back (nameSignal.Data());
    std::cout << " >>>> integral = " << vectTHSig.at(vectTHSig.size()-1) -> Integral () << std::endl;;
    vectNameSig.push_back ("ggHoff");
    vectColourSig.push_back(2);
    vectSystSig.push_back(0.00);
    vectScaleSig.push_back(-1.0000*sqrt(GammaOverGammaSM));
    //    vectNormalizationSig.push_back(0.719);  
    std::cout << "I'm here: " << WHEREAMI << std::endl; WHEREAMI++;
    
    name = Form("%sggH_s%s",cutNameBefore.Data(),cutNameAfter.Data());
    vectTHSig.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
//     vectNameSig.push_back (nameSignal.Data());
    std::cout << " >>>> integral = " << vectTHSig.at(vectTHSig.size()-1) -> Integral () << std::endl;;
    vectNameSig.push_back ("ggHoff");
    vectColourSig.push_back(2);
    vectSystSig.push_back(0.00);
    vectScaleSig.push_back(-1.0000*sqrt(GammaOverGammaSM));
    //    vectNormalizationSig.push_back(0.719);  
    std::cout << "I'm here: " << WHEREAMI << std::endl; WHEREAMI++;
    
    
    
    name = Form("%sggH_s%s",cutNameBefore.Data(),cutNameAfter.Data());
    vectTHSig.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
//     vectNameSig.push_back (nameSignal.Data());
    std::cout << " >>>> integral = " << vectTHSig.at(vectTHSig.size()-1) -> Integral () << std::endl;;
    vectNameSig.push_back ("ggHoff");
    vectColourSig.push_back(2);
    vectSystSig.push_back(0.00);
    vectScaleSig.push_back(1.0000*GammaOverGammaSM);
    //    vectNormalizationSig.push_back(0.719);  
    std::cout << "I'm here: " << WHEREAMI << std::endl; WHEREAMI++;
    
    
    
    
    
    //---- VBF
    
    name = Form("%sqqH_sbi%s",cutNameBefore.Data(),cutNameAfter.Data());
    vectTHSig.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
//     vectNameSig.push_back (nameSignal.Data());
    vectNameSig.push_back ("qqHoff");
    vectColourSig.push_back(2);
    vectSystSig.push_back(0.00);
    vectScaleSig.push_back(1.0000*sqrt(GammaOverGammaSM));
    //    vectNormalizationSig.push_back(0.719);  
    std::cout << "I'm here: " << WHEREAMI << std::endl; WHEREAMI++;
    
    name = Form("%sqqH_b%s",cutNameBefore.Data(),cutNameAfter.Data());
    vectTHSig.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
//     vectNameSig.push_back (nameSignal.Data());
    vectNameSig.push_back ("qqHoff");
    vectColourSig.push_back(2);
    vectSystSig.push_back(0.00);
    vectScaleSig.push_back(-1.0000*sqrt(GammaOverGammaSM));
    //    vectNormalizationSig.push_back(0.719);  
    std::cout << "I'm here: " << WHEREAMI << std::endl; WHEREAMI++;
    
    name = Form("%sqqH_s%s",cutNameBefore.Data(),cutNameAfter.Data());
    vectTHSig.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
//     vectNameSig.push_back (nameSignal.Data());
    vectNameSig.push_back ("qqHoff");
    vectColourSig.push_back(2);
    vectSystSig.push_back(0.00);
    vectScaleSig.push_back(-1.0000*sqrt(GammaOverGammaSM));
    //    vectNormalizationSig.push_back(0.719);  
    std::cout << "I'm here: " << WHEREAMI << std::endl; WHEREAMI++;
    
    
    
    name = Form("%sqqH_s%s",cutNameBefore.Data(),cutNameAfter.Data());
    vectTHSig.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
//     vectNameSig.push_back (nameSignal.Data());
    vectNameSig.push_back ("qqHoff");
    vectColourSig.push_back(2);
    vectSystSig.push_back(0.00);
    vectScaleSig.push_back(1.0000*GammaOverGammaSM);
    //    vectNormalizationSig.push_back(0.719);  
    std::cout << "I'm here: " << WHEREAMI << std::endl; WHEREAMI++;
    
    
    
   }
   else { //---- on-shell Higgs as signal
    name = Form("%sggH%s",cutNameBefore.Data(),cutNameAfter.Data());
    vectTHSig.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
    vectNameSig.push_back ("ggH");
//     vectNameSig.push_back (nameSignalOn.Data());
    //    vectNameSig.push_back ("H m_{H}=125 ");
    vectColourSig.push_back(6);
    vectSystSig.push_back(0.00);
    vectScaleSig.push_back(1.0000);
    //    vectScaleSig.push_back(1.0000*sqrt(GammaOverGammaSM));
    //    vectNormalizationSig.push_back(0.719);  
    std::cout << "I'm here: " << WHEREAMI << std::endl; WHEREAMI++;
    
    name = Form("%sqqH%s",cutNameBefore.Data(),cutNameAfter.Data());
    vectTHSig.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
    vectNameSig.push_back ("qqH");
//     vectNameSig.push_back (nameSignalOn.Data());
    //    vectNameSig.push_back ("H m_{H}=125 ");
    vectColourSig.push_back(6);
    vectSystSig.push_back(0.00);
    vectScaleSig.push_back(1.0000);
    //    vectScaleSig.push_back(1.0000*sqrt(GammaOverGammaSM));
    //    vectNormalizationSig.push_back(0.719);  
   }
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   ///==== signal (end)  ====
   
   
   
   ///==== background (begin)  ====  

   name = Form("%sVV%s",cutNameBeforeSig.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
//    vectNameBkg.push_back ("WZ/ZZ/VVV");
   vectNameBkg.push_back ("VVandVVV");
   vectColourBkg.push_back(858);
   vectSystBkg.push_back(0.00);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(0.281);
   std::cout << "I'm here: " << WHEREAMI << std::endl; WHEREAMI++;
   
   if (energy == 0) { //---- only 8 TeV
    name = Form("%sVVV%s",cutNameBeforeSig.Data(),cutNameAfter.Data());
    vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
    //    vectNameBkg.push_back ("WZ/ZZ/VVV");
    vectNameBkg.push_back ("VVandVVV");
    vectColourBkg.push_back(858);
    vectSystBkg.push_back(0.00);
    vectScaleBkg.push_back(1.0000);
    vectNormalizationBkg.push_back(0.281);
   }

   
   name = Form("%sWJet%s",cutNameBeforeSig.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
   vectNameBkg.push_back ("W+jets");
   vectColourBkg.push_back(921);
   vectSystBkg.push_back(0.00);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(0.667);
   
   name = Form("%sVg%s",cutNameBeforeSig.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
//    vectNameBkg.push_back ("V+#gamma/V+#gamma*");
   vectNameBkg.push_back ("Vg");
   vectColourBkg.push_back(616+1);
   vectSystBkg.push_back(0.00);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(1.000);
   
   if (energy == 0 && which != 3) { 
    name = Form("%sVgS%s",cutNameBeforeSig.Data(),cutNameAfter.Data());
//    if (f[iFile]->GetListOfKeys()->Contains(name)) {
    vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
//     vectNameBkg.push_back ("V+#gamma/V+#gamma*");
//     vectNameBkg.push_back ("Wgs");
    vectNameBkg.push_back ("Vg");
    vectColourBkg.push_back(616+2);
    vectSystBkg.push_back(0.00);
    vectScaleBkg.push_back(1.0000);
    vectNormalizationBkg.push_back(1.000);
//    }
   }
   
   
   name = Form("%sTop%s",cutNameBeforeSig.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
//    vectNameBkg.push_back ("Top");
   vectNameBkg.push_back ("top");
   vectColourBkg.push_back(400);
   vectSystBkg.push_back(0.10);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(5.654);

//    if (energy == 0) { //---- only 8 TeV
//     name = Form("%sDYTT%s",cutNameBefore.Data(),cutNameAfter.Data());
//     vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
//     //    vectNameBkg.push_back ("DYTT");
//     vectNameBkg.push_back ("DY+jets");
//     vectColourBkg.push_back(418);
//     vectSystBkg.push_back(0.00);
//     vectScaleBkg.push_back(1.0000);
//     vectNormalizationBkg.push_back(0.377);
//    }
   name = Form("%sDYTT%s",cutNameBeforeSig.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
//    vectNameBkg.push_back ("DYTT");
   vectNameBkg.push_back ("DY+jets");
   vectColourBkg.push_back(418);
   vectSystBkg.push_back(0.00);
   vectScaleBkg.push_back(1.0000);
   vectNormalizationBkg.push_back(0.377);
   
//    name = Form("%sWW%s",cutNameBefore.Data(),cutNameAfter.Data());
   //----> take WW from fit, since it is data-driven in normalization!
   name = Form("%sWW%s",cutNameBeforeSig.Data(),cutNameAfter.Data());
//    if (f[iFile]->GetListOfKeys()->Contains(name)) {   
    std::cout << " >>> found: " << name.Data() << std::endl;
    vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
    vectNameBkg.push_back ("WW");
    vectColourBkg.push_back(851);
    vectSystBkg.push_back(0.00);
    vectScaleBkg.push_back(1.0000);
    vectNormalizationBkg.push_back(2.256);
//    }
   
//    name = Form("%sWWlow%s",cutNameBeforeSig.Data(),cutNameAfter.Data());
//    std::cout << " f[iFile]->GetListOfKeys() = ";
// //    f[iFile]->GetListOfKeys()->Print();
//    
// //    if (f[iFile]->GetListOfKeys()->Contains(name)) {    
//     std::cout << " >>> found: " << name.Data() << std::endl;
//     vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
//     vectNameBkg.push_back ("WW");
//     vectColourBkg.push_back(851);
//     vectSystBkg.push_back(0.00);
//     vectScaleBkg.push_back(1.0000);
//     vectNormalizationBkg.push_back(2.256);
// //    }
//    
//    name = Form("%sWWhigh%s",cutNameBeforeSig.Data(),cutNameAfter.Data());
// //    if (f[iFile]->GetListOfKeys()->Contains(name)) {    
//     std::cout << " >>> found: " << name.Data() << std::endl;
//     vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
//     vectNameBkg.push_back ("WW");
//     vectColourBkg.push_back(851);
//     vectSystBkg.push_back(0.00);
//     vectScaleBkg.push_back(1.0000);
//     vectNormalizationBkg.push_back(2.256);
// //    }
   
   
   
//    name = Form("%sggWW%s",cutNameBefore.Data(),cutNameAfter.Data());
//    if (f[iFile]->GetListOfKeys()->Contains(name)) {
//     vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
//     vectNameBkg.push_back ("WW");
//     vectColourBkg.push_back(853);
//     vectSystBkg.push_back(0.00);
//     vectScaleBkg.push_back(1.0000);
//     vectNormalizationBkg.push_back(2.256);
//    }
   
   
   name = Form("%sggH_b%s",cutNameBeforeSig.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
   vectNameBkg.push_back ("ggWW");
   vectColourBkg.push_back(8);
   vectSystBkg.push_back(0.00);
   vectScaleBkg.push_back(1.0000);
   //    vectNormalizationBkg.push_back(0.719);  
   std::cout << "I'm here: " << WHEREAMI << " ggWW " << std::endl; WHEREAMI++;
   
   
   name = Form("%sqqH_b%s",cutNameBeforeSig.Data(),cutNameAfter.Data());
   vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
   //     vectNameBkg.push_back (nameSignal.Data());
   vectNameBkg.push_back ("WW");
   vectColourBkg.push_back(8);
   vectSystBkg.push_back(0.00);
   vectScaleBkg.push_back(1.000);
   //    vectNormalizationBkg.push_back(0.719);  
   std::cout << "I'm here: " << WHEREAMI << std::endl; WHEREAMI++;
   
   
  
   
   if (doWeight != 1) { //---- on-shell higgs as background
    
    name = Form("%sggH%s",cutNameBefore.Data(),cutNameAfter.Data());
    vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
    vectNameBkg.push_back ("ggH");
//     vectNameBkg.push_back (nameSignalOn.Data());
    //    vectNameBkg.push_back ("H m_{H}=125 ");
    vectColourBkg.push_back(6);
    vectSystBkg.push_back(0.00);
    vectScaleBkg.push_back(1.0000);
    //    vectScaleBkg.push_back(1.0000*sqrt(GammaOverGammaSM));
    //    vectNormalizationBkg.push_back(0.719);  
    std::cout << "I'm here: " << WHEREAMI << std::endl; WHEREAMI++;
    
    name = Form("%sqqH%s",cutNameBefore.Data(),cutNameAfter.Data());
    vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
    vectNameBkg.push_back ("qqH");
//     vectNameBkg.push_back (nameSignalOn.Data());
    //    vectNameBkg.push_back ("H m_{H}=125 ");
    vectColourBkg.push_back(7);
    vectSystBkg.push_back(0.00);
    vectScaleBkg.push_back(1.0000);
    //    vectScaleBkg.push_back(1.0000*sqrt(GammaOverGammaSM));
    //    vectNormalizationBkg.push_back(0.719);  
    
   }
   else { //---- off-shell higgs as background
    
    name = Form("%sggH_sbi%s",cutNameBefore.Data(),cutNameAfter.Data());
    vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
    std::cout << " >>>> integral = " << vectTHBkg.at(vectTHBkg.size()-1) -> Integral () << std::endl;;
//     vectNameBkg.push_back (nameSignal.Data());
    vectNameBkg.push_back ("ggHoff");
    vectColourBkg.push_back(2);
    vectSystBkg.push_back(0.00);
    vectScaleBkg.push_back(1.0000*sqrt(GammaOverGammaSM));
    //    vectNormalizationBkg.push_back(0.719);  
    std::cout << "I'm here: " << WHEREAMI << std::endl; WHEREAMI++;
    
    name = Form("%sggH_b%s",cutNameBefore.Data(),cutNameAfter.Data());
    vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
//     vectNameBkg.push_back (nameSignal.Data());
    std::cout << " >>>> integral = " << vectTHBkg.at(vectTHBkg.size()-1) -> Integral () << std::endl;;
    vectNameBkg.push_back ("ggHoff");
    vectColourBkg.push_back(2);
    vectSystBkg.push_back(0.00);
    vectScaleBkg.push_back(-1.0000*sqrt(GammaOverGammaSM));
    //    vectNormalizationBkg.push_back(0.719);  
    std::cout << "I'm here: " << WHEREAMI << std::endl; WHEREAMI++;
    
    name = Form("%sggH_s%s",cutNameBefore.Data(),cutNameAfter.Data());
    vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
//     vectNameBkg.push_back (nameSignal.Data());
    std::cout << " >>>> integral = " << vectTHBkg.at(vectTHBkg.size()-1) -> Integral () << std::endl;;
    vectNameBkg.push_back ("ggHoff");
    vectColourBkg.push_back(2);
    vectSystBkg.push_back(0.00);
    vectScaleBkg.push_back(-1.0000*sqrt(GammaOverGammaSM));
    //    vectNormalizationBkg.push_back(0.719);  
    std::cout << "I'm here: " << WHEREAMI << std::endl; WHEREAMI++;
    
    
    
    name = Form("%sggH_s%s",cutNameBefore.Data(),cutNameAfter.Data());
    vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
    vectNameBkg.push_back (nameSignal.Data());
    std::cout << " >>>> integral = " << vectTHBkg.at(vectTHBkg.size()-1) -> Integral () << std::endl;;
    //    vectNameBkg.push_back ("ggHoff");
    vectColourBkg.push_back(2);
    vectSystBkg.push_back(0.00);
    vectScaleBkg.push_back(1.0000*GammaOverGammaSM);
    //    vectNormalizationBkg.push_back(0.719);  
    std::cout << "I'm here: " << WHEREAMI << std::endl; WHEREAMI++;
    
    
    
    
    
    //---- VBF
    
    name = Form("%sqqH_sbi%s",cutNameBefore.Data(),cutNameAfter.Data());
    vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
//     vectNameBkg.push_back (nameSignal.Data());
    vectNameBkg.push_back ("qqHoff");
    vectColourBkg.push_back(90);
    vectSystBkg.push_back(0.00);
    vectScaleBkg.push_back(1.0000*sqrt(GammaOverGammaSM));
    //    vectNormalizationBkg.push_back(0.719);  
    std::cout << "I'm here: " << WHEREAMI << std::endl; WHEREAMI++;
    
    name = Form("%sqqH_b%s",cutNameBefore.Data(),cutNameAfter.Data());
    vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
//     vectNameBkg.push_back (nameSignal.Data());
    vectNameBkg.push_back ("qqHoff");
    vectColourBkg.push_back(90);
    vectSystBkg.push_back(0.00);
    vectScaleBkg.push_back(-1.0000*sqrt(GammaOverGammaSM));
    //    vectNormalizationBkg.push_back(0.719);  
    std::cout << "I'm here: " << WHEREAMI << std::endl; WHEREAMI++;
    
    name = Form("%sqqH_s%s",cutNameBefore.Data(),cutNameAfter.Data());
    vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
//     vectNameBkg.push_back (nameSignal.Data());
    vectNameBkg.push_back ("qqHoff");
    vectColourBkg.push_back(90);
    vectSystBkg.push_back(0.00);
    vectScaleBkg.push_back(-1.0000*sqrt(GammaOverGammaSM));
    //    vectNormalizationBkg.push_back(0.719);  
    std::cout << "I'm here: " << WHEREAMI << std::endl; WHEREAMI++;
    
    
    
    name = Form("%sqqH_s%s",cutNameBefore.Data(),cutNameAfter.Data());
    vectTHBkg.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
//     vectNameBkg.push_back (nameSignal.Data());
    vectNameBkg.push_back ("qqHoff");
    vectColourBkg.push_back(90);
    vectSystBkg.push_back(0.00);
    vectScaleBkg.push_back(1.0000*GammaOverGammaSM);
    //    vectNormalizationBkg.push_back(0.719);  
    std::cout << "I'm here: " << WHEREAMI << std::endl; WHEREAMI++;
    
    
    
   }
   
   
   
   
   ///==== background (end)  ====
   
   
   
   ///==== data (begin)  ====
      
   if (doSignalInjection == false) {
    name = Form("%sData%s",cutNameBefore.Data(),cutNameAfter.Data());
    vectTHData.push_back ( FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)) );
//     vectTHData.push_back ( (TH1F*) ((TH1F*) f[iFile]->Get(name))->Clone() );
    vectNameData.push_back ("Data");
//     hs->setDataHist (FilterBins(binsToSelect, (TH1F*) f[iFile]->Get(name)));
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
   
   
   //  int which = 0;  //---- mth:mll 0 jet
   //  int which = 2;  //---- mth:mll 1 jet
   //  int which = 3;  //---- mth:mll 2 jet
   //  int which = 4;  //---- mva 0 jet
   //  int which = 6;  //---- mva 1 jet
   //  int which = 7;  //---- mva 0+1 jet
   
   if (doBlind) {
    //    hs->setBlindBinSx(100);
    hs->setBlindBinSx(9);
    hs->setBlindBinDx(9);
    //    hs->setBlindBinDx(0);
    
    if (which == 4) {
     hs->setBlindBinSx(17*3-10);
     hs->setBlindBinDx(17*1+5);
    }
    
    if (which == 6) {
     hs->setBlindBinSx(15*2-10);
     hs->setBlindBinDx(15*1-5);
    }
    
    if (which == 7) {
     //     hs->setBlindBinSx(0);
     //     hs->setBlindBinDx(0);
     hs->setBlindBinSx(17*3-10);
     hs->setBlindBinDx(17*1+5);
    }
    
    if (which == 3) {
     hs->setBlindBinSx(3);
     hs->setBlindBinDx(5);
    }
    
    if (which == 0) {
     //     hs->setBlindBinSx(0);
     //     hs->setBlindBinDx(0);
     hs->setBlindBinSx(11*3);
     hs->setBlindBinDx(11*2);
    }
    
    
    if (which == 2) {
     hs->setBlindBinSx(11*2+4);
     hs->setBlindBinDx(11*2+4);
    }
    
   }
   
   
   hs->setCutSx(-999,">");
   hs->setCutDx(-999,"<");
   
//    name = Form("%s%smodel_errs",folder.Data(),nameChannel.Data()); 
   name = Form("%s%smodel_errs",folderSig.Data(),nameChannel.Data());  //----> signal + background fit uncertainty -> removal of lnU effects 
//    name = Form("%s%smodel_errs",folderBkg.Data(),nameChannel.Data());  //----> background fit uncertainty -> removal of lnU effects 
   
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
 

 if (doWeight != 0) {
  //   hs->addWeight1D(NY-minNY); //---- add S/(S+B) weight ---> used only for propaganda plot and data-background
  hs->addWeight1D(NX-minNX); //---- add S/(S+B) weight ---> used only for propaganda plot and data-background
 }
//  hs->addWeight(NY-minNY); //---- add S/(S+B) weight ---> used only for propaganda plot and data-background
//  hs->addWeight1D(NY-minNY); //---- add S/(S+B) weight ---> used only for propaganda plot and data-background
 
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
 
//  double vedges[] = {-300, -250, -200, -150, -100, -75, -50, -20, 0, 20, 50, 75, 100, 150, 200, 250, 300};
//  double vedges[] = {0, 20, 50, 75, 100, 150, 200, 250, 300};
 
//  double vedges[] = {-1.00, -0.75, -0.50, -0.25, 0.00, 0.25, 0.50, 0.75, 1.00};  //---- mva
 
 double vedges[(NMAXX-minNX)*(NMAXY-minNY)+1];
 for (int i=0; i<(NMAXX-minNX)*(NMAXY-minNY)+1; i++) {
  vedges[i] = 0. + 1.*i; 
  //   std::cout << " vedges[" << i << "] = " << vedges[i] << std::endl;
 }
 
 
 
 
 if (energy == 0) { //---- 8 TeV
  if ((which == 0) || (which == 2)) {
   if (doWeight == 1) { //---- on-shell
    double vedges_temp[] = {0, 50, 70, 90, 100, 110, 120, 130, 140, 160, 200, 450};
    for (int i=0; i<(NMAXX-minNX)*(NMAXY-minNY)+1; i++) {
     vedges[i] = vedges_temp[i]; 
    }
   }
   else if (doWeight == 2) { //---- off-shell
    double vedges_temp[] = {0, 50, 70, 90, 100, 110, 120, 130, 140, 160, 200, 450};
    for (int i=0; i<(NMAXX-minNX)*(NMAXY-minNY)+1; i++) {
     vedges[i] = vedges_temp[i]; 
    }
   }
  }
  
  if (which == 3) {
   if (doWeight == 1) { //---- on-shell
    double vedges_temp[] = {0, 50, 100, 130, 170, 450};
    for (int i=0; i<(NMAXX-minNX)*(NMAXY-minNY)+1; i++) {
     vedges[i] = vedges_temp[i]; 
    }
   }
   else if (doWeight == 2) { //---- off-shell
    double vedges_temp[] = {0, 50, 100, 130, 170, 450};
    for (int i=0; i<(NMAXX-minNX)*(NMAXY-minNY)+1; i++) {
     vedges[i] = vedges_temp[i]; 
    }
   }
  }
  
  if (which == 4) {
   if (doWeight == 1) { //---- on-shell
    double vedges_temp[] = {-1.00, -0.70, -0.60, -0.50, -0.40, -0.30, -0.20, -0.10, 0.00, 0.10, 0.20, 0.30, 0.40, 0.50, 0.60, 0.70, 0.80, 1.00};
    for (int i=0; i<(NMAXX-minNX)*(NMAXY-minNY)+1; i++) {
     vedges[i] = ((vedges_temp[i]) + 1.00) * 160.; 
    }
   }
   else if (doWeight == 2) { //---- off-shell
    double vedges_temp[] = {-1.00, -0.70, -0.60, -0.50, -0.40, -0.30, -0.20, -0.10, 0.00, 0.10, 0.20, 0.30, 0.40, 0.50, 0.60, 0.70, 0.80, 1.00};
    for (int i=0; i<(NMAXX-minNX)*(NMAXY-minNY)+1; i++) {
     vedges[i] = vedges_temp[i]; 
    }
   }
  }
  
  if (which == 6) {
   if (doWeight == 1) { //---- on-shell
    double vedges_temp[] = {-1.00, -0.60, -0.50, -0.40, -0.30, -0.20, -0.10, 0.00, 0.10, 0.20, 0.30, 0.40, 0.50, 0.60, 0.70, 1.00};
    for (int i=0; i<(NMAXX-minNX)*(NMAXY-minNY)+1; i++) {
     vedges[i] = ((vedges_temp[i]) + 1.00) * 160.; 
    }
   }
   else if (doWeight == 2) { //---- off-shell
    double vedges_temp[] = {-1.00, -0.60, -0.50, -0.40, -0.30, -0.20, -0.10, 0.00, 0.10, 0.20, 0.30, 0.40, 0.50, 0.60, 0.70, 1.00};
    for (int i=0; i<(NMAXX-minNX)*(NMAXY-minNY)+1; i++) {
     vedges[i] = vedges_temp[i]; 
    }
   }
  }
  
  
 }
 else { //---- 7 TeV
  if ((which == 0) || (which == 2)) {
   if (doWeight == 1) { //---- on-shell
    double vedges_temp[] = {0, 50, 90, 110, 130, 160, 200, 450};
    for (int i=0; i<(NMAXX-minNX)*(NMAXY-minNY)+1; i++) {
     vedges[i] = vedges_temp[i]; 
    }
   }
   else if (doWeight == 2) { //---- off-shell
    double vedges_temp[] = {0, 50, 90, 110, 130, 160, 200, 450};
    for (int i=0; i<(NMAXX-minNX)*(NMAXY-minNY)+1; i++) {
     vedges[i] = vedges_temp[i]; 
    }
   }
  }
  
  if (which == 3) {
   if (doWeight == 1) { //---- on-shell
    double vedges_temp[] = {0, 80, 130, 450};
    for (int i=0; i<(NMAXX-minNX)*(NMAXY-minNY)+1; i++) {
     vedges[i] = vedges_temp[i]; 
    }
   }
   else if (doWeight == 2) { //---- off-shell
    double vedges_temp[] = {0, 80, 130, 450};
    for (int i=0; i<(NMAXX-minNX)*(NMAXY-minNY)+1; i++) {
     vedges[i] = vedges_temp[i]; 
    }
   }
  }
  
 }
 
 
 
 
 
 
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
 
 
 
 
 ///---- output file to dump and prepare common plots

 TGraphAsymmErrors* finalErrorBand = (TGraphAsymmErrors*) (hs->get_ErrorBand());
 finalErrorBand->SetName("errorBand");
 
 ///---- fix bin edges (begin) ----
//  set_vectEdges(vEdges, vectTHBkg, vectTHSig, vectTHData, finalErrorBand);
 std::cout << " vectNameData.size() = " << vectNameData.size() << std::endl;
 std::cout << " vectTHData.size() =   " << vectTHData.size() << std::endl;
 set_vectEdges(vEdges, vectTHBkg, vectTHSig, vectTHData);
 ///---- fix bin edges (end) ----
 
 ///---- re-weight the histograms to apply the weight (begin) ----
 if (doWeight != 0) {
  addWeight1D(NX-minNX, vectTHBkg, vectTHSig, vectTHData); //---- add S/(S+B) weight ---> used only for propaganda plot and data-background
 }
 ///---- re-weight the histograms to apply the weight (end) ----
 
 std::ostringstream stress;
 stress << "final_" << which << "_" << energy << "_" << doWeight << ".root";
 std::string nameOutFile(stress.str());
 TFile* outfile = new TFile (nameOutFile.c_str(),"recreate");
 
 for (int iBkg = 0; iBkg < vectScaleBkg.size(); iBkg++) { 
  (vectTHBkg.at(iBkg)) -> Sumw2();
  vectTHBkg.at(iBkg)   -> Scale(vectScaleBkg.at(iBkg));
 }
 for (int iSig = 0; iSig < vectScaleSig.size(); iSig++) { 
  (vectTHSig.at(iSig)) -> Sumw2();
  std::cout << " vectScaleSig.at(" << iSig << ") = " << vectScaleSig.at(iSig)  << " Integral = " << vectTHSig.at(iSig)->Integral() << std::endl;
  vectTHSig.at(iSig)   -> Scale(vectScaleSig.at(iSig));
  std::cout << " vectScaleSig.at(" << iSig << ") = " << vectScaleSig.at(iSig)  << " Integral = " << vectTHSig.at(iSig)->Integral() << std::endl;
 }
 
//  
 
 ///---- Bkg ----
//   for (int iBkg = 0; iBkg < vectNameBkg.size(); iBkg++) { 
//    (vectTHBkg.at(iBkg))->SetName(vectNameBkg.at(iBkg).c_str());
//   }
  
  //---- add systematic background
  for (int iBkg = 0; iBkg < vectSystBkg.size(); iBkg++) { 
   int nbin = vectTHBkg.at(iBkg) -> GetNbinsX();
   for (int iBin = 0; iBin < nbin; iBin++) {
    double err_before = vectTHBkg.at(iBkg) -> GetBinError(iBin+1);
    double value = vectTHBkg.at(iBkg) -> GetBinContent(iBin+1);
    double syst = vectSystBkg.at(iBkg);
    double err_after = sqrt(err_before*err_before + syst*value*syst*value);
    vectTHBkg.at(iBkg) -> SetBinError(iBin+1, err_after);
   }
  }
  
  
  for (int iBkg = 0; iBkg < vectNameBkg.size(); iBkg++) { 
   (vectTHBkg.at(iBkg))->SetName(vectNameBkg.at(iBkg).c_str());
   for (int jBkg = iBkg+1; jBkg < vectNameBkg.size(); jBkg++) {
    if (vectNameBkg.at(iBkg) == vectNameBkg.at(jBkg)) {
     (vectTHBkg.at(iBkg)) -> Add(vectTHBkg.at(jBkg));
    }
   }
  }
  
  
  for (int iBkg = 0; iBkg < vectNameBkg.size(); iBkg++) { 
   bool alreadySaved = false;
   for (int jBkg = iBkg-1; jBkg >= 0; jBkg--) {
    if (vectNameBkg.at(iBkg) == vectNameBkg.at(jBkg)) {
     alreadySaved = true;
    }
   }
   if (!alreadySaved) {
    (vectTHBkg.at(iBkg))->Write();
   }
  }
  
  ///---- Sig ----
//   for (int iSig = 0; iSig < vectNameSig.size(); iSig++) { 
//    (vectTHSig.at(iSig)) -> Sumw2();
//    (vectTHSig.at(iSig))->SetName(vectNameSig.at(iSig).c_str());
//   }
  
  for (int iSig = 0; iSig < vectNameSig.size(); iSig++) { 
   (vectTHSig.at(iSig))->SetName(vectNameSig.at(iSig).c_str());
   for (int jSig = iSig+1; jSig < vectNameSig.size(); jSig++) {
    if (vectNameSig.at(iSig) == vectNameSig.at(jSig)) {
     std::cout << " Adding: vectNameSig.at(" << iSig << "::" << jSig << ") :: to " << vectNameSig.at(jSig) << " out of total = " << vectNameSig.size() << std::endl;
     (vectTHSig.at(iSig)) -> Add(vectTHSig.at(jSig));
     std::cout << "    Integral = " << (vectTHSig.at(iSig)) -> Integral() << " addition was = " << vectTHSig.at(jSig)->Integral() << std::endl;
    }
   }
  }
  
  
  for (int iSig = 0; iSig < vectNameSig.size(); iSig++) { 
   bool alreadySaved = false;
   for (int jSig = iSig-1; jSig >= 0; jSig--) {
    if (vectNameSig.at(iSig) == vectNameSig.at(jSig)) {
     alreadySaved = true;
    }
   }
   if (!alreadySaved) {
    (vectTHSig.at(iSig))->Write();
   }
  }
  
  
  ///---- Data ----
  std::cout << " vectNameData.size() = " << vectNameData.size() << std::endl;
  std::cout << " vectTHData.size() =   " << vectTHData.size() << std::endl;
  for (int iData = 0; iData < vectNameData.size(); iData++) { 
   (vectTHData.at(iData)) -> Sumw2();
   (vectTHData.at(iData))->SetName(vectNameData.at(iData).c_str());
  }
  
  for (int iData = 0; iData < vectNameData.size(); iData++) { 
   for (int jData = iData+1; jData < vectNameData.size(); jData++) {
    if (vectNameData.at(iData) == vectNameData.at(jData)) {
     (vectTHData.at(iData)) -> Add(vectTHData.at(jData));
    }
   }
  }
  
  for (int iData = 0; iData < vectNameData.size(); iData++) { 
   bool alreadySaved = false;
   for (int jData = iData-1; jData >= 0; jData--) {
    if (vectNameData.at(iData) == vectNameData.at(jData)) {
     alreadySaved = true;
    }
   }
   if (!alreadySaved) {
    (vectTHData.at(iData))->Write();
//     TCanvas* cccccc = new TCanvas();
//     std::cout << " iData = " << iData << std::endl;
//     (vectTHData.at(iData))->Draw();
   }
  }
  
  ///---- data band
  if (doWeight) {
   TGraphAsymmErrors* gr_data = (TGraphAsymmErrors*) (hs->GetDataGR());
   gr_data->SetName("gr_data");
   gr_data->Write();
  }
  
  ///---- error band ----
  finalErrorBand->Write();
  
    
  outfile->Close();
 
  std::ostringstream stress2;
  stress2 << "cp final_" << which << "_" << energy << "_" << doWeight << ".root final_" << which << "_" << energy << "_" << doWeight << "_" << GammaOverGammaSM << ".root";
  std::string nameOutFile2(stress2.str());
  gSystem->Exec(nameOutFile2.c_str());
  
  
  std::cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~ " << std::endl;
  std::cout << " which = " << which << std::endl;
  std::cout << " energy = " << energy << std::endl;
  std::cout << " doWeight = " << doWeight << std::endl;
  
  std::cout << " NMAXY = " << NMAXY << std::endl;
  std::cout << " minNX = " << minNX << std::endl;
  std::cout << " NMAXX = " << NMAXX << std::endl;
  
  
  
}




