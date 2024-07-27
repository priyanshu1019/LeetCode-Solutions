class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> t(n+1 , vector<int>(n+1));

        for(int i =0 ; i < n ; i++){
            t[i][i] = 0;
        }
        for(int l = 2 ; l<= n ; l++){
            for(int i =0 ; i+l-1 < n ; i++){
                int j = i+l-1;
                if( s[i] == s[j]){
                    t[i][j] = t[i+1][j-1];
                }else{
                    t[i][j] = 1+min(t[i+1][j] , t[i][j-1]);
                }
            }
        }
        return t[0][n-1];
    }
};