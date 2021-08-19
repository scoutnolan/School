/**
 * character.cpp - CPE 212-01, Spring 2020 - Project04 - Sorted Lists
 */
#include <iostream>
#include "character.hpp"

Character::Character(int id, string characterName, Race characterRace) {
    uid = id;
    name = characterName;
    race = characterRace;
    health = 0;
    exp = 0;
    level = 1;
    job = "Not Assigned";
}

Character::Character() {
    uid = rand() % 1000 + 1;
    name = "";
    race = HUMAN;
    health = 0;
    exp = 0;
    level = 1;
    job = "Not Assigned";
}

// Implement the Observers here

int Character::GetLevel() const {
    return level;
}

int Character::GetExp() const {
    return exp;
}

string Character::GetName() const {
    return name;
}

string Character::GetJob() const {
    return job;
}

string Character::GetRace() const {
    return RaceStrings[race];
}

Weapon Character::GetWeapon() const {
    return weapon;
}

int Character::GetHealth() const {
    return health;
}

// Implement the Transformers here
void Character::AddExp(int amount) {
    exp += amount;
}

void Character::SetHealth(int h) {
    health = h;
}

void Character::SetWeapon(Weapon w) {
    weapon = w;
}

void Character::SetJob(string j) {
    job = j;
}

int Character::GetUid() const {
    return uid;
}

void Character::DisplayInventory() const
{
    std::cout << "Inventory for: " << GetName() << std::endl;
    inventory.ShowInventory();
}

Inventory* Character::GetInventory() {
    return &inventory;
}

/**
 * Student Section Begin
 */
void Character::AddToInventory(Item &i)
{
    if(!inventory.isFull())
    {
        inventory.Add(i);
    }
    // Inventory items;
    // items.Add(i);
    //_count = _count -1;
    /**
     * Add the item to the inventory
     */
}

bool Character::operator!=(const Character &otherCharacter) const
{
    return otherCharacter.uid != this->GetUid();
    /**
     * Implement the operator overload for this operator.
     * Use the uid value
     */
}

bool Character::operator==(const Character &otherCharacter) const
{
    return otherCharacter.uid == this->GetUid();
    /**
     * Implement the operator overload for this operator.
     * Use the uid value
     */
}

bool Character::operator<(const Character &otherCharacter) const
{
    return otherCharacter.uid < this->GetUid();
    /**
     * Implement the operator overload for this operator.
     * Use the uid value
     */
}

bool Character::operator>(const Character &otherCharacter) const
{
    return otherCharacter.uid > this->GetUid();
    /**
     * Implement the operator overload for this operator.
     * Use the uid value
     */
}

void Character::LootTarget(Character *target)
{
    //Inventory items;
    target->inventory.ShowInventory();
    while(!target->inventory.isEmpty())
    {
        
        Item newItem = target->inventory.PopFront();
        if(newItem.GetType() != "RawGold")
        {
            target->inventory.ShowInventory();
            AddToInventory(newItem);
        }
    }
    /**
     * Given a Character target add all of the items in their inventory to your own.
     */
}

/**
 * Student Section End
 */

/**
 * Public method TakeDamage
 * @param damage The amount of damage taken by the Character
 * @attention DO NOT MODIFY
 */
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


/**
 * Public method to print the damage given by a character
 * @param characterName - Name of the character attacking
 * @param targetName - Name of the target, or enemy, being attacked
 * @param weaponName - Name of the weapon used in the attacking
 * @param damage - The amount of damage done by the character and weapon
 * @attention DO NOT MODIFY
 * @example PrintDamage("Billy", "Willy", "Candle Stick", 140);
 */
void Character::PrintDamage(string characterName, string targetName, string weaponName, int damage) {
    cout << characterName << " attacks " << targetName << " with " << weaponName << " for " << damage << " points" << endl;
}