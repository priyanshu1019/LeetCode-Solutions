class Solution {
private:
    int timer=1;
    void dfs(int node,int parent,vector<int> &vis,vector<int> adj[],
    vector<int> &time ,vector<int> &low,vector<vector<int>> &bridges){

            vis[node]=1;
            time[node]=low[node]=timer;
            timer++;
            for(auto adjNode:adj[node]){
                if(adjNode==parent)continue;
                if(vis[adjNode]==0){
                    dfs(adjNode,node,vis,adj,time,low,bridges);
                    low[node]=min(low[node],low[adjNode]);
                    if(low[adjNode]>time[node]){
                        //bridge alert
                        bridges.push_back({node,adjNode});
                    }


                }else{

                    low[node]=min(low[node],low[adjNode]);
                }
            }




    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> vis(n,0);
        vector<int> adj[n];
        for(auto it:connections){
                adj[it[0]].push_back(it[1]);
                adj[it[1]].push_back(it[0]);
        }
        vector<int> time(n);
        vector<int> low(n);
        vector<vector<int>> bridges;
        dfs(0,-1,vis,adj,time,low,bridges);
        return bridges;

    }
};