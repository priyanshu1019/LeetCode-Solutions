class DisjointSet{
    
    public:
    vector<int> rank,size,parent;
    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findParent(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findParent(parent[node]);
    }
    void unionByRank(int u,int v){
        int ulp_u=findParent(u);
        int ulp_v=findParent(v);
        if(ulp_u==ulp_v){
            return;
        }
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }else{
            parent[ulp_v]=ulp_u;
        }
    }
    void unionBySize(int u,int v){
        int ulp_u=findParent(u);
        int ulp_v=findParent(v);
        if(ulp_u==ulp_v){
            return;
        }
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        
        for(auto &edge:edges)
        {
            int u = edge[0];
            int v = edge[1];
            ds.unionBySize(u , v);
        }
        vector<int> imp;
        for(int i =0 ; i< n ; i++)
        {
            if(ds.findParent(i )== i) imp.push_back(i);
        }
        long long  ans = 0 ;
        int remainingNodes = n;
        for(auto &it:imp)
        {
            long long  size = ds.size[it];

            ans = ans +(remainingNodes-size)*size;
            remainingNodes -= size;
        }

        return ans;
    }

};