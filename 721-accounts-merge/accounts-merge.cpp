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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int> mapMailNode;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mapMailNode.find(accounts[i][j])==mapMailNode.end()){
                    //that is we couldn't find 
                    mapMailNode[accounts[i][j]]=i;
                }else{
                    ds.unionBySize(i,mapMailNode[accounts[i][j]]);
                }
            }
        }
        vector<string> mergeMail[n];
        for(auto it:mapMailNode){
            string mail=it.first;
            int node=ds.findParent(it.second);
            mergeMail[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(mergeMail[i].size()==0)continue;
            sort(mergeMail[i].begin(),mergeMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(int j=0;j<mergeMail[i].size();j++){
                temp.push_back(mergeMail[i][j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};