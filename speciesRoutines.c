#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./speciesRoutines.h"

void registerSpecies(FILE *file){
	Species temp_species;
	printf("ID: ");
	scanf("%d", &temp_species.species_id);
	printf("NAME: ");
	readline(temp_species.name);
	printf("SNAME: ");
	readline(temp_species.scientific_name);
	printf("POP: ");
	scanf("%d", &temp_species.population);
	printf("STATS: ");
	readline(temp_species.status);
	printf("XY: ");
	scanf("%f %f", &temp_species.location[0], &temp_species.location[1]);
	printf("HI: ");
	scanf("%d", &temp_species.human_impact);
	fwrite(&temp_species.species_id,sizeof(int),1,file);
	fwrite(&temp_species.name,NAME_SIZE*sizeof(char),1,file);
	fwrite(&temp_species.scientific_name,SCIENTIFIC_SIZE*sizeof(char),1,file);
	fwrite(&temp_species.population,sizeof(int),1,file);
	fwrite(&temp_species.status,STATUS_SIZE*sizeof(char),1,file);
	fwrite(&temp_species.location[0],sizeof(float),1,file);
	fwrite(&temp_species.location[1],sizeof(float),1,file);;;
	fwrite(&temp_species.human_impact,sizeof(int),1,file);
};

void reportSpecies(FILE *file){
	printf("reportSpecies");
};

void searchSpecies(FILE *file){
	printf("searchSpecies");
};

void registerInfoSpecies(FILE *file){
	printf("registerInfoSpecies");
};
