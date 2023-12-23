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

void quick_sort(int *arr, int first,int last){
	int pivot, temp, k1, k2;
	if(first>=last) return;
	pivot=arr[first];
	k1= first+1;
	k2= last; 
	 while(k1<=k2){
	 	while((k1<=last) && (arr[k1]<=pivot)) {k1++; }
		while ((k2>first)&& (arr[k2]>pivot)){k2--;}
		if(k1<k2) { temp=arr[k1]; arr[k1]= arr[k2]; arr[k2]=temp; }
		}
	 arr[first]=arr[k2]; arr[k2]=pivot;
	 quick_sort(arr, first, k2-1);
	 quick_sort(arr, k2+1, last); 
	
	} 
	 	
int main(){
	int arr[5];
	fill_array(arr, 5, 10 ,20);

	cout<<"Array Before Sort"<<"\t";
	print_array(arr,5);
	
	quick_sort(arr, 0, 4);
	cout<<"Array After Sort"<<"\t";
	print_array(arr, 5);

return 0;	
		
}
	
