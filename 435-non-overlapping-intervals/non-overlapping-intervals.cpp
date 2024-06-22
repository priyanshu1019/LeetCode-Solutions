class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count = 0;
        int n = intervals.size();
        sort(intervals.begin() , intervals.end());
        for(auto it:intervals){
            cout<<it[0]<<" "<<it[1]<<endl;
        }
        vector<int> prev(2);
        prev[0] = intervals[0][0];
        prev[1] = intervals[0][1];
        for(int i =1 ; i< n ; i++ ){
            if( intervals[i][0]< prev[1] ){
                count++;
                prev[1] = min(prev[1] , intervals[i][1]);
            }else{
                prev[0] =intervals[i][0];
                prev[1] =intervals[i][1];
            }
        }

        return count;
    }
};