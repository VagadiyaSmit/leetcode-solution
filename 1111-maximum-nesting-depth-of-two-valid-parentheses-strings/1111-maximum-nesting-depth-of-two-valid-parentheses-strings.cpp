class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {  //T.C = O(n) S.C = O(1)
        int n = seq.length();
        vector<int> result(n);
        int depth = 0;
        for(int i = 0;i < n;i++){
            

            if(seq[i] == '('){
                depth++;
                result[i] = depth % 2;
            }
            else{
                
                result[i] = depth % 2;
                depth--;
            }
        }
        return result;
    }
};