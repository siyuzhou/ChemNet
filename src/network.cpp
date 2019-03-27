#include <deque>
#include "network.hpp"

Network::Network() {}

bool Network::addReaction(Reaction &newReaction)
{
  if (findReaction(newReaction) != nullptr)
    return false;

  std::deque<Species *> newReactants, newProducts;

  for (const auto &reactantPtr : newReaction.allReactants())
  {
    const Species *inSpeciesPtr = findSpecies(*reactantPtr);
    if (inSpeciesPtr == nullptr)
    {
      addSpecies(*reactantPtr);
      newReactants.push_back(&speciesContainer.back());
    }
    else
      newReactants.push_back(const_cast<Species *>(inSpeciesPtr));
  }

  for (const auto &productPtr : newReaction.allProducts())
  {
    const Species *inSpeciesPtr = findSpecies(*productPtr);
    if (inSpeciesPtr == nullptr)
    {
      addSpecies(*productPtr);
      newProducts.push_back(&speciesContainer.back());
    }
    else
      newProducts.push_back(const_cast<Species *>(inSpeciesPtr));
  }

  reactionsContainer.push_back(
      Reaction(newReactants, newProducts,
               newReaction.forwardRate(), newReaction.backwardRate(),
               newReaction.name(), newReaction.type()));

  return true;
}

bool Network::addSpecies(Species &newSpecies)
{
  if (findSpecies(newSpecies) != nullptr)
    return false;
  speciesContainer.push_back(newSpecies);
  return true;
}

const Reaction *Network::findReaction(const Reaction &reaction)
{
  for (const auto &r : reactionsContainer)
    if (r == reaction)
      return &r;
  return nullptr;
}

const Species *Network::findSpecies(const Species &species)
{
  for (const auto &s : speciesContainer)
    if (s == species)
      return &s;
  return nullptr;
}

const std::deque<Species> &Network::allSpecies() { return speciesContainer; }

const std::deque<Reaction> &Network::allReactions() { return reactionsContainer; }