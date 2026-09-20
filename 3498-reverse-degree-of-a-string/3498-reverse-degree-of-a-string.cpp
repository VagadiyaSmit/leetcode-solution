class Solution {
public:
    int reverseDegree(string s) {    // T.C = O(n) S.C = O(1)
        long long total = 0;
        for (size_t i = 0; i < s.size(); i++) {
            int rev = 'z' - s[i] + 1;          // reversed alphabet value: 
            total += (long long)(i + 1) * rev; // (i + 1) is the 1-indexed position; cast avoids overflow
        }
        return total;
    }
};