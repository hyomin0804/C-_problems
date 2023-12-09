#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

vector<int> adj[1004]; 
int visited[1004];

int t,n,m,a,b,cnt;

//dfs의 완전 기본형  
void dfs(int i){
	visited[i]=1;
	
	for(int k: adj[i]){
		if(!visited[k]) dfs(k);
	}
	
	return;
}

int main(){
	cin >> t;
	
	while(t--){
		cnt=0;

		memset(visited,0, sizeof(visited));
		memset(adj,0, sizeof(adj));
		cin >> n;
		cin >> m;
		
		for(int i=0; i<m; i++){
			cin >> a >> b;
			
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		
		for(int i=1; i<=n; i++){
			if(visited[i]==0){
				dfs(i);
				cnt++;
			}

		}
		//cout << "cnt: " << cnt << "\n";
		//cout << "n: " << n <<  " m: " << m <<"\n";
		if(m==n-1 && cnt==1) cout << "tree\n";
		else cout << "graph\n";
		
	}
	
	
	return 0;
}
