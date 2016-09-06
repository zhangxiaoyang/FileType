test: test.o FileType.o
	g++ -o test test.o FileType.o
clean:
	rm *.o
	rm test
test.o: test.cpp
	g++ -c -o test.o test.cpp
FileType.o: FileType.cpp FileType.h
	g++ -c -o FileType.o FileType.cpp
