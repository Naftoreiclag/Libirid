/* Copyright (c) 2013 https://github.com/Naftoreiclag/
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef CMDDICTIONARY_H
#define CMDDICTIONARY_H

#include <string>

class CmdDictionary
{
    public:
        void getCommand(std::string userInput);

        CmdDictionary();
        virtual ~CmdDictionary();
    protected:
    private:
};

#endif // CMDDICTIONARY_H
