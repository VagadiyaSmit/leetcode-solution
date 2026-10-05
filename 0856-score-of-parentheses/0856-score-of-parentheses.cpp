class Solution {
public:
    int scoreOfParentheses(string s) {   // T.C = O(n) S.C = O(1)
        int score = 0;
        int depth = 0;
        for(int i = 0;i < s.size();i++){
            if(s[i] == '('){
                depth++;
            }
            else{
                depth--;
                if(s[i - 1] == '('){
                    score += 1 << depth;
                }
            }

        }
        return score;
    }
};