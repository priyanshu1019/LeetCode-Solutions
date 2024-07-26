class Solution {
public:
    int t[1001][1001];
    int helper(string &text1 , string &text2 , int i , int j){
        if( i >= text1.size() || j >= text2.size()) return 0;
        int take = 0 , notTake = 0;
        if( t[i][j]!= -1)return t[i][j];
        if( text1[i] == text2[j]){
            take = 1 + helper(text1 , text2 , i+1 , j+1);
        }else{

        notTake = max(helper(text1 , text2 , i+1 , j) , helper(text1 , text2 , i , j+1));
        }

        return t[i][j] = max(take , notTake);

    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(t , -1 , sizeof(t));
        return helper(text1 , text2 , 0 , 0 );
    }
};