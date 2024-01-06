class Solution {
public:
    string convert(string s, int numRows) {
        if( numRows <= 1) return s;
        vector<string> li(numRows , "");
        int currentLine = 0;
        bool reachedEdge = true;

        for(int i = 0 ; i<s.length() ; i++)
        {
            if( currentLine == 0 || currentLine == numRows -1 )
            {
                reachedEdge = !reachedEdge;
            }
            li[currentLine]+=s[i];
            if( reachedEdge)
            {
                currentLine--;
            }else{
                currentLine++;
            }
        }

        string ans = "";
        for(auto &str : li)
        {
            ans+= str;
        }

        return ans;

    }
};