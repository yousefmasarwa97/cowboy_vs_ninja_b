#pragma once
#include"Team.hpp"
class Team2 :public Team{
    public:
    Team2(Character *leader):Team(leader){}
    void add(Character *hero);

} ;