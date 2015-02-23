{

 TH1F* h_qqH_norm = new TH1F ("qqH_norm","qqH",3, 0, 3);
 TH1F* h_ggH_norm = new TH1F ("ggH_norm","ggH",3, 0, 3);

 
 TH1F* h_qqH = new TH1F ("qqH","qqH",3, 0, 3);
 TH1F* h_ggH = new TH1F ("ggH","ggH",3, 0, 3);
 
 //---- 0 jet
 h_qqH -> SetBinContent(1,3.1310);
 h_ggH -> SetBinContent(1,247.0227);
 h_qqH_norm -> SetBinContent(1,3.1310/(3.1310+247.0227));
 h_ggH_norm -> SetBinContent(1,247.0227/(3.1310+247.0227));
 
 //---- 1 jet
 h_qqH -> SetBinContent(2, 8.7510);
 h_ggH -> SetBinContent(2, 69.8991);
 h_qqH_norm -> SetBinContent(2, 8.7510/(8.7510+69.8991));
 h_ggH_norm -> SetBinContent(2, 69.8991/(8.7510+69.8991));
 
 
 //---- 2 jet
 h_qqH -> SetBinContent(3, 4.5291);
 h_ggH -> SetBinContent(3, 1.4172);
 h_qqH_norm -> SetBinContent(3, 4.5291/(4.5291+1.4172));
 h_ggH_norm -> SetBinContent(3, 1.4172/(4.5291+1.4172));
          
    
 h_qqH->SetFillColor(kBlue);
 h_qqH->SetLineColor(kBlue);
 h_qqH->SetFillStyle(3004);
 
 h_ggH->SetFillColor(kRed);
 h_ggH->SetLineColor(kRed);
 h_ggH->SetFillStyle(3003);



 h_qqH_norm->SetFillColor(kBlue);
 h_qqH_norm->SetLineColor(kBlue);
 h_qqH_norm->SetFillStyle(3004);
 
 h_ggH_norm->SetFillColor(kRed);
 h_ggH_norm->SetLineColor(kRed);
 h_ggH_norm->SetFillStyle(3003);



 
 TLegend * legend = new TLegend(0.83,0.93,0.95,0.20);
 legend -> AddEntry(h_ggH, "ggH");
 legend -> AddEntry(h_qqH, "qqH");
 legend -> SetFillColor(kWhite);
 
 THStack* hs = new THStack("st","");
 hs->Add(h_qqH);
 hs->Add(h_ggH);
 
 TCanvas* cc = new TCanvas("cComposition","cComposition",1000,500);
//  hs->Draw("C");
 hs->Draw("histo");
 hs->GetXaxis()->SetTitle("number of jets");
 hs->GetXaxis()->SetRangeUser(110,600);
 hs->GetYaxis()->SetRangeUser(0,1);
 hs->GetYaxis()->SetTitle("Expected events");
 legend->Draw();
 gPad->SetGrid();
 
 THStack* hs_norm = new THStack("st_norm","");
 hs_norm->Add(h_qqH_norm);
 hs_norm->Add(h_ggH_norm);
 
 TCanvas* cc_norm = new TCanvas("cCompositionNorm","cCompositionNorm",1000,500);
 hs_norm->Draw("histo");
 hs_norm->GetXaxis()->SetTitle("number of jets");
 hs_norm->GetXaxis()->SetRangeUser(110,600);
 hs_norm->GetYaxis()->SetRangeUser(0,1);
 hs_norm->GetYaxis()->SetTitle("relative composition");
 legend->Draw();
 gPad->SetGrid();
 



}


