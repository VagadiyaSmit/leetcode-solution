class Solution {
    string toBinary(char c){ //T.C = O(L), where L = length of input string s
        int n = c;            //S.C = O(8L) = O(L) auxiliary space
        string s;
        while(n){
            s += n % 2 + '0';
            n /= 2;

        }
        while(s.length() != 8){
            s += '0';
        }
        reverse(s.begin(),s.end());
        return s;
    }
public:
    bool isPalindromic(string s) {
        string ans;
        for(char& c : s) ans += toBinary(c);

        for(int i = 0, j = ans.length()-1;i < j;++i,--j){
            if(ans[i] != ans[j]) return false;
        }
        return true;
    }
};