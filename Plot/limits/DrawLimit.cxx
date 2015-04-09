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
 
//  TFile* f = new TFile("Toys.higgsCombineTest.MultiDimFit.0j.Gamma.root","READ");
 TFile* f = new TFile("Toys.higgsCombineTest.MultiDimFit.0j.Gamma.bis.root","READ");
 //  TFile* f = new TFile("Toys.higgsCombineTest.MultiDimFit.0j.GammaAndRF.root","READ");
 TTree* limit = (TTree*) f->Get("limit");
 
 float deltaNLL;
 float CMS_zz4l_GGsm;
 float RF;
 
 limit->SetBranchAddress("deltaNLL",&deltaNLL);
 limit->SetBranchAddress("CMS_zz4l_GGsm",&CMS_zz4l_GGsm);
//  limit->SetBranchAddress("RF",&RF);
 
 
 TFile* newF = new TFile("test.root","RECREATE");
 TH1F* OneSigma = new TH1F ("OneSigma","1 #sigma",20,0,40);
 TH1F* TwoSigma = new TH1F ("TwoSigma","2 #sigma",40,0,80);
 
 TGraph* gr[300];
 TString* name[300];
 TCanvas* ccToy = new TCanvas("ccToy","ccToy",600,600);
//  ccToy->Divide(10,10);
 ccToy->Divide(20,20);
 
 int iEvent=0;
 std::cout << " entries = " << limit->GetEntries() << std::endl;
 for (int iToy=0; iToy<300; iToy++) {
  name[iToy] = new TString();
  name[iToy] -> Form ("toy_%d",iToy);
  gr[iToy] = new TGraph;
  gr[iToy] -> SetName (name[iToy]->Data());
  int iPointOnGraph = 0;
  for (int iPoint=0; iPoint<252; iPoint++) {
   limit->GetEntry(iEvent);
   iEvent++;
   if (deltaNLL>=0 && deltaNLL<100) {
    gr[iToy]->SetPoint(iPointOnGraph,CMS_zz4l_GGsm,2*deltaNLL);
    iPointOnGraph++;
   }
  }
  
  gr[iToy]->RemovePoint(0);
  ccToy->cd(iToy+1);
  gr[iToy]->Draw("AP");
  
  double value_x_1sigma = findCrossingOfScan1D(*gr[iToy], 1.00);
//   std::cout << " value_x_1sigma = " << value_x_1sigma << std::endl;
  if (value_x_1sigma != 0) OneSigma->Fill(value_x_1sigma);
//   double value_x_2sigma = findCrossingOfScan1D(*gr[iToy], 3.84);
  double value_x_2sigma = findCrossingOfScan1D(*gr[iToy], 2.00);
  //   std::cout << " value_x_2sigma = " << value_x_2sigma << std::endl;
  if (value_x_2sigma != 0) TwoSigma->Fill(value_x_2sigma);
  
 }
 
 TCanvas* cc = new TCanvas("cc","cc",800,600);
 cc->Divide(2,1);
 cc->cd(1);
 OneSigma->Draw();
 cc->cd(2);
 TwoSigma->Draw();
 
}