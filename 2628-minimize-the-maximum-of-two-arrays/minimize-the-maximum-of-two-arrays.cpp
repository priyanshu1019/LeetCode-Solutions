class Solution {
public:
    int gcd(int a , int b )
    {
        if( b == 0)
        {
            return a;
        }
        return gcd(b , a % b);
    }
    int minimizeSet(int d1, int d2, int u1, int u2) {
        
        long l = 1 , r = 2000000009;
        long lcm = ((long) d1 * (long) d2) / gcd(d1 , d2);
        long ans = r;
        while(l<= r)
        {
            long mid = r - ( r-l)/2;
            int x = (int)(mid - (mid /d1));
            int y = (int)(mid - (mid /d2));
            int z = (int)(mid - (mid/lcm));
            if(x<u1 || y<u2 || z<u1+u2){
                l = mid+1;
            }else{
                ans = min(ans , mid);
                r = mid-1;
            }
        }

        return (int) ans;

    }
};