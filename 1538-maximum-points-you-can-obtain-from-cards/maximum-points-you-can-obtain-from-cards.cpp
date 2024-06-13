class Solution {
public:
    int maxScore(vector<int>& points, int k) {
        int n = points.size();
        if( k == n ) return accumulate(points.begin() , points.end(), 0);
        int score = 0;
        int maxScore = 0;
        int l , r;
        for(int i = 0 ; i< k ; i++)
        {
            score += points[i];
        }
        maxScore = score;
        l = 0;
        r = k-1;

        while(l != n-k)
        {
            score -= points[r];
            l = (l-1 + n) %n;
            r = (r-1 + n) % n;
            score += points[l];
            maxScore = max(maxScore , score);
            cout<<"l "<<l<<" r "<<r <<" score "<<score<<" maxSCore "<<maxScore<<endl;
        }

        return maxScore;
    }
};