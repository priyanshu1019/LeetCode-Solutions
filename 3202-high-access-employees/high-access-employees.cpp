class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        
        vector<string> ans;
        map<string , vector<int>> mp;
        for( auto &access_time : access_times)
        {
            string name = access_time[0];
            string hour = access_time[1].substr(0,2);
            string min  = access_time[1].substr(2,2);
            int hourInt = stoi(hour);
            int minInt  = stoi(min);
            int totalMinute = hourInt* 60 + minInt;
            mp[name].push_back(totalMinute);

        }

        for( auto &it: mp)
        {
            if( it.second.size() < 3)
                continue;
            sort(it.second.begin() , it.second.end());
            for( int i = 0 ; i < it.second.size()-2 ; i++ )
            {
                if( abs(it.second[i] - it.second[i+1]) <60 and abs(it.second[i]  - it.second[i+2]) < 60 )
                {
                    ans.push_back(it.first);
                    break;
                }
            }
        }

        return ans;
    }
};