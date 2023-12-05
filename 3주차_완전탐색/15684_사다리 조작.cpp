#include <bits/stdc++.h>
using namespace std;
const int INF=987564321;
int n,m,h,a,b,ret=INF;
int visited[34][34]
bool check(){
	
	
	for(int i=1; i<=n; i++){
		int start=i;
		for(int j=1; j<h; j++){
			if(visited[j][start]) start++;
			else if(visited[j][start-1]) start--;
		}
		if(start != i) return false;
	}
	
	return true;
} 

void go(int here, int cnt){
	//백트래킹 알고리즘, 사다리가 3개가 넘어가거나 기존 min 값보다 크면 무시 
	if(cnt > 3 || cnt >=ret ) return; 
	
	// i->i 인지 체크하고 만약 맞다면 최솟값 출력  
	if(check()){
		ret=min(ret,cnt); return;
	} 
	
 
	for(int i= here; i <=h; i++){ // 가로선: 행  
		for(int j=1; j<n; j++){ //세로선 방향으로 사다리 한개씩 추가, n에는 n+1까지 사다리 놔야해서 뻄  
			if(visited[i][j] || visited[i][j - 1] || visited[i][j + 1]) continue;
			visited[i][j] = 1;
            go(i, cnt + 1);
            visited[i][j] = 0;
		}
	}

} 

int main(){
	cin >> n >> m >> h;
	
	for(int i=0; i<m; i++){
		cin >> a >> b;
		visited[a][b]=1;
	}
	
	go(1,0); // 현재있는 세로선 , 추가한 사다리 개수  
	cout << (ret == INF) ? -1 :ret << "\n"; 
	return 0;
} 
