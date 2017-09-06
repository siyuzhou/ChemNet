#include <iostream>
#include <random>
#include <string>
#include "species.hpp"

int main()
{
  std::string formula = "101";
  float potential, concentration, inflow, decay;

  std::srand(20);
  potential = std::rand() / (float)RAND_MAX * 7.5;
  concentration = std::rand() / (float)RAND_MAX * 2;
  inflow = std::rand() / (float)RAND_MAX * 1;
  decay = std::rand() / (float)RAND_MAX * 1;

  Species sp(formula, potential, concentration, decay, inflow);

  std::cout << "Species " << sp.getFormula() << " parameters:\n"
            << "potential: " << sp.getPotential() << '\n'
            << "concentration: " << sp.getConcentration() << '\n'
            << "decay: " << sp.getDecay() << '\n'
            << "inflow: " << sp.getInflow() << std::endl;
}