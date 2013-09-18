#include "CmdLexicographer.h"

#include "CmdDictionary.h"

#include "CommandDance.h"
#include "CommandEat.h"

void CmdLexicographer::graph()
{
    // Add commands
    CmdDictionary::cmdByAlias->append("eat", new CommandEat());
    CmdDictionary::cmdByAlias->append("dance", new CommandDance());
}
