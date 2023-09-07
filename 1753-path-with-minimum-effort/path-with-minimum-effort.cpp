class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        dist[0][0]=1;
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        while(!pq.empty()){
            auto it =pq.top();
            pq.pop();
            int dif=it.first;
            int x=it.second.first;
            int y=it.second.second;
            if(x==n-1 && y==m-1) return dif;
            for(int i=0;i<4;i++){
                int newX=x+dx[i];
                int newY=y+dy[i];
                if(newX>=0 && newX<n && newY>=0 && newY<m){
                    int newEffort=max(dif,abs(heights[x][y]-heights[newX][newY]));
                        if(newEffort<dist[newX][newY]){
                            dist[newX][newY]=newEffort;
                            pq.push({newEffort,{newX,newY}});
                        }
                    
                }
            }
        }
        return 0;
    }
};