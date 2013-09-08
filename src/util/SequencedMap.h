#ifndef SEQUENCEDMAP_H
#define SEQUENCEDMAP_H

#include <vector>
#include <map>

template <class K, class V>
class SequencedMap
{
    public:
        void append(K key, V val)
        {
            lookupTable.insert(std::pair<K, V>(key, val));
            insertionOrder.push_back(key);
        }
        size_t size()
        {
            return insertionOrder.size();
        }
        V at(unsigned int location)
        {
            K key = insertionOrder[location];

            return lookupTable.find(key)->second;
        }
        SequencedMap() {}
    private:
        std::vector<K> insertionOrder;
        std::map<K, V> lookupTable;
};

#endif // SEQUENCEDMAP_H
