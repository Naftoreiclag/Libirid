#ifndef SYSOUT_H
#define SYSOUT_H

#include <string>
#include <vector>

/* std::cout made generic!
 */

class Sysout
{
    // These remind me of my Java days... Horrible!
    // ...pleasing, but still HORRIBLE!!! I mean, no pointers!?
    // and don't even get me started on automatic garbage collection...
    // The Java libraries are amazing though.
    public:
        static std::string toFriendlyString(std::vector<std::string>* wordList);
        static void print(std::string str);
        static void print(std::vector<std::string>* wordList);
        static void println(std::string str);
        static void println(std::vector<std::string>* wordList);
        static void println();
    protected:
    private:
        // Private, because we'll never instantiate this.
        Sysout();
};

#endif // SYSOUT_H