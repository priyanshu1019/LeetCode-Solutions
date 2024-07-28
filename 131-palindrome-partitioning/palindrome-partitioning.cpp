class Solution {
public:
    vector<vector<string>> result;
    bool isPalindrome(string&s , int i , int j ){
        while(i < j){
            if( s[i] != s[j])return false;
            i++;j--;
        }
        return true;
    }
    void helper(string &s , vector<string>&curr , int ind){
        if( ind == s.size()) {
            result.push_back(curr);
            return;
        }
        for(int i = ind; i < s.size(); i++){
            if(isPalindrome(s , ind , i)){
                curr.push_back(s.substr(ind , i-ind+1));
                helper(s , curr , i+1);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        helper(s , curr , 0 );
        return result;
    }
};