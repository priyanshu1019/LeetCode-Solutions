class Solution {
public:
    int helper(int n,int c)
    {
        if(n==0)
        {
            return c;
        }
        if(n%2==0)
        {
            //even
            return helper(n/2,c+1);
        }
        return helper(n-1,c+1);
    }
    int numberOfSteps(int n) {
        return helper(n,0);
    }
};