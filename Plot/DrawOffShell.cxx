{
 
 TFile* files[100];
 TH1F*  histo[100];
 TString nameFile;
 
//  int nGamma = 10+2-7;
 int nGamma = 10+2;
 
//  float Gamma[30] = {0.1, 0.2, 0.3, 0.4, 0.5, 1, 2, 3, 5, 7, 10, 20, 30};
 float Gamma[10+2+1] = {0.01,0.05,0.1, 0.3, 0.5, 1, 3, 5, 7, 10, 20, 30,40};
//  float Gamma[10+2+1-7] = {0.01,0.05,0.1, 0.3, 0.5, 1};
 int Color[30]   = {1,2,3,4,5,6,9,7,8,40,30,41,31,42,32,43,33,44,34,45,35};
 for (int iGamma = 0; iGamma<nGamma; iGamma++) {
  std::ostringstream stress2;
  stress2 << "final_4_0_0_" << Gamma[iGamma] << ".root";
  nameFile.Form("%s",stress2.str().c_str());
//    nameFile.Form("final_4_0_0_%d.root",Gamma[iGamma]);
   files[iGamma] = new TFile (nameFile.Data(), "READ");
//    histo[iGamma] = (TH1F*) files[iGamma]->Get("qqHoff");
   histo[iGamma] = (TH1F*) files[iGamma]->Get("ggHoff");
   histo[iGamma]->SetLineColor(Color[iGamma]);
 }
 
 TCanvas* cc = new TCanvas("cc","cc",800,600);
 TLegend * legend = new TLegend(0.30,0.90,0.60,0.70);
 
 histo[0]->GetYaxis()->SetRangeUser(-10,20);
 histo[0]->GetYaxis()->SetTitle("events");
 for (int iGamma = 0; iGamma<nGamma; iGamma++) {
  if (iGamma==0) histo[iGamma]->Draw();
  else           histo[iGamma]->Draw("same");
 
  nameFile.Form("#Gamma %f SM",Gamma[iGamma]);
  legend -> AddEntry(histo[iGamma], nameFile);
 }

 legend -> SetFillColor(kWhite);
 legend->Draw();
 gPad->SetGrid();
 
 
 
 
 
//  float bins[11] = {0,1,2,3,4,5,6,7,8,9,10};
//  int nBin = 10;
 
 float bins[121];
 int nBin = 120;
 for (int iBin = 0; iBin<=nBin; iBin++) {
  bins[iBin] = iBin;
 }
 
 TH2F* global = new TH2F("global","global",nGamma, Gamma, nBin, bins);
 for (int iGamma = 0; iGamma<nGamma; iGamma++) {
  for (int iBin = 0; iBin<nBin; iBin++) {
//    global->Fill(Gamma[iGamma],bins[iBin],histo[iGamma]->GetBinContent(iBin+93));
   global->Fill(Gamma[iGamma],bins[iBin],histo[iGamma]->GetBinContent(iBin+5));
  }
 }
 TCanvas* cc2 = new TCanvas("cc2","cc2",800,600);
 global->Draw("colz");
 
}



