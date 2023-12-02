#include <bits/stdc++.h>
using namespace std;

const int INF =987654321;
int n, dp[16][1<<16], cost[16][16];
        // 현위치, 16개 도시 방문 경우의 수  
        
        
int tsp(int here, int visited){
	// 기저사례  
	if(visited==(1<<n)-1){ // 모든 지점을 방문했다면  
		return cost[here][0] ? cost[here][0] : INF;
		//cost[here][0]이 있다면 cost[here][0]을 반환 아니면 INF를 반환  
	} 
	//메모이제이션
	int &ret = dp[here][visited];
	if(ret != -1) return ret;
	ret =INF; // 최솟값은 최댓값부터 시작한다.
	
	for(int i=0; i<n; i++){
		if(visited & (1<<i)) continue; //방문 했다면 continue;
		if(cost[here][i]==0) continue; // 경로가 없다면 continue;
		//로직  
		ret =min(ret, tsp(i, visited | (1<<i)) + cost[here][i]) ;
	} 
	
	return ret;
}

int main (){
	
	cin >> n;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> cost[i][j];

		}
	}
	//초기화  
	memset(dp, -1, sizeof(dp)); // dp는 단지 상태 값 저장  
	cout << tsp(0,1) <<'\n';
	
	return 0;
} 
