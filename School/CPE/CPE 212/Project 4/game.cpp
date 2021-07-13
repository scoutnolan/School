#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "party.hpp"
#include "character.hpp"
#include "inventory.hpp"
#include "rogue.hpp"
#include "mage.hpp"
#include "warrior.hpp"
#include "goblin.hpp"
#include "cleric.hpp"

using namespace std;


static void Bar() {
    cout << "-------------------------" << endl;
}


static void TrimName(std::string & name)
{
    if(name.front() == ' ')
    {
        name.erase(0, 1);
    }
    if(name.front() == '\"')
    {
        name.erase(0, 1);
    }
    if(name.back() == '\"')
    {
        name.erase(name.size() - 1);   
    }
}

static std::string ReadName(std::ifstream &stream)
{
    int quoteCount = 0;
    std::string name;
    while(quoteCount < 2)
    {
        std::string tmp;
        stream >> tmp;
        for(const auto & c : tmp)
        {
            if(c == '\"')
            {
                quoteCount ++;
            }
        }
        name += tmp;
        if(quoteCount != 2)
        {
            name += " ";
        }
    }
    TrimName(name);
    return name;
}


Party *ReadVilliansFile(const std::string &inFile, bool &success)
{
    Party *enemies = new Party("Enemies");
    Character *lastEnemy;
    std::cout << "Reading input file: " << inFile << std::endl;
    ifstream input;
    input.open(inFile);
    if(!input.is_open())
    {
        std:cout << "Failed to open input file" << std::endl;
        success = false;
        return NULL;
    }

    char op;
    input >> op;
    while(input)
    {
        switch(op)
        {
            case '+':
            {
                int uid;
                int quoteCount =0;
                input >> op;
                input >> uid;
                std::string newGoblinLine = ReadName(input);
                Goblin *g = new Goblin(uid, newGoblinLine, GOBLIN);
                enemies->AddMember(g);
                lastEnemy = g;
                break;
            }
            case 'i':
            {
                int uid;
                int value;
                char type;
                Type t;
                input >> uid;
                input >> type;
                switch(type)
                {
                    case 'r': 
                        t = RAWGOLD;
                        break;
                    case 'p':
                        t = POTION;
                        break;
                    case 'w':
                        t = WEAPON;
                        break;
                    case 'm':
                        t = ARMOR;
                        break;
                    case 'a':
                        t = ACCESSORY;
                        break;
                    default:
                        t = RAWGOLD;
                        break;
                }
                input >> value;
                std::string name = ReadName(input);
                Item i(name, value, t);
                lastEnemy = enemies->FindMember(uid);
                if(lastEnemy == nullptr)
                {
                    std::cout << "FAILED TO FIND MEMBER UID: " << uid << std::endl;
                    return nullptr;
                }
                lastEnemy->AddToInventory(i);
                break;
            }
            default:
            {
                std::cout << "UNknown operator: " << op << std::endl;
                return nullptr;
            }
        }

        input >> op;
    }


    // enemies->PrintAll();
    success = true;
    return enemies;

}


int main(int argc, char* const argv[])
{
    Party *heroes = new Party("Heroes");
    Party *villians;
    Character *lastHero;
    ifstream inputs;
    std::string comment;

    char op;


    // Output usage message if test input file name is not provided
    if (argc != 2)
    {
        cout << "Usage:\n  Game  <inputfile>\n";
        return 1;
    }

    // Attempt to open test input file -- terminate if file does not open
    inputs.open(argv[1]);
    if (!inputs)
    {
        cout << "Error - unable to open input file" << endl;
        return 1;
    }

    // Process comment line from input file
    getline(inputs, comment);                          // Input file header comment
    cout << endl << comment << endl << endl;           // Output file header comment


    // Below is the primary loop that processes each operation appearing within the test file.
    // Starts with an initial priming read of first operation

    inputs >> op;
    while(inputs)
    {
        switch(op)
        {
            case 'c': /// combat
            {
                char attackerType;
                int uidAttacker;
                int uidDefender;
                Party *attacker;
                Party *defender;
                inputs >> attackerType;
                inputs >> uidAttacker;
                inputs >> uidDefender;
                switch(attackerType)
                {
                    case ('a'):
                    {
                        attacker = heroes;
                        defender = villians;
                        break;
                    }
                    case ('e'):
                    {
                        attacker = villians;
                        defender = heroes;
                        break;
                    }
                    default: 
                        std::cout << "UNKNOWN ATTACKER TYPE : " << attackerType << std::endl;
                        return -1;
                }
                if(attacker == nullptr)
                {
                    std::cout << "ATTACKER NOT FOUND: " << uidAttacker << std::endl;
                    return -1;
                }
                if(defender == nullptr)
                {
                    std::cout << "DEFENDER NOT FOUND: " << uidDefender << std::endl;
                    return -1;
                }

                attacker->Attack(defender, uidAttacker, uidDefender);
                break;
            }
            case 'v':   /// villian script
            {                
                std::string inputFile;
                inputs >> inputFile;
                bool success = false;
                villians = ReadVilliansFile(inputFile, success);
                if(!success)
                {
                    std::cout << "FAILED TO READ VILLIAN FILE" << std::endl;
                    return -1;
                }
                
                break;
            } 
            case '+':   /// add a hero
            {
                Character * newHero;
                char cl;
                int uid;
                char race;
                inputs >> cl;
                inputs >> uid;
                inputs >> race;
                std::string name = ReadName(inputs);
                Race r;
                switch(race)
                {
                    case 'h':
                        r = HUMAN;
                        break;
                    case 'e':
                        r = ELF;
                        break;
                    case 'd':
                        r = DWARF;
                        break;
                    case 'g':
                        r = GNOME;
                        break;
                    default:
                        std::cout << "UNKNOWN RACE CAUGHT: " << r << std::endl;
                        return -1;
                }
                switch(cl)
                {
                    case 'r':   /// rogue
                    {
                        newHero = new Rogue(uid, name, r);
                        break;
                    }
                    case 'm':   /// mage
                    {
                        newHero = new Mage(uid, name, r);
                        break;
                    }
                    case 'w':   /// warrior
                    {
                        newHero = new Warrior(uid, name, r);
                        break;
                    }
                    case 'c': /// cleric
                    {
                        newHero = new Cleric(uid, name, r);
                        break;
                    }
                    default:
                    {
                        std::cout << "Unknown class type found: " << cl << std::endl;
                        return -1;
                    }
                }
                heroes->AddMember(newHero);
                break;
            }      
            case 'p':   /// print
            {
                char type;
                char what;
                int uid;
                inputs >> type;
                switch(type)
                {
                    case 'e':   /// enemies party
                    {
                        inputs >> what;
                        switch(what)
                        {
                            case 'i':
                            {
                                inputs >> uid;
                                std::cout << "UID: " <<  uid << std::endl;
                                Character *thing = villians->FindMember(uid);
                                if(thing == nullptr)
                                {
                                    std::cout << "UID: " << uid << " does not exist in villians" << std::endl;
                                    return -1;
                                }
                                thing->DisplayInventory();
                                break;
                            }
                            case 's':
                            {
                                inputs >> uid;
                                Character *thing = villians->FindMember(uid);
                                if(thing == nullptr)
                                {
                                    std::cout << "UID: " << uid << " does not exist in villians" << std::endl;
                                    return -1;
                                }
                                villians->PrintHeader();
                                villians->PrintMemberData(thing);
                                villians->PrintFooter();
                                break;
                            }
                            case 'a':
                            {
                                villians->PrintAll();
                                break;
                            }
                            default: 
                            {
                                std::cout << "Unknown type to print: " << what << std::endl;
                                return -1;
                                break;
                            }
                        }
                        break;
                    }
                    case 'p': /// player party
                    {
                        inputs >> what;
                        switch(what)
                        {
                            case 'i':
                            {
                                inputs >> uid;
                                std::cout << "UID: " <<  uid << std::endl;
                                Character *thing = heroes->FindMember(uid);
                                if(thing == nullptr)
                                {
                                    std::cout << "UID: " << uid << " does not exist in villians" << std::endl;
                                    return -1;
                                }
                                thing->DisplayInventory();
                                break;
                            }
                            case 's':
                            {
                                inputs >> uid;
                                Character *thing = heroes->FindMember(uid);
                                if(thing == nullptr)
                                {
                                    std::cout << "UID: " << uid << " does not exist in villians" << std::endl;
                                    return -1;
                                }
                                heroes->PrintHeader();
                                heroes->PrintMemberData(thing);
                                heroes->PrintFooter();
                                break;
                            }
                            case 'a':
                            {
                                heroes->PrintAll();
                                break;
                            }
                            default: 
                            {
                                std::cout << "Unknown type to print: " << what << std::endl;
                                return -1;
                                break;
                            }
                        }     
                        break;               
                    }
                    default:
                    {
                        std::cout << "UNKNOWN INPUT CAUGHT: " << type << std::endl;
                        return -1;
                    }
                }
                break;
            } 
            case 'i':   /// inventory
            {
                int uid;
                int value;
                char type;
                Type t;
                inputs >> uid;
                inputs >> value;
                inputs >> type;
                switch(type)
                {
                    case 'r': 
                        t = RAWGOLD;
                        break;
                    case 'p':
                        t = POTION;
                        break;
                    case 'w':
                        t = WEAPON;
                        break;
                    case 'm':
                        t = ARMOR;
                        break;
                    case 'a':
                        t = ACCESSORY;
                        break;
                    default:
                        t = RAWGOLD;
                        break;
                }
                std::string name = ReadName(inputs);
                Item i(name, value, t);
                Character *person = heroes->FindMember(uid);
                if(person == nullptr)
                {
                    std::cout << "FAILED TO FIND MEMBER UID: " << uid << std::endl;
                    return -1;
                }
                person->AddToInventory(i);
                break;
            }
            case '#':   /// comment
            {
                getline(inputs, comment);
                std::cout << "#" <<  comment << std::endl;
                break;
            }
            default:
            {
                std::cout << "UNKOWN INPUT CAUGHT: " << op << std::endl;
                return -1;
            }
        }
        inputs >> op;
    }	

}

// int main (int argc, char * const argv[])
// {

//     Party *heroes = new Party("Heroes");
//     Party *villians = new Party("Villians");
//     Rogue *r = new Rogue(2343, "Roguey McRoguerson", HUMAN);
//     Mage *m = new Mage(3325, "Magus McFirepants", ELF);
//     Warrior *w = new Warrior(2445, "Shamus McDoof", DWARF);
//     Cleric *c = new Cleric(2653, "Bill McDevotee", GNOME);
//     Goblin *g = NULL;

//     g = new Goblin(5, "Generic Goblin 1", GOBLIN);
//     villians->AddMember(g);
//     g = new Goblin(4, "Generic Goblin 2", GOBLIN);
//     villians->AddMember(g);
//     g = new Goblin(3, "Generic Goblin 3", GOBLIN);
//     villians->AddMember(g);
//     g = new Goblin(2, "Generic Goblin 4", GOBLIN);
//     villians->AddMember(g);
//     g = new Goblin(1, "Generic Goblin 5", GOBLIN);
//     villians->AddMember(g);
//     r->DisplayInventory();
//     heroes->AddMember(r);
//     heroes->AddMember(m);
//     heroes->AddMember(w);
//     heroes->AddMember(c);
//     heroes->ShowParty();
//     villians->ShowParty();
//     heroes->AttackSpecific(villians, 2343, 5);
//     heroes->AttackSpecific(villians, 3325, 5);
//     heroes->AttackSpecific(villians, 2445, 5);
//     w->DisplayInventory();

//     villians->ShowParty();
//     return 0;
// }

// int main (int argc, char * const argv[])
// {
//     ifstream inputs;		    // Input file stream variable for test file
//     char op, ch, r, d, c, a, id, p, v, i;	// Hold operation and optional char input from test file
//     string   comment;           // Holds comment string input from test file
//     Warrior* warrior = NULL;
//     Cleric* cleric = NULL;
//     Rogue* rogue = NULL;
//     Mage* mage = NULL;
//     Goblin* goblin = NULL;


//     Character *lastCharacter;

//     string name;
//     Race race;
//     Type itemType;
//     Item item;


//     // Output usage message if test input file name is not provided
//     if (argc != 2)
//     {
//         cout << "Usage:\n  Game  <inputfile>\n";
//         return 1;
//     }

//     // Attempt to open test input file -- terminate if file does not open
//     inputs.open(argv[1]);
//     if (!inputs)
//     {
//         cout << "Error - unable to open input file" << endl;
//         return 1;
//     }

//     // Process comment line from input file
//     getline(inputs, comment);                          // Input file header comment
//     cout << endl << comment << endl << endl;           // Output file header comment


//     // Below is the primary loop that processes each operation appearing within the test file.
//     // Starts with an initial priming read of first operation

//     inputs >> op;				                         // Attempt to input first test operation from file

//     while (inputs)                                     // While Not-EOF
//     {
//         switch (op)                                      // Process operation input from test file
//         {
//             case '#':   // Test file comment
//                 getline(inputs, comment);          // Input and echo the comment appearing in the test file
//                 cout << '#' << comment << endl;
//                 break;

//             case 's':
//                 inputs >> c;    // Job Type to see the Status
//                 switch (c)
//                 {
//                     case 'w': warrior->Status(); break;
//                     case 'm': mage->Status(); break;
//                     case 'r': rogue->Status(); break;
//                     case 'c': cleric->Status(); break;
//                     case 'g': goblin->Status(); break;
//                     default: break;
//                 }
//                 break;
//             case 'i':
//                 inputs >> ch;       // Job of the player to add inventory to
//                 inputs >> v;        // Value of the item to be added
//                 inputs >> i;        // Type of the Item
//                 inputs >> name;     // Name

//                 switch(i)
//                 {
//                     case 'p':
//                         itemType = POTION;
//                         break;
//                     case 'w':
//                         itemType = WEAPON;
//                         break;
//                     case 'c':
//                         itemType = ACCESSORY;
//                         break;
//                     case 'a':
//                         itemType = ARMOR;
//                         break;
//                     case 'r':
//                         itemType = RAWGOLD;
//                         break;
//                     default:
//                         cout << "We do not support that item type in this game" << endl;
//                         return 1;
//                 }

//                 item.Set(name, v, itemType);

//                 // lastCharacter->AddToInventory(item);

//                 switch (ch)
//                 {
//                     case 'w': warrior->AddToInventory(item); break;
//                     case 'm': mage->AddToInventory(item); break;
//                     case 'r': rogue->AddToInventory(item); break;
//                     case 'c': cleric->AddToInventory(item); break;
//                     case 'g': lastCharacter->AddToInventory(item); break;
//                     default: break;

//                 }
//                 break;

//             case 'b':          // Print Bar
//                 Bar();         // Function definition appears at the end of this file
//                 break;

//             case 'p':
//                 inputs >> p;    // What to print
//                 inputs >> c;    // Job Type of element to print
//                 switch(p)
//                 {
//                     case 'i':
//                         switch (c)
//                         {
//                             case 'w': warrior->DisplayInventory(); break;
//                             case 'm': mage->DisplayInventory(); break;
//                             case 'r': rogue->DisplayInventory(); break;
//                             case 'c': cleric->DisplayInventory(); break;
//                             case 'g': goblin->DisplayInventory(); break;
//                         }
//                     default:
//                         break;
//                 }
//                 break;

//             case '+':   // Constructor
//                 inputs >> ch;       // Job to create
//                 inputs >> id;       // ID of the Character
//                 inputs >> r;        // Race
//                 inputs >> name;     // Name

//                 cout << "Job: " << ch << endl;
//                 cout << "ID: " << id << endl;
//                 cout << "Race: " << r << endl;
//                 cout << "Name: " << name << endl;

//                 switch(r)
//                 {
//                     case 'h':
//                         race = HUMAN;
//                         break;
//                     case 'e':
//                         race = ELF;
//                         break;
//                     case 'd':
//                         race = DWARF;
//                         break;
//                     case 'n':
//                         race = GNOME;
//                         break;
//                     case 'g':
//                         race = GOBLIN;
//                         break;
//                     default:
//                         cout << "We do not support that race in this game" << endl;
//                         return 1;
//                 }

//                 try {
//                     switch (ch)
//                     {
//                         case 'w':
//                             warrior = new Warrior(id, name, race);
//                             break;
//                         case 'm':
//                             mage = new Mage(id, name, race);
//                             break;
//                         case 'r':
//                             rogue = new Rogue(id, name, race);
//                             break;
//                         case 'c':
//                             cleric = new Cleric(id, name, race);
//                             break;
//                         case 'g':
//                             goblin = new Goblin(id, name, race);
//                             lastCharacter = (Character*)goblin;
//                             break;
//                         default:
//                             cout << "The game does not support that Job" << endl;
//                             break;
//                     }
//                 }
//                 catch ( ... )                      // Catch any exception thrown above
//                 {
//                     cout << "Failed";
//                 }

//                 cout << endl;
//                 break;

//             case '-':   // Destructor
//                 inputs >> d;
//                 switch (d)
//                 {
//                     case 'w':
//                         delete warrior;
//                         warrior = NULL;
//                         break;
//                     case 'm':
//                         delete mage;
//                         mage = NULL;
//                         break;
//                     case 'r':
//                         delete rogue;
//                         rogue = NULL;
//                         break;
//                     case 'c':
//                         delete cleric;
//                         cleric = NULL;
//                         break;
//                     case 'g':
//                         delete goblin;
//                         goblin = NULL;
//                         break;
//                     default:
//                         cout << "The game does not support that Job" << endl;
//                         break;
//                 }
//                 break;
//             case 'a': // Attack
//                 inputs >> d;    // Enemy or Character Type: w, m, r, c
//                 inputs >> r;    // Attack method: a for regular and s or special class specific attack
//                 switch (d)
//                 {
//                     case 'w':
//                         if (r == 'a')
//                         {
//                             warrior->Attack(goblin);
//                         }
//                         else {
//                             warrior->PowerAttack(goblin);
//                         }
//                         break;
//                     case 'm':
//                         if (r == 'a')
//                         {
//                             mage->Attack(goblin);
//                         }
//                         else {
//                             mage->Fireball(goblin);
//                         }
//                         break;
//                     case 'r':
//                         if (r == 'a')
//                         {
//                             rogue->Attack(goblin);
//                         }
//                         else {
//                             rogue->BackStab(goblin);
//                         }
//                         break;
//                     case 'c':
//                         if (r == 'a')
//                         {
//                             cleric->Attack(goblin);
//                         }
//                         else {
//                             inputs >> c;    // Destination of the action
//                             switch (c)
//                             {
//                                 case 'w': cleric->Heal(warrior); break;
//                                 case 'm': cleric->Heal(mage); break;
//                                 case 'r': cleric->Heal(rogue); break;
//                                 case 'c': cleric->Heal(cleric); break;
//                             }
//                         }
//                         break;
//                     case 'g':
//                         inputs >> c;    // Destination of the action
//                         if (r == 'a')
//                         {
//                             switch (c)
//                             {
//                                 case 'w': goblin->Attack(warrior); break;
//                                 case 'm': goblin->Attack(mage); break;
//                                 case 'r': goblin->Attack(rogue); break;
//                                 case 'c': goblin->Attack(cleric); break;
//                             }
//                         }
//                         else {
//                             switch (c)
//                             {
//                                 case 'w': goblin->SneakAttack(warrior); break;
//                                 case 'm': goblin->SneakAttack(mage); break;
//                                 case 'r': goblin->SneakAttack(rogue); break;
//                                 case 'c': goblin->SneakAttack(cleric); break;
//                             }
//                         }
//                         break;
//                     default:
//                         cout << "The game does not support that Job" << endl;
//                         break;
//                 }
//                 break;
//             default:    // Error
//                 cout << "Error - unrecognized operation '" << op << "'" << endl;
//                 cout << "Terminating now..." << endl;
//                 return 1;
//                 break;
//         }
//         inputs >> op;	                                 // Attempt to input next command
//     }


//     return 0;
// }
