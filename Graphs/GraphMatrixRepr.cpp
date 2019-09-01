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

};


int main(){
	Graph g(4);
	g.pushi(0, 1);
	g.pushi(0, 2);
	g.pushi(1, 2);
	g.pushi(1, 3, false);
	
	g.print();
}
