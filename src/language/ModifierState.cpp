#include "Grammar.h"

#include "Dictionary.h"

gmr::ModifierState::ModifierState()
: id(Dictionary::getErroneousModifierId())
{
}

gmr::ModifierState::ModifierState(ModifierId id)
: id(id)
{
}
