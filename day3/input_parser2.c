#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int problemSolver1(FILE* input){

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
	}
	return score;
}

char findDuplicateFor3(const char *a, const char *b, const char *c){
	char duplicate = '\0';
	printf(" A: %s B: %s C: %s", a, b, c);

	for(int i = 0; a[i] != '\n'; i++){
		for(int j = 0; b[j] != '\n'; j++){
			for(int k = 0; c[k] != '\n'; k++){
				if(b[j] == c[k] && c[k] == a[i]){
					duplicate = b[j];
					break;
				}
			}
		}
	}

	return duplicate;
}

int findScoreForChar(char duplicate){
	if((int) duplicate > 96){
		return (int)duplicate - 96;
	} else if ((int) duplicate > 64){
		return (int)duplicate - 64 + 26;
	}
	return -1;
}

int problemSolver2(FILE* input){
	char * line; 
	size_t length; 
	ssize_t read;

	int score = 0;
	int line_count = 0;

	char a[64];
	char b[64];
	char c[64];

	while ((read = getline(&line, &length, input)) != -1) {	
		if(line_count == 0){
			strcpy(a, line);
		} else if(line_count == 1){
			strcpy(b, line);
		} else if(line_count == 2){
			strcpy(c, line);
		}

		line_count = (line_count + 1) % 3;
		if(line_count == 0){
			char dup = findDuplicateFor3(a,b,c);
			score += findScoreForChar(dup);
			printf("Duplicate: %c \n", dup);
		}
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
		answer = problemSolver2(input);
	} else {
		answer = problemSolver1(input);
	}

	printf("\n=======================\nProgram complete! Answer: %d \n", answer);

	fclose(input);
	return 0;
}
