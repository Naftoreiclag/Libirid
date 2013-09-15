#include "Grammar.h"

#include "Dictionary.h"

// By default, the noun has an erroneous id, ambiguous plurality, and is definite
gmr::NounState::NounState()
: id(Dictionary::getErroneousNounId()), plurality(ambiguous), definity(gmr::definite)
{
    modifiers = new std::vector<gmr::ModifierId>();
}
