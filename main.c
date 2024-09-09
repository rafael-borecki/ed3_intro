#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./funcoesFornecidas.h"
#include "./speciesRoutines.h"

int main(){
  int command;
  char filename[30];

  /* 
   * Modo alternativo de ler as entradas com o uso das funções fornecidas,
   * entretanto, não funciona corretamente no runcodes.
   * scanf("%d", &command);
   * char dump_space = getchar();/
    *readline(filename);
  */

  scanf("%d %s", &command, filename);	//RUNCODES

  switch(command){
    
    /*
     * Para o caso 1, o programa deve escrever as informacoes passadas
     * em um arquivo binario. Para isso, é aberto um arquivo em modo
     * de escrita binaria.
     * Em seguida, é inicializado um vetor de contagem, para verificar
     * se foi inserido algum speciesId repetido. Esse fluxo é iterado
     * em um loop de N passos, sendo N um input do usuario.
     * Dentro desse loop, é executada a função registerSpecies(), que 
     * faz o trabalho efetivo de inserir as informações no binário.
     * Por fim, caso o fluxo resulte em sucesso, é realizado o 
     * checksum com a função fornecida binarioNaTela().
     * */

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

  /*
   * Para o caso 2, é aberto arquivo em modo de leitura binário, e é medido
   * o seu comprimento em bytes com ajuda do fseek e ftell. Isso é feito
   * para garantir que a funcao de leitura reportSpecies() não irá ser exe-
   * cutada com redundancia.
   */

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

    /*
     * No caso 3, é aberto um arquivo em modo de leitura binária,
     * sobre o qual é realizada uma busca com base no RRN, com o 
     * uso da função searchSpecies(), que faz o trabalho efetivo
     * de busca. Caso o RRN extrapole o tamanho do arquivo, a fun-
     * ção retorna um erro.
     * */

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

  /*
   * Por fim, no caso 4, o arquivo binario é aberto em modo
   * de leitura e escrita simultânea.
   * Em seguida, através da função registerInfoSpecies(), o
   * programa registra o input do usuario sobre quais informa-
   * ções ele quer alterar, e verifica se atende as condições
   * estipuladas. Caso atenda, o programa sobrescreve no 
   * arquivo os novos dados. 
   * Em seguida, é realizado o checksum com a função forneci-
   * da sobre o binário produzido.
   * */

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
