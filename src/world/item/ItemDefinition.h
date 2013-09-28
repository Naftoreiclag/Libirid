#ifndef ITEMDEFINITION_H
#define ITEMDEFINITION_H

#include <vector>

#include "../../language/Grammar.h"

class ItemDefinition
{
    public:
        ItemDefinition* addName(NounId id);
        unsigned int numNames();

        ItemDefinition();
        virtual ~ItemDefinition();
    private:
        std::vector<NounId> names;
};

#endif // ITEMDEFINITION_H
