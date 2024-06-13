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
        int countExtra = 0;

        for(auto &connection:connections)
        {
            int u = connection[0];
            int v = connection[1];

            int u_parent = ds.findParent(u);
            int v_parent = ds.findParent(v);

            if( u_parent == v_parent){
                //already a connection meaning this is extra connection
                countExtra++;
                continue;
            }
            ds.unionByRank(u,v);
        }

        int countDisconnectedNodes = 0;
        for(int i = 0 ; i< n ; i++)
        {
            if( ds.parent[i] == i )
            {
                countDisconnectedNodes++;
            }
        }

        if( countDisconnectedNodes-1 <= countExtra) return countDisconnectedNodes-1;

        return -1;
    }
};