#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    vector<int> ret;
    int a= friends.size();
    int adj[a][a];
    int rate[a][3];
    fill(&adj[0][0], &adj[0][0]+a*a,0);
    fill(&rate[0][0], &rate[0][0]+a*3,0);

    //memset(ret, 0,sizeof(ret)*a);

    for(int i=0; i<gifts.size(); i++){
        string k= gifts[i];
   
        string f= k.substr(0, k.find(" "));
        string s= k.substr(k.find(" ")+1, k.length());
		 
        int a= find(friends.begin(), friends.end(), f)-friends.begin();
        int b= find(friends.begin(), friends.end(), s)-friends.begin();
        adj[a][b]++;
    }
    
    for(int i=0; i<friends.size();i++){
        int sum=0;
        int sum2=0;
        for(int j=0; j<friends.size();j++){
            sum+=adj[i][j];
            sum2+=adj[j][i];
        }
        
        rate[i][0]=sum;
        rate[i][1]=sum2;
        rate[i][2]=sum-sum2;
    }

    for(int i=0; i<friends.size();i++){
        int cnt=0;
        for(int j=0; j<friends.size();j++){
            if(adj[i][j]>adj[j][i]){
                cnt++;
            }else if(adj[i][j]==adj[j][i]){
                if(rate[i][2]>rate[j][2]) cnt++;
            }
        }
        ret.push_back(cnt);
    }
    answer=*max_element(ret.begin(),ret.end());
    return answer;
}
