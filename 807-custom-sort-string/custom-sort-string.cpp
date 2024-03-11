class Solution {
public:
    string customSortString(string order, string s) {
        int n = order.size();
        int m = s.size();
        map<int , char> om;
        unordered_map<char,int> sm;

        for(int i = 0 ; i< n ; i++)
        {
           om[i] = order[i];
        }
        for(int i = 0 ; i<m ; i++)
        {
            sm[s[i]]++;
        }
        char arr[s.length()];
        int ind = 0;
        for(auto &it:om)
        {
            if( sm.find(it.second)!= sm.end())
            {
                while(sm[it.second]>0)
                {
                    arr[ind] = it.second;
                    ind++;
                    sm[it.second]--;
                }
            }
        }
        for(auto &it:sm)
        {
            if(it.second != 0)
            {
                while(it.second >0)
                {
                    arr[ind] = it.first;
                    ind++;
                    it.second--;
                }
            }
        }

        string ans = "";
        for(int i = 0 ; i<m ; i++)
        {
            ans+= arr[i];
        }
        return ans;
    }
};
