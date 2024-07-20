class Solution {
public:
    string smallestSubsequence(string s) {
        int n         = s.size();
        string result = "";
        vector<bool> taken(26 ,false);
        vector<int> lastIndex(26 , 0);

        for(int i =0 ; i < n ; i++ ){
            lastIndex[s[i]-'a'] = i;
        }
        for(int i =0 ; i < n; i++){
            int ind = s[i]-'a';
            if( taken[ind] == true) continue;

            while(result.size() > 0 and result.back() > s[i] and lastIndex[result.back()-'a'] > i){
                taken[result.back()-'a'] = false;
                result.pop_back();
            }
            result.push_back(s[i]);
            taken[ind] = true;
        }

        return result;
    }
};