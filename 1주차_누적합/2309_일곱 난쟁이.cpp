/*
#include <bits/stdc++.h>
using namespace std;
int small[9];
vector<int> v;
void combi(int start, vector<int> b){
		
	if(b.size()==7 ){
		int sum=0;
		for(int i: b){
			sum+=small[i];
		}
		
		if( sum==100) {
			for(int j: b){
				v.push_back(small[j]);
			}
			sort(v.begin(),v.end());
			
			for(int i: v){
			cout << i << "\n";
			}
			exit(0);
		}
		
		return;
	}
	// ÀÎµ¦½º·Î °æ¿ìÀÇ ¼ö »Ì±â  
	for(int i=start+1; i<9; i++ ){
		
		b.push_back(i);
		combi(i, b);
		b.pop_back();
	}
	return;
	
}

int main(){
	for(int i=0; i<9; i++){
		cin >> small[i];
	}
	
	vector<int> b;
	combi(-1,b);
	
	
	return 0;
} 
*/

#include <bits/stdc++.h>
using namespace std;
int small[9];

int main(){
	for(int i=0; i<9; i++){
		cin >> small[i];
	}
	
	for(int i=0; i<(1<<9);i++){
		
		if (__builtin_popcount(i) == 7) {
			int sum=0;
			vector<int> v;
			for (int j = 0; j < 9; j++) {
                if (i & (1 << j)) {
                    sum += small[j];
                    v.push_back(small[j]);
                }
            }
            
			if(sum==100) {
				sort(v.begin(),v.end());
				
				for(int k: v){
				cout << k << "\n";
				
				}
				exit(0);
			}
			
		}
	}
	
	
	
	return 0;
} 
