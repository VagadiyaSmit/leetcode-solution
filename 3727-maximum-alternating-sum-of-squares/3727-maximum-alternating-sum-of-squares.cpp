class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {        //T.C = O(n * log n) S.C = O(n)
        //simply make a square arr and sort it and substract first half arr score from the last half part
        int n = nums.size();
        vector<long long> sq(n);

        for(int i = 0; i < n;i++)
            sq[i] = 1LL * nums[i] * nums[i];

        sort(sq.begin(),sq.end());

        int negCount = n/2;
        long long score = 0;

        for(int i = 0;i < negCount;i++)
            score -= sq[i];
        
        for(int i = negCount;i < n;i++)
            score += sq[i];

        return score;

    }
};