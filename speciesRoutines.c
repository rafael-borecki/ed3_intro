#include "./speciesRoutines.h"
#include "./funcoesFornecidas.h"

void registerSpecies(FILE *file){
  Species temp_species;
  memset(&temp_species, '$', sizeof(temp_species));
  if(DEBUG == 1) printf("ID: ");
  scanf("%d", &temp_species.species_id);
  if(DEBUG == 1) printf("NAME: ");
  readline(temp_species.name);
  if(DEBUG == 1) printf("SNAME: ");
  readline(temp_species.scientific_name);
  if(DEBUG == 1) printf("POP: ");
  scanf("%d", &temp_species.population);
  if(DEBUG == 1) printf("STATS: ");
  readline(temp_species.status);
  if(DEBUG == 1) printf("XY: ");
  scanf("%f %f", &temp_species.location[0], &temp_species.location[1]);
  if(DEBUG == 1) printf("HI: ");
  scanf("%d", &temp_species.human_impact);

  fwrite(&temp_species.species_id,sizeof(int),1,file);
  fwrite(&temp_species.name,NAME_SIZE*sizeof(char),1,file);
  fwrite(&temp_species.scientific_name,SCIENTIFIC_SIZE*sizeof(char),1,file);
  fwrite(&temp_species.population,sizeof(int),1,file);
  fwrite(&temp_species.status,STATUS_SIZE*sizeof(char),1,file);
  fwrite(&temp_species.location[0],sizeof(float),1,file);
  fwrite(&temp_species.location[1],sizeof(float),1,file);
  fwrite(&temp_species.human_impact,sizeof(int),1,file);
};

void reportSpecies(FILE *file){
  Species temp_species;
  fread(&temp_species.species_id, sizeof(int), 1, file);
  fread(temp_species.name, sizeof(char), NAME_SIZE, file);
  fread(temp_species.scientific_name, sizeof(char), SCIENTIFIC_SIZE, file);
  fread(&temp_species.population, sizeof(int), 1, file);
  fread(temp_species.status, sizeof(char), STATUS_SIZE, file);
  fread(&temp_species.location[0], sizeof(float), 1, file);
  fread(&temp_species.location[1], sizeof(float), 1, file);
  fread(&temp_species.human_impact, sizeof(int), 1, file);

  printf("ID:%d\n",temp_species.species_id);
  printf("Nome:%s\n",temp_species.name);
  printf("Nome Científico:%s\n",temp_species.scientific_name);
  printf("População:%d\n",temp_species.population);
  printf("Status:%s\n",temp_species.status);
  printf("Localização:(%.2f %.2f)\n",temp_species.location[0],temp_species.location[1]);
  printf("Impacto Humano:%d\n\n",temp_species.human_impact);

};

void searchSpecies(FILE *file){
  printf("searchSpecies");
};

void registerInfoSpecies(FILE *file){
  printf("registerInfoSpecies");
};
