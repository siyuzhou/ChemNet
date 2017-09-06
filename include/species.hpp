#ifndef SPECIES_H
#define SPECIES_H

#include <string>

class Species
{
public:
  Species(std::string, float, float, float, float = 0.);

  std::string getFormula();
  float getPotential();
  float getConcentration();
  float getInflow();
  float getDecay();

  void setPotential(float p);
  void setConcentration(float c);
  void setInflow(float i);
  void setDecay(float d);

private:
  std::string formula;
  float potential;
  float concentration;
  float decay;
  float inflow;
};

#endif