class Solution {
public:
    vector<string> generateParenthesis(int n) {        // T.C  ≈ O(4^n / √n) S.C = O(n)
        vector<string> result;
        string curr;
        curr.reserve(2*n);         //avoid reallocation
        backtrack(result,curr,0,0,n);
        return result; 
    }

private:
    void backtrack(vector<string>& result,string& curr,int open,int close,int n){
        if (curr.size() == 2 * n) {
            result.push_back(curr);
            return;
        }
        // Choice 1: add '(' if we still have opening brackets left to use.
        if (open < n) {
            curr.push_back('(');                       // choose
            backtrack(result, curr, open + 1, close, n); // explore
            curr.pop_back();                           // undo (backtrack)
        }
        // Choice 2: add ')' only if it closes an already-open '('.
        // close < open ensures no prefix ever has more ')' than '('.
        if (close < open) {
            curr.push_back(')');                       // choose
            backtrack(result, curr, open, close + 1, n); // explore
            curr.pop_back();                           // undo (backtrack)
        }
    }
};