class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {        //T.C = O(n) S.C = O(n)
        unordered_map<int,int> freq;                       //approach hash map
        int count = 0;

        for(int x : nums){
            if(freq.count(x - k)) 
                count += freq[x - k];
            if(freq.count(x + k))
                count += freq[x + k];

            freq[x]++;
        }

        return count;
    }
};