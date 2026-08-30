class Solution {
public:
    int minimumDeletions(vector<int>& nums) {   //T.C = O(n) S.C = O(1) 
        int n = nums.size();
        int minIdx = 0;
        int maxIdx = 0;
        for(int i = 0;i < n;i++){
            if(nums[i] > nums[maxIdx]){
                maxIdx = i;
            }
            if(nums[i] < nums[minIdx]){
                minIdx = i;
            }
        }
        int i = min(minIdx,maxIdx);
        int j = max(minIdx,maxIdx);

        int option1 = j + 1;            //both from front
        int option2 = n - i;            //both from back
        int option3 = (i + 1)+(n - j);

        return min({option1,option2,option3});

    }
};