#include <bits/stdc++.h>
using namespace std;
string x;
char aeiou[]={'a','e','i','o','u'};
int cnt;


bool isaei(char a){
	return (a=='a' || a =='e' || a=='i' || a=='o' || a=='u');
}

bool check(string s){
	bool flag =1;
	string ss="";
	int cnt=0;			
	for(int i=0; i<s.size();i++){
		
		if(isaei(s[i])){
		 	ss+='1'; // 모음일때 1 
		}else{
			cnt++;
		 	ss+='0'; // 자음일 때  0
		 	if (cnt==s.size()) {
		 		//cout << "모음 포함 안됨\n ";
		 		flag=0;
			 }
		}
		
		//같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다.
		if(s.size()>=2 && i<s.size()-1 && s[i]==s[i+1]){
			if(s[i]!='e' && s[i]!='o') {
				//cout << "같은 글자 2번\n";
				flag=0;
			}
		} 
	}
//	cout << "ss=" << ss << "\n" ;
	//모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
	long long pos1=0,pos2=0; 
	pos1=ss.find("000");
	pos2=ss.find("111");
	if (pos1 != string::npos || pos2 != string::npos){
		//cout << "모음 3개 혹은 자음이 3개 연속됨\n";
		flag=0;
	} 

	return flag;
}

int main(){
	while(true){
		
		cin >> x;
		if(x == "end") break;
		
		if(check(x)) cout << "<" << x << "> is acceptable.\n";
		else cout << "<" << x << "> is not acceptable.\n";
	}
	
	
	return 0;
} 
