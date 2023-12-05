#include <bits/stdc++.h>
using namespace std;

void postOrder(int here){
	if(visited[here]) continue;
	
	if(adj[here].size()==1) postOrder(adj[here][0]);
	if(adj[here.size()==2]) {
		postOrder(adj[here][0]); // ���ʺ��� Ž��  
		postOrder(adj[here][1]) // ���� �� ���� ������ Ž��  
	}
	
	// �� ���� �ڽ� �湮  
	visited[here]=1;
	cout << here << " "; // �湮 ���� ǥ��  
}

void preOrder(int here){
	if(visited[here]) continue;
	visited[here]=1; // ������ �湮�ȵǾ� ������ �湮  
	cout << here << " "; // �湮 ���� ǥ�� 
	
	if(adj[here].size()==1) preOrder(adj[here][0]);
	if(adj[here.size()==2]) {
		preOrder(adj[here][0]); // ���ʺ��� Ž��  
		preOrder(adj[here][1]) // ���� �� ���� ������ Ž��  
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
		inOrder(adj[here][0]); // ���ʺ��� Ž��
		
		inOrder[here]=1; // �߰��� �湮 
		cout << here << " "; // �湮 ���� ǥ��  
		  
		preOrder(adj[here][1]) // ���� �� ���� ������ Ž��  
	}
	
	 
}
int main(){
	adj[1].push_back(2);
	adj[1].push_back(3);
	
	adj[2].push_back(4);
	adj[2].push_back(5);
	
	int root=1; // ��Ʈ ��Ʈ 
	
	//Ʈ�� ��ȸ�� root ������ �����ϴ°� ����  
	cout << " ���� ��ȸ : postOrder \n";
	postOrder(root); memset(visited, 0, sizeof(visited));
	
	cout << " ����  ��ȸ : preOrder \n";
	preOrder(root); memset(visited, 0, sizeof(visited));
	
	cout << " ����  ��ȸ : inOrder \n";
	inOrder(root); memset(visited, 0, sizeof(visited));
	
	 
}
