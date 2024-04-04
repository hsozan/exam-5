#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{}

TargetGenerator::~TargetGenerator()
{}

void TargetGenerator::learnTargetType(ATarget *s)
{
    _targets[s->getType()]=s;
}
void TargetGenerator::forgetTargetType(std::string &s)
{
    if(_targets[s])
        _targets[s]=NULL;
}
ATarget *TargetGenerator::createTarget(std::string const &s)
{
    if(_targets[s])
        return (_targets[s]->clone());
    return NULL;
}