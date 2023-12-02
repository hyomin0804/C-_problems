#include <bits/stdc++.h>
using namespace std;
int n;
string a,s;
bool flag=0;
char f,l;
vector<char> v1,v2;
vector<string> s1;
int cnt1,cnt2;

int main() {
	cin >> n;
	cin >> a;
	for(char i: a){
		if(i=='*') {
			flag=1; 
			continue;
		}
		if(flag==0) v1.push_back(i);
		else v2.push_back(i);
	}
	
	for(int i=0; i<n; i++){
		cin >> s;
		s1.push_back(s);	
	}

	
	for(int i=0; i<n; i++){
		cnt1=0;
		cnt2=0;
		for(int j=0;j<v1.size();j++){
			if(v1[j]==s1[i][j]) cnt1++;
			//cout << "앞자리"<<v1[j] << " " << s1[i][j] << "\n";
		}
		for(int j=0;j<v2.size();j++){
			int k= s1[i].size()-v2.size()+j;
			if(v2[j]==s1[i][k]) cnt2++;
			//cout << "뒷 자리"<<v2[j] << " " << s1[i][k] << "\n";
		}
		if(cnt2+cnt1<=s1.size()){ //이 반례 중요 ab*ab 일때 ab는 안되어야함 
			if(cnt1==v1.size() && cnt2==v2.size()) cout << "DA\n";
			else cout << "NE\n";
		}else cout << "NE\n";
		
	}
	
	return 0;
	
} 

// 정답 코드 
#include<bits/stdc++.h> 
using namespace std;   
int n; 
string s, ori_s, pre, suf; 
int main(){
    cin >> n;
    cin >> ori_s;  
    int pos = ori_s.find('*');  
    pre = ori_s.substr(0, pos); 
    suf = ori_s.substr(pos + 1); 
    for(int i = 0; i < n; i++){
        cin >> s; 
        if(pre.size() + suf.size() > s.size()){
            cout << "NE\n";
        }else{
            if(pre == s.substr(0, pre.size()) && suf == s.substr(s.size() - suf.size())) cout << "DA\n";
            else cout <<"NE\n";  
        } 
    } 
    return 0;
}  
