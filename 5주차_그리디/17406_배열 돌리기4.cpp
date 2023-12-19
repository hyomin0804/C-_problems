#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;
int mp[54][54],b[54][54],visited[54][54];
int n,m,k,r,c,s,min_=987654321;
int sy,sx,ex,ey,dir;
int dy[]={0,1,0,-1};
int dx[]={1,0,-1,0};

vector<int> vv;
vector<pair<int,int>> vvv;
struct a{
	int r,c,s;
};
vector<a> v;

void rotate_(int y, int x, int first){   
	if(!first && y == sy && x == sx) dir=0; 
	if(!first && y == sy && x == ex) dir++; 
	if(!first && y == ey && x == ex) dir++;
	if(!first && y == ey && x == sx) dir++; 
	int ny = y + dy[dir]; 
	int nx = x + dx[dir]; 
	if(visited[ny][nx]) return;
	visited[ny][nx] = 1; 
	vvv.push_back({ny, nx});
	rotate_(ny, nx, 0); 
	
}

void go(int y, int x, int c){
	// 센터 y,x에서 얼마나 떨어져 있는지  
	for(int i=1; i<=c; i++){
		sy = y - 1 * i; 
		sx = x - 1 * i; 
		ey = y + 1 * i; 
		ex = x + 1 * i; 
		dir=0;
		vvv.clear();
		memset(visited, 0, sizeof(visited)); 
		rotate_(sy,sx,1); //first 표시 =1 
		vector<int> turn; // 좌표값 기반으로 실제 값 저장  
		for(auto c: vvv) turn.push_back(b[c.first][c.second]);
		rotate(turn.rbegin(),turn.rbegin()+1, turn.rend());
		for(int i = 0; i < vvv.size(); i++) cout << turn[i] << " "; 
		cout << "\n";
		for(int i = 0; i < vvv.size(); i++) b[vvv[i].first][vvv[i].second] = turn[i]; 
	}
}

int main(){
	cin >> n >> m >> k;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> mp[i][j];
		}
	}
	for(int i=0; i<k; i++){
		cin >> r >> c >> s;
		v.push_back({r-1,c-1,s});
		vv.push_back(i);
	}
	
	do{
		memcpy(b, mp, sizeof(b));
		for(int i: vv){
			go(v[i].r, v[i].c, v[i].s);
		}
		for(int i=0; i<n; i++){
			int temp=0;
			for(int j=0; j<m; j++){
				temp+=b[i][j];
			}
			min_=min(min_, temp);
		}
	}while (next_permutation(vv.begin(), vv.end()));
	
	cout << min_ << "\n";
	return 0;
} 
