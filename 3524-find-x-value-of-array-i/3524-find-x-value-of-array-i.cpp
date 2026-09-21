class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k,0);     //count of subarray
        vector<long long> count(k,0);   //reminder

        for(int a : nums){
            int m = a % k;       //calculate remainder

            vector<long long>curr(k,0);

            for(int r = 0;r < k;r++)        // extend every old subarray by a: remainder r becomes (r * m) % k
                curr[(r*m) % k] += count[r];

            curr[m] += 1;

            for(int r = 0;r < k;r++)
                result[r] += curr[r];

            count = curr;
        }
        return result;

    }
};