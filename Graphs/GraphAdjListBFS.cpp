#include<bits/stdc++.h>
using namespace std;
class Graph{
	private:
		int V;
		map<int,list<int> > adjList; //adjList.first-> key and adjList.second -> value
	public:
		Graph(int v){
			this->V = v;
		}
	
		void push(int u, int v, bool bidir = true){
			adjList[u].push_back(v);
			if(bidir){
				adjList[v].push_back(u);
			}
		}
		void print();
		void BFS(int src);
};

void Graph::print(){
	for(auto x: adjList){
		cout<<"Nodes connected to "<<x.first<<"are: ";
		for(auto z: x.second){
			cout<<z<<" ";
		}
		cout<<endl;
	}
	
}

void Graph::BFS(int src){
	bool *visited = new bool[V]{0};
	queue<int> Q;
	
	Q.push(src);
	visited[src] = true;
	
	cout<<"BFS: ";
	while(!Q.empty()){
		int node = Q.front(); Q.pop();
		
		cout<<"\nYour node is: "<<node;
		for(auto neighbour: adjList[node]){
			if(!visited[neighbour]){
				cout<<" and Visited "<<neighbour;
				Q.push(neighbour);
				visited[neighbour] = true;
			}
		}	
	}
}


int main(){
	Graph g(3);
	
	g.push(0, 1);
	g.push(0, 2);
	g.push(1, 2);
	
	g.print();
	g.BFS(0);
	g.print();
}
