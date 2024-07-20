class Solution {
private:
    int n; 
    unordered_map<string,bool>mp;
    bool isConcatenated(string &word , unordered_set<string>&st){
        if( mp.find(word) != mp.end())return mp[word];
        int len = word.size();
        for(int i = 0 ; i < len ;i++ ){
            string prefix = word.substr(0 , i+1);
            string suffix = word.substr(i+1);
            if( (st.find(prefix)!= st.end() and st.find(suffix)!= st.end()) 
            || (st.find(prefix ) != st.end() and isConcatenated(suffix , st))){
                return mp[word]=true;
            }
        }
        return mp[word] = false;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        n = words.size();
        mp.clear();
        vector<string> result;
        unordered_set<string> st(words.begin() , words.end());
        for(int i =0 ; i < n ; i++ ){
            if( isConcatenated(words[i] , st)){
                result.push_back(words[i]);
            }
        }

        return result;
    }
};