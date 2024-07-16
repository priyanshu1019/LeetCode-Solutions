class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        if( n == k) return accumulate(cardPoints.begin() , cardPoints.end(),0);

        int score = 0;
        int maxScore = INT_MIN;
        for(int i =0 ; i < k ; i++){
            score+= cardPoints[i];
        }
        maxScore = score;
        int l = 0 , r = k-1;

        while( l != n-k){
            score -= cardPoints[r];
            l  = (l-1+n)%n;
            r  = (r-1+n)%n;
            score += cardPoints[l];
            maxScore = max(score,maxScore);
        }

        return maxScore;
    }
};