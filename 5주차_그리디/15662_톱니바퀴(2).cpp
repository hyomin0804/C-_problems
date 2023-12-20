#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n,cnt,k,a,b;
string s;
vector<int> v[1000];
vector<int> chk;
bool toggle;
void check(){
	for(int i=0; i<n-1; i++){
 		//cout << v[i][2] << " ==" << v[i+1][6] << "\n";
		if(v[i+1][6]==v[i][2]){
			chk.push_back(1);
		}else chk.push_back(0);
	}
}

void rotate_(int i){
	if(toggle==1){
		//cout << "반시계\n";
		rotate(v[i].begin(),v[i].begin()+1,v[i].end());
		toggle=0;
	}else {
		rotate(v[i].rbegin(),v[i].rbegin()+1,v[i].rend());
	//cout << "시계\n";
		toggle=1;
	}
}

void move(int idx, int dir){
	chk.clear();
	check();
	int flag1=0,flag2=0;
	//cout << "방향" << dir << "\n";
//	for(int i=0; i<chk.size();i++) cout << chk[i] << " ";
//	cout << "\n";
	
	if(dir==1){ //시계  
		rotate(v[idx].rbegin(),v[idx].rbegin()+1,v[idx].rend());
		toggle=1;
		if(idx>0){
			for(int i=idx-1; i>=0; i--){
				if(chk[i]==1) flag1=1;
				if(!flag1){
					rotate_(i);
				}
			}
			//cout << "왼쪽 끝\n"; 
		}
		toggle=1;
		if(idx<n-1){
			for(int i=idx; i<n-1; i++){
				if(chk[i]==1) flag2=1;
				if(!flag2){
					rotate_(i+1);
				}
			}
			//cout << "오른쪽 끝\n"; 
		}
		
		
	}else { // 반시계  
		rotate(v[idx].begin(),v[idx].begin()+1,v[idx].end());
		toggle=0;
		if(idx>0){
			for(int i=idx-1; i>=0; i--){
				if(chk[i]==1) flag1=1;
				if(!flag1){
					rotate_(i);
				}
			}
			//cout << "왼쪽 끝\n"; 
		}
		toggle=0;
		if(idx<n-1){
			for(int i=idx; i<n-1; i++){
				if(chk[i]==1) flag2=1;
				if(!flag2){
					rotate_(i+1);
				}
			}
		//	cout << "오른쪽 끝\n"; 
		}
		
		
	}
	/*
	for(int i=0; i<n; i++){
		for(int j=0; j<8; j++){
			cout << v[i][j] << " ";
		}cout << "\n";
	}
	*/
	return;	
}
int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> s;
		for(int j=0; j<8; j++){
			v[i].push_back(s[j]-'0');
		}
	}
	
	cin >> k;
	for(int i=0; i<k; i++){
		cin >> a >> b;
		move(a-1,b);
	}
	for(int i=0; i<n; i++){
		if(v[i][0]==1) cnt++;
	}
	
	cout <<  cnt << "\n";
	return 0;
} 
