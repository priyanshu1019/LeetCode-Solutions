class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int arrowCount = 1;
        int n = points.size();
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
        });
        int mini = points[0][1];

        for(int i = 1 ; i< n ; i++)
        {
            if( points[i][0] <= mini)
            {
                mini = min(mini,points[i][1]);
            }else{
                mini = points[i][1];
                arrowCount++;
            }
        }
        return arrowCount;
    }
};