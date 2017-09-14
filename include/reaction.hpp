#ifndef REACTION_HPP
#define REACTION_HPP

#include <string>
#include <deque>
#include <map>
#include "species.hpp"

class Reaction
{
public:
  Reaction(const std::deque<Species *> &, const std::deque<Species *> &, float = 0., float = 0., const std::string = "", const std::string = "");

  const std::string &name() const;
  const std::string &type() const;
  const std::deque<Species *> &allReactants() const;
  const std::deque<Species *> &allProducts() const;
  const int numReactants() const;
  const int numProducts() const;

  bool hasReactant(Species &) const;
  bool hasProduct(Species &) const;

  float forwardRate();
  float backwardRate();
  const std::map<std::string, float> changeConcentration(float);
  void update(const std::map<std::string, float> &);
  void react(float);

  bool operator==(const Reaction &) const;

private:
  const std::string chemistry_;
  const std::string name_;
  const std::deque<Species *> reactants;
  const std::deque<Species *> products;
  float rateForward, rateBackward;
};

#endif