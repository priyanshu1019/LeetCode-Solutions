class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        if( s.size() == 0)
        {
            return "";
        }
        string ans;
        int index = 0;
        int count = 0;
        for(int i = 0; i<n ; i++)
        {
            if( s[i] == ')' ) count--;
            else if( s[i] =='(') count++;

            if( count == 0)
            {
                ans += s.substr(index + 1 , i-index -1);
                index = i+1;
            }
        }

        return ans;
        
    }
};