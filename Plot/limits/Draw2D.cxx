
void Draw2D() {
 
   int n =  limit->Draw("2*deltaNLL:CMS_zz4l_GGsm:R","deltaNLL<10","goff");
 //   int n =  limit->Draw("2*deltaNLL:CMS_zz4l_GGsm:RV","","goff");
//  int n =  limit->Draw("2*deltaNLL:CMS_zz4l_GGsm:RF","deltaNLL<100","goff");
//  int n =  limit->Draw("2*deltaNLL:CMS_zz4l_GGsm:RV","deltaNLL<100","goff");
 
 //  int n =  limit->Draw("2*deltaNLL:R","","goff");
 TGraph2D *graphScan = new TGraph2D(n,limit->GetV2(),limit->GetV3(),limit->GetV1());
 graphScan->SetTitle("");
 graphScan->SetMarkerStyle(21);
 graphScan->SetMarkerColor(kRed);
 graphScan->SetLineColor(kRed);
 graphScan->GetXaxis()->SetTitle("R");
 graphScan->GetYaxis()->SetTitle("r = #Gamma/#Gamma_{SM}");
 graphScan->GetZaxis()->SetTitle("- 2#Delta logL");
 graphScan->GetZaxis()->SetRangeUser(0,10);

 graphScan->Draw("surf1");
 //  graphScan->Draw("colz");
 
 gPad->SetGrid();
 
}

