#ifndef SYSOUT_H
#define SYSOUT_H

/* std::cout made generic!
 */

class Sysout
{
    // These remind me of my Java days... Horrible!
    // ...pleasing, but still HORRIBLE!!! I mean, no pointers!?
    // and don't even get me started on automatic garbage collection...
    // The Java libraries are amazing though.
    public:
        void print(std::string str)
        void println(std::string str)
        void println()
    protected:
    private:
        // Private, because we'll never instantiate this.
        Sysout();
};

#endif // SYSOUT_H
