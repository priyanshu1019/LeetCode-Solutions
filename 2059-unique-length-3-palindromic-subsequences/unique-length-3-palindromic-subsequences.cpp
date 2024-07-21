class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> letters;
        int n = s.size();
        int result = 0;
        for(auto &ch:s){
            letters.insert(ch);
        }
        for(auto &letter:letters){
            //find first and last index of this letter
            int first_idx = -1;
            int last_idx  = -1;
            for(int i =0 ;i < n ; i++){
                if( s[i] == letter){
                    if( first_idx == -1) first_idx = i;
                    last_idx = i;
                }
            }
            unordered_set<char> st;
            for(int i = first_idx + 1 ; i< last_idx ; i++){
                st.insert(s[i]);
            }
            result += st.size();
        }
        return result;
    }
};