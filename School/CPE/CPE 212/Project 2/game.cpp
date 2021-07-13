#include <iostream>
#include <fstream>
#include <string>
#include "character.hpp"
#include "inventory.hpp"
#include "rogue.hpp"
#include "mage.hpp"
#include "warrior.hpp"
#include "goblin.hpp"
#include "cleric.hpp"

using namespace std;

void Bar();

int main (int argc, char * const argv[])
{
    ifstream inputs;					     // Input file stream variable for test file
    char op, ch, r, d, c, a;							 // Hold operation and optional char input from test file
    string   comment;                      // Holds comment string input from test file
    Warrior* warrior = NULL;
    Cleric* cleric = NULL;
    Rogue* rogue = NULL;
    Mage* mage = NULL;
    Goblin* goblin = NULL;

    string name;
    Race race;


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

    inputs >> op;				                         // Attempt to input first test operation from file

    while (inputs)                                     // While Not-EOF
    {
        switch (op)                                      // Process operation input from test file
        {
            case '#':   // Test file comment
                getline(inputs, comment);          // Input and echo the comment appearing in the test file
                cout << '#' << comment << endl;
                break;

            case 's':
                inputs >> c;    // Job Type to see the Status
                switch (c)
                {
                    case 'w': warrior->Status(); break;
                    case 'm': mage->Status(); break;
                    case 'r': rogue->Status(); break;
                    case 'c': cleric->Status(); break;
                    case 'g': goblin->Status(); break;
                }
                break;
            case 'i':
                inputs >> c;    // Job Type to see the Status
                switch (c)
                {
                    case 'w': warrior->ShowInventory(); break;
                    case 'm': mage->ShowInventory(); break;
                    case 'r': rogue->ShowInventory(); break;
                    case 'c': cleric->ShowInventory(); break;
                    case 'g': goblin->ShowInventory(); break;
                }
                break;

            case 'b':   // Print Bar
                Bar();         // Function definition appears at the end of this file
                break;

            case '+':   // Constructor
                inputs >> ch;       // Job to create
                inputs >> r;     // Race
                inputs >> name;     // Name

                switch(r)
                {
                    case 'h':
                        race = HUMAN;
                        break;
                    case 'e':
                        race = ELF;
                        break;
                    case 'd':
                        race = DWARF;
                        break;
                    case 'n':
                        race = GNOME;
                        break;
                    case 'g':
                        race = GOBLIN;
                        break;
                    default:
                        cout << "We do not support that race in this game" << endl;
                        return 1;
                }

                try {
                    switch (ch)
                    {
                        case 'w':
                            warrior = new Warrior(name, race);
                            break;
                        case 'm':
                            mage = new Mage(name, race);
                            break;
                        case 'r':
                            rogue = new Rogue(name, race);
                            break;
                        case 'c':
                            cleric = new Cleric(name, race);
                            break;
                        case 'g':
                            goblin = new Goblin(name, race);
                            break;
                        default:
                            cout << "The game does not support that Job" << endl;
                            break;
                    }
                }
                catch ( ... )                      // Catch any exception thrown above
                {
                    cout << "Failed";
                }

                cout << endl;
                break;

            case '-':   // Destructor
                inputs >> d;
                switch (d)
                {
                    case 'w':
                        delete warrior;
                        warrior = NULL;
                        break;
                    case 'm':
                        delete mage;
                        mage = NULL;
                        break;
                    case 'r':
                        delete rogue;
                        rogue = NULL;
                        break;
                    case 'c':
                        delete cleric;
                        cleric = NULL;
                        break;
                    case 'g':
                        delete goblin;
                        goblin = NULL;
                        break;
                    default:
                        cout << "The game does not support that Job" << endl;
                        break;
                }
                break;
            case 'a': // Attack
                inputs >> d;    // Enemy or Character Type: w, m, r, c
                inputs >> r;    // Attack method: a for regular and s or special class specific attack
                switch (d)
                {
                    case 'w':
                        if (r == 'a')
                        {
                            warrior->Attack(goblin);
                        }
                        else {
                            warrior->PowerAttack(goblin);
                        }
                        break;
                    case 'm':
                        if (r == 'a')
                        {
                            mage->Attack(goblin);
                        }
                        else {
                            mage->Fireball(goblin);
                        }
                        break;
                    case 'r':
                        if (r == 'a')
                        {
                            rogue->Attack(goblin);
                        }
                        else {
                            rogue->BackStab(goblin);
                        }
                        break;
                    case 'c':
                        if (r == 'a')
                        {
                            cleric->Attack(goblin);
                        }
                        else {
                            inputs >> c;    // Destination of the action
                            switch (c)
                            {
                                case 'w': cleric->Heal(warrior); break;
                                case 'm': cleric->Heal(mage); break;
                                case 'r': cleric->Heal(rogue); break;
                                case 'c': cleric->Heal(cleric); break;
                            }
                        }
                        break;
                    case 'g':
                        inputs >> c;    // Destination of the action
                        if (r == 'a')
                        {
                            switch (c)
                            {
                                case 'w': goblin->Attack(warrior); break;
                                case 'm': goblin->Attack(mage); break;
                                case 'r': goblin->Attack(rogue); break;
                                case 'c': goblin->Attack(cleric); break;
                            }
                        }
                        else {
                            switch (c)
                            {
                                case 'w': goblin->SneakAttack(warrior); break;
                                case 'm': goblin->SneakAttack(mage); break;
                                case 'r': goblin->SneakAttack(rogue); break;
                                case 'c': goblin->SneakAttack(cleric); break;
                            }
                        }
                        break;
                    default:
                        cout << "The game does not support that Job" << endl;
                        break;
                }
                break;
            default:    // Error
                cout << "Error - unrecognized operation '" << op << "'" << endl;
                cout << "Terminating now..." << endl;
                return 1;
                break;
        }
        inputs >> op;	                                 // Attempt to input next command
    }


    return 0;
}

void Bar() {
    cout << "-------------------------" << endl;
}