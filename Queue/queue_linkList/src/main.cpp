#include "../include/Queue.hpp"

int main()
{
	Queue<int> q;
	q.enqueue(10);
	q.enqueue(9);
	q.enqueue(11);
	q.enqueue(8);
	q.enqueue(6);
	q.display();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();	
	q.display();
	
	Person p = {34, "javad"};
	Queue<Person> Q;
	Q.enqueue(p);
	Q.display();
}