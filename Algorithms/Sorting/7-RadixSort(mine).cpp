#include <iostream>
#include <cstdlib>
#include<time.h>
using namespace std;

#define SIZE 5

int* randlist(int size){
	int *list;
	srand(time(NULL));	
	for (int i =0 ; i<size; i++){
			int x=rand()%1001;
			list[i]=x;
	}
return list;
}

int* countSort(int *list, int size, int digit){
	
	int temp[size];
	int counters[10];
	for(int i=0; i<10; i++ ) counters[i]=0;
	for(int i=0; i<size; i++) counters[(list[i]/digit) % 10]++;  //intial value of digit is 1,// so to get 2 in 432 , (432/1)%10=2,// to get 3 (432/10)= 43 not 43.2 as its integer, 43%10=3 
																	//freq array 1,2,3,4 // 1:3-- 1 repeated 3 times,, counters[1]++ l2et "1" w bt3od t3dy 3la kol element kda..  
	for(int i=1; i<10; i++) counters[i]=counters[i]+counters[i-1];  // acummulative sum 1,2,3,4 --> 1,3,6,10
	for(int i=size-1;i>= 0; i--) // we start from the bottom of the list
	{
		temp[--counters[(list[i]/digit) % 10]]=list[i];
		//ex		temp[--counters[1]=list[i]; 
	}	
	for(int i=0; i<size; i++){
		list[i]=temp[i];
	}
return list;
}	 	
int* radixSort (int *list, int size){
	int digit=1;
	for(int bit=1; bit<4; bit++, digit*=10) //1: unit, 2:tenth, 3: hundredth (al 5anat bta3t ay rkm)..
	{	
		list=countSort(list,size,digit);
		
	}
return list;
}

int main(){
		
	int* y;
	y=randlist(5);
	for (int i =0 ; i<5; i++){
		cout<<y[i]<<"\t";	
	}
	cout<<"\n";
	y= radixSort(y, 5);
	
	for (int i =0 ; i<5; i++){
		cout<<y[i]<<"\t";	
//		cout<<"\n";			
	}
    return 0; 
}
