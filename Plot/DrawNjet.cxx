{
 
 TH1F* hafter_offshell = new TH1F("hafter_offshell","weighted",3,0,3);
 hafter_offshell->SetBinContent(1,9.0428);
 hafter_offshell->SetBinContent(2,9.1635);
 hafter_offshell->SetBinContent(3,8.8432);
 
 hafter_offshell->SetLineColor(kBlue);
 hafter_offshell->SetLineWidth(2.0);
 hafter_offshell->Scale(1. / hafter_offshell->Integral());
 
 
 TH1F* hbefore_offshell = new TH1F("hbefore_offshell","un-weighted",3,0,3);
 hbefore_offshell->SetBinContent(1,9.0428 / (13.3258/5.85323));
 hbefore_offshell->SetBinContent(2,9.1635 / (5.78547/1.40855));
 hbefore_offshell->SetBinContent(3,8.8432 / (1.79911/0.195922));
 
 hbefore_offshell->SetLineColor(kRed);
 hbefore_offshell->SetLineWidth(2.0);
 hbefore_offshell->Scale(1. / hbefore_offshell->Integral());
 
 hbefore_offshell->Draw();
 hafter_offshell->Draw("same");
 
 hbefore_offshell->GetXaxis()->SetTitle("number of jets");
 hbefore_offshell->GetYaxis()->SetTitle("relative contribution");

 gPad->BuildLegend();
 gPad->SetGrid();
 
}


