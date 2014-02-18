##Start of the Makefile
prog4: main.o
	g++ -o prog4 prog4.o -I.
	
main.o: prog4.cpp prog4.h
	g++ -Wall -c prog4.cpp -I.
	
clean:
	rm *.o
	
##End of the Makefile