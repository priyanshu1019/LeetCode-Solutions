class Solution {
private:
    void helper(vector<vector<int>> &ans , vector<int> &temp , int k , int n , int i )
    {
        if( k == 0 and n == 0 )
        {
                ans.push_back(temp);
                return;
            
        }
        if ( k <0 || n<0) return;
        if( i > 9) return ;
        temp.push_back(i);
        helper(ans , temp , k-1 , n-i , i+1 );
        temp.pop_back();
        helper(ans , temp , k ,n  , i+1 );
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        if(k>n)
        {
            return ans;
        }
        vector<int> temp;
        helper(ans , temp , k , n , 1);
        return ans;
    }
};