class Solution {
public:
    
    bool isValid(const string& s) {
        int bal = 0;
        for (char c : s) {
            if (c == '(') bal++;
            else if (c == ')') {
                if (--bal < 0) return false; // ')' with no matching '('
            }
        }
        return bal == 0;
    }

   
    void dfs(string s, int start, int l, int r, vector<string>& result) {
       
        if (l == 0 && r == 0) {
            if (isValid(s)) result.push_back(s);
            return;
        }
        for (int i = start; i < (int)s.size(); i++) {
            
            if (i != start && s[i] == s[i - 1]) continue;

           
            if (s[i] == '(' && l > 0)
                dfs(s.substr(0, i) + s.substr(i + 1), i, l - 1, r, result);
            else if (s[i] == ')' && r > 0)
                dfs(s.substr(0, i) + s.substr(i + 1), i, l, r - 1, result);
            
        }
    }

    vector<string> removeInvalidParentheses(string s) {
       
        int l = 0, r = 0;
        for (char c : s) {
            if (c == '(') l++;                 
            else if (c == ')') {
                if (l > 0) l--;                
                else r++;                     
            }
        }
        
        vector<string> result;
        dfs(s, 0, l, r, result);
        return result;
    }
};