class Solution {
public:
    int t[501][501];
    int helper(string &s , int i , int j ){
        if( i >= j){
            return 0;
        }
        if( t[i][j] != -1)return t[i][j];
        if( s[i] == s[j]){
            return t[i][j] = helper(s , i+1 , j-1);
        }else
            return t[i][j] = 1+min(helper(s , i+1 , j),helper(s , i , j-1));
        
    }
    int minInsertions(string s) {
        int n = s.size();
        memset(t , -1 , sizeof(t));
        return helper(s , 0 , n-1);
    }
};