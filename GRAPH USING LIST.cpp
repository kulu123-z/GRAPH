//using linked list for directed grapbs
#include<iostream>
using namespace std;

class ListNode
{
	public:
		int vertexNumber;
		ListNode *next;
};

class Graph
{
	public:
		int V;//vertex
		int E;//edge
		ListNode *Adj;
		
		//constructor
		Graph(int vertex, int edge)
		{
			this->V = vertex;
			this->E = edge;
			this->Adj = (ListNode *)malloc(this->V * sizeof(ListNode));	
			
			//intialize all vertex node with vertex name
			for(int i=0; i<this->V; i++)
			{
				//G->Adj[i]->vertexNumber = i;
				this->Adj[i].vertexNumber = i;
				
				//G->Adj[i]->next = G->Adj+i;
				this->Adj[i].next = this->Adj+i;//address of self node intially
			}
		}
		
			
		void adjListOfGraph(int source, int destination)
		{
			ListNode *temp,*newNode;
			
		//	for(int i=0; i<this->E; i++)
		//	{
				
				newNode = (ListNode *)malloc(sizeof(ListNode));//create new node
				
				newNode->vertexNumber = destination;
				newNode->next = &this->Adj[source];//refersourence of source node
				
				temp = &this->Adj[source];//address of source node in temp pointer
				
				while(temp->next != &this->Adj[source])
				{
					temp = temp->next;
				}
				temp->next = newNode;
			//}
		}
		
		void graphPrint()
		{
			cout<<"\nGRAPH USING ADJACENCY LIST\n";
			ListNode *temp;
			for(int i=0; i<this->V; i++)
			{
				cout<<"\nEDGES FROM VERTEX "<<i<<" TO ";
				temp = &this->Adj[i];//address of one by one vertex node
				if(temp->next == &this->Adj[i])
				{
					continue;
				}
				while( temp->next != &this->Adj[i])
				{
					temp = temp->next;
					cout<<"  "<<temp->vertexNumber;
				}
			}
		}
		
};
int main()
{
	Graph G(5,5);
	G.adjListOfGraph(0,1);
	G.adjListOfGraph(0,2);
	G.adjListOfGraph(0,3);
	G.adjListOfGraph(0,4);
	
	G.adjListOfGraph(1,0);
	G.adjListOfGraph(1,2);
	G.adjListOfGraph(1,3);
	
	G.adjListOfGraph(2,0);
	G.adjListOfGraph(2,1);
	
	
	G.adjListOfGraph(4,0);
	G.graphPrint();
}

