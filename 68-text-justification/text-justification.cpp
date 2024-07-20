class Solution {
public:
    int MAX_WIDTH;
    string findLine(int i , int j , int eachGaddhaSpace  , int extraGaddhaSpace  , vector<string>&words ){
        string line ;
        for(int k = i ; k <j ; k++){
            line += words[k];
            if( k == j -1 ) continue;
            for(int j =1 ; j <= eachGaddhaSpace ; j++){
                line += " ";
            }
            if( extraGaddhaSpace > 0){
                line += " ";
                extraGaddhaSpace--;
            }
        }
        
        while( line.size() < MAX_WIDTH ){
            //last line wala case
            line += " ";
        }
        return line;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        MAX_WIDTH = maxWidth;
        int n     = words.size();
        vector<string> result;
        int i     = 0;

        while( i < n ){
            int letterCount = words[i].size();
            int gaddhe      = 0;
            int j           = i+1;

            while( j < n and letterCount + 1 + gaddhe + words[j].size() <= MAX_WIDTH ){
                letterCount += words[j].size();
                gaddhe++;
                j++;
            } 

            int remainingGaddhe = MAX_WIDTH - letterCount;
            int eachGaddhaSpace = gaddhe == 0? 0 :remainingGaddhe / gaddhe;
            int extraGaddhaSpace= gaddhe == 0? 0 :remainingGaddhe % gaddhe;
            if( j == n ){
                //last line
                eachGaddhaSpace = 1;
                extraGaddhaSpace = 0;
            }
            result.push_back(findLine(i , j ,eachGaddhaSpace , extraGaddhaSpace , words));
            i = j;
        }

        return result;
    }
};