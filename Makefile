D_SRC=src/
SRC=$(wildcard $(D_SRC)*.c)  # get all source files
SRC_MAIN=$(wildcard */main.c)  # get all main files

TEST_SRC=$(filter-out $(SRC_MAIN), $(SRC))  # remove the main files from the source, so that they don't conflict if there are multiple main() functions
# TEST_SRC += Unity/src/unity.c

C_TESTS=$(wildcard test/*.c)  # get all the test files
TESTS=$(patsubst test/%.c,test/%,$(C_TESTS))

INCLUDE=include/

main: $(SRC)
	$(info MAKING $@ USING SOURCE FILES: $^)
	gcc -o $(DEST)$@ $^ -I $(INCLUDE)
tests: $(TESTS) 
	$(info MADE $@ USING SOURCE FILES: $^)

all: main tests

test/test_%: test/test_%.c src/%.c Unity/src/unity.c
	gcc -o $(DEST)$@ test/test_$*.c $(D_SRC)$*.c Unity/src/unity.c -I $(INCLUDE) -I Unity/src/
