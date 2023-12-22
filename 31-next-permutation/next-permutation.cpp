class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n   = nums.size();
        int ind = -1;
        
        //break point
        for(int i = n-2 ; i >=0 ; i--){
            
            if( nums[i+1] > nums[i] ){
                
                ind = i;
                break;
                
            }
            
        }
        cout<<ind;
        if( ind == -1){
            reverse(nums.begin()  , nums.end());
            return;
        }
        cout<<"here";
        //find just greater element and swap
        for(int i = n-1; i > ind ; i-- ){
            
            if(nums[i] > nums[ind]){
                swap(nums[i] , nums[ind]);
                break;
            }
            
        }
        
        //reverse the elements after the break point
        reverse(nums.begin()+ind +1, nums.end());
        return;

    }
};