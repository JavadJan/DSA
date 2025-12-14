#include "../include/Stack.hpp"

Stack::Stack()
{
	std::cout << "\033[1;33mDefault Stack Constructor\033[0m" << std::endl;
}

Stack::Stack(size_t size):size(size), top(-1) // an empty stack
{
	std::cout << "\033[1;33mConstuctor with Param arr[]\033[0m" << std::endl;
	this->data = new std::string[size];
}

Stack::Stack(const Stack &other)
{
	(void)other;
	std::cout << "\033[1;33m Copy Stack Constructor\033[0m" << std::endl;
}
Stack& Stack::operator=(const Stack &other)
{
	(void)other;
	std::cout << "\033[1;33m assignment operator\033[0m" << std::endl;
	return (*this);
}
Stack::~Stack()
{
	std::cout << "\033[1;33m deconstructor \033[0m" << std::endl;
	delete [] this->data ;
	
}

const std::string &Stack::pop()
{
	std::string x;

	if (this->top == -1)
	{
		std::cout << "Stack is underflowed, nothing to pop" << std::endl;
		return {};
	}
	else
	{
		x = data[this->top];
		(this->top)--;
	}
	// take out one node from last current stack.
	// what is current stack? *this
	// LIFO: last-in last-out
	return (x);
}



void	Stack::push(const std::string &str) // the stack it does not nessessary, *this point to the current stack
{
	if (this->top == static_cast<int>(this->size -1))
	{
		std::cout << "Stack overflowed(stack is full)" << std::endl;
	}
	else{
		this->top++;
		this->data[this->top] = str;
	}
}

void	Stack::display()
{
	if (this->top == -1)
	{
		std::cout << "stack is mepty" << std::endl;
		return ;
	}
	for (int i = 0; i <= top; i++)
	{
		std::cout << "elem: " << this->data[i] << std::endl;
	}
	std::cout << "top: " << this->data[top] << std::endl;
}


bool Stack::isEmpty()
{
	return (top ? false : true); // true == yes
}
bool Stack::isFull()
{
	return ((top == static_cast<int>(this->size)) ? true : false);	
}
int Stack::peek(int index) {
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
