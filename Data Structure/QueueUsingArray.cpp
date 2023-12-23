#include<iostream>
using namespace std;

class queue_using_array{
	private: 
		int front, rear, *arr, size, counter; // Counter: represents number of elements...
		
	public:
		queue_using_array(){
			size=5;
			arr= new int[size];
			front=rear=counter=0;
		}
		
		queue_using_array(int ss){
			arr=new int[ss];
			size=ss;
			front=rear=counter=0;
		}
		
		void enqueue(int data){
			arr[rear]=data;
			rear=(rear+1)%size;
			counter++;
		}
		int dequeue(){
															 
			int temp=front;
			front=(front+1) % size;
			counter--;
			return arr[temp];	
		}
		bool is_empty(void)
		{
			return (counter == 0);
		}
		bool is_full(void)
		{
			return counter == size;
		}
		int get_number_of_elements(void)
		{
			return counter;
		}
		int get_max_size(void)
		{
			return size;
		}
		void double_size(){
			int*temp;
			temp= new int[size*2];
			for(int i=0; i<counter;i++)
				temp[i]=arr[(i+front)%size];  //i=4, f=1 , temp[4]= arr[0]; arr[0] //((i+front)%size) in case the list circulated , ex:INEQUEUE size=5 rear=4 so rear=(4+1)%size, rear=0(Circulated)
											// so we check if ex: f=3, counter> 5(size)-3 that means rear was circulated and we need to go read from the arr[0]...
			delete arr;
			arr=temp;
			size=size*2;
			front=0;
			rear= counter;		
		}
		
};
int main(void)
{
	queue_using_array st1 ;

	int k ;
	for(k = 1 ; k <= 7 ; k++)
		st1.enqueue(k*10);
	
	//st1.double_size();

	for(k = 1 ; k <= 5 ; k++)
		//if(k==5) cout<<"\n";
		//else 
		cout << st1.dequeue() << "\n";
	
	cout<<st1.get_number_of_elements();
}


