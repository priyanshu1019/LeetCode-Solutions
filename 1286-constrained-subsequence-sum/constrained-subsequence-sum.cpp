class Solution {
public:
    typedef pair< int , int > p;
    int constrainedSubsetSum(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        vector<int> dp( n , 0 );
        dp       = nums;
        int maxR = dp[0];
        
        priority_queue<p> pq;
        pq.push({dp[0] , 0 });
        
        for(int i = 1 ; i< n ; i++ ){
            
            while( !pq.empty() and i-pq.top().second > k ){
                
                pq.pop();
                
            }
            dp[i] = max( dp[i] , nums[i] + pq.top().first );
            pq.push({ dp[i] , i });
            maxR  = max( maxR , dp[i] );
            
        }
        
        return maxR;
        
    }
};