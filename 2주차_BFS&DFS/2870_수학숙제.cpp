#include <bits/stdc++.h>
using namespace std;
int n;
string s, ss="";
vector<string> v;

// ���ڿ� ���� ũ�� ��  
bool cmp(string a, string b){
	if(a.size() == b.size()) return a<b;
	return a.size() <b.size();
}

void go (){
	while (true){
		if(ss.size() && ss.front()=='0') ss.erase(ss.begin());
		else break;
		
	}
	if(ss.size()==0) ss="0";
	v.push_back(ss);
	ss=""; // ss �ʱ�ȭ  
	return;
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> s;
		ss="";

		for(int a=0; a<s.size(); a++){
			// ���ڶ��  
			if(isdigit(s[a])) ss+=s[a];
				
			else{ // ���ڶ��  
				if(ss.size()){
					//���ݱ��� ���� ���ڿ�  
					go();
				}
				
			}
					
		}
		if(ss.size()) go();
	}
	
	sort(v.begin(), v.end(),cmp);
	for(string i: v){
		cout << i << "\n";
	} 
	
	return 0;
} 
