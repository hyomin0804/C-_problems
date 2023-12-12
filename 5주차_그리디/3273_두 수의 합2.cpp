/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,a,b,s,e,ret;
vector<int> v;

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a;
		v.push_back(a);
	}
	cin >> b;
	sort(v.begin(),v.end());
	s=0;
	e=1;

	while(s!=n){
		if(e==n){
			s++;
			e=s;
			
		}if(v[s]+v[e]>b){
			s++;
			e=s;
		}
		if(v[s]+v[e]==b) {
			//cout << s << " " << e << "\n";
			ret++;
			s++;
			e=s;
		}
		e++;
	}
	cout << ret; 
	return 0;
} 
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,a,b,s,e,ret;
vector<int> v;

int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a;
		v.push_back(a);
	}
	cin >> b;
	sort(v.begin(),v.end());
	s=0;
	e=n-1;

	while(s<e){
		if(v[s]+v[e]>b){
			e--;
		}else if(v[s]+v[e]<b){
			s++;
		}else {
			ret++;
			e--;
		}
	}
	cout << ret; 
	return 0;
} 
