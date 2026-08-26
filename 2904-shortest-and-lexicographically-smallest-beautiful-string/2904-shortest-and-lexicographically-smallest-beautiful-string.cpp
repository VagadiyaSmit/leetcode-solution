class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {   //T.C = O(n) S.C = O(n)
        int n = s.size();
        int totalOnes = count(s.begin(),s.end(),'1');
        if(totalOnes < k) return "";

        string best = "";
        int left = 0,ones = 0;

        for(int right = 0; right < n;right++){
            if(s[right] == '1') ones++;

            //shrink while too many ones or exactly k ones with leading
            while(ones > k || (ones == k && s[left] == '0')){
                if(s[left] =='1') ones--;
                left++;
            }
            if(ones == k){
                string candidates = s.substr(left,right - left + 1);
                if(best.empty() || candidates.size() < best.size() || (candidates.size() == best.size() && candidates < best)){
                    best = candidates;
                }
            }
        }
        return best;
    }
};