class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxiProfit = INT_MIN;
        int prevMin = -1;
        int n = prices.size();
        for(int i =0 ; i < n ; i++ )
        {
            if(prevMin != -1 and prices[i] > prevMin)
            {
                maxiProfit = max(maxiProfit , prices[i] -prevMin );
            }
            else{
                prevMin = prices[i];
            }
        }

        return maxiProfit == INT_MIN? 0 : maxiProfit;
    }
};