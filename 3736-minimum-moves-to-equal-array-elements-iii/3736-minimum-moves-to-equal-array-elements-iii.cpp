class Solution {
public:
    int minMoves(vector<int>& nums) {           //T.C = O(n) S.C = O(1)
        int target = *max_element(nums.begin(),nums.end());
        int moves = 0;
        for(int x: nums){
            moves += target - x;
        }
    
        return moves;
    }
};