#pragma once
#include "Character.hpp"
#include "Ninja.hpp"
#include <string>

namespace ariel{}

class YoungNinja: public Ninja{
    private:
    int speed;
    
    public:
    YoungNinja(string name,const Point &location);

};