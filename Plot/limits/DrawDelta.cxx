
void DrawDelta(std::string nameInput)
{
 
 TFile* f = new TFile(nameInput.c_str(),"READ");
 
 TH1F* DeltaAtDefault = (TH1F*) f->Get("DeltaAtDefault");
 
 DeltaAtDefault->Draw();
 std::cout << " \% > 3.84 = (" << 100 * DeltaAtDefault->Integral( DeltaAtDefault->GetXaxis()->FindBin(3.84) ,-1) / DeltaAtDefault->Integral(-1,-1);
 std::cout << " +/- " << 100 * sqrt(DeltaAtDefault->Integral( DeltaAtDefault->GetXaxis()->FindBin(3.84) ,-1)) / DeltaAtDefault->Integral(-1,-1);
 std::cout << ") % ";
 std::cout << std::endl;
 
}