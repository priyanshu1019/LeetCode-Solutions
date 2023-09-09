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
private:
    bool isValid(int row,int col,int n,int m){
      return row>=0 && row<n && col>=0 && col<m;
  }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size(); 
        DisjointSet ds(n*n);
        //conecting the islands first 
        int countOne=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0)continue;
                countOne++;
                int dx[]={-1,0,1,0};
                int dy[]={0,1,0,-1};
                for(int ind=0;ind<4;ind++){
                    int adjRow=row+dx[ind];
                    int adjCol=col+dy[ind];
                    if(isValid(adjRow,adjCol,n,n) && grid[adjRow][adjCol]==1){
                        int nodeNo=row*n+col;
                        int adjNodeNo=adjRow*n+adjCol;
                        ds.unionBySize(nodeNo,adjNodeNo);
                    }
                }
            }
        }
        if(countOne==n*n){
            return n*n;
        }
        int mx=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1)continue;
                int dx[]={-1,0,1,0};
                int dy[]={0,1,0,-1};
                set<int> components;
                for(int ind=0;ind<4;ind++){
                    int adjRow=row+dx[ind];
                    int adjCol=col+dy[ind];
                    if(isValid(adjRow,adjCol,n,n) && grid[adjRow][adjCol]==1){
                        // int nodeNo=row*n+col;
                        // int adjNodeNo=adjRow*n+adjCol;
                        // ds.unionBySize(nodeNo,adjNodeNo);
                        components.insert(ds.findParent(adjRow*n+adjCol));
                    }
                }
                int totalSize=0;
                for(auto it:components){
                    totalSize+=ds.size[it];
                }
                mx=max(mx,totalSize+1);
            }
        }
        return mx;
    }
};