class Solution {
public:
    int bitwiseComplement(int n) {  // T.C = O(log n) S.C = O(1)
        if( n == 0 ){
            return 1;
        }
        int mask = 1;
        while(mask < n){
            mask  = (mask << 1) | 1;
        }
        return mask ^ n;
    }
};