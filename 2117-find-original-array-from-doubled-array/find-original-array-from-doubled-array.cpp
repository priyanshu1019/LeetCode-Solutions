class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        
        if( changed.size() % 2 != 0) return {};
        vector<int> original ;
        map<int,int> mp;
        sort(changed.begin(),changed.end());
        for(auto &it: changed)
        {
            mp[it]++;
        }

        for(auto &it: changed)
        {
            if( mp[it] == 0)
            {
                //doubled value may be 
                continue;
            }
            int doubled = it*2;
            if( mp.find(doubled) == mp.end() || mp[doubled] == 0 )
            {
                return {};
            }
            original.push_back(it);
            mp[it]--;
            mp[doubled]--;
        }
        return original;
    }
};