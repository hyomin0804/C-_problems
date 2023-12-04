#include <bits/stdc++.h>
using namespace std;
int t;
string s;


int main(){
	cin >> t;
	while(t--){
		cin >> s;
		stack<char> stk;
		
		for(char a: s){
			
			if(stk.size()>=1){
				if(a==')' && stk.top()=='('){
					stk.pop();
				}else{
					stk.push(a);
				} 
			}else{
				stk.push(a);
			} 
			
		}
		
		if(stk.size())	cout << "NO" << "\n";
		else cout << "YES" << "\n";
	}
		
	return 0;
} 
