#include <bits/stdc++.h>
using namespace std;

int dy[]={-1, 0, 1 ,0};
int dx[]={0, 1, 0, -1};

int visited_f[1004][1004];
int visited_s[1004][1004];
const int INF=987564321;
int r,c,y,x,nx,ny,ret;
int mp[1004][1004];
char a;
pair<int,int> start_p,start_f;

void bfs_f(int sy, int sx){
	visited_f[sy][sx]=1;
	queue<pair<int,int>> q;
	q.push({sy,sx});
	
	while(q.size()){
		tie(y,x)= q.front(); q.pop();
		
		for(int i =0; i<4; i++){
			ny= y+dy[i];
			nx= x+dx[i];
			
			if(nx<0 || nx>c || ny>r || ny<0 || mp[ny][nx]==0 ) continue;
			if(visited_f[ny][nx] != INF) continue;
			visited_f[ny][nx]=visited_f[y][x]+1;
			q.push({ny,nx});
			
		}
		
	}

}

void bfs_p(int sy, int sx){
	visited_s[sy][sx]=1;
	queue<pair<int,int>> q2;
	q2.push({sy,sx});
	
	while(q2.size()){
		tie(y,x)= q2.front(); q2.pop();
		//벽을 제외한 가장자리 까지 왔다면  
		if(x==c-1 || y==r-1 || x==0 || y==0){
			ret=visited_s[y][x];
			break;
		}
		
		
		for(int i =0; i<4; i++){
			ny= y+dy[i];
			nx= x+dx[i];
			
			if(nx<0 || nx>c || ny>r || ny<0 || mp[ny][nx]==0) continue;
			if(visited_s[y][x]+1>=visited_f[ny][nx]) continue; // 불과의 이동 비교  
			if(visited_s[ny][nx]) continue;
			visited_s[ny][nx]=visited_s[y][x]+1;
			q2.push({ny,nx});
			
		}
		
	}

}


int main(){
	
	cin >> r >> c;
	fill(&visited_f[0][0],&visited_f[0][0]+1004*1004,INF ); // 불이 없을떄 고려 
	for (int i=0; i< r; i++){
		for(int j=0; j<c; j++){
			cin >> a;
			if (a=='J'){
				start_p=make_pair(i,j);
				mp[i][j]=1;
				//visited_p[i][j]=1;
			}
			else if(a=='F'){
				start_f=make_pair(i,j);
				
				mp[i][j]=1;
				//visited_f[i][j]=1;
			}else if (a=='.'){
				mp[i][j]=1;
			}else mp[i][j]=0;
			
		}
		
		
	}
	bfs_f(start_f.first, start_f.second);
	bfs_p(start_p.first, start_p.second);
	if(ret==0) cout << "IMPOSSIBLE ";
	else cout <<ret;
	return 0;
	
} 
