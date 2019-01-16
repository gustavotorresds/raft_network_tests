CXX=clang++ -std=c++11

SRCS=src/main.cpp src/server.cpp src/client.cpp src/configuration.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

#all: configuration
#
#configuration: $(OBJS)
#	$(CXX) -o configuration $(OBJS)
#
#configuration.o: configuration.cpp configuration.h
#
#clean: 
#	rm -f $(OBJS) configuration

all: main

main: $(OBJS)
	$(CXX) -o main $(OBJS)

main.o: main.cpp server.h client.h configuration.h

server.o: server.h server.cpp

client.o: client.h client.cpp

configuration.o: configuration.h configuration.cpp

clean: 
	rm -f $(OBJS) main
