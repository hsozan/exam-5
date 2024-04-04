#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>

class Warlock
{
  private:
    std::string _name;
    std::string _title;
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
};
#endif