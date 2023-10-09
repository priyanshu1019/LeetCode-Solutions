class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> t(n+1);
        t[1]=1;
        int i2=1;
        int i3=1;
        int i5=1;
        for(int i=2;i<=n;i++){
            int i2Ugly=t[i2]*2;
            int i3Ugly=t[i3]*3;
            int i5Ugly=t[i5]*5;

            int mini=min({i2Ugly,i3Ugly,i5Ugly});

            t[i]=mini;
            if(mini==i2Ugly){
                i2++;
            }
            if(mini==i3Ugly){
                i3++;
            }
            if(mini==i5Ugly){
                i5++;
            }

        }
        return t[n];
    }
};