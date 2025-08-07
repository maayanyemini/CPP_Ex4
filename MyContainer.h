//Maayanyemini123@gmail.com 

#ifndef MYCONTAINER_H
#define MYCONTAINER_H
#include <vector>
#include <iostream>
#include "Iterator/AscendingOrder.h"
#include "Iterator/DescendingOrder.h"
#include "Iterator/Order.h"
#include "Iterator/SideCrossOrder.h"
#include "Iterator/ReverseOrder.h"
#include "Iterator/MiddleOutOrder.h"

namespace Container {
    template<typename T = int> //variable type default to int
    class MyContainer {
    private:
        std::vector<T> elements;

    public:
        // Giving the iterators an access to private elements
        friend class AscendingIterator<T>;
        friend class DescendingIterator<T>;
        friend class SideCrossIterator<T>;
        friend class ReverseIterator<T>;
        friend class OrderIterator<T>;
        friend class MiddleOutIterator<T>;

        void addElement(const T &element);

        void removeElement(const T &item);

        /**
         * **\
         * @brief Returns the number of elements currently stored.
         * @return Size of the container.
         */
        size_t size() const {
             return elements.size(); 
            }
        //Warning!- Do not add/remove elements while iterating, as it may invalidate iterators.
        // Iterator methods to access different orders of elements 
        // we send the current container mycontainer to the iterator
        // size()/0 is the starting index for the iterator

        AscendingIterator<T> begin_ascending_order() { return AscendingIterator<T>(*this, 0); }
        AscendingIterator<T> end_ascending_order() { return AscendingIterator<T>(*this, size()); }

        DescendingIterator<T> begin_descending_order() { return DescendingIterator<T>(*this, 0); }
        DescendingIterator<T> end_descending_order() { return DescendingIterator<T>(*this, size()); }

        SideCrossIterator<T> begin_side_cross_order() { return SideCrossIterator<T>(*this, 0); }
        SideCrossIterator<T> end_side_cross_order() { return SideCrossIterator<T>(*this, size()); }

        ReverseIterator<T> begin_reverse_order() { return ReverseIterator<T>(*this, 0); }
        ReverseIterator<T> end_reverse_order() { return ReverseIterator<T>(*this, size()); }

        OrderIterator<T> begin_order() { return OrderIterator<T>(*this, 0); }
        OrderIterator<T> end_order() { return OrderIterator<T>(*this, size()); }

        MiddleOutIterator<T> begin_middle_out_order() { return MiddleOutIterator<T>(*this, 0); }
        MiddleOutIterator<T> end_middle_out_order() { return MiddleOutIterator<T>(*this, size()); }

        /**
        * **\
        * @brief Outputs the container elements to a stream.
        * @param os Output stream.
        * @param container Container to print.
        * @return Reference to the output stream.
        */
        friend std::ostream &operator<<(std::ostream &os, const MyContainer<T> &container) {
            os << "[";
            for (size_t i = 0; i < container.elements.size(); ++i) {
                os << container.elements[i];
                if (i + 1 != container.elements.size()) {
                    os << ", ";
                }
            }
            os << "]";
            return os;
        }
    };

    /**
     * **\
     * @brief Adds an element to the end of the container.
     * @param element Element to add.
     */
    template<typename T>
    void MyContainer<T>::addElement(const T &element) {
        elements.push_back(element);
    }

    /**
         * **\
         * @brief Removes an element from the container.
         * @param item The element to remove.
         * @throws std::runtime_error if the element is not found.
         */
    template<typename T>
    void MyContainer<T>::removeElement(const T &item) {
        auto oldSize = elements.size(); 
        // Remove the element if it exists- push the item to the end of the vector and then erase it and return the new size
        elements.erase(std::remove(elements.begin(), elements.end(), item), elements.end());
        if (elements.size() == oldSize) {
            throw std::runtime_error("Element not found in container");
        }
    }
}
#endif //MYCONTAINER_H
