#include <iostream>
using namespace std;

class sort{
	private : 
		int size;
		int *arr;
	
	public:
		sort(int n)
		{
			size=n;
			arr=new int[size];
		}
		
		void read()	{
			
			for (int i=0; i<size; i++){
				arr[i]=rand()%100;
			}
	    }
	    
		void print(){
			for(int i=0; i<size; i++){
				cout<<arr[i]<<"\t";
			}
			cout<<"\n";
		}
		
		void selection(){
			int temp;
			int min;
			for(int i=0; i<size-1;i++){
				min=i;
				
					for(int j=i+1 ; j<size; j++){
						if(arr[j]<arr[min]) min=j;					
					}
				temp=arr[i];
				arr[i]=arr[min];
				arr[min]=temp;
				cout<<arr[i]<<"\n";
			}
	
		}		
		
}; 

int main(){
  sort obj1(5);
	obj1.read();
	cout<<"Array Before Sort"<<"\t";
	obj1.print();
	
	obj1.selection();
	cout<<"Array After Sort"<<"\t";
	obj1.print();

	
		return 0;
}
