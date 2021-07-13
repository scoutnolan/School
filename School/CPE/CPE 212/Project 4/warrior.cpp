/**
 * warrior.cpp - CPE 212-01, Spring 2020 - Project02 - Class Inheritance
 */
#include <iostream>
#include <math.h>
#include "warrior.hpp"

/**
 * Warrior Class constructor
 * @param characterName The name of the character being created
 * @param characterRace The race of the character being created. This is a enum value.
 * @extends This constructor extends the base Character constructor
 */
Warrior::Warrior(int id, string characterName, Race characterRace) : Character(id, characterName, characterRace)
{
    // Set the Job name
    SetJob("Warrior");
    // Set the Health to 150
    SetHealth(150);
    /**
     * Assign the starter weapon for the Warrior
     *   Weapon
     *     name : "Starter Longsword"
     *     cost : 100
     *     damage : 10
     */
    Weapon sword;
    sword.cost = 100;
    sword.damage = 10;
    sword.name = "Starter Longsword";
    SetWeapon(sword);

    // Add the weapon to the inventory of the Warrior
    Item equipment(sword.name, sword.cost, WEAPON);
    AddToInventory(equipment);

    // Assign a value of 10 as the starting strength value
    strength = 10;
}

/**
 * Public method Status that prints out the Status of the Warrior
 * @attention You MUST print out the local Warrior variables.
 *  The format for the print must be "PrivateVar: PrivateVal" where the name of the private variable is capitalized
 * @example For the private variable luck which is set to 7 you would print the following
 *      "Luck: 7"
 */
void Warrior::Status()
{
    Character::Status();
    cout << "Strength: " << strength << endl;
}

/**
 * Public method of Warrior that attacks an enemy Character
 * @param enemy Pointer to the enemy Character
 */
void Warrior::Attack(Character * enemy)
{
    /**
     * 1. The damage for a Warrior is calculated by the weapon damage + half the strength value
     * 2. The enemy Character must take the damage dealt by the Warrior
     * 3. Please print out the details of the attack in the following format
     *
     *   <Character Name> attacks <Enemy Name> with <Character's Weapon Name> for <damage> points
     */

    // Insert your code here
    Weapon myWeapon = GetWeapon();
    int damage = myWeapon.damage + (strength * 0.5);
    cout << GetName() << " attacks " << enemy->GetName() << " with " << myWeapon.name << " for " << damage << " points" << endl;
    enemy->TakeDamage(damage);
}

void Warrior::PowerAttack(Character * enemy)
{
    /**
     * 1. The damage for a Power Attack is calculated by the health / 100 * (weapon damage + half the strength value)
     * 2. The enemy Character must take the damage dealt by the Warrior
     * 3. Please print out the details of the attack in the following format
     *
     *   <Character Name> attacks <Enemy Name> with a Power Attack for <damage> points
     */

    // Insert your code here
    Weapon myWeapon = GetWeapon();
    int myHealth = GetHealth();
    int damage = (myHealth / 100) * (myWeapon.damage + (strength * 0.5));
    cout << GetName() << " attacks " << enemy->GetName() << " with a Power Attack for " << damage << " points" << endl;
    enemy->TakeDamage(damage);
}