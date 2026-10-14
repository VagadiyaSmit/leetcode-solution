class Solution {
public:
    string maxSumOfSquares(int num, int sum) {          //T.C =O(num) S.C = O(1)
        if(sum > 9 *num)
            return "";

        string res;
        res.reserve(num);

        int nines = sum / 9;   
        int rem   = sum % 9;   

        
        res.append(nines, '9');

        
        if ((int)res.size() < num) 
            res.push_back('0' + rem);

        res.append(num - res.size(), '0');

        return res;

    }
};