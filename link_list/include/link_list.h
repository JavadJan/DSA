#ifndef LINK_LIST_H
# define LINK_LIST_H
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
struct			Node
{
	int			data;
	struct Node	*next;
};
void			add_at_end_lst(struct Node **head, struct Node *node);
struct Node		*create_new_node(int data);
struct Node		*last_node(struct Node *head);
void			display(struct Node *head);
void			recursive_display(struct Node *head);
int				count_recursively(struct Node *head);
struct Node		*search(struct Node *p, int key);
struct Node		*improved_search(struct Node **p, int key);
struct Node		*Rsearch(struct Node *p, int key);
struct Node		*rmax(struct Node *p);
struct Node		*max(struct Node *p);
int				sum(struct Node *p);
int				rsum(struct Node *p);
void			insert(struct Node **head, int index, int value);
void			insert_in_sorted(struct Node **head, struct Node *new);
void			delete_first(struct Node **head);
void			delete_at(struct Node **head, int index);
void			delete_at_index_tow(struct Node **head, int index);
char*			check_sorted(struct Node *p);
bool			rcheck_sorted(struct Node *p);
bool			check_sorted2(struct Node *p);
void			delete_dup(struct Node **head);
void			reverse_link(struct Node **head);
void		reverse_link_sliding(struct Node **head);
void		concatinate(struct Node **new, struct Node **head);
struct Node *merge_list(struct Node *first, struct Node *second);
bool			isLoop(struct Node *p);
void	r_circular_display(struct Node *head);
void	circular_display(struct Node *head);

#endif