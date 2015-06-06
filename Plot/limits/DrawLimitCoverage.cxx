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






void DrawLimitCoverage(std::string inputFile = "grid_7TeV-8TeV-toysScan.root", double expectedLimit = 15.0){
 
 TChain* limit = new TChain("limit");
 
 limit->Add(inputFile.c_str()); // -> 0+1+2 jet 7+8 TeV 
 

 int excluded = 0;
 int totaltoys= 0;
 
 
 float deltaNLL;
 float CMS_zz4l_GGsm;
 float RF;
 int iToy;
 
 limit->SetBranchAddress("deltaNLL",&deltaNLL);
 limit->SetBranchAddress("CMS_zz4l_GGsm",&CMS_zz4l_GGsm);
//  limit->SetBranchAddress("RF",&RF);
 limit->SetBranchAddress("iToy",&iToy);
 
 
 TGraph* gr[300];
 TString* name[300];
 int iPointOnGraph[300];
 
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
//    std::cout << " iToy = " << iToy << " iEntry = " << iEntry << std::endl;
   gr[iToy-1]->SetPoint(iPointOnGraph[iToy-1],CMS_zz4l_GGsm,2*deltaNLL);
   iPointOnGraph[iToy-1]++;
  }
 }
 
 for (int nToy=0; nToy<105; nToy++) {
    
  if (gr[nToy] != 0x0 && gr[nToy]->GetN() >= 1 ) {
   gr[nToy]->RemovePoint(0);
   double minimumX = moveTGraph(gr[nToy]);

   if (minimumX < expectedLimit) {
    excluded++;
   }
   
   totaltoys++; 
   
  }
 }
 
 std::cout << " ------------ " << std::endl;
 std::cout << " excluded = " << excluded << " / " << totaltoys << " = (" << 100.*excluded/totaltoys << " +/- " << sqrt(excluded)/totaltoys*100 << ") %" << std::endl;
 std::cout << " ------------ " << std::endl; 
 
}


