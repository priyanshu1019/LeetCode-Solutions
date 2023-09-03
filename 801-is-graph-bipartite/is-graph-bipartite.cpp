class Solution {
    bool check(int start,int n,vector<vector<int>> &graph,vector<int> &color){
        color[start]=0;
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto adjacent:graph[node]){
                if(color[adjacent]==-1){
                    color[adjacent]=!color[node];
                    q.push(adjacent);
                }else if(color[adjacent]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1)//not colored yet
            {
                if(check(i,n,graph,color)==false){
                    return false;
                }
            }
        }
        return true;
    }
};