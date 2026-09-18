class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;       //T.C = O(n) S.C = O(n)
        stack<int> s;

        for(int i = (int)nums2.size()-1;i >= 0;i--){
            while(!s.empty() && s.top() <= nums2[i])
                s.pop();
            
            if(s.empty())
                m[nums2[i]] = -1;
            else
                m[nums2[i]] = s.top();

            s.push(nums2[i]);
        }
    
        vector<int> ans;
        for(int j = 0; j< (int)nums1.size();j++)
            ans.push_back(m[nums1[j]]);
        
        return ans;
    }
};