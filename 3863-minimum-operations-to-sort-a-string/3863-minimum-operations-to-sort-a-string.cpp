class Solution {
public:
    int minOperations(string s) {               //T.C = O(n) S.C = O(1)
        
        int n = s.size();
        
        //1.freq count
        int count[26] = {0};
        for(char c:s) 
            count[c -'a']++;
        
        //2.base cases
        if(is_sorted(s.begin(),s.end()))   
            return 0;
        
        if(n == 2) return -1;
        
        //3.find min & max char
        char minChar = 'z', maxChar = 'a';
        for (char c : s) {
            minChar = min(minChar, c); 
            maxChar = max(maxChar, c); 
        }

        //4.chaeck other main cases
        if(s[0] == minChar || s[n-1] == maxChar)
            return 1;

        bool planA = (s[n - 1] != minChar) || (count[minChar - 'a'] > 1);
        bool planB = (s[0] != maxChar)     || (count[maxChar - 'a'] > 1);
        
        if (planA || planB) 
            return 2;

        return 3;              //worst case(minChar is in last pos & maxChar is in first pos).
    }
};