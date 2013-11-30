/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "AdjunctDefinition.h"

#include <string>

#include "Grammar.h"

std::string AdjunctDefinition::getForm()
{
    return form;
}

AdjunctDefinition::AdjunctDefinition(std::string form, gmr::AdjunctType type)
: form(form),
type(type)
{
}
