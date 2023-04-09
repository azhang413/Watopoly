CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -MMD -Werror=vla
OBJECTS = display.o Watopoly.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = runit

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

clean:
	rm ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS}
