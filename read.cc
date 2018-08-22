#include <ROOT/RDataFrame.hxx>
#include <ROOT/RVec.hxx>

#include <TSystem.h>

#include <iostream>

int main() {
   gSystem->Load("./libEvent.so");

   ROOT::RDataFrame rdf("Events", "test.root");

   auto fnCutEnergy = [](ROOT::VecOps::RVec<double> energy) {
      for (unsigned i = 0; i < energy.size(); ++i) {
         if (energy[i] > 10.0) return true;
      }
      return false;
   };
   auto count = rdf.Filter(fnCutEnergy, {"fParticles.fEnergy"}).Count().GetValue();

   std::cout << "Count: " << count << std::endl;
}