class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(),points.end());
        int arrowCount = 1;
        int mini = points[0][1];
        
        for(int i = 1 ; i<n ; i++ )
        {
            if( points[i][0] <= mini )
            {
                mini = min(mini , points[i][1]);
            }else{
                arrowCount++;
                mini = points[i][1];
            }
        }

        return arrowCount;
    }
};