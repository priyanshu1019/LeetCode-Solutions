class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        int n = bank.size();
        int prev  = 0;
        int total = 0;
        for(int i = 0 ; i < n ; i++ ){

            int curr = 0;
            for(int j = 0 ; j < bank[i].size() ; j++){

                if( bank[i][j] == '1' ){
                    curr++;
                }

            }
            cout<< curr<<endl;
            if(i!= 0 and curr != 0 ){

                total += prev * curr; 

            }
            if( curr != 0)
                prev = curr;



        }

        return total;

    }
};