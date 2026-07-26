class Solution {
public:
    bool isPalindrome(int n) {  // T.C = O(log n) S.C = O(1)
        long long rev = 0;
        if( n < 0)
            return false;
        int ori = n;
        while(n != 0){
            int data = n%10;
            rev = rev*10 + data;
            n /= 10;
        }
        return ori == rev;
    }
};