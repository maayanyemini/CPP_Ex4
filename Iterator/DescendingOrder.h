// Maayanyemini123@gmail.com

#ifndef DESCENDINGORDER_H
#define DESCENDINGORDER_H

#include <vector>
#include <algorithm>

namespace Container {

    template<typename T> class MyContainer;

    /**
     * @brief Iterator for traversing MyContainer in descending value order.
     * Iterates from the largest element to the smallest,
     * based on the actual values stored in the container.
     */
    template<typename T = int>
    class DescendingIterator {
    private:
        MyContainer<T>& container;      // the container being iterated
        size_t index;                        // Current position in the sorted index list
        std::vector<size_t> sorted_indices;  // Stores indices of container elements in descending order

        /**
         * @brief Builds the index list sorted by descending values.
         * Fills 'sorted_indices' with [0, 1, ..., n-1] and sorts it
         * such that elements with higher values come first.
         */
        void build_descending_order() {
            const size_t s = container.size();
            sorted_indices.resize(s);
            // Fill the index list: [0, 1, ..., s-1]
            for (size_t i = 0; i < s; ++i) {
                sorted_indices[i] = i;
            }
            // Sort indices based on the actual values in descending order
            std::sort(sorted_indices.begin(), sorted_indices.end(),
                      [&](size_t a, size_t b) {
                          return container.elements[a] > container.elements[b];
                      });
        }

    public:
        /**
         * @brief Constructor for DescendingIterator.
         * Creates an iterator for the given container, starting at the specified index.
         * @param cont Reference to the container to iterate.
         * @param start Starting index in the sorted_indices list (default is 0).
         */
        explicit DescendingIterator(MyContainer<T>& cont, size_t start = 0)
            : container(cont), index(start) {
            build_descending_order();
        }

        /**
         * @brief Dereference operator.
         * Provides read-only access to the current element in descending order.
         * @return Const reference to the element at the current position.
         * @throws std::out_of_range if the iterator is invalid.
         */
        const T& operator*() const {
            if (index >= sorted_indices.size()) {
                throw std::out_of_range("DescendingIterator: dereference out of range");
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
                throw std::out_of_range("DescendingIterator: dereference out of range");
            }
        return container.elements[sorted_indices[index]];
        
        }


        /**
         * @brief Pre-increment operator (++it).
         * Moves the iterator forward to the next element in descending order.
         * @return Reference to the incremented iterator.
         * @throws std::out_of_range if incrementing beyond the valid range.
         */
        DescendingIterator& operator++() {
            if (index >= sorted_indices.size()) {
                throw std::out_of_range("DescendingIterator increment out of range");
            }
            ++index;
            return *this;
        }

        /**
         * @brief Post-increment operator (it++).
         * Moves the iterator forward and returns its previous state.
         * @return A copy of the iterator before it was incremented.
         */
        DescendingIterator operator++(int) {
            DescendingIterator temp = *this;
            ++(*this);
            return temp;
        }

        /**
         * @brief Equality comparison.
         * Two iterators are equal if they refer to the same container and index.
         * @param other The iterator to compare with.
         * @return True if equal, false otherwise.
         */
        bool operator==(const DescendingIterator& other) const {
            return &container == &other.container && index == other.index;
        }

        /**
         * @brief Inequality comparison.
         * Checks whether two iterators differ in container or index.
         * @param other The iterator to compare with.
         * @return True if not equal, false otherwise.
         */
        bool operator!=(const DescendingIterator& other) const {
            return !(*this == other);
        }
    };

}

#endif // DESCENDINGORDER_H
