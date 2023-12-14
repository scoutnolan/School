/**
 * rogue.cpp - CPE 212-01, Spring 2020 - Project02 - Class Inheritance
 */
#include <iostream>
#include <math.h>
#include "rogue.hpp"

/**
 * Rogue Class constructor
 * @param characterName The name of the character being created
 * @param characterRace The race of the character being created. This is a enum value.
 * @extends This constructor extends the base Character constructor
 */
Rogue::Rogue(int id, string characterName, Race characterRace) : Character(id, characterName, characterRace)
{
    // Set the Job name
    SetJob("Rogue");
    // Set the Health to 100
    SetHealth(100);
    /**
     * Assign the starter weapon for the Rogue
     *   Weapon
     *     name : "Starter Daggers"
     *     cost : 100
     *     damage : 5
     */
    Weapon daggers;
    daggers.cost = 100;
    daggers.damage = 10;
    daggers.name = "Starter Daggers";
    SetWeapon(daggers);

    // Add the weapon to the inventory of the Rogue
    // Set the equipment ID to 11
    Item equipment(daggers.name, daggers.cost, WEAPON);
    AddToInventory(equipment);
    Item potion("Low Quality Health Potion", 5, POTION);
    AddToInventory(potion);
    

    // Assign a value of 10 as the starting dexterity value
    dexterity = 10;
}

/**
 * Public method Status that prints out the Status of the Rogue
 * @attention Use the PrintStatus helper function. Enter the attribute name exactly like it is listed
 *  in the header file
 * @example For the private variable "luck" which is set to 7 you would print the following
 *      PrintStatus(luck, 7);
 */
void Rogue::Status()
{
    Character::Status();
    cout << "Dexterity: " << dexterity << endl;
}

/**
 * Public method of Rogue that attacks an enemy Character
 * @param enemy Pointer to the enemy Character
 */
void Rogue::Attack(Character * enemy)
{
    /**
     * 1. The damage for a Rogue is calculated by the weapon damage + half the dexterity value
     * 2. The enemy Character must take the damage dealt by the Rogue
     * 3. Please print out the details of the attack in the following format
     *
     *   <Character Name> attacks <Enemy Name> with <Character's Weapon Name> for <damage> points
     */

    // Insert your code here
    Weapon myWeapon = GetWeapon();
    int damage = myWeapon.damage + (dexterity * 0.5);
    Character::PrintDamage(GetName(), enemy->GetName(), myWeapon.name, damage);
    enemy->TakeDamage(damage);
}

void Rogue::BackStab(Character *enemy)
{
    /**
     * 1. The damage for a Rogue is calculated by the 50 + weapon damage + half the dexterity value
     * 2. The enemy Character must take the damage dealt by the Rogue
     * 3. Please print out the details of the attack in the following format
     *
     *   <Character Name> Back Stabs <Enemy Name> for <damage> points
     */

    // Insert your code here
    Weapon myWeapon = GetWeapon();
    int damage = 50 + myWeapon.damage + (dexterity * 0.5);
    PrintBackStab(GetName(), enemy->GetName(), damage);
    enemy->TakeDamage(damage);
}

/**
 * Private method to this file that displays the special attack for this character
 * @param characterName - Name of the character
 * @param targetName - Name of the recipient of the special attack
 * @param attackAmount - Amount of damage dealt by the character
 * @attention DO NOT MODIFY
 */
void PrintBackStab(string characterName, string targetName, int attackAmount) {
    cout << characterName << " Back Stabs " << targetName << " for " << attackAmount << " points" << endl;
}