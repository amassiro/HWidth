{
 
 TFile* files[100];
 TH1F*  histo[100];
 TString nameFile;
 
 int Gamma[10] = {1,2,3,5,10,20,30};
 int Color[10] = {1,2,3,4,5,6,7,8,9};
 for (int iGamma = 0; iGamma<7; iGamma++) {
   nameFile.Form("final_4_0_0_%d.root",Gamma[iGamma]);
   files[iGamma] = new TFile (nameFile.Data(), "READ");
   histo[iGamma] = (TH1F*) files[iGamma]->Get("ggHoff");
   histo[iGamma]->SetLineColor(Color[iGamma]    );
 }
 
 TCanvas* cc = new TCanvas("cc","cc",1000,500);
 TLegend * legend = new TLegend(0.70,0.90,0.90,0.70);
 
 histo[0]->GetYaxis()->SetRangeUser(-10,20);
 for (int iGamma = 0; iGamma<7; iGamma++) {
  if (iGamma==0) histo[iGamma]->Draw();
  else           histo[iGamma]->Draw("same");
 
  nameFile.Form("#Gamma %d SM",Gamma[iGamma]);
  legend -> AddEntry(histo[iGamma], nameFile);
 }

 legend -> SetFillColor(kWhite);
 legend->Draw();
 gPad->SetGrid();
 
 
}


