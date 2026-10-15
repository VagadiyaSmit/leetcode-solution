class Solution {
public:
   
    int sumCounts(vector<int>& nums) {      //T.C = O(n^2) S.C = O(1)
        int n = nums.size();
        int ans = 0;                      

        for (int i = 0; i < n; i++) {    
            bool seen[101] = {false};
            int distinct = 0;            

            for (int j = i; j < n; j++) { 
                if (!seen[nums[j]]) {     
                    seen[nums[j]] = true;
                    distinct++;          
                }
                ans += distinct * distinct; 
            }
        }
        return ans;
    }
};