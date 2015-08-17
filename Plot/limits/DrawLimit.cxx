double findCrossingOfScan1D(TGraph& graph, double value) {
 double* x = graph.GetX();
 double* y = graph.GetY();
 int imin = 0;
 int n = graph.GetN();
 
 //---- check that it is on the "right" tail of the likelihood scan
 double xmin; 
 double ymin=1000;
 
 for (int i=0; i<n; i++) {
  if (y[i] < ymin && y[1] >=0) {
   ymin = y[i];
   xmin = x[i];
  }
 }
 
 for (int i=0; i<n; i++) {
  if (y[i] > value && x[i] >= xmin) {
   return x[i];
  }
 }
 
 return -999.;
}




double moveTGraph(TGraph* graph){
 double minLikelihood = 1000;
 double minX = -99;
 double* x = graph->GetX();
 double* y = graph->GetY();
 int imin = 0;
 int n = graph->GetN();
 for (int i=0; i<n; i++) {
  if (y[i] < minLikelihood) {
   minLikelihood = y[i];
   minX = x[i];
  }
 }
 
 //---- minimum of likelihood scan must bo 0
 if (minLikelihood != 0) {
//   std::cout << " minLikelihood = " << minLikelihood << std::endl;
  for (int i=0; i<n; i++) {
   graph->SetPoint(i,x[i],y[i]-minLikelihood);
  }
 }
 
 return minX;
}






void DrawLimit(std::string inputFile = "grid_7TeV-8TeV-toysScan.root", double defaultValue = 1.0, int ntoys = 105, std::string deltasFolder = ""){
 
 TChain* limit = new TChain("limit");
 
 
//  TFile* f = new TFile("higgsCombineTest.MultiDimFit.0j.toys.toysFreq.root","READ");  -> not very nice
//  TFile* f = new TFile("higgsCombineTest.MultiDimFit.0j.toys.noSyst.root","READ"); // -> reasonable good
//  TFile* f = new TFile("higgsCombineTest.MultiDimFit.0j.toys.toysFreq.new.root","READ"); // -> reasonable good
 
//  TFile* f = new TFile("Toys.higgsCombineTest.MultiDimFit.0j.StandardModel.root","READ"); // -> 0 jet final model
//  TFile* f = new TFile("Toys.higgsCombineTest.MultiDimFit.012j.StandardModel.root","READ"); // -> 0+1+2 jet final model
//  TFile* f = new TFile("forPaper/Toys.higgsCombineTest.MultiDimFit.012j.StandardModel.extendedRange.root","READ"); // -> 0+1+2 jet final model
 
//  limit->Add("forPaper/Toys.higgsCombineTest.MultiDimFit.012j.StandardModel.extendedRange.root"); // -> 0+1+2 jet final model
//  limit->Add("forPaper/Toys.higgsCombineTest.MultiDimFit.012j.StandardModel.extendedRange.bis.root"); // -> 0+1+2 jet final model
 
//  limit->Add("grid_7TeV-8TeV-toysScan.root"); // -> 0+1+2 jet 7+8 TeV 
 limit->Add(inputFile.c_str()); // -> 0+1+2 jet 7+8 TeV 
 
 
 
 
//  TFile* f = new TFile("Toys.higgsCombineTest.MultiDimFit.0j.Gamma.root","READ");
//  TFile* f = new TFile("Toys.higgsCombineTest.MultiDimFit.0j.Gamma.bis.root","READ");
 //  TFile* f = new TFile("Toys.higgsCombineTest.MultiDimFit.0j.GammaAndRF.root","READ");
//  TTree* limit = (TTree*) f->Get("limit");
 
 float deltaNLL;
 float CMS_zz4l_GGsm;
 float RF;
 int iToy;
 
 limit->SetBranchAddress("deltaNLL",&deltaNLL);
 limit->SetBranchAddress("CMS_zz4l_GGsm",&CMS_zz4l_GGsm);
//  limit->SetBranchAddress("RF",&RF);
 limit->SetBranchAddress("iToy",&iToy);
 
 
 TFile* newF = new TFile("test.root","RECREATE");
//  TH1F* OneSigma = new TH1F ("OneSigma","1 #sigma",20,0,60);
//  TH1F* TwoSigma = new TH1F ("TwoSigma","2 #sigma",20,0,60);
 TH1F* OneSigma = new TH1F ("OneSigma","1 #sigma",12,0,20);
 TH1F* TwoSigma = new TH1F ("TwoSigma","2 #sigma",12,0,20);
 
 TH1F* DeltaAtDefault = new TH1F ("DeltaAtDefault","2#Delta likelihood at nominal point",100,0,5);
 
 //  TH1F* TwoSigma = new TH1F ("TwoSigma","2 #sigma",80,0,80);
 
 TGraph* gr[300];
 TString* name[300];
 int iPointOnGraph[300];
 
 TCanvas* ccToy = new TCanvas("ccToy","ccToy",600,600);
 std::cout << " ntoys = " << ntoys << std::endl;
 ccToy->Divide(sqrt(ntoys)+1,sqrt(ntoys)+1);
//  ccToy->Divide(20,20);
//  ccToy->Divide(6,6);
//  ccToy->Divide(8,8);
 for (int nToy=0; nToy<ntoys; nToy++) {
  name[nToy] = new TString();
  name[nToy] -> Form ("toy_%d",nToy);
  gr[nToy] = new TGraph;
  gr[nToy] -> SetName (name[nToy]->Data());
  iPointOnGraph[nToy] = 0;
 }
 
 int iEvent=0;
 std::cout << " entries = " << limit->GetEntries() << std::endl;
 
 for (int iEntry=0; iEntry < limit->GetEntries() ; iEntry++) {
  limit->GetEntry(iEntry);   
  //   std::cout << " iEntry = " << iEntry << std::endl;
  
  if (deltaNLL<100) {
//    if (deltaNLL>=0 && deltaNLL<100) {
//    std::cout << " iToy = " << iToy << " iEntry = " << iEntry << " iPointOnGraph[" << iToy-1 << "] = " << iPointOnGraph[iToy-1] << std::endl;
   iToy = abs(iToy);
   gr[iToy-1]->SetPoint(iPointOnGraph[iToy-1],CMS_zz4l_GGsm,2*deltaNLL);
   iPointOnGraph[iToy-1]++;
  }
 }
 
 TCanvas* ccall[300];

 for (int nToy=0; nToy<ntoys; nToy++) {
  
  name[nToy] = new TString();
  name[nToy] -> Form ("cc_toy_%d",nToy);
//   ccall[nToy] = new TCanvas(name[nToy]->Data(),name[nToy]->Data(),400,400);
  
  
  if (gr[nToy] != 0x0 && gr[nToy]->GetN() >= 1 ) {
//    std::cout << " gr[" << nToy << "]->GetN() = " << gr[nToy]->GetN() << std::endl;
   gr[nToy]->RemovePoint(0);
   double minimumX = moveTGraph(gr[nToy]);

   ccToy->cd(nToy+1);
   gr[nToy]->SetMarkerSize(0.5);
   gr[nToy]->SetMarkerStyle(20);
   
   gr[nToy]->Draw("AP");
   
//    ccall[nToy] -> cd ();
//    ccall[nToy] -> SetGrid();
//    gr[nToy]->Draw("AP");

   
   double value_x_1sigma = findCrossingOfScan1D(*gr[nToy], 1.00);
   //   std::cout << " value_x_1sigma = " << value_x_1sigma << std::endl;
   if (value_x_1sigma != 0) OneSigma->Fill(value_x_1sigma);
     double value_x_2sigma = findCrossingOfScan1D(*gr[nToy], 3.84);
//    double value_x_2sigma = findCrossingOfScan1D(*gr[nToy], 2.00);
//      std::cout << " value_x_2sigma = " << value_x_2sigma << std::endl;
   if (value_x_2sigma != 0) TwoSigma->Fill(value_x_2sigma);
   
   
   DeltaAtDefault -> Fill (gr[nToy]->Eval(defaultValue)) ;
   
  }
 }
 
 TCanvas* cc = new TCanvas("cc","cc",800,600);
 cc->Divide(2,1);
 cc->cd(1);
 OneSigma->Draw();
 cc->cd(2);
 TwoSigma->Draw();
 
 
//  TFile* outputfile = new TFile("new.root","RECREATE");
 TFile* outputfile2 = new TFile("new2sigma.root","RECREATE");
 TwoSigma->Write();
 
 TFile* outputfile1 = new TFile("new1sigma.root","RECREATE");
 OneSigma->Write();
 
 TFile* outputfileDelta = new TFile("newDelta.root","RECREATE");
 DeltaAtDefault->Write();
 
 
 if (deltasFolder != "") {
  TFile* outputfile2bis = new TFile((deltasFolder + "/sigma2_" + inputFile.c_str()).c_str(),"RECREATE");
  TwoSigma->Write();
  
  TFile* outputfile1bis = new TFile((deltasFolder + "/sigma1_" + inputFile.c_str()).c_str(),"RECREATE");  
  OneSigma->Write();
  
  TFile* outputfileDeltabis = new TFile((deltasFolder + "/delta_" + inputFile.c_str()).c_str(),"RECREATE");
  DeltaAtDefault->Write();
  
 }
 
}