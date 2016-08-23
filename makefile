CC = g++
CCMAC = g++
CFLAGS= -c -ansi -pedantic -std=c++0x -Weffc++ -g
MOVE = /bin/mv -f
RM = /bin/rm -f
BIN = ./bin

EXE=bin/exec
LIBS=-framework OpenGL -framework GLUT
LIBSLINUX= -lGL -lglut -lm -lGLU
LIBSWINDOWS= -lglu32 -lopengl32  -lglut32 
LDFLAGS= -lm -g -lstdc++

SOURCES = $(wildcard src/*.cpp src/*/*.cpp src/*/*/*.cpp)
ENTETES = $(wildcard src/*.h src/*/*.h src/*/*/*.h)

#SOURCES = ${shell ls *.cpp}
#ENTETES = ${shell ls *.h}
#OBJS =${subst .cpp,.o, ${SOURCES}}
OBJS = ${SOURCES:.cpp=.o}


ifdef DEBUG
	CFLAGS += -g
endif

mac: ${OBJS}
	${CCMAC} ${OBJS} -o ${EXE} ${LDFLAGS} ${LIBS}

linux: ${OBJS}
	${CC} ${OBJS} -o ${EXE} ${LDFLAGS} ${LIBSLINUX}

windows: ${OBJS}
	${CC} ${OBJS} -o ${EXE} ${LDFLAGS} ${LIBSWINDOWS}
   
.cpp.o:
	${CC} ${CFLAGS} $^ -o ${^:.cpp=.o}

run:
	cd bin;./exec

.PHONY: clean veryclean

clean: #pas de dependance
	/bin/rm -f *.o *.gch *.bak *~ src/*.o src/*/*.o src/*/*/*.o

veryclean: clean
	/bin/rm -f ${EXE}
	/bin/rm -f lib/libEngine.a
    
libUnix: ${OBJS}
	/bin/rm -f lib/libEngine.a
	/bin/rm -f src/main.o
	ar -cvq lib/libEngine.a src/*.o
