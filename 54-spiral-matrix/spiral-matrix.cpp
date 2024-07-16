class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if( matrix.size() == 0){
            return {};
        }
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();
        int dir = 0;
        int top = 0;
        int left =0;
        int bottom= n-1;
        int right= m-1;

        while(left <= right and top<= bottom){
            if( dir == 0){
                for(int i = left ; i <= right ; i++){
                    ans.push_back(matrix[top][i]);
                }
                top++;
            }else if( dir == 1){
                for(int i = top ; i <= bottom ; i++){
                    ans.push_back(matrix[i][right]);
                }
                right--;
            }else if( dir == 2){
                for(int i = right ; i >= left ; i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }else if( dir == 3){
                for(int i = bottom ; i >= top ; i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
            dir = (dir + 1)%4;
        }
        return ans;
    }
};