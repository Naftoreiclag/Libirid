#include "WordNoun.h"

// Make this better. Does not work for "bus"
std::string WordNoun::generatePluralForm(std::string word)
{
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
