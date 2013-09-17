#include "CmdDictionary.h"

#include <string>
#include "../util/SequencedMap.h"

SequencedMap<std::string, Command*>* CmdDictionary::cmdByAlias = new SequencedMap<std::string, Command*>();

CmdDictionary::CmdDictionary()
{
    //ctor
}

CmdDictionary::~CmdDictionary()
{
    //dtor
}
