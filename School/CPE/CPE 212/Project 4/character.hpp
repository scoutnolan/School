/**
 * character.hpp - CPE 212-01, Spring 2020 - Project04 - Sorted Lists
 */
#include <string>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <fstream>
#include <ostream>
#include "list.hpp"
#include "item.h"
#include "inventory.hpp"

using namespace std;

#ifndef CHARACTER_H
#define CHARACTER_H

/**
 * Enum that defines the available races of the game
 */
enum Race {
    HUMAN = 0,
    ELF = 1,
    DWARF = 2,
    GNOME = 3,
    GOBLIN = 4
};

static const string RaceStrings[] = {"Human", "Elf", "Dwarf", "Gnome", "Goblin"};

/**
 * Weapon structure that defines the name, damage an cost of the weapon
 */
struct Weapon {
    string name;
    int damage;
    int cost;
};

class Character
{
private:
    int uid;        // User id of the Character
    string name;    // Name of the character
    string job;     // Job of the character: Valid jobs are: "Warrior", "Mage", "Rogue" and "Cleric"
    Race race;      // Race is defined in the above enum
    Weapon weapon;  // The weapon of the Character
    int health;     // Amount of health the Character has available. This is different for each job.
    int level;      // The level of the Character
    int exp;        // Experience of the Character. As this increases so does the Character's level
    Inventory inventory;   // List of items that are used for the character's inventory **New
public:
    // Constructors
    Character();
    Character(int uid, string characterName, Race characterRace);

    // Observers
    string GetName() const;
    string GetRace() const;
    Race GetRaceEnum() const;
    int GetLevel() const;
    Weapon GetWeapon() const;
    int GetExp() const;
    string GetJob() const;
    int GetHealth() const;
    int GetUid() const; // new
    void DisplayInventory() const; // new

    // Transformers
    void AddExp(int amount);
    void SetHealth(int h);
    void SetJob(string j);
    void TakeDamage(int h);
    void AddToInventory(Item &i);
    void SetWeapon(Weapon w);
    void LootTarget(Character *target); // new
    Inventory* GetInventory();

    // Overloads (new)
    bool operator==(const Character &otherCharacter) const;
    bool operator!=(const Character &otherCharacter) const;
    bool operator>(const Character &otherCharacter) const;
    bool operator<(const Character &otherCharacter) const;

    friend ostream& operator<<(ostream& os, const Character& ch)
    {
        os << ch.GetUid();
        return os;
    }


    void Status();
    virtual void Attack(Character * target) = 0;

    // Print Helper functions
    void PrintDamage(string characterName, string targetName, string weaponName, int damage);
};
#endif // End of CHARACTER_H
