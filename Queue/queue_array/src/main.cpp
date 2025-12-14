#include "../include/Queue.hpp"

struct Task{
	std::string task;
	int priotity;
};

std::ostream& operator<<(std::ostream& out, const Task& t)
{
	out << "task: " << t.task << ", priority: " << t.priotity << std::endl;
	return out;
}

int main()
{
	Queue<std::string> q(4);
	q.enqueue("🧜");
	q.enqueue("🧜");
	q.enqueue("🧜");
	q.enqueue("🧜");
	q.display();

	/* test priority */
	//Node* arr[];
	Task tsk[7] = {{"task1", 1},{"task2", 3},{"task3", 2},{"task4", 3},{"task5", 1}, {"task6", 2}, {"task7", 1}};
	Queue<Task> priority_queue[3] = { Queue<Task>(7), Queue<Task>(7), Queue<Task>(7) };

	for (size_t i = 0; i < 7; i++)
	{
		std::cout << tsk[i];
		int p = tsk[i].priotity;   // 1,2,3
        priority_queue[p -1].enqueue(tsk[i]);

	}
	// Q1 = heighest priority
	std::cout << "Q 1: " << std::endl;
	priority_queue[1 - 1].display();
	
	// Q2 = middle priority
	std::cout << "Q 2: " << std::endl;
	priority_queue[2 - 1].display();

	// Q3 = lowest priority
	std::cout << "Q 3: " << std::endl;
	priority_queue[3 -1].display();
}