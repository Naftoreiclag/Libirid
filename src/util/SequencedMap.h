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
        K first(unsigned int location)
        {
            return insertionOrder.at(location);
        }
        V second(unsigned int location)
        {
            return lookupTable.find(insertionOrder.at(location))->second;
        }
        SequencedMap() {}
    private:
        std::vector<K> insertionOrder;
        std::map<K, V> lookupTable;
};

#endif // SEQUENCEDMAP_H
