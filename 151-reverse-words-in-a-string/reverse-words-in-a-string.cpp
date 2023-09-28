class Solution {
private:
    string ltrim(string temp){
        string ans="";
        bool flag=false;
        for(char ch:temp){
            if(ch!=' '){
                flag=true;
            }
            if(flag){
                ans+=ch;
            }

        }
        return ans;
    }
public:
    string reverseWords(string str) {
        string temp="";
        string ans="";
        reverse(str.begin(),str.end());
        for(int i=0;i<str.size();i++){
            char  ch=str[i];
            if(ch!=' '){
                temp+=ch;
            }else if (ch == ' ' && i > 0 && str[i - 1] != ' '){
                reverse(temp.begin(),temp.end());
                ans+=temp+' ';
                temp="";
            }
        }	
        reverse(temp.begin(),temp.end());
        ans+=temp;
        ans=ltrim(ans);
        reverse(ans.begin(),ans.end());
        ans=ltrim(ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};