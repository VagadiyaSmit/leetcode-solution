class Solution {
public:
    int minAddToMakeValid(string s) {       //T.C = O(n)  S.C = O(1)
        int balance = 0,needOpen = 0;
        for(char ch : s){
            if(ch == '('){
                balance++;
            }
            else{   
                if(balance > 0)
                    balance--;
                else
                    needOpen++;                

            }
        }
        return needOpen + balance;
    }
};