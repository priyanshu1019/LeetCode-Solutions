class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        int left = n-1;
        int right = 0;
        while( left >= 0 and right < m){
            if( nums1[left] <= nums2[right]){
                break;
            }else{
                swap(nums1[left--] , nums2[right++]);
            }
        }

        sort(nums1.begin() , nums1.begin()+n);
        sort(nums2.begin() , nums2.end());
        int i = n;
        for(int j = 0 ; j < m ; j++){
            nums1[i+j] = nums2[j];
        }

    }
};