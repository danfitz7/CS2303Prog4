##Start of the Makefile
prog4: main.o node.o
	g++ -o prog4 prog4.o node.o -I.
	
main.o: prog4.h node.h prog4.cpp
	g++ -Wall -c prog4.cpp -I.
	
node.o: node.h prog4.h node.cpp
	g++ -Wall -c node.cpp -I.
	
clean:
	rm *.o
	
##End of the Makefile
