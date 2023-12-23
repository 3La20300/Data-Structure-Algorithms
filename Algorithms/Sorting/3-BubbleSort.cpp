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
		
		void bubble()
		{
			int b , temp , flag ;
			b = 2 ;
			do{
				flag = 0 ;
				for(int i = 0 ; i <= size - b ; i++)
				{
					if(arr[i] > arr[i+1])
					{ temp = arr[i] ; arr[i] = arr[i+1] ; arr[i+1] = temp ; flag++; }
				}
				b++;
			}while(flag > 0);
		}
		
}; 

int main(){
  sort obj1(5);
	obj1.read();
	cout<<"Array Before Sort"<<"\t";
	obj1.print();
	
	obj1.bubble();
	cout<<"Array After Sort"<<"\t";
	obj1.print();

	
		return 0;
}
