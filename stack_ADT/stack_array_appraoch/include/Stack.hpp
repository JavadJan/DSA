#ifndef Stack_hpp
# define Stack_hpp
#include <iostream>
#include <string.h>


class Stack{ // implement a stack with array
	private:
		std::string *data;// stack with arr, st
		size_t size;
		int 	top;

	public:
		Stack();
		Stack(size_t size);
		Stack(const Stack &other);
		Stack& operator=(const Stack &other);
		~Stack();

		/* methods for array appraoch*/
		const std::string& pop();
		void push(const std::string &str);
		bool isEmpty();
		bool isFull();
		int peek(int pos);
		void display();

};

bool	isBalance(char *exp);
bool ValidParanthesis(char *exp);

#endif