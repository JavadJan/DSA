
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

typedef struct	json {
	enum {
		MAP,
		INTEGER,
		STRING
	} type;
	union {
		struct {
			struct pair	*data;
			size_t		size;
		} map;
		int	integer;
		char	*string;
	};
}	json;

typedef struct	pair {
	char	*key;
	json	value;
}	pair;

int parser(json *dst, FILE *stream);
int parse_string(json *dst, FILE *stream);
int parse_map(json *dst, FILE *stream);
int parse_int(json *dst, FILE *stream);
void skip_ws(FILE *stream);

int	peek(FILE *stream)
{
	int	c = getc(stream);
	ungetc(c, stream);
	return c;
}

void	unexpected(FILE *stream)
{
	char p = peek(stream);
    if (p != EOF)
        printf("unexpected token '%c'\n", p);
    else
        printf("unexpected end of input\n");
}

int	accept(FILE *stream, char c)
{
	skip_ws(stream);
	if (peek(stream) == c)
	{
		(void)getc(stream);
		skip_ws(stream);
		return 1;
	}
	return 0;
}

int	expect(FILE *stream, char c)
{
	if (accept(stream, c))
		return 1;
	unexpected(stream);
	return 0;
}

void	free_json(json j)
{
	switch (j.type)
	{
		case MAP:
			for (size_t i = 0; i < j.map.size; i++)
			{
				free(j.map.data[i].key);
				free_json(j.map.data[i].value);
			}
			free(j.map.data);
			break ;
		case STRING:
			free(j.string);
			break ;
		default:
			break ;
	}
}

void	serialize(json j)
{
	switch (j.type)
	{
		case INTEGER:
			printf("%d", j.integer);
			break ;
		case STRING:
			putchar('"');
			for (int i = 0; j.string[i]; i++)
			{
				if (j.string[i] == '\\' || j.string[i] == '"')
					putchar('\\');
				putchar(j.string[i]);
			}
			putchar('"');
			break ;
		case MAP:
			putchar('{');
			for (size_t i = 0; i < j.map.size; i++)
			{
				if (i != 0)
					putchar(',');
				serialize((json){.type = STRING, .string = j.map.data[i].key});
				putchar(':');
				serialize(j.map.data[i].value);
			}
			putchar('}');
			break ;
	}
}
void skip_ws(FILE *stream) {
    int c;
    while (isspace(c = getc(stream))) { }
    ungetc(c, stream);
}

static char *ft_strsup(char arr[], int size)
{
	char *tmp = malloc(size + 1);
	if (!tmp)
		return NULL;
	for (int i = 0; i < size; i++) {
		tmp[i] = arr[i];
	}
	tmp[size] = '\0';
	return tmp;

}

#define BUFFER_SIZE 99999

int parse_string(json *dst, FILE *stream)
{
	int size = 0;
	char arr[BUFFER_SIZE];
	fflush(stdout);
	skip_ws(stream);
	if (!expect(stream, '"'))
		return (-1);
	char c;
	while (1)
	{
		skip_ws(stream);
		c = getc(stream);
		if (c == EOF) // did not close
		{
			unexpected(stream);
			return (-1);
		}
		if (c == '"')
			break;
		skip_ws(stream);
		if (c == '\\')
		{
			c = getc(stream); // cause to jump
			if (c == EOF)
			{
				unexpected(stream);
				return (-1);
			}
		}
		
		arr[size] = c;
		size++;
	}
	skip_ws(stream);
	arr[size] = '\0';
	dst->type = STRING;
	dst->string = ft_strsup(arr, size);
	if (!dst->string)
		return(-1);
	return (1);
}

int parse_map(json *dst, FILE *stream)
{
	int size = 0;
	pair *items = NULL;
	json key;

	/* {"name":"javad"} */
	if (!expect(stream, '{'))
	{
		//unexpected(stream);
		return (-1);
	}
	skip_ws(stream);
	if (accept(stream, '}'))
	{
		dst->type = MAP;
		dst->map.size = 0;
		dst->map.data = NULL;
		return 1;
	}
	skip_ws(stream);

	while (1)
	{
		/* "name" */
		if (parse_string(&key, stream) == -1)
		{
			if (items)
				free(items);
			return (-1);
		}
		/* : */
		if (!expect(stream, ':'))
		{
			free(key.string);
			if (items)
				free(items);
			return (-1);
		}
		skip_ws(stream);
		// allocate space for new pair
		pair *tmp = realloc(items, sizeof(pair) * (size + 1));
		if (!tmp)
		{
			free(key.string);
			for (int i = 0; i < size; i++)
			{
				free(items[i].key);
				free_json(items[i].value);
			}
			free(items);
			return (-1);
		}
		items = tmp;
		/* "-----":{value} */
		// value can be again integer or string or {}
		if (parser(&items[size].value, stream) == -1)
		{
			free(key.string);
			for (int i = 0; i < size; i++)
			{
				free(items[i].key);
				free_json(items[i].value);
			}
			free(items);
			return (-1);
		}
		items[size].key = key.string;
		size++;
		if (accept(stream, ','))
			continue;
		else if (accept(stream, '}'))
		{
			dst->type = MAP;
			dst->map.data = items;
			dst->map.size = size;
			return (1);
		}
		else
		{
			unexpected(stream);
			for (int i = 0; i < size; i++)
			{
				free(items[i].key);
				free_json(items[i].value);
			}
			free(items);
			return (-1);
		}
	}
	return (1);
}
int parse_int(json *dst, FILE *stream)
{
	int n;
	skip_ws(stream);
	if (fscanf(stream, "%d", &n) == 1) // 
	{
		dst->type = INTEGER;
		dst->integer = n;
		return (1);
	}
	unexpected(stream);
	return (-1);
}
int parser(json *dst, FILE *stream)
{
	skip_ws(stream);
	char c = peek(stream);
	if (c == '"')
		return (parse_string(dst, stream));
	else if (c == '{')
		return (parse_map(dst, stream));
	else if (isdigit(c) || c == '-')
		return (parse_int(dst, stream));
	else{
		unexpected(stream);
		return (-1);
	}
}

int argo(json *dst, FILE *stream)
{
	return (parser(dst, stream));
}
int	main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	(void)argc;
	char *filename = argv[1];
	FILE *stream = fopen(filename, "r");
	json	file;
	fflush(stdout);
	if (argo (&file, stream) != 1)
	{
		free_json(file);
		return 1;
	}
	serialize(file);
	printf("\n");
}