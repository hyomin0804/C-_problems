// �� �ڵ�  -> ���  
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

//���� �ڵ�  
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
		if(pq.size() == 7){ //pq���� �׻� 7���� �ֵ��� -> ���� ū ������ ���ֱ� 
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
[��ó] [�˰��� ����] 5����. �׸��� ���ν����� ��������|�ۼ��� ū��
