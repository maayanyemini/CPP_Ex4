//Maayanyemini123@gmail.com 

#include <iostream>
#include "MyContainer.h"

using namespace Container;

int main() {
    MyContainer<int> container;

    std::cout << "Initial size: " << container.size() << std::endl;

    std::cout << "\nAdding elements: 6, 10, 7, 1, 2" << std::endl;
    container.addElement(6);
    container.addElement(10);
    container.addElement(7);
    container.addElement(1);
    container.addElement(2);

    std::cout << "Container after insertions: " << container << std::endl;
    std::cout << "Size: " << container.size() << std::endl;

    std::cout << "\nAscending order: ";
    for (auto it = container.begin_ascending_order(); it != container.end_ascending_order(); ++it)
        std::cout << *it << ' ';
    std::cout << std::endl;

    std::cout << "Descending order: ";
    for (auto it = container.begin_descending_order(); it != container.end_descending_order(); ++it)
        std::cout << *it << ' ';
    std::cout << std::endl;

    std::cout << "Side-cross order: ";
    for (auto it = container.begin_side_cross_order(); it != container.end_side_cross_order(); ++it)
        std::cout << *it << ' ';
    std::cout << std::endl;

    std::cout << "Reverse order: ";
    for (auto it = container.begin_reverse_order(); it != container.end_reverse_order(); ++it)
        std::cout << *it << ' ';
    std::cout << std::endl;

    std::cout << "Insertion order: ";
    for (auto it = container.begin_order(); it != container.end_order(); ++it)
        std::cout << *it << ' ';
    std::cout << std::endl;

    std::cout << "Middle-out order: ";
    for (auto it = container.begin_middle_out_order(); it != container.end_middle_out_order(); ++it)
        std::cout << *it << ' ';
    std::cout << std::endl;

    // Remove an existing element
    std::cout << "\nRemoving element 6..." << std::endl;
    container.removeElement(6);
    std::cout << "After removal: " << container << std::endl;

    // Try removing a non-existing element (should throw an exception)
    try {
        std::cout << "Trying to remove element 100..." << std::endl;
        container.removeElement(100);
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    // Test behavior with an empty container
    MyContainer<int> empty;
    std::cout << "\nTesting empty container..." << std::endl;
    std::cout << "Size: " << empty.size() << std::endl;
    std::cout << "Elements: " << empty << std::endl;

    std::cout << "Middle-out on empty: ";
    for (auto it = empty.begin_middle_out_order(); it != empty.end_middle_out_order(); ++it)
        std::cout << *it << ' ';
    std::cout << std::endl;

    // Modify elements using iterators
    std::cout << "\nModifying values through iterators..." << std::endl;

    auto asc_it = container.begin_ascending_order();
    *asc_it = 100; // needs to be the first element (1) to be changed to 100
    auto rev_it = container.begin_reverse_order();
    *rev_it = 200; // needs to be the last element (2) to be changed to 200

    std::cout << "Container after modifications: " << container << std::endl << std::endl;

    std::cout << "Ascending after modification: ";
    for (auto it = container.begin_ascending_order(); it != container.end_ascending_order(); ++it)
    std::cout << *it << ' ';
    std::cout << std::endl << std::endl;

    std::cout << "Descending after modification: ";
    for (auto it = container.begin_descending_order(); it != container.end_descending_order(); ++it)
    std::cout << *it << ' ';
    std::cout << std::endl << std::endl;

    std::cout << "Side-cross after modification: ";
    for (auto it = container.begin_side_cross_order(); it != container.end_side_cross_order(); ++it)
    std::cout << *it << ' ';
    std::cout << std::endl << std::endl;

    std::cout << "Reverse after modification: ";
    for (auto it = container.begin_reverse_order(); it != container.end_reverse_order(); ++it)
    std::cout << *it << ' ';
    std::cout << std::endl << std::endl;

    std::cout << "Insertion order after modification: ";
    for (auto it = container.begin_order(); it != container.end_order(); ++it)
    std::cout << *it << ' ';
    std::cout << std::endl << std::endl;

    std::cout << "Middle-out after modification: ";
    for (auto it = container.begin_middle_out_order(); it != container.end_middle_out_order(); ++it)
    std::cout << *it << ' ';
    std::cout << std::endl << std::endl;

    return 0;
}

