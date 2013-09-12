#include "WordNoun.h"

std::string WordNoun::generatePluralForm(std::string word)
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

    // If it ends in "y"
    if(word.at(word.size() - 1) == 'y')
    {
        // Drop the "y" and add "ies"
        return word.substr(0, word.size() - 1) + "ies";
    }

    // Just add "s"
    return word + "s";
}

std::string WordNoun::getSingularForm()
{
    return singularForm;
}

std::string WordNoun::getPluralForm()
{
    return pluralForm;
}

WordNoun::WordNoun(std::string singularForm)
: singularForm(singularForm)
{
    pluralForm = generatePluralForm(singularForm);
}

WordNoun::WordNoun(std::string singularForm, std::string pluralForm)
: singularForm(singularForm),
pluralForm(pluralForm)
{
}
