#include "CmdDictionary.h"

#include "../util/SequencedMap.h"

class string;

SequencedMap<std::string, fcmd::Functionality>* CmdDictionary::cmdByAlias = new SequencedMap<std::string, fcmd::Functionality>();
