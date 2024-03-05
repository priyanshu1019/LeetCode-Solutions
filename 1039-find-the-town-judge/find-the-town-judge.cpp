class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if( trust.size() == 0 ) return n == 1? 1 : -1;
        vector<int> indegree(n+1 , 0);
        vector<int> outdegree(n+1 , 0);

        for(auto &vec:trust)
        {
            int first = vec[0];
            int second = vec[1];
            outdegree[first]++;
            indegree[second]++;
        }
        for(int i = 0 ; i<= n ; i++)
        {
            if(indegree[i] == n-1 and outdegree[i] ==0)
            {
                return i;
            }
            cout<<indegree[i] <<" "<<outdegree[i]<<endl;
        }
        return -1;
    }
};