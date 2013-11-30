/* Copyright (c) 2013 https://github.com/Naftoreiclag/
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef INANEMAP_H
#define INANEMAP_H

/* This is supposed to function like a map, except it also
 * "indexes" the keys by the order they were added, and
 */

// Don't use this. It is just like a vector.
// I'll keep it here though just in case I need to make
// an even unsmarter implementation of a map than SequencedMap

template <class K, class V>
class InaneMap
{
    public:
        InaneMap() {}
        virtual ~InaneMap() {}
    protected:
    private:
};

#endif // INANEMAP_H
