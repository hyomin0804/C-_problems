#include <bits/stdc++.h>
using namespace std;
int n,a,k,root;
vector<int> v[54];

int dfs(int a){
	
	int cnt=0;  // 여기서 초기화 안하면 틀림... 
	int ret=0;
	
	for(int b : v[a] ){
		if( b==k) continue;
		ret+=dfs(b); // 밑에서부터 쌓아 올리면서 더함  
		cnt++;
	}
	if(cnt==0) return 1; // 리프 노드는 자식 없으니 1 반환  
	return ret;
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a;
		if( a== -1 ) root=i;
		else v[a].push_back(i);
	}
	cin >> k;
	
	if(k==root){
		cout << 0 << "\n";
		return 0;
	}

	cout << dfs(root) << "\n";
	return 0;
} 
