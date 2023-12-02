#include <bits/stdc++.h>
using namespace std;
int n, INF=987654321; // ��� �� ��  �ִ� 10 
int a[11], m,temp,ret=INF, comp[11], visited[11];
vector<int> adj[11];


pair<int,int> dfs(int here, int value){
	visited[here]=1;
	pair<int,int> ret ={1, a[here]}; // ���� ��� ��: {���� �� ����� ������, �α����� ����} 
	
	
	for (int there: adj[here]){ // ���� ��� Ȯ��  
		if(comp[there] != value) continue; // ���� ���ڷ� ���� value�� ���� �޶�! 
		if(visited[there]) continue;
		pair<int,int> _temp =dfs(there, value);
		ret.first += _temp.first;
		ret.second += _temp.second; // �α��� ���� ��  
		}
		return ret;	
} 
// ������ 0�� 1 �ΰ��� ����  
int main (){
	cin >> n;
	for (int i=1; i<=n; i++){
		cin >> a[i]; // �� ������ �α� �� ���� 
		
	}
	for(int i=1; i<=n; i++){
		cin >> m;
		for(int j=0; j<m; j++){
			cin >>temp;
			adj[i].push_back(temp); // <- ���� �� �κ� 2���� ���Ϳ��� �����Ѱ� �ƴѰ�? 
			adj[temp].push_back(i); // ����� ����  
		}
	} 
	
	for (int i=1; i<(1<<n)-1;i++){ // ��带 ��ĥ�ϴ� ��� ����� ��  
		fill(comp, comp+11,0); // ��� ��ĥ�ϴ� �迭 �ʱ�ȭ  
		fill(visited, visited+11,0); //dfs �� �ʿ�  
		int idx1=-1, idx2 =-1;
		for(int j=0; j<n; j++){
			if(i & (1<<j)){ // ���� 1�� ������  
			comp[j+1]=1; // ��� ��ĥ, ���� 1���� �����ϱ� +1  
			idx1=j+1; // 1 ���� ���� �ε���  
			}
			else idx2=j+1; // 0���� ���� �ε���  
		} 
		pair<int,int> comp1=dfs(idx1,1);
		pair<int,int> comp2=dfs(idx2,0);
		if(comp1.first + comp2.first==n) ret = min(ret, abs(comp1.second-comp2.second));
		 // �ɰ��� ������ ���� ��ü n�� �Ǵ���, ���� 3���� �ɰ����� <nũ�⸦ ���� 
	}
	cout << (ret == INF ? -1: ret) <<"\n";
} 
