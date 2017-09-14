#include "species.hpp"
#include <string>

Species::Species() {}

Species::Species(std::string n, float p, float c, float d, float i) : name_(n)
{
  potential = p;
  concentration = c;
  decay = d;
  inflow = i;
}

void Species::setConcentration(float c)
{
  concentration = (c > 0) ? c : 0;
}

void Species::setPotential(float p)
{
  potential = p;
}

void Species::setDecay(float d)
{
  decay = (d > 0) ? d : 0;
}

void Species::setInflow(float i)
{
  inflow = i;
}

float Species::getConcentration() const { return concentration; }
float Species::getPotential() const { return potential; }
float Species::getDecay() const { return decay; }
float Species::getInflow() const { return inflow; }
const std::string &Species::name() const { return name_; }

bool Species::operator==(const Species &species) const
{
  return (name_ == species.name_);
}