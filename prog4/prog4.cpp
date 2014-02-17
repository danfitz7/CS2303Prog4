/*
CS 2302 PROGRAM 4
Daniel Fitzgerald
2/17/14
*/



//function prototypes

/*
*/
int main(int argc, char* argv[]){
	if(DEBUG){printf("\n\nPROGRAM 3\nProcessing %i events...\n", argc);}
	
	//ensure there is the correct number of command line arguments (the first is the name of our program, the second should be the number of arguments to come from a file)
	if (argc<3){
		printf("ERROR: Proper usage requires <source> and <event> followed by the event data, one event per line\n");
		return 0;
	}
	
	//char* progString=argv[0];				//the first arg is always the name of the program
	unsigned int nJobs=atoi(argv[1]); 		//the number of samples should be the second argument
	unsigned int eventTime=atoi(argv[2]);	//the event time in 100 millisecond units
	
	//loop through the rest of the command line arguments
	printf("Reading %i events...\n", nJobs);
	
	//pointer to the head node of the queue (linked list) of events (sorted by arrival time)
	node* eventListPtr=NULL;	

	//variables to store input line data
	int ID, ARRIVAL_TIME, CPU;
		
	//loop through events to read in
	process* processPtrs[nJobs];		//array pointers to all processPtrs we will simulate (for data collection)
	for (unsigned int arg=0;arg<nJobs;arg++){	//loop through input lines
	}
	printf("\nDone.\n");
}
