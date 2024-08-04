class Solution {
private:
    int getTotalTime(vector<int> &piles , int h , int mid)
    {
        int total = 0;
        for(int i = 0 ; i < piles.size() ; i++)
        {
            total += ceil((double)piles[i]/mid); //time for this pile 
            //check if the total time has already crossed the limited time or not 
            if( total > h)
            {
                //-3 indicates the above case
                return -3;
            }
        }
        return total;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxi = -1e9;
        for(int i = 0 ; i < n ; i++)
        {
            maxi = max(maxi , piles[i]);
        }
        //minimum number of bananas that koko can eat in 1 hour
        int low = 1;
        //maximum number of bananas that koko can eat in 1 hour
        int high= maxi;
        while(low <= high)
        {
            int mid = low +(high - low)/2;
            int totalTime = getTotalTime(piles , h , mid);
            if( totalTime == -3)
            {
                //we have to increase the number of bananas to eat per hour
                low = mid + 1;
            }else{
                //it can be the answer but we check for the better answer;
                high= mid -1;
            }
        }
        return low;

    }
};