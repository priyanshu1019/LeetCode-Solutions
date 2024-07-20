class Solution {
private:
    string compress(string &chars) {
        int ind = 0;
        int count = 0;
        char ch;
        string token = "";
        for(int i =0 ; i< chars.size() ; i++){
            if( i == 0){
                ch = chars[i];
                count = 1;
            }else{
                if( chars[i-1] == chars[i]){
                    count++;
                }else{
                    
                    
                        string ctr = to_string(count);
                        for(auto c:ctr){
                            token+= c;
                        }
                    
                    token+= ch;
                    ch = chars[i];
                    count = 1;
                }
            }
        }
        
        
            string ctr = to_string(count);
            for(auto c:ctr){
                token+= c;
            }
        
        token += ch;
        
        return token;
    }
    void helper(int ind , int n , vector<string> &dp){
        if( ind > n) return;
        string com = compress(dp[ind-1]);
        dp[ind] = com;
        helper(ind+1 , n , dp);
    }
public:
    string countAndSay(int n) {
        vector<string> dp( n+1 );
        dp[1] = "1";
        if( n == 1) return "1";
        helper( 2  , n  , dp);
        // for(int i =0 ; i < n+1 ; i++){
        //     cout<<dp[i]<<" ";
        // }
        return dp[n];
    }
};