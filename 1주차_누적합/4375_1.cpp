/*
// ó�� �ۼ��� �ڵ� -> long long�� �޸� �ʰ���  
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a;
string s;

int main(){
	while(cin >> a){
		s='1';
		while(true){
			s+='1';
			ll k= atoi(s.c_str());
			if(k>a && k%a==0 ){
				cout << s.size() << "\n";
				break;
		}
		}
		
		
	}
	
	return 0;
} 
*/

#include<bits/stdc++.h>
using namespace std;  
typedef long long ll; 
int n;
int main(){ 
	while(cin>>n){
		int cnt = 1, ret = 1; 
		while(true){
			if(cnt % n == 0){
				cout <<ret << "\n";
				break;
			}else{
				cnt = (cnt * 10) + 1; 
				cnt %= n; 
				ret++;
			}
		} 
	}  
	return 0;
} 
