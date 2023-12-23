#include<iostream>
using namespace std;

const int N=7 ;
int arr[N]={60 , 20, 40,70 ,30 ,10,80} ;


void heapify_node(int i, int n) // heapify a node with its children
{
	int parent= i;
	int l= 2*i +1;
	int r= 2*i +2;
	if (l<n && arr[l]> arr[parent])
		parent=l;

	if (r<n && arr[r]> arr[parent])
		parent=r;

	if ( parent!= i ){
		int temp= arr[parent];	
		arr[parent]=arr[i];
		arr[i]=temp;
		heapify_node(parent, n);
	}
	
}
	
heapify_tree(int n) //heapify node by node 
{
	for(int i=n/2-1; i>=0; i--)
		heapify_node(i, n);
	
}

void heap_sort(int * arr, int n)
{
	heapify_tree(N);
	for(int i=n-1; i>=0; i--) // swap root with last child after heap sort
	{
		int temp =arr[0];
		arr[0]=arr[i];
		arr[i]=temp; 
		heapify_tree(i); // i is then new number of elements so that the last index= (n -2)
	}

}



int main(){
	cout<<"array before heap";
	for(int i =0; i<N;i++)
		cout<<arr[i]<<"\n";
	
	cout<<"\n";
	
	heap_sort(arr, N);
	
	for(int i=0; i<N; i++)
		cout<<arr[i]<<"\n";
	
}
