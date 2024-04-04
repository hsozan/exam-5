#include "Warlock.hpp"
Warlock::Warlock()
{}

Warlock::Warlock(Warlock const &a)
{
    *this=a;
}

Warlock & Warlock::operator=(Warlock const &a)
{
    this->_name = a._name;
    this->_title = a._title;
    return *this;
}

Warlock::Warlock(std::string n,std::string t)
{
    _name=n;
    _title=t;
    std::cout << _name << ": This looks like another boring day." << std::endl;
}
Warlock::~Warlock()
{
    std::cout << _name << ": My job here is done!" << std::endl;
}

std::string Warlock::getTitle() const
{
    return _title;
}

std::string Warlock::getName() const
{
    return _name;
}

void Warlock::setTitle(std::string const t)
{
    _title = t;
}

void Warlock::introduce() const
{
    std::cout<< _name << ": I am " << _name <<", "<<_title<<"!\n";
}


void Warlock::learnSpell(ASpell *s)
{
    _SpellBook[s->getName()]=s;
}

void Warlock::forgetSpell(std::string s)
{
    if(_SpellBook[s])
        _SpellBook[s] = NULL;
}

    

void Warlock::launchSpell(std::string s,ATarget &t)
{
    if(_SpellBook[s])
        _SpellBook[s]->launch(t);
}

#include "Dummy.hpp"
#include "Fwoosh.hpp"

int main()
{
  Warlock richard("Richard", "the Titled");

  Dummy bob;
  Fwoosh* fwoosh = new Fwoosh();

  richard.learnSpell(fwoosh);

  richard.introduce();
  richard.launchSpell("Fwoosh", bob);

  richard.forgetSpell("Fwoosh");
  richard.launchSpell("Fwoosh", bob);
}

/*
~$ ./a.out | cat -e
Richard: This looks like another boring day.$
Richard: I am Richard, the Titled!$
Target Practice Dummy has been fwooshed!$
Richard: My job here is done!$
*/