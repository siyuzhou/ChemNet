#include <iostream>
#include <random>
#include <string>
#include <deque>
#include "species.hpp"
#include "reaction.hpp"
#include "network.hpp"

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
      << "\tSpecies " << speciesPtr->name() << " parameters:\n"
      << "\t\tpotential: " << speciesPtr->getPotential() << '\n'
      << "\t\tconcentration: " << speciesPtr->getConcentration() << '\n'
      << "\t\tdecay: " << speciesPtr->getDecay() << '\n'
      << "\t\tinflow: " << speciesPtr->getInflow() << std::endl;
}

int main()
{
  std::srand(20);

  std::deque<Species *> reactants, products;
  Species chemicals[4] = {randomSpecies("10"), randomSpecies("01"), randomSpecies("1001"), randomSpecies("010")};
  reactants.push_back(&chemicals[0]);
  reactants.push_back(&chemicals[1]);
  products.push_back(&chemicals[2]);

  std::cout << (reactants[0]->name() == reactants[1]->name()) << ' ';
  std::cout << (*reactants[0] == *reactants[1]) << std::endl;

  Reaction r1(reactants, products, 1, 0.5, "R1", "polymer");

  std::cout << "Reaction " << r1.name() << " of type " << r1.type() << std::endl;
  std::cout << "Reactants:\n";
  for (auto reactantPtr : r1.allReactants())
    printSpecies(reactantPtr);
  std::cout << "Products:\n";
  for (auto productPtr : r1.allProducts())
    printSpecies(productPtr);

  float dt = 0.1;
  r1.react(dt);
  std::cout << "\nAfter reaction for " << dt << std::endl;
  std::cout << "Reactants:\n";
  for (auto reactantPtr : r1.allReactants())
    printSpecies(reactantPtr);
  std::cout << "Products:\n";
  for (auto productPtr : r1.allProducts())
    printSpecies(productPtr);
}