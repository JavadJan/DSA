#ifndef Queue_hpp
# define Queue_hpp
#include <iostream>
#include <string.h>

template<typename T>
class Node{	
	public:
	T data;
	Node *next;
	//Node(): next(NULL){}
};

template<typename T>
class Queue{ // implement a Queue with array
	private:
		Node<T>* rear;
		Node<T>* front;
	public:
		Queue():rear(NULL), front(NULL){}
		~Queue(){}
		void enqueue(T x)
		{
			Node<T>* t = new Node<T>;
			if(t == NULL)
			{
				std::cout << "Queue is full\n";
			}
			else
			{
				t->data = x;
				t->next = NULL;
				if (front == NULL)
				{
					front = rear = t;

				}
				else
				{
					rear->next = t;
					rear = t;
				}
			}
		}
		T dequeue()
		{
			Node<T>* p;
			T x = 0;
			if (front == NULL)
				std::cout << "Queue is empty\n";
			else
			{
				p = front;
				x = front->data;
				front = front->next;
				delete p;
			}
			return x;
		}
		void display()
		{
			if (front == NULL)
			{
				std::cout << "Queue is empty\n";
				return ;
			}
			Node<T> *temp = front;
			while (temp!=NULL)
			{
				std::cout << temp->data <<"->" ;
				temp = temp->next;
			}
			std::cout << std::endl;
		}

};

struct Person{
	int age;
	std::string name;
};

std::ostream& operator<<(std::ostream& os, const Person& b) {
    os << "{ age: " << b.age
       << ", name: " << b.name << " }";
    return os;
}

#endif