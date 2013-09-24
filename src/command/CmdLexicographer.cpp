#include "CmdLexicographer.h"

#include "CmdDictionary.h"

#include "Functionalities.h"

void CmdLexicographer::graph()
{
    // Add commands
    CmdDictionary::cmdByAlias->push_back(fcmd::AliasFunctionalityPair("eat", Eat::execute));
    CmdDictionary::cmdByAlias->push_back(fcmd::AliasFunctionalityPair("dance", Dance::execute));
    CmdDictionary::cmdByAlias->push_back(fcmd::AliasFunctionalityPair("move", Move::execute));
    CmdDictionary::cmdByAlias->push_back(fcmd::AliasFunctionalityPair("go", Move::execute));
    CmdDictionary::cmdByAlias->push_back(fcmd::AliasFunctionalityPair("look", Look::execute));
    CmdDictionary::cmdByAlias->push_back(fcmd::AliasFunctionalityPair("chop down", Lumberjack::execute));
    CmdDictionary::cmdByAlias->push_back(fcmd::AliasFunctionalityPair("cut down", Lumberjack::execute));
    CmdDictionary::cmdByAlias->push_back(fcmd::AliasFunctionalityPair("go", Do::execute));
    CmdDictionary::cmdByAlias->push_back(fcmd::AliasFunctionalityPair("do", Do::execute));
    CmdDictionary::cmdByAlias->push_back(fcmd::AliasFunctionalityPair("take", Take::execute));
}
