#include "ScriptLibrary.h"

#include <iostream>
#include <fstream>

ScriptLibrary::ScriptLibrary()
{
}

ScriptLibrary* ScriptLibrary::instance;
ScriptLibrary* ScriptLibrary::getInstance()
{
    if(instance == NULL)
    {
        instance = new ScriptLibrary();
    }

    return instance;
}

ScriptLibrary::~ScriptLibrary()
{
}

std::string* ScriptLibrary::loadLua(std::string path)
{
    // Create a new file stream
    std::ifstream fileStream;

    // Open file with mode "input"
    fileStream.open(path.c_str(), std::ios::in);

    // Tell the file stream to go to the end
    fileStream.seekg(0, fileStream.end);
    int length = fileStream.tellg();
    fileStream.seekg(0, fileStream.beg);

    //
    char* buffer = new char[length];

    // Write everything from beginning to end to the string
    fileStream.read(buffer, length);

    // Close the file
    fileStream.close();

    std::cout << buffer;
}
