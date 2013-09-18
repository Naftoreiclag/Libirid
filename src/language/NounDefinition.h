#ifndef NOUNDEFINITION_H
#define NOUNDEFINITION_H

#include <string>

/* A noun. Just the word of it. No meaning or anything.
 * Keeps separate plural and singular forms.
 */

class NounDefinition
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
        NounDefinition(std::string singularForm);

        // Make a word and specify the plural form
        NounDefinition(std::string singularForm, std::string pluralForm);
    private:
        // Forms
        std::string singularForm;
        std::string pluralForm;
};

#endif // NounDefinition_H
