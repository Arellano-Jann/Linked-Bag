LinkedBagExecutable: test.o 
	g++ test.o -o LinkedBagExecutable

test.o: test.cpp LinkedBag.h node.h
	g++ -c test.cpp

clean:
	rm *.o LinkedBagExecutable