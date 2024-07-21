class Solution {
private:
    vector<int> getNsl(vector<int>& heights ){
        int n = heights.size();
        vector<int> nsl(n);
        stack<int> st;

        for(int i =0 ; i < n ; i++){
            if(st.empty()){
                nsl[i] = -1;
            }else{
                while(!st.empty() and heights[st.top()] >= heights[i]){
                    st.pop();
                }

                nsl[i] = st.empty()? -1:st.top();
            }
            st.push(i);
        }
        return nsl;
    }
    vector<int> getNsr(vector<int>& heights ){
        int n = heights.size();
        vector<int> nsr(n);
        stack<int> st;

        for(int i =n-1 ; i >=0 ; i--){
            if(st.empty()){
                nsr[i] = n;
            }else{
                while(!st.empty() and heights[st.top()] >= heights[i]){
                    st.pop();
                }

                nsr[i] = st.empty()? n:st.top();
            }
            st.push(i);
        }
        return nsr;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nsl = getNsl(heights);
        vector<int> nsr = getNsr(heights);

        int ans = INT_MIN;
        int n   = heights.size();
        for(int i = 0 ; i < n ; i++){
            ans = max(ans , heights[i]*(nsr[i]-nsl[i]-1));
        }

        return ans;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix){
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dist(n , vector<int> ( m , 0));
        for(int row = 0 ; row< n ; row++){
            for(int col =0 ; col < m ; col++){
                if( matrix[row][col] == '1' ){
                    dist[row][col] = 1;
                }else{
                    dist[row][col] = 0;
                }
            }
        }
        for(int row = 0 ; row< n ; row++){
            for(int col =0 ; col < m ; col++){
                if(row != n-1 and dist[row+1][col] != 0){
                    dist[row+1][col] += dist[row][col];
                }
            }
        }
        int ans = 0;
        for(auto &vec: dist){
            int area = largestRectangleArea(vec);
            ans = max(area , ans);
        }

        return ans;
    }
};