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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int count=0;
        for(auto it:connections){

            int u=it[0];
            int v=it[1];
            int parU=ds.findParent(u);
            int parV=ds.findParent(v);
            if(parU==parV){
                count++;
            }
            else {
                ds.unionBySize(u,v);
            }
        }
        //count is extra wire
        //now we need no of components not connect 
        int single=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i){
                single++;
            }
        }
        int ans=single-1;
        if(count>=ans){
            return ans;
        }
        return -1;
    }
};