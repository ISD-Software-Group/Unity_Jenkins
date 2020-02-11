SRC=$(wildcard src/*.c)  # get all source files
SRC_MAIN=$(wildcard */main.c)  # get all main files

TEST_SRC=$(filter-out $(SRC_MAIN), $(SRC))  # remove the main files from the source, so that they don't conflict if there are multiple main() functions
TEST_SRC += Unity/src/unity.c

TESTS=$(wildcard test/*.c)  # get all the test files

INCLUDE=include/

DEST=build/

main: $(SRC)
	$(info MAKING $@ USING SOURCE FILES: $^)
	gcc -o build/$@ $^ -I $(INCLUDE)
tests: $(TESTS) $(TEST_SRC)
	$(info MAKING $@ USING SOURCE FILES: $^)
	gcc -o $(DEST)test_add test/test_add.c $(TEST_SRC) -I $(INCLUDE) -I Unity/src/
	gcc -o $(DEST)test_subtract test/test_subtract.c $(TEST_SRC) -I $(INCLUDE) -I Unity/src/