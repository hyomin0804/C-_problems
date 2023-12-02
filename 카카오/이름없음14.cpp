#include <bits/stdc++.h>

using namespace std;

vector<pair<vector<int>,int>> ret;

int go(vector<int> a, vector<int> b ,vector<vector<int>> dice){ //½Â¸®È½¼ö ¸®ÅÏ 
    
    

    return;
}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    
    int n=dice.size()/2;

    for(int i=0; i < (1<<dice.size()); i++){
        if(__builtin_popcount(i)==n){
            vector<int> v;
            vector<int> vv;
            for(int j=0; j<dice.size();j++){
                if(i & (1<<j)){
                    v.push_back(j);
                }
            }

            for(int a=0; a<dice.size();a++){
                if(find(v.begin(),v.end(), a) == v.end()) vv.push_back(a);
            }

            ret.push_back({go(v, vv),v}) 
        }
    }
    sort(ret.begin(), ret.end(), greater<pair<int,vector<int>>)
    answer=ret[0][1];
    return answer;
}
