class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {      //T.c = O(n) S.C = O(n)
        int n = heights.size();
        vector<int> left(n,0);        //left smaller nearest
        vector<int> right(n,0);       //right smaller nearest
        stack<int> s1;
        //right smaller
        for(int i = n-1;i >= 0;i--){
            while(s1.size() > 0 && heights[s1.top()] >= heights[i])
                s1.pop();
            
            right[i] = s1.empty() ? n : s1.top();         // not -1  because of  (r - l -1 ) r is not negative
            s1.push(i);
        }
        stack<int> s2;
        // left smaller
        for(int i = 0; i < n;i++){
            while(s2.size() > 0 && heights[s2.top()] >= heights[i])
                s2.pop();

            left[i] = s2.empty() ? -1:s2.top();
            s2.push(i);
        }

        
        int ans = 0;  // ans is not negative possible

        for(int i = 0;i < n;i++){
            int weight = (right[i] - left[i] - 1);
            int currArea = heights[i] * weight;
            ans = max(ans,currArea);
        }
        return ans;
    }
};