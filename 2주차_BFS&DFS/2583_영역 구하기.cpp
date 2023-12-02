#include <bits/stdc++.h>
using namespace std;
#define y1 dsf // y1은 사용하려면 define 하고 해야함 
int n,m,k,ny,nx,x1,x2,y1,y2;
vector<int> v;
int cnt=0;
int dy[]={-1, 0, 1, 0};
int dx[]={0, 1, 0, -1};
int mp[100][100], visited[100][100];
int ret;

int dfs(int sy, int sx){
	ret++;
	visited[sy][sx]=2;
	for(int i=0; i<4; i++){
		
		ny= sy+ dy[i];
		nx= sx+ dx[i];
		
		if(nx<0 || nx>=m || ny>=n || ny<0 || mp[ny][nx]) continue;
		if(visited[ny][nx]) continue;
		dfs(ny,nx);
	}
	return ret;
}


int main(){
	cin >> n >> m >> k;
	
	for(int i=0; i<k; i++){
		cin >> x1 >> y1 >> x2 >> y2;
		
		for(int j=y1; j<y2; j++){
			for(int k=x1; k<x2; k++){
				mp[j][k]=1;
			}
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(mp[i][j] || visited[i][j]) continue;
			cnt++;
			ret=0;
			v.push_back(dfs(i,j));
		}
	}

	cout << cnt << "\n";
	sort(v.begin(),v.end());
	for(int i: v){
		cout << i << " ";
	}
	
	return 0;
} 
