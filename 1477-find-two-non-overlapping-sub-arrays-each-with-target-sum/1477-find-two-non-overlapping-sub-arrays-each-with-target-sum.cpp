
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {     //T.C = O(n) S.C = O(n)
        int n = arr.size();

        vector<int> best(n, INT_MAX);     // best[i] = shortest valid subarray length using arr[0..i]

        int left = 0;
        int sum = 0;
        int answer = INT_MAX;

        for (int right = 0; right < n; ++right) {
            sum += arr[right];                // expand window

            while (sum > target) {            // shrink window from left while sum too big
                sum -= arr[left];
                ++left;
            }

            if (sum == target) {
                int currentLength = right - left + 1;
                
                // Try pairing this window with the best window found strictly before `left`
                if (left > 0 && best[left - 1] != INT_MAX) {
                    answer = min(answer, currentLength + best[left - 1]);     
                }

                best[right] = currentLength;   // record this window's length at index `right`
            }

            if (right > 0) {
                best[right] = min(best[right], best[right - 1]);    // roll the minimum forward
            }
        }

        return answer == INT_MAX ? -1 : answer;
    }
};