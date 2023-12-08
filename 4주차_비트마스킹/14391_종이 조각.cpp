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
    // ��ü ��� 0,1�� ���� �� �ִ� ����� �� 
	// 1�����̱� ������ �ึ��  int k = i * m + j;�� �ؼ� �ٲ������  
    for (int s = 0; s < (1 << (n * m)); s++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int cur = 0;
            for (int j = 0; j < m; j++) {
                int k = i * m + j;
                if ((s & (1<<k)) == 0) {
                    cur = cur * 10 + a[i][j];
                } else {
                    sum += cur; // 1 ������ ���ݱ��� ���� ���� ���ϱ�  
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
                    sum += cur; // 0 ������ ���ݱ��� ���� ���� ���ϱ�  
                    cur = 0; // ���� ���� ����� ���� �ʱ�ȭ  
                }
            }
            sum += cur; // 0������ ���ݱ��� ���� ���� ���ϱ�  
        }
        ret = max(ret,sum);
    }
    cout << ret << '\n';
    return 0;
}
