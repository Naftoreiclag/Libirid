#include "Grammar.h"

#include <string>

#include "Dictionary.h"

std::string gmr::NounState::getUnmodifiedName()
{
    return plurality == gmr::plural ? Dictionary::getNoun(id)->getPluralForm() : Dictionary::getNoun(id)->getSingularForm();
}

// By default, the noun has an erroneous id, ambiguous plurality, and is definite
gmr::NounState::NounState()
: id(Dictionary::getErroneousNounId()), plurality(gmr::ambiguous), definity(gmr::definite)
{
    modifiers = new std::vector<gmr::ModifierId>();
}
