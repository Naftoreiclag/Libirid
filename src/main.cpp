#include <iostream>
#include <string>
#include <sstream>
#include <vector>

void getInput(std::vector<std::string>* v)
{
    // Clear out the vector
    v->clear();

    // Extract a buffer for the input
    std::string line;
    std::getline(std::cin, line);
    std::stringstream sBuffer(line);

    // Get words
    std::string word;
    while(sBuffer >> word)
    {
        v->push_back(word);
    }
}

void printVec(std::vector<std::string>* v)
{
    for(std::vector<std::string>::iterator it = v->begin(); it != v->end(); ++ it)
    {
        std::cout << *it << std::endl;
    }
}

int main()
{
    std::cout << "Fuzzy Computing Machine" << std::endl;

    bool running = true;

    std::vector<std::string>* v = new std::vector<std::string>();

    while(running)
    {
        std::cout << "Enter something:" << std::endl;
        getInput(v);
        std::cout << std::endl;
        std::cout << "You entered:" << std::endl;
        printVec(v);
        std::cout << std::endl;
    }

    return 0;
}
