#include "CmdLexicographer.h"

#include "CmdDictionary.h"

#include "Functionalities.h"

void CmdLexicographer::graph()
{
    // Add commands
    CmdDictionary::cmdByAlias->push_back(cmd::AliasFunctionalityPair("eat", Eat::execute));
    CmdDictionary::cmdByAlias->push_back(cmd::AliasFunctionalityPair("dance", Dance::execute));
    CmdDictionary::cmdByAlias->push_back(cmd::AliasFunctionalityPair("move", Move::execute));
    CmdDictionary::cmdByAlias->push_back(cmd::AliasFunctionalityPair("go", Move::execute));
    CmdDictionary::cmdByAlias->push_back(cmd::AliasFunctionalityPair("look", Look::execute));
    CmdDictionary::cmdByAlias->push_back(cmd::AliasFunctionalityPair("chop down", Lumberjack::execute));
    CmdDictionary::cmdByAlias->push_back(cmd::AliasFunctionalityPair("cut down", Lumberjack::execute));
    CmdDictionary::cmdByAlias->push_back(cmd::AliasFunctionalityPair("go", Do::execute));
    CmdDictionary::cmdByAlias->push_back(cmd::AliasFunctionalityPair("do", Do::execute));
    CmdDictionary::cmdByAlias->push_back(cmd::AliasFunctionalityPair("take", Take::execute));
}
