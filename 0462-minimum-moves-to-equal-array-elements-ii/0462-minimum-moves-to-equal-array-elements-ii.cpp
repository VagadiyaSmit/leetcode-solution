class Solution {
public:
    int minMoves2(vector<int>& nums) {      //T.C = O(n) S.C = O(1)
        int n = nums.size();
        int mid = n/2;

        nth_element(nums.begin(),nums.begin() + mid,nums.end());   //set quickselect of mid index
        int medium  = nums[mid];
        long long moves = 0;
        for(int x: nums){
            moves += llabs((long long)x - medium);      //casts before subtracting
        }
        return (int)moves;
    }
};