#include "../include/link_list.h"

bool isLoop(struct Node *p)
{
	struct Node *slow, *fast;
	slow = fast = p;
	do
	{
		slow = slow->next;
		fast = fast->next;
		fast = fast ? fast->next : fast; // if fast == NULL fast otherwise fast = fast->next
		
	} while (slow && fast && slow != fast);
	if (fast == slow)
		return true;
	else return false;
}