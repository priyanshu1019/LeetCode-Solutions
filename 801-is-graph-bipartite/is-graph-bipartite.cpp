class Solution {
private:
    bool check(int node , vector<int> adj[] , vector<int> &color )
    {
        for(int &adjNode:adj[node])
        {
            if( color[adjNode]  == -1)
            {
                color[adjNode] = !color[node];
                if(check(adjNode , adj , color) ==false)
                {
                    return false;
                }
            }else if( color[adjNode] == color[node])
            {
                return false;
            }
        }

        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adj[n];
        vector<int> color(n , -1);

        //adjList
        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<graph[i].size(); j++)
            {
                adj[i].push_back(graph[i][j]);
            }
        }

        for(int i = 0 ; i< n ; i++)
        {
            if( color[i] == -1)
            {
                //not colored
                color[i] = 1;
                if( check(i , adj , color) == false)
                {
                    return false;
                }
            }
        }

        return true;

        
    }
};