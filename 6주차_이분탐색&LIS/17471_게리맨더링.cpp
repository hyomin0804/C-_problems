#include <bits/stdc++.h>
using namespace std;
int n, INF=987654321; // 노드 개 수  최대 10 
int a[11], m,temp,ret=INF, comp[11], visited[11];
vector<int> adj[11];


pair<int,int> dfs(int here, int value){
	visited[here]=1;
	pair<int,int> ret ={1, a[here]}; // 담을 결과 값: {연결 된 노드의 사이즈, 인구수의 총합} 
	
	
	for (int there: adj[here]){ // 연결 노드 확인  
		if(comp[there] != value) continue; // 내가 인자로 받은 value와 색이 달라! 
		if(visited[there]) continue;
		pair<int,int> _temp =dfs(there, value);
		ret.first += _temp.first;
		ret.second += _temp.second; // 인구수 더하 기  
		}
		return ret;	
} 
// 구역을 0과 1 두개로 나눔  
int main (){
	cin >> n;
	for (int i=1; i<=n; i++){
		cin >> a[i]; // 각 구역의 인구 수 저장 
		
	}
	for(int i=1; i<=n; i++){
		cin >> m;
		for(int j=0; j<m; j++){
			cin >>temp;
			adj[i].push_back(temp); // <- 여기 이 부분 2차원 벡터여야 가능한거 아닌가? 
			adj[temp].push_back(i); // 양방향 연결  
		}
	} 
	
	for (int i=1; i<(1<<n)-1;i++){ // 노드를 색칠하는 모든 경우의 수  
		fill(comp, comp+11,0); // 노드 색칠하는 배열 초기화  
		fill(visited, visited+11,0); //dfs 때 필요  
		int idx1=-1, idx2 =-1;
		for(int j=0; j<n; j++){
			if(i & (1<<j)){ // 만약 1을 만나면  
			comp[j+1]=1; // 노드 색칠, 노드는 1부터 있으니까 +1  
			idx1=j+1; // 1 구역 시작 인덱스  
			}
			else idx2=j+1; // 0구역 시작 인덱스  
		} 
		pair<int,int> comp1=dfs(idx1,1);
		pair<int,int> comp2=dfs(idx2,0);
		if(comp1.first + comp2.first==n) ret = min(ret, abs(comp1.second-comp2.second));
		 // 쪼개진 구역의 합이 전체 n이 되는지, 만약 3개로 쪼개지면 <n크기를 가짐 
	}
	cout << (ret == INF ? -1: ret) <<"\n";
} 
