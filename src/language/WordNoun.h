#ifndef WordNoun_H
#define WordNoun_H

#include <string>

/* A noun. Just the word of it. No meaning or anything.
 * Keeps separate plural and singular forms.
 */

class WordNoun
{
    public:
        // Auto-generates a plural form (tacks an "s" at the end)
        static std::string generatePluralForm(std::string word);

        // Gets forms
        std::string getSingularForm();
        std::string getPluralForm();

        // Make a word and auto-generate the plural form.
        WordNoun(std::string singularForm);

        // Make a word and specify the plural form
        WordNoun(std::string singularForm, std::string pluralForm);
    protected:
    private:
        // Forms
        std::string singularForm;
        std::string pluralForm;
};

#endif // WordNoun_H
