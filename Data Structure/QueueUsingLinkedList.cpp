#include <iostream>
using namespace std;

struct queuenode{
 	int data ;
	queuenode* next; //"next" means "next" , every elements point to the element after it , for ex: 0 points to 1 
				// we call it "next" because in queue we read from 0 to 1 so we consider 1 as the next place... 	
};

class LinkedListQueue
{
	private:		
		queuenode* front, *rear;
	public:
		LinkedListQueue()
		{
			front=NULL;
			rear=NULL;
		}
		void enqueue(int data){
			queuenode* temp=new queuenode;
		 	temp->data =data;
		 	temp->next=NULL;
			if(rear==NULL ) front=rear=temp; // front=temp
											// rear=temp 	
			else
			{
				rear->next=temp;
				rear=temp;
			}
		}
		int dequeue()
		{	
		 	int data;
			queuenode* temp;
			data=front->data;		
			temp=front;
			front=front->next;
			delete temp;
			if (front==NULL) rear=NULL;
			return data;
			
		}
		bool isEmpty(void)
		{
			return front == NULL;
		}
		void printQueue(void)
		{
			queuenode *temp;
			cout << "All data in queue : ";
			for(temp = front ; temp != NULL ; temp = temp->next)
				cout << temp->data << "\t";
			cout << "\n";
		}
		int getNumberOfElements(void)
		{
			int counter;
			queuenode *temp;
			counter = 0;
			for(temp = front ; temp != NULL ; temp = temp->next)		
				counter++;
			return counter;
		}

};
int main()
{
	LinkedListQueue list1;
	list1.enqueue(5);
	list1.enqueue(3);
	list1.enqueue(2);
	list1.enqueue(7);
	list1.dequeue();
	
	cout<<list1.getNumberOfElements();
	
}
