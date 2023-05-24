#pragma once
#include "Character.hpp"
#include <vector>
#include"Point.hpp"
#include"Ninja.hpp"
#include"Cowboy.hpp"
#include"OldNinja.hpp"
#include"TrainedNinja.hpp"
#include"YoungNinja.hpp"

namespace ariel{}
class Team
{
private:
vector<Character*> team;
Character *leader;

  

public:
Team(Character *leader);
~Team();
Team() = delete; 
Team(const Team &) = delete;
Team& operator =(Team const&) = delete;
Team(Team&&) = delete;
Team& operator=(Team&&) = delete;



vector<Character*>get_team();
void set_leader(Character* );
void choose_leader();
Character* choose_victum(Character*,Team *other);
virtual void add( Character *hero);
virtual void attack(Team *other);
virtual int stillAlive() const;
// vector<Character*> getTeam() {return this->team;}
void setTeam(vector<Character*> newTeam){this->team = std::move(newTeam);}
virtual void print();
void sort();
Character* getLeader(){return this->leader;}

};