class Solution {
public:
    string reverseParentheses(string s) {       //T.C = O(n)  S.C = O(n)
        int n = s.size();
        vector<int> pair_(n);
        stack<int> st;

        //part 1 : find matching pairs
        for(int i = 0;i < n;i++){
            if( s[i] == '(' )
                st.push(i);
            else if( s[i] == ')' ){
                int j = st.top();
                st.pop();
                pair_[i] = j;
                pair_[j] = i;
            }
        } 
        //part 2 : traverse with direction flipping
        string result;
        int dir = 1;
        for(int curr = 0; curr >= 0 && curr < n;){
            if(s[curr] == '(' || s[curr] == ')'){
                curr = pair_[curr];
                dir = -dir;
            }else{
                result += s[curr];
            }
            curr += dir;
        }
        return result;
    }
};