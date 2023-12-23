#include<iostream>
using namespace std;

struct node{
	int data;
	node * next, *prev;
	node(int dd): data(dd), next(NULL), prev(NULL){}
};
//insert_first
//insert_last
//insert_at_index
//insert_in_order
//delete_first
//delete_last
//delete_index
//delete_first_occur
//get_size
//isempty
//delete_list
//search
//print_first_to_last
//print_Last_to_first

class Double_LinkedList{
	public:
	int count=0;	
	node* front, *rear;
	Double_LinkedList(): front(NULL), rear(NULL){}
	void insert_first(int dd){
		node* temp= new node(dd);
		if(!front)
		{
			front=rear=temp;
		}
		else
		{
			temp->next=front;
			front->prev=temp;
			front=temp;
		}
		count++;	
	}
	
	void insert_last(int dd)
	{
		node*temp=new node(dd);
		if(! front){
			front=rear=temp;
		}
		else{
			temp->prev=rear;
			rear->next=temp;
			rear=temp;	
			}
		count++;
	}
	
	void insert_at_index(int index, int dd)
	{
		node*temp=new node(dd);
		if( index<=0) 
			insert_first(dd);
//		else if(index==count-1)
//			insert_last(dd);
		else{
			
			node* current= front;
			node* parent= NULL;
			int ind=0;
			while (current && index!= ind )
			{
				parent=current;
				current=current->next;
				ind++;			
			}
			if(! current)
			{
				insert_last(dd);
			}
			else 
			{
				if(! parent) 
					{ insert_first(dd);
						}
					else {
					
						temp->next=current;
						temp->prev= parent;
						parent->next=temp;
						current->prev=temp;
					}
			}
		}
	count++;
	}

	void insert_in_order(int dd)
	{ 
		if(!front)
			insert_first(dd);
		else{
			node* temp= new node(dd);
			node* current= front;
			node* parent= NULL;
			while (current && current->data < dd)
			{
				parent=current;
				current=current->next;	
			}
			if(! current)
			{
				insert_last(dd);
			}
			else
			{	if(! parent)
				{ insert_first(dd);
					}
				else {
				
					temp->next=current;
					temp->prev= parent;
					parent->next=temp;
					current->prev=temp;
				}
			}
		}
			
		count++;
	}
	
	void delete_first()
	{
		if(!front)
			cout<<"Empty";
		
		else
		{
			node* temp=front;
			if(front->next)
			{
				front=front->next;
				front->prev=NULL; 
			}
			else 
				front=rear=NULL;
			delete temp;		
			count--;
		}
			
	}

	void delete_last()
	{
		if(!front)
			cout<<"Empty";
		else
		{	node* temp=rear;
			if(rear->prev)
			{
				rear=rear->prev;
				rear->next=NULL;
			}
			else 
				front=rear=NULL;
			
			delete temp;	
			count--;	 
		}
			 	
	}
	
	void delete_index(int index)
	{
		if(index<=0) 
			delete_first();
		else if(index==count-1)
			delete_last();
		else
		{
			node* current= front;
			node* parent=NULL;
			int ind=0;
			while(current && ind != ind)
			{
				parent=current;
				current=current->next; // the element of disired index
				ind++;		
			}
			if(! current)
			{
				delete_last();
			}
		
			else 
			{
				parent->next= current->next;
				current->next->prev= parent;	
				delete current;
			}	
		}
		count--;		
	}
	
	void delete_first_occur(int dd)
	{
		if(!front)
		{
			cout<<"empty";	
		}
		else 
		{
			node* current= front;
			node* parent=NULL;
			while (current && current->data< dd)
			{
				parent=current;
				current=current->next;
			}
			if(! current )
			{
				cout<<"Not found";	
			}
			else
			{	
				if (current->next) //element in the middle
				{
					   if(parent )
					   {
					   	parent->next=current->next;
						} 
						else 
						{ 
						delete_first();
						}	
				}
				else // last element
				{
					if(parent) //last element with parent
					{
						parent->next=NULL;
					}
					else //last element without parent (the list has only one element)
					{
						front=rear=NULL;	
					}
					delete current;	
				}
				count--;
			}
		
		}
		
	}
	
	int get_size()
	{
		return count;
	}
	bool is_empty(){
		return !front;
	}
	void delete_list()
	{
		while (!is_empty())
			{
				delete_first();
			}
	}
	
	int search(int dd)
	{
		if(!front)
			return -1;
		else
		 {
		 	node* current= front;
		 	int ind=0;
		 	while (current && current->data != dd)
		 	{
		 		current= current->next;
				ind++;	
			}
		 	if(! current)
		 	{
		 		return -1;	
			}
			else
				return ind;  
		 }	
	}
	
	void print_first_to_last()
	{
		node* current=front;
		while (current)
		{
			cout<<current->data<<" ";
			current=current->next;
		}
		cout<<endl;
	}
	void print_last_to_first()
	{
		node* current=rear;
		while (current)
		{
			cout<<current->data<<" ";
			current=current->prev;
		}
		cout<<endl;
	}

};
int main()
{
	Double_LinkedList d1;
	d1.insert_last(3);
	d1.insert_first(1);
//	d1.insert_last(4);
//	d1.insert_last(5);
	d1.insert_at_index(1,2);
	d1.print_first_to_last();
//	d1.insert_in_order(0);
//	d1.print_first_to_last();
//	d1.print_last_to_first();
//	d1.delete_first();
//	d1.print_first_to_last();
//	d1.delete_last();
//	d1.print_first_to_last();
//	d1.delete_index(1);
//	d1.delete_first_occur(1 );
//	cout<<d1.search(2)<<endl;
//	cout<<d1.get_size()<<endl;	
//	d1.print_first_to_last();

}

