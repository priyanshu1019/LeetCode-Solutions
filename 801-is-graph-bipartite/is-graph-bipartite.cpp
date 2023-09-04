class Solution {
    bool check(int node,int n,vector<vector<int>> &graph,vector<int> &color){
        
       for(auto adjacent:graph[node]){
                if(color[adjacent]==-1){
                    color[adjacent]=!color[node];
                    if(!check(adjacent,n,graph,color)){
                        return false;
                    }
                }else if(color[adjacent]==color[node]){
                    return false;
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
                color[i]=0;
                if(check(i,n,graph,color)==false){
                    return false;
                }
            }
        }
        return true;
    }
};