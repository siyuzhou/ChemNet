#ifndef SPECIES_H
#define SPECIES_H

#include <string>

class Species
{
public:
  Species();
  Species(std::string, float, float, float, float = 0.);

  const std::string &getName() const;
  float getPotential() const;
  float getConcentration() const;
  float getDecay() const;
  float getInflow() const;

  void setPotential(float);
  void setConcentration(float);
  void setDecay(float);
  void setInflow(float);

private:
  std::string name;
  float potential;
  float concentration;
  float decay;
  float inflow;
};

#endif