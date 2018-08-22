#include <vector>

struct Particle {
   Particle() : fEnergy(0.0), pid(0) { }
   double fEnergy;
   int pid;
};

struct Event {
   std::vector<Particle> fParticles;
};
