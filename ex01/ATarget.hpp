#ifndef ATARGET_HPP
#define ATARGET_HPP

#include "ASpell.hpp"
class ASpell;
class ATarget
{
    protected:
        std::string _type;
        ATarget();
    public:
        ATarget(std::string t);
        virtual ~ATarget();
        ATarget(ATarget const &a);
        ATarget &operator=(ATarget const &a);
        std::string getType() const;

        virtual ATarget *clone() const=0;
        void getHitBySpell(ASpell const &s) const;
};
#endif
