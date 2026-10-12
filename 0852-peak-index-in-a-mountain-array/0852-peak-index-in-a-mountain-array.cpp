class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int target;
        int i = 0,j =arr.size()-1;
        while(i<=j){
            int mid = i +(j-i)/2;
            if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]){
                return mid;
            }
            else if(arr[mid]>arr[mid+1]){
                j = mid-1;
            }
            else{
                i = mid+1;
            }
        }
        return -1;
    
    }
};