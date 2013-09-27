#include "ItmDictionary.h"

#include <map>

std::map<itm::ItemId, ItemDefinition*> ItmDictionary::registeredItems;
itm::ItemId ItmDictionary::erroneousItemId;

void ItmDictionary::addItem(itm::ItemId id, ItemDefinition* definition)
{
    registeredItems.insert(std::pair<itm::ItemId, ItemDefinition*>(id, definition));
}

void ItmDictionary::addItemAsErroneous(itm::ItemId id, ItemDefinition* definition)
{
    registeredItems.insert(std::pair<itm::ItemId, ItemDefinition*>(id, definition));

    erroneousItemId = id;
}

itm::ItemId ItmDictionary::getErroneousItemId()
{
    return erroneousItemId;
}

ItemDefinition* ItmDictionary::getItem(itm::ItemId id)
{
    std::map<itm::ItemId, ItemDefinition*>::iterator focus = registeredItems.find(id);

    if(focus == registeredItems.end())
    {
        return registeredItems.find(erroneousItemId)->second;
    }

    return focus->second;
}
