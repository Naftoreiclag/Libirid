#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

int main()
{
    std::cout << "Enter a name for the new command classes:" << std::endl;
    std::cout << " Example:" << std::endl;
    std::cout << "    Entering Foo will make classes CommandFoo.cpp and CommandFoo.h in src/command/" << std::endl;
    std::cout << "    Entering Bar will make classes CommandBar.cpp and CommandBar.h in src/command/" << std::endl;
    std::string name;
    std::cin >> name;

    std::string qut = "\"";

    std::ofstream seep;
    std::string consp = "..\\src\\command\\Command" + name + ".cpp";
    seep.open(consp.c_str());
    seep << "#include " + qut + "Command" + name + ".h" + qut + "\n";
    seep << "\n";
    seep << "#include " + qut + "../language/Grammar.h" + qut + "\n";
    seep << "\n";
    seep << "#include " + qut + "../util/Sysout.h" + qut + "\n";
    seep << "\n";
    seep << "bool Command" + name + "::execute(gmr::SentenceState* stnc)\n";
    seep << "{\n";
    seep << "    Sysout::println(" + qut + "autogen!" + qut + ");\n";
    seep << "\n";
    seep << "    return true;\n";
    seep << "}\n";
    seep << "\n";
    seep << "Command" + name + "::Command" + name + "()\n";
    seep << "{\n";
    seep << "}\n";
    seep.close();

    std::string uppercaseName = name;
    std::transform(uppercaseName.begin(), uppercaseName.end(), uppercaseName.begin(), ::toupper);

    std::ofstream aych;
    std::string conah = "..\\src\\command\\Command" + name + ".h";
    aych.open(conah.c_str());
    aych << "#ifndef COMMAND" + uppercaseName + "_H\n";
    aych << "#define COMMAND" + uppercaseName + "_H\n";
    aych << "\n";
    aych << "#include " + qut + "Command.h" + qut + "\n";
    aych << "\n";
    aych << "#include " + qut + "../language/Grammar.h" + qut + "\n";
    aych << "\n";
    aych << "class Command" + name + ": public Command\n";
    aych << "{\n";
    aych << "    public:\n";
    aych << "        bool execute(gmr::SentenceState* stnc);\n";
    aych << "        Command" + name + "();\n";
    aych << "    protected:\n";
    aych << "    private:\n";
    aych << "};\n";
    aych << "\n";
    aych << "#endif // COMMAND" + uppercaseName + "_H\n";
    aych.close();

    return 0;
}
