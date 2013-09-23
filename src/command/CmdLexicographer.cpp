#include "CmdLexicographer.h"

#include "CmdDictionary.h"

#include "Functionalities.h"

void CmdLexicographer::graph()
{
    // Add commands
    CmdDictionary::cmdByAlias->append("eat", Eat::execute);
    CmdDictionary::cmdByAlias->append("dance", Dance::execute);
    CmdDictionary::cmdByAlias->append("move", Move::execute);
    CmdDictionary::cmdByAlias->append("go", Move::execute);
    CmdDictionary::cmdByAlias->append("look", Look::execute);
    CmdDictionary::cmdByAlias->append("chop down", Lumberjack::execute);
    CmdDictionary::cmdByAlias->append("cut down", Lumberjack::execute);
    CmdDictionary::cmdByAlias->append("do", Do::execute);
    CmdDictionary::cmdByAlias->append("take", Take::execute);
}
