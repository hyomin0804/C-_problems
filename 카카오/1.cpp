#include <bits/stdc++.h>


using namespace std;
map<char, int> mp;

vector<string> survey={"AN", "CF", "MJ", "RT", "NA"};
vector<int> choices={5, 3, 2, 7, 5};
int score[8] = {0,3,2,1,0,1,2,3};
/* 처음 시도  
int pplus(int idx){
    if(idx==1 || idx==7) return 3;
    if(idx==2 || idx==6) return 2;
    if(idx==3 || idx==5) return 1;
    if(idx==4) return 0;
    
}
*/
string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
 	
    for(int i=0; i< survey.size(); i++){
    	
        if(choices[i]<=3){ //비동의
        	int a=pplus(choices[i]);       
            mp[survey[i][0]] += score[choices[i]];
            
        }else if(choices[i]==4){
            continue;
        }else{ // i>5
        
            mp[survey[i][1]]+= score[choices[i]];
        }
    }
    
    
    answer += mp['R'] >= mp['T'] ? "R" : "T";
    answer += mp['C'] >= mp['F'] ? "C" : "F";
    answer += mp['J'] >= mp['M'] ? "J" : "M";
    answer += mp['A'] >= mp['N'] ? "A" : "N";
    
    return answer;
}

int main(){
	cout << solution(survey, choices);
	return 0;
}
