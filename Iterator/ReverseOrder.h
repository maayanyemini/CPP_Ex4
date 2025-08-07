//Maayanyemini123@gmail.com 


#ifndef REVERSEORDER_H
#define REVERSEORDER_H

#include <vector>
#include <stdexcept>

namespace Container {
    template<typename T> class MyContainer;

    /**
     * @brief Iterator that scans a MyContainer in reverse order.
     * The iteration goes from the last inserted element to the first.
     * For example, if the elements are [10, 20, 30], the iteration order will be 30, 20, 10.
     */
    template<typename T = int>
    class ReverseIterator {
    private:
        MyContainer<T>& container; // the container being iterated
        size_t index;                   // Current position
        std::vector<size_t> reverse_indices; // Holds indices of elements in reverse order

        /**
         * @brief Builds the vector of indices in reverse order.
         * This function fills the reverse_indices vector with indices from
         * the last to the first (i.e., size-1 down to 0).
         */
        void build_reverse_order() {
            const size_t s = container.size();
            reverse_indices.resize(s);
            for (size_t i = 0; i < s; ++i) {
                reverse_indices[i] = s - 1 - i; // Fill with indices from last to first
            }
        }

    public:
        /**
         * @brief Constructs a ReverseIterator for a given container.
         * @param cont Reference to the container to iterate
         * @param start Initial index (default is 0, which means start from the last element)
         */
        explicit ReverseIterator(MyContainer<T>& cont, size_t start = 0)
            : container(cont), index(start) {
            build_reverse_order();
        }

        /**
         * @brief Dereference operator (const version).
         * @return Const reference to the current element.
         * @throws std::out_of_range if index is out of bounds.
         */
        const T& operator*() const {
            if (index >= reverse_indices.size()) {
                throw std::out_of_range("ReverseIterator: Dereferencing out of bounds");
            }
            return container.elements[reverse_indices[index]];
        }

        /**
        * @brief Writable dereference operator.
        * Returns a non-const reference to the current element,
        * allowing the user to modify it through the iterator.
        * @return Reference to the current element.
        * @throws std::out_of_range if index exceeds bounds.
        */
        T& operator*() {
            if (index >= reverse_indices.size()) {
                throw std::out_of_range("ReverseIterator: dereference out of range");
            }
        return container.elements[reverse_indices[index]];
        
        }

        /**
         * @brief Pre-increment operator.
         * @return Reference to the incremented iterator.
         */
        ReverseIterator& operator++() {
            ++index;
            return *this;
        }

        /**
         * @brief Post-increment operator.
         * @return Copy of the iterator before incrementing.
         */
        ReverseIterator operator++(int) {
            ReverseIterator temp = *this;
            ++(*this);
            return temp;
        }

        /**
         * @brief Equality comparison operator
         * @param other Iterator to compare to.
         * @return True if both iterators point to the same container and index.
         */
        bool operator==(const ReverseIterator& other) const {
            return &container == &other.container && index == other.index;
        }

        /**
         * @brief Inequality comparison operator.
         * @param other Iterator to compare to.
         * @return True if iterators are not equal.
         */
        bool operator!=(const ReverseIterator& other) const {
            return !(*this == other);
        }
    };

}

#endif // REVERSEORDER_H
