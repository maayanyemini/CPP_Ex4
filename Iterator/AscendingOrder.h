// Maayanyemini123@gmail.com

#ifndef ASCENDINGORDER_H
#define ASCENDINGORDER_H

#include <vector>
#include <algorithm>

namespace Container {

    template<typename T>
    class MyContainer;

    /**
     * @brief Iterator for iterating over a MyContainer in ascending order.
     * The iteration traverses the container's elements from the smallest value to the largest value,
     * regardless of the original insertion order.
     */
    template<typename T = int>
    class AscendingIterator {
    private:
        MyContainer<T>& container;     // the container being iterated
        size_t index;                        // Current position in sorted order
        std::vector<size_t> sorted_indices;  // Holds indices of elements sorted by value

        /**
         * @brief Builds the sorted index list for ascending order traversal.
         * Initializes 'sorted_indices' with sequential indices [0, 1, ..., n-1],
         * sorts them based on the values in 'container.elements'.
         */
        void build_ascending_order() {
            const size_t s = container.size();
            sorted_indices.resize(s);

            // Fill the index list: [0, 1, ..., s-1]
            for (size_t i = 0; i < s; ++i) {
                sorted_indices[i] = i;
            }

            // Sort indices based on the actual values in the container
            std::sort(sorted_indices.begin(), sorted_indices.end(),
                      [&](size_t a, size_t b) {
                          return container.elements[a] < container.elements[b];
                      });
        }

    public:

        /**
         * @brief Constructor.
         * Initializes the iterator at the specified starting position
         * (usually 0 for begin or container.size() for end).
         * @param cont The container to iterate.
         * @param start The starting index in the sorted list.
         */
        explicit AscendingIterator(MyContainer<T>& cont, size_t start = 0)
            : container(cont), index(start) {
            build_ascending_order();
        }

        /**
         * @brief Dereference operator.
         * Returns the current element in the sorted traversal.
         * @return Reference to the current element.
         * @throws std::out_of_range if index exceeds bounds.
         */
        const T& operator*() const {
            if (index >= sorted_indices.size()) {
                throw std::out_of_range("AscendingIterator: dereference out of range");
            }
            return container.elements[sorted_indices[index]];
        }

        /**
        * @brief Writable dereference operator.
        * Returns a non-const reference to the current element,
        * allowing the user to modify it through the iterator.
        * @return Reference to the current element.
        * @throws std::out_of_range if index exceeds bounds.
        */
        T& operator*() {
            if (index >= sorted_indices.size()) {
                throw std::out_of_range("AscendingIterator: dereference out of range");
            }
            return container.elements[sorted_indices[index]];
        }

    
        /**
         * @brief Pre-increment operator (++it).
         * Advances the iterator to the next element in ascending order.
         * @return Reference to the incremented iterator.
         * @throws std::out_of_range if incrementing past the end.
         */
        AscendingIterator& operator++() {
            if (index >= sorted_indices.size()) {
                throw std::out_of_range("AscendingIterator: increment past end");
            }
            ++index;
            return *this; // return the incremented iterator- pre-increment
        }

        /**
         * @brief Post-increment operator (it++).
         * Returns a copy of the iterator before incrementing.
         * Useful when old state is needed before advancing.
         */
        AscendingIterator operator++(int) {
            AscendingIterator temp = *this;
            ++(*this);
            return temp; // return the old state - post-increment
        }

        /**
         * @brief Equality comparison.
         * Two iterators are equal if they refer to the same container and same position.
         */
        bool operator==(const AscendingIterator& other) const {
            return &container == &other.container && index == other.index;
        }

        /**
         * @brief Inequality comparison.
         */
        bool operator!=(const AscendingIterator& other) const {
            return !(*this == other);
        }
    };
}

#endif // ASCENDINGORDER_H
