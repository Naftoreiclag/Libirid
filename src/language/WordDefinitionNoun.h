#ifndef WORDDEFINITIONNOUN_H
#define WORDDEFINITIONNOUN_H

#include <string>

/* A noun. Just the word of it. No meaning or anything.
 * Keeps separate plural and singular forms.
 */

class WordDefinitionNoun
{
    public:
        // Auto-generates a plural form (tacks an "s" at the end)
        static std::string generatePluralForm(std::string word);

        // Gets forms
        std::string getSingularForm();
        std::string getPluralForm();

        //
        bool hasAmbiguousPlurality();

        // Make a word and auto-generate the plural form.
        WordDefinitionNoun(std::string singularForm);

        // Make a word and specify the plural form
        WordDefinitionNoun(std::string singularForm, std::string pluralForm);
    protected:
    private:
        // Forms
        std::string singularForm;
        std::string pluralForm;
};

#endif // WordDefinitionNoun_H
