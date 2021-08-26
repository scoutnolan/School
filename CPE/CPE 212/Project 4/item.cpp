#include "item.h"

/**
* Student Section Begin
*/
bool Item::operator==(const Item &otherItem) const
{
    return this->type == otherItem.type;
    /**
     * Implement this operator using the name and type
     */
}

bool Item::operator!=(const Item &otherItem) const
{
    return this->type != otherItem.type;
    /**
     * Implement this operator
     */
}

bool Item::operator<(const Item & otherItem) const
{
    return this->type < otherItem.type;
    /**
     * Implement this operator using the name
     */
}

bool Item::operator>(const Item & otherItem) const
{
    return this->type > otherItem.type;
    /**
     * Implement this operator using the name
     */
}

bool Item::operator<=(const Item & otherItem)  const
{
    return this->type <= otherItem.type;
    /**
     * Implement this operator
     */
}

bool Item::operator>=(const Item & otherItem)  const
{
    return this->type >= otherItem.type;
    /**
     * Implement this operator using the name
     */
}
/**
* Student Section End
*/
