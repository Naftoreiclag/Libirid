#ifndef ITEMDEFINITION_H
#define ITEMDEFINITION_H

#include <vector>

#include "../../language/Grammar.h"

class ItemDefinition
{
    public:
        ItemDefinition* addName(gmr::NounId id);
        unsigned int numNames();

        ItemDefinition();
        virtual ~ItemDefinition();
    private:
        std::vector<gmr::NounId> names;
};

#endif // ITEMDEFINITION_H
