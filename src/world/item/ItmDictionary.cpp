#include "ItmDictionary.h"

#include <map>

std::map<itm::ItemId, ItemDefinition*> ItemDictionary::registeredItems;
itm::ItemId ItemDictionary::erroneousItemId;

void ItemDictionary::addItem(itm::ItemId id, ItemDefinition* definition)
{
    registeredItems.insert(std::pair<itm::ItemId, ItemDefinition*>(id, definition));
}

void ItemDictionary::addItemAsErroneous(itm::ItemId id, ItemDefinition* definition)
{
    registeredItems.insert(std::pair<itm::ItemId, ItemDefinition*>(id, definition));

    erroneousItemId = id;
}

itm::ItemId ItemDictionary::getErroneousItemId()
{
    return erroneousItemId;
}

ItemDefinition* ItemDictionary::getItem(itm::ItemId id)
{
    std::map<itm::ItemId, ItemDefinition*>::iterator focus = registeredItems.find(id);

    if(focus == registeredItems.end())
    {
        return registeredItems.find(erroneousItemId)->second;
    }

    return focus->second;
}
