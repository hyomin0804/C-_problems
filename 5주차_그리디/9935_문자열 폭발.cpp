/*
// ���� �ۼ��� �ڵ� -> �ð� �ʰ�  
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
		auto a= s.find(bom); // �ð� ���⵵ n 
		s.erase(a, bom.size()); // �ð� ���⵵ n 
		// �� �ð� ���⵵ n!���� ��û ŭ  
		//cout << "���� �ε���" << a  << "~" << a+bom.size()-1 << "\n";
		//cout << "������ �� ���ڿ�" << s << "\n"; 
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
