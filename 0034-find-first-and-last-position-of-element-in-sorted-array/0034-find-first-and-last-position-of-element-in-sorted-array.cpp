class Solution {
public:
    int firstPosition(vector<int>& nums, int target) {
        int st = 0,end = nums.size()-1;
        int ans = -1;

        while(st <= end){
            
            int mid = st + (end - st)/2;
            
            if(nums[mid] == target){
                ans = mid;
                end = mid-1;     // search left part
            }else if( nums[mid] < target){
                st = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return ans;
    }
        int endPosition(vector<int>& nums, int target) {
        int st = 0,end = nums.size()-1;
        int ans = -1;

        while(st <= end){
            int index1 = 0;
            int mid = st + (end - st)/2;
            
            if(nums[mid] == target){
                ans = mid;
                st = mid+1;           //search right part
            }else if( nums[mid] < target){
                st = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target){
        return {firstPosition(nums,target),endPosition(nums,target)};
    } 
};