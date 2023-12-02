#include <bits/stdc++.h>
using namespace std;
string s;
int mp [55][55],d [55][55];
int visited [55][55];
int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};
int n,m;

int go(int a, int b){
	if( a>n || b> m || a<1 || b<1 || mp[a][b]=='H') return 0; 
	if(visited[a][b]){
		cout << -1 << "\n";
		exit(0);
	}
	//메모이제이션 
	int &ret=d[a][b];
	if(ret) return ret;
	
	visited[a][b]=1;
	int k=(int)mp[a][b] - '0';
	
	for(int i=0; i<4; i++){
		int ny=a+dy[i]*k;
		int nx=b+dx[i]*k;
		
		ret=max(ret, go(ny,nx)+1);
	} 
	visited[a][b]=0; // 원복  
	return ret;
	
}



int main(){
	cin >> n >> m;
	
	for(int i=1; i<=n; i++){
		cin >>s;
		for(int j=1; j<=m; j++){
			mp[i][j]= s[j-1];
		}
	}
	
	cout << go(1,1) << "\n";
	
	
	return 0;
} 
