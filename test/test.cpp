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

void printSpecies(const Species &species)
{
  std::cout
      << "\tSpecies " << species.name() << " parameters:\n"
      << "\t\tpotential: " << species.getPotential() << '\n'
      << "\t\tconcentration: " << species.getConcentration() << '\n'
      << "\t\tdecay: " << species.getDecay() << '\n'
      << "\t\tinflow: " << species.getInflow() << std::endl;
}

void printReaction(const Reaction &reaction)
{
  std::cout << "Reaction " << reaction.name() << " of type " << reaction.type() << " ";
  for (const auto reactantPtr : reaction.allReactants())
    std::cout << reactantPtr->name() << ' ';
  std::cout << "-> ";
  for (const auto productPtr : reaction.allProducts())
    std::cout << productPtr->name() << ' ';
  std::cout << std::endl;
}

void testReaction()
{
  std::srand(20);

  std::deque<Species *> reactants, products;
  Species chemicals[4] = {randomSpecies("10"), randomSpecies("01"), randomSpecies("1001")};
  reactants.push_back(&chemicals[0]);
  reactants.push_back(&chemicals[1]);
  products.push_back(&chemicals[2]);

  Reaction r1(reactants, products, 1, 0.5, "R1", "polymer");

  std::cout << "Reaction " << r1.name() << " of type " << r1.type() << std::endl;
  std::cout << "Reactants:\n";
  for (const auto reactantPtr : r1.allReactants())
    printSpecies(*reactantPtr);
  std::cout << "Products:\n";
  for (const auto productPtr : r1.allProducts())
    printSpecies(*productPtr);

  float dt = 0.1;
  r1.react(dt);
  std::cout << "\nAfter reaction for " << dt << std::endl;
  std::cout << "Reactants:\n";
  for (const auto reactantPtr : r1.allReactants())
    printSpecies(*reactantPtr);
  std::cout << "Products:\n";
  for (const auto productPtr : r1.allProducts())
    printSpecies(*productPtr);
}

void testNetwork()
{
  std::srand(30);
  Network network;

  std::deque<std::string> rNames = {"10", "01"};
  std::deque<std::string> pNames = {"1001"};

  std::deque<Species *> reactants, products;
  for (const auto &rname : rNames)
  {
    Species reactant = randomSpecies(rname);
    reactants.push_back(&reactant);
  }
  for (const auto &pname : pNames)
  {
    Species product = randomSpecies(pname);
    products.push_back(&product);
  }

  float forwardRate = std::rand() / (float)RAND_MAX;
  float backwardRate = std::rand() / (float)RAND_MAX;

  Reaction reaction1 = Reaction(reactants, products, forwardRate, backwardRate, "R1", "Polymer");

  network.addReaction(reaction1);

  printReaction(reaction1);
}

int main()
{
  // testReaction();
  testNetwork();
}