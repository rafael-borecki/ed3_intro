#ifndef __SPECIES_ROUTINES__
#define __SPECIES_ROUTINES__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
 * Inicialização de macros para a execução do programa.
 */

#define DEBUG 0
#define NAME_SIZE 41
#define SCIENTIFIC_SIZE 61
#define STATUS_SIZE 9
#define FILLER '$'

/* 
 * Inicialização da struct Species, conforme definido
 * no documento.
 */


typedef struct {
  int species_id;
  char name[NAME_SIZE];
  char scientific_name[SCIENTIFIC_SIZE];
  int population;
  char status[STATUS_SIZE];
  float location[2];
  int human_impact;
} Species;

/*
 * Definição da funções que serão utilizadas pelo
 * fluxo do programa, em ordem, respectivamente, 
 * as funções do caso 1,2,3,4.
 */

void registerSpecies(FILE *file, int* idTracker, int *idCount);
void reportSpecies(FILE *file);
void searchSpecies(FILE *file);
void registerInfoSpecies(FILE *file);

#endif
