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
		
		void insertion(){
		int temp;
		int x;
			
			 for(int i=1; i<size; i++){
				// cout<<i<<"\n";
				x=i;	
				
				for (int j=i-1; j>=0; j-- ){
					
					if(arr[i]<arr[j]){
						temp=arr[i];
				//		cout<<temp<<"\t";
						
						arr[i]=arr[j];
				//		cout<<arr[i]<<"\t";
						
						arr[j]=temp;
				//		cout<<arr[j]<<"\t";
						
				//		cout<<"\n";
						i--;	
					}
				    else {
					i=x;
					break;
				    }
			    }
				
		    }
		
	   }		
		
}; 

int main(){
  sort obj1(5);
	obj1.read();
	cout<<"Array Before Sort"<<"\t";
	obj1.print();
	
	obj1.insertion();
	cout<<"Array After Sort"<<"\t";
	obj1.print();

	
		return 0;
}
