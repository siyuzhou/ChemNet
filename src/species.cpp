#include "species.hpp"
#include <string>

Species::Species(std::string n, float p, float c, float d, float i) : name(n)
{
  potential = p;
  concentration = c;
  decay = d;
  inflow = i;
}