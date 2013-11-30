/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

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
