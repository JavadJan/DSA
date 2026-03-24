#ifndef LIFE_H
# define LIFE_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


struct pen{
	int x;
	int y;
	bool pen;
}

struct board{
	int hight;
	int width;
	int iter;
	struct pen down;
};



#endif