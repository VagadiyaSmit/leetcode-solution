class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int freq[51] = {0};

        for(int& i:nums)
            ++freq[i];

        int ans = -1;
        for(int i = 0; i < n;++i){
            if(k == n || (freq[nums[i]] == 1 && (k == 1 || !i || i == n - 1)))
                ans = max(ans,nums[i]);
  
        }
        return ans; 
    }
};