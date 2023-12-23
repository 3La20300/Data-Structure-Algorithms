#include<iostream>
using namespace std;
#define dim 7
#define INF 99

int weight[dim][dim] =   
		{ 
			{ 0, 1, INF, INF, INF, 2, INF },
			{ 1, 0, 8, INF, INF, INF, INF },
			{ INF, 8, 0, 4, INF, 3, INF },
			{ INF, INF, 4, 0, 6, INF, INF },
			{ INF, INF, INF, 6, 0, 5, INF },
			{ 2, INF, 3, INF, 5, 0, 2 },
			{ INF, INF, INF, INF, INF, 2, 0 } 
		};

void all_to_all_short()
{
	bool flag=0 ;
	do
	{
		flag=0;
		for (int src=0; src<dim; src++) //each source
		{
				for(int dest=0; dest<dim; dest++) // one source with all destination
				{
						for(int via=0; via<dim; via++) // all roads between one source and one destination 
						{
							if (weight[src][dest]> weight[src][via]+ weight[via][dest]) //if the road from source to via pt then to dest shorter than the direct road from the source to dest then replace
							{
								weight[src][dest]= weight[src][via]+ weight[via][dest];
								flag=1;
							}
						}
				}
		}
	}while(flag);	//flag==1
}
void print_matrix(int r, int c, int mat[][dim])
{
	for(int i=0; i<dim; i++)
	{
		for(int j=0; j<dim; j++)
		{
			if (mat[i][j]!=INF) cout<< mat[i][j]<<" ";
			else cout<<"# ";
		}
		cout<<"\n";	
	}
}
int main()
{
	cout<<"OLD"<<endl;
	print_matrix(dim,dim,weight);
	all_to_all_short();
	cout<<"\nNEW"<<endl;
	print_matrix(dim,dim,weight);

}
