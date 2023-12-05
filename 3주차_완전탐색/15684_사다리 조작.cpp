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
	//��Ʈ��ŷ �˰���, ��ٸ��� 3���� �Ѿ�ų� ���� min ������ ũ�� ���� 
	if(cnt > 3 || cnt >=ret ) return; 
	
	// i->i ���� üũ�ϰ� ���� �´ٸ� �ּڰ� ���  
	if(check()){
		ret=min(ret,cnt); return;
	} 
	
 
	for(int i= here; i <=h; i++){ // ���μ�: ��  
		for(int j=1; j<n; j++){ //���μ� �������� ��ٸ� �Ѱ��� �߰�, n���� n+1���� ��ٸ� �����ؼ� �M  
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
	
	go(1,0); // �����ִ� ���μ� , �߰��� ��ٸ� ����  
	cout << (ret == INF) ? -1 :ret << "\n"; 
	return 0;
} 
