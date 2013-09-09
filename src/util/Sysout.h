#ifndef SYSOUT_H
#define SYSOUT_H

#include <string>

/* Just some auxiliary functions for std::cout.
 * That way, I'll have a generic way to output stuff to the screen.
 */

class Sysout
{
    public:
        static void print(std::string str);
        static void println(std::string str);
        static void println();
    protected:
    private:
        // Never need to instantiate this
        Sysout() {}
};

#endif // SYSOUT_H
