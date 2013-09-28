#include "ItmLexicographer.h"

#include "ItmDictionary.h"
#include "ItemDefinition.h"

void ItmLexicographer::graph()
{
    ItemDefinition* stick = new ItemDefinition().addName();
    ItmDictionary::addItem(1, new ItemDefinition());
}
