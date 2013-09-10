#ifndef VECTORUTIL_H
#define VECTORUTIL_H

#include <vector>
#include <algorithm>

// THIS STUFF IS BROKEN DON'T USE IT
// And it is redundant.
// Just use std::vector<T> duplicate(original);

template <class T>
class VectorUtil
{
    public:
        // Returns a clone of the input vector
        static std::vector<T>* clone(std::vector<T>* original)
        {
            /*// The empty clone
            std::vector<T> duplicate;

            // Iterate from the beginning to the end
            for(typename std::vector<T>::iterator it = original->begin(); it != original->end(); ++ it)
            {
                // Add it to our clone
                duplicate.push_back(*it);
            }

            // Return
            return &duplicate;*/

            //std::vector<T> duplicate(*original);
            //return &duplicate;

            //std::vector<T> duped(*original);
            //std::vector<T>* duplicate = &duped;

            //std::copy(original->begin(), original->end(), duped);

            std::vector<T> duplicate(*original);

            return &duplicate;
        }

        // Returns a clone of the input vector, except with the first n entries shaved off
        static std::vector<T>* clone(std::vector<T>* original, unsigned int shave)
        {
            // The empty clone
            std::vector<T> duplicate;

            // If the shaving will make the vector bald
            if(shave >= original->size())
            {
                // Then skip the shaving and just make the clone bald
                return &duplicate;
            }

            // Iterate from the shaving point to the end
            typename std::vector<T>::iterator it = original->begin();
            it += shave; // Don't forget to shave!
            while(it != original->end())
            {
                // Add it to our clone
                duplicate.push_back(*it);

                // Count
                ++ it;
            }

            // Return
            return &duplicate;
        }
    protected:
    private:
        // Private, because we'll never instantiate this.
        VectorUtil() {}
};

#endif // VECTORUTIL_H
