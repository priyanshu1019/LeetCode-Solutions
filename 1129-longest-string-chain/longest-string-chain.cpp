class Solution {
private:
    bool isPossible(string &curr , string &prev){
        int count = 0;
        int n = curr.size();
        int m = prev.size();
        if( m >= n) return false;
        if( n - m >= 2)return false;
        int j = 0;
        for(int i = 0 ; i<n;){
            if( curr[i] == prev[j]){
                i++ ; j++;
            }else{
                count++;
                i++;
            }
        }
        return count == 1;
    }
    int helper(vector<string>& words , int ind , int prev , vector<vector<int>>&dp ){

        if(ind >= words.size()) return 0;
        if( dp[ind][prev+1] != -1)return dp[ind][prev+1];
        int len = helper(words , ind+1 , prev , dp);

        if( prev == -1 || isPossible(words[ind] , words[prev])){
            len = max(len , 1+ helper(words , ind+1 , ind, dp));
        }
        return dp[ind][prev+1]=len;

    }
public:
    int longestStrChain(vector<string>& words) {
        auto cmp = [&](string a , string b){
            return a.size() < b.size();
        };
        sort(words.begin() , words.end() , cmp);
        int n = words.size();
        vector<vector<int>> dp(n , vector<int>(n+1 , -1));
        return helper(words , 0 , -1 , dp);
        return 0;
    }
};