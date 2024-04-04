#include "ATarget.hpp"

ATarget::ATarget()
{
}

ATarget::~ATarget()
{}

ATarget::ATarget(std::string t)
{
    _type=t;
}

ATarget & ATarget::operator=(ATarget const &a)
{
    this->_type=a._type;
    return *this;
}

std::string ATarget::getType() const
{
    return _type;
}

void ATarget::getHitBySpell(ASpell const &s) const
{

    std::cout<<_type<< " has been "<< s.getEffects() << "!\n";
}