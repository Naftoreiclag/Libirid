/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "NounDefinition.h"

std::string NounDefinition::generatePluralForm(std::string word)
{
    // If it ends in "s"
    if(word.at(word.size() - 1) == 's')
    {
        // Add "es"
        return word + "es";
    }

    // If it ends in "o"
    if(word.at(word.size() - 1) == 'o')
    {
        // Add "es"
        return word + "es";
    }

    // If it ends in "z"
    if(word.at(word.size() - 1) == 'z')
    {
        // Add "es"
        return word + "es";
    }

    // If it ends in "x"
    if(word.at(word.size() - 1) == 'x')
    {
        // Add "es"
        return word + "es";
    }

    // If it ends in "sh"
    if(word.substr(word.size() - 2, 2) == "sh")
    {
        // Add "es"
        return word + "es";
    }

    // If it ends in "ch"
    if(word.substr(word.size() - 2, 2) == "ch")
    {
        // Add "es"
        return word + "es";
    }

    // If it ends in "y"
    if(word.at(word.size() - 1) == 'y')
    {
        // Drop the "y" and add "ies"
        return word.substr(0, word.size() - 1) + "ies";
    }

    // Just add "s"
    return word + "s";
}

std::string NounDefinition::getSingularForm()
{
    return singularForm;
}

std::string NounDefinition::getPluralForm()
{
    return pluralForm;
}

bool NounDefinition::hasAmbiguousPlurality()
{
    return singularForm == pluralForm;
}

NounDefinition::NounDefinition(std::string singularForm)
: singularForm(singularForm)
{
    pluralForm = generatePluralForm(singularForm);
}

NounDefinition::NounDefinition(std::string singularForm, std::string pluralForm)
: singularForm(singularForm),
pluralForm(pluralForm)
{
}
