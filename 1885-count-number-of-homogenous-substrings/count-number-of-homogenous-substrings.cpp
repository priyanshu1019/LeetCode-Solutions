class Solution {
public:
    int MOD = 1e9+7;
    int countHomogenous(string s) {
        int len = 0;
        int result = 0;
        int n = s.size();
        for(int i =0 ; i < n ; i++){
            if(i >0 and s[i] == s[i-1]){
                len++;
            }else{
                len =1;
            }
            result = (result + len) % MOD;
        }
        return result % MOD;
    }
};