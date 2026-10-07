class Solution {
public:
    int maxProfit(vector<int>& prices) {            // T.C = O(n) S.C = O(1) 
        int maxProfit = 0,currBuy = prices[0];

        for(int i = 0;i < prices.size();i++){
            if(prices[i] < currBuy){
                currBuy = prices[i];
            }
            else if(maxProfit < (prices[i] - currBuy)){    
                maxProfit = (prices[i] - currBuy);    
            }
        }
        return maxProfit;
    }
};