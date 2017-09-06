#include "species.hpp"
#include <string>

Species::Species(std::string f, float p, float c, float d, float i)
{
  formula = f;
  setPotential(p);
  setConcentration(c);
  setDecay(d);
  setInflow(i);
}

std::string Species::getFormula()
{
  return formula;
}

float Species::getPotential()
{
  return potential;
}

float Species::getConcentration()
{
  return concentration;
}

float Species::getInflow()
{
  return inflow;
}

float Species::getDecay()
{
  return decay;
}

void Species::setPotential(float p)
{
  potential = p;
}

void Species::setConcentration(float c)
{
  concentration = c;
}

void Species::setInflow(float i)
{
  inflow = i;
}

void Species::setDecay(float d)
{
  decay = d;
}