#include <stdio.h>
#include <stdlib.h>

int main() {

FILE *input = fopen("input.txt", "r");

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

char * line; 
size_t length; 
ssize_t read;

int score_matrix[9] =  {3,0,6,
						6,3,0,
						0,6,3};
int score = 0;


while ((read = getline(&line, &length, input)) != -1) {

	int their = line[0];
	their -= 65;

	int yours = line[2];
	yours -= 88;

	score += score_matrix[their + (3*yours)];

	if(line[2] == 'X'){
		score += 1;
	} else if(line[2] == 'Y'){
		score += 2; 
	} else if(line[2] == 'Z'){
		score += 3; 
	}
}

printf("final score is %i \n", score);

fclose(input);
return 0;
}
