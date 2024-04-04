#include "SpellBook.hpp"

SpellBook::SpellBook()
{}

SpellBook::~SpellBook()
{}

void SpellBook::learnSpell(ASpell *s)
{
    _Book[s->getName()]=s;
}
void SpellBook::forgetSpell(std::string &s)
{
    if(_Book[s])
        _Book[s]=NULL;
}
ASpell *SpellBook::createSpell(std::string const &s)
{
    if(_Book[s])
        return (_Book[s]->clone());
    return NULL;
}