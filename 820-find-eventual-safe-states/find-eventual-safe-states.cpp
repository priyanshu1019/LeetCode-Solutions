class Solution {
private:
    bool dfs(int node,vector<vector<int>> &graph,vector<int> &vis,vector<int> &pathVis,vector<int> &check){
        vis[node]=1;
        pathVis[node]=1;
        check[node]=0;
        //check is 1 means safe
        for(auto it:graph[node]){
            if(!vis[it]){
                if(dfs(it,graph,vis,pathVis,check)){
                    return true;
                }
            }else if(pathVis[it]){
                    return true;
                }
        }
        check[node]=1;
        //because we traversed completely and we didn't find any cycle for the path starting 
        //with this node so it is safe 

        pathVis[node]=0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0);
        vector<int> pathVis(n,0);
        vector<int> check(n,0);
        vector<int> safeNodes;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,graph,vis,pathVis,check);
            }
        }
        for(int i=0;i<n;i++){
            if(check[i]){
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};