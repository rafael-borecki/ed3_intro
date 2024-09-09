#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./funcoesFornecidas.h"
#include "./speciesRoutines.h"

int main(){
  int command;
  char filename[30];
  //scanf("%d", &command);
  //char dump_space = getchar();
  //readline(filename);
  scanf("%d %s", &command, filename);	//RUNCODES
  //setbuf(stdin, NULL);

  switch(command){
    case(1):{
	      int n;
	      scanf("%d", &n);
	      FILE* file = fopen(filename, "wb");
	      if (!file){
		printf("Falha no processamento do arquivo");
		return EXIT_FAILURE;
	      }
	      
	      int idCount = 1;
	      int *idTracker = (int*) malloc (n * sizeof(int) + 10 * sizeof(int));
	      for(int i = 0; i < n; i++)
		idTracker[i] = -1;
	      
	      for (int i = 0; i < n; i++){
		registerSpecies(file, idTracker, &idCount);
	      }
	      fclose(file);

	      file = fopen(filename, "rb");
	      if (!file){
		printf("Falha no processamento do arquivo");
		return EXIT_FAILURE;
	      }
	      binarioNaTela(filename);
	      fclose(file);
	      free(idTracker);
	      break;
	    }

    case(2):{
	      FILE* file = fopen(filename, "rb");
	      if (!file){
		printf("Falha no processamento do arquivo");
		return 0;
	      }

	      fseek(file,0,SEEK_END);
	      long int file_end = ftell(file);
	      fseek(file,0,SEEK_SET);

	      while(file_end - ftell(file) > 130){
		reportSpecies(file);
		//if(file_end - ftell(file) > 130
		  printf("\n");
	      }
	      fclose(file);
	      break;
	    }

    case(3):{
	      FILE* file = fopen(filename, "rb");
	      if (!file){
		printf("Falha no processamento do arquivo");
		return EXIT_FAILURE;
	      }
	      searchSpecies(file);
	      printf("\n");
	      fclose(file);
	      break;
	    }

    case(4):{
	      FILE* file = fopen(filename, "rb+");
	      if (!file){
		printf("Falha no processamento do arquivo");
		return EXIT_FAILURE;
	      }
	      registerInfoSpecies(file);
	      fclose(file);

	      file = fopen(filename, "rb");
	      if (!file){
		printf("Falha no processamento do arquivo");
		return EXIT_FAILURE;
	      }
	      binarioNaTela(filename);
	      fclose(file);
	      break;
	    }
  }
  return 0;
}
