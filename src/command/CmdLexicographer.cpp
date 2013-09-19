#include "CmdLexicographer.h"

#include "CmdDictionary.h"

#include "CommandDance.h"
#include "CommandEat.h"

void CmdLexicographer::graph()
{
    // Add commands
    CmdDictionary::cmdByAlias->append("eat", CommandEat::execute);
    CmdDictionary::cmdByAlias->append("dance", CommandDance::execute);
}
