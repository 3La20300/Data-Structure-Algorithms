// Stack    FILO(first in-last out)  ,   LIFO

#include<iostream> 
using namespace std;

struct stacknode {
	int data;
	stacknode* next; //"next" means "prev" , every elements point to the element before it , for ex: 1 points to 0 
					// we call it "next" because in stack we read from 1 to 0 so we consider 0 as the next place...  
};

class LinkedListStack{
	private:
	 	stacknode* top;
	public:
		LinkedListStack(){
			top=NULL;
		}
		void push(int data ){
			stacknode* temp;
			temp=new stacknode;
			temp->data=data;	
			temp->next=top;
			top=temp;
		}
		int pop(){
			stacknode* temp;
			int dd;
			dd=top->data; 
			temp=top; // we saved top in temp to delete the previos value of top later,, ptr=ptr2... delete ptr will delete ptr2 try in draft.cpp
			top=top->next;
			delete temp; // here the deletion happens
			return dd;
		}
		int getNumberOfElements()
		{
			stacknode* temp;
			int counter=0;
			for(temp=top; temp!=NULL; temp=temp->next)
				counter++;
			return counter;
		}	
		void printStack(void)
		{
			stacknode *temp;
			cout << "Data in stack: ";
			for(temp = top ; temp != NULL ; temp = temp->next)		
				cout << temp->data << "\t";
			cout << "\n";
		}

};
