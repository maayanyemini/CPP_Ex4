# 📦 MyContainer – Custom C++ Container with Unique Iterators

---

## 🧾 About the Project

`MyContainer` is a generic container class written in C++, featuring a collection of specialized iterators that allow for unique and non-traditional traversal methods. The project demonstrates modern C++ techniques including custom iteration logic, exception safety, and memory management with leak checks.

---

## 🔁 Available Iterators

- 🔼 **AscendingIterator** – Iterates over the container in ascending order.
- 🔽 **DescendingIterator** – Iterates in descending order.
- 🔀 **SideCrossIterator** – Alternates between smallest and largest values.
- ↩️ **ReverseIterator** – Traverses in reverse of insertion order.
- 🔁 **OrderIterator** – Follows the exact insertion order.
- 🎯 **MiddleOutIterator** – Starts from the middle and moves outward alternately.

---

## 🗂️ Folder Structure
.
├── Iterator/ # All iterator class headers
│ ├── AscendingOrder.h
│ ├── DescendingOrder.h
│ ├── SideCrossOrder.h
│ ├── ReverseOrder.h
│ ├── Order.h
│ └── MiddleOutOrder.h
│
├── MyContainer.h # Main container class
├── Main.cpp # Demo usage
├── Test.cpp # Unit tests (based on doctest)
├── Makefile # Build, test, valgrind, and clean commands
└── README.md # This file

---

## 🛠️ Build & Run Commands

Run any of the following from the terminal:

| Command         | Description                                        |
|----------------|----------------------------------------------------|
| `make Main`     | Builds and runs the main demo (`Main.cpp`)         |
| `make test`     | Compiles and runs the unit tests (`Test.cpp`)      |
| `make valgrind` | Runs memory leak detection using `valgrind`        |
| `make clean`    | Cleans up all compiled files and executables       |

---

## ✅ What's Covered in the Tests?

- Template usage with types like `int`, `std::string`, etc.
- Adding and removing elements, with error handling for invalid operations.
- All iterators are tested for git add .correctness and edge-case behavior.
- Exceptions for advancing past the end of iterators.
- Empty container behavior with all iterators.
- Memory leaks detection with `valgrind`.

---

## 👩‍💻 Author

**Maayan Cohen Yemini** 
**Email: maayanyemini123@gmail.com** 
