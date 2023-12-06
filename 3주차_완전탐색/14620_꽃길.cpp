#include <bits/stdc++.h>
using namespace std;
const int INF=987654321;
int n,ret=INF,x,y,sum;
int mp[10][10];
int visited[10][10];
vector<pair<int,int>> v;

int dy[]={-1, 0, 1, 0};
int dx[]={0, 1, 0, -1};

struct A{
	int a,b,c;
};

vector<A> vv;

bool check(pair<int,int> a, pair<int,int> b, pair<int,int> c){
	
	for(auto i : {a,b,c}){
		tie(y,x) = i;
		
		visited[y][x]=1;
		for(int i=0; i<4; i++){
			int ny= y+dy[i];
			int nx= x+dx[i];
			if(ny>=n || nx >=n || ny<0 || nx<0 || visited[ny][nx]) return false;
			visited[ny][nx]=1;
		}
	}

	return true;
}

int cost(pair<int,int> a, pair<int,int> b, pair<int,int> c){
	sum=0;
	for(auto i : {a,b,c}){
		tie(y,x) = i;
		sum+=mp[y][x];
		
		for(int i=0; i<4; i++){
			int ny= y+dy[i];
			int nx= x+dx[i];
			sum+=mp[ny][nx];
		}
		
	}
	//cout << sum << "\n";
	return sum;
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> mp[i][j];
			v.push_back({i,j}); // 맵 전체 위치  
		}
	}
	
	for(int i=0; i<n*n; i++){
		for(int j=i+1; j<n*n; j++){
			for(int k=j+1; k<n*n; k++){
				vv.push_back({i,j,k}); // 세개 뽑는 경우 
				 
			}
		}
	}
	
	
	for(auto i : vv){
		memset(visited, 0, sizeof(visited));
		if(check(v[i.a] ,v[i.b] ,v[i.c] )){
			ret=min(ret, cost(v[i.a] ,v[i.b] ,v[i.c]));
		}
		
	}
	cout << ret;
	
	
	return 0;
} 
