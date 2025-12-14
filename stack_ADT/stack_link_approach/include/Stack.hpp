#ifndef Stack_hpp
# define Stack_hpp
#include <iostream>
#include <string.h>



typedef struct st_list {
	int age = 0;
	std::string name;
	struct st_list *next = nullptr;
} t_st_list;

class Stack{ // implement a stack with array
	private:
		t_st_list *top;

	public:
		Stack();
		//Stack(size_t size);
		Stack(const Stack &other);
		Stack& operator=(const Stack &other);
		~Stack();

		/* methods for link list approach */
		void push(const t_st_list& data);
		std::string pop();
		int isEmpty();
		int isFull();
		std::string stackTop();

		void display();
};

bool	isBalance(char *exp);
bool ValidParanthesis(char *exp);

#endif