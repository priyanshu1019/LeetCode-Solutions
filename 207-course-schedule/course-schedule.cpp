class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n=numCourses;
        vector<int> adj[n];
        vector<int> indegree(n,0);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        int count=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            for(auto adjNode:adj[node]){
                indegree[adjNode]--;
                if(indegree[adjNode]==0){
                    q.push(adjNode);
                }
            }
        }
        return count==n? true:false;

    }
};