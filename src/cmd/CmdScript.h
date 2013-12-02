#ifndef CMDSCRIPT_H
#define CMDSCRIPT_H

#include "CmdStuff.h"

namespace cmd
{
    class CmdScript
    {
        protected:
            CmdScript(ScriptType::T type);
        public:
            void execute();
        private:
            ScriptType::T type;
    };
}

#endif // CMDSCRIPT_H
