#include<iostream>
#define INF 99999
using namespace std;
class Graph
{
	public:
		int V;
		int E;
		int *Adj;
};

void printSolution(Graph *G)
{
	int i,j;
	
	for(i=0; i<G->V; i++)
	{
		for(j=0; j<G->V; j++)
		{
			if(*(G->Adj+i*G->V+j) == INF)
			{
				cout<<"    INF";
			}
			else
			{
				cout<<"    "<<*(G->Adj+i*G->V+j);
			}
		}
		cout<<endl;
	}
}

void floydwarshall(Graph *G)
{
	int i,j,k;
	int dist[G->V][G->V];
	
	for(i=0; i<G->V; i++)
	{
		for(j=0; j<G->V; j++)
		{
			dist[i][j] = *(G->Adj+i*G->V+j);
		}
	}
	
	for(k=0; k<G->V; k++)
	{
		for(i=0; i<G->V; i++)
		{
			for(j=0; j<G->V; j++)
			{
				if(dist[i][k] + dist[k][j] < dist[i][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	
	for(i=0; i<G->V; i++)
	{
		for(j=0; j<G->V; j++)
		{
			*(G->Adj+i*G->V+j) = dist[i][j];
		}
	}
}
int main()
{
	int i,j,matrix[4][4]={{0,5,INF,10},
						  {INF,0,3,INF},
						  {INF,INF,0,1},
						  {INF,INF,INF,0}};
						  
	Graph *G;
	G = (Graph *)malloc(sizeof(Graph));
	G->V = 4;
	G->E = 4;
	G->Adj = (int *)malloc((G->V)* (G->V) * sizeof(int));
	
	for(i=0; i<G->V; i++)
	{
		for(j=0; j<G->V; j++)
		{
			*(G->Adj+i*G->V+j) = matrix[i][j];
		}
	}
	cout<<"\nORIGINAL SOLUTION: \n";
	printSolution(G);
	floydwarshall(G);
	cout<<"\nMATRIX BELOW SHOWS THE SHORTEST DISTANCE BETWEEN EVERY \n";
	printSolution(G);
}
