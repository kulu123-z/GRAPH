#include<iostream>
using namespace std;
class GraphAdjanecyMatrix
{
	public:
		int vertex;
		int **matrix;
		//int *mat;
		
		//parameterized constructor
		GraphAdjanecyMatrix(int vertex)
		{
			this->vertex = vertex;
			this->matrix = new int*[vertex];//here only 1D array
			
			for(int i=0; i<vertex; i++)
			{
				*(matrix + i) = new int[vertex];//here matrix is 2D array
				
				for(int j=0; j<vertex; j++)
				{
					*(*(matrix + i) +j) = 0;//all element is now zero
				}
			}
		}
		//takes O(1) time to add edge
		void addEdge(int source, int destination)
		{
			*(*(matrix + source) + destination) = 1;
			
			//in indirect graph it is symmetric that mean a[i][j] = a[j][i]
			//back edge for indirect graph
			*(*(matrix + destination) + source) = 1;
		}
		
		void printGraph()
		{
			cout<<"\nGRAPH USING ADJANECY MATRIX\n";
			
			for(int i=0; i<vertex; i++)
			{
				for(int j=0; j<vertex; j++)
				{
					cout<<"	"<<*(*(matrix + i) + j);
				}
				cout<<endl;
			}
			
			//here printing graph such as adjency list method 
			for(int i=0; i<vertex; i++)
			{
				cout<<"\nVERTEX "<<i<<"  IS CONNECTED WITH TO :";
				for(int j=0; j<vertex; j++)
				{
					if(*(*(matrix + i) + j) == 1)
					{
						cout<<"	"<<j;
					}
				}
				cout<<endl;
			}
		}
};

int main()
{
	GraphAdjanecyMatrix G(5);
	
	G.addEdge(0,1);
	G.addEdge(0,4);
	G.addEdge(1,2);
	G.addEdge(1,3);
	G.addEdge(1,4);
	G.addEdge(2,3);
	G.addEdge(3,4);
	G.printGraph();
}
