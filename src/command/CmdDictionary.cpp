#include "CmdDictionary.h"

#include <string>

#include "../util/SequencedMap.h"

SequencedMap<std::string, fcmd::Functionality>* CmdDictionary::cmdByAlias = new SequencedMap<std::string, fcmd::Functionality>();
