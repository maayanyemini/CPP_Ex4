//Maayanyemini123@gmail.com 


#ifndef SIDECROSSORDER_H
#define SIDECROSSORDER_H

#include <vector>
#include <algorithm>
#include <stdexcept>

namespace Container {
    template<typename T> class MyContainer;

    /**
     * @brief Iterator that scans a MyContainer in side-cross order.
     * The iteration order alternates between the smallest and largest remaining elements.
     * For example, for the sorted container [1, 2, 3, 4, 5], the iteration order will be:
     * 1, 5, 2, 4, 3
     */

    template<typename T = int>
    class SideCrossIterator {
    private:
        MyContainer<T>& container; // the container being iterated
        size_t index;           // Current position
        std::vector<size_t> sideCross_indices; // Holds indices of elements in side-cross order

        /**
         * @brief Builds the vector of indices in side-cross order.
         * The method sorts the indices by the values they point to, 
         * then alternates between taking the smallest and the largest remaining elements.
         */
        void build_sideCross_order() {
        const size_t s = container.size();  // Get the total number of elements in the container
        std::vector<size_t> sorted_indices(s);  // Vector to store indices of the elements

        // Initialize sorted_indices with 0 to s-1
        for (size_t i = 0; i < s; ++i) {
            sorted_indices[i] = i;
        }

        // Sort indices based on the values of the corresponding elements in ascending order
        std::sort(sorted_indices.begin(), sorted_indices.end(),
            [&](size_t a, size_t b) {
            return container.elements[a] < container.elements[b];
        });

        sideCross_indices.clear();  // Clear any previous side-cross ordering
        if (sorted_indices.empty()) return;  // Edge case: empty container

        size_t left = 0;                       // Start pointer (smallest element)
        size_t right = sorted_indices.size() - 1;  // End pointer (largest element)

        // Build the side-cross pattern: smallest, largest, next smallest, next largest, etc.
        while (left <= right) {
        if (left == right) {
            sideCross_indices.push_back(sorted_indices[left]);  // Only one element left
        } else {
            sideCross_indices.push_back(sorted_indices[left]);   // Add smallest
            sideCross_indices.push_back(sorted_indices[right]);  // Add largest
        }
        left++;
        if (right == 0) break;  // Prevent underflow when right is 0
        right--;
        }
    }
    public:
        /**
         * @brief Constructs a SideCrossIterator for a given container.
         * @param cont Reference to the container.
         * @param start Starting index in the iteration order (default is 0).
         */
        explicit SideCrossIterator(MyContainer<T>& cont,size_t start = 0)
            : container(cont), index(start) {
            build_sideCross_order();
        }

        /**
         * @brief Dereference operator for reading the current element (const version).
         * @return A const reference to the current element.
         * @throws std::out_of_range if the iterator is out of bounds.
         */
        const T& operator*() const {
            if (index >= sideCross_indices.size()) {
                throw std::out_of_range("SideCrossIterator: Dereference past end");
            }
            return container.elements[sideCross_indices[index]];
        }

         /**
        * @brief Writable dereference operator.
        * Returns a non-const reference to the current element,
        * allowing the user to modify it through the iterator.
        * @return Reference to the current element.
        * @throws std::out_of_range if index exceeds bounds.
        */
        T& operator*() {
            if (index >= sideCross_indices.size()) {
                throw std::out_of_range("SideCrossIterator: dereference out of range");
            }
        return container.elements[sideCross_indices[index]];
        
        }

    
        /**
         * @brief Pre-increment operator (++it).
         * Advances the iterator to the next element.
         * @return Reference to the incremented iterator.
         */
        SideCrossIterator& operator++() {
            ++index;
            return *this;
        }

        /**
         * @brief Post-increment operator (it++).
         * @return Copy of the iterator before it was incremented.
         */
        SideCrossIterator operator++(int) {
            SideCrossIterator temp = *this;
            ++(*this);
            return temp;
        }

        /**
         * @brief Equality comparison operator.
         * @param other Iterator to compare with.
         * @return True if iterators are equal.
         */
        bool operator==(const SideCrossIterator& other) const {
            return &container == &other.container && index == other.index;
        }

        /**
         * @brief Inequality comparison operator.
         * @param other Iterator to compare with.
         * @return True if iterators are not equal.
         */
        bool operator!=(const SideCrossIterator& other) const {
            return !(*this == other);
        }
    };

}

#endif // SIDECROSSORDER_H
