#include <limits>
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "Point.hpp"
#include "SmartTeam.hpp"
#include "Character.hpp"
#include <stdexcept>
#include <vector>

namespace ariel{}
SmartTeam::SmartTeam(Character* leader):Team(leader){
}
void SmartTeam::add( Character *hero){
    if (smart_team.size()>=10) {
    throw runtime_error("full!");
    
    }
    if(hero==nullptr){
        throw runtime_error("hero is null");
    }
    if (hero->getismember()==true) { // throw error if the input is already in smart_team
        throw runtime_error("Already in Team!!!");
    }
    else{

    smart_team.push_back(hero);
    hero->setismember(true) ;
    set_position_to_war();
    
    }

}
void SmartTeam::attack(Team *enemy) {
    if ( enemy==nullptr) {
        throw std::invalid_argument ("other team is null");
    }
    if (enemy->stillAlive()==0) {
        throw std::runtime_error("The other Team is Dead");
    
    }
    if (stillAlive()==0 && enemy->stillAlive()==0) {
        throw ("there is no one alive"); 
    }
    if (this->stillAlive()==0) {
        throw std::runtime_error("The Team is Dead");
    }
    if (!getLeader()->isAlive()) {
        choose_leader();
    }


    Character *victim=nullptr;
    victim=get_weakest_enemy(enemy);
    for (int i=0;i<smart_team.size();i++) {
        //if the hp if the victim is 10 or less i choose a cowboy to attack him and not to waste the attack of a ninja
        if (victim->gethp()<=10) {
            Cowboy *cowboyWithMostBullets = get_cowboy_with_most_boolets();
            // Check if the enemy is still alive after the attack
            if (!victim->isAlive()) {
                // Find the next weakest enemy
                victim = get_weakest_enemy(enemy);
            }
            if (cowboyWithMostBullets->hasboolets()) {
                cowboyWithMostBullets->attack(victim);
            }
        }
        //if the victim hp more than 10 is better that a ninja will attack
        else if (victim->gethp()>=10) {
            Ninja* nearest_ninja=get_nearest_to_victim(victim);
            if (!victim->isAlive()) {
                // Find the next weakest enemy
                victim = get_weakest_enemy(enemy);
            }
            nearest_ninja->attack(victim);
        }       
    }    
}
    



//return the cowboy wich have the most boolets
Cowboy* ::SmartTeam::get_cowboy_with_most_boolets() {
    Cowboy *cowboy_with_max_boolets = nullptr;
    int maxboolets = 0;
    for (Character* c : smart_team) {
        if (!c->get_isninja()) {
            Cowboy *c = dynamic_cast<Cowboy *>(c);
            if (c->boolets_num()>maxboolets) {
                cowboy_with_max_boolets=c;
                maxboolets=c->boolets_num();
            
            }
        }   
    }
    return cowboy_with_max_boolets;
}

//get the enemy eith the lowest hp 
Character* SmartTeam::get_weakest_enemy(Team *enemy) {
    Character *weakest_enemy = nullptr;
    int min_hp = std::numeric_limits<double>::max();
    for (Character* c:enemy->get_team()){
        if (c->gethp()<min_hp) {
            min_hp=c->gethp();
            weakest_enemy=c;
        
        }
    }
    return weakest_enemy;
}
//get the nearest character to the ninja from the enemy team to attack him later
Ninja*  SmartTeam::get_nearest_to_victim(Character* victim){
    double min_distance=std::numeric_limits<double>::max();
    Ninja* nearest=nullptr;
    for (Character *c : smart_team){
        if(c->distance(victim)<min_distance && c->get_isninja()){
            Ninja *c = dynamic_cast<Ninja *>(c);
            nearest=c;
            min_distance=c->distance(victim);
        }
        
    }
    return nearest;

}




//get all the ninja close to the team leader
void SmartTeam::set_position_to_war(){
    for (Character *c : smart_team) {
        if (c->get_isninja()) {
            Ninja *c = dynamic_cast<Ninja *>(c);
            while (c->distance(this->getLeader())>c->gethp()) {
               
                c->move(getLeader());
            }
        
        }
    
    }
  
}


// void SmartTeam::swap_loc(Character* ninja,Character* cowboy){
//     Point ninja_loc=ninja->getLocation();
//     Point cowboy_loc=cowboy->getLocation();
//     ninja->set_location(cowboy_loc);
//     cowboy->set_location(ninja_loc);

// }