{
 //---- VBF central jet veto
 
//  latino->Draw("1"," baseW * effW * triggW * ( (njet>=2 && njet<=3 && (jetpt3<=30 || !(jetpt3 > 30 && ( (jeteta1-jeteta3 > 0 && jeteta2-jeteta3 < 0) || (jeteta2-jeteta3 > 0 && jeteta1-jeteta3 < 0)))))       &&     (ch1*ch2 ==-1) && trigger==1. && pt1>20 && pt2>20 && mll>70. && (nextra==0) * (bveto_mu && bveto_ip && nbjettche==0) && mjj>500 && ptll>45 && njet>=2 && abs(eta1 - (jeteta1+jeteta2)/2)/detajj < 0.5 && abs(eta2 - (jeteta1+jeteta2)/2)/detajj < 0.5 && detajj>2.5)")
//  latino->Draw("1"," baseW * effW * triggW * (                                                                                                                                                                        (ch1*ch2 ==-1) && trigger==1. && pt1>20 && pt2>20 && mll>70. && (nextra==0) * (bveto_mu && bveto_ip && nbjettche==0) && mjj>500 && ptll>45 && njet>=2 && abs(eta1 - (jeteta1+jeteta2)/2)/detajj < 0.5 && abs(eta2 - (jeteta1+jeteta2)/2)/detajj < 0.5 && detajj>2.5)")
 
 
 
 
 TH1F* h_powheg_norm = new TH1F ("powheg_norm","powheg",2, 0, 2);
 TH1F* h_ggH_norm = new TH1F ("ggH_norm","ggH",2, 0, 2);

 
 TH1F* h_powheg = new TH1F ("powheg","powheg",2, 0, 2);
 TH1F* h_ggH = new TH1F ("ggH","ggH",2, 0, 2);
 
 //---- 0 = cjv, 1 = !cjv
 h_powheg -> SetBinContent(1,5.494381e-01);
 h_powheg -> SetBinContent(2,5.767007e-01-5.494381e-01);
 
 h_powheg->SetFillColor(kBlue);
 h_powheg->SetLineColor(kBlue);
 h_powheg->SetFillStyle(3004);
 
 h_ggH->SetFillColor(kRed);
 h_ggH->SetLineColor(kRed);
 h_ggH->SetFillStyle(3003);

 
 h_ggH_norm->SetFillColor(kRed);
 h_ggH_norm->SetLineColor(kRed);
 h_ggH_norm->SetFillStyle(3003);

 h_powheg_norm

 
 TLegend * legend = new TLegend(0.83,0.93,0.95,0.20);
//  legend -> AddEntry(h_ggH, "ggH");
 legend -> AddEntry(h_powheg, "powheg");
 legend -> SetFillColor(kWhite);
 
 
 TCanvas* cc = new TCanvas("cComposition","cComposition",1000,500);
 h_powheg->Draw();
 h_powheg->GetXaxis()->SetTitle("central jet veto");
 h_powheg->GetYaxis()->SetTitle("Expected events");
 legend->Draw();
 gPad->SetGrid();
 
 
 TCanvas* cc_norm = new TCanvas("cCompositionNorm","cCompositionNorm",1000,500);
 h_powheg->DrawNormalized();
 h_powheg->GetXaxis()->SetTitle("central jet veto");
 h_powheg->GetYaxis()->SetRangeUser(0,1);
 h_powheg->GetYaxis()->SetTitle("relative composition");
 legend->Draw();
 gPad->SetGrid();
 



}


