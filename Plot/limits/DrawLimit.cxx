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




void DrawLimit(){
 
 
 
//  TFile* f = new TFile("higgsCombineTest.MultiDimFit.0j.toys.toysFreq.root","READ");  -> not very nice
//  TFile* f = new TFile("higgsCombineTest.MultiDimFit.0j.toys.noSyst.root","READ"); // -> reasonable good
//  TFile* f = new TFile("higgsCombineTest.MultiDimFit.0j.toys.toysFreq.new.root","READ"); // -> reasonable good
 
//  TFile* f = new TFile("Toys.higgsCombineTest.MultiDimFit.0j.StandardModel.root","READ"); // -> 0 jet final model
//  TFile* f = new TFile("Toys.higgsCombineTest.MultiDimFit.012j.StandardModel.root","READ"); // -> 0+1+2 jet final model
 TFile* f = new TFile("Toys.higgsCombineTest.MultiDimFit.012j.StandardModel.extendedRange.root","READ"); // -> 0+1+2 jet final model
 
 
 
//  TFile* f = new TFile("Toys.higgsCombineTest.MultiDimFit.0j.Gamma.root","READ");
//  TFile* f = new TFile("Toys.higgsCombineTest.MultiDimFit.0j.Gamma.bis.root","READ");
 //  TFile* f = new TFile("Toys.higgsCombineTest.MultiDimFit.0j.GammaAndRF.root","READ");
 TTree* limit = (TTree*) f->Get("limit");
 
 float deltaNLL;
 float CMS_zz4l_GGsm;
 float RF;
 int iToy;
 
 limit->SetBranchAddress("deltaNLL",&deltaNLL);
 limit->SetBranchAddress("CMS_zz4l_GGsm",&CMS_zz4l_GGsm);
//  limit->SetBranchAddress("RF",&RF);
 limit->SetBranchAddress("iToy",&iToy);
 
 
 TFile* newF = new TFile("test.root","RECREATE");
 TH1F* OneSigma = new TH1F ("OneSigma","1 #sigma",20,0,40);
 TH1F* TwoSigma = new TH1F ("TwoSigma","2 #sigma",40,0,40);
//  TH1F* TwoSigma = new TH1F ("TwoSigma","2 #sigma",80,0,80);
 
 TGraph* gr[300];
 TString* name[300];
 int iPointOnGraph[300];
 
 TCanvas* ccToy = new TCanvas("ccToy","ccToy",600,600);
 ccToy->Divide(10,10);
//  ccToy->Divide(20,20);
//  ccToy->Divide(6,6);
//  ccToy->Divide(8,8);
 for (int nToy=0; nToy<105; nToy++) {
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
  
  if (deltaNLL>=0 && deltaNLL<100) {
   std::cout << " iToy = " << iToy << " iEntry = " << iEntry << std::endl;
   gr[iToy-1]->SetPoint(iPointOnGraph[iToy-1],CMS_zz4l_GGsm,2*deltaNLL);
   iPointOnGraph[iToy-1]++;
  }
 }
 
 TCanvas* ccall[300];

 for (int nToy=0; nToy<100; nToy++) {
  
  name[nToy] = new TString();
  name[nToy] -> Form ("cc_toy_%d",nToy);
//   ccall[nToy] = new TCanvas(name[nToy]->Data(),name[nToy]->Data(),400,400);
  
  
  if (gr[nToy] != 0x0) {
   gr[nToy]->RemovePoint(0);
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
   //   std::cout << " value_x_2sigma = " << value_x_2sigma << std::endl;
   if (value_x_2sigma != 0) TwoSigma->Fill(value_x_2sigma);
  }
 }
 
 TCanvas* cc = new TCanvas("cc","cc",800,600);
 cc->Divide(2,1);
 cc->cd(1);
 OneSigma->Draw();
 cc->cd(2);
 TwoSigma->Draw();
 
}