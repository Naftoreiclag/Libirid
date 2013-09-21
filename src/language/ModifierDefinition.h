#ifndef MODIFIERDEFINITION_H
#define MODIFIERDEFINITION_H

#include <string>

class ModifierDefinition
{
    public:
        std::string getForm();
        ModifierDefinition(std::string form);
    private:
        std::string form;
};

#endif // WORDMODIFIER_H
