class Solution {
public:
    int strStr(string s1, string s2) {
        if(s2.length() > s1.length()){
            return -1;
        }
        for(int i = 0;i<= s1.length() - s2.length();++i){
            if(s1.substr(i,s2.length()) == s2){
                return i;
            }
        }
        return -1;
    }
};