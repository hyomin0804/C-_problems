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
		// ���ٸ��� �ε�ܺ��� �ǳ� 
		//if(visited[i]) continue;
		//dfs(i);
		
		//���Ծ go
		// if(visited[i]) return;
		visited[u]=1;
		//for (int i : adj[u]){
		//	dfs(i);
		//}
	}
	cout << u <<"�� ���� ���۵� �Լ��� ����Ǿ����ϴ�.\n";
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
