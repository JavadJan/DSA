#include <stdio.h>
#include <stdlib.h>


struct Node
{
	int val;
	int col;
	struct Node *next;	
};


int main()
{
	int col;
	int row;
	printf("enter number of row and col ");
	scanf("%d", &row, &col);

	// define an array of pointers to linked lists
	// create sparse matrix
	struct Node* A[row];
	*A = malloc(sizeof(struct Node *) * row);
	if (!A)
		return 1;
	printf("Enter col, val in order");
	for (int i = 0; i < n ; i++)
	{
		printf("in which row: ");
		scanf("%d", )

		if 
		scanf("%d %d\n", A[i]->col, A[i]->val);
	}
}