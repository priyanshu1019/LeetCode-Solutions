class Solution {
public:
    void solve(string &s, int ind , vector<vector<string>>&result , vector<string>&currPartition  , vector<vector<bool>>&t){
        if( ind == s.size()){
            result.push_back(currPartition);
            return;
        }
        for(int j = ind ; j < s.size() ; j++){
            if( t[ind][j] == true){
                currPartition.push_back(s.substr(ind , j-ind+1));
                solve(s , j+1 , result , currPartition, t);
                currPartition.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> t(n+1 , vector<bool>(n+1 , false));
        for(int i = 0 ; i < n ; i++){
            t[i][i] = true;
        }
        for(int l = 2 ; l <= n ; l++){
            for(int i = 0 ; i+l-1<n ; i++){
                int j = i+l - 1;
                if( s[i] == s[j]){
                    t[i][j] = (l == 2) ? true:t[i+1][j-1];
                }
            }
        }
        vector<vector<string>> result;
        vector<string> currPartition;
        solve(s , 0 , result , currPartition , t);
        return result;
    }
};