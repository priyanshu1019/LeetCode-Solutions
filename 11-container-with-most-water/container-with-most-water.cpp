class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxiArea = 0;
        int n        = height.size();
        int left    = 0;
        int right    = n-1;
        if( height.size() == 1 || height.size() == 0)return 0;
        while(left < right){
            int area = min(height[left] , height[right])*(right-left);
            maxiArea = max(maxiArea , area);
            
            if( height[left] >= height[right]){
                right--;
            }else{
                left++;
            }
        }

        return maxiArea;
    }
};