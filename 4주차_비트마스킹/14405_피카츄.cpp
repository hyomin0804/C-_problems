#include <iostream>
using namespace std;

string s;
int main(){
	cin >> s;
	while(true){
		if(s.size()>2 && s[0]=='p' && s[1]=='i'){
			s=s.substr(2);
			continue;
		}else if(s.size()>2 && s[0]=='k' && s[1]=='a'){
			s=s.substr(2);
			continue;
		}else if(s.size()>3 && s[0]=='c' && s[1]=='h' && s[2]=='u' ){
			s=s.substr(3);
			continue;
		}else break;
	}
	if(s.size()) cout << "NO";
	else cout << "YES";
	
	return 0;
} 
