/* Copyright (c) 2013 https://github.com/Naftoreiclag/
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "Grammar.h"

#include "Dictionary.h"

gmr::ModifierState::ModifierState()
: id(Dictionary::getErroneousModifierId())
{
}

gmr::ModifierState::ModifierState(ModifierId id)
: id(id)
{
}
