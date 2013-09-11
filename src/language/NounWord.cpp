#include "NounWord.h"

// Make this better. Does not work for "bus"
std::string NounWord::generatePluralForm(std::string word)
{
    return word + "s";
}

std::string NounWord::getSingularForm()
{
    return singularForm;
}

std::string NounWord::getPluralForm()
{
    return pluralForm;
}

NounWord::NounWord(std::string singularForm)
: singularForm(singularForm)
{
    pluralForm = generatePluralForm(singularForm);
}

NounWord::NounWord(std::string singularForm, std::string pluralForm)
: singularForm(singularForm),
pluralForm(pluralForm)
{
}
