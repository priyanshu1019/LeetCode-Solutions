class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> safe;
        vector<int> indegree(n , 0);
        vector<int> reversedAdj[n];

        for(int u = 0 ; u< n; u++)
        {
            for(int &v:graph[u])
            {
                reversedAdj[v].push_back(u);
                indegree[u]++;
            }
        }
        queue<int> q;
        for(int i =0; i<n ; i++)
        {
            if(indegree[i] ==0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            safe.push_back(node);

            for(int adjNode:reversedAdj[node])
            {
                indegree[adjNode]--;
                if( indegree[adjNode]==0)
                {
                    q.push(adjNode);
                }
            }
        }

        sort(safe.begin(), safe.end());
        return safe;
    }
};