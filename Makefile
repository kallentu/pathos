CXXFLAGS = -std=c++17 -I${SRC_DIR} -I${TEST_DIR} -Wall -Wextra -Wpedantic -MMD -g

SRC_DIR = src
SOURCES = $(shell find ${SRC_DIR} -name '*.cc')
OBJECTS = ${SOURCES:.cc=.o}
DEPENDS = ${SOURCES:.cc=.d}
EXEC = pathos

# We need to add dependencies from the actual game files, but don't
# want to compile the main function that runs the game.
TEST_DIR = test
TEST_SOURCES = $(shell find . -name '*.cc' -not -name "main.cc")
TEST_OBJECTS = ${TEST_SOURCES:.cc=.o}
TEST_DEPENDS = ${TEST_SOURCES:.cc=.d}
GTEST_DIR = /usr/src/googletest/googletest
GTEST_INCLUDE = ${GTEST_DIR}/include
TEST_LIBS = -I ${GTEST_INCLUDE} -lgtest -lgmock -lgtest_main -lpthread
TEST_EXEC = run-tests

${EXEC}: ${OBJECTS}
	${CXX} ${LDFLAGS} $^ -lncurses -o $@
	./${EXEC}

${TEST_EXEC}: ${TEST_OBJECTS}
	${CXX} ${LDFLAGS} $^ -lncurses -o $@ ${TEST_LIBS}
	./${TEST_EXEC}

-include ${DEPENDS} ${TEST_DEPENDS}

.PHONY: clean

clean:
	rm -f ${OBJECTS} ${DEPENDS} ${TEST_OBJECTS} ${TEST_DEPENDS}
