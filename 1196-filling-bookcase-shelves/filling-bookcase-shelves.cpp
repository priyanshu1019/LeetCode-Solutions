class Solution {
public:
    int n ;
    int WIDTH;
    int t[1001][1001];
    int solve(vector<vector<int>>&books , int ind , int remainingW , int maxH){

        if( ind  >= n) return maxH;
        if( t[ind][remainingW] != -1){
            return t[ind][remainingW];
        }
        int bookW = books[ind][0];
        int bookH = books[ind][1];
        int take  = INT_MAX;
        int skip  = INT_MAX;
        if(bookW <= remainingW){
            take  = solve(books , ind+1 , remainingW-bookW , max(maxH , bookH));
        }
        skip      = maxH + solve(books , ind+1 ,WIDTH - bookW , bookH );

        return t[ind][remainingW] = min(take , skip);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset(t , -1 , sizeof(t));
        n = books.size();
        WIDTH = shelfWidth;
        int remainingW = shelfWidth;
        return solve(books , 0 , remainingW , 0 );
    }
};