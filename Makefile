SRCDIR = src
CXXFLAGS = -std=c++17 -I${SRCDIR} -Wall -Wextra -Wpedantic -MMD -g
SOURCES = $(shell find ${SRCDIR} -name '*.cc')
OBJECTS = ${SOURCES:.cc=.o}
DEPENDS = ${SOURCES:.cc=.d}
EXEC = pathos

${EXEC}: ${OBJECTS}
	${CXX} ${LDFLAGS} $^ -lncurses -o $@

-include ${DEPENDS}

.PHONY: clean

clean:
	rm -f ${OBJECTS} ${DEPENDS}
