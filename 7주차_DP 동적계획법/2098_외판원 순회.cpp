#include <bits/stdc++.h>
using namespace std;

const int INF =987654321;
int n, dp[16][1<<16], cost[16][16];
        // ����ġ, 16�� ���� �湮 ����� ��  
        
        
int tsp(int here, int visited){
	// �������  
	if(visited==(1<<n)-1){ // ��� ������ �湮�ߴٸ�  
		return cost[here][0] ? cost[here][0] : INF;
		//cost[here][0]�� �ִٸ� cost[here][0]�� ��ȯ �ƴϸ� INF�� ��ȯ  
	} 
	//�޸������̼�
	int &ret = dp[here][visited];
	if(ret != -1) return ret;
	ret =INF; // �ּڰ��� �ִ񰪺��� �����Ѵ�.
	
	for(int i=0; i<n; i++){
		if(visited & (1<<i)) continue; //�湮 �ߴٸ� continue;
		if(cost[here][i]==0) continue; // ��ΰ� ���ٸ� continue;
		//����  
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
	//�ʱ�ȭ  
	memset(dp, -1, sizeof(dp)); // dp�� ���� ���� �� ����  
	cout << tsp(0,1) <<'\n';
	
	return 0;
} 
