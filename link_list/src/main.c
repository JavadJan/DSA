#include "../include/link_list.h"

void test(int *temp)
{
	printf("address of a: %p\n", temp);
	printf("value of a: %d\n", *temp);
	(*temp)++;
}
void	change(int **p, int **q)
{
	printf("chabge derefrence in *p: %p with *q: %p\n", *p, *q);
	int *temp;
	temp = *q;
	*q = *p;
	*p = temp;
}

void change_with_single_pointer(int *p, int *q)
{
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}

struct student {
	char *name;
	int age;
};

#define wrong 0
#define correct 1

void	change_ptr0(struct student *user1, struct student *user2)
{

	struct student *temp;
	temp = user1;
	user1 = user2;
	user2 = temp;
	//here it goes 
	printf("s0:{%s, %d} and s1:{%s, %d}\n", user1->name, user1->age, user2->name, user2->age);
}

void	change_ptr1(struct student **user1, struct student **user2)
{

	struct student *temp;
	temp = (*user1);
	(*user1) = (*user2);
	(*user2) = temp;
	//here it goes 
	printf("s0:{%s, %d} and s1:{%s, %d}\n", (*user1)->name, (*user1)->age, (*user2)->name, (*user2)->age);
}
void	pointer()
{
	int a = 10;
	int b = 20;

	int *p;
	int *q;

	p = &a;
	q = p;
	printf("address of a: %p\n", p);
	printf("address of a: %p\n", q);
	test(p);
	printf("value of a==*p: %d\n", *p);
	// ------------------------------#
	//                               #
	//          change at address    #
	//                               #
	//-------------------------------#
	q = &b;
	printf("address of b: %p\n", &b);
	printf("address of b: %p\n", q);
	printf("value of b: %d\n", *q);
	printf("-----> *q: %d\n", *q);
	printf("-----> *p: %d\n", *p);
	printf("%p <----change this two address-----> %p\n", p, q);
	change(&p, &q);
	printf("%p <----changed this two address-----> %p\n", p, q);
	printf("now the value a and b should be changed: \n");
	printf("-----> *q: %d\n", *q);
	printf("-----> *p: %d\n", *p);
	change_with_single_pointer(p, q);
	printf("-----> *q: %d\n", *q);
	printf("-----> *p: %d\n", *p);

	// ------------------------------#
	//                               #
	//         pointer and struct    #
	//                               #
	//-------------------------------#
	struct student s0 = {"student1", 35};
	struct student s1 = {"student2", 41};
	if (wrong)
	{
		printf("s0:{%s, %d} and s1:{%s, %d}\n", s0.name, s0.age, s1.name, s1.age);
		change_ptr0(&s0, &s1);
		printf("s0:{%s, %d} and s1:{%s, %d}\n", s0.name, s0.age, s1.name, s1.age);
	}
	if (correct)
	{
		struct student *ptr1 = &s0;
		struct student *ptr2 = &s1;
		// to efect on original you should take those address
		printf("\n\n swap wth **ptr:\n");
		printf("s0:{%s, %d} and s1:{%s, %d}\n", ptr1->name, ptr1->age, ptr2->name, ptr2->age);
		change_ptr1(&ptr1, &ptr2);
		printf("s0:{%s, %d} and s1:{%s, %d}\n", ptr1->name, ptr1->age, ptr2->name, ptr2->age);
	}

}
int main()
{
	pointer();
	// ------------------------------#
	//                               #
	//          add, last, create    #
	//                               #
	//-------------------------------#
	struct Node *head = NULL;
	struct Node *node0 = create_new_node(7);
	
	printf("address of node0:%p\n\n", node0);
	add_at_end_lst(&head, node0);
	printf("valuead of head(expected address of node0):%p\n\n", head);

	struct Node *node1 = create_new_node(12);
	add_at_end_lst(&head, node1);

	struct Node *node2 = create_new_node(17);
	add_at_end_lst(&head, node2);
	
	display(head);

	// ------------------------------#
	//                               #
	//          add, last, create    #
	//                               #
	//-------------------------------#
	printf("\n\n\n");
	// ------------------------------#
	//                               #
	//             count             #
	//                               #
	//-------------------------------#
	printf("number of element: %d\n", count_recursively(head));
	recursive_display(head);

	// ------------------------------#
	//                               #
	//              search           #
	//                               #
	//-------------------------------#
	display(head);
	struct Node *find = improved_search(&head, 17);
	if (find)
		printf("found: %d\n", find->data);
	else
		printf("not found\n");
	printf("after improved: \n");
	display(head);
	struct Node *rfind = Rsearch(head, 11);	

	if (rfind)
		printf("find 11 recursively: %d \n", rfind->data);
	else
		printf("rfind nor found!\n");
	display(head);
	struct Node *x = improved_search(&head,11);
	if (x)
		printf("find x recursively: %d \n", x->data);
	else
		printf("x nor found!\n");
	display(head);
	// ------------------------------#
	//                               #
	//          maximum element      #
	//                               #
	//-------------------------------#
	printf("\n\nimplement max element: \n");
	struct Node *max_el = max(head);
	printf("max element: %d\n",max_el->data);
	struct Node *rmax_el = rmax(head);
	printf("max element: %d\n",rmax_el->data);
	// ------------------------------#
	//                               #
	//          sum element          #
	//                               #
	//-------------------------------#
	printf("\n implement sum part: \n");
	printf("sum in travers way: %d\n", sum(head));
	printf("sum in recursive way: %d\n", rsum(head));

	// ------------------------------#
	//                               #
	//          insert element       #
	//                               #
	//-------------------------------#
	printf("\nimplement insert at index: \n");
	insert(&head, 0, 5);
	display(head);

	// ------------------------------#
	//                               #
	//          create element       #
	//                               #
	//-------------------------------#
	printf("let's create a link list and from start:\n");
	struct Node *new = NULL;
	struct Node *NewNode = create_new_node(10);
	if (!NewNode)
		return 1;
	printf("insert in a sorted link_list:\n");
	insert_in_sorted(&new, NewNode);
	display(new);
	insert(&new, 0, 6);
	insert(&new, 1, 8);
	insert(&new, 2, 9);
	insert(&new, 3, 8);
	insert(&new, 4, 10);
	insert(&new, 5, 11);


	struct Node *NewNode0 = create_new_node(22);
	if (!NewNode)
		return 1;
	add_at_end_lst(&new, NewNode0);
	display(new);


	// ------------------------------#
	//                               #
	//        delete element         #
	//                               #
	//-------------------------------#
	delete_at_index_tow(&new, 4);
	display(new);
	delete_at(&new, 3);
	display(new);
	// ------------------------------#
	//                               #
	//        check sorted	         #
	//                               #
	//-------------------------------#
	printf("%s\n", check_sorted(new));
	if (check_sorted2(new))
	{
		/* code */
		printf("second approach: link_list is is sorted\n");
	}
	else
	{
		printf("second approach: link_list is not sorted\n");
		/* code */
	}
	display(new);
	if (rcheck_sorted(new))
		printf("ckeck sorted recursively: is sorted\n");
	else
		printf("recursively: the link_list is not sorted\n");
	printf("\033[1;31m\n\n");
	// ------------------------------#
	//                               #
	//        delete dup	         #
	//                               #
	//-------------------------------#
	printf("delete duplicate:\n");
	struct Node *NewNode1 = create_new_node(22);
	if (!NewNode1)
		return 1;
	add_at_end_lst(&new, NewNode1);

	struct Node *NewNode2 = create_new_node(22);
	if (!NewNode2)
		return 1;
	add_at_end_lst(&new, NewNode2);

	struct Node *NewNode3 = create_new_node(22);
	if (!NewNode3)
		return 1;
	add_at_end_lst(&new, NewNode3);

	display(new);

	delete_dup(&new);
	display(new);
	printf("\033[0m\n");

	// ------------------------------#
	//                               #
	//        reverse link	         #
	//                               #
	//-------------------------------#
	reverse_link(&new);
	display(new);
	reverse_link_sliding(&new);
	display(new);
	// ------------------------------#
	//                               #
	//        concatinate	         #
	//                               #
	//-------------------------------#
	struct Node *first = NULL;
	insert(&first, 0, 5);
	insert(&first, 1, 7);
	insert(&first, 2, 12);
	insert(&first, 3, 17);

	/* merge */
	struct Node *merge = merge_list(new, first);
	printf("merge: ");
	display(merge);


	printf("\n\nconcat new and head:\n");
	concatinate(&new, &head);
	display(new);
	/* test with null */
	struct Node *_null = NULL;
	concatinate(&new, &_null);
	display(new);
	concatinate(&_null, &new);
	printf("\nconcat to null: \n");
	display(_null);
	printf("\ndelete duplicate: \n");
	delete_dup(&_null);
	display(_null);
	// ------------------------------#
	//                               #
	//        check loop	         #
	//                               #
	//-------------------------------#
	printf("\n\ncheck loop: \n");
	display(_null);
	if (isLoop(_null))
		printf("there is loop in this link list\n");
	else
		printf("there is no loop link list\n");

	struct Node *last = last_node(_null);

	last->next = _null;
	display(_null);
	if (isLoop(_null))
		printf("there is loop in this link list\n");
	else
		printf("there is no loop link list\n");
	circular_display(_null);
}