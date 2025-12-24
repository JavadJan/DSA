#ifndef AST_H
# define AST_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct ast
{
	int		val;
	char	*left;
	char	*right;
}			t_ast;

#endif