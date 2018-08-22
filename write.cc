#include <TFile.h>
#include <TSystem.h>
#include <TTree.h>

#include "event.h"

int main() {
   gSystem->Load("./libEvent.so");

   Particle particle1;
   Particle particle2;
   particle1.fEnergy = 1.0;
   particle1.fEnergy = 42.0;

   Event* event = new Event();
   event->fParticles.push_back(particle1);
   event->fParticles.push_back(particle2);

   TFile* file = new TFile("test.root", "RECREATE");
   TTree* tree = new TTree("Events", "");
   tree->Branch("EventBranch", &event, 32000, 99);
   tree->Fill();
   file->Write();
   file->Close();
}