class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        // Fill the dp array to find the length of LCS
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(str1[i-1] == str2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        string result = "";
        int i = n, j = m;
        
        // Reconstruct the shortest common supersequence
        while(i > 0 && j > 0) {
            if(str1[i-1] == str2[j-1]) {
                result = str1[i-1] + result;
                i--;
                j--;
            } else if(dp[i-1][j] > dp[i][j-1]) {
                result = str1[i-1] + result;
                i--;
            } else {
                result = str2[j-1] + result;
                j--;
            }
        }

        // Add remaining characters of str1
        while(i > 0) {
            result = str1[i-1] + result;
            i--;
        }

        // Add remaining characters of str2
        while(j > 0) {
            result = str2[j-1] + result;
            j--;
        }

        return result;
    }
};
