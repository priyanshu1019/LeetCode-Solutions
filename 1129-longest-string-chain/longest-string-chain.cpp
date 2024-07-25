class Solution {
private:
    bool isPossible(string &curr , string &prev){
        int count = 0;
        int n = curr.size();
        int m = prev.size();
        if( m >= n ||  n - m >= 2) return false;
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
    
public:
    int longestStrChain(vector<string>& words) {
        auto cmp = [&](string a , string b){
            return a.size() < b.size();
        };
        sort(words.begin() , words.end() , cmp);
        int n = words.size();
        int maxLEN = 1;
        vector<int>dp(n , 1);
        for(int ind = 0 ; ind < n ; ind++){
            for(int prev = 0 ; prev < ind ; prev++){
                if( isPossible(words[ind] , words[prev])){
                    dp[ind] = max(dp[ind] , 1+dp[prev]);
                }
                maxLEN = max(maxLEN , dp[ind]);
            }
        }
        return maxLEN;
    }
};