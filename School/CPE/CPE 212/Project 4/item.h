#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

enum Type
{
    POTION = 0,
    WEAPON = 1,
    ARMOR = 2,
    ACCESSORY = 3,
    RAWGOLD = 4,
};

static const std::string TypeStrings[] = {"Potion", "Weapon", "Armor", "Accessory", "RawGold"};

class Item
{
private:
    std::string name;
    float value;
    Type type;

public:
    Item(std::string n, float v, Type t)
    {
        name = n;
        value = v;
        type = t;
    };

    Item() = default;
    std::string GetName() const {
        return name;
    };

    float GetValue() const {
        return value;
    };

    std::string GetType() const {
        return TypeStrings[type];
    };

    void Set(std::string n, float v, Type t)
    {
        name = n;
        value = v;
        type = t;
    };

    void SetName(std::string n)
    {
        name = n;
    };

    void SetValue(float v)
    {
        value = v;
    };

    void SetType(Type t)
    {
        type = t;
    };

    // Overloads (new)
    bool operator==(const Item & otherItem) const;
    bool operator!=(const Item & otherItem) const;
    bool operator>(const Item & otherItem) const;
    bool operator<(const Item & otherItem) const;
    bool operator>=(const Item & otherItem) const;
    bool operator<=(const Item & otherItem) const;

    friend std::ostream& operator<<(std::ostream& os, const Item& item)
    {
        os << item.type;
        return os;
    }
};

#endif //ITEM_H
