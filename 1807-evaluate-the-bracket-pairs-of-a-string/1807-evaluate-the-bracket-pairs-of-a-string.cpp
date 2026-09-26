class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {   //T.C = O(m+n)  S.C = O(m) m = knowledge heep
        unordered_map<string, string> dict;
        dict.reserve(knowledge.size() * 2);
        for (auto& kv : knowledge) {
            dict[kv[0]] = kv[1];
        }

        string result;
        result.reserve(s.size()); // upper bound-ish, avoids reallocation

        string key;
        bool inBracket = false;

        for (char c : s) {
            if (c == '(') {
                inBracket = true;
                key.clear();
            } else if (c == ')') {
                inBracket = false;
                auto it = dict.find(key);
                if (it != dict.end()) {
                    result += it->second;
                } else {
                    result += '?';
                }
            } else if (inBracket) {
                key += c;
            } else {
                result += c;
            }
        }

        return result;
    }
};