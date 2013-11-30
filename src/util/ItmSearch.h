/* Copyright (c) 2013 https://github.com/Naftoreiclag/
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef ITMSEARCH_H
#define ITMSEARCH_H

#include "../language/Grammar.h"

#include <vector>

class ItemState;
class Room;

class ItmSearch
{
    public:
        static std::vector<ItemState> search(Room* room, gmr::NounState* nounState);
};

#endif // ITMSEARCH_H
