#include <iostream>

using namespace std;

void read_array(int *ptr , int size)
{
	for(int k = 0 ; k < size ; k++)
	{
		cout << "array["<<k<<"] = ";
		cin >> ptr[k] ;
	}
}
void fill_array(int *ptr , int size , int min , int max)
{
	for(int k = 0 ; k < size ; k++)
	{		ptr[k] = min + rand() % (max - min +1);
	}
}
void print_array(int *ptr , int size)
{
	for(int k = 0 ; k < size ; k++)
		cout << ptr[k] << "\t";
	cout << "\n";
}

void merge_two_lists(int *arr, int f1, int e1, int f2, int e2){
int *ptr;
ptr= new int[e2-f1+1]; // we supposed that arr1 and arr2 are consective(in the same array so e2 >e1 
 )
	int k1, k2, k3;
	k1=f1; k2=f2; k3=0;
	
	while((k1<=e1) &&(k2<=e2)) //get the smallest of two lists and place it in ptr
	{
		if(arr[k1]<arr[k2]) {ptr[k3]=arr[k1]; k1++; k3++;}
		else {ptr[k3]=arr[k2]; k2++; k3++;}	
	}
	// check if one if the lists ended before the other
	while(k1<=e1) {ptr[k3]=arr[k1]; k3++; k1++;}  // if  while loop no 1 ended because ONLY k2<=e2
	while(k2<=e2) {ptr[k3]=arr[k2]; k3++; k2++; } // if  while loop no 1 ended because ONLY k2<=e2
		
	for(int i=0; i<=e2-f1; i++){
			arr[i+f1]=ptr[i];
	}
}

void merge_sort(int *arr, int first, int last)	{
	int mid;
	if(first>=last) return;
	mid=(first+last)/2;
	merge_sort(arr, first, mid);
	merge_sort(arr, mid+1, last);
	merge_two_lists(arr, first, mid, mid+1,last);
	
}

ib nt main(){
	int arr[5];
	fill_array(arr, 5, 10 ,20);
	
	cout<<"Array Before Sort"<<"\t";
	print_array(arr,5);
	
	merge_sort(arr, 0, 4);
	cout<<"Array After Sort"<<"\t";
	print_array(arr, 5);

return 0;	
		
}
