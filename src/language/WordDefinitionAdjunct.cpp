#include "WordDefinitionAdjunct.h"

#include <string>

#include "Grammar.h"

std::string WordDefinitionAdjunct::getForm()
{
    return form;
}

WordDefinitionAdjunct::WordDefinitionAdjunct(std::string form, gmr::AdjunctType type)
: form(form),
type(type)
{
}
