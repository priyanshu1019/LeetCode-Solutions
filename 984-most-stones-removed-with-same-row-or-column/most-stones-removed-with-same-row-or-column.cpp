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
    int removeStones(vector<vector<int>>& stones) {
        //since we are not directly given the matrix with 1 indicating a stone
        //but we are given the coordinates 
        //let us find the last row and last col where a stone is placed
        int lastRow=0;
        int lastCol=0;
        for(auto it:stones){
            lastRow=max(lastRow,it[0]);
            lastCol=max(lastCol,it[1]);
        }
        DisjointSet ds(lastRow+lastCol+1);//1 just for safety
        unordered_map<int,int> stoneNodes;
        for(auto it:stones){
            int nodeRow=it[0];//row itself
            int nodeCol=it[1]+lastRow+1;
            //now combine these two 
            ds.unionByRank(nodeRow,nodeCol);
            stoneNodes[nodeRow]=1;
            stoneNodes[nodeCol]=1;
        }
        int count=0;
        for(auto it:stoneNodes){
            if(ds.findParent(it.first)==it.first){
                count++;
            }
        }
        return stones.size()-count;
    }
};