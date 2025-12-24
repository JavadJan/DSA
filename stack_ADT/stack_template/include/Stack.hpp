#ifndef Stack_hpp
# define Stack_hpp
#include <iostream>
#include <string.h>
#include <optional>

template <typename T>
class Node{
	public:
		T data;
		Node *next;
};

template <typename T>
class Stack{ // implement a stack with array
	private:
		Node<T> *top;
	public:
		Stack();
		//Stack(size_t size);
		Stack(const Stack &other);
		Stack& operator=(const Stack &other);
		~Stack();

		/* methods for link list approach */
		void push(const T& data);
		T pop();
		int isEmpty();
		int isFull();
		T stackTop();

		void display();
};
#include "Stack.tpp"
bool	isBalance(char *exp);
bool ValidParanthesis(char *exp);
char *convert(const char *infix);
char *InToPostfix_bracket(const char *infix);
int eval(const char *postfix);

#endif