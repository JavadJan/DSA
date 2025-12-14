#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

//! Define the json structure with three possible types: MAP, INTEGER, STRING
typedef struct json {
    enum {
        MAP,
        INTEGER,
        STRING
    } type; // indicates the current type of JSON value
    union {
        struct {
            struct pair *data; // dynamic array of key-value pairs if type = MAP
            size_t      size;  // number of pairs in the map
        } map;
        int     integer; // integer value if type = INTEGER
        char    *string; // pointer to string if type = STRING
    };
} json;

//! Define a pair (key-value) used inside a MAP object
typedef struct pair {
    char *key;  // key is always a string
    json value; // value is another JSON object
} pair;

#define BUFFER_SIZE 99999 // maximum size for string buffer

// Forward declarations
int     peek(FILE *stream);
void    unexpected(FILE *stream);
int     expect(FILE *stream, char c);
void    free_json(json j);
int     argo(json *dst, FILE *stream);
int     accept(FILE *stream, char c);

int     parse_string(json *dst, FILE *stream);
int     parse_int(json *dst, FILE *stream);
int     parse_map(json *dst, FILE *stream);
int     parser(json *dst, FILE *stream);
static char *ft_strdup(char *str);

//! Auxiliary function to duplicate a string into heap memory
static char *ft_strdup(char *str)
{
    size_t str_s = 0;           // length of string
    while (str[str_s])          // count until null terminator
        str_s++;
    char *str_cpy = malloc(str_s + 1); // allocate memory (+1 for '\0')
    if (!str_cpy)
        return NULL;
    for (size_t i = 0; i <= str_s; i++) // copy including '\0'
        str_cpy[i] = str[i];
    return str_cpy;
}

//! Skip whitespace characters in the input stream
void skip_ws(FILE *stream)
{
    int c;
    while (isspace(c = getc(stream)))
        ;
    ungetc(c, stream);
}


//! Parse an integer type from input stream
int parse_int(json *dst, FILE *stream)
{
    int n;
	skip_ws(stream);
    if (fscanf(stream, "%d", &n) == 1) // try to read integer
    {
        dst->type = INTEGER;   // set type
        dst->integer = n;      // store value
        return 1;              // success
    }
    unexpected(stream);        // if reading fails
    return -1;                 // error
}

//! Parse a string type from input stream
int parse_string(json *dst, FILE *stream)
{
    char buffer[BUFFER_SIZE]; // temporary buffer for string
    char c;
    int i;

	skip_ws(stream);
    if (!expect(stream, '"')) // must start with double quote
        return -1;
    i = 0;
    while (1)
    {
        c = getc(stream); // read one character
        if (c == EOF)     // error: unexpected EOF
        {
            unexpected(stream);
            return -1;
        }
        if (c == '"')     // closing quote found → end of string
            break;
        if (c == '\\')    // escape sequence detected
        {
            c = getc(stream); // read escaped char
            if (c == EOF)
            {
                unexpected(stream);
                return -1;
            }
        }
        if (i >= BUFFER_SIZE - 1) // avoid overflow
        {
            unexpected(stream);
            return -1;
        }
        buffer[i++] = c; // store char into buffer
    }
    buffer[i] = '\0'; // terminate string
    dst->type = STRING;
    dst->string = ft_strdup(buffer); // duplicate string into heap
    if (!dst->string)
        return -1;
    return 1; // success
}

//! Parse a JSON map/object { "key": value, ... }
int parse_map(json *dst, FILE *stream)
{
    pair *items = NULL;   // dynamic array of key-value pairs
    size_t size = 0;      // number of parsed pairs
    json key;             // temporary json for key

	skip_ws(stream);
    if (!expect(stream, '{')) // must start with '{'
        return -1;

    // Special case: empty object "{}"
    if (accept(stream, '}'))
    {
        dst->type = MAP;
        dst->map.size = 0;
        dst->map.data = NULL;
        return 1;
    }

    while (1) // loop until closing '}'
    {
        // parse the key as a string
        if (parse_string(&key, stream) == -1)
        {
            if (items)
                free(items); // cleanup if error
            return -1;
        }

        // expect colon after key
        if (!expect(stream, ':'))
        {
            free(key.string);
            if (items)
                free(items);
            return -1;
        }

        // allocate space for new pair
        pair *tmp = realloc(items, sizeof(pair) * (size + 1));
        if (!tmp)
        {
            free(key.string);
            for (size_t i = 0; i < size; i++)
            {
                free(items[i].key);
                free_json(items[i].value);
            }
            free(items);
            return -1;
        }
        items = tmp;

        // parse value recursively
        if (parser(&items[size].value, stream) == -1)
        {
            free(key.string);
            for (size_t i = 0; i < size; i++)
            {
                free(items[i].key);
                free_json(items[i].value);
            }
            free(items);
            return -1;
        }

        // assign key
        items[size].key = key.string;
        size++;

        // if next char is comma → continue with next pair
        if (accept(stream, ','))
            continue;
        // if next char is closing brace → end of object
        else if (accept(stream, '}'))
        {
            dst->type = MAP;
            dst->map.size = size;
            dst->map.data = items;
            return 1;
        }
		
        else
        {
            // unexpected token → error
            unexpected(stream);
            for (size_t i = 0; i < size; i++)
            {
                free(items[i].key);
                free_json(items[i].value);
            }
            free(items);
            return -1;
        }
    }
}

//! Dispatcher: decides what kind of JSON value to parse next
int parser(json *dst, FILE *stream)
{
	skip_ws(stream);
    int c = peek(stream); // look at next char without consuming it
    if (c == '"')
        return parse_string(dst, stream); // string
    else if (isdigit(c) || c == '-')
        return parse_int(dst, stream);    // number
    else if (c == '{')
        return parse_map(dst, stream);    // map/object
    else
    {
        unexpected(stream);               // unknown token
        return -1;
    }
}

//! Utility: peek at next char
int peek(FILE *stream)
{
    int c = getc(stream);
    ungetc(c, stream);
    return c;
}

//! Print an unexpected token error message
void unexpected(FILE *stream)
{
    int p = peek(stream);
    if (p != EOF)
        printf("unexpected token '%d'\n", p);
    else
        printf("unexpected end of input\n");
}

//! Utility: accept one char if it matches expected
int accept(FILE *stream, char c)
{
    if (peek(stream) == c)
    {
        (void)getc(stream);
        return 1;
    }
    return 0;
}

//! Utility: expect one char, else error
int expect(FILE *stream, char c)
{
    if (accept(stream, c))
        return 1;
    unexpected(stream);
    return 0;
}

//! Free a JSON structure recursively
void free_json(json j)
{
    switch (j.type)
    {
        case MAP:
            for (size_t i = 0; i < j.map.size; i++)
            {
                free(j.map.data[i].key);        // free key
                free_json(j.map.data[i].value); // free value recursively
            }
            free(j.map.data);                   // free array of pairs
            break;
        case STRING:
            free(j.string);                     // free string
            break;
        default:
            break;                              // integers need no free
    }
}

//! Serialize JSON back into textual form
void serialize(json j)
{
    switch (j.type)
    {
        case INTEGER:
            printf("%d", j.integer); // print number
            break;
        case STRING:
            putchar('"');
            for (int i = 0; j.string[i]; i++)
            {
                if (j.string[i] == '\\' || j.string[i] == '"')
                    putchar('\\'); // escape necessary chars
                putchar(j.string[i]);
            }
            putchar('"');
            break;
        case MAP:
            putchar('{');
            for (size_t i = 0; i < j.map.size; i++)
            {
                if (i != 0)
                    putchar(',');
                serialize((json){.type = STRING, .string = j.map.data[i].key}); // print key
                putchar(':');
                serialize(j.map.data[i].value); // print value
            }
            putchar('}');
            break;
    }
}

//! Top-level entry to parser
int argo(json *dst, FILE *stream)
{
    return parser(dst, stream);
}

//! Main entry point
int main(int argc, char **argv)
{
    if (argc != 2) // must provide exactly one filename
        return 1;
    char *filename = argv[1];
    FILE *stream = fopen(filename, "r"); // open file
    if (!stream)
    {
        perror("fopen");
        return 1;
    }
    json file; // parsed JSON object
    if (argo(&file, stream) != 1) // parse failure
    {
        fclose(stream);
        return 1;
    }
    serialize(file);   // print parsed JSON
    printf("\n");
    free_json(file);   // cleanup memory
    fclose(stream);    // close file
    return 0;
}
