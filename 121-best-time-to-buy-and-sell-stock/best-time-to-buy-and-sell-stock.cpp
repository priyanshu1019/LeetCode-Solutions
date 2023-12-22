class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxProfit    = 0;
        int n            = prices.size();
        int lowerCircuit = prices[0];
        
        for(int i = 1 ; i < n ; i++ ){
            
            int profit = prices[i] - lowerCircuit;
            maxProfit  = max(maxProfit , profit);
            lowerCircuit = min(lowerCircuit , prices[i]);
            
        }
        
        return maxProfit;
        
        
    }
};