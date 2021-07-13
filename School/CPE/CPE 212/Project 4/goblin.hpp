/**
 * goblin.hpp - CPE 212-01, Spring 2020 - Project02 - Class Inheritance
 */
#include "character.hpp"
#include "inventory.hpp"
#ifndef GOBLIN_H
#define GOBLIN_H

/**
 * Private method to this file that displays the special attack for this character
 * @param characterName - Name of the character
 * @param targetName - Name of the recipient of the special attack
 * @param attackAmount - Amount of damage dealt by the character
 */
void PrintSneakAttack(string characterName, string targetName, int attackAmount);

class Goblin : public Character
{
private:
    int attack;
public:
    /**
     * Goblin Class constructor
     * @param characterName The name of the character being created
     * @param characterRace The race of the character being created. This is a enum value.
     * @extends This constructor extends the base Character constructor
     * @attention Follow these instructions:
     *  Goblin starts with 30 health
     *  Assign the starter weapon for the Goblin
     *      Weapon
     *         name : "Pointy Stick"
     *         cost : 1
     *         damage : 3
     *  Add the weapon to the Goblins inventory
     *  Assign a value of 2 for the base Goblin characteristic
     */
    Goblin(int id, string characterName, Race characterRace);
    /**
     * Public method of Goblin that attacks an enemy Character
     * @param enemy Pointer to the enemy Character
     * @attention Follow these instructions:
     *  1. The damage for a Goblin is calculated by the weapon damage + half the attack value
     *  2. The enemy Character must take the damage dealt by the Goblin
     *  3. Use the PrintDamage method from the base class to print out the results
     */
    void Attack(Character * target);
    /**
     * Public method of Goblin that Sneak Attacks a target Character
     * @param target Pointer to the Character to be healed
     * @attention Follow these instructions:
     *  1. The Sneak Attack damage for a Goblin is calculated by the base damage value 20 + half the attack value plus weapon damage
     *  2. The target Character must take damage the amount dealt by the Goblin
     *  3. Use the PrintSneakAttack function to print out the results
     */
    void SneakAttack(Character * target);
    /**
     * Public method Status that prints out the Status of the Goblin
     * @attention Use the PrintStatus helper function. Enter the attribute name exactly like it is listed
     *  in the header file
     * @example For the private variable "luck" which is set to 7 you would print the following
     *      PrintStatus(luck, 7);
     */
    void Status();
};

#endif