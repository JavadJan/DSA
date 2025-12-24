//#include "../include/Stack.hpp"

template<typename T>
Stack<T>::Stack(): top(NULL)
{
	std::cout << "\033[1;33mDefault Stack Constructor\033[0m" << std::endl;
}
template <typename T>
Stack<T>::Stack(const Stack<T> &other)
{
	(void)other;
	std::cout << "\033[1;33m Copy Stack Constructor\033[0m" << std::endl;
}
template <typename T>
Stack<T>& Stack<T>::operator=(const Stack &other)
{
	(void)other;
	std::cout << "\033[1;33m assignment operator\033[0m" << std::endl;
	return (*this);
}
template <typename T>
Stack<T>::~Stack()
{
	std::cout << "\033[1;33m deconstructor \033[0m" << std::endl;

	Node<T> *current = top;
	while (current != NULL) {
		Node<T>* temp = current;
		current = current->next;
		delete temp;  // free memory allocated with 'new'
	}
	top = NULL;	
	
}
template <typename T>
void	Stack<T>::push(const T& data)
{
	Node<T> *st = new Node<T>;
	if (st == NULL)
	{
		std::cout << "Stack is full" << std::endl;
		return;
	}
	st->data = data;
	st->next = top;
	top = st;
}

template<typename T>
T Stack<T>::pop()
{
	T data;
	Node<T> *p;
	if (top == NULL)
		throw std::runtime_error("Stack is empty");
	else
	{
		p = top;
		top = top->next;
		data = p->data;
		delete p;
	}
	return data;
}
template <typename T>
int Stack<T>::isEmpty()
{
	if (top == NULL)
		return (1); // it si empty
	return (0);
}

template <typename T>
int Stack<T>::isFull()
{
	Node<T> *t = new Node<T>;
	if (!t)
		return 1;// it is full, true == full
	return (0);
}

template <typename T>
T	Stack<T>::stackTop()
{
	return (top->data);
}

template <typename T>
void Stack<T>::display()
{
	Node<T> *p = top;
	while (p != NULL)
	{	
		std::cout << "data: " << p->data << std::endl;
		p = p->next;
	}
	
}

