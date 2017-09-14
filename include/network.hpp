#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <deque>
#include "species.hpp"
#include "reaction.hpp"

class Network
{
public:
  Network();

  bool addReaction(Reaction &);
  bool addSpecies(Species &);

  const std::deque<Species> &allSpecies();
  const std::deque<Reaction> &allReactions();

private:
  const Reaction *findReaction(const Reaction &);
  const Species *findSpecies(const Species &);

  std::deque<Species> speciesContainer;
  std::deque<Reaction> reactionsContainer;
};

#endif