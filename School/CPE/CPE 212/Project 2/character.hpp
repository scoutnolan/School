/**
 * character.hpp - CPE 212-01, Spring 2020 - Project02 - Class Inheritance
 */
#include <string>
#include <iostream>
#include <fstream>

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

static const char * RaceStrings[] = {"Human", "Elf", "Dwarf", "Gnome", "Goblin"};

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
    string name;    // Name of the character
    string job;     // Job of the character: Valid jobs are: "Warrior", "Mage", "Rogue" and "Cleric"
    Race race;      // Race is defined in the above enum
    Weapon weapon;  // The weapon of the Character
    int health;     // Amount of health the Character has available. This is different for each job.
    int level;      // The level of the Character
    int exp;        // Experience of the Character. As this increases so does the Character's level
public:
    // Constructors
    Character();
    Character(string characterName, Race characterRace);

    // Observers
    string GetName() const;
    Race GetRace() const;
    int GetLevel() const;
    Weapon GetWeapon() const;
    int GetExp() const;
    string GetJob() const;
    int GetHealth() const;

    // Transformers
    void AddExp(int amount);
    void SetHealth(int h);
    void SetJob(string j);
    void TakeDamage(int h);

    // Virtual Methods
    virtual void SetWeapon(Weapon w);

    // Pure Virtual Methods
    virtual void Status() = 0;
    virtual void Attack(Character * target) = 0;
};
#endif // End of CHARACTER_H
