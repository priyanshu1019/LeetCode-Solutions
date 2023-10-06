class Solution {
public:
    int integerBreak(int n) {
        if(n<=3){
            return n-1;
        }

        int count_of_threes=n/3; //to get how many max possible three we can get
        int remainder=n%3;   //remainder can be 0 1 2 
        if(remainder==0){
            return pow(3,count_of_threes);
        }
        else if(remainder==1){
            return pow(3,count_of_threes-1)*4;
        }else if(remainder==2){
            return pow(3,count_of_threes)*2;
        }
        return -1;
    }
};