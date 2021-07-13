/**
 * character.cpp - CPE 212-01, Spring 2020 - Project02 - Class Inheritance
 */
#include "character.hpp"


// cd /your/project02/location-bash-4.2$  
// /home/work/cpe212-01-20s/project02/Game inputfilename
// Implement the Constructors here

// Implement the Observers here


// Implement the Transformers here

/**
 * Public method TakeDamage
 * @param damage The amount of damage taken by the Character
 * @attention DO NOT MODIFY
 */
Character::Character(){
    name = "";
    job = "";
    race = HUMAN;
    weapon.name = "";
    weapon.cost = 0;
    weapon.damage = 0;
    SetWeapon(weapon);
    health = 1;
    level = 1;
    exp = 0;
}

Character::Character(string charname, Race charrace){
    name = charname;
    race = charrace;
    health = 1;
    level = 1;
    exp = 0;
}

string Character::GetName() const{
    return name;
     // get the name of the character
 }


Race Character::GetRace() const{ 
    return race;
     // get the race of the character
 }

int Character::GetLevel() const{
    return level;
    // need to call in the level from the character class
    // get the level of the character
}

Weapon Character::GetWeapon() const{
    return weapon;
    // get the character's weapon
}

int Character::GetExp() const{
    return exp;
    // get the experience of the character
}

string Character::GetJob() const{
    return job;
    // get the job of the character
}

int Character::GetHealth() const{
    return health;
}

void Character::AddExp(int amount){
    exp += amount;
    cout << name << " adds " << exp << " points of experience." << endl;
    
    // add experience to the character
}

void Character::SetHealth(int hp){
    health = hp;
    // add set the character's hhealth
}

void Character::SetJob(string charjob){
    job = charjob;
    //Character::SetJob(job);
    // set the job of the character
}

void Character::TakeDamage(int damage) {
    cout << name << " takes " << damage << " points of damage." << endl;
    if ((health - damage) < 0)
    {
        cout << name << " has died." << endl;
        health = 0;
    }
    else 
    {
        health -= damage;
    }
}

void Character::SetWeapon(Weapon w){
    weapon = w;
}

/**
 * Public method to print the base Character's Status
 * @attention DO NOT MODIFY
 */
void Character::Status() {
    cout << job << " Status" << endl;
    cout << "Name: " << name << endl;
    cout << "Race: " << RaceStrings[race] << endl;
    cout << "Level: " << level << endl;
    cout << "Exp: " << exp << endl;
    cout << "Health: " << health << endl;
}

void Character::Attack(Character*target){
    Character::Attack(target);
}