class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {      // T.C = O(n) S.C = O(1)
        int i = m-1,j = n-1;        // i is point last ele of A,j is point last ele of B
        int idx = m + n - 1;        //idx is point A 's last index 

        while( i >= 0 && j >= 0){
            
            if(A[i] > B[j]){
                swap(A[i],A[idx]);
                i--,idx--;
            }
            else{
                swap(B[j],A[idx]);
                j--,idx--;
            }
        
        }
        while(j >= 0){
            swap(B[j],A[idx]);
            j--,idx--;
        }
    }
};