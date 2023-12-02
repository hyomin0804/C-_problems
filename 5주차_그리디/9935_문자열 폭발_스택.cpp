#include <bits/stdc++.h>
using namespace std;
string s, bom;
stack<char> stk;
string ret="";
int main(){
	cin >> s;
	cin >> bom;
	
	for(char a: s){
		stk.push(a);
		if( stk.size() >= bom.size() && stk.top() == bom[bom.size()-1] ){
			string ss="";
			for(int i=0; i<bom.size(); i++){
				ss+=stk.top(); stk.pop();
			}
			reverse(ss.begin(), ss.end());
			if(bom != ss){
				for(int j: ss){
					stk.push(j);
				}
			}
		}
		}
		
		if( stk.size()==0 ) cout <<  "FRULA\n";
		else{
        while(stk.size()){
            ret += stk.top(); stk.pop();
        }
        reverse(ret.begin(), ret.end()); 
        cout << ret << "\n";
    }

		
		
	return 0;
	
}
