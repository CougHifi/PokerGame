/*This is my struct array for the Hand*/
struct Hand{
	//Row and column arrays needs to be 5 deep. I made them 6 deep so that it can accept a NULL character at the end of the string
	//This will prevent the runtime check faliure #2-s. 
	int row[6];
	int col[6];
};

struct sort {
	int row[6];
	int col[6];
};