#include<iostream>
#include<unordered_map>
#include<map>
#include<list>
#include<queue>
using namespace std;

template<typename T>
class Graph{
	
	unordered_map<T,list<T> > adjList;
public:

	void addEdge(T u,T v,bool bidir=true){
		adjList[u].push_back(v);
		if(bidir){
			adjList[v].push_back(u);
		}
	}

	void printAdjList(){

		for(auto row:adjList){
			T key = row.first;
			cout<<key<<"->";

			for(auto city:row.second){
				cout<<city<<",";
			}
			cout<<endl;
		}

	}
	void bfs(T source,T dest){
		queue<T> q;
		q.push(source);

		unordered_map<T,bool> visited;
		map<T,int> dist;
		map<T,T> parent;

		visited[source] = true;
		dist[source] = 0;
		parent[source]  = source;

		while(!q.empty()){
			T temp = q.front();
			//cout<<temp<<" ";
			q.pop();

			for(auto neighbour:adjList[temp]){
				if(!visited[neighbour]){
					q.push(neighbour);
					visited[neighbour] = true;
					dist[neighbour] = dist[temp] + 1;
					parent[neighbour]  = temp;
				}
			}
		}
		
		/*for(auto p:dist){
			cout<<p.first<<" and "<<p.second<<endl;
		}*/
		cout<<dist[dest]<<endl;
		//Path
		T temp  = dest;
		while(temp!=source){
			cout<<temp<<"<---";
			temp = parent[temp];
		}
		cout<<source<<endl;
	}

	void dfsHelper(T src,map<T,bool>&visited){

		visited[src] = true;
		cout<<src<<" ";

		for(auto neighbour:adjList[src]){
			if(!visited[neighbour]){
				dfsHelper(neighbour,visited);
			}
		}
	}

	void dfs(T source){
		map<T,bool> visited;
		dfsHelper(source,visited);		
	}
};

int main(){
	/*
	Graph<int> g;
	g.addEdge(0,4);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(2,4);
	g.addEdge(4,3);
	g.addEdge(3,5);

	g.bfs(0);

	
	Graph<string> g2;
	g2.addEdge("Amritsar","Jaipur");
	g2.addEdge("Amritsar","Delhi");
	g2.addEdge("Delhi","Jaipur");
	g2.addEdge("Delhi","Agra");

	//g2.printAdjList();
	g2.bfs("Amritsar");
	*/

	Graph<int> g;
	int board[50] = {0};
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = -10;
    board[32] = -2;
    board[34] = -22;

    for(int u=1;u<=36;u++){
    	for(int dice=1;dice<=6;dice++){
    		int v = u + dice;
    		v += board[v];

    		g.addEdge(u,v,false);
    	}
    }

    //g.bfs(1,36);

    g.dfs(1);



	return 0;
}