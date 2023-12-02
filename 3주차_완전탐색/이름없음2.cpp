#include <bits/stdc++.h>
using namespace std;
int n,k,c=0,d=1;
vector<int> ret;
int visited[100004];

void go(int a, int b, int cnt){
	visited[a]=1;
	
	if(a==b) {
		ret.push_back(cnt-1);
		return;
	}
	if (a>b){
		go(a-1, b, cnt+1);
		visited[a-1]=0;
	}
	else {
		if(a+1 <= 100000 && visited[a+1]==0){
			go(a+1, b, cnt+1);
			visited[a+1]=0;
		}
		if(a*2 <= 100000 && visited[a*2]==0){
			go(a*2, b, cnt+1);
			visited[a*2]=0;
		}
	}
}

int main(){
	cin >> n >> k;
	
	visited[n]=1;
	go(n,k,c);
	
	sort(ret.begin(), ret.end());
	
	for(int i=1;i< ret.size();i++){
		if(ret[0]==ret[i]) d++;
	}
	
	cout << ret[0] << "\n";
	cout << d << "\n";
	
	return 0;
} 
