/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef SYSIN_H
#define SYSIN_H

#include <string>
#include <vector>

/* std::cin stuff
 */

class Sysin
{
    public:
        // Split the words into a vector
        static void splitWords(std::string rawInput, std::vector<std::string>* wordContainer);
        //static std::vector<std::string>* splitWords(std::string rawInput);

        // Pauses program and gets the stuff typed in and puts each word int wordList
        static void getWords(std::vector<std::string>* wordList);

        // Pauses program and gets the stuff typed in and puts each word int wordList in lowercase
        static void getWordsLowercase(std::vector<std::string>* wordList);
};

#endif // SYSIN_H