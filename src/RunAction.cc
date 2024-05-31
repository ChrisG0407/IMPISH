#include "RunAction.hh"
#include "Analysis.hh"
#include "PrimaryGeneratorAction.hh"
#include "DetectorConstruction.hh"

#include "G4AccumulableManager.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4UnitsTable.hh"
#include "G4RunManager.hh"

#include "HistoManager.hh"

#include "G4Run.hh"
#include "G4SystemOfUnits.hh"
#include "G4Threading.hh"

namespace ImpressForGrips
{
RunAction::RunAction() :
  G4UserRunAction(), fHistoManager(0)
{
 fHistoManager = new HistoManager();
}

RunAction::~RunAction()
{
  delete fHistoManager;
}

void RunAction::BeginOfRunAction(const G4Run*)
{ 
  //Creating the histograms
  //
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
  if ( analysisManager->IsActive() ) {
    analysisManager->OpenFile();
  } 
  Analysis::instance().initFiles(IsMaster());
}

void RunAction::EndOfRunAction(const G4Run*)
{
  //Saving the histograms
  //
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
  if ( analysisManager->IsActive() ) {
    analysisManager->Write();
    analysisManager->CloseFile();
    }
  Analysis::instance().saveFiles(IsMaster());
}
}
