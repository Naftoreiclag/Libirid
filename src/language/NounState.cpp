#include "Grammar.h"
#include "Dictionary.h"

gmr::NounState::NounState()
: id(Dictionary::getErroneousNounId()), plurality(ambiguous)
{
}

gmr::NounState::NounState(NounId id, Plurality plurality)
: id(id), plurality(plurality)
{
}
