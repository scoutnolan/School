/**
 * goblin.cpp - CPE 212-01, Spring 2020 - Project02 - Class Inheritance
 */
#include <iostream>
#include <math.h>
#include "goblin.hpp"

/**
 * Goblin Class constructor
 * @param characterName The name of the character being created
 * @param characterRace The race of the character being created. This is a enum value.
 * @extends This constructor extends the base Character constructor
 */
Goblin::Goblin(int id, string characterName, Race characterRace) : Character(id, characterName, characterRace)
{
    // Set the Job name
    SetJob("Goblin");
    // Set the Health to 30
    SetHealth(30);
    /**
     * Assign the starter weapon for the Goblin
     *   Weapon
     *     name : "Pointy Stick"
     *     cost : 1
     *     damage : 3
     */
    Weapon stick;
    stick.cost = 1;
    stick.damage = 5;
    stick.name = "Pointy Stick";
    SetWeapon(stick);

    // Add the weapon to the inventory of the Goblin
    Item equipment(stick.name, stick.cost, WEAPON);
    AddToInventory(equipment);

    // Assign a value of 10 as the starting attack value
    attack = 2;
}

/**
 * Public method Status that prints out the Status of the Goblin
 * @attention Use the PrintStatus helper function. Enter the attribute name exactly like it is listed
 *  in the header file
 * @example For the private variable "luck" which is set to 7 you would print the following
 *      PrintStatus(luck, 7);
 */
void Goblin::Status()
{
    Character::Status();
    cout << "Attack: " << attack << endl;
}

/**
 * Public method of Goblin that attacks an enemy Character
 * @param enemy Pointer to the enemy Character
 */
void Goblin::Attack(Character * enemy)
{
    /**
     * 1. The damage for a Goblin is calculated by the weapon damage + half the attack value
     * 2. The enemy Character must take the damage dealt by the Goblin
     * 3. Please print out the details of the attack in the following format
     *
     *   <Character Name> attacks <Enemy Name> with <Character's Weapon Name> for <damage> points
     */

    // Insert your code here
    Weapon myWeapon = GetWeapon();
    int damage = myWeapon.damage + (attack * 0.5);
    Character::PrintDamage(GetName(), enemy->GetName(), myWeapon.name, damage);
    enemy->TakeDamage(damage);
}

void Goblin::SneakAttack(Character *enemy)
{
    /**
     * 1. The damage for a Rogue is calculated by the 50 + weapon damage + half the dexterity value
     * 2. The enemy Character must take the damage dealt by the Rogue
     * 3. Please print out the details of the attack in the following format
     *
     *   <Character Name> Sneak Attacks <Enemy Name> for <damage> points
     */

    // Insert your code here
    Weapon myWeapon = GetWeapon();
    int damage = 20 + myWeapon.damage + (attack * 0.5);
    PrintSneakAttack(GetName(), enemy->GetName(), damage);
    enemy->TakeDamage(damage);
}

/**
 * Private method to this file that displays the special attack for this character
 * @param characterName - Name of the character
 * @param targetName - Name of the recipient of the special attack
 * @param attackAmount - Amount of damage dealt by the character
 */
void PrintSneakAttack(string characterName, string targetName, int attackAmount) {
    cout << characterName << " Sneak Attacks " << targetName << " for " << attackAmount << " points" << endl;
}

/**
 * Public method to print a inherited classes custom characteristic value
 * @param customCharacteristicName - These are the unique attributes given to each child class. Make sure to capitalize the first character
 * @param characteristicValue  - This is the actual value of the unique attribute
 * @attention DO NOT MODIFY
 * @example PrintStatus("luck", 7);
 */
void PrintStatus(string customCharacteristicName, int characteristicValue) {
    customCharacteristicName[0] = toupper(customCharacteristicName[0]);
    cout << customCharacteristicName << ": " << characteristicValue << endl;
}