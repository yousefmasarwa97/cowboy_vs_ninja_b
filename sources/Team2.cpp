#include "Team2.hpp"
#include"Team.hpp"
using namespace std;
#include <iostream>
namespace ariel{}
void Team2::add(Character *hero)
{
    if (hero->getismember())
    {
        throw runtime_error("the leader is already in team!");
    }
    
    if (this->get_team().size() >= 10)
    {
        throw runtime_error ("the team is already full");
    }
    if (hero->isAlive() && hero->getismember() == false)
    {
        vector <Character*> newTeamMembers = get_team(); 
        newTeamMembers.push_back(hero); 
        setTeam(newTeamMembers); 
        hero->setismember(true);
    }
}
    
