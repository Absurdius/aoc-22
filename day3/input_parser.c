#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

	printf("Advent of code input parser\n");
	printf("Called with %d arguments ", argc);
	printf("which are: \n");

	for(int i = 0; argv[i] != NULL; i++){
		printf("%s\n", argv[i]);
	}

	FILE *input;

	if(argc == 2){
		input = fopen("test.txt", "r");
	} else {
		input = fopen("input.txt", "r");
	}

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

	int score = 0; 
	int char_score = 0;

	while ((read = getline(&line, &length, input)) != -1) {
		int half = (strlen(line) - 1) / 2; 
		char first_half[half];
		//char second_half[half]; 
		first_half[half] = '\0';
		char duplicate = '\0';

		char_score = 0;

		for(int i = 0; line[i] != '\n'; i++){
			if(i<half){
				first_half[i] = line[i];
			} else {
				for(int j = 0; j < strlen(first_half); j++){
					if(line[i] == first_half[j]){
						duplicate = line[i];
						if((int) duplicate > 96){
							char_score = (int)duplicate - 96;
						} else if ((int) duplicate > 64){
							char_score = (int)duplicate - 64 + 26;
						}
						break;
					}
				}
			}
		}
		score += char_score;

		printf("half length: %d line: %s", half, line);
		printf("duplicate: %c, char_value: %i, score: %i \n", duplicate, char_score, score);

		// go through
	}


	printf("score: %d\n", score);
	printf("\n=======================\nProgram complete! :D\n");

	fclose(input);
	return 0;
}
