#include <iostream>
#include <random>
#include <string>
#include "species.hpp"
#include "reaction.hpp"

int main()
{
  std::string name = "101";
  float potential, concentration, inflow, decay;

  std::srand(20);
  potential = std::rand() / (float)RAND_MAX * 7.5;
  concentration = std::rand() / (float)RAND_MAX * 2;
  inflow = std::rand() / (float)RAND_MAX * 1;
  decay = std::rand() / (float)RAND_MAX * 1;

  Species sp(name, potential, concentration, decay, inflow);

  std::cout << "Species " << sp.name << " parameters:\n"
            << "potential: " << sp.potential << '\n'
            << "concentration: " << sp.concentration << '\n'
            << "decay: " << sp.decay << '\n'
            << "inflow: " << sp.inflow << std::endl;
}