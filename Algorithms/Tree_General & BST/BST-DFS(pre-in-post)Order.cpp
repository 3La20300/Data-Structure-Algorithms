#include<iostream>
using namespace std;

struct binary_node{
	int data;
	binary_node * left, *right;
};

class binary_search_tree{
	private:
	binary_node*	get_smallest_right(binary_node* ptr)
		{
			while (ptr->left)
			{
				ptr=ptr->left;
			}
			
			return ptr;	
		}
		
		binary_node *root;
		binary_node* make_new_node(int dd);
		void rec_insertion(binary_node *ptr, int dd);
		void rec_pre_order(binary_node *ptr);
		void rec_in_order(binary_node *ptr);
		void rec_post_order(binary_node *ptr);
		bool rec_search(binary_node *ptr , int dd);
		bool rec_delete_data(binary_node *&ptr , int dd);

	public:
		binary_search_tree()  { root = NULL; }
		void insert_data(int dd);
		bool search_data(int dd);
		void print_pre_order();
		void print_in_order();
		void print_post_order();
		bool remove_data(int dd);
};

binary_node* binary_search_tree:: make_new_node(int dd)
{
	binary_node *temp= new binary_node();
	temp->data=dd;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}		

void binary_search_tree::insert_data(int dd)
{
	if (root==NULL) root=make_new_node(dd);
	else rec_insertion(root, dd);	
}	
void binary_search_tree::rec_insertion(binary_node* ptr,int dd) //Making A new Tree not inserting to replacing any node
{
	if (dd<ptr->data){
		if (ptr->left==NULL) ptr->left=make_new_node(dd);
		else rec_insertion(ptr->left, dd);
	}
	else if (dd>ptr->data)
			if (ptr->right==NULL) ptr->right=make_new_node(dd);
		else rec_insertion(ptr->right, dd);

}

bool binary_search_tree::search_data(int dd)
{
	if(root == NULL)	
	{ cout << "You can not search for " << dd 
		<< " in an empty tree\n";  return false; }
	else rec_search(root, dd);
}

bool binary_search_tree::rec_search(binary_node *ptr , int dd)
{
	if (dd== ptr->data) 
	{  	cout<< "\nWe Found it in the tree";
		return true;
	}
	else if (dd<ptr->data) rec_search(ptr->left, dd);
	else if (dd>ptr->data) rec_search (ptr->right, dd);
}

void binary_search_tree::print_pre_order()
{
	if(root== NULL)  cout << "\nTree is Empty\n";
	else 
	cout<<"\nPre-Order";
	rec_pre_order(root);
	cout<<"\n";
}

void binary_search_tree::rec_pre_order(binary_node *ptr )
{	
	if(ptr==NULL) return;
	cout<<ptr->data<<"\t"; //F
	rec_pre_order(ptr->left);//L  //	if (ptr->left!=NULL) rec_pre_order(ptr->left); else return; 	//	if (ptr->right!=NULL) rec_pre_order(ptr->right)	else return;
	rec_pre_order(ptr->right);//R	
}

void binary_search_tree::print_in_order()
{
	if(root== NULL)  cout << "\nTree is Empty\n";
	else 
		cout<<"\nIN-Order";
	rec_in_order(root);
	cout<<"\n";
}

void binary_search_tree::rec_in_order(binary_node *ptr )
{
	if(ptr==NULL) return;
	rec_in_order(ptr->left);//L
	cout<<ptr->data<<"\t";//F
	rec_in_order(ptr->right);//R	
}

void binary_search_tree::print_post_order()
{
	if(root== NULL)  cout << "\nTree is Empty\n";
	else 
	cout<<"\nPost-Order";
	rec_post_order(root);
	cout<<"\n";
}

void binary_search_tree::rec_post_order(binary_node *ptr )
{	
	if(ptr==NULL) return;
	rec_post_order(ptr->left);//L
	rec_post_order(ptr->right);//R
	cout<<ptr->data<<"\t";	//F
}
bool binary_search_tree::remove_data(int dd)
{
	if(root == NULL)	
	{  cout << "You can not delete from an empty tree\n";  return false; }
	else  return rec_delete_data(root , dd);
}
bool binary_search_tree:: rec_delete_data(binary_node *&ptr , int dd)
{	cout<<"Hey";
	if (dd<ptr->data)
		rec_delete_data(ptr->left,dd);	
	else if (dd>ptr->data)
		rec_delete_data(ptr->right,dd);	
	else
		{
			if (!ptr->left) // this part and next part is responsiple for deletion of a node after swap(getSmallestRight) or if the tree it self is ONLY LHSided Or ONLY RHSided
			{
				binary_node* temp=ptr->right;
				delete ptr;
				ptr=temp;
				return 1; 
			}
			else if (!ptr->right)
			{
				binary_node* temp=ptr->left;
				delete ptr;
				ptr=temp;
				return 1; 

			}
			else
			{
				binary_node* temp= get_smallest_right(ptr->right); // get the smallest node in the RHS..
				ptr->data=temp->data;
				rec_delete_data(ptr->right, temp->data);
				return true;			
			} 	
	
 		}
}

																//	binary_search_tree()  { root = NULL; }
																//	void insert_data(int dd);
																//	bool search_data(int dd);
																//	void print_pre_order(void);
																//	void print_in_order(void);
																//	void print_post_order(void);
																//	bool remove_data(int dd);

int main(){
	binary_search_tree tree1;
	tree1.insert_data(5);	
	tree1.insert_data(1);
	tree1.insert_data(3);
	tree1.insert_data(8);
	tree1.insert_data(9);
	tree1.insert_data(6);
	tree1.print_pre_order();
	tree1.print_in_order();
	tree1.print_post_order();	
	tree1.remove_data(6);	
	tree1.print_in_order();

}
