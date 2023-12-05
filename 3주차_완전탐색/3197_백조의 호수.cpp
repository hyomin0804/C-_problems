#include <bits/stdc++.h>
using namespace std;
int r,c,cnt,x,y;
string s;
bool flag;

pair<int,int> s1, s2;
char mp[1504][1504];
int visited[1504][1504];
int visited2[1504][1504];

int dy[]={-1, 0, 1, 0};
int dx[]={0, 1, 0, -1};

queue<pair<int,int>> waterQ,water_tempQ,swanQ,swan_tempQ;

// &이 연산자로 원본까지 수정  
void Qclear(queue<pair<int, int>> &q){
   queue<pair<int, int>> empty;
   swap(q,empty);
} 

void water_melting(){
	
    while(waterQ.size()){
    	
		tie(y, x) = waterQ.front(); waterQ.pop();
		
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= r || nx < 0 || nx >= c || visited[ny][nx])continue;
            if(mp[ny][nx] == 'X'){
                visited[ny][nx] = 1; 
                water_tempQ.push({ny, nx});
                // 물로 바꾸기  
                mp[ny][nx] = '.'; 
            } 
        }
    }
}

bool check(){
	
	while(swanQ.size()){
		tie(y,x)=swanQ.front();swanQ.pop();
		
		for(int i=0; i<4; i++){

			int ny= y+ dy[i];
			int nx= x + dx[i];
			
			if(ny>=r || nx>=c || ny<0 || nx<0) continue;
			if(visited2[ny][nx]) continue;
			visited2[ny][nx]=visited2[y][x]+1; // 미리 방문할 벽도 방문 처리  
			
			if(mp[ny][nx] == '.') swanQ.push({ny,nx});
			else if(mp[ny][nx] == 'X') swan_tempQ.push({ny, nx});
            else if(mp[ny][nx] == 'L') return true;
		}
	}
	
	return false;
	
	
} 

int main(){
	cin >> r >> c;
	for(int i=0; i<r; i++){
		cin >>s;
		for(int j=0; j<c; j++){
			mp[i][j]=s[j];
			if (s[j]=='.' || s[j]=='L') visited[i][j]=1, waterQ.push({i,j}); 
			if(s[j]=='L' &&flag==0){
				s1={i,j};
				flag=1;
			}else if(s[j]=='L' &&flag==1){
				s2={i,j};
			}
		}
	}
	
	swanQ.push({s1.first, s1.second});
	visited2[s1.first][s1.second]=1;
	
	while (true){
		//백조 만나는지 체크  
		if(check()) break; 
		
		// 녹이기  
		water_melting();
		
		//초기화  
		waterQ = water_tempQ;
		swanQ = swan_tempQ;
		
        Qclear(water_tempQ);
        Qclear(swan_tempQ);
		
		// 하루 더하기  
		cnt++; 
		
		
	}
	
	cout << cnt << "\n";
	
	return 0;
}
