class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        if ((int)target.size() != n) return "";

        vector<int> freq(26, 0);
        for (char ch : s) freq[ch - 'a']++;

        int oddCount = 0, oddChar = -1;
        for (int c = 0; c < 26; c++)
            if (freq[c] % 2) { oddCount++; oddChar = c; }

        bool odd = (n % 2 == 1);
        if ((odd && oddCount != 1) || (!odd && oddCount != 0)) return ""; // no palindrome permutation exists

        int h = n / 2;
        vector<int> hc(26, 0);
        for (int c = 0; c < 26; c++) hc[c] = freq[c] / 2;

        int totalSlots = h + (odd ? 1 : 0);

        // Try to match target's first half (+ mid) exactly.
        vector<int> avail = hc;
        vector<int> matched(totalSlots, -1);
        int m = 0;
        while (m < h) {
            int c = target[m] - 'a';
            if (avail[c] > 0) { avail[c]--; matched[m] = c; m++; }
            else break;
        }
        if (m == h && odd) {
            int c = target[h] - 'a';
            if (c == oddChar) { matched[h] = c; m = h + 1; }
        }

        auto build = [&](vector<int>& A, int mid) {
            string P(n, ' ');
            for (int i = 0; i < h; i++) P[i] = char('a' + A[i]);
            if (odd) P[h] = char('a' + mid);
            for (int i = 0; i < h; i++) P[n - 1 - i] = char('a' + A[i]);
            return P;
        };

        if (m == totalSlots) {
            vector<int> A(matched.begin(), matched.begin() + h);
            int mid = odd ? matched[h] : -1;
            string P = build(A, mid);
            if (P > target) return P; // provably the smallest possible answer
        }

        int M = (m == totalSlots) ? totalSlots - 1 : m;

        // Special-case: diverge at the mid slot.
        if (odd && M == h) {
            if (oddChar > target[h] - 'a') {
                vector<int> A(matched.begin(), matched.begin() + h);
                return build(A, oddChar);
            }
            M = h - 1;
        }

        // Set avail = hc - sum(matched[0..M-1]), then walk p down, updating incrementally.
        vector<int> availP = hc;
        for (int i = 0; i < M; i++) availP[matched[i]]--;

        for (int p = M; p >= 0; p--) {
            int tgt = target[p] - 'a';
            int choice = -1;
            for (int c = tgt + 1; c < 26; c++)
                if (availP[c] > 0) { choice = c; break; }

            if (choice != -1) {
                vector<int> A(h);
                for (int i = 0; i < p; i++) A[i] = matched[i];
                A[p] = choice;
                availP[choice]--;

                int idx = p + 1;
                for (int c = 0; c < 26 && idx < h; c++)
                    while (availP[c] > 0 && idx < h) { A[idx++] = c; availP[c]--; }

                int mid = odd ? oddChar : -1;
                return build(A, mid);
            }
            if (p > 0) availP[matched[p - 1]]++; // restore for next iteration
        }

        return "";
    }
};