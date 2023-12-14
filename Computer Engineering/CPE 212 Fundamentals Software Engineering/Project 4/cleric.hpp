/**
 * cleric.hpp - CPE 212-01, Spring 2020 - Project02 - Class Inheritance
 */
#include "character.hpp"
#include "inventory.hpp"

#ifndef CLERIC_H
#define CLERIC_H

/**
 * Private method to this file that displays the special attack for this character
 * @param characterName - Name of the character
 * @param targetName - Name of the recipient of the special attack
 * @param healAmount - Amount of damage healed by the character
 */
void PrintHeal(string characterName, string targetName, int healAmount);

class Cleric: public Character
{
private:
    int willpower;
public:
    /**
     * Cleric Class constructor
     * @param characterName The name of the character being created
     * @param characterRace The race of the character being created. This is a enum value.
     * @extends This constructor extends the base Character constructor
     * @attention Follow these instructions:
     *  Cleric starts with 50 health
     *  Assign the starter weapon for the Cleric
     *      Weapon
     *         name : "Simple Wand"
     *         cost : 100
     *         damage : 5
     *  Add the weapon to the Clerics inventory
     *  Assign a value of 10 for the base Cleric characteristic
     */
    Cleric(int id, string characterName, Race characterRace);
    /**
     * Public method of Cleric that attacks an enemy Character
     * @param enemy Pointer to the enemy Character
     * @attention Follow these instructions:
     *  1. The damage for a Cleric is calculated by the weapon damage + half the willpower value
     *  2. The enemy Character must take the damage dealt by the Cleric
     *  3. Use the PrintDamage method from the base class to print out the results
     */
    void Attack(Character * enemy);
    /**
     * Public method of Cleric that heals a target Character
     * @param target Pointer to the Character to be healed
     * @attention Follow these instructions:
     *  1. The heal amount for a Cleric is calculated by the base heal value 10 + half the willpower value
     *  2. The target Character must heal the amount dealt by the Cleric
     *  3. Please use the PrintHeal helper function
     */
    void Heal(Character * target);
    /**
     * Public method Status that prints out the Status of the Cleric
     * @attention Use the PrintStatus helper function. Enter the attribute name exactly like it is listed
     *  in the header file
     * @example For the private variable "luck" which is set to 7 you would print the following
     *      PrintStatus(luck, 7);
     */
    void Status();
};


#endif //CLERIC_H
