#include "ASpell.hpp"

ASpell::ASpell()
{

}
ASpell::~ASpell()
{}

ASpell::ASpell(std::string n,std::string const e)
{
    _name=n;
    _effects=e;
}

ASpell & ASpell::operator=(ASpell const &a)
{
    this->_name=a._name;
    this->_effects=a._effects;
    return *this;
}

std::string ASpell::getName() const
{
    return _name;
}

std::string ASpell::getEffects() const
{
    return _effects;
}

void ASpell::launch(ATarget const &t) const
{
    t.getHitBySpell(*this);
}