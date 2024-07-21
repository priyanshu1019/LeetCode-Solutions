class Solution {
public:
    bool isVowel(char ch){
        return ch == 'a'||ch == 'e'|| ch == 'i' ||ch == 'o' || ch == 'u';
    }
    int beautifulSubstrings(string s, int k) {
        int n = s.size();
        int result = 0;
        for(int i =0 ; i < n ; i++){
            int vowelCount = 0;
            int consonantCount = 0;
            for(int j = i ; j<n ; j++){
                if(isVowel(s[j])){
                    vowelCount++;
                }else{
                    consonantCount++;
                }
                if( vowelCount == consonantCount and (vowelCount * consonantCount ) % k == 0){
                    result ++;
                }
            }
        }
        return result;
    }
};