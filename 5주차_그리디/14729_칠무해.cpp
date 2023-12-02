// 내 코드  -> 통과  
#include <bits/stdc++.h>
using namespace std;
int n;
double a;
int main(){
	priority_queue<double, vector<double>, greater<double>> pq;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a;
		pq.push(a);
	}
	
	for(int i=0; i<7; i++){
		printf("%.3lf\n", pq.top());
		pq.pop();
	}
}

//정답 코드  
#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int)(x).size())    
#define f first
#define s second
typedef unsigned long long ll; 
const int INF = 987654321; 
int n;
double temp;
priority_queue<double> pq; 
vector<double> v; 
int main () {
	cin >> n; 

	for(int i = 0; i < n; i++){
		cin >> temp;
		if(pq.size() == 7){ //pq에는 항상 7개만 있도록 -> 가장 큰 값부터 없애기 
			pq.push(temp); pq.pop();
		}else pq.push(temp); 
	}
	while(pq.size()){
		v.push_back(pq.top()); pq.pop();
	}
	reverse(v.begin(), v.end()); 
	for(double i : v) printf("%.3lf\n", i); 
	return 0;
}
[출처] [알고리즘 강의] 5주차. 그리디 라인스위핑 투포인터|작성자 큰돌
