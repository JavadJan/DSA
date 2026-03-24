#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


struct Pen {
    int x;
    int y;
    int down;   // 1 = pen down, 0 = pen up
};

struct Board {
    int width;
    int height;
    int iter;

    struct Pen pen;

    char **cells;   // current board
    char **next;    // next iteration board
};

int initConfig(struct Board *board)
{
    char buf[1024];
    int n;
    while ((n = read(0, buf, 1024)) > 0)
    {
        for (int i = 0; i < n; i++)
        {
            char c = buf[i];

            // here you will handle: w a s d x
            // update pen, update position, draw, etc.
            if (c == 'w' && board->pen.y > 0)
                board->pen.y--;
            else if (c == 's' && board->pen.y < board->height - 1)
                board->pen.y++;
            else if (c == 'a' && board->pen.x > 0)
                board->pen.x--;
            else if (c == 'd' && board->pen.x < board->width - 1)
                board->pen.x++;
            else if (c == 'x')
            {
                board->pen.down = !board->pen.down;
                if (board->pen.down) // if pen down then become 1? 
                    board->cells[board->pen.y][board->pen.x] = 1;
            }
			else
			{
				return 0;		
			}
            if (board->pen.down)
                board->cells[board->pen.y][board->pen.x] = 1;
        }
    }
	return 1;
}

int countNeighbors(struct Board *board, int y, int x)
{
    int count = 0;
    for (int dy = -1; dy <= 1; dy++)
    {
        for (int dx = -1; dx <= 1; dx++)
        {
            if (dx == 0 && dy == 0)
                continue;
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < board->width && ny >= 0 && ny < board->height)
                count += board->cells[ny][nx]; // this is the value
        }
    }
    return count;
}

void ConwayGame(struct Board *board)
{
    board->next = calloc(board->height, sizeof(char *));
    if (!board->next)
        return;
    for (int i = 0; i < board->height; i++)
    {
        board->next[i] = calloc(board->width, sizeof(char));
        if (!board->next[i])
            return;
    }

    for (int iter = 0; iter < board->iter; iter++)
    {
        for (int y = 0; y < board->height; y++)
        {
            for (int x = 0; x < board->width; x++)
            {
                int neighbors = countNeighbors(board, y, x);
                if (board->cells[y][x]) // if it was drew
                    board->next[y][x] = (neighbors == 2 || neighbors == 3) ? 1 : 0;
                else
                    board->next[y][x] = (neighbors == 3) ? 1 : 0;
            }
        }
        for (int y = 0; y < board->height; y++)
        {
            for (int x = 0; x < board->width; x++)
                board->cells[y][x] = board->next[y][x];
        }
    }

    for (int i = 0; i < board->height; i++)
        free(board->next[i]);
    free(board->next);
}

void printBoard(struct Board board)
{
    for (int y = 0; y < board.height; y++)
    {
        for (int x = 0; x < board.width; x++)
            putchar(board.cells[y][x] ? 'O' : ' ');
        putchar('\n');
    }
}

void printError(const char * msg)
{
	int i = 0;
    while (msg[i])
    	putchar(msg[i++]);
}
int main(int ac, char *av[])
{
    if (ac != 4)
    {
        //char err[] = "Error in Argument\n";
        printError("Error in Argument\n");
        return 1;
    }

    struct Board board;
    board.width  = atoi(av[1]);
    board.height = atoi(av[2]);
    board.iter   = atoi(av[3]);
    board.pen.x    = 0;
    board.pen.y    = 0;
    board.pen.down    = 0;

    // allocate your board here later
    board.cells = calloc(board.height, sizeof(char *));
    if (!board.cells)
        return 1;
    for (int i = 0; i < board.height; i++)
    {
        board.cells[i] = calloc(board.width, sizeof(char));
        if (!board.cells[i])
            return 1;
    }
	
    // Read until EOF (Ctrl+D)
	if (!initConfig(&board))
	{
		for (int i = 0; i < board.height; i++)
		{
        	free(board.cells[i]);
		}
		free(board.cells);
		printError("Invalid direction\n");
		return 1;
	}
    

    // after EOF: run Game of Life iterations
    ConwayGame(&board);

    // then print final board
    printBoard(board);
	for (int i = 0; i < board.height; i++)
    {
        free(board.cells[i]);
    }
	free(board.cells);
    return 0;
}
