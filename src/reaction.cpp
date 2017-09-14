#include <string>
#include <deque>
#include <map>
#include <iterator>
#include "reaction.hpp"

Reaction::Reaction(const std::deque<Species *> &r, const std::deque<Species *> &p, float fr, float br, const std::string n, const std::string c) : reactants(r.begin(), r.end()), products(p.begin(), p.end()), name_(n), chemistry_(c)
{
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
    changes[reactantPtr->name()] = dt * (backwardRate() * totalConcProducts - forwardRate() * totalConcReactants - reactantPtr->getDecay() * reactantPtr->getConcentration() + reactantPtr->getInflow());

  for (auto const &productPtr : products)
    changes[productPtr->name()] = dt * (forwardRate() * totalConcReactants - backwardRate() * totalConcReactants - productPtr->getDecay() * productPtr->getConcentration() + productPtr->getInflow());

  return changes;
}

void Reaction::update(const std::map<std::string, float> &concChanges)
{
  float newConcentration;
  for (auto &reactantPtr : reactants)
  {
    newConcentration = reactantPtr->getConcentration() + concChanges.at(reactantPtr->name());
    if (newConcentration < 0)
      newConcentration = 0;
    reactantPtr->setConcentration(newConcentration);
  }
  for (auto &productPtr : products)
  {
    newConcentration = productPtr->getConcentration() + concChanges.at(productPtr->name());
    if (newConcentration < 0)
      newConcentration = 0;
    productPtr->setConcentration(productPtr->getConcentration() + concChanges.at(productPtr->name()));
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

const std::string &Reaction::name() const { return name_; }

const std::string &Reaction::type() const { return chemistry_; }

const std::deque<Species *> &Reaction::allReactants() const { return reactants; }

const std::deque<Species *> &Reaction::allProducts() const { return products; }

const int Reaction::numReactants() const { return reactants.size(); }

const int Reaction::numProducts() const { return products.size(); }

bool Reaction::hasReactant(Species &species) const
{
  for (const auto &reactantPtr : reactants)
    if (*reactantPtr == species)
      return true;

  return false;
}

bool Reaction::hasProduct(Species &species) const
{
  for (const auto &productPtr : products)
    if (*productPtr == species)
      return true;

  return false;
}

bool Reaction::operator==(const Reaction &reaction) const
{
  if ((this->numProducts() != reaction.numProducts()) || this->numReactants() != reaction.numReactants())
    return false;

  for (const auto &reactantPtr : reactants)
    if (!reaction.hasReactant(*reactantPtr))
      return false;

  for (const auto &productPtr : products)
    if (!reaction.hasProduct(*productPtr))
      return false;

  return true;
}