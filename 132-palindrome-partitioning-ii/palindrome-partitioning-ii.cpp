class Solution {
public:
    bool isPalindrome(int i , int j , string & s){
        while( i < j ){
            if( s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int  solve(string& s, int ind , vector<int>&t){
        if( ind == s.size())
        {
            return 0;
        }
        if( t[ind] != -1)return t[ind];
        int min_cuts = INT_MAX;
        for(int j = ind ; j < s.size() ; j++){
            if( isPalindrome(ind , j , s)){
                min_cuts = min(min_cuts ,1+ solve(s , j+1 , t ));
            }
        }
        return t[ind] = min_cuts;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> t(n , -1);
        
        return solve(s , 0 , t )-1;
        // return ans;
    }
};