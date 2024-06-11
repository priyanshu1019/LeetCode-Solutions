class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        vector<int> indegree(n , 0);

        for(auto &vec:pre)
        {
            int u = vec[0];
            int v = vec[1];
            adj[v].push_back(u);

            indegree[u]++;
        }
        queue<int> q;
        for(int i =0 ; i< n ;i++)
        {
            if(indegree[i] == 0 )
            {
                q.push(i);
            }
        }

        vector<int> order;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            order.push_back(node);

            for(int &adjNode:adj[node])
            {
                indegree[adjNode]--;
                if(indegree[adjNode] == 0 )
                {
                    q.push(adjNode);
                }
            }
        }
        vector<int> empty;
        return order.size() < n ? empty:order;
    }
};