CXX=clang++ -std=c++11

SRCS=main.cpp server.cpp client.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: main

main: $(OBJS)
	$(CXX) -o main $(OBJS)

main.o: main.cpp server.h client.h

server.o: server.h server.cpp

client.o: client.h client.cpp

clean: 
	rm -f $(OBJS) main
