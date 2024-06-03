class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> result;
        result.push_back({1});
        if( numRows == 1) return result;

        //initialize with first and last value as 1 
        for(int i = 1 ; i< numRows ; i++)
        {
            vector<int> temp(i+1);
            temp[0] = 1;
            temp[i] = 1;
            result.push_back(temp);

        }

        //fill values

        for(int i = 2 ; i < numRows ; i++)
        {
            for(int j = 1 ; j<i; j++)
            {
                result[i][j] = result[i-1][j]+result[i-1][j-1];
            }
        }

        return result;
    }
};