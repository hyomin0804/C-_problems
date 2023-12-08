#include <bits/stdc++.h>
using namespace std;
int n,m,mp[50][50], visited[50][50];
int cnt,ret,maxx;
int comp[50];
int dy[]={0, -1, 0, 1};
int dx[]={-1, 0, 1, 0};


int dfs(int y, int x, int cnt){
	
	visited[y][x]=cnt;
	
	int sum=1;
	for(int i=0; i<4; i++){
		if( mp[y][x] & (1<<i) ) continue; 
		
		int ny= y+dy[i];
		int nx= x+dx[i];

		if(nx<0 || ny<0 || nx>=m || ny>=n || visited[ny][nx]) continue;
		
		sum+=dfs(ny,nx,cnt);
		
		
	}
	return sum;
}


int main(){
	cin >> m >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> mp[i][j];
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(visited[i][j]) continue;
			cnt++;
			comp[cnt]=dfs(i,j,cnt);
			ret=max(ret,comp[cnt]);
		}
	}
	
	//모든 칸의 벽의 유무를  확인하면서 하나씩 허물어보기  
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			//네개의 방향에 있는 벽 확인 
			for(int k=0; k<4; k++){
					int a= i+dy[k];
					int b= j+dx[k];
					//cout<< "나 여기 1"<< "\n";
					if(b<0 || a<0 || b>=m || a>=n) continue;
					if( visited[i][j] == visited[a][b]) continue; // 벽 사이의 영역 cnt값이 다르다면  
					int neww=comp[visited[i][j]]+comp[visited[a][b]];
					maxx=max(maxx, neww);
					
				}
			
			}	
		}
	
	cout << cnt << "\n";
	cout << ret << "\n";
	cout << maxx << "\n";
	
	return 0;
} 
