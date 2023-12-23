#include<iostream>
#include<time.h>
#include<cstdlib>
using namespace std;

int main(void)
{
	int arr[20] , key , a ;
	srand(time(NULL));
//	srand(3);
	for(a = 0 ; a <= 19 ; a++)
	{
		arr[a] = 5 + rand() % 96 ;
		cout << arr[a] << "\t";
	}	
	cout << "\nPlease enter a key number to search for it: ";
	cin >> key ;
	// LINEAR Search PART
	for(a = 0 ; a <= 19 ; a++)
		if(arr[a] == key)		break; //IF SORTED Linear Search : if(arr[i]>key) break;
	if(a == 20)			cout << "Number can not be found\n";
	else				cout << "Number is found at index " << a << endl;
	
	return 0;
	//
}


