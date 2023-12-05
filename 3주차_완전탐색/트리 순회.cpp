#include <bits/stdc++.h>
using namespace std;

void postOrder(int here){
	if(visited[here]) continue;
	
	if(adj[here].size()==1) postOrder(adj[here][0]);
	if(adj[here.size()==2]) {
		postOrder(adj[here][0]); // 왼쪽부터 탐색  
		postOrder(adj[here][1]) // 왼쪽 다 돌면 오른쪽 탐색  
	}
	
	// 그 다음 자신 방문  
	visited[here]=1;
	cout << here << " "; // 방문 순서 표시  
}

void preOrder(int here){
	if(visited[here]) continue;
	visited[here]=1; // 나부터 방문안되어 있으면 방문  
	cout << here << " "; // 방문 순서 표시 
	
	if(adj[here].size()==1) preOrder(adj[here][0]);
	if(adj[here.size()==2]) {
		preOrder(adj[here][0]); // 왼쪽부터 탐색  
		preOrder(adj[here][1]) // 왼쪽 다 돌면 오른쪽 탐색  
	}
	
	 
}

void inOrder(int here){
	if(visited[here]) continue;
	
	if(adj[here].size()==1){
		inOrder(adj[here][0]);
		visited[here]=1; 
		cout << here << " ";
	} 
	if(adj[here.size()==2]) {
		inOrder(adj[here][0]); // 왼쪽부터 탐색
		
		inOrder[here]=1; // 중간에 방문 
		cout << here << " "; // 방문 순서 표시  
		  
		preOrder(adj[here][1]) // 왼쪽 다 돌면 오른쪽 탐색  
	}
	
	 
}
int main(){
	adj[1].push_back(2);
	adj[1].push_back(3);
	
	adj[2].push_back(4);
	adj[2].push_back(5);
	
	int root=1; // 루트 노트 
	
	//트리 순회는 root 노드부터 시작하는게 좋음  
	cout << " 후위 순회 : postOrder \n";
	postOrder(root); memset(visited, 0, sizeof(visited));
	
	cout << " 전위  순회 : preOrder \n";
	preOrder(root); memset(visited, 0, sizeof(visited));
	
	cout << " 중위  순회 : inOrder \n";
	inOrder(root); memset(visited, 0, sizeof(visited));
	
	 
}
