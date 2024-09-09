#include "./speciesRoutines.h"
#include "./funcoesFornecidas.h"


/* 
 * registerSpecies (COMANDO 1)
 *
 * Registra uma espécie a partir do teclado(stdin) no arquivo binário "filename".
 *
 * Antes de adicionar a espécie ao arquivo, verifica se o ID dela é unico.
 * Se não existir, adiciona a espécie normalmente no arquivo "filename".
 * Se existir o ID, não registra a espécie no arquivo e pula para a próxima
 * entrada do teclado.
 */

void registerSpecies(FILE *file, int *idTracker, int *idCount){
  Species temp_species;
  memset(&temp_species, '$', sizeof(temp_species));

  scanf("%d", &temp_species.species_id);
  readline(temp_species.name);
  readline(temp_species.scientific_name);
  scanf("%d", &temp_species.population);
  readline(temp_species.status);
  scanf("%f %f", &temp_species.location[0], &temp_species.location[1]);
  scanf("%d", &temp_species.human_impact);
  
  int idUnique = 1;
  for(int i = 0; i < *idCount; i++){
    if(temp_species.species_id == idTracker[i]){
      printf("Informação já inserida no arquivo\n");
      idUnique = 0;
      break;
    }
  }
  
  if(idUnique == 1){
    idTracker[*idCount] = temp_species.species_id;
    *idCount = *idCount + 1;

    fwrite(&temp_species.species_id,sizeof(int),1,file);
    fwrite(&temp_species.name,NAME_SIZE*sizeof(char),1,file);
    fwrite(&temp_species.scientific_name,SCIENTIFIC_SIZE*sizeof(char),1,file);
    fwrite(&temp_species.population,sizeof(int),1,file);
    fwrite(&temp_species.status,STATUS_SIZE*sizeof(char),1,file);
    fwrite(&temp_species.location[0],sizeof(float),1,file);
    fwrite(&temp_species.location[1],sizeof(float),1,file);
    fwrite(&temp_species.human_impact,sizeof(int),1,file);
  }
};


/* reportSpecies (COMANDO 2)
 *
 * Dada uma certa posição do ponteiro file, imprime na tela todo
 * o registro da espécie.
 */

void reportSpecies(FILE *file){
  Species temp_species;
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

/* 
 * searchSpeciesRRN (COMANDO 3)
 *
 * Dado um RRN, procura o registro que ocupa o RRN passado.
 *
 * Caso o RRN seja invalido, o procedimento é encerrado.
 */

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

/* 
 * registerInfoSpecies (COMANDO 4)
 *
 *  Pede um ID, o número n de informações a serem modificadas.
 *  Para cada n, lê-se uma instrução e o dado referente
 */

void registerInfoSpecies(FILE *file){ 
  Species temp_species;

  int jump_size = sizeof(temp_species.species_id) + sizeof(temp_species.name) + sizeof(temp_species.scientific_name) + sizeof(temp_species.population) + sizeof(temp_species.status) + sizeof(temp_species.location) + sizeof(temp_species.human_impact);


  // leitura do ID do comando
  int target_id;
  if(DEBUG == 1) printf("TARGET_ID: ");
  scanf("%d", &target_id);

  fread(&temp_species.species_id, sizeof(int), 1, file);
  fread(temp_species.name, NAME_SIZE * sizeof(char), 1, file);
  fread(temp_species.scientific_name, SCIENTIFIC_SIZE * sizeof(char), 1, file);
  fread(&temp_species.population, sizeof(int), 1, file);
  fread(temp_species.status, STATUS_SIZE * sizeof(char), 1, file);
  fread(&temp_species.location, sizeof(float), 2, file);
  fread(&temp_species.human_impact, sizeof(int), 1, file);

  while(temp_species.species_id != target_id && !feof(file)){
    fread(&temp_species.species_id, sizeof(int), 1, file);
    fread(temp_species.name, NAME_SIZE * sizeof(char), 1, file);
    fread(temp_species.scientific_name, SCIENTIFIC_SIZE * sizeof(char), 1, file);
    fread(&temp_species.population, sizeof(int), 1, file);
    fread(temp_species.status, STATUS_SIZE * sizeof(char), 1, file);
    fread(&temp_species.location, sizeof(float), 2, file);
    fread(&temp_species.human_impact, sizeof(int), 1, file);
  }
  if(DEBUG == 1) printf("TEMP_SPECIES_ID: %d", temp_species.species_id);

  if(temp_species.species_id != target_id){
    printf("Espécie não encontrada\n");
    return;
  }

  // lê quantidade de informações
  int ttl_changes;
  if(DEBUG == 1) printf("\nTTL_CHANGES: ");
  scanf("%d", &ttl_changes);

  char instruction[20];
  int instruction_cmd;
  int hi=-1, population=-1;
  char status[STATUS_SIZE];
  memset(&status, '$', STATUS_SIZE);

  while(ttl_changes--){
    if(DEBUG == 1) printf("INSTRUCTION: ");
    readline(instruction);
    if(strcmp(instruction,"STATUS") == 0){
      instruction_cmd = 1;
    }
    if(strcmp(instruction,"HUMAN IMPACT") == 0){
      instruction_cmd = 2;
    }
    if(strcmp(instruction,"POPULATION") == 0){
      instruction_cmd = 3;
    }
    switch(instruction_cmd){
      case(1):{
		if(strcmp(temp_species.status,"NULO") == 0){
		  readline(status);
		  if(DEBUG == 1){ printf("cur_status: %s\n", temp_species.status);
		    printf("%s", status);
		  }
		  strcpy(temp_species.status,status);
		}
		else{
		  if(DEBUG == 1) printf("cur_status: %s\n", temp_species.status);
		  printf("Informação já inserida no arquivo\n");
		}
		break;
	      }

      case(2):{
		if(DEBUG == 1) printf("hi: ");
		if(!temp_species.human_impact){
		  scanf("%d", &hi);
		}
		else{printf("Informação já inserida no arquivo\n");}
		break;
	      }

      case(3):{
		if(DEBUG == 1) printf("population: ");
		if(!temp_species.population){
		  scanf("%d", &population);
		}
		else{printf("Informação já inserida no arquivo\n");}
		break;
	      }    
    }

    // escrita dos dados no arquivo
    int current_pos = ftell(file);
    fseek(file, current_pos - jump_size, SEEK_SET);

    fwrite(&temp_species.species_id,sizeof(int),1,file);
    fwrite(&temp_species.name,NAME_SIZE*sizeof(char),1,file);
    fwrite(&temp_species.scientific_name,SCIENTIFIC_SIZE*sizeof(char),1,file);
    if(population != -1){
      fwrite(&population,sizeof(int),1,file);
    }
    else{
      fwrite(&temp_species.population,sizeof(int),1,file);
    }
    fwrite(&temp_species.status,STATUS_SIZE*sizeof(char),1,file);
    fwrite(&temp_species.location[0],sizeof(float),1,file);
    fwrite(&temp_species.location[1],sizeof(float),1,file);
    if(hi != -1){
      fwrite(&hi,sizeof(int),1,file);
    }
    else{
      fwrite(&temp_species.human_impact,sizeof(int),1,file);
    }
  }
};	
