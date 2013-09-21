#include "CmdLexicographer.h"

#include "CmdDictionary.h"

#include "Functionalities.h"

void CmdLexicographer::graph()
{
    // Add commands
    CmdDictionary::cmdByAlias->append("eat", Eat::execute);
    CmdDictionary::cmdByAlias->append("dance", Dance::execute);
    CmdDictionary::cmdByAlias->append("move", Move::execute);
    CmdDictionary::cmdByAlias->append("look", Look::execute);
}
