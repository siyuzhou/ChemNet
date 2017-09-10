#include <string>
#include <vector>
#include <map>
#include <iterator>
#include "reaction.hpp"

Reaction::Reaction(const std::vector<Species *> r, const std::vector<Species *> p, float fr, float br, const std::string n, const std::string c) : chemistry(c), name(n)
{
  reactants = r;
  products = p;
  rateForward = fr;
  rateBackward = br;
}

const std::map<std::string, float> &Reaction::changeConcentration(float dt)
{
  float totalConcReactants = 1., totalConcProducts = 1.;
  for (auto const &reactantPtr : reactants)
  {
    totalConcReactants *= reactantPtr->concentration;
  }
  for (auto const &productPtr : products)
  {
    totalConcProducts *= productPtr->concentration;
  }

  std::map<std::string, float> changes;
  for (auto const &reactantPtr : reactants)
  {
    changes[reactantPtr->name] = backwardRate() * totalConcProducts - forwardRate() * totalConcReactants - reactantPtr->decay * reactantPtr->concentration + reactantPtr->inflow;
  }
  for (auto const &productPtr : products)
  {
    changes[productPtr->name] = forwardRate() * totalConcReactants - backwardRate() * totalConcReactants - productPtr->decay * productPtr->concentration + productPtr->inflow;
  }
  return changes;
}

void Reaction::update(const std::map<std::string, float> &concChanges)
{
  for (auto const &reactantPtr : reactants)
  {
    reactantPtr->concentration += concChanges.at(reactantPtr->name);
  }
  for (auto const &productPtr : products)
  {
    productPtr->concentration += concChanges.at(productPtr->name);
  }
}

void Reaction::react(float dt)
{
  update(changeConcentration(dt));
}

float Reaction::forwardRate()
{
  /*Stub. Will implement calculation.*/
  return rateForward;
}

float Reaction::backwardRate()
{
  /*Stub. Will implement calculation.*/
  return rateBackward;
}

const std::vector<Species *> &Reaction::getReactants() const { return reactants; }

const std::vector<Species *> &Reaction::getProducts() const { return products; }
