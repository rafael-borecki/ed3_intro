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
  //fflush(stdout);
  Species temp_species;
  fread(&temp_species.species_id, sizeof(int), 1, file);
  fread(temp_species.name, sizeof(char), NAME_SIZE, file);
  fread(temp_species.scientific_name, sizeof(char), SCIENTIFIC_SIZE, file);
  fread(&temp_species.population, sizeof(int), 1, file);
  fread(temp_species.status, sizeof(char), STATUS_SIZE, file);
  fread(&temp_species.location, sizeof(float), 2, file);
  fread(&temp_species.human_impact, sizeof(int), 1, file);

  printf("ID: %d\n",temp_species.species_id);
  printf("Nome: %s\n",temp_species.name);
  printf("Nome Científico: %s\n",temp_species.scientific_name);
  if(temp_species.population)
    printf("População: %d\n",temp_species.population);
  else printf("População: NULO\n");
  printf("Status: %s\n",temp_species.status);
  printf("Localização: (%.2f, %.2f)\n",temp_species.location[0],temp_species.location[1]);
  if (temp_species.human_impact)
    printf("Impacto Humano: %d\n",temp_species.human_impact);
  else printf("Impacto Humano: NULO\n");
};

void searchSpecies(FILE *file){
  Species temp_species;
  int rrn;
  scanf("%d", &rrn);
  int jump_size = sizeof(temp_species.species_id) + sizeof(temp_species.name) + sizeof(temp_species.scientific_name) + sizeof(temp_species.population) + sizeof(temp_species.status) + sizeof(temp_species.location) + sizeof(temp_species.human_impact);

  fseek(file, 0, SEEK_END);
  int max_jump = ftell(file) / jump_size;
  fseek(file, 0, SEEK_SET);
  
  if(rrn > max_jump){
    printf("Espécie não encontrada");
    return;
  }

  if(fseek(file, rrn * jump_size, SEEK_SET) != 0) {
    printf("Espécie não encontrada");
    return;
  }

  //if (DEBUG == 1) printf("\nSIZEOF STRUCT: %d\n", sizeof(temp_species));
  //if(fread(&temp_species, sizeof(temp_species), 1, file) != 1) {
  // printf("Espécie não encontrada\n");
  //  return;
  //}

  fread(&temp_species.species_id, sizeof(int), 1, file);
  fread(temp_species.name, NAME_SIZE * sizeof(char), 1, file);
  fread(temp_species.scientific_name, SCIENTIFIC_SIZE * sizeof(char), 1, file);
  fread(&temp_species.population, sizeof(int), 1, file);
  fread(temp_species.status, STATUS_SIZE * sizeof(char), 1, file);
  fread(&temp_species.location, sizeof(float), 2, file);
  fread(&temp_species.human_impact, sizeof(int), 1, file);

  printf("ID: %d\n",temp_species.species_id);
  printf("Nome: %s\n",temp_species.name);
  printf("Nome Científico: %s\n",temp_species.scientific_name);
  if(temp_species.population)
    printf("População: %d\n",temp_species.population);
  else printf("População: NULO\n");
  printf("Status: %s\n",temp_species.status);
  printf("Localização: (%.2f, %.2f)\n",temp_species.location[0],temp_species.location[1]);
  if (temp_species.human_impact)
    printf("Impacto Humano: %d\n",temp_species.human_impact);
  else printf("Impacto Humano: NULO\n");
};

void registerInfoSpecies(FILE *file){
  printf("registerInfoSpecies");
};
