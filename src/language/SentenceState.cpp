/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "Grammar.h"

gmr::SentenceState::SentenceState(std::vector<NounState*>* nounStates)
: nounStates(nounStates)
{
}
