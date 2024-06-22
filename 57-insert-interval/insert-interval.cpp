class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        int n = intervals.size();
        int ind = n-1;

        while( ind > 0 and intervals[ind-1][0] >= intervals[ind][0]){
            if( intervals[ind-1][0] == intervals[ind][0] ){
                if( intervals[ind-1][1] > intervals[ind][1]){
                    swap(intervals[ind-1] , intervals[ind]);
                }
            }else{
                swap(intervals[ind-1] , intervals[ind]);
            }
            ind--;
        }
        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for(int i = 1 ; i < n ; i++){
            if( result.back()[1] >= intervals[i][0]){
                result.back()[1] = max(result.back()[1] , intervals[i][1]);
            }else{
                result.push_back(intervals[i]);
            }
        }

        return result;

    }
};