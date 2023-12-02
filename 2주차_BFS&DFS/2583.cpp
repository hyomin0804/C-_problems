#include<bits/stdc++.h>
using namespace std;

int mp[101][101];
int visited[101][101];
int dy[]={-1, 0 , 1, 0};
int dx[]={0, 1 , 0, -1};
int n,m,k,a,b,c,d;
int cnt=1;
vector<int> ret;

int dfs(int y, int x){
	visited[y][x]=1; 
	int cnt = 1;
	for (int i=0; i<4; i++){
		int ny= y + dy[i];
		int nx= x + dx[i];
		
		
		if(nx<0 || ny<0 || nx>=n || ny>=m || mp[ny][nx]==1) continue;
		if(visited[ny][nx]) continue;
		cnt += dfs(ny, nx);
		
		
		
	}
	return cnt;
}



int main(){
	cin >> m >> n >> k;
	for (int i =0; i<k; i++){
		cin >> a >> b >> c >> d;
		
		for(int x=a; x<c; x++){
			for(int y=b; y<d; y++){
				mp[y][x]=1;
			}
		}
	}

	cout << "\n";
	
	for (int i=0; i<m; i++){
		for (int j=0; j<n; j++){
			if(mp[i][j]==0 && !visited[i][j]) {
				cnt = 1;
				ret.push_back(dfs(i,j));
			}
		}
	}
	sort(ret.begin(), ret.end());
	cout<< ret.size()<<"\n";
	for(int i : ret) cout << i <<" ";
	cout << "\n";
	
	for (int i=0; i<m; i++){
		for (int j=0; j<n; j++){
			cout << visited[i][j] << " ";
		}
		cout << "\n"; 
		
	}
		

	return 0;
}
