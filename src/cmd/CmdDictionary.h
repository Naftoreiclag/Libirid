/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef CMDDICTIONARY_H
#define CMDDICTIONARY_H

/* Singleton. This will hold all the scripts that can be accessed by user
 * inputs.
 */

#include <string>

class CmdDictionary
{
    private:
        CmdDictionary();
        virtual ~CmdDictionary();
    public:
        // Get the current singleton instance, creating one if it does not exist
        static CmdDictionary* getInstance();

        void loadCommand()
        void getCommand(std::string userInput);
    private:
        static CmdDictionary* instance;
};

#endif // CMDDICTIONARY_H
