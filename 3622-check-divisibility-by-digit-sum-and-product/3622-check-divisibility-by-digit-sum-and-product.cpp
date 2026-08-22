class Solution {
public:
    
    bool checkDivisibility(int n) {  //T.C = O(log10 n) S.C = O(1)
        int org = n;
        int sum = 0;
        int mul = 1;
        while( n != 0){
            int dig = n % 10;
            sum += dig;
            mul *= dig;
            n /= 10;
        }
        int comb = sum + mul;
       
        return org % comb == 0;
    }
};