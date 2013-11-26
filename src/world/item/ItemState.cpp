#include "ItemState.h"

#include "ItemDefinition.h"

#include "ItmDictionary.h"

ItemState::ItemState(itm::ItemDefId definitionId)
: definition(definitionId)
{
}

ItemDefinition* ItemState::accessDefinition()
{
    return ItmDictionary::getItem(definition);
}

ItemState::~ItemState()
{
    //dtor
}
