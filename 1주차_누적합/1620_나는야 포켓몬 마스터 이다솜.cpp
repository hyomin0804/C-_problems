#include <bits/stdc++.h>
using namespace std;
map<int,string> poke;
map<string,int> poke2;
int n,m;
string a;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> a;
		poke[i]=a; //int - string
		poke2[a]=i; // string - int
	}
	
	for(int i=0; i<m; i++){
		string k;
		cin >> k;
		if(atoi(k.c_str())){ //숫자 라면
			cout << poke[atoi(k.c_str())] << "\n";
		}else{ //문자라면  
			cout << poke2[k] << "\n";
		}
		
	}
	
	return 0;
}
