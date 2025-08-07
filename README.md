
# 📦 MyContainer Project

---

### 📘 Project Description

This project implements a generic container class named `MyContainer`, along with several advanced iterators that traverse the container’s elements in unique orders:

- **AscendingIterator** – iterates in ascending (sorted) order.
- **DescendingIterator** – iterates in descending (reverse sorted) order.
- **SideCrossIterator** – alternates between the smallest and largest elements.
- **ReverseIterator** – iterates in reverse insertion order.
- **OrderIterator** – iterates in original insertion order.
- **MiddleOutIterator** – starts from the middle and alternates outward.

The project includes comprehensive unit tests for all functionalities, proper exception handling for invalid operations, and memory leak detection using valgrind.

---

### 🗂️ Project Structure

```
.
├── Iterator/                    # Folder containing all iterator classes
│   ├── AscendingOrder.h
│   ├── DescendingOrder.h
│   ├── SideCrossOrder.h
│   ├── ReverseOrder.h
│   ├── Order.h
│   └── MiddleOutOrder.h
│
├── MyContainer.h               # Main generic container header
├── Main.cpp                    # Demo and usage example main file
├── Test.cpp                    # Unit tests (doctest framework)
├── Makefile                    # Compilation, testing, valgrind, cleanup
└── README.md                   # This documentation file
```

---

### Makefile Commands:

| Command         | Description                                   |
| --------------- | ---------------------------------------------|
| `make Main`     | Builds and runs the demonstration executable (`Main.cpp`) |
| `make test`     | Builds and runs the unit tests (`Test.cpp`) using doctest |
| `make valgrind` | Runs memory leak checks on the demo executable with `valgrind` |
| `make clean`    | Removes all compiled binaries and temporary files |

---

### 🛠️ Usage Examples

```bash
# Build and run the demo
make Main

# Build and run all unit tests
make test

# Run memory leak detection using valgrind
make valgrind

# Clean build artifacts and executables
make clean
```

---

### ✅ What is Tested?

- Creating containers with default and custom template types (e.g., `int`, `std::string`).
- Adding and removing elements, including exception throwing when removing non-existent elements.
- Iterator traversals verifying element order for each iterator type.
- Exception throwing when incrementing iterators past the end (overflow).
- Behavior of all iterators on empty containers.

---

### 👩‍💻 Author

**Eden Hassin**  
📧 Edenhassin@gmail.com  
🗓️ Project completed: May–June 2025
