#include "ItemDefinition.h"

#include <vector>

#include "../../language/Grammar.h"

#ifdef DEBUG
#include "../../util/Sysout.h"
#endif // DEBUG

ItemDefinition::addName(NounId id)
{
    bool alreadyHas = false;

    for(std::vector<NounId>::iterator it = names.begin(); it != names.end(); ++ it)
    {
        if(*it == id)
        {
            alreadyHas = true;
            break;
        }
    }

    if(!alreadyHas)
    {
        names.push_back(id);
    }
    #ifdef DEBUG
    else
    {
        Sysout::print("Warning! You are trying to add an item name, but it already has it!");
    }
    #endif // DEBUG

    return this;
}

ItemDefinition::numNames()
{
    return names.size();
}

ItemDefinition::ItemDefinition()
{
    //ctor
}

ItemDefinition::~ItemDefinition()
{
    //dtor
}
