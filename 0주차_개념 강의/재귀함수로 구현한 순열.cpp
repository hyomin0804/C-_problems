#include <bits/stdc++.h>
using namespace std;
 
int n=9, r=7;
int a[9];

void print(){
	for(int i=0; i<r; i++) c out << a[i] << " ";
	cout<<"\n";
}

void solve(){
	int sum =0; 
	for(int i=0; i<r;i++) sum+=a[i];
	
	if(sum==100){
		sort(a,a+7);
		for(int i=0; i<r;i++) cout << a[i] << "\n";
		exit(0);// return을 하면 solve만 종료되지만 exit 하면 main 함수까지 종료
	}
}

void makePermutation (int n,int r, int depth){
	//기저사례 
	if (r==depth){
		solve();
		return;
	}
	
	for (int i=depth; i<n; i++){
		swap(a[i],a[depth]);
		makePermutation(n,r,depth+1);
		swap(a[i],a[depth]); 
	}
	
	return;
}

int main(){
	for(int i =0; i<9; i++) cin >> a[i];
	makePermutation(n,r,0);
	return 0;
}
