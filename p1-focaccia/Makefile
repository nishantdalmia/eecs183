CC=g++ -g -Wall -std=c++17

FOCACCIA_SOURCES=focaccia.cpp

FOCACCIA_OBJS=${FOCACCIA_SOURCES:.cpp=.o}

all: focaccia

focaccia: 
	${CC} -o ${FOCACCIA_OBJS} ${FOCACCIA_SOURCES}
	./${FOCACCIA_OBJS}

# Generic rules for compiling a source file to an object file
%.o: %.cpp
	${CC} -c $<
%.o: %.cc
	${CC} -c $<

clean:
	rm -f ${FOCACCIA_OBJS} focaccia 
	rm -rf ${FOCACCIA_OBJS}.dSYM

