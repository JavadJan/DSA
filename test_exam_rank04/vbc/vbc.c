
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node {
    enum {
        ADD,
        MULTI,
        VAL
    }   type;
    int val;
    struct node *l;
    struct node *r;
}   node;

node    *new_node(node n)
{
    node *ret = calloc(1, sizeof(n));
    if (!ret)
        return (NULL);
    *ret = n;
    return (ret);
}

void    destroy_tree(node *n)
{
    if (!n)
        return ;
    if (n->type != VAL)
    {
        destroy_tree(n->l);
        destroy_tree(n->r);
    }
    free(n);
}

void    unexpected(char c)
{
    if (c)
        printf("Unexpected token '%c'\n", c);
    else
        printf("Unexpected end of file\n");
}

int accept(char **s, char c)
{
	(void)c;
    if (**s)
    {
        (*s)++;
        return (1);
    }
    return (0);
}

int expect(char **s, char c)
{
    if (accept(s, c))
        return (1);
    unexpected(**s);
    return (0);
}
node *parse_add(char **str);
node *parse_multiple(char **str);
node *parse_val(char **str);
//...
node *parse_val(char **str)
{
	node *res;
	node tmp;

	if (**str == '(')
	{
		(*str)++;
		res = parse_add(str);
		if (!res || **str !=')')
		{
			destroy_tree(res);
			unexpected(**str);
			return NULL;
		}
		(*str)++;
		return (res);
	}

	if (isdigit(**str))
	{
		tmp.type = VAL;
		tmp.l = NULL;
		tmp.r = NULL;
		tmp.val = **str - '0';

		res = new_node(tmp);
		(*str)++;
		return (res);
	}
	unexpected(**str);
	return(NULL);
}

node *parse_multiple(char **str)
{
	node *left;
	node *right;
	node tmp;

	left = parse_val(str);
	if (!left)
	{
		return (NULL);
	}

	while (**str == '*')
	{
		(*str)++; // jump *
		right = parse_val(str);
		if (!right)
		{
			destroy_tree(left);
			return (NULL);
		}
		tmp.r = right;
		tmp.l = left;
		tmp.val = 0;
		tmp.type = MULTI;
		left = new_node(tmp);
		if (!left)
		{
			destroy_tree(right);
			return (NULL);
		}
	}
	return (left);
}
node *parse_add(char **str)
{
	node *left;
	node *right;
	node tmp;
	left = parse_multiple(str); // fill left,
	while (**str == '+')
	{
		(*str)++;
		right = parse_multiple(str); // fill right
		if (!right)
		{
			destroy_tree(left);
			return (NULL);
		}
		tmp.type = ADD;
		tmp.l = left;
		tmp.r = right;
		tmp.val = 0;
		left = new_node(tmp); // create current and pass as left
		if (!left) 
		{
			destroy_tree(right);
			return (NULL);
		}
	}
	return (left);
}

//node *parser(char *s)
//{
//	if (*s == '+')
//		return (parse_add(s));
//	else if (*s == '*')
//		return (parse_multiple(s));
//	else if (isdigit(atoi(&(*s))))
//		return (parse_val(s));
//	else
//		return NULL;
//}
node    *parse_expr(char *s)
{
    //...
	node *ret;
	ret = parse_add(&s);
	if (!ret)
		return (NULL);
    if (*s) 
    {
        destroy_tree(ret);
        return (NULL);
    }
    return (ret);
}

int eval_tree(node *tree)
{
    switch (tree->type)
    {
        case ADD:
            return (eval_tree(tree->l) + eval_tree(tree->r));
        case MULTI:
            return (eval_tree(tree->l) * eval_tree(tree->r));
        case VAL:
            return (tree->val);
    }
	return 0;
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
    node *tree = parse_expr(argv[1]);
	printf("TEST\n");
    if (!tree)
        return (1);
    printf("%d\n", eval_tree(tree));
    destroy_tree(tree);
}