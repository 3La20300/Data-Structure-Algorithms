#include<iostream>
using namespace std;

struct node
{
  int data;
  struct node *next;
  node(int val): data(val), next(NULL){}
};

class Linked_List{
private:
	node* head;
	int count=0;
public:
	Linked_List(): head(NULL){}
	void insert_back(int val)
	{
		node* node1=new node(val);
		if(!head) head=node1;
		else
		{
			node* current=head;
			while(current->next) current= current->next;
			current->next=node1;
		}
		count++;
	}
	
	void insert_front(int val)
	{
		node* node1=new node(val);
		if(!head) head=node1;
		else{
			node1->next=head;
			head=node1;
		}
		count++;
	}
	

	void delete_last()
	{
		if(!head) cout<<"RunTime eRROR: EMPTY LIST";
		else if(!head->next)
		{
			delete head;
			head=NULL;
		}
		else
		{
			node* current;
			current=head;
			node* past=NULL; //you have to always intiate pointers with null ...
			while(current->next)
			{
				past=current;
				current=current->next;
			}
			past->next=NULL;
			delete current;  
		}
		count--;
	}
	
	void delete_first()
	{
		
		if(!head) cout<<"RunTime eRROR: EMPTY LIST";
		else 
		{
			node* temp=head->next;
			delete head;
			head=temp;
		}
		count--;
	}
	 int get_item_index(int val)
	 {
	 	if(!head){
		   cout<<"RunTime eRROR: EMPTY LIST";
	 		return -1;
		}
		 else 
	 	{
	 		int index=0;
	 		node* current =head;
	 		while (current->next && current->data != val)
	 		{
	 			current=current->next;
	 			index++;
			}
			if(current->data == val) 
			{
				return index;
			}
			return -1;
		 }
	 
	 }
	 void insert_in_order(int val)
	 {
	 	if(!head)
		   cout<<"RunTime eRROR: EMPTY LIST";
		else
		{
			int index=0;
			node* current= head;
			node*past=NULL;
			while (current->next && current->data <val){
				past=current;
				current=current->next;
				index++;
			}
			if(current->next){
				if (current==head) insert_front(val);
				else
				{
				insert_index(val,index);	
				}
			}
			else{
				insert_back(val);
			}
		}
			 	
	 }
	
	void delete_index(int index)
	{
	 	if(!head)
		   cout<<"RunTime eRROR: EMPTY LIST";
		else{
			int ind=0;
			node* current=head;
			node* past=NULL;
			while (current->next && index!=ind)
			{	
				past=current;
				current=current->next;
				ind++;
			}
			if(current==head)
			{
			head=head->next;  
			delete current;
		    }
		    else if (current->next) 
			{
			 	past->next= current->next;	
				delete current;	
			}
			else {
				past->next=NULL;
				delete current;
			}
			
		}
			
	}
	
	void insert_index(int val, int index)
	{
			node* node1= new node(val);			
			int ind=0;
			node* current=head;
			node* past=NULL;
			while (current->next && index!=ind)
			{	
				past=current;
				current=current->next;
				ind++;
			}
			if(current==head) insert_front(val);
			else if(current->next) 
			{
				past->next=node1;
				node1->next=current;	
			}
			else
			{
				past->next=node1;
			}
	}	
	
	void delete_item(int val){
		if(head){
			int ind=0;
			node* current=head;
			node* past=NULL;
			while (current->next && current->data != val)
			{	
				past=current;
				current=current->next;
				ind++;
			}
			if(current==head)
			{
			head=head->next;  
			delete current;
		    }
		    else if (current->next) 
			{
			 	past->next= current->next;	
				delete current;	
			}
			else {
				past->next=NULL;
				delete current;
			}
			count--;
		}
	}
	
	void display(){
		if(head)
		{	node* current=head;
			while (current)
			{	
				cout<< current->data<<"\t";
				current=current->next;
			}
		}
	}	
	
};

int main()
{
	Linked_List l ;
	l.insert_front(1);
	l.insert_back(2);
	l.insert_back(3);
	l.insert_back(34);
	
	l.insert_index(22,2);
	cout<<l.get_item_index(1)<<"\n";
	l.display(); 	
}
