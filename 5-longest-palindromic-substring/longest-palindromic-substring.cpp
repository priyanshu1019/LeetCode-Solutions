class Solution {
private:
    bool isPalindrome( string &s , int i , int j , vector<vector<int>> &dp )
    {
        
        if( i >= j ) return true;
        if( dp[i][j] != -1 ) return dp[i][j];
        if( s[i] == s[j]){
            return dp[i][j] = isPalindrome( s , i+1 , j-1 , dp );
        }
        return dp[i][j] = false;
        
    }
public:
    string longestPalindrome(string s) {
        
        int n         = s.size();
        int maxLen    = INT_MIN;
        int startPos = 0;
        vector<vector<int>> dp(1001 , vector<int>( 1001 , -1));
        for( int i = 0 ; i < n ; i++ )
        {
            
            for(int j = i ; j < n ; j++ )
            {
                
                if( isPalindrome( s , i , j , dp ) and ( j- i + 1) >maxLen ){
                    
                    maxLen   = j - i + 1;
                    startPos = i ;
                }
                
            }
            
        }
        
        return s.substr( startPos , maxLen );
        
    }
};