#ifndef SEQUENCEDMAP_H
#define SEQUENCEDMAP_H

#include <vector>
#include <map>

/* This is supposed to function like a map, except it also
 * "indexes" the keys by the order they were added.
 */

/* Note: I'm putting everything in the header file, since
 *       that is the STL for C++. If I put it in a definition
 *       file, then I'd have to explicitly state EVERY
 *       type I plan on using. The only downside to putting
 *       everything in the header is the compile time.
 */

template <class K, class V>
class SequencedMap
{
    public:
        // Adds a key-value at the end of the list
        void append(K key, V val)
        {
            lookupTable.insert(std::pair<K, V>(key, val));
            insertionOrder.push_back(key);
        }

        // The number of keys in the map
        std::size_t size()
        {
            return insertionOrder.size();
        }

        // Gets the value of a key
        V get(K key)
        {
            return lookupTable.find(key)->second;
        }

        // Gets the first value of a key at a location
        K first(unsigned int location)
        {
            return insertionOrder.at(location);
        }

        // Gets the second value of a key at a location
        V second(unsigned int location)
        {
            return lookupTable.find(insertionOrder.at(location))->second;
        }

        //
        SequencedMap() {}
    private:
        // Keeps track of the order the keys were added
        std::vector<K> insertionOrder;

        // Key-values
        std::map<K, V> lookupTable;
};

#endif // SEQUENCEDMAP_H
