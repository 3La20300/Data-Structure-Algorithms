#include<iostream>
using namespace std;

struct treeNode {
	char father, child;
	int order;
};


class stack_using_array
{
	private:
		int  top , size ;
		char *arr ;
	
	public:
		stack_using_array(void)
		{
			arr = new char[10];
			size = 10;
			top = 0;
		}
		stack_using_array(int ss)
		{
			arr = new char[ss];
			size = ss;
			top = 0;
		}
		void push(char data) { arr[top++] = data ; }
		char pop(void) { return arr[--top]; }
		
		bool is_full(void) { return top >= size; }
		
		bool is_empty(void) { return top <= 0 ;  } 
	};
	
class queue_using_array{
	private: 
		int front, rear, size, counter; // Counter: represents number of elements...
		char  *arr;
	public:
		queue_using_array(){
			size=5;
			arr= new char[size];
			front=rear=counter=0;
		}
		
		queue_using_array(int ss){
			arr=new char[ss];
			size=ss;
			front=rear=counter=0;
		}
		
		void enqueue(char data){
			arr[rear]=data;
			rear=(rear+1)%size;
			counter++;
		}
		char dequeue(){
															 
			int temp=front;
			front=(front+1) % size;
			counter--;
			return arr[temp];	
		}
		bool is_empty(void) { return (counter == 0); }
		bool is_full(void) { return counter == size; }
};

void print_DFS(treeNode *ptr,int size )
{	
	int counter=0;
	char *sons= new char[size];
	stack_using_array st1;
	for (int i= 0; i<size; i++)
	{ 
		if (ptr[i].father==0)
		{
			st1.push(ptr[i].child);
			break;
		}
	}
	
	while (!st1.is_empty()){
		char temp=st1.pop();
		cout<<temp<<"\t";
		counter=0;
		for (int i=0; i<size ;i++){
			if (ptr[i].father==temp)
			{
			 	sons[ptr[i].order]=ptr[i].child;
			 	counter++;
			}
		}
		for (int i=counter; i>=1;i--)
		st1.push(sons[i]);
	}
		
	
	cout<<"\n"<<"\n";
}


void print_BFS(treeNode *ptr, int size){
	int counter=0;
	char *sons =new char[size];
	queue_using_array qu1;
	for (int i=0; i<size; i++)
	{
		if (ptr[i].father==0)
		{
			qu1.enqueue(ptr[i].child);
			break;
		}	
	}
	
	while (!qu1.is_empty()){
		char temp=qu1.dequeue();
		cout<<temp<<"\t";
		counter=0;
		for(int i=0; i<size; i++)
		if (ptr[i].father==temp){
			sons[ptr[i].order]=ptr[i].child;
			counter++;			
		}
		for(int i=1;i<=counter;i++ )
		qu1.enqueue(sons[i]);
	}		
}

