class Solution {
public:
    int sumOfSquares(vector<int>& nums) {       //T.C = O(n) S.C = O(1)

        //we have to return the sum of all square their index(expact 0) and size modulo is zero.

        int n = nums.size();
        int sum = 0;
        for(int i = 1;i <= n;++i){
            if(n % i == 0){
                sum += (nums[i-1]*nums[i-1]);
            }

        }
        return sum;
    }
};