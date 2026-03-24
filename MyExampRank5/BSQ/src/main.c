#include "../bsq.h"
#include <errno.h>

/* ----------------------------- */
/* 								 */
/* 			READING MAP			 */
/* 								 */
/* ----------------------------- */
void Error(const char *msg)
{
	fprintf(stderr, "%s\n", msg);
}
void inttial_map(t_map *map)
{
	if (!map)
		return;
	map->cols = 0;
	map->rows = 0;
	map->empty = 0;
	map->obstacle = 0;
	map->full = 0;
	map->grid = NULL;

	map->i = 0;
	map->j = 0;
}

// Helper: skip whitespace (space or tab) and count how many
static int skip_whitespace_count(const char *line, int *i)
{
	int count = 0;
	while (line[*i] == ' ' || line[*i] == '\t')
	{
		count++;
		(*i)++;
	}
	return count;
}

// e.g., 9 . o x
int parseHeader(FILE *fp, t_map *map)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read = getline(&line, &len, fp);
	if (read == -1)
	{
		Error("map error : Header");
		free(line);
		return 0;
	}

	int i = 0;
	int rows = 0;
	char empty, obstacle, full;
	// Skip leading whitespace
	skip_whitespace_count(line, &i);

	// Extract rows (number)
	if (line[i] < '0' || line[i] > '9')
	{
		Error("map error : invalid char in header");
		free(line);
		return 0;
	}
	while (line[i] >= '0' && line[i] <= '9')
	{
		rows = rows * 10 + (line[i] - '0');
		i++;
	}

	if (rows <= 0)
	{
		Error("map error : Invalid line");
		free(line);
		return 0;
	}

	// Extract empty character
	if (skip_whitespace_count(line, &i) < 1)
	{
		Error("map error : No seperated space in header");
		free(line);
		return 0;
	}
	if (line[i] == '\0' || line[i] == '\n')
	{
		Error("map error : invalid char in header");
		free(line);
		return 0;
	}
	empty = line[i++];

	// Extract obstacle character
	if (skip_whitespace_count(line, &i) < 1)
	{
		Error("map error : No seperated space in header");
		free(line);
		return 0;
	}
	if (line[i] == '\0' || line[i] == '\n')
	{
		Error("map error : invalid char in header");
		free(line);
		return 0;
	}
	obstacle = line[i++];

	// Extract full character
	if (skip_whitespace_count(line, &i) < 1)
	{
		Error("map error : No seperated space in header");
		free(line);
		return 0;
	}
	if (line[i] == '\0' || line[i] == '\n')
	{
		Error("map error : invalid char in header");
		free(line);
		return 0;
	}
	full = line[i++];

	// Validate uniqueness
	if (empty == obstacle || empty == full || obstacle == full)
	{
		Error("map error : Dupplicated char in header");
		free(line);
		return 0;
	}

	map->rows = rows;
	map->empty = empty;
	map->obstacle = obstacle;
	map->full = full;
	free(line);
	return 1;
}

void printMap(t_map *map)
{
	//printf("rows: %d, empty: %c obstacle: %c full: %c\n", map->rows, map->empty, map->obstacle, map->full);
	for (int i = 0; i < map->rows; i++)
	{
		fputs(map->grid[i], stdout);
		fputs("\n", stdout);
	}
	printf("\n");
}

/* ----------------------------- */
/* 								 */
/* 			FREE MAP			 */
/* 								 */
/* ----------------------------- */
void free_map(t_map *map)
{
	if (!map || !map->grid)
		return;
	for (int i = 0; i < map->rows; i++)
	{
		free(map->grid[i]);
	}
	free(map->grid);
	map->grid = NULL;
	map->rows = 0;
	map->cols = 0;
}

int read_map(FILE *fp, t_map *map)
{
	// parser header
	if (!parseHeader(fp, map))
	{
		return 0;
	}
	// alloc memory
	map->grid = (char ** ) malloc(sizeof(char *) * map->rows);
	if (!map->grid)
	{
		Error("Falied alocation mempry");
		return 0;
	}

	// fill grid
	int i =0;
	for (; i < map->rows; i++)
	{
		size_t len = 0;
		map->grid[i] = NULL;
		ssize_t read = getline(&map->grid[i], &len, fp);
		if (read == -1)
		{
			fprintf(stderr, "Failed to read line %d\n", i);
			for (int j = 0; j < i; j++)
				free(map->grid[j]);
			free(map->grid);
			map->grid = NULL;
			return 0;
		}
		/* remove trailing newline if present */
		if (read > 0 && map->grid[i][read - 1] == '\n')
			map->grid[i][read - 1] = '\0';

		/* set column count from first line */
		if (i == 0)
		{
			int cols = 0;
			while (map->grid[0][cols])
				cols++;
			map->cols = cols;
		}
		else
		{
			int num_cols = 0;
			while(map->grid[i][num_cols])
				num_cols++;
			if (num_cols != map->cols)
			{
				for (int j = 0; j <= i; j++)
					free(map->grid[j]);
				free(map->grid);
				map->grid = NULL;
				Error("map error: invalid header map");
				return 0;
			}
		}
	}

	char *extra = NULL;
	size_t extralen = 0;
	ssize_t extraread = getline(&extra, &extralen, fp);
	if (extraread != -1 && extraread > 0)
	{
		free(extra);
		Error("map error: too many lines");
		if (map->grid)
			free_map(map);
		return 0;
	}
	free(extra);
	if (map->rows != i)
	{
		Error("map error: line map is not enough");
		if (map->grid)
			free_map(map);
		return 0;
	}
	return 1;
}
/* ----------------------------- */
/* 								 */
/* 		VALIDATING MAP			 */
/* 								 */
/* ----------------------------- */
int validate_map(t_map *map)
{
	// no negative rows, 
    if (map->rows <= 0 || map->cols <= 0)
	{
		Error("map error : invalid line in map");
        return 0;
	}

    for (int i = 0; i < map->rows; i++)
    {
        for (int j = 0; j < map->cols; j++)
        {
            char c = map->grid[i][j];
            if (c != map->empty && c != map->obstacle)
            {
				Error("map error : Unknow char in map");
                return 0;
            }
        }
    }

	if ((map->obstacle == map->full) || (map->empty == map->obstacle) || map->empty == map->full)
	{
		Error("error map: Dupplicated char in map");
		return 0;
	}
    return 1;
}

/* ----------------------------- */
/* 								 */
/* 			SOLVE BSQ			 */
/* 								 */
/* ----------------------------- */


static int min(int a, int b, int c)
{
	int min = (a > b) ? b : a;
	return ( min < c ? min : c);
}


int maxSquare(/*vector<vector<int>> &mat*/ t_map *map) {
	//int n = mat.size(), m = mat[0].size();
	int n = map->rows;
	int m = map->cols;
    int longest = 0;
    
    // Create 2d array for tabulation
    //vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    int dp[n][m];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map->grid[i][j] == map->obstacle)
				dp[i][j] = 0;
			else
				dp[i][j] = 1;
		}
	}
	
	// Fill the dp using proper bounds and recurrence
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			
			if (map->grid[i][j] == map->obstacle) {
				dp[i][j] = 0;
			}
			else
			{
				if (i == 0 || j == 0)
				{
					dp[i][j] = 1;
				}
				else 
				{
					dp[i][j] = 1 + min(
						dp[i - 1][j],    // top
						dp[i][j - 1],    // left
						dp[i - 1][j - 1] // top-left
					);
				}
			}
			
			// get bottom-right dimension
			if (longest < dp[i][j])
			{
				map->i = i;
				map->j = j;
				longest = dp[i][j];
			}
		}
	}
	
	return longest;
}

int solve_bsq(t_map *map)
{
	int longest = maxSquare(map);
	//printf("longest: %d i: %d j: %d\n", longest, map->i, map->j);
	int n = map->rows;
	int m = map->cols;
	int offsetX = map->i - longest + 1;
	int offsetY = map->j - longest + 1;

	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = m-1; j >= 0; j--)
		{
			if ((i >= offsetX && j >= offsetY) && (i <= map->i && j <= map->j))
			{
				map->grid[i][j] = map->full;
			}
		}
	}
	
	printMap(map);
	return (0);
}


int main(int argc, char const *argv[])
{
	t_map map;
	inttial_map(&map);
	/* 1. read map */
	// ----------> a. read from stdin
	//printf("TEST\n");
	if (argc == 1)
	{
		if (!read_map(stdin, &map))
			return 1;
		if (!validate_map(&map))
		{
			free_map(&map);
			return 1;
		}
		solve_bsq(&map);
		free_map(&map);
		return 0;
	}
	//printf("TEST1\n");
	// ----------> b. read from file
	for (int f = 1; f < argc; f++)
	{
		
		FILE *fp = fopen(argv[f], "r");
		if (!fp)
		{
			fprintf(stderr, "Failed to open map\n");
			continue;;
		}
		//printf("TEST2\n");
		if (!read_map(fp, &map) )
		{
			//Error("Failed to read map");
			//printf("TEST3\n");
			fclose(fp);
			continue;;
		}
		//printf("TEST3.5\n");
		if (!validate_map(&map))
		{
			//printf("TEST4\n");
			free_map(&map);
			fclose(fp);
			continue;;
		}
		//printf("TEST5\n");
		/* 2. validate map */
		//validate_map(&map);
		/* 3. solve bsq */
		solve_bsq(&map);
		fclose(fp);
		if (f < argc - 1)
			printf("\n");
	}
	
	/* 4. free map */
	free_map(&map);
	return 0;
}
