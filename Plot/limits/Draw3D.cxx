

void Draw3D() {
 
 int n =  limit->Draw("2*deltaNLL:CMS_zz4l_GGsm:RF:RV","","goff");
 
 //  int n =  limit->Draw("2*deltaNLL:R","","goff");
 TGraph2D *graphScan = new TGraph2D(n,limit->GetV2(),limit->GetV3(),limit->GetV4(),limit->GetV1());
 graphScan->SetTitle("");
 graphScan->SetMarkerStyle(21);
 graphScan->SetMarkerColor(kRed);
 graphScan->SetLineColor(kRed);
 graphScan->Draw("colz");
 graphScan->GetZaxis()->SetTitle("RV");
 graphScan->GetYaxis()->SetTitle("RF");
 graphScan->GetXaxis()->SetTitle("r = #Gamma/#Gamma_{SM}");
 //  graphScan->GetZaxis()->SetTitle("- 2#Delta logL");
 //  graphScan->GetZaxis()->SetRangeUser(0,10);
 gPad->SetGrid();
}

