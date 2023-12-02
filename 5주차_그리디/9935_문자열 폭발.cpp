/*
// 내가 작성한 코드 -> 시간 초과  
#include <bits/stdc++.h>
using namespace std;
string s, bom;

int main(){
	cin >> s;
	cin >> bom;
	
	while(true){
		if(s.find(bom)==string::npos) {
			if(s.size()==0) cout <<  "FRULA\n";
			else cout << s << "\n";
			break;
		}
		auto a= s.find(bom); // 시간 복잡도 n 
		s.erase(a, bom.size()); // 시간 복잡도 n 
		// 총 시간 복잡도 n!으로 엄청 큼  
		//cout << "지울 인덱스" << a  << "~" << a+bom.size()-1 << "\n";
		//cout << "지워진 후 문자열" << s << "\n"; 
		}
	
	return 0;
	
} 
*/

#include <bits/stdc++.h>
using namespace std;
string s, ss="", bom;

int main(){
	cin >> s;
	cin >> bom;
	
	for(char a: s){
		ss+=a;	
		if(ss.size()>=bom.size()){
			string b= ss.substr(ss.size()-bom.size(), bom.size());
			if(b==bom) ss.erase(ss.size()-bom.size(), bom.size());
		}
	}
	
	if(ss.size()==0) cout <<  "FRULA\n";
	else cout << ss << "\n";
		
		
	return 0;
	
} 
