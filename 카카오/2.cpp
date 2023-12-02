#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
ll sum1, sum2, cnt;


int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -2;
    sum1 = accumulate(queue1.begin(), queue1.end(), 0);
    sum2 = accumulate(queue2.begin(), queue2.end(), 0);
    
    ll max_= queue1.size()*4;
    if(((sum1 + sum2)%2) == 1)
        return -1;
    
    while(true){
        if(sum1==sum2) break;
        
        if(cnt>max_){
            cnt=-1;
            break;
        }
        
        if(sum1>sum2){
            sum2+=queue1.front();
            sum1-=queue1.front();
            queue2.push_back(queue1.front());
            queue1.erase(queue1.begin());
            cnt++;
            
        }else{
            sum1+=queue2.front();
            sum2-=queue2.front();
            queue1.push_back(queue2.front());
            queue2.erase(queue2.begin());
            cnt++;
            
        }
    }
    answer=cnt;
    return answer;
}
