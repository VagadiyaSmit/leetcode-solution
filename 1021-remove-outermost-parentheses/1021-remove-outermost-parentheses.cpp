class Solution {
public:
    string removeOuterParentheses(string s) {           //T.C = O(n) S.C = O(1)
        string result;
        result.reserve(s.size());
        int depth = 0;

        for(char ch : s){
            if(ch == '('){
                if(depth > 0) result += ch;
                depth++;
            }
            else{
                depth--;
                if(depth > 0){
                    result += ch;
                }
            }
        }
        return result;
    }
};