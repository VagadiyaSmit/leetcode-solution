class Solution {
public:
    int minInsertions(string s) {       //T.C = O(n) S.C = O(1)
        int need = 0;
        int ans = 0;
        for(char ch : s){
            if(ch == '('){
                if(need % 2 == 1){
                    ans++;
                    need--;
                }
                need += 2;
            }
            else{
                need--;
                if(need == -1){
                    ans++;
                    need = 1;
                }
            }   
        }
        return ans + need;
    }
};