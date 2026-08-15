class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size()-1;

        while(i >= 0){
            if(digits[i] < 9){
                digits[i]++;
                return digits;   //no more carry ,done
                
            }else{
                digits[i] = 0;  //9+1 = 10 ,carry continues
                i--;
            }

        }
        //if we fall though,every digit wes 9 
        digits.insert(digits.begin(),1);
        return digits;
        
    }
};