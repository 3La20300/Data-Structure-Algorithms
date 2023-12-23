#include <iostream>

using namespace std;

int rec_binary_search(int*arr, int first, int last , int key){
	int mid;
		
		if (first > last) return -1;
		mid=(first+last)/2;
		if(key==arr[mid]) return mid;
		else if(key>arr[mid]) return rec_binary_search(arr, mid+1, last, key );
		else return rec_binary_search(arr, first, mid-1, key );	
			
	
}

int main(){
	int arr[10]={-10, -3, 7, 12, 13, 18 , 20 , 22 , 24 ,25};
	int x=rec_binary_search(arr,0,(sizeof(arr)/sizeof(int))-1, 15);
	int y=rec_binary_search(arr,0,(sizeof(arr)/sizeof(int))-1, 20);
	cout<<"\n"<<x;
	cout<<"\n"<<y;
	
}
