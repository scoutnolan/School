/**
 * mage.cpp - CPE 212-01, Spring 2020 - Project02 - Class Inheritance
 */
#include <iostream>
#include <math.h>
#include "mage.hpp"

/**
 * Mage Class constructor
 * @param characterName The name of the character being created
 * @param characterRace The race of the character being created. This is a enum value.
 * @extends This constructor extends the base Character constructor
 */
Mage::Mage(int id, string characterName, Race characterRace) : Character(id, characterName, characterRace)
{
    // Set the Job name
    SetJob("Mage");
    // Set the Health to 50
    SetHealth(50);
    /**
     * Assign the starter weapon for the Mage
     *   Weapon
     *     name : "Simple Staff"
     *     cost : 100
     *     damage : 5
     */
    Weapon staff;
    staff.cost = 100;
    staff.damage = 5;
    staff.name = "Simple Staff";
    SetWeapon(staff);

    // Add the weapon to the inventory of the Mage
    Item equipment(staff.name, staff.cost, WEAPON);
    AddToInventory(equipment);

    // Assign a value of 10 as the starting intelligence value
    intelligence = 10;
}

/**
 * Public method Status that prints out the Status of the Mage
 * @attention You MUST print out the local Mage variables.
 *  The format for the print must be "PrivateVar: PrivateVal" where the name of the private variable is capitalized
 * @example For the private variable luck which is set to 7 you would print the following
 *      "Luck: 7"
 */
void Mage::Status()
{
    Character::Status();
    cout << "Intelligence: " << intelligence << endl;
}

/**
 * Public method of Mage that attacks an enemy Character
 * @param enemy Pointer to the enemy Character
 */
void Mage::Attack(Character * enemy)
{
    /**
     * 1. The damage for a Mage is calculated by the weapon damage + half the intelligence value
     * 2. The enemy Character must take the damage dealt by the Mage
     * 3. Please print out the details of the attack in the following format
     *
     *   <Character Name> attacks <Enemy Name> with <Character's Weapon Name> for <damage> points
     */

    // Insert your code here
    Weapon myWeapon = GetWeapon();
    int damage = myWeapon.damage + (intelligence * 0.5);
    cout << GetName() << " attacks " << enemy->GetName() << " with " << myWeapon.name << " for " << damage << " points" << endl;
    enemy->TakeDamage(damage);
}


void Mage::Fireball(Character *enemy) {
    // Insert your code here
    Weapon myWeapon = GetWeapon();
    int damage = 10 + myWeapon.damage + (intelligence * 0.5);
    cout << GetName() << " attacks " << enemy->GetName() << " with a Fireball for " << damage << " points" << endl;
    enemy->TakeDamage(damage);
}