#include <iostream>
#include <cstdlib>
#include<time.h>
using namespace std;

#define SIZE 5
struct st
{
	int id;
	char grade ;
};
int main()
{
	struct st list[SIZE] , temp[SIZE];
	int k;
	int counters[6] ;
	char ch;
	//Generate random data (serial 30 id start from 1001 and random grade from A to F)
	srand(time(NULL));
	for(k = 0 ; k < SIZE ; k++)
	{
		list[k].id = k + 1001 ;
		list[k].grade = 'A' + rand() % 6 ;
		cout << k << "\t" << list[k].id << "\t" << list[k].grade << "\n";
	}

	for(k = 0 ; k < 6 ; k++)		counters[k] = 0;

	for(k = 0 ; k < SIZE ; k++){
			counters[list[k].grade - 'A']++;

	}
/////////////////////	
//		for(k = 0 ; k < 6 ; k++){
//			
//			cout<< counters[k];
//			cout<<"\n";
//	}
///////////////////////
	for(k = 1 ; k < 6 ; k++)
	{
//		ch = 'A' + k ;
		counters[k] = counters[k-1] + counters[k] ;
//		cout << k << "\t" << ch << "\t" << counters[k] << "\n";
	}

	for(k = SIZE-1 ; k >= 0 ; k--)
		temp[--counters[list[k].grade - 'A']] = list[k];

//	cout << "Data after sorting according to grade: \n";
	for(k = 0 ; k < SIZE ; k++)
	{
		list[k] = temp[k];
//		cout << k << "\t" << list[k].id << "\t" << list[k].grade << "\n";
	}
	cout<<"\n\n";
	for(k = 0 ; k < SIZE ; k++)
	{
		cout << k << "\t" << list[k].id << "\t" << list[k].grade << "\n";
	}




}

