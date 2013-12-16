/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef SCRIPT_H
#define SCRIPT_H

namespace script
{
    class Script
    {
        protected:
            Script();
        public:
            virtual ~Script();
        public:
            virtual void execute() = 0;
    };
}

#endif // SCRIPT_H
