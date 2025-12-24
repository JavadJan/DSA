struct ListNode	*addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
	int carry = 0;
	struct ListNode *head = NULL, *tail = NULL;
	while (l1 != NULL || l2 != NULL || carry != 0) // 1. & is wrong,
		//2. travesrse untill one of them is not null
	{                                             
		// instead change the value of
		int val1 = (l1 != NULL) ? l1->val : 0;
		int val2 = (l2 != NULL) ? l2->val : 0;
		int sum = val1 + val2 + carry;

		// create new node
		struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
		if (!newNode)
			return (NULL);

		newNode->val = sum % 10;
		newNode->next = NULL;
		carry = sum / 10;

		// Append to result list
		if (head == NULL)
			head = newNode;
		else
			tail->next = newNode;

		tail = newNode;

		if (l1)
			l1 = l1->next;
		if (l2)
			l2 = l2->next;
	}

	return (head);
}