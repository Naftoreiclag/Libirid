/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef LISTOFSCRIPTS_H
#define LISTOFSCRIPTS_H

class ListOfScripts
{
    /////////////////////////////////
    // Singleton Pattern
    /////////////////////////////////

    private:
        // Constructor; private so we can have singletons FTW
        ListOfScripts();
    public:
        // Singleton instance
        static ListOfScripts* getInstance();

        // Destructor
        ~ListOfScripts();
    private:
        // Singleton instance
        static ListOfScripts* instance;

    /////////////////////////////////
    // Functionality
    /////////////////////////////////

    public:
        //

};

#endif // LISTOFSCRIPTS_H
