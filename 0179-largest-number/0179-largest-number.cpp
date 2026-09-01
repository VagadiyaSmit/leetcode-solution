class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> str;
        str.reserve(nums.size());
        for(int n : nums){
            str.push_back(to_string(n));
        }

        sort(str.begin(),str.end(),[](const string& a,const string& b){
            return a + b >  b + a;
        });
        if(!str.empty() && str[0] == "0"){   // Edge case: all zeros -> collapse "000..." to "0"
            return "0";
        }
        string result;
        for(const string& s : str){
            result += s;
        }
        return result;
    }
};