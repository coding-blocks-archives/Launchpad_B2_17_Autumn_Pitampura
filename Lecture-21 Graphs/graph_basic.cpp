#include<iostream>
#include<list>
using namespace std;

class Graph{
	int V;
	list<int> *l;
public:
	Graph(int v){
		V = v;
		l = new list<int>[V];
	}

	void addEdge(int u,int v,bool bidir=true){
		l[u].push_back(v);
		
		if(bidir){
			l[v].push_back(u);
		}
	}

	void printAdjList(){
		for(int i=0;i<V;i++){
			cout<<i<<"->";

			for(int neighbour:l[i]){
				cout<<neighbour<<",";
			}
			cout<<"\b \b"<<endl;
		}
	}
	int dfsMoonHelper(int src,bool *visited){

		visited[src] = true;
		int ans = 1;

		for(auto neighbour:l[src]){
			if(!visited[neighbour]){
				int childCount = dfsMoonHelper(neighbour,visited);
				ans += childCount;
			}
		}
		return ans;
	}

	int dfsMoon(){
		bool *visited = new bool[V]{0};

		int ans = V*(V-1)/2;

		for(int i=0;i<V;i++){
			if(!visited[i]){
				int S = dfsMoonHelper(i,visited);
				ans = ans - (S)*(S-1)/2;
			}
		}
		return ans;
	}
};


int main(){

	Graph g(5);
	/*
	g.addEdge(0,4);
	g.addEdge(0,1);
	g.addEdge(1,3);
	g.addEdge(1,4);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(2,4);
	*/
	g.addEdge(0,1);

	g.addEdge(2,3);
	g.addEdge(0,4);

	cout<<g.dfsMoon()<<endl;


	return 0;
}