CXXFLAGS = -std=c++17 -I${SRC_DIR} -Wall -Wextra -Wpedantic -MMD -g

SRC_DIR = src
SOURCES = $(shell find ${SRC_DIR} -name '*.cc')
OBJECTS = ${SOURCES:.cc=.o}
DEPENDS = ${SOURCES:.cc=.d}
EXEC = pathos

TEST_DIR = test
TEST_SOURCES = $(shell find ${TEST_DIR} -name '*.cc')
TEST_OBJECTS = ${TEST_SOURCES:.cc=.o}
TEST_DEPENDS = ${TEST_SOURCES:.cc=.d}
GTEST_DIR = /usr/src/googletest/googletest
GTEST_INCLUDE = ${GTEST_DIR}/include
TEST_LIBS = -I ${GTEST_INCLUDE} -lgtest -lgtest_main -lpthread
TEST_EXEC = run-tests

${EXEC}: ${OBJECTS}
	${CXX} ${LDFLAGS} $^ -lncurses -o $@
	./${EXEC}

${TEST_EXEC}: ${TEST_OBJECTS}
	${CXX} ${LDFLAGS} $^ -o $@ ${TEST_LIBS}
	./${TEST_EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm -f ${OBJECTS} ${DEPENDS} ${TEST_OBJECTS} ${TEST_DEPENDS}
