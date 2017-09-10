#include <iostream>
#include <random>
#include <string>
#include "species.hpp"
#include "reaction.hpp"

Species randomSpecies(std::string n, bool food = false)
{
  float potential, concentration, inflow, decay;

  potential = std::rand() / (float)RAND_MAX * 7.5;
  concentration = std::rand() / (float)RAND_MAX * 2;
  inflow = (food) ? std::rand() / (float)RAND_MAX * 1 : 0;
  decay = std::rand() / (float)RAND_MAX * 1;

  return Species(n, potential, concentration, decay, inflow);
}

void printSpecies(const Species *speciesPtr)
{
  std::cout
      << "\tSpecies " << speciesPtr->getName() << " parameters:\n"
      << "\t\tpotential: " << speciesPtr->getPotential() << '\n'
      << "\t\tconcentration: " << speciesPtr->getConcentration() << '\n'
      << "\t\tdecay: " << speciesPtr->getDecay() << '\n'
      << "\t\tinflow: " << speciesPtr->getInflow() << std::endl;
}

int main()
{
  std::srand(20);

  std::vector<Species *> reactants, products;
  Species chemicals[3] = {randomSpecies("10"), randomSpecies("01"), randomSpecies("1001")};
  reactants.push_back(&chemicals[0]);
  reactants.push_back(&chemicals[1]);
  products.push_back(&chemicals[2]);

  Reaction r1(reactants, products, 1, 0.5, "R1", "polymer");

  std::cout << "Reaction " << r1.name << " of type " << r1.chemistry << std::endl;
  std::cout << "Reactants:\n";
  for (auto reactantPtr : r1.getReactants())
    printSpecies(reactantPtr);
  std::cout << "Products:\n";
  for (auto productPtr : r1.getProducts())
    printSpecies(productPtr);

  float dt = 0.1;
  r1.react(dt);
  std::cout << "\nAfter reaction for " << dt << std::endl;
  std::cout << "Reactants:\n";
  for (auto reactantPtr : r1.getReactants())
    printSpecies(reactantPtr);
  std::cout << "Products:\n";
  for (auto productPtr : r1.getProducts())
    printSpecies(productPtr);
}