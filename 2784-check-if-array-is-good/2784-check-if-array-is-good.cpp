class Solution {
public:
    bool isGood(vector<int>& nums) {  //T.C = O(log n)  S.C = O(1)
        int n = nums.size();
        if(nums.size() == 1)
            return false;

        sort(nums.begin(),nums.end());   //T.C = O(nlog n)
      
        for(int j = 0;j < n-2;j++){     // T.C = O(n)
            if(nums[j] != j+1){
                return false;
            }
        }
        return nums[n-2] == n-1 && nums[n-1] == n-1;
        
    }
};