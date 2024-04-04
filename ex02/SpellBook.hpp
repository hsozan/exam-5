#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include <iostream>
#include <map>
#include "ASpell.hpp"

class SpellBook
{
  private:
    std::map <std::string , ASpell *> _Book;

    SpellBook(SpellBook const &a);
    SpellBook &operator=(SpellBook const &a);
  public:
    SpellBook();
    ~SpellBook();

    void learnSpell(ASpell *s);
    void forgetSpell(std::string &s);
    ASpell *createSpell(std::string const &s);
};
#endif