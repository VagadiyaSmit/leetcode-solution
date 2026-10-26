class Solution {
public:
    int sortPermutation(vector<int>& nums) {            //T.C = O(n) S.C = O(1)
        int n = nums.size();

      
        int ans = -1;
        bool misplaced = false;

        
        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                ans &= nums[i];
                misplaced = true;
            }
        }

        
        if (!misplaced) return 0;   //array is sorted

        
        return ans;
    }
};