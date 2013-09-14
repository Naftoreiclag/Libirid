#include "AdjunctDefinition.h"

#include <string>

#include "Grammar.h"

std::string AdjunctDefinition::getForm()
{
    return form;
}

AdjunctDefinition::AdjunctDefinition(std::string form, gmr::AdjunctType type)
: form(form),
type(type)
{
}
