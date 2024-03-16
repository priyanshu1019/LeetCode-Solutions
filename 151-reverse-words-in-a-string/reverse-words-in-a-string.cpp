class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string ans ="";
        string currWord="";
        int i = 0;
        for(char &ch:s)
        {
            if( ch != ' ')
            {
                currWord +=ch;
            }else{
                if( currWord == "")
                {
                    continue;
                }
                if( i == 0 )
                {
                    ans = currWord;
                    i++;
                }
                else{
                    ans = currWord + " " + ans;
                }
                currWord = "";
            }
        }
        if( currWord != "")
        {
            if( i == 0 )
                {
                    ans = currWord;
                    i++;
                }
                else{
                    ans = currWord + " " + ans;
                }
        }
        return ans;
    }
};