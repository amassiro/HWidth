void drawOffWithWithoutWeight(TString var, TString cutAdditional = "1") {

 //  From /home/amassiro/Latinos/Shape/tree_skim_all_hwidth
 //---- r99t  drawOffWithWithoutWeight.cxx\(\"njet*\(njet\<2\)+2*\(njet\>1\)\"\)
 
 TFile *_file0 = TFile::Open("latinogg2vv_Hw1_SigShoulder_8TeV.root");

 TTree* t0 = (TTree*) _file0->Get("latino");

 TCanvas* cc = new TCanvas("cc","",800,600);

 TString cut;

 //---- apply weight
 cut = Form ("(%s) * ((((njet==0) * (13.3258/5.85323)) + ((njet==1) * (5.78547/1.40855)) + ((njet>=2) * (1.79911/0.195922)))) * ((!sameflav) * (mll>12 && pt1>20 && pt2>10 && ch1*ch2<0) * (baseW*puW*effW*triggW) * (trigger==1.) * (nextra==0) * (pfmet>20.) * (mpmet>20.) * (bveto_mu && bveto_ip && nbjettche==0))",cutAdditional.Data());
 t0->SetLineColor(kBlue);
 t0->SetLineWidth(2);
 t0->Draw(var.Data(),cut.Data());

 float integral = 0;
 TH2F *htemp = (TH2F*)gPad->GetPrimitive("htemp");
 htemp->SetName("htemp0");
 integral = htemp->Integral();
 std::cout << " integral = " << integral << std::endl;

 t0->SetLineColor(kRed);
 t0->SetLineWidth(2);

 cut = Form ("(%s) * ((!sameflav) * (mll>12 && pt1>20 && pt2>10 && ch1*ch2<0) * (baseW*puW*effW*triggW) * (trigger==1.) * (nextra==0) * (pfmet>20.) * (mpmet>20.) * (bveto_mu && bveto_ip && nbjettche==0))",cutAdditional.Data());
 t0->Draw(var.Data(),cut.Data(),"same");
 TH2F *htemp1 = (TH2F*)gPad->GetPrimitive("htemp");
 htemp1->SetName("htemp1");
 integral = htemp1->Integral();
 std::cout << " integral = " << integral << std::endl;

 cc->SetGrid();


 
 //---- normalized plot
 TCanvas* ccnorm = new TCanvas("ccnorm","",800,600);
 htemp1->DrawNormalized();
 htemp->DrawNormalized("same");
 ccnorm->SetGrid();


}


