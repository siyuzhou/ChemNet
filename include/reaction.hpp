#ifndef REACTION_H
#define REACTION_H

#include <string>
#include <vector>
#include <map>
#include "species.hpp"

class Reaction
{
public:
  const std::string chemistry;
  const std::string name;

  Reaction(const std::vector<Species *> &, const std::vector<Species *> &, float = 0., float = 0., const std::string = "", const std::string = "");

  const std::vector<Species *> &getReactants() const;
  const std::vector<Species *> &getProducts() const;

  float forwardRate();
  float backwardRate();
  const std::map<std::string, float> changeConcentration(float);
  void update(const std::map<std::string, float> &);
  void react(float);

private:
  std::vector<Species *> reactants;
  std::vector<Species *> products;
  float rateForward, rateBackward;
};

#endif