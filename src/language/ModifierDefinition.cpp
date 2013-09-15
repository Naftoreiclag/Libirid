#include "ModifierDefinition.h"

#include <string>

std::string ModifierDefinition::getForm()
{
    return form;
}

ModifierDefinition::ModifierDefinition(std::string form)
: form(form)
{
}
