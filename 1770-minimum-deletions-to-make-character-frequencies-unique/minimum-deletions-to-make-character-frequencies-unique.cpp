class Solution {
public:
    int minDeletions(string s) {
        
        int minDel = 0;
        vector<int> freq(26 , 0);
        unordered_set<int> st;
        for(auto it:s)
        {
            freq[it-'a']++;
        }
        for(auto it:freq)
        {
            if( it == 0) continue;
            if( st.find(it) != st.end() )
            {
                while(st.find(it) != st.end() and it > 0 )
                {
                    it--;
                    minDel++;

                }
                if( it != 0)
                {
                    st.insert(it);
                }
            }else{
                st.insert(it);
            }
        }

        return minDel;

    }
};