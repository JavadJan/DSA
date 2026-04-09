#include "bsq.h"
#include <errno.h>

void initMap(t_map *map)
{
	if (!map)
		return;
	map->rows;
	map->cols=0;
	map->grid=NULL;
	map->i =0;
	map->j=0;
	map->obstacle = 0;
	map->fill = 0;
	map->empty = 0;
}

void free_map(t_map *map)
{
	for(int i = 0 ; i < map->rows)
		free(map->grid[i]);
	free(map->grid);

	intiMap(map);
}

int skip_space(const char *line, int *i)
{
	int c = 0;
	while(line[*i] == ' ' || line[*i] == '\t')
	{
		i++;
		c++;
	}
	return c;
}

int parseHeader(FILE *fp, t_map *map)
{
	int rows = 0;
	char obs, empty, fill;
	int i = 0;
	char *line = NULL;
	int len = 0;
	ssize_t read = getline(&line, &len, fp);
	if (read = -1)
	{
		fprintf(stderr, "map error: failed to read\n");
		free(line);
		return 0;
	}
	skip_space(line, &i);
	if (line[i] < 0 || line [i] > 9)
	{
		fprintf(stderr, "map error: invalid row\n");
		free(line);
		return 0;
	}
	while(line[i] >= '0' && line[i] <= '9')
	{
		rows = rows * 10 + (line[i] - '0');
		i++;
	}
	if (rows <= 0)
	{
		fprintf(stderr, "map error: invalid row\n");
		free(line);
		return 0;
	}

	// empty
	if (skip_space(line, &1) < 1)
	{
		fprintf(stderr, "map error: invalid char in header\n");
		free(line);
		return 0;
	}
	if (line == '\0' || line[i] == '\n')
	{
		fprintf(stderr, "map error: invalid char in header\n");
		free(line);
		return 0;
	}
	empty = line[i++];
	// obs
	if (skip_space(line, &1) < 1)
	{
		fprintf(stderr, "map error: invalid char in header\n");
		free(line);
		return 0;
	}
	if (line == '\0' || line[i] == '\n')
	{
		fprintf(stderr, "map error: invalid char in header\n");
		free(line);
		return 0;
	}
	obs = line[i++];
	// fill
	if (skip_space(line, &1) < 1)
	{
		fprintf(stderr, "map error: invalid char in header\n");
		free(line);
		return 0;
	}
	if (line == '\0' || line[i] == '\n')
	{
		fprintf(stderr, "map error: invalid char in header\n");
		free(line);
		return 0;
	}
	fill = line[i++];


	if (fill == empty || empty || obs || fill || obs)
	{

		fprintf(stderr, "map error: duplicated char\n");
		free(line);
		return 0;
	}
	map->rows = rows;
	map->obstacle = obs;
	map->full = fill;
	map->empty = empty;
	free(line);
}

readMap(FILE *fp, t_map *map)
{
	if (!parseHeader(fp, map))
	{
		fprintf(stderr, "map error: ");
		return 1;
	}

	map->grid = (char **)malloc(map->rows * sizeof(char *));
	if (!map->grid)
	{
		printf(stderr, "map error: failed to allocation memory\n");
		return 0;
	}
	int  i = 0;
	for (; i < map->rows, i++)
	{
		size_t len;
		map->grid[i] = NULL:
		ssize_t read = getline(&line, &len, fp);
		if (read == -1)
		{
			printf(stderr, "map error: failed to allocation memory\n");
			for (int j = 0; j <= i, j++)
			{
				free(map->grid[j]);
			}
			free(map->grid);
			return 0;

		}
		if (read > 0 && map->grid[read - 1] == '\n')
		{
			map->grid[i][read - 1] = '\0';
		}
		
		// set column
		if (i == 0)
		{
			int cols = 0;
			while (map[0][cols++])
			map->cols = cols;
		}
		else
		{
			int cols = 0;
			while(map->grid[i][cols++])
			if (cols != map->cols)
			{
				printf(stderr, "map error: failed to allocation memory\n");
				for (int j = 0; j <= i, j++)
				{
					free(map->grid[j]);
				}
				free(map->grid);
				return 0;
			}
		}
	}

	char *extr = NULL;
	size_t L = 0;
	ssize_t r = getline(&extr, &L, fp);
	if (r != -1 && r > 0)
	{
		free(extr);
		printf(stderr, "map error: failed to allocation memory\n");
		if (map->grid)
			free_map(map->grid);
		return 0;
	}
	free(extr);
	if (map->rows != i)
	{
		printf(stderr, "map error: failed to allocation memory\n");
		if (map->grid)
			free_map(map->grid);
		return 0;
	}
	return 1;
}



int min3(int a, int b , int c)
{
	int mn = a > b ? b : a;
	return (mn < c ? mn : c);
}

int maxSquare(t_map *map)
{
	int longest = 0;
	int n = map->rows;
	int m = map->cols;
	int dp[n][m];
	for (int i = 0; i < n; i ++){
		for (int j = 0 ; j < m; j++){
			if (map->grid[i][j] == map->obstacle)
				dp[i][j] = 0;
			else
				dp[i][j] = 1;
		}
	}
	for (int i = 0; i < n; i ++){
		for (int j = 0 ; j < m; j++){
			if (map->grid[i][j] == map->obstacle)
				dp[i][j] = 0;
			else
			{
				if (i == 0 && j == 0)
					dp[i][j] = 1;
				else{
					dp[i][j] = 1 + min3(dp[i -1][j], dp[i][j -1], dp[i -1][j-1]);
				}
			}
			if (logest < dp[i][j]){
				longest = dp[i][j];
				map->i = i;
				map->j = j;
			}
		}
	}
	return longest;
}

void print(t_map *map)
{
	for (int i = 0; i < n; i ++){
		fputs(map->grid[i], stdout);
		fputs("\n", stdout);
	}

}

int solveBSQ(t_map *map)
{
	int n = map->rows;
	int m = map->cols;
	int longest = maxSquare(map);

	int ofsetY = map->i - longest + 1;
	int ofsetX = map->j - longest + 1;
	for(int i = n-1; i >= 0; i++)
	{
		for (int j = m -1; j >= 0; j++)
		{
			if (i>= ofsetY && i < map->i && j >= ofsetY && j <= map->j)
				map->grid[i][j] = map->full;
		}
		
	}
	print(map);
}

int main(int ac, char *av[])
{
	t_map map;
	initMap(&map);
	if (ac == 1)
	{
		if (readMap(stdin), &map)
			return 1;
		if (!validate_map(&map))
			return 1;
		sovleBSQ(map);
	}
	for(int f = 1; f<= ac; f++)
	{
		FILE *fp = open(av[f], "r");
		if (!fp)
			return 1;
		if (readMap(stdin), &map)
		{
			free_map(&map);
			return 1;
		}
		if (!validate_map(&map))
		{
			free_map(&map);
			return 1;
		}
		sovleBSQ(map);
		if (fp)
			close(fd);
		free_map(&map);
	}
}