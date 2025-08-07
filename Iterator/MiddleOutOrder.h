//Maayanyemini123@gmail.com 


#ifndef MIDDLEOUTORDER_H
#define MIDDLEOUTORDER_H

#include <vector>


namespace Container {
    template<typename T> class MyContainer;

    /**
     * @brief Iterator that scans a MyContainer in middle-out order.
     * Starts from the middle element, then alternates left and right.
     * For even-sized containers, the middle index is rounded down.
     * Example: For [7,15,6,1,2], the iteration order is 6,15,1,7,2.
     */
    template<typename T = int>
    class MiddleOutIterator {
    private:
        MyContainer<T>& container; // the container being iterated
        size_t index;               // Current position in the middle-out order
        std::vector<size_t> middleOut_indices; // Holds indices of elements in middle-out order

        /**
         * @brief Builds the vector of indices in middle-out order.
         * The order starts at the middle element, then alternates left and right.
         */
        void build_middleOut_order() {
        const size_t s = container.size();  
        middleOut_indices.clear();          
        if (s == 0) return;                  // No elements → no order to build

        const size_t mid = s / 2;            // Calculate the middle index (round down if even)

        middleOut_indices.push_back(mid);    // Start from the middle element

        int left = static_cast<int>(mid) - 1; // Pointer to the element just left of the middle
        size_t right = mid + 1;               // Pointer to the element just right of the middle
        bool nextIsLeft = true;               // Flag to alternate between left and right

        // Continue until we have added all elements in the middle-out order
        while (middleOut_indices.size() < s) {
            if (nextIsLeft && left >= 0) {            // If it's left's turn and still within bounds
            middleOut_indices.push_back(static_cast<size_t>(left));
            --left;                               // Move further left
        } else if (!nextIsLeft && right < s) {    // If it's right's turn and still within bounds
            middleOut_indices.push_back(right);
            ++right;                              // Move further right
        }
        nextIsLeft = !nextIsLeft;                 // Alternate sides
    }
}

    public:
        /**
         * @brief Constructs a MiddleOutIterator for the given container.
         * @param cont Reference to the container to iterate.
         * @param start Initial index position within the computed middle-out order (default is 0).
         */
        explicit MiddleOutIterator(MyContainer<T>& cont, size_t start = 0)
            : container(cont), index(start) {
            build_middleOut_order();
        }

        /**
         * @brief Dereference operator.
         * @return A const reference to the current element in the container.
         * @throws std::out_of_range if the iterator is out of bounds.
         */
        const T& operator*() const {
            if (index >= middleOut_indices.size()) {
                throw std::out_of_range("MiddleOutIterator dereference out of range");
            }
            return container.elements[middleOut_indices[index]];
        }

        /**
        * @brief Writable dereference operator.
        * Returns a non-const reference to the current element,
        * allowing the user to modify it through the iterator.
        * @return Reference to the current element.
        * @throws std::out_of_range if index exceeds bounds.
        */
        T& operator*() {
            if (index >= middleOut_indices.size()) {
                throw std::out_of_range("MiddleOutIterator dereference out of range");
            }
        return container.elements[middleOut_indices[index]];
        
        }

        /**
         * @brief Prefix increment operator.
         * @return Reference to the incremented iterator.
         * @throws std::out_of_range if incrementing beyond the range.
         */
        MiddleOutIterator& operator++() {
            if (index >= middleOut_indices.size()) {
                throw std::out_of_range("MiddleOutIterator increment out of range");
            }
            ++index;
            return *this;
        }

        /**
         * @brief Postfix increment operator.
         * @return Copy of the iterator before the increment.
         */
        MiddleOutIterator operator++(int) {
            MiddleOutIterator temp = *this;
            ++(*this);
            return temp;
        }

        /**
         * @brief Equality comparison operator.
         * @param other Iterator to compare with.
         * @return True if both iterators point to the same position in the same container.
         */
        bool operator==(const MiddleOutIterator& other) const {
            return &container == &other.container && index == other.index;
        }

        /**
         * @brief Inequality comparison operator.
         * @param other Iterator to compare with.
         * @return True if the iterators point to different positions or containers.
         */
        bool operator!=(const MiddleOutIterator& other) const {
            return !(*this == other);
        }
    };

}

#endif // MIDDLEOUTORDER_H
