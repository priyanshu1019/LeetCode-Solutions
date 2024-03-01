class Solution {
private:
    string generateKey(string word)
    {
        int freq[26] = {0};
        for(char ch:word)
        {
            freq[ch-'a']++;
        } 
        string key ="";
        for(int i = 0 ; i<26;i++)
        {
            if(freq[i]>0)
            {
                char ch = 'a'+i;
                for(int j = 0 ; j<freq[i];j++)
                {
                    key+=ch;
                }
            }
        }
        return key;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result ;
        unordered_map<string , vector<string>> mp;

        int n = strs.size();
        for(int i = 0 ; i<n ; i++)
        {
            string key = generateKey(strs[i]);
            mp[key].push_back(strs[i]);
        }

        for(auto &it:mp )
        {
            result.push_back(it.second);
        }
        return result;
    }
};