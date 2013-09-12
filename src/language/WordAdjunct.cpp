#include "WordAdjunct.h"

#include <string>

#include "Grammar.h"

std::string WordAdjunct::getForm()
{
    return form;
}

WordAdjunct::WordAdjunct(std::string form, gmr::AdjunctType type)
: form(form),
type(type)
{
}
