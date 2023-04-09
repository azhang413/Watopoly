CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -MMD -Werror=vla
OBJECTS = shuffle.o player.o building.o display.o square.o theBoard.o Watopoly.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = Watopoly

${EXEC} : ${OBJECTS}
		${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

clean :
		rm ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS} # reads the .d files and reruns dependencies
