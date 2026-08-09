/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        // Step 1: Find the peak index
        int peak = findPeak(mountainArr, n);

        // Step 2: Search the increasing part [0, peak]
        int idx = binarySearch(mountainArr, target, 0, peak, true);
        if (idx != -1) return idx;

        // Step 3: Search the decreasing part [peak, n-1]
        idx = binarySearch(mountainArr, target, peak, n - 1, false);
        return idx;
    }

private:
    int findPeak(MountainArray &arr, int n) {
        int st = 0, end = n - 1;
        while (st < end) {
            int mid = st + (end - st) / 2;
            if (arr.get(mid) < arr.get(mid + 1)) {
                // still climbing, peak is to the right
                st = mid + 1;
            } else {
                // descending, peak is at mid or to the left
                end = mid;
            }
        }
        return st; // st == end == peak index
    }

    int binarySearch(MountainArray &arr, int target, int st, int end, bool ascending) {
        while (st <= end) {
            int mid = st + (end - st) / 2;
            int val = arr.get(mid);
            if (val == target) return mid;
            if (ascending) {
                if (val < target) st = mid + 1;
                else end = mid - 1;
            } else {
                if (val > target) st = mid + 1;
                else end = mid - 1;
            }
        }
        return -1;
    }
};