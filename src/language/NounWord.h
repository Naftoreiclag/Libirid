#ifndef NOUNWORD_H
#define NOUNWORD_H

#include <string>

class NounWord
{
    public:
        static std::string generatePluralForm(std::string word);
        std::string getSingularForm();
        std::string getPluralForm();
        NounWord(std::string singularForm);
        NounWord(std::string singularForm, std::string pluralForm);
    protected:
    private:
        std::string singularForm;
        std::string pluralForm;
};

#endif // NOUNWORD_H
