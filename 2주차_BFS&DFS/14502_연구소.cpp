#include <bits/stdc++.h>
using namespace std;
int n,m,a,x,y,ret;
int mp [10][10];
int visited [10][10];
vector<pair<int,int>> v,vv;
vector<vector<int>> sam;

int dy[]={-1, 0, 1, 0};
int dx[]={0, 1, 0, -1};

void bfs(int sy, int sx){
	
	queue<pair<int,int>> q;
	q.push({sy,sx});
	
	while (q.size()){
		
		tie(y,x)= q.front(); q.pop();
		
		for(int i=0; i<4; i++){
			int ny= y + dy[i];
			int nx= x + dx[i];
	
			if(nx>=m || ny >=n || nx<0 || ny<0) continue;
	
			if(visited[ny][nx] ==0){
				visited[ny][nx]=2;
				q.push({ny,nx});
			}
	
			
		}
	}
} 

int main(){
	cin >> n >> m;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> a;
			mp[i][j]=a;
			if(a==2){
				v.push_back({i,j});
			}
			if(a==0){
				vv.push_back({i,j});
			}
		}
	}
	
	// 벽 3개 고르기  
	for(int i=0; i< vv.size(); i++){
		for(int j=i+1; j< vv.size(); j++){
			for(int k=j+1; k< vv.size(); k++){
				sam.push_back({i,j,k});
			}
		}
	}
	
	  
	for(auto a: sam){
		
		memcpy(visited,mp,sizeof(mp));
		int cnt=0;
		
		// 벽 세우기
		for(int i: a){
			visited[vv[i].first][vv[i].second] = 1;
			//cout << " 벽: " << vv[i].first << ", " << vv[i].second << "\n";
		}
		
		// 바이러스 퍼뜨리기  
		for(auto a : v){
			visited[a.first][a.second]=2;
			bfs(a.first, a.second);
		}
		
		// 안전영역 개수 세기  
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(visited[i][j]==0) cnt++;
			}
		}
		ret=max(ret,cnt);

	}
	
	cout << ret;
	return 0;
} 
