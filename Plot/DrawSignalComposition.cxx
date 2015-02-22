{
 
 TH1F* h_qqH = new TH1F ("qqH","qqH",3, 0, 3);
 TH1F* h_ggH = new TH1F ("ggH","ggH",3, 0, 3);
 
 //---- 0 jet
 h_qqH -> SetBinContent(1,0.0850);
 h_ggH -> SetBinContent(1,9.8382);
  
 //---- 1 jet
 h_qqH -> SetBinContent(2, 0.4449);
 h_ggH -> SetBinContent(2, 6.3889);
 
 //---- 2 jet
 h_qqH -> SetBinContent(3, 0.2723);
 h_ggH -> SetBinContent(3, 0.2261);
 
    
 h_qqH->SetFillColor(kBlue);
 h_qqH->SetLineColor(kBlue);
 h_qqH->SetFillStyle(3004);
 
 h_ggH->SetFillColor(kRed);
 h_ggH->SetLineColor(kRed);
 h_ggH->SetFillStyle(3003);
 
 TLegend * legend = new TLegend(0.83,0.93,0.95,0.20);
 legend -> AddEntry(h_ggH, "ggH");
 legend -> AddEntry(h_qqH, "qqH");
 legend -> SetFillColor(kWhite);
 
 THStack* hs = new THStack("st","");
 hs->Add(h_qqH);
 hs->Add(h_ggH);
 
 TCanvas* cc = new TCanvas("cComposition","cComposition",1000,500);
 hs->Draw("C");
 hs->GetXaxis()->SetTitle("number of jets");
 hs->GetXaxis()->SetRangeUser(110,600);
 hs->GetYaxis()->SetRangeUser(0,1);
 hs->GetYaxis()->SetTitle("Relative composition");
 legend->Draw();
 gPad->SetGrid();
 
 TCanvas* cc_ggH = new TCanvas("cc_ggH","cc_ggH",800,500);
 h_ggH->Draw("E4");
 TCanvas* cc_qqH = new TCanvas("cc_qqH","cc_qqH",800,500);
 h_qqH->Draw("E4");
 
 
 
 
 
}


