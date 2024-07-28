class Solution {
public:
    int result = INT_MIN;
    int m;
    void solve(int idx , int count , int n , vector<int> &resultant , vector<vector<int>>&requests){
        
        if( idx == m ){
            int allZeros = true;
            for(auto it:resultant){
                if( it != 0){
                    allZeros = false;
                    break;
                }
            }
            if( allZeros ){
            result = max(result , count);
            }
            return;
        }
        
        int from = requests[idx][0];
        int to   = requests[idx][1];
        
        resultant[from]--;
        resultant[to]++;
        
        solve(idx+1 , count+1 , n , resultant , requests);
        
        resultant[from]++;
        resultant[to]--;
        
        solve(idx+1 , count , n , resultant , requests);
        
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        m     = requests.size();
        vector<int> resultant(n , 0);
        //idx , count , n , resultant , requests
        solve(0 , 0 , n , resultant , requests );
        
        return result;
    }
};