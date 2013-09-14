#ifndef ADJUNCTDEFINITION_H
#define ADJUNCTDEFINITION_H

#include <string>

#include "Grammar.h"

/* Adjuncts. Class-structure-wise, kind of a mix between nouns and
 * articles. Not diverse enough to have unlisted types, but contextual
 * enough to be its own class.
 */

class AdjunctDefinition
{
    public:
        std::string getForm();
        AdjunctDefinition(std::string form, gmr::AdjunctType type);
    protected:
    private:
        //
        std::string form;
        gmr::AdjunctType type;
};

#endif // WORDADJUNCT_H
