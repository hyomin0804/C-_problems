#include <bits/stdc++.h>
using namespace std;
int lo=1, hi, mid, ret=987654321,sum;
int n,m;

bool check(int mid, int a[]){ // int *a도 가능 
	int sam=0;
	int cnt=0;
	for(int i=0; i<n;i++){
		if(sam>mid) return 0; // mid 키워야함  
		
		sam+= a[i];
		if(sam>mid){
			cnt++; 
			sam=a[i];
		} 
		else if(sam==mid){
			cnt++; 
			sam=0;
		} 
	}
	if (sam > 0) cnt++;
	return m >= cnt; // mid 키워야함  
}
int main(){
	cin >> n >> m; // 강의 수 블루레이 개수 
	int a[n];
	for(int i=0; i<n; i++){
		cin >> a[i];
		sum+=a[i];
		hi=sum;
	}
	while(lo<=hi){
		mid=(lo+hi)/2;
		
		if(check(mid, a)){
			
			ret=min(ret,mid);
			hi=mid-1;
			
		}else lo=mid+1;
	}
	
	cout << ret << "\n"; 

	return 0;
} 
