#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include <iostream>
#include <map>
#include "ATarget.hpp"

class TargetGenerator
{
  private:
    std::map <std::string, ATarget *> _targets;
    TargetGenerator(TargetGenerator const &a);
    TargetGenerator &operator=(TargetGenerator const &a);
  public:
    TargetGenerator();
    ~TargetGenerator();

    void learnTargetType(ATarget *s);
    void forgetTargetType(std::string &s);
    ATarget *createTarget(std::string const &s);
};
#endif