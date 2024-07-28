class Solution {
public:
    vector<vector<int>> result;
    void solve(int ind , int &n , int k , vector<int>&curr){
        if( k== 0) {
            result.push_back(curr); 
            return;
        }
        if( ind > n )return;

        curr.push_back(ind);
        solve(ind+1 , n , k-1 , curr);
        curr.pop_back();
        solve(ind+1 , n , k , curr);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        solve(1 , n , k , curr);
        return result;
    }
};