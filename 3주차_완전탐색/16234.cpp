# include<bits/stdc++.h>
using namespace std;
int n,l,r,nx,ny,cnt2,sum;

int mp[51][51];
int visited[51][51];
int dy[]={-1, 0, 1, 0};
int dx[]={0, 1, 0, -1};
vector<pair<int,int>> v;

void dfs(int y, int x, vector<pair<int,int>> &v){
	
	
	for(int i=0; i<4; i++){
		ny= y+dy[i];
		nx= x + dx[i];
		
		if (nx<0 || ny<0 || nx >= n || ny>=n || visited[ny][nx]) continue;
		if(l<=abs(mp[y][x]-mp[ny][nx]) && r>=abs(mp[y][x]-mp[ny][nx]) ){
			visited[ny][nx]=1;
			v.push_back({ny,nx});
			sum += mp[ny][nx];
			
			dfs(ny,nx,v);
		}
		
	}
}

int main(){
	
	cin >> n >> l >> r;
	
	for (int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> mp[i][j];
		}
	}
	
	while(true){
		bool flag=0 ; // 인구 이동이 일어났나 안일어났나 
		fill(&visited[0][0],&visited[51][51],0);
		
		
		for (int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(visited[i][j]==0){
					v.clear();
					visited[i][j]=1;
					v.push_back({i,j});
					sum=mp[i][j];
					dfs(i,j,v);
					if(v.size()==1) continue;// 인구 이동 조건을 만족한 블록이 없을 경우 continue 
					for(pair<int,int> b:v){ //맵 업데이트(인구이동) 
						mp[b.first][b.second]=sum/v.size();
						flag=1;
					}
				} 
				}
			}
		
		
		if(!flag) break; 
		cnt2++;
	}
	
	cout << cnt2 << '\n';
	return 0;
} 
