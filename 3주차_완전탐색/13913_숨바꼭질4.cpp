/*내가 짠 코드 -> vector 
#include <bits/stdc++.h>
using namespace std;
int n,k;
int cnt[200004];
vector<int> v[200004];
int max_=200004;

int main(){
	
	cin >> n >> k;
	
	queue<int> q;
	q.push(n);
	cnt[n]=1;
	v[n].push_back(-1);
	
	while (true){
				
		int here = q.front(); q.pop();
		if(here==k) break;
		
		for(int there: {here+1, here-1, here*2}){
			if(there>=max_ || there<0 || cnt[there]) continue;
			
			q.push(there);
			cnt[there]=cnt[here]+1; 
			v[there].push_back(here);
		}
		
		
		
	}
	
	cout << cnt[k]-1 << "\n";
	vector<int> ret; 
	while(k != -1){ 
	    ret.push_back(k);
	    k = v[k][0]; 
	}   
	reverse(ret.begin(), ret.end());
	for(int i : ret) cout << i << "\n";
	return 0;
} 
*/
// 정답 코드-> prev 이용  
 #include <bits/stdc++.h>
using namespace std;
#define prev aaa
#define next aaaa
const int max_n = 200004;
int visited[max_n], prev[max_n], n, k, ret, here, cnt, next;   
vector<int> v; 
queue<int> q;  
int main() { 
    cin >> n >> k; 
    visited[n] = 1; 
    q.push(n);  
    while(q.size()){
        here = q.front();  
        q.pop();
        if(here == k){
            ret = visited[k]; 
            break;
        }
		for(int next : {here + 1, here - 1, here * 2}){
            if(next >= max_n || next < 0 || visited[next]) continue;  
            visited[next] = visited[here] + 1; 
            prev[next] = here; 
            q.push(next); 
		} 
    }   
    for(int i = k; i != n; i = prev[i]){
        v.push_back(i);
    }
    v.push_back(n);
    cout << ret - 1<< '\n'; 
    reverse(v.begin(), v.end());
	for(int i : v) cout << i << ' '; 
    return 0;
}
