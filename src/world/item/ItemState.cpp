#include "ItemState.h"

#include "ItemDefinition.h"

ItemState::ItemState(itm::ItemDefId definitionId)
: definition(definitionId)
{
}

ItemState::~ItemState()
{
    //dtor
}
