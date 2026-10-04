class Solution {
public:
    int searchInsert(vector<int>& A, int target) {     // T.C = O(log n)  S.C = O(1)
        int st = 0,end = A.size()-1;
        while(st <= end){
            int mid = st + (end - st)/2;
            if(A[mid] == target){
                return mid;
            }
            else if(A[mid] < target){
                st = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return st;
    }
    
};