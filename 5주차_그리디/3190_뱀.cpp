#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
int n,a,c,d,mp[104][104],l,e,turn,idx;
char f,dir_;
vector<pair<int,char>> dir;
deque<pair<int,int>> dq;
int cnt,ccnt; 
int dy[]={0,-1,0,1};
int dx[]={1,0,-1,0};

int move(int y, int x){
	
	while (true){
		cnt++;
		int ny=y+dy[idx];
		int nx=x+dx[idx];
		
		if(ny<0 || nx <0 || ny>=n || nx>=n) break;
		if (find(dq.begin(), dq.end(), make_pair(ny, nx)) != dq.end()) break;
		if(mp[ny][nx]==1){
			dq.push_front({ny,nx});
			mp[ny][nx]=0;
			 
		}else {
			dq.push_front({ny,nx});
			dq.pop_back();

		}
		y=ny;
		x=nx;
		
		if(cnt == turn){
			if(dir_=='L') {
				idx= (idx+1) %4 ;
			}else{
				if(idx-1<0){
					idx=3;
				}else idx--;
			}
			ccnt++;
			turn=dir[ccnt].first;
			dir_=dir[ccnt].second;
		}
	}
	
	
	
	return cnt;
	
	
}


int main(){
	cin >> n;
	cin >> a;
	for(int i=0; i<a; i++){
		cin >> c >> d;
		mp[c-1][d-1]=1; // 사과  
	}
	cin >> l;
	for(int i=0; i<l; i++){
		cin >> e >> f;
		dir.push_back({e,f});
	}
	
	
	turn=dir[0].first; 
	dir_=dir[0].second;
	idx=0;
	dq.push_back({0,0});

	cout << move(0,0); // 머리 y,x,시간t  

	 
	return 0;
} 

/*
//visited 추가
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
int n,a,c,d,mp[104][104],l,e,turn,idx,visited[104][104];
char f,dir_;
vector<pair<int,char>> dir;
deque<pair<int,int>> dq;
int cnt,ccnt; 
int dy[]={0,-1,0,1};
int dx[]={1,0,-1,0};

int move(int y, int x){
	
	while (true){
		cnt++;
		int ny=y+dy[idx];
		int nx=x+dx[idx];
		
		if(ny<0 || nx <0 || ny>=n || nx>=n) break;
		//if (find(dq.begin(), dq.end(), make_pair(ny, nx)) != dq.end()) break;
		if(visited[ny][nx]) break;
		if(mp[ny][nx]==1){
			dq.push_front({ny,nx});
			mp[ny][nx]=0;
			visited[ny][nx]=1;
			 
		}else {
			dq.push_front({ny,nx});
			visited[dq.front().first][dq.front().second]=1;
			visited[dq.back().first][dq.back().second]=0;
			dq.pop_back();
		}
		y=ny;
		x=nx;
		
		if(cnt == turn){
			if(dir_=='L') {
				idx= (idx+1) %4 ;
			}else{
				if(idx-1<0){
					idx=3;
				}else idx--;
			}
			ccnt++;
			turn=dir[ccnt].first;
			dir_=dir[ccnt].second;
		}
		cout << "cnt: " << cnt << "\n";
		cout << "\n";
		for(int i=0 ;i<n; i++){
			for(int j=0; j<n; j++){
				cout << mp[i][j] << " ";
			}cout << "\n";
		}cout << "\n";
		
		cout << "\n";
		for(int i=0 ;i<n; i++){
			for(int j=0; j<n; j++){
				cout << visited[i][j] << " ";
			}cout << "\n";
		}cout << "\n";
		
	}
	
	return cnt;
	
	
}


int main(){
	cin >> n;
	cin >> a;
	for(int i=0; i<a; i++){
		cin >> c >> d;
		mp[c-1][d-1]=1; // 사과  
	}
	cin >> l;
	for(int i=0; i<l; i++){
		cin >> e >> f;
		dir.push_back({e,f});
	}
	
	
	turn=dir[0].first; 
	dir_=dir[0].second;
	idx=0;
	dq.push_back({0,0});
	visited[0][0]=1;
	cout << move(0,0); // 머리 y,x,시간t  

	 
	return 0;
}
*/
