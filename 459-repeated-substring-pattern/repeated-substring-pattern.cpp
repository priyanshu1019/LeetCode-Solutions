class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int  n = s.size();
        for(int i = 1 ; i <= n /2 ; i++){
            if( n % i == 0){
                int count = n / i ;
                string token = s.substr(0 , i);
                string temp = "";
                while( count > 0 ){
                    temp += token;
                    count--;
                }
                if( temp == s)return true;
            }
        }
        return false;
    }
};