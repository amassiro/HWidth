

void Draw2j() {
 
 TChain* latino = new TChain ("latino");
//  latino->Add("latinogg2vv_Hw25_CotHead_8TeV.root"); 
//  latino->Add("latinogg2vv_Hw25_CotTail_8TeV.root");
 latino->Add("latinogg2vv_Hw1_SigShoulder_8TeV.root"); 
 latino->Add("latinogg2vv_Hw1_SigTail_8TeV.root");
 
 //  TFile* fileWeight = new TFile ("scaleFactors.root");
 //  TFile* fileWeight = new TFile ("scaleFactors_invFirstOrd.root");
 TFile* fileWeight = new TFile ("scaleFactors_invFirstOrd_Norm.root");
 
 TH1F* h0up = (TH1F*) fileWeight->Get("h1_powheg_gg2vv_fitHighErr_2");
 TH1F* h0do = (TH1F*) fileWeight->Get("h1_powheg_gg2vv_fitLowErr_2");
 
//  TF1* funUp = new TF1("funUp", "[0] + [1]/x",120,1500);
//  TF1* funDo = new TF1("funDo", "[0] + [1]/x",120,1500);

//  TF1* funUp = new TF1("funUp", "pol10",120,1500);
//  TF1* funDo = new TF1("funDo", "pol10",120,1500);

 TF1* funUp = new TF1("funUp", "[0] + [1] * x + [2] * x * x + [3] * x * x * x + [4] * x * x * x * x + [5] / x",120,7500);
 TF1* funDo = new TF1("funDo", "[0] + [1] * x + [2] * x * x + [3] * x * x * x + [4] * x * x * x * x + [5] / x",120,7500);
 TF1* fNominal = new TF1("fNominal", "0.7777+161.9353/x",120,1500);
 
 funUp->SetLineColor(kBlue);
 funDo->SetLineColor(kRed);
 fNominal->SetLineColor(kBlack);
 
 TCanvas* ccFit = new TCanvas ("ccFit","",800,600);
 h0up->Fit("funUp");
 h0do->Fit("funDo");
 h0up->Draw();
 h0do->Draw("same");
 funUp->Draw("same");
 funDo->Draw("same");
 fNominal->Draw("same");
 
 TString funDoString = Form ("%f + %f * mWW + %f * mWW * mWW + %f * mWW * mWW * mWW + %f * mWW * mWW * mWW * mWW + %f / mWW", 
                             funDo->GetParameter(0),
                             funDo->GetParameter(1),
                             funDo->GetParameter(2),
                             funDo->GetParameter(3),
                             funDo->GetParameter(4),                             
                             funDo->GetParameter(5)     
 );
 
 TString funUpString = Form ("%f + %f * mWW + %f * mWW * mWW + %f * mWW * mWW * mWW + %f * mWW * mWW * mWW * mWW + %f / mWW", 
                             funUp->GetParameter(0),
                             funUp->GetParameter(1),
                             funUp->GetParameter(2),
                             funUp->GetParameter(3),
                             funUp->GetParameter(4),                             
                             funUp->GetParameter(5)                             
 );
 
 TCanvas* ccDistro = new TCanvas ("ccDistro","",800,600);
 
 TString variable = Form ("mth");
 TString cut = Form ("    trigger==1. \
                      &&  ((ch1*ch2)<0 && pt1>20 && pt2>10) \
                      &&  zveto==1 \
                      &&  pfmet>20. \
                      &&  mpmet>20. \
                      &&  mll>12 \
                      &&  bveto_mu==1  \
                      &&  nextra==0  \
                      &&  bveto_ip==1 \
                      &&  nbjettche==0");
 
 
 cut = Form ("(%s) && njet==2 && ( ptll>45 && (njet>=2 && njet<=3 && (jetpt3<=30 || !(jetpt3 > 30 && (  (jeteta1-jeteta3 > 0 && jeteta2-jeteta3 < 0) || (jeteta2-jeteta3 > 0 && jeteta1-jeteta3 < 0)))))   && abs(eta1 - (jeteta1+jeteta2)/2)/detajj < 0.5 && abs(eta2 - (jeteta1+jeteta2)/2)/detajj < 0.5      && detajj>2.5     && mjj>500 && \
                     (   (mll<70 && pt2<40) || (mll>=70 && pt2>20 && pt1>20)  )  )  \
               &&    (mll>=70)", cut.Data());
 
 
 
 
 const int NBINS = 17;
 Double_t edges[NBINS+ 1] = {-1.00, -0.70, -0.60, -0.50, -0.40, -0.30, -0.20, -0.10, 0.00, 0.10, 0.20, 0.30, 0.40, 0.50, 0.60, 0.70, 0.80, 1.00};
 
 TH1F* nominal = new TH1F("nominal","",NBINS, edges);
 TH1F* up      = new TH1F("up","",NBINS, edges);
 TH1F* down    = new TH1F("down","",NBINS, edges);
 
 TString toDraw;
 TString toCut;
 
 nominal->Sumw2();
 
 toDraw = Form ("(%s)*(0.7777+161.9353/mWW) >> nominal", variable.Data());
 toCut = Form ("(%s)*(1.0753-48.9352/mWW)", cut.Data());
 latino->Draw(toDraw.Data(), toCut.Data());
 
 toDraw = Form ("(%s) >> up", variable.Data());
 toCut = Form ("(%s)*(%s)", cut.Data(),funUpString.Data());
 latino->Draw(toDraw.Data(), toCut.Data());
 
 toDraw = Form ("(%s) >> down", variable.Data());
 toCut = Form ("(%s)*(%s)", cut.Data(),funDoString.Data());
 latino->Draw(toDraw.Data(), toCut.Data());
 
 float integral    = nominal->Integral();
 float integral_up = up->Integral();
 float integral_do = down->Integral();
 
 nominal->Scale (1./integral);
 up  ->Scale (1./integral_up);
 down->Scale (1./integral_do);
 
 nominal->SetLineStyle(2);
 down->SetLineStyle(3);
 
 nominal->SetFillColor(kBlack);
 nominal->SetFillStyle(3001);
 
 nominal->SetLineColor(kBlack);
 up  ->SetLineColor(kBlue);
 down->SetLineColor(kRed);
 
 nominal->SetLineWidth(2);
 up  ->SetLineWidth(2);
 down->SetLineWidth(2);
 
 nominal->Draw("E2");
 up->Draw("same");
 down->Draw("same");
 
 
 
 
}
