#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

#define SIZE 5
int main()
{
	int numbers[100] , temp[100] ;
	int counters[10] , k , n , a , b;
	for(k = 0 ; k < 100 ; k++)		numbers[k] = rand() % 1000 ;
	b = 1 ;
	for(int digit = 1 ; digit <= 3 ; digit++ , b*= 10)
	{
		cout << "Digit = " << digit << "\t b = " << b << "\n";

		for(k = 0 ; k < 10 ; k++)			counters[k] = 0 ;

		for(k = 0 ; k < 100 ; k++)
		{
			n = (numbers[k] / b) % 10 ;
			counters[n]++;
		}

		for(k = 1 ; k < 10 ; k++)			
			counters[k] = counters[k] + counters[k-1];

		for(k = 99 ; k >= 0 ; k--)
		{
				n = (numbers[k] / b) % 10 ;
				temp[--counters[n]] = numbers[k] ;
		}

		for(k = 0 ; k <= 99 ; k++)
		{
			numbers[k] = temp[k];
			cout << numbers[k] << "\t";
		}
		cout << "\n\n";
		getch();
	}
//	getch

