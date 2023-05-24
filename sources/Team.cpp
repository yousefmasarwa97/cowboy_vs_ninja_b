#include "Team.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include <cstddef>
#include <fstream>
#include <iostream>
#include <stdexcept>
using namespace std;
namespace ariel
{
}

Team::Team(Character *leader):leader(leader){
    this->add(leader);
    leader->setismember(true);
}


Team::~Team()
{
    for (Character *c : team)
    {
        delete (c);
    }
}

vector<Character*> Team::get_team(){
    return this->team ;
}

void Team::set_leader(Character* other){
    this->leader=other;
}

void Team::add( Character *hero){
    if (team.size()>=10) {
        throw runtime_error("full!");
    
    }
    if(hero==nullptr){
        throw runtime_error("hero is null");
    }
    if (hero->getismember()==true) { // throw error if the input is already in team
        throw runtime_error("Already in Team!!!");
    }
    else{

    team.push_back(hero);
    hero->setismember(true) ;
    sort();
    }
}

void Team::attack(Team *other){

    if ( other==nullptr) {
        throw std::invalid_argument ("other team is null");
    }
    if (other->stillAlive()==0) {
        throw std::runtime_error("The other Team is Dead");
    
    }

    if (stillAlive()==0 && other->stillAlive()==0) {
        throw ("there is no one alive"); 
    }

    if (this->stillAlive()==0) {
        throw std::runtime_error("The Team is Dead");
    }
    
    
    
    if (!this->leader->isAlive()) {
        choose_leader();
    }



    Character *victim=nullptr;
    victim=choose_victum(this->leader,other);
    for (Character *c : team) {
        if (c->isAlive() && !victim->isAlive()) { 
            if (!other->stillAlive()) {
             return;
            }
            victim=choose_victum(leader, other);
            c->attack(victim);
        }
        else if (c->isAlive() && victim->isAlive()) {
            c->attack(victim);
        
        }
    
    }
}

    

   




Character* Team::choose_victum(Character *main_char,Team *other){
    if (other->stillAlive() < 1)
    {
        throw runtime_error("the team is already killed :~(");
    }else{
        double min_distance=10000;
        double currentdist=0;
        Character* char_to_hit=nullptr;
        for(Character *c:other->get_team()){
            if (leader->distance(c)<min_distance && c->isAlive() ) {
                min_distance=leader->distance(c);
                char_to_hit=c;
            }
        }
        return char_to_hit;
        
    }
}


void Team::choose_leader(){
    double min_distance=10000;
    Character* main_character=nullptr;
    for (size_t i=0; i<team.size();i++) {
        if (team.at(i)==this->leader) {
            continue;
        }
        else if (this->leader->distance(team.at(i))<min_distance && team.at(i)->isAlive()) {
            main_character=team.at(i);
            min_distance=this->leader->distance(team.at(i));
        }
        
    }
    
   this->leader=main_character;
}

void Team::print(){
    for (size_t i=0; i<team.size(); i++){
        cout<<team.at(i)->print()<<"\n"<<endl;
    }
}

int Team::stillAlive()const{
    int counter=0;
   
    for (Character* member : team) {
        if (member->isAlive()) { 
            counter++;
        }
    }

    return counter;
}

void Team::sort(){
    vector<Character*> sorted_team;
    for (size_t i=0; i<team.size(); i++)  {
        if (Cowboy* cow=dynamic_cast<Cowboy*>(team.at(i))) {
            sorted_team.push_back(cow);
        }
    
    }
    for (size_t i=0; i<team.size(); i++)  {
        if (Ninja* ninja=dynamic_cast<Ninja*>(team.at(i))) {
            sorted_team.push_back(ninja);
        }
    }
    team=sorted_team;
}