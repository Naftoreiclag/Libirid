#include "ItmLexicographer.h"

#include "ItmDictionary.h"
#include "ItemDefinition.h"

#include "../../IdList.h"

void ItmLexicographer::graph()
{
    ItmDictionary::addItem(I_STICK, (new ItemDefinition())->addName(N_STICK));
}
