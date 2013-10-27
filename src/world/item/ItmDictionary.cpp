#include "ItmDictionary.h"

#include <map>

std::map<itm::ItemDefId, ItemDefinition*> ItmDictionary::registeredItems;
itm::ItemDefId ItmDictionary::erroneousItemDefId;

void ItmDictionary::addItem(itm::ItemDefId id, ItemDefinition* definition)
{
    registeredItems.insert(std::pair<itm::ItemDefId, ItemDefinition*>(id, definition));
}

void ItmDictionary::addItemAsErroneous(itm::ItemDefId id, ItemDefinition* definition)
{
    registeredItems.insert(std::pair<itm::ItemDefId, ItemDefinition*>(id, definition));

    erroneousItemDefId = id;
}

itm::ItemDefId ItmDictionary::getErroneousItemDefId()
{
    return erroneousItemDefId;
}

ItemDefinition* ItmDictionary::getItem(itm::ItemDefId id)
{
    std::map<itm::ItemDefId, ItemDefinition*>::iterator focus = registeredItems.find(id);

    if(focus == registeredItems.end())
    {
        return registeredItems.find(erroneousItemDefId)->second;
    }

    return focus->second;
}
