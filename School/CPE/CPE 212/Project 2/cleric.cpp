/**
 * cleric.cpp - CPE 212-01, Spring 2020 - Project02 - Class Inheritance
 */
#include "cleric.hpp"

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

Cleric::Cleric(string characterName, Race characterRace):Character(characterName, characterRace){
    Item item;
    SetJob("Cleric"); // sets the job of this person
    willpower = 10;         // default characteristic
    Weapon w;               // weapon object
    w.name = "Simple Wand"; // name of the weapon
    w.damage = 5;           // damage of the weapon
    w.cost = 100;           // cost of the weapon
    SetHealth(50);          // sets the health of the character
    SetWeapon(w);           // sets the weapon of the character based on the weapon object created
    item.name = w.name;     // creating a new item based on the weapon to add it to the characters inventory.
    item.value = w.cost;
    item.type = WEAPON;
    AddToInventory(item);
    GetLevel();
    GetExp();
}

/******************************************
 * Attack Function
 * Public method of Cleric that attacks an enemy Character
 * @param enemy Pointer to the enemy Character
 * @attention Follow these instructions:
 *  1. The damage for a Cleric is calculated by the weapon damage + half the willpower value
 *  2. The enemy Character must take the damage dealt by the Cleric
 *  3. Please print out the details of the attack in the following format
 *      <Character Name> attacks <Enemy Name> with <Character's Weapon Name> for <damage> points
 */
void Cleric::Attack(Character * enemy){
    int damage = this->GetWeapon().damage + willpower/2;
    cout << GetName() << " attacks " << enemy->GetName() << " with " << this->GetWeapon().name << " for " << damage << " points" << endl;
    enemy->TakeDamage(damage);
}



/** 
 * Heal Function
 * Public method of Cleric that heals a target Character
 * @param target Pointer to the Character to be healed
 * @attention Follow these instructions:
 *  1. The heal amount for a Cleric is calculated by the base heal value 10 + half the willpower value
 *  2. The target Character must heal the amount dealt by the Cleric
 *  3. Please print out the details of the attack in the following format
 *      <Character Name> heals <Target Name> for <heal amount> points
 */

 void Cleric::Heal(Character * target){
     int heal = 10 + willpower/2;
     int target_heal = target->GetHealth();
     cout << GetName() << " heals " << target->GetName() << " for " << heal << " points" << endl; 
     target->SetHealth(target_heal+heal); 
 }

/**
 * Status Function
 * Public method Status that prints out the Status of the Cleric
 * @attention You MUST print out the local Cleric variables.
 *  The format for the print must be "PrivateVar: PrivateVal" where the name of the private variable is capitalized
 * @example For the private variable luck which is set to 7 you would print the following
 *      "Luck: 7"
 */

 void Cleric::Status(){
     Character::Status();
     cout << "Willpower: " << willpower << endl; 
 }
