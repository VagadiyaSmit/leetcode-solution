class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int Max = INT_MIN;
        int sMax = INT_MIN;
        if(nums.size() == 1){
            return -1;

        }
        for(int x:nums){
            if(x > Max){
                sMax = Max;
                Max = x;
            }
            else if( x > sMax){
                sMax = x;
            }
        }
        return (Max -1)*(sMax -1);
    }
};