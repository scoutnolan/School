/**
 * rogue.hpp - CPE 212-01, Spring 2020 - Project02 - Class Inheritance
 */
#include "character.hpp"
#include "inventory.hpp"
#ifndef ROGUE_H
#define ROGUE_H

void PrintBackStab(string characterName, string targetName, int attackAmount);

class Rogue : public Character
{
private:
    int dexterity;
public:
    /**
     * Rogue Class constructor
     * @param characterName The name of the character being created
     * @param characterRace The race of the character being created. This is a enum value.
     * @extends This constructor extends the base Character constructor
     * @attention Follow these instructions:
     *  Cleric starts with 100 health
     *  Assign the starter weapon for the Cleric
     *      Weapon
     *         name : "Starter Daggers"
     *         cost : 100
     *         damage : 5
     *  Add the weapon to the Clerics inventory
     *  Assign a value of 10 for the base Rogue characteristic
     */
    Rogue(int uid, string characterName, Race characterRace);
    /**
     * Public method of Rogue that attacks an enemy Character
     * @param enemy Pointer to the enemy Character
     * @attention Follow these instructions:
     *  1. The damage for a Rogue is calculated by the weapon damage + half the dexterity value
     *  2. The enemy Character must take the damage dealt by the Rogue
     *  3. Use the PrintDamage method from the base class to print out the results
     */
    void Attack(Character * target);
    /**
     * Public method of Rogue that Back Stabs a target Character
     * @param target Pointer to the Character to be healed
     * @attention Follow these instructions:
     *  1. The Back Stab damage for a Rogue is calculated by the weapon damage + base damage value 50 + half the dexterity value
     *  2. The target Character must take damage the amount dealt by the Rogue
     *  3. Please use the PrintBackStab helper function
     */
    void BackStab(Character * target);
    /**
     * Public method Status that prints out the Status of the Rogue
     * @attention Use the PrintStatus helper function. Enter the attribute name exactly like it is listed
     *  in the header file
     * @example For the private variable "luck" which is set to 7 you would print the following
     *      PrintStatus(luck, 7);
     */
    void Status();
};

#endif //ROGUE_H