string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char, int> surv_elm;
    int score[8] = {0,3,2,1,0,1,2,3};
    for(int i =0; i<survey.size(); i++){ 
        int isFront = choices[i]/4;
        char p_type = survey[i][isFront];
        surv_elm[p_type] += score[choices[i]];
    }
        

    answer += surv_elm['R'] >= surv_elm['T'] ? "R" : "T";
    answer += surv_elm['C'] >= surv_elm['F'] ? "C" : "F";
    answer += surv_elm['J'] >= surv_elm['M'] ? "J" : "M";
    answer += surv_elm['A'] >= surv_elm['N'] ? "A" : "N";

    return answer;
}
