{
 //---- VBF central jet veto
 
//  r99t ../../../output_Latinos_tree_2012_2orMoreJet2012_wwewk/latino_2500_vbfToH500toWWTo2LAndTau2Nu.root
//  latino->Draw("1"," baseW * effW * triggW * ( (njet>=2 && njet<=3 && (jetpt3<=30 || !(jetpt3 > 30 && ( (jeteta1-jeteta3 > 0 && jeteta2-jeteta3 < 0) || (jeteta2-jeteta3 > 0 && jeteta1-jeteta3 < 0)))))       &&     (ch1*ch2 ==-1) && trigger==1. && pt1>20 && pt2>20 && mll>70. && (nextra==0) * (bveto_mu && bveto_ip && nbjettche==0) && mjj>500 && ptll>45 && njet>=2 && abs(eta1 - (jeteta1+jeteta2)/2)/detajj < 0.5 && abs(eta2 - (jeteta1+jeteta2)/2)/detajj < 0.5 && detajj>2.5)")
//  latino->Draw("1"," baseW * effW * triggW * (                                                                                                                                                                        (ch1*ch2 ==-1) && trigger==1. && pt1>20 && pt2>20 && mll>70. && (nextra==0) * (bveto_mu && bveto_ip && nbjettche==0) && mjj>500 && ptll>45 && njet>=2 && abs(eta1 - (jeteta1+jeteta2)/2)/detajj < 0.5 && abs(eta2 - (jeteta1+jeteta2)/2)/detajj < 0.5 && detajj>2.5)")
// 
//  latino->Draw("1", "baseW * effW * triggW * (mWW>130)*( 0.125*( (dataset == 160) || (dataset == 169) || (dataset == 176) || (dataset == 172)) - 0.250*( (dataset == 161) || (dataset == 175) || (dataset == 173) || (dataset == 170)) + 0.125*( (dataset == 162) || (dataset == 171) || (dataset == 174) || (dataset == 177)))")

//  TH1F h ("h","",10,0,2)
//  latino->Draw("1 >> h", "baseW * effW * triggW * ( (njet>=2 && njet<=3 && (jetpt3<=30 || !(jetpt3 > 30 && ( (jeteta1-jeteta3 > 0 && jeteta2-jeteta3 < 0) || (jeteta2-jeteta3 > 0 && jeteta1-jeteta3 < 0)))))       &&     (ch1*ch2 ==-1) && trigger==1. && pt1>20 && pt2>20 && mll>70. && (nextra==0) * (bveto_mu && bveto_ip && nbjettche==0) && mjj>500 && ptll>45 && njet>=2 && abs(eta1 - (jeteta1+jeteta2)/2)/detajj < 0.5 && abs(eta2 - (jeteta1+jeteta2)/2)/detajj < 0.5 && detajj>2.5) * (mWW>130)*( 0.125*( (dataset == 160) || (dataset == 169) || (dataset == 176) || (dataset == 172)) - 0.250*( (dataset == 161) || (dataset == 175) || (dataset == 173) || (dataset == 170)) + 0.125*( (dataset == 162) || (dataset == 171) || (dataset == 174) || (dataset == 177)))")
//  latino->Draw("1 >> h", "baseW * effW * triggW * (                                                                                                                                                                        (ch1*ch2 ==-1) && trigger==1. && pt1>20 && pt2>20 && mll>70. && (nextra==0) * (bveto_mu && bveto_ip && nbjettche==0) && mjj>500 && ptll>45 && njet>=2 && abs(eta1 - (jeteta1+jeteta2)/2)/detajj < 0.5 && abs(eta2 - (jeteta1+jeteta2)/2)/detajj < 0.5 && detajj>2.5) * (mWW>130)*( 0.125*( (dataset == 160) || (dataset == 169) || (dataset == 176) || (dataset == 172)) - 0.250*( (dataset == 161) || (dataset == 175) || (dataset == 173) || (dataset == 170)) + 0.125*( (dataset == 162) || (dataset == 171) || (dataset == 174) || (dataset == 177)))")
 
 
//  1.48437824100255966e-02
//  3.55644124818523043e-04
 
//  1.81118901818990707e-02
//  4.00155001845930926e-04
 
 
 
 
 TH1F* h_powheg_norm = new TH1F ("powheg_norm","powheg",2, 0, 2); 
 TH1F* h_powheg = new TH1F ("powheg","powheg",2, 0, 2);

 TH1F* h_phantom_norm = new TH1F ("phantom_norm","phantom",2, 0, 2); 
 TH1F* h_phantom = new TH1F ("phantom","phantom",2, 0, 2);

 
 //---- 0 = cjv, 1 = !cjv
 h_powheg -> SetBinContent(1,5.494381e-01);
 h_powheg -> SetBinContent(2,5.767007e-01-5.494381e-01);
 h_powheg -> SetBinError(1,0);
 h_powheg -> SetBinError(2,0);
 
 h_powheg->SetFillColor(kBlue);
 h_powheg->SetLineColor(kBlue);
 h_powheg->SetFillStyle(3004);
 
 h_powheg->Sumw2();
 
 h_powheg_norm = (TH1F*) h_powheg->Clone();
 float integral = h_powheg_norm->Integral();
 h_powheg_norm -> Scale (1. / integral);

 
 h_phantom -> SetBinContent(1,1.48437824100255966e-02);
 h_phantom -> SetBinContent(2,1.81118901818990707e-02-1.48437824100255966e-02);

 h_phantom -> SetBinError(1,3.55644124818523043e-04);
 h_phantom -> SetBinError(2,4.00155001845930926e-04);
 
 h_phantom->SetFillColor(kRed);
 h_phantom->SetLineColor(kRed);
 h_phantom->SetFillStyle(3004);
 
 h_phantom->Sumw2();
 
 h_phantom_norm = (TH1F*) h_phantom->Clone();
 integral = h_phantom_norm->Integral();
 h_phantom_norm -> Scale (1. / integral);
 
 
 TLegend * legend = new TLegend(0.70,0.90,0.90,0.70);
 legend -> AddEntry(h_powheg, "powheg");
 legend -> AddEntry(h_phantom, "phantom");
 legend -> SetFillColor(kWhite);
 
 
 TCanvas* cc = new TCanvas("cComposition","cComposition",1000,500);
 h_powheg->Draw("E");
 h_phantom->Draw("Esame");
 h_powheg->GetXaxis()->SetTitle("central jet veto");
 h_powheg->GetYaxis()->SetTitle("Expected events");
 legend->Draw();
 gPad->SetGrid();
 
 
 TCanvas* cc_norm = new TCanvas("cCompositionNorm","cCompositionNorm",1000,500);
 h_powheg_norm->Draw("E");
 h_phantom_norm->Draw("Esame");
 h_powheg_norm->GetXaxis()->SetTitle("central jet veto");
 h_powheg_norm->GetYaxis()->SetRangeUser(0,1);
 h_powheg_norm->GetYaxis()->SetTitle("relative composition");
 legend->Draw();
 gPad->SetGrid();

}


