#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int problemSolver1(FILE* input){

	char * line; 
	size_t length; 
	ssize_t read;
	
	int score = 0; 

	while ((read = getline(&line, &length, input)) != -1) {
	}

	return score;
}

int problemSolver2(FILE* input){
	char * line; 
	size_t length; 
	ssize_t read;

	int score = 0;

	while ((read = getline(&line, &length, input)) != -1) {
		
	}

	return score;
}


int main(int argc, char *argv[]){

	printf("Advent of code input parser\n");
	printf("Called with %d arguments ", argc);
	printf("which are: \n");

	char *input_file = "input.txt";
	int problem = 1;

	for(int i = 0; argv[i] != NULL; i++){
		printf("%s\n", argv[i]);
		
		if(strcmp(argv[i], "-t") == 0){
			input_file = "test.txt";
		} 

		if(strcmp(argv[i], "-2") == 0){
			problem = 2;
		}
	}

	FILE *input;	
	input = fopen(input_file, "r");

	if(input == NULL)
	{
		printf("File could not be opened");
		return 1; 
	}

	int file_size = 0; 
	fseek (input , 0 , SEEK_END);
	file_size = ftell (input);
	rewind (input);

	printf("File size %i \n", file_size); 

	int answer = 0; 
	if(problem == 2){
		problemSolver2(input);
	} else {
		problemSolver1(input);
	}

	printf("\n=======================\nProgram complete! Answer: %d \n", answer);

	fclose(input);
	return 0;
}
