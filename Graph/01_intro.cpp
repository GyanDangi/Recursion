#include <bits/stdc++.h>
using namespace std;

class graph{

	public:
	unordered_map<int, list<int>> adjlist;
	// map<int, list<int>> adjlist;


	void addEdge(int u, int v, bool direction){

		// direction =0 => undirected
		// direction =1 => directed Graph

		//created edge from  node(u) to node(v)
		// u --> v
		adjlist[u].push_back(v);

		// undirected: v-->u as well u-->v
		if(direction==0){
			//created edge from  node(v) to node(u)
			adjlist[v].push_back(u);
		}
	
	}

	void  printAdjList(){
			 
			 for(auto i:adjlist){
				cout<<i.first<<"->";
				for(auto j:i.second){
					cout<<j<<",";
				}
				cout<<endl;
			 }
		}
};


int main(){

	int n;
	cout<<"enter the number of nodes:";
	cin>> n;

	int m;
	cout<<"enter the number of edges:";
	cin>>m;

	graph g;
	cout<<"enter the edges:"<<endl;

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin>>u>>v;
		
		// creating undirected graph:
		g.addEdge(u,v,0);
	}

	cout<<"Your Adjacency list of graph is:"<<endl;
	g.printAdjList();
	

	return 0;
}