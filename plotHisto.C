{
  gROOT->Reset();
  
  // Draw histos filled by Geant4 simulation 
  //
  
  //Create root file name along with the canvas   
  TFile f = TFile("x-ray_beam.root");
  TCanvas* c1 = new TCanvas("c1", "  ");
  
  //1-D Histogram
  TH1D* hist1 = (TH1D*)f.Get("1");
  hist1->Draw("HIST");
  
}
