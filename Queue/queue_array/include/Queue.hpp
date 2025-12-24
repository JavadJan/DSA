#ifndef Queue_hpp
# define Queue_hpp
#include <iostream>
#include <string.h>

template<typename T>
class Queue{ // implement a Queue with array
	private:
		int size;
		T *Q; // not only the int, but also can store double, float, char, typedef struct, string
		int rear;
		int front;
	public:
		Queue():size(0),Q(NULL), rear(0), front(0){}
		Queue(size_t _size): size(_size), Q(new T[_size]), rear(0), front(0){}
		~Queue(){delete [] Q;}
		void enqueue(T x){
			if ((rear + 1) %size == front) // if it is full 
			{
				std::cout << "Queue is full" << std::endl;
			}
			else
			{
				rear = (rear + 1) %size; // circular
				Q[rear] = x;
			}
		}
		T dequeue()
		{
			T x = 0;
			if (rear == front)
			{
				std::cout << "Queue is empty" <<  std::endl;

			}
			else{
				front = (front + 1) %size;
				x = Q[front];
			}
		}
		void display()
		{
			int i = front + 1;
			std::cout<< "💁 ";
			do
			{
				std::cout << Q[i] << "|"; // it is better to write and overload<<
				i = (i + 1) % size;
			} while (i != (rear + 1) %size);
			std::cout << std::endl;
		}

};


#endif