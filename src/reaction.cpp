#include <string>
#include <vector>
#include <map>
#include <iterator>
#include "reaction.hpp"

Reaction::Reaction(const std::vector<Species *> &r, const std::vector<Species *> &p, float fr, float br, const std::string n, const std::string c) : name(n), chemistry(c)
{
  reactants = r;
  products = p;
  rateForward = fr;
  rateBackward = br;
}

const std::map<std::string, float> Reaction::changeConcentration(float dt)
{
  float totalConcReactants = 1., totalConcProducts = 1.;
  for (auto const &reactantPtr : reactants)
    totalConcReactants *= reactantPtr->getConcentration();

  for (auto const &productPtr : products)
    totalConcProducts *= productPtr->getConcentration();

  std::map<std::string, float> changes;
  for (auto const &reactantPtr : reactants)
    changes[reactantPtr->getName()] = dt * (backwardRate() * totalConcProducts - forwardRate() * totalConcReactants - reactantPtr->getDecay() * reactantPtr->getConcentration() + reactantPtr->getInflow());

  for (auto const &productPtr : products)
    changes[productPtr->getName()] = dt * (forwardRate() * totalConcReactants - backwardRate() * totalConcReactants - productPtr->getDecay() * productPtr->getConcentration() + productPtr->getInflow());

  return changes;
}

void Reaction::update(const std::map<std::string, float> &concChanges)
{
  float newConcentration;
  for (auto const &reactantPtr : reactants)
  {
    newConcentration = reactantPtr->getConcentration() + concChanges.at(reactantPtr->getName());
    if (newConcentration < 0)
      newConcentration = 0;
    reactantPtr->setConcentration(newConcentration);
  }
  for (auto const &productPtr : products)
  {
    newConcentration = productPtr->getConcentration() + concChanges.at(productPtr->getName());
    if (newConcentration < 0)
      newConcentration = 0;
    productPtr->setConcentration(productPtr->getConcentration() + concChanges.at(productPtr->getName()));
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
