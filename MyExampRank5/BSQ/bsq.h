#ifndef BSQ_H
#define BSQ_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_map
{
    int rows;
    int cols;
    char empty;
    char obstacle;
    char full;
    char **grid;
	int i;
	int j;
} t_map;

//int     read_map(FILE *fp, t_map *map);
//int     solve_bsq(t_map *map);
//void    free_map(t_map *map);
//int     validate_map(t_map *map);


#endif