class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin() , g.end());
        sort(s.begin() , s.end());

        int count = 0 ;
        int n = g.size();
        int j = 0;
        for(int i = 0 ; i < n && j<s.size() ; ){
            if( s[j] >= g[i]){
                count++;
                i++;
            }
            j++;
        }

        return count;
    }
};