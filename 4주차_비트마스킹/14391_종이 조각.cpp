#include <iostream>
#include <cstdio>
using namespace std;
int a[4][4], n, m, ret; 
string s;

int main() { 
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for(int j=0; j<m; j++){
        	a[i][j]=s[j]-'0';
		}
	}
    // 전체 모든 0,1로 만들 수 있는 경우의 수 
	// 1차원이기 때문에 행마다  int k = i * m + j;로 해서 바꿔줘야함  
    for (int s = 0; s < (1 << (n * m)); s++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int cur = 0;
            for (int j = 0; j < m; j++) {
                int k = i * m + j;
                if ((s & (1<<k)) == 0) {
                    cur = cur * 10 + a[i][j];
                } else {
                    sum += cur; // 1 나오면 지금까지 만든 숫자 더하기  
                    cur = 0;
                }
            }
            sum += cur;
        }
        
        for (int j = 0; j < m; j++) {
            int cur = 0;
            for (int i = 0; i < n; i++) {
                int k = i * m + j;
                if ((s & (1<<k)) != 0) {
                    cur = cur * 10 + a[i][j];
                } else {
                    sum += cur; // 0 나오면 지금까지 만든 숫자 더하기  
                    cur = 0; // 다음 숫자 만들기 위해 초기화  
                }
            }
            sum += cur; // 0나오면 지금까지 만든 숫자 더하기  
        }
        ret = max(ret,sum);
    }
    cout << ret << '\n';
    return 0;
}
