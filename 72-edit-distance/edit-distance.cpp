class Solution {
public:
    int n , m;
    int t[501][501];
    int helper(string &word1 , string &word2 , int i , int j){
        if( i == n){
            return m-j;
        }
        else if( j == m){
            return n-i;
        }
        if( t[i][j] != -1) return t[i][j];
        if( word1[i] == word2[j]){
            return t[i][j] = helper(word1 , word2 , i+1 , j+1);
        }
        int replace =1+ helper(word1 , word2 , i+1 , j+1);
        int dele  =1+ helper(word1 , word2 , i+1 , j);
        int insert  =1+ helper(word1 , word2 , i, j+1);

        return t[i][j] = min({replace , dele , insert});
    }
    int minDistance(string word1, string word2) {
        n = word1.size();
        m = word2.size();
        memset(t , -1 , sizeof(t));
        return helper(word1 , word2 , 0 , 0);

    }
};