#include <bits/stdc++.h>
using namespace std;


int main(){
	while (true){
		bool check=true;
		stack<char> stk;
		string s;
		getline(cin, s);
		if(s==".") break;
		
		for(char a: s){
			if(a==')' || a==']') {
				if(stk.size() ==0){
					check=false;
					break;
				}
				else if (a==')' && stk.top()=='(') stk.pop();
				else if (a==']' && stk.top()=='[') stk.pop();
				else check=false;
				
			}else if(a=='(' || a=='[') stk.push(a);
		
		
		}
		
		if(stk.size() || check==false){
			cout << "no\n";
			 
		} 
		else {
			cout << "yes\n";
		}
	}
	
	return 0;
} 
