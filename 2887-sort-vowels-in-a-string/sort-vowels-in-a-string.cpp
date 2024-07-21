class Solution {
private:
    bool isVowel(char ch){
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
public:
    string sortVowels(string s) {
        unordered_map<char , int> mp;
        for(auto &ch:s){
            if(isVowel(ch)){
                mp[ch]++;
            }
        }
        string correctOrder = "AEIOUaeiou";
        int j = 0;

        for(int i = 0 ; i < s.size() ; i++){
            if( isVowel(s[i])){
                while(mp[correctOrder[j]] == 0) j++;
                s[i] = correctOrder[j];
                mp[correctOrder[j]]--;
            }
        }
        return s;
    }
};