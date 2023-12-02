/*
// 처음 내가 짠 코드 시간복잡도 10만*10만  
#include <bits/stdc++.h>
using namespace std;
int n,k,a,ret=-1,_ret;
vector<int> temp;
int main(){
	 
	cin>> n >> k;
	
	for (int i=0; i<n; i++){
		
		cin >> a;
		temp.push_back(a);
	}
	
	for(int j=0; j<n-k+1; j++){
		_ret=0;
		for(int i=j; i<j+k; i++){
		_ret+=temp[i];
		}
		ret=max(ret,_ret);
	}
	cout << ret;
	
	
	
	return 0;
}
*/
 // prefix 사용 
#include <bits/stdc++.h>
using namespace std;
int n,k,a,ret=-10000004,_ret; // 최솟값 잘 정하기 ㅠㅠ 100 * 10만 = 1000만   
int psum[100004];
vector<int> temp;
int main(){
	 
	cin>> n >> k;
	
	for (int i=1; i<=n; i++){
		
		cin >> a;
		psum[i]=psum[i-1]+a;
	}
	
	for(int j=n; j>=k; j--){
		ret=max(ret,psum[j]-psum[j-k]);	
	}
		
	cout << ret;
	
	
	
	return 0;
} }
