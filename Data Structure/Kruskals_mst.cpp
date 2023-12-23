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

int kruskals_mst()
{
	int z[dim];
	int min=INF, row_min=INF, col_min=INF, total_weight=0, group=0;	
	for(int i=0; i<dim; i++)
	{
		for(int j=0; j<dim; j++)
		{
			min_span[i][j]=INF;
			if(i==j) min_span[i][j]==0;
		}
		z[i]=-1;
	}
	while (1)
	{
		min=INF;
		for(int i=0; i<dim; i++)
		{
			for(int j=0; j<i; j++)
			{
				if(weight[i][j]<min)
				{
					min=weight[i][j];
					row_min=i;
					col_min=j;
				}
			}	
		}
		if(min==INF) return total_weight;
		if (z[row_min]!=z[col_min] || z[row_min]==-1 || z[col_min]==-1 ) 
		{
			min_span[row_min][col_min]=min_span[col_min][row_min]=min;
			//cout<<"\n"<<min<<"\n";
			total_weight+=min;
			if (z[row_min]==-1 && z[col_min]==-1) // case1: A and B not in group
			{
				group++;
				z[row_min]=z[col_min]=group;
			}
			else if (z[row_min]==-1 && z[col_min]!=-1) // case2: A isn't in group but B is, so attach A to the group of B 
			{
				z[row_min]=z[col_min];
			}	
			else if(z[row_min]!=-1 && z[col_min]==-1) // case3: A is in group but B isn't in one, so attach B to the group of A
			{
				z[col_min]=z[row_min];
			}
			else 									// case4: A and B are in different groups , so attach all elements in group of B to the group of A
			{
				int temp= z[col_min];
				for(int i=0; i<dim; i++)
				{  if (z[i]==temp)
					z[i]=z[row_min];
				}
			}
		}
		weight[row_min][col_min]=INF;
	}
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
	cout<< "Total Weight: "<< kruskals_mst();
	cout<<"\nMsT: \n";
	print_matrix(dim, dim, min_span);
		
}
