
# ---- shape based analysis
# GetTop_Macro_forDataCard_Complete(int iWP, std::string suffix = "of", std::string whatAnalysis = "shape", bool doEnrichToGetEvents = false, int binCutPt = 0, int binTCHE = 0

# pt 0 thce 0

rm test/HWidth/ttbar/result-eff-shape-of-pt-0-tche-0.txt
root -l test/HWidth/ttbar/GetTop-Macro-forDataCard-Complete.cxx\(0,\"of\"\,\"shape\",true,0,0\)
rm TopCard_2j-shape-of-pt-0-tche-0.txt
cat test/HWidth/ttbar/result-shape-of-pt-0-tche-0-0.txt >>  TopCard_2j-shape-of-pt-0-tche-0.txt
rm TopCard_2j-shape-of-pt-0-tche-0-ScaleFactor.txt
cat test/HWidth/ttbar/result-SF-shape-of-pt-0-tche-0-0.txt >>  TopCard_2j-shape-of-pt-0-tche-0-ScaleFactor.txt

