class Solution {
private:
    
    void solve(string &str , vector<string>&result , int n , int open , int close){
        if( str.size() == 2*n) {
            result.push_back(str);
            return;
        }

        //open bracket 
        if( open < n){
            str.push_back('(');
            solve(str , result , n , open +1, close);
            str.pop_back();
        }
        //backtrack
        //close bracket
        if( close < open){
            str.push_back(')');
            solve(str , result , n , open , close+1);
            str.pop_back();
        }
        
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string str ="";

        solve(str, result , n , 0 , 0 );

        return result;
    }
};