class Solution {
private:
    int dp[51][6];
    int helper(int ind,int n,int vowelInd){
        if(vowelInd==4||ind==n){
            return 1;
        }
        if(dp[ind][vowelInd]!=-1){
            return dp[ind][vowelInd];
        }
        //let us pick the vowel
        int pick=helper(ind+1,n,vowelInd);
        //not pick
        int notpick=helper(ind,n,vowelInd+1);

        return dp[ind][vowelInd]=pick+notpick;
    }
public:
    int countVowelStrings(int n) {
        memset(dp,-1,sizeof(dp));
        return helper(0,n,0);
    }
};