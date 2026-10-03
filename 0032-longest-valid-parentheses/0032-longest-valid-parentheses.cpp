class Solution {
public:
    int longestValidParentheses(string s) {       //T.C = O(n) S.C = O(n)
        int maxLen = 0;
        stack<int> st;
        st.push(-1);


        for(int i = 0; i < (int)s.size();i++){
            if(s[i] == '(')
                st.push(i);
            else
                st.pop();
            
            if(st.empty())
                st.push(i);
            else
                maxLen = max(maxLen,i-st.top());
        }
        return maxLen;
    }
   
};