#include<bits/stdc++.h>
using namespace std;

class Graph{
	private:
		int V;
		vector<vector<int> > mat;

	public:
		Graph(const int v){
			this->V = v;
			mat.resize(V);
			for(int i=0; i<v; i++){
				for(int j=0; j<v; j++){
					mat[i].push_back(0);
				}
				cout<<endl;
			}
		}
		
		void push(int u, int v, bool bidir = true){
			
		}
		
		void print(){
			for(int i=0; i<V; i++){
				for(int j=0; j<V; j++){
					cout<<mat[i][j];
				}
				cout<<endl;
			}
		}
		
		void pushi(int u, int v, bool bidir = true){
			mat[u][v] = 1;
			if(bidir) mat[v][u] = 1;
		}
		
		void BFS(int src);

};



void Graph::BFS(int src){
	bool visited[V] = {0};
	queue<int> Q;
	Q.push(src);
	visited[src] = true;
	
	while(!Q.empty()){
		int node = Q.front(); Q.pop();
		for(int i=node; i<V;i++){
			cout<<"Node "<<i;
			for(int j=0; j<V; j++){
				if((!visited[j]) && mat[i][j] == 1){
					cout<<" Visited: "<<j;
					Q.push(j);
					visited[j] = true;
				}
				cout<<endl;
			}
			cout<<endl;
		}
	}
}




int main(){
	Graph g(6);
	g.pushi(0, 1);
	g.pushi(0, 2);
	g.pushi(1, 3);
	g.pushi(3, 2);
	g.pushi(3, 4);
	g.pushi(4, 5);
	
	g.BFS(0);
	g.print();
}
