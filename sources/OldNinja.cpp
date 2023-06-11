#include"OldNinja.hpp"
#include"Character.hpp"
#include "Ninja.hpp"
namespace ariel{}

OldNinja::OldNinja(string name,const Point &location)
:Ninja(name,location,150,8){
    this->set_isninja(true);
}