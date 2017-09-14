#ifndef SPECIES_HPP
#define SPECIES_HPP

#include <string>

class Species
{
public:
  Species();
  Species(std::string, float, float, float, float = 0.);

  const std::string &name() const;
  float getPotential() const;
  float getConcentration() const;
  float getDecay() const;
  float getInflow() const;

  void setPotential(float);
  void setConcentration(float);
  void setDecay(float);
  void setInflow(float);

  bool operator==(const Species &) const;

private:
  const std::string name_;
  float potential;
  float concentration;
  float decay;
  float inflow;
};

#endif