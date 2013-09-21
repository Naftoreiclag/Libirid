#ifndef SYSOUT_H
#define SYSOUT_H

#include <string>
#include <vector>

#include "../language/Grammar.h"

#include "../util/Rotcev.h"
#include "../util/Point3i.h"

/* std::cout made generic!
 */

class Sysout
{
    public:
        static void setDisplayWidth(unsigned short displayWidth);
        static std::string wordWrappify(std::string paragraph);
        static void printDictionaryEntries();
        static std::string toFriendlyString(gmr::WordType wordType);
        static std::string toFriendlyString(std::vector<std::string>* wordList);
        static std::string toFriendlyString(gmr::Plurality plurality);
        static std::string toFriendlyString(gmr::ArticleType definity);
        static std::string toFriendlyString(gmr::NounState* nounState);
        static std::string toFriendlyString(gmr::SentenceState* stncState);
        static std::string toFriendlyString(Rotcev3i* r);
        static std::string toFriendlyString(Point3i p);
        static std::string toString(int i);
        static void printSlow(std::string str);
        static void print(std::string str);
        static void d_print(std::string str);
        static void print(int i);
        static void println(std::string str);
        static void d_println(std::string str);
        static void println(int i);
        static void println();
        static void d_println();

        // Deprecated functions
        static void print(std::vector<std::string>* wordList);
        static void println(std::vector<std::string>* wordList);
    private:
        //
        static unsigned short displayWidth;
};

#endif // SYSOUT_H
