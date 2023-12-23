#include <iostream>

using namespace std;

int binary_search(int*arr, int first, int last , int key){
	int mid;
	
	while (first<=last){
		int mid=(first+last)/2;
		if(key==arr[mid]) return mid;		// binary search works only on sorted arrays
		else if(key>arr[mid]) first= mid+1; // if we reach the last search , asuume arrSize=5 so last search first=1, last=1, mid =1 if key>arr[1] first=1+1=2 > last, key<arr[1] last=mid-1=0 < first
										 	// thats why we wrote the while(first<=1) 
		else last=mid-1;
						
		
	}
	return -1;
	
}

int main(){
	int arr[10]={-10, -3, 7, 12, 13, 18 , 20 , 22 , 24 ,25};
	int x=binary_search(arr,0,(sizeof(arr)/sizeof(int))-1, 13);
	int y=binary_search(arr,0,(sizeof(arr)/sizeof(int))-1, 9); // size 0f array output size*4 so we divide by size(int) which = 4
	cout<<"\n"<<x;
	cout<<"\n"<<y;
	//cout<<"\n"<<sizeof(arr);	
}
