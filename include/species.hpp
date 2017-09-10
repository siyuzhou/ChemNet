#ifndef SPECIES_H
#define SPECIES_H

#include <string>

struct Species
{
  const std::string name;
  float potential;
  float concentration;
  float decay;
  float inflow;

  Species(std::string, float, float, float, float = 0.);
};

#endif