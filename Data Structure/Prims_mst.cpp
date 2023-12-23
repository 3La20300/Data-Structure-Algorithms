#include<iostream>
using namespace std;

#define dim 7
#define INF 99

int weight[dim][dim] =
{ { 0, 3, INF, INF, INF, INF, 2 },
  { 3, 0, 2, INF, INF, INF, 5 },
  { INF, 2, 0, 7, 1, 1, 3 },
  { INF, INF, 7, 0, 6, 7, INF },
  { INF, INF, 1, 6, 0, 4, INF },
{ INF, INF, 1, 7, 4, 0, 8 },
{ 2, 5, 3, INF, INF, 8, 0 } };

int min_span[dim][dim];

int prims_mst()
{
	int z[dim][3];
	int min=INF, row_min=0, col_min=-1, total_weight=0;
	for(int i=0; i<dim; i++)
	{
		for(int j=0;j<dim ;j++)
		{
			min_span[i][j]=INF;
			if (i==j) min_span[i][j]=0;
		}
		z[i][0]=-1; // node written by...
		z[i][1]=INF; // node weight
		z[i][2]=0; // node entered the circle(min_span graph) or not
	}
	z[row_min][0]=0;
	z[row_min][1]=0;
	z[row_min][2]=1;
	
	do
	{
		for(int i=0; i<dim;i++)
		{
			if(z[i][2]==0 && weight[i][row_min]<z[i][1]) // check for the nodes thats outside the circle and override if same node has another father with less weight 
			{
				z[i][0]=row_min;
				z[i][1]=weight[row_min][i];
			}
		}
		min=INF;
		col_min=-1;
		for(int i=0; i<dim; i++)
		{
			if (z[i][2]==0 && z[i][1]<min ) //get the value and the location of the min weight node
			{
				min=z[i][1];
				row_min=z[row_min][0];
				col_min=i;
			}
		}
		if (min ==INF) return total_weight;
		min_span[row_min][col_min]=min_span[col_min][row_min]=min;
		total_weight+=min;
		row_min=col_min; // override with new value that entered the circle(the min_span graph) so it will be the node through which other nodes will enter the circle
		z[row_min][2]=1; // indicate that a node joined the circle (the min_span graph)
	}while(row_min!=-1);
}
void print_matrix(int row, int col, int mat[dim][dim])
{
	for(int i=0; i<dim; i++)
	{
		for(int j=0; j<dim; j++)
		{
			if(mat[i][j]!=INF) cout<<mat[i][j]<<" ";
			else cout<<"# ";
		}
	cout<<"\n";
	}
	
}

int main()
{
	cout<<"Old Graph\n";
	print_matrix(dim, dim, weight);
	cout<< "Total Weight: "<< prims_mst();
	cout<<"\nMsT: \n";
	print_matrix(dim, dim, min_span);
		
}
