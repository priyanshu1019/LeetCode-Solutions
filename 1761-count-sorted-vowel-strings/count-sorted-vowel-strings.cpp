class Solution {
private:
    int helper(int ind,int n,int vowelInd){
        if(vowelInd==4){
            return 1;
        }
        if(ind==n){
            return 1;
        }
        //let us pick the vowel
        int pick=helper(ind+1,n,vowelInd);
        //not pick
        int notpick=helper(ind,n,vowelInd+1);

        return pick+notpick;
    }
public:
    int countVowelStrings(int n) {
        return helper(0,n,0);
    }
};