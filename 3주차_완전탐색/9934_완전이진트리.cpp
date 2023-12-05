#include <bits/stdc++.h>
using namespace std;
int n,a,depth;
vector<int> v;
vector<int> ret[1050];
int visited[1050];

void go(int depth){
	int a=0;
	while(visited[a]) a+=1;

	int start=a;
		
	for(int i=0; i<=(1<<n)-1 ; i += (1 << depth)){
		ret[depth].push_back(v[start+i]);
		//cout <<  " 방문 노드: " << v[start+i] << "\n"; 
		visited[start+i]=1;
	}
	
}

int main(){
	cin >> n;
	for(int i=0; i<(1<<n)-1; i++){
		cin >>a;
		v.push_back(a);
	}

	for(int i=1; i<n+1 ;i++){
		go(i);
	}
	
	for(int i=n; i!= 0; i--){
		for(int a: ret[i]){
			cout << a << " ";
			
		}cout << "\n";
	}
	
	return 0;
} 
