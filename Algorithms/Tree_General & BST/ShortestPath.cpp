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

void shortest_path(int source, int dest) 
{
	int z[dim][3];
	for(int i=0; i<dim;i++)
	{
		z[i][0]=-1;
		z[i][1]=INF;
		z[i][2]=0;	
	}
	int mini=0, row_min =source; //min is the dist between source and it self as it will be the 1st node
	z[source][0]=source;
	z[source][1]=0;
	z[source][2]=1;
	do
	{
		for(int i=0 ; i<dim; i++)
		{
			if(z[i][2]==0 && weight[row_min][i]+mini<z[i][1]) // check for the nodes thats outside the circle and override if same node has another father with less weight 
															  //we checked here for z[i][2] ==0 not z[i][0]==-1 cause if we checked on zi0 it changes to 1 after entered graph not circle so if a same node comes with different weight condtion wouldnt be approved 
			{
				z[i][0]=row_min;
				z[i][1]=weight[row_min][i]+mini; 
			}	
		}
		row_min=-1; mini=INF;
		for(int i=0; i< dim;i++)
		{ 
			if (z[i][2]==0 && z[i][1] < mini)
			{
				mini=z[i][1];
       		 	row_min=i;
				
			}
		}
		z[row_min][2]=1;	
	} while (dest!=row_min);
	int r= dest;
	while (r!=source)
	{
		cout<<r<<"\n";
		r=z[r][0]; 	// (0) -> 5 -> 2 -> (3) shortest path from (0) to (3)
	}	
}
int main()
{
shortest_path(0,3) ;
}
