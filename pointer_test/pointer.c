#include <stdio.h>
#include <unistd.h>

// here edit ptr1[2] to another var
void change_ptr2 (int ***ptr3)
{
	printf("address of ptr in function: %p\n", *ptr3);
	int c = 3;
	// go to  the address that you have
	(**ptr3) = &c;
	printf("address of ptr in function after ++: %p\n", *ptr3);
//get  ^  address of **ptr2 then assing the 3th cell
}

void modify(int *p)
{
	*p = 5;
}

int main()
{
	int a = 1;
	int *ptr;

	ptr = &a;
	printf("value of a: %d\n", *ptr);
	printf("address of a: %p\n", ptr);
	printf("address of a: %p\n", &a);
	printf("addres of ptr: %p\n", &ptr);

	int **ptr1 = &ptr ;
	//*ptr1 = ptr; // now we have address of ptr
	// you can go to the address ptr and print value of that address
	printf("value of a: %d\n", **ptr1);

	// now you can acces to the address of by access to the ptr
	printf("adress of a by ptr1: %p\n", *ptr1);

	// you have access to the address of ptr
	printf("address of ptr by ptr1: %p\n", ptr1);
	printf("address of a via ptr1: %p\n\n", *ptr1);

	//(*ptr1)++;
	int b = 0;
	*ptr1 = &b;

	printf("value of b: %d\n", **ptr1);
	printf("address of b: %p\n", *ptr1);
	printf("address of ptr: %p\n", ptr1);
	printf("address of b: %p\n\n", &b);

	// pass by address
	change_ptr2(&ptr1);
	printf("value of c: %d\n", **ptr1);
	printf("value of b: %d\n", **ptr1);
	printf("value of a: %d\n", **ptr1);
	printf("value of a via ptr: %d\n", *ptr);
	printf("address of ptr1: %p\n", ptr1);

	// send a copy of address
	// pass addrss of that value and take in other then in that function change the value
	modify(ptr);
	printf("value of c: %d\n", **ptr1);
	printf("value of b: %d\n", **ptr1);
	printf("value of a: %d\n", *ptr);
	

}