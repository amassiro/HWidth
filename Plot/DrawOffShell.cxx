{
 
 TFile* files[100];
 TH1F*  histo[100];
 TH1F*  histo_ggWW[100];
 TString nameFile;
 
//  int nGamma = 10+2-7;
 int nGamma = 10+2+5;
 
 
 
 
 
//  float Gamma[30] = {0.1, 0.2, 0.3, 0.4, 0.5, 1, 2, 3, 5, 7, 10, 20, 30};
 float Gamma[10+2+1+5] = {0.01,0.05,0.1, 0.3, 0.5, 1, 3, 5, 7, 10, 20, 30, 40, 50, 60, 100, 200,210};
//  float Gamma[10+2+1-7] = {0.01,0.05,0.1, 0.3, 0.5, 1};
 int Color[30]   = {1,2,3,4,5,6,9,7,8,40,30,41,31,42,32,43,33,44,34,45,35};
 for (int iGamma = 0; iGamma<nGamma; iGamma++) {
  std::ostringstream stress2;

  //---- 0 jet
//   stress2 << "final_4_0_0_" << Gamma[iGamma] << ".root";
  
  //---- 1 jet
  stress2 << "final_4_0_0_" << Gamma[iGamma] << ".root";

  nameFile.Form("%s",stress2.str().c_str());
//    nameFile.Form("final_4_0_0_%d.root",Gamma[iGamma]);
   files[iGamma] = new TFile (nameFile.Data(), "READ");
//    histo[iGamma] = (TH1F*) files[iGamma]->Get("qqHoff");
   histo[iGamma] = (TH1F*) files[iGamma]->Get("ggHoff");
   histo[iGamma]->SetLineColor(Color[iGamma]);

   histo_ggWW[iGamma] = (TH1F*) files[iGamma]->Get("ggWW");
   histo_ggWW[iGamma]->SetLineColor(Color[iGamma]);  
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
 
//  float bins[121];
//  int nBin = 120;
 
 
 
 
 //---- 0 jet
//  float bins[17*6+1];
//  int nBin = 17*6;
 
 //---- 1 jet
 float bins[15*4+1];
 int nBin = 15*4;
 
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
 global->GetXaxis()->SetTitle("#Gamma / #Gamma_{SM}");
 global->GetYaxis()->SetTitle("bin");
 global->GetZaxis()->SetRangeUser(0,200);
 
 
 TH2F* global_sbi = new TH2F("global_sbi","global_sbi",nGamma, Gamma, nBin, bins);
 for (int iGamma = 0; iGamma<nGamma; iGamma++) {
  for (int iBin = 0; iBin<nBin; iBin++) {
   global_sbi->Fill(Gamma[iGamma],bins[iBin],histo[iGamma]->GetBinContent(iBin+5) + histo_ggWW[iGamma]->GetBinContent(iBin+5));
  }
 }
 TCanvas* cc3 = new TCanvas("cc3","cc3",800,600);
 global_sbi->Draw("colz");
 global_sbi->GetXaxis()->SetTitle("#Gamma / #Gamma_{SM}");
 global_sbi->GetYaxis()->SetTitle("bin");
 global_sbi->GetZaxis()->SetRangeUser(0,200);
 
 
 
}



