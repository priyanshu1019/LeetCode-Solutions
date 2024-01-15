class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<char , int> mp1 , mp2;
        for(auto it:word1)
        {
            mp1[it]++;
        }
        for(auto it:word2)
        {
            mp2[it]++;
        }
        map<int, int> mp;
        for(auto it:mp1)
{
    if(mp2.find(it.first) == mp2.end()) return false;
    mp[it.second]++;
}
for(auto it:mp2)
{
    if(mp1.find(it.first) == mp1.end()) return false;
    mp[it.second]--;
}

        for(auto it:mp)
        {
            if(it.second != 0)
            {
                return false;
            }
        }
        return true;
    }
};