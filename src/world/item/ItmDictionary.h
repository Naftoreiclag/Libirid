#ifndef ITEMDICTIONARY_H
#define ITEMDICTIONARY_H

#include <map>

class ItemDefinition;

namespace itm
{
    typedef unsigned int ItemId;
}

class ItemDictionary
{
    public:
        static void addItem(itm::ItemId id, ItemDefinition* definition);
        static void addItemAsErroneous(itm::ItemId id, ItemDefinition* definition);
        static itm::ItemId getErroneousItemId();
        static ItemDefinition* getItem(itm::ItemId id);
    private:
        static itm::ItemId erroneousItemId;
        static std::map<itm::ItemId, ItemDefinition*> registeredItems;
};

#endif // ITEMDICTIONARY_H
