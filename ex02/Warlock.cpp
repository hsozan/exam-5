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
   _book.learnSpell(s);
}

void Warlock::forgetSpell(std::string s)
{
    _book.forgetSpell(s);
}

    

void Warlock::launchSpell(std::string s,ATarget &t)
{
    _book.createSpell(s)->launch(t);
}

#include "Dummy.hpp"
#include "Fwoosh.hpp"
#include "TargetGenerator.hpp"
#include "BrickWall.hpp"
#include "Fireball.hpp"
#include "Polymorph.hpp"

int main()
{
  Warlock richard("Richard", "foo");
  richard.setTitle("Hello, I'm Richard the Warlock!");
  BrickWall model1;

  Polymorph* polymorph = new Polymorph();
  TargetGenerator tarGen;

  tarGen.learnTargetType(&model1);
  richard.learnSpell(polymorph);

  Fireball* fireball = new Fireball();

  richard.learnSpell(fireball);

  ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

  richard.introduce();
  richard.launchSpell("Polymorph", *wall);
  richard.launchSpell("Fireball", *wall);
}

/*
~$ ./a.out | cat -e
Richard: This looks like another boring day.$
Richard: I am Richard, Hello, I'm Richard the Warlock!!$
Inconspicuous Red-brick Wall has been turned into a critter!$
Inconspicuous Red-brick Wall has been burnt to a crisp!$
Richard: My job here is done!$
~$
*/