#ifndef SYSIN_H
#define SYSIN_H

#include <string>
#include <vector>

/* std::cin stuff
 */

class Sysin
{
    public:
        // Pauses program and gets the stuff typed in and puts each word int wordList
        static void getWords(std::vector<std::string>* wordList);
    protected:
    private:
        // Private, because we'll never instantiate this.
        Sysin();
};

#endif // SYSIN_H
