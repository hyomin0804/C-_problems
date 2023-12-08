#include <bits/stdc++.h>
using namespace std;
int t,a,m;
string s;

void calc(string s, int a){
	if(s=="add"){
		m |= (1<<a);
	}else if(s== "remove"){
		m &= ~(1<<a);
	}else if(s=="check"){
		if( m &= (1<<a)) cout << "1\n";
		else cout << "0\n";
		
	}else if(s=="toggle"){
		m ^=(1<<a);
	}else if(s=="all"){
		m=(1<<21)-1;
	}else if(s=="empty"){
		m=0;
	}
	
	return;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	cin.ignore();
	//getline(cin, s);
	
	for(int i=0; i<t; i++){
		getline(cin, s);
		auto l= s.find(" ");

		if(l==string::npos){
			calc(s,0);
			//cout << s << "\n";

		}else{
			//cout <<"문자: " <<s.substr(0,l) << " 숫자: " << atoi(s.substr(l+1).c_str()) << "\n";
			calc(s.substr(0,l),atoi(s.substr(l+1).c_str()) );
		}
		
	}

	return 0;
} 
