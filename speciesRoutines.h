#ifndef __SPECIES_ROUTINES__
#define __SPECIES_ROUTINES__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define DEBUG 0
#define NAME_SIZE 41
#define SCIENTIFIC_SIZE 61
#define STATUS_SIZE 9
#define FILLER '$'

typedef struct {
    int species_id;
    char name[NAME_SIZE];
    char scientific_name[SCIENTIFIC_SIZE];
    int population;
    char status[STATUS_SIZE];
    float location[2];
    int human_impact;
} Species;

void registerSpecies(FILE *file);
void reportSpecies(FILE *file);
void searchSpecies(FILE *file);
void registerInfoSpecies(FILE *file);

#endif
