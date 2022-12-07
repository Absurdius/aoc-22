#include <stdio.h>
#include <stdlib.h>

int main() {

FILE *input = fopen("calorie-input", "r");

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

int max_calories = 0; 
int current_calories = 0;

while ((read = getline(&line, &length, input)) != -1) {
	int line_value = atoi(line);
	if(line_value == 0){
		if(current_calories > max_calories){
			max_calories = current_calories;
		}
		current_calories = 0;

	} else {
		current_calories += line_value;
	}
}

printf("Max calories is: %d \n", max_calories);

fclose(input);
return 0;
}
