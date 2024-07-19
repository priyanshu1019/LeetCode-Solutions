class Solution {
private:
    bool isValid( string &str){
        stack<char> st;

        for(char ch : str){
            if( ch == '('){
                st.push(ch);
            }else{
                if( st.empty() || st.top() != '(' and ch == ')') return false;
                st.pop();
            }
        }
        return st.empty();
    }
    void solve(string &str , vector<string>&result , int n ){
        if( str.size() == 2*n) {
            if( isValid(str) == true) result.push_back(str);

            return;
        }

        //open bracket 
        str.push_back('(');
        solve(str , result , n);
        //backtrack
        str.pop_back();
        //close bracket
        str.push_back(')');
        solve(str , result , n);
        str.pop_back();
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string str ="";
        solve(str, result , n );

        return result;
    }
};