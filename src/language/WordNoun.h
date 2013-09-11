#ifndef WordNoun_H
#define WordNoun_H

#include <string>

class WordNoun
{
    public:
        static std::string generatePluralForm(std::string word);
        std::string getSingularForm();
        std::string getPluralForm();
        WordNoun(std::string singularForm);
        WordNoun(std::string singularForm, std::string pluralForm);
    protected:
    private:
        std::string singularForm;
        std::string pluralForm;
};

#endif // WordNoun_H
