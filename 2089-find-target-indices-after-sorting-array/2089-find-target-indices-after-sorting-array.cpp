class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {  //T.C = O(n) S.C = O(1)
        int n = nums.size();
        int less = 0,equal = 0;
        for(int x: nums){
            if(x < target)
                less++;
            else if(x == target)
                equal++;
        }
        vector<int> Result;
        for(int i = less;i < less+equal;i++)
            Result.push_back(i);
        
        return Result;
    }
};