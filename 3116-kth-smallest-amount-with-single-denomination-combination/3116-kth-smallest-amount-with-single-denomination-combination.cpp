class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        long long low = *min_element(coins.begin(), coins.end()) * 1LL;
        long long high = *max_element(coins.begin(), coins.end()) * 1LL * k;

        vector<vector<long long>> set(n + 1);

        function<void(long long,int,int)> setCreation = [&](long long val, int setNumber, int idx){
            val = lcm(val, (long long)coins[idx]);
            if(val > high) return;

            set[setNumber].push_back(val);
            for(int i = idx + 1; i < n; ++i)
                setCreation(val, setNumber + 1, i);
        };

        for(int i = 0; i < n; i++)
            setCreation(1, 1, i);

        auto getRank = [&](long long value) -> long long {
            long long rank = 0;
            for(int i = 1; i <= n; ++i){
                for(int j = 0; j < (int)set[i].size(); ++j){
                    if(i % 2 != 0) rank += value / set[i][j];
                    else rank -= value / set[i][j];
                }
            }
            return rank;
        };

        while(low < high){
            long long mid = low + (high - low) / 2;
            long long rank = getRank(mid);
            if(rank >= k) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};