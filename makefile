CC := g++
FLAGS = -std=c++11
COMPILE_FLAG = $(FLAGS) -c  

main: Document.o Human.o Library.o main.o
	$(CC) Document.o Human.o Library.o main.o $(FLAGS) -o main

Document.o: Document.cpp Document.hpp
	$(CC) $(COMPILE_FLAG) Document.cpp

Human.o: Human.cpp Human.hpp Document.hpp
	$(CC) $(COMPILE_FLAG) Human.cpp 

Library.o: Library.cpp Human.hpp 
	$(CC) $(COMPILE_FLAG) Library.cpp

main.o: main.cpp Library.hpp
	$(CC) $(COMPILE_FLAG) main.cpp


clean:
	rm *.o a.out