#include "ItmLexicographer.h"

#include "ItmDictionary.h"
#include "ItemDefinition.h"

void ItmLexicographer::graph()
{
    ItemDefinition* stick = (new ItemDefinition())->addName(2);
    ItmDictionary::addItem(1, new ItemDefinition());
}
