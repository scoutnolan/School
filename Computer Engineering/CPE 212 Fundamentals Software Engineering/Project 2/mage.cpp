/**
 * mage.cpp - CPE 212-01, Spring 2020 - Project02 - Class Inheritance
 */
#include "mage.hpp"

/**
 * Mage Class constructor
 * @param characterName The name of the character being created
 * @param characterRace The race of the character being created. This is a enum value.
 * @extends This constructor extends the base Character constructor
 * @attention Follow these instructions:
 *  Mage starts with 50 health
 *  Assign the starter weapon for the Cleric
 *      Weapon
 *         name : "Simple Staff"
 *         cost : 100
 *         damage : 5
 *  Add the weapon to the Mage inventory
 *  Assign a value of 10 for the base Mage characteristic
 */
Mage::Mage(string characterName, Race characterRace):Character(characterName, characterRace){
    SetJob("Mage");            // sets the job of this person
    intelligence = 10;         // default characteristic
    Weapon w;                  // weapon object
    w.name = "Simple Staff";   // name of the weapon
    w.damage = 5;              // damage of the weapon
    w.cost = 100;              // cost of the weapon
    SetHealth(50);             // sets the health of the character
    SetWeapon(w);              // sets the weapon of the character based on the
    Item item;
    item.name = w.name;
    item.value = w.cost;
    item.type = WEAPON;
    AddToInventory(item);
}
/**
 * Public method of Mage that attacks an enemy Character
 * @param enemy Pointer to the enemy Character
 * @attention Follow these instructions:
 *  1. The damage for a Mage is calculated by the weapon damage + half the intelligence value
 *  2. The enemy Character must take the damage dealt by the Mage
 *  3. Please print out the details of the attack in the following format
 *      <Character Name> attacks <Enemy Name> with <Character's Weapon Name> for <damage> points
 */

void Mage::Attack(Character * enemy){
    int damage = this->GetWeapon().damage + intelligence/2;
    cout << GetName() << " attacks " << enemy->GetName() << " with " << this->GetWeapon().name << " for " << damage << " points" << endl;
    enemy->TakeDamage(damage);
}

/**
 * Public method of Mage that sends a Fireball at an enemy Character
 * @param enemy Pointer to the enemy Character
 * @attention Follow these instructions:
 *  1. The damage for a Fireball is calculated by the base damage 10 + weapon damage + half the intelligence value
 *  2. The enemy Character must take the damage dealt by the Mage
 *  3. Please print out the details of the attack in the following format
 *      <Character Name> attacks <Enemy Name> with a Fireball for <damage> points
 */
void Mage::Fireball(Character * target){
     int damage = this->GetWeapon().damage + 10 + intelligence/2;
     cout << GetName() << " attacks " << target->GetName() << " with a Fireball for " << damage << " points" << endl;  
     target->TakeDamage(damage);
 }

/**
 * Public method Status that prints out the Status of the Cleric
 * @attention You MUST print out the local Cleric variables.
 *  The format for the print must be "PrivateVar: PrivateVal" where the name of the private variable is capitalized
 * @example For the private variable luck which is set to 7 you would print the following
 *      "Luck: 7"
 */

void Mage::Status(){
    Character::Status();
    cout << "Intelligence: " << intelligence << endl;
}