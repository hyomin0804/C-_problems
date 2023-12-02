#include <bits/stdc++.h>
using namespace std;

const int V=10;
vector<int> adj[V];
bool visited[V];

void go(int idx){
	cout << idx << '\n';
	
	visited[idx]=1;
	
	for(int i : adj[idx]){
		if(visited[i]) continue;
		go(i);
	}
	
}

int main(){
	adj[1].push_back(2);
	adj[1].push_back(3);
	
	adj[3].push_back(1);
	adj[3].push_back(4);
	
	adj[4].push_back(3);
	
	for(int i=0; i<10; i++){
		if(adj[i].size() && visited[i]==0) go(i); // 연결된 정점이 있다면 
	}
	return 0;

} 
