#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

#define SIZE 5

struct st{
	int id;
	char grade;
};

st* randSt(int size){
	st *list= new st[size];
	srand(time(NULL));	
	for (int i =0 ; i<size; i++){
		list[i].id=1001+i;
		int z= rand()%6;
		list[i].grade='A'+z;
		
	}
return list;
}


	st* countsort(st *list, int size){
		
		st* temp=new st[size];
		int counters[6];
		for(int i=0; i<6; i++ ) counters[i]=0;
		for(int i=0; i<size; i++) counters[list[i].grade-'A']++;  //freq array 1,2,3,4 // 1:3-- 1 repeated 3 times,, counters[1]++ l2et "1" w bt3od t3dy 3la kol element kda..  
		for(int i=1; i<6; i++) counters[i]=counters[i]+counters[i-1];  // acummulative sum 1,2,3,4 --> 1,3,6,10
		for(int i=size-1;i>= 0; i--) // we start from the bottom of the list
		{
			temp[--counters[list[i].grade-'A']]=list[i];
			//ex		temp[--counters[B]=list[i]; B means 1 , ABCD...., B-A=1 which is B m=index and so on
		}	
		for(int i=0; i<size; i++){
			list[i]=temp[i];
		}
	return list;
	}	 	



int main(){
		
	st* y;
	y=randSt(5);
	for (int i =0 ; i<5; i++){
		cout<<y[i].id<<"\t";	
		cout<<y[i].grade<<"\t";
		cout<<"\n";			
	}
	cout<<"\n";
	y= countsort(y, 5);
	
	for (int i =0 ; i<5; i++){
		cout<<y[i].id<<"\t";	
		cout<<y[i].grade<<"\t";
		cout<<"\n";			
	}
    return 0; 
}
