#ifndef PARTY_HPP
#define PARTY_HPP

#include "list.hpp"
#include "character.hpp"
#include "inventory.hpp"
#include "rogue.hpp"
#include "mage.hpp"
#include "warrior.hpp"
#include "goblin.hpp"
#include "cleric.hpp"
#include <iomanip>

#include <string>

class Party
{
private:
    std::string name;
    List<Character *> members;
    int size = 0;

public:
    Party(const std::string & name);
    Party();

    std::string GetName() const;
    void AddMember(Character *c);
    bool RemoveMember(Character *c);
    Character* FindMember(int id);
    void ShowParty() const;

    void Attack(Party* targetGroup, int playerUID, int targetUID);
    
    int GetSize() const;
    
    // provided
    void PrintMemberData(Character *m) const;
    void PrintHeader() const
    {
        std::cout << "--------------------------------------------------------------------" << std::endl;
        std::cout << "                      Party Screen: " << name << std::endl;
        std::cout << "--------------------------------------------------------------------" << std::endl;
        std::cout << "ID   Name              Level  Health    Race    Job" << std::endl;
        std::cout << "--------------------------------------------------------------------" << std::endl;
    }

    void PrintFooter() const
    {
        std::cout << "--------------------------------------------------------------------" << std::endl;
    }
    void PrintAll() const
    {
        PrintHeader();
        members.ResetIterator();
        while(!members.AtEnd())
        {
            PrintMemberData(*members.IterateItems());
        }
        PrintFooter();
    }

};


#endif // #ifndef PARTY_HPP