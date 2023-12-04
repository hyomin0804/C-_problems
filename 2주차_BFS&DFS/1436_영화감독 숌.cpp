
#include <bits/stdc++.h>
using namespace std;
int n;
// string s="666";
string ret;

int main(){
	cin >> n;
	int i=666;
	int cnt=0;
	for(;; i++){
		if(to_string(i).find("666") != string::npos){
			cnt++;
			if(cnt==n){
				cout << i;
				break;
			} 
			
			}
		}
	
	//cout << ret;
	return 0;
} 


	
		

