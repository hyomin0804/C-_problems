#include <bits/stdc++.h>
using namespace std;

const int n=6;
bool visited[n];
vector<int> adj[n];

void dfs(int u){
	visited[u]=1;
	cout << u << '\n';
	for (int i : adj[u]){
		if(visited[i]==0){
			dfs(i);
		}
		// 돌다리도 두들겨보고 건너 
		//if(visited[i]) continue;
		//dfs(i);
		
		//못먹어도 go
		// if(visited[i]) return;
		visited[u]=1;
		//for (int i : adj[u]){
		//	dfs(i);
		//}
	}
	cout << u <<"로 부터 시작된 함수가 종료되었습니다.\n";
	return;
}

int main(){
	adj[1].push_back(2);
	adj[2].push_back(4);
	adj[2].push_back(5);
	adj[4].push_back(2);
	adj[1].push_back(3);
	dfs(1);
}
