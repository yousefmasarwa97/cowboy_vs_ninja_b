#pragma once
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "Team.hpp"

namespace ariel{}
class SmartTeam : public Team{
    private:
    vector<Character*> smart_team;

    public:
    SmartTeam(Character*);
    Ninja* get_nearest_to_victim(Character*);
    Character* get_weakest_enemy(Team*);
    Character* get_farest_ninja(Character*);
    void swap_loc(Character*,Character*);
    Cowboy* get_cowboy_with_most_boolets();
    void add(Character *hero);
    void attack(Team*);
    void set_position_to_war();
   
};
