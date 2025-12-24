#include "../include/Queue.hpp"

Queue::Queue()
{
	std::cout << "\033[1;33mDefault Queue Constructor\033[0m" << std::endl;
}

Queue::Queue(size_t size):size(size), top(-1) // an empty Queue
{
	std::cout << "\033[1;33mConstuctor with Param arr[]\033[0m" << std::endl;
	this->data = new std::string[size];
}

Queue::Queue(const Queue &other)
{
	(void)other;
	std::cout << "\033[1;33m Copy Queue Constructor\033[0m" << std::endl;
}
Queue& Queue::operator=(const Queue &other)
{
	(void)other;
	std::cout << "\033[1;33m assignment operator\033[0m" << std::endl;
	return (*this);
}
Queue::~Queue()
{
	std::cout << "\033[1;33m deconstructor \033[0m" << std::endl;
	delete [] this->data ;
	
}

const std::string &Queue::pop()
{
	std::string x;

	if (this->top == -1)
	{
		std::cout << "Queue is underflowed, nothing to pop" << std::endl;
		return {};
	}
	else
	{
		x = data[this->top];
		(this->top)--;
	}
	// take out one node from last current Queue.
	// what is current Queue? *this
	// LIFO: last-in last-out
	return (x);
}



void	Queue::push(const std::string &str) // the Queue it does not nessessary, *this point to the current Queue
{
	if (this->top == static_cast<int>(this->size -1))
	{
		std::cout << "Queue overflowed(Queue is full)" << std::endl;
	}
	else{
		this->top++;
		this->data[this->top] = str;
	}
}

void	Queue::display()
{
	if (this->top == -1)
	{
		std::cout << "Queue is mepty" << std::endl;
		return ;
	}
	for (int i = 0; i <= top; i++)
	{
		std::cout << "elem: " << this->data[i] << std::endl;
	}
	std::cout << "top: " << this->data[top] << std::endl;
}


bool Queue::isEmpty()
{
	return (top ? false : true); // true == yes
}
bool Queue::isFull()
{
	return ((top == static_cast<int>(this->size)) ? true : false);	
}
int Queue::peek(int index) {
	int x = -1;
	int pos = this->top - index + 1;
	if (pos < 0 || pos > this->top) 
	{
		std::cout << "Invalid position!" << std::endl;
	} 
	else 
	{
		x = top - pos + 1;
	}
	return x;
}
