#include "species.hpp"
#include <string>

Species::Species() {}

Species::Species(std::string n, float p, float c, float d, float i)
{
  name = n;
  potential = p;
  concentration = c;
  decay = d;
  inflow = i;
}

void Species::setConcentration(float c)
{
  concentration = c;
}

void Species::setPotential(float p)
{
  potential = p;
}

void Species::setDecay(float d)
{
  decay = d;
}

void Species::setInflow(float i)
{
  inflow = i;
}

float Species::getConcentration() const { return concentration; }
float Species::getPotential() const { return potential; }
float Species::getDecay() const { return decay; }
float Species::getInflow() const { return inflow; }
const std::string &Species::getName() const { return name; }