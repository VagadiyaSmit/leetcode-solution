class Solution {
public:
    int trap(vector<int>& height) {        //T.C = O(n) S.C = O(1)
        int l = 0,r = height.size()-1;
        int Lmax = 0,Rmax = 0;
        int ans = 0;
        while(l < r){
            Lmax = max(Lmax,height[l]);
            Rmax = max(Rmax,height[r]);

            if(Lmax < Rmax){
                ans += (Lmax - height[l]);
                l++;
            }else{
                ans += (Rmax - height[r]);
                r--;
            }
        }
        return ans;
    }
};