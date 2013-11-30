/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef SYSOUT_H
#define SYSOUT_H

#include "../language/Grammar.h"

#include "../util/Point3i.h"

class string;
class vector;

/* std::cout made generic!
 */

class Sysout
{
    public:
        // How wide the screen is
        static void setDisplayWidth(unsigned short displayWidth);

        // Adds newlines to a string to accommodate to screen width
        static std::string wordWrappify(std::string paragraph);

        // Print out all the dictionary entries
        #ifdef DEBUG
        static void printDictionaryEntries();
        #endif

        // Makes stuff readable by a human
        static std::string toFriendlyString(gmr::WordType wordType); // Word type
        static std::string toFriendlyString(gmr::Plurality plurality); // Plurality
        static std::string toFriendlyString(gmr::Definity definity); // Article Type
        static std::string toFriendlyString(gmr::NounState* nounState); // Noun State
        static std::string toFriendlyString(std::vector<std::string>* wordList); // Word List
        static std::string toFriendlyString(gmr::SentenceState* stncState); // Sentence State
        static std::string toFriendlyString(Point3i p); // Point3i

        // X to String
        static std::string toString(int i); // Integer

        // Print an integer
        static void print(int i);
        static void println(int i); // Line

        // Print a string
        static void print(std::string str);
        static void println(std::string str); // Line
        static void printSlow(std::string str); // Slowly

        // Print a line
        static void println();
    private:
        // How wide the screen is
        static unsigned short displayWidth;
};

#endif // SYSOUT_H
