#include<bits/stdc++.h>
using namespace std;

class Graph{
	private:
		int V;
		map<int,list<int> > adjList;
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
};

//void Graph::push(int u, int v, bool bidir = true){
//}

void Graph::print(){
	for(auto x: adjList){
		cout<<"Nodes connected to "<<x.first<<"are: ";
		for(auto z: x.second){
			cout<<z<<" ";
		}
	}
	
}

int main(){
	Graph g(4);
	
	g.push(0, 1);
	g.push(0, 2);
	g.push(1, 2);
	
	g.print();
}
