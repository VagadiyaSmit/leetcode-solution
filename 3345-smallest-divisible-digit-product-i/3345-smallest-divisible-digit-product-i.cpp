class Solution {
public:
    int smallestNumber(int n, int t) {  //T.C = O(d * k) S.C = O(1)
        while(true){
            int x = n;
            int product = 1;
            while(x > 0){
                product *= (x % 10);
                x /= 10;
            }   
            if(product % t == 0)
                return n;
                
            n++;

        }
    }
};