class Solution {
private:
    bool isPalindrome(string s , int low , int high){
        while(low <= high){
            if(s[low] != s[high]){
                return false;
            }
            low ++;
            high--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int n = s.size();
        int low = 0;
        int high = n-1;

        while(low <= high){
            if( s[low] != s[high]){
                //check by skipping left or right 
                return (isPalindrome(s , low + 1 , high) || isPalindrome(s , low , high -1));
            }else{
                low++;
                high--;
            }
        }
        return true;
    }
};