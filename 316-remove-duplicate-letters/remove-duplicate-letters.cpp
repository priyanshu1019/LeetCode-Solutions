class Solution {
public:
    string removeDuplicateLetters(string s) {
        string result = "";
        int n         = s.size();
        vector<bool> taken(26 , false);
        vector<int> lastIndex(26 , 0);

        for(int i =0 ; i < n ; i++){
            lastIndex[s[i]-'a'] = i;
        }   

        for(int i = 0 ; i< n ; i++){
            int ind = s[i]-'a';
            if( taken[ind])continue;

            while(result.size()>0 and result.back() > s[i] and lastIndex[result.back()-'a'] > i){
                taken[result.back()-'a'] = false;
                result.pop_back();
            }

            result.push_back(s[i]);
            taken[s[i]-'a'] = true;
        }
        return result;
    }
};