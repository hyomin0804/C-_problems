#include <bits/stdc++.h>
using namespace std;
int n;
char a;
vector<char> v1;
vector<string> ret;

bool cmp(string a, string b){
	
	if( a.size()==b.size() ){
		return a<b;
	}
	return a.size() < b.size();
}

void check(vector<int> v){

	for(int i=0; i< n; i++){
		if(v1[i]=='<'){
			if( v[i] < v[i+1] ) continue;
			else return;
		}else if(v1[i]=='>'){
			if( v[i] > v[i+1] ) continue;
			else return;
		}
	}
	
	string str;
	for(int i: v) {
		str+= i +'0';
	}

	ret.push_back(str);
	return;
}

void combi(int start, vector<int> vv){
	
	if(vv.size()==n+1) {

		do{
			check(vv);
		}while(next_permutation(vv.begin(),vv.end()));
		return;
	}
	
	for(int i=start+1 ; i<10; i++){
		vv.push_back(i);
		combi(i,vv);
		vv.pop_back();
	}
	

	return ;
}

int main(){
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >>a;
		v1.push_back(a);
	}
	vector<int> vv;
	combi(-1,vv);
	
	sort(ret.begin(),ret.end(), cmp);
	
	//for(string i: ret) cout << i << "\n";
	cout << ret.back() << "\n";
	cout << ret.front() << "\n";
	return 0;
} 
