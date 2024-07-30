class Solution {
public:
    vector<string> result;
    void solve(string &digits , string &curr , int ind , vector<string>&mp){
        if( ind == digits.size()){
            result.push_back(curr);
            return;
        }
        int idx = digits[ind] - '0';
        for(char ch:mp[idx]){
            curr.push_back(ch);
            solve(digits , curr , ind+1 , mp);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return result;
        string curr = "";
        vector<string> mp = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits , curr , 0 ,mp);
        return result;
    }
};