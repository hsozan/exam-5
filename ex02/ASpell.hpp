#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
    protected:
        std::string _name;
        std::string _effects;
        ASpell();
    public:
        ASpell(std::string n,std::string const e);
        virtual ~ASpell();
        ASpell(ASpell const &a);
        ASpell &operator=(ASpell const &a);
        std::string getName() const;
        std::string getEffects() const;

        virtual ASpell *clone() const = 0;
        
        void launch(ATarget const &t) const;
};
#endif
