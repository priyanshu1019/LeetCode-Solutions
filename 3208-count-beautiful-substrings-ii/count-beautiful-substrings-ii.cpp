class Solution {
private:
    bool isVowel( char ch){
        return ch == 'a'||ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
public:
    # define ll long long
    long long beautifulSubstrings(string s, int k) {
        ll vowel     = 0;
        ll consonant = 0;
        unordered_map<ll , unordered_map<ll , ll>> mp;
        mp[0][0]     = 1;
        ll result    = 0;
        int n        = s.size();
        for(int i =0 ; i < n ; i++ ){
            if( isVowel(s[i])){
                vowel++;
            }else{
                consonant++;
            }
            ll pSum = vowel - consonant;

            for(auto &[pastVowelCount , count]:mp[pSum]){
                if((vowel%k - pastVowelCount)*(vowel % k - pastVowelCount) % k == 0){
                    result += count;
                }
            }
            mp[pSum][vowel % k]++;
        }
        return result;
    }
};