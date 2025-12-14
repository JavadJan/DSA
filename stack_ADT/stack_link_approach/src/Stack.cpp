#include "../include/Stack.hpp"

Stack::Stack(): top(NULL)
{
	std::cout << "\033[1;33mDefault Stack Constructor\033[0m" << std::endl;
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

	t_st_list* current = top;
	while (current != NULL) {
		t_st_list* temp = current;
		current = current->next;
		delete temp;  // free memory allocated with 'new'
	}
	top = NULL;	
	
}

void	Stack::push(const t_st_list& data)
{
	t_st_list *st = new t_st_list;
	if (st == NULL)
	{
		std::cout << "Stack is full" << std::endl;
		return;
	}
	st->age = data.age;
	st->name = data.name;
	st->next = top;
	top = st;
}

std::string Stack::pop()
{
	std::string name = "";
	t_st_list *p;
	if (top == NULL)
	{
		std::cout << "stack is empty" << std::endl;
		return "NULL";
	}
	else
	{
		p = top;
		top = top->next;
		name = p->name;
		delete p;
	}
	return name;
}
int Stack::isEmpty()
{
	if (top == NULL)
		return (1); // it si empty
	return (0);
}
int Stack::isFull()
{
	t_st_list *t = new t_st_list;
	if (!t)
		return 1;// it is full, true == full
	return (0);
}

std::string Stack::stackTop()
{
	return (top->name);
}

void Stack::display()
{
	t_st_list *p = top;
	while (p != NULL)
	{	
		std::cout << "name: " << p->name << ", age: " << p->age << std::endl;
		p = p->next;
	}
	
}

