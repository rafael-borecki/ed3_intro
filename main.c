#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./funcoesFornecidas.c"
#include "./speciesRoutines.c"

int main(){
	int command;
	char filename[30];
	scanf("%d", &command);
	char dump_space = getchar();
	readline(filename);

	switch(command){
		case(1):{
							int n;
							scanf("%d", &n);
							FILE* file = fopen(filename, "wb");
							if (file == NULL){
								return EXIT_FAILURE;
							}
							for (int i = 0; i < n; i++){
								registerSpecies(file);
							}
							fclose(file);
							break;
						}

		case(2):{
							FILE* file = fopen(filename, "rb");
							if (file == NULL){
								return EXIT_FAILURE;
							}
							reportSpecies(file);
							fclose(file);
							break;
						}

		case(3):{
							FILE* file = fopen(filename, "rb");
							if (file == NULL){
								return EXIT_FAILURE;
							}
							searchSpecies(file);
							fclose(file);
								break;
						}

		case(4):{
							int n,species_id;
							scanf("%d", &n);
							FILE* file = fopen(filename, "wb");
							if (file == NULL){
								return EXIT_FAILURE;
							}
							for (int i = 0; i < n; i++){
								registerInfoSpecies(file);
							}
							fclose(file);
							break;
						}
	}
	return 0;
}
