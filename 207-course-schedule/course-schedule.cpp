class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> indegree(n , 0 );
        vector<int> adj[n];
        for(auto &vec : prerequisites)
        {
            int u = vec[0];
            int v = vec[1];
            adj[v].push_back(u);
            indegree[u]++;
        }

        int count = 0;
        queue<int> q;
        for(int i =0 ; i< n ; i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;

            for(int adjNode:adj[node])
            {
                indegree[adjNode]--;
                if(indegree[adjNode]==0)
                {
                    q.push(adjNode);
                }
            }
        }

        return count==n;
    }
};