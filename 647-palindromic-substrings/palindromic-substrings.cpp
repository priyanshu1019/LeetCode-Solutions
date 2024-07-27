class Solution {
private:
    int t[1001][1001];
    int isPalindrome(int i , int j , string & s){
        if( i >= j) return true;
        if(t[i][j]!= -1)return t[i][j];
        if( s[i] == s[j]) return t[i][j] = isPalindrome(i+1 , j-1 , s);

        return t[i][j] = false;
    }
public:
    int countSubstrings(string s) {
        int n = s.length();
        int ans= 0;
        memset(t , -1 , sizeof(t));
        for(int i =0 ; i < n ; i++){
            for(int j =i ; j < n ; j++){
                if( isPalindrome(i , j , s)){
                    ans+=1;
                }
            }
        }
        return ans;
    }
};