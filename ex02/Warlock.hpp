#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "Atarget.hpp"
#include "SpellBook.hpp"

class Warlock
{
  private:
    std::string _name;
    std::string _title;

    SpellBook _book;

    Warlock(Warlock const &a);
    Warlock &operator=(Warlock const &a);
    Warlock();
  public:
    Warlock(std::string n,std::string t);  
    ~Warlock();
    std::string getTitle() const;
    std::string getName() const;

    void setTitle(std::string const t);
    void    introduce() const;

    void learnSpell(ASpell *s);
    void forgetSpell(std::string s);
    void launchSpell(std::string s,ATarget &t);
};
#endif