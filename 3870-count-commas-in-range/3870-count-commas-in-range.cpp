class Solution {
public:
    int countCommas(int n) {
        long long total = 0;
        long long lower = 1;      // 10^(L-1)
        long long upper = 9;      // 10^L - 1
        int L = 1;

        while (lower <= n) {
            long long hi = min((long long)n, upper);
            long long count = hi - lower + 1;   // numbers with exactly L digits, <= n
            long long commasPerNumber = (L - 1) / 3;
            total += count * commasPerNumber;

            lower = upper + 1;
            upper = upper * 10 + 9;
            L++;
        }

        return (int)total;
    }
};