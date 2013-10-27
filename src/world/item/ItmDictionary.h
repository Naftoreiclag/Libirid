#ifndef ITMDICTIONARY_H
#define ITMDICTIONARY_H

#include <map>

#include "ItemDefinition.h"

class ItmDictionary
{
    public:
        static void addItem(itm::ItemDefId id, ItemDefinition* definition);
        static void addItemAsErroneous(itm::ItemDefId id, ItemDefinition* definition);
        static itm::ItemDefId getErroneousItemDefId();
        static ItemDefinition* getItem(itm::ItemDefId id);
    private:
        static itm::ItemDefId erroneousItemDefId;
        static std::map<itm::ItemDefId, ItemDefinition*> registeredItems;
};

#endif // ITMDICTIONARY_H
