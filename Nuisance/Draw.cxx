

void Draw() {
 
 TChain* latino = new TChain ("latino");
 latino->Add("latinogg2vv_Hw25_CotHead_8TeV.root"); 
 latino->Add("latinogg2vv_Hw25_CotTail_8TeV.root");
 
 TFile* fileWeight = new TFile ("scaleFactors.root");
 
 TH1F* h0up = (TH1F*) fileWeight->Get("h1_powheg_gg2vv_fitHighErr_0");
 TH1F* h0do = (TH1F*) fileWeight->Get("h1_powheg_gg2vv_fitLowErr_0");
 
 TString variable = Form ("HwidthMVAbkg*(mll>=70)");
 TString cut = Form ("1");
 
 latino->Draw(variable.Data(), cut.Data());
 
}