// Stack    FILO(first in-last out)  ,   LIFO
#include <iostream>
using namespace std;


class stack_using_array
{
private:
	int  top , size , *arr ;
public:
	stack_using_array(void)
	{
		arr = new int[10];
		size = 10;
		top = 0;
	}
	stack_using_array(int ss)
	{
		arr = new int[ss];
		size = ss;
		top = 0;
	}
	void push(int data)
	{
		if(is_full())
		{
			cout  << "Stack is full, so size will be double\n";
			double_size();
		}
		arr[top] = data ;
		top++;
	}
	int pop(void)
	{
		if(is_empty())
		{
			cout << "Stack is empty\n";
			return -1;
		}
		top--;
		return arr[top];
	}
	int read_top_data(void)
	{
		if(is_empty())		return -1;
		else					return arr[top-1];
	}
	bool is_full(void)
	{
		return top >= size;
	}
	bool is_empty(void)
	{
		return top <= 0 ;  
	}
	int get_max_size(void)
	{
		return size ;
	}
	int get_nuumber_of_item(void)
	{
		return top;
	}
	void double_size(void)
	{
		int *temparr;
		temparr = new int[size*2];
		for(int k = 0 ; k < top ; k++)
			temparr[k] = arr[k];
		delete arr;
		size = size * 2;
		arr = temparr;
	}
	void delete_stack_data()   // override stackdata...
	{
		top = 0;
	}
	~stack_using_array(void)
	{
		delete arr;
	}
};

int main(void)
{
	stack_using_array st1 ;
	cout<<st1.get_max_size();
	cout<<"\n"<<st1.get_nuumber_of_item()<<"\n";
	int k ;
	for(k = 1 ; k <= 12 ; k++) //12 > size..
		st1.push(k*10);

	for(k = 1 ; k <= 15 ; k++)
		cout << st1.pop() << "\t"<<"\n";
	st1.delete_stack_data();
	st1.~stack_using_array();
}

