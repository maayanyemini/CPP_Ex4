# Maayanyemini123@gmail.com 

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

# Targets
MAIN_SRC = main.cpp
TEST_SRC = Test.cpp
EXEC_MAIN = demo
EXEC_TEST = test_runner

# Build and run main
Main:
	$(CXX) $(CXXFLAGS) $(MAIN_SRC) -o $(EXEC_MAIN)
	./$(EXEC_MAIN)

# Build and run tests
test:
	$(CXX) $(CXXFLAGS) $(TEST_SRC) -o $(EXEC_TEST)
	./$(EXEC_TEST)

# Valgrind memory check on tests
valgrind:
	valgrind --leak-check=full --track-origins=yes ./$(EXEC_MAIN)

# Clean generated binaries
clean:
	rm -f $(EXEC_MAIN) $(EXEC_TEST)
