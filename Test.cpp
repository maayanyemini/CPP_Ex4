//Maayanyemini123@gmail.com 

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "MyContainer.h"
using namespace Container;

// Test the default template type of MyContainer (should be int)
TEST_CASE("Default type of MyContainer is int") {
    MyContainer<> defaultContainer;  // no template parameter
    defaultContainer.addElement(1);
    defaultContainer.addElement(2);
    CHECK((defaultContainer.size() == 2));
}

// Test adding, removing, and throwing on missing element
TEST_CASE("Basic container operations") {
    MyContainer<int> container;

    // Check initial size is zero
    CHECK((container.size() == 0));

    // Add elements
    container.addElement(8);
    container.addElement(10);
    container.addElement(3);

    // Check size after additions
    CHECK((container.size() == 3));

    // Remove existing element
    container.removeElement(10);
    CHECK((container.size() == 2));

    // Remove non-existent element should throw
    CHECK_THROWS_AS(container.removeElement(99), std::runtime_error);
}

// Check AscendingIterator produces sorted order
TEST_CASE("AscendingIterator order") {
    MyContainer<int> container;
    container.addElement(7);
    container.addElement(2);
    container.addElement(5);

    std::vector<int> expected = {2, 5, 7};
    std::vector<int> actual;

    for (auto it = container.begin_ascending_order(); it != container.end_ascending_order(); ++it)
        actual.push_back(*it);

    CHECK((actual == expected));

    auto it = container.begin_ascending_order();
    SUBCASE("Dereference operator *") {
        CHECK((*it == 2));
    }
    SUBCASE("Pre-increment ++it") {
        ++it;
        CHECK((*it == 5));
    }
    SUBCASE("Post-increment it++") {
        AscendingIterator<int> before = it++;
        CHECK((*before == 2));
        CHECK((*it == 5));
    }
    SUBCASE("Increment to end and exception") {
        ++it; // 2 -> 5
        ++it; // 5 -> 7
        ++it; // now needs to be out of range
        CHECK_THROWS_AS(*it, std::out_of_range);
    }
    SUBCASE("Modify element via iterator") {
    *it = 42;  // modify first element
    auto it2 = container.begin_ascending_order(); // start from the beginning again Because we modified the first element
    std::vector<int> updated;
    while (it2 != container.end_ascending_order()) {
        updated.push_back(*it2);
        ++it2;
    }
    std::vector<int> expected = {5, 7, 42};
    CHECK(updated == expected);
}
}

// Check DescendingIterator produces reversed sorted order
TEST_CASE("DescendingIterator order") {
    MyContainer<int> container;
    container.addElement(1);
    container.addElement(4);
    container.addElement(3);

    std::vector<int> expected = {4, 3, 1};
    std::vector<int> actual;

    for (auto it = container.begin_descending_order(); it != container.end_descending_order(); ++it)
        actual.push_back(*it);

    CHECK((actual == expected));

    auto it = container.begin_descending_order();
    SUBCASE("Dereference operator *") {
        CHECK((*it == 4));
    }
    SUBCASE("Pre-increment ++it") {
        ++it;
        CHECK((*it == 3));
    }
    SUBCASE("Post-increment it++") {
        DescendingIterator<int> before = it++;
        CHECK((*before == 4));
        CHECK((*it == 3));
    }
    SUBCASE("Increment to end and exception") {
        ++it; // 4 -> 3
        ++it; // 3 -> 1
        ++it; // now suppose to be out of range
        CHECK_THROWS_AS(*it, std::out_of_range);
    }
    SUBCASE("Modify element via iterator") {
    *it = 99;  // modify highest element
    auto it2 = container.begin_descending_order();
    std::vector<int> updated;
    while (it2 != container.end_descending_order()) {
        updated.push_back(*it2);
        ++it2;
    }
    std::vector<int> expected = {99, 3, 1};  // expectation to new order after modification
    CHECK(updated == expected);
}
}

// Check SideCrossIterator alternates smallest/largest
TEST_CASE("SideCrossIterator order") {
    MyContainer<int> container;
    container.addElement(1);
    container.addElement(3);
    container.addElement(5);
    container.addElement(7);
    container.addElement(9);

    std::vector<int> expected = {1, 9, 3, 7, 5};
    // {42,3,9,5,7} // if we modify the first element
    std::vector<int> actual;

    for (auto it = container.begin_side_cross_order(); it != container.end_side_cross_order(); ++it)
        actual.push_back(*it);

    CHECK((actual == expected));

    auto it = container.begin_side_cross_order();
    SUBCASE("Dereference operator *") {
        CHECK((*it == 1));
    }
    SUBCASE("Pre-increment ++it") {
        ++it;
        CHECK((*it == 9));
    }
    SUBCASE("Post-increment it++") {
        SideCrossIterator<int> before = it++;
        CHECK((*before == 1));
        CHECK((*it == 9));
    }
    SUBCASE("Increment to end and exception") {
        ++it; // 1 -> 9
        ++it; // 9 -> 3
        ++it; // 3 -> 7
        ++it; // 7 -> 5
        ++it; // now out of range
        CHECK_THROWS_AS(*it, std::out_of_range);
    }
    SUBCASE("Modify element via iterator") {
    *it = 42;  // modify first element

    auto it2 = container.begin_side_cross_order();
    std::vector<int> updated;
    while (it2 != container.end_side_cross_order()) {
        updated.push_back(*it2); // collect updated elements
        ++it2;
    }

    std::vector<int> expected =  {3, 42, 5, 9, 7};   // new order after modification
    CHECK(updated == expected);
}
}

// Check ReverseIterator goes backwards by insertion order
TEST_CASE("ReverseIterator order") {
    MyContainer<int> container;
    container.addElement(10);
    container.addElement(20);
    container.addElement(30);

    std::vector<int> expected = {30, 20, 10};
    std::vector<int> actual;

    for (auto it = container.begin_reverse_order(); it != container.end_reverse_order(); ++it)
        actual.push_back(*it);

    CHECK((actual == expected));

    auto it = container.begin_reverse_order();
    SUBCASE("Dereference operator *") {
        CHECK((*it == 30));
    }
    SUBCASE("Pre-increment ++it") {
        ++it;
        CHECK((*it == 20));
    }
    SUBCASE("Post-increment it++") {
        ReverseIterator<int> before = it++;
        CHECK((*before == 30));
        CHECK((*it == 20));
    }
    SUBCASE("Increment to end and exception") {
        ++it; // 30 -> 20
        ++it; // 20 -> 10
        ++it; // now out of range
        CHECK_THROWS_AS(*it, std::out_of_range);
    }
    SUBCASE("Iterator after container change") {
    container.addElement(99);
    auto it = container.begin_reverse_order();
    CHECK((*it == 99));
    }
    SUBCASE("Modify element via iterator") {
    *it = 42;  // 30 becomes 42
    std::vector<int> updated;
    for (auto it2 = container.begin_reverse_order(); it2 != container.end_reverse_order(); ++it2)
        updated.push_back(*it2);
    std::vector<int> expected = {42, 20, 10};
    CHECK(updated == expected);
}

}

// Check OrderIterator returns elements in insertion order
TEST_CASE("OrderIterator order (insertion)") {
    MyContainer<int> container;
    container.addElement(5);
    container.addElement(2);
    container.addElement(8);

    std::vector<int> expected = {5, 2, 8};
    std::vector<int> actual;

    for (auto it = container.begin_order(); it != container.end_order(); ++it)
        actual.push_back(*it);

    CHECK((actual == expected));

    auto it = container.begin_order();
    SUBCASE("Dereference operator *") {
        CHECK((*it == 5));
    }
    SUBCASE("Pre-increment ++it") {
        ++it;
        CHECK((*it == 2));
    }
    SUBCASE("Post-increment it++") {
        OrderIterator<int> before = it++;
        CHECK((*before == 5));
        CHECK((*it == 2));
    }
    SUBCASE("Increment to end and exception") {
        ++it; // 5 -> 2
        ++it; // 2 -> 8
        ++it; // now out of range
        CHECK_THROWS_AS(*it, std::out_of_range);
    }
    SUBCASE("Modify element via iterator") {
    *it = 99; // modify first element
    auto it2 = container.begin_order();
    std::vector<int> updated;
    while (it2 != container.end_order()) {
        updated.push_back(*it2);
        ++it2;
    }
    std::vector<int> expected = {99, 2, 8}; //the first element is now 99
    CHECK(updated == expected);
    }
}

// Check MiddleOutIterator starts at middle and alternates outwards
TEST_CASE("MiddleOutIterator order") {
    MyContainer<int> container;
    container.addElement(10);
    container.addElement(20);
    container.addElement(30);
    container.addElement(40);
    container.addElement(50);

    std::vector<int> expected = {30, 20, 40, 10, 50};
    std::vector<int> actual;

    for (auto it = container.begin_middle_out_order(); it != container.end_middle_out_order(); ++it)
        actual.push_back(*it);

    CHECK((actual == expected));

    auto it = container.begin_middle_out_order();
    SUBCASE("Dereference operator *") {
        CHECK((*it == 30));
    }
    SUBCASE("Pre-increment ++it") {
        ++it;
        CHECK((*it == 20));
    }
    SUBCASE("Post-increment it++") {
        MiddleOutIterator<int> before = it++;
        CHECK((*before == 30));
        CHECK((*it == 20));
    }
    SUBCASE("Increment to end and exception") {
        ++it; // 30 -> 20
        ++it; // 20 -> 40
        ++it; //40 -> 10
        ++it; //10 -> 50
        ++it; // now out of range
        CHECK_THROWS_AS(*it, std::out_of_range);
    }
    SUBCASE("Modify element via iterator") {
        *it = 100; //center changed to `100`
        auto it2 = container.begin_middle_out_order();
        std::vector<int> updated;
        while (it2 != container.end_middle_out_order()) {
        updated.push_back(*it2);
        ++it2;
        }
        std::vector<int> expected = {100, 20, 40, 10, 50};
        CHECK(updated == expected);
    }
}

// Check all iterators are empty when container is empty
TEST_CASE("Edge cases: empty container iterators") {
    MyContainer<int> empty;

    CHECK((empty.size() == 0));

    CHECK((empty.begin_order() == empty.end_order()));
    CHECK((empty.begin_ascending_order() == empty.end_ascending_order()));
    CHECK((empty.begin_side_cross_order() == empty.end_side_cross_order()));
    CHECK((empty.begin_descending_order() == empty.end_descending_order()));
    CHECK((empty.begin_reverse_order() == empty.end_reverse_order()));
    CHECK((empty.begin_middle_out_order() == empty.end_middle_out_order()));

    // Dereferencing any begin should throw
    CHECK_THROWS_AS(*empty.begin_ascending_order(), std::out_of_range);
    CHECK_THROWS_AS(*empty.begin_reverse_order(), std::out_of_range);
    CHECK_THROWS_AS(*empty.begin_middle_out_order(), std::out_of_range);
}

// Test the container with std::string type instead of int
TEST_CASE("Container with std::string") {
    MyContainer<std::string> names;
    names.addElement("Shir");
    names.addElement("Yossi");
    names.addElement("Maayan");

    // Check size
    CHECK((names.size() == 3));

    // Check ascending order
    std::vector<std::string> expected = {"Maayan", "Shir", "Yossi"};
    std::vector<std::string> actual;
    for (auto it = names.begin_ascending_order(); it != names.end_ascending_order(); ++it)
        actual.push_back(*it);
    CHECK((actual == expected));

    // Check reverse order (insertion)
    actual.clear();
    for (auto it = names.begin_reverse_order(); it != names.end_reverse_order(); ++it)
        actual.push_back(*it);
    CHECK((actual == std::vector<std::string>{"Maayan", "Yossi", "Shir"}));

    // Remove a name and check again
    names.removeElement("Yossi");
    CHECK((names.size() == 2));
    CHECK_THROWS_AS(names.removeElement("Mor"), std::runtime_error);
}
