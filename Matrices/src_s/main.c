#include <stdio.h>
#include <stdlib.h>

struct element
{
	int i;
	int j;
	int val;
};

struct sparse
{
	int m;
	int n;
	int num_non;
	struct element *elm;
};

int compare(const void *a, const void *b) {
    struct element *e1 = (struct element *)a;
    struct element *e2 = (struct element *)b;

    if (e1->i != e2->i)
        return e1->i - e2->i;   // sort by row
    return e1->j - e2->j;       // then by column
}

void display(struct sparse s) {
    int k = 0;
    for (int i = 0; i < s.m; i++) {
        for (int j = 0; j < s.n; j++) {
            if (k < s.num_non && i == s.elm[k].i && j == s.elm[k].j) {
                printf("%d ", s.elm[k].val);
                k++;
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main()
{
	struct sparse s;
	
	printf("Enter Dimention\n");
	scanf("%d%d", &s.m, &s.n);

	printf("Enter num non_zero:\n");
	scanf("%d", &s.num_non);
	
	s.elm = (struct element *)malloc(sizeof(struct element) * s.num_non);
	if (!s.elm)
		return (1);
	printf("Enter value of matrix: \n");

	for (int i = 0; i < s.num_non; i++)
	{
		scanf("%d%d%d", &s.elm[i].i, &s.elm[i].j, &s.elm[i].val);
	}
	qsort(s.elm, s.num_non, sizeof(struct element), compare);

	display(s);
	printf("your Sparse matrix: %d %d %d\n", s.m, s.n, s.num_non);
}