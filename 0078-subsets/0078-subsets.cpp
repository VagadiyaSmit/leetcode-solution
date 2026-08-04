class Solution {
public:
    void get_all_subsets(vector<int>& nums,vector<int> &ans,int i, vector<vector<int>> &all_subsets){
         if(i == nums.size()){
            //store subset
            all_subsets.push_back(ans);
            return;
        } 
        ans.push_back(nums[i]);
        get_all_subsets(nums,ans,i+1,all_subsets);
        ans.pop_back();
        get_all_subsets(nums,ans,i+1,all_subsets);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> all_subsets;
     
        vector<int> ans; 
        get_all_subsets(nums,ans,0,all_subsets);
        return all_subsets;
    }
};