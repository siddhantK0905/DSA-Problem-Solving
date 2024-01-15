class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {

        map<int,int>mp;
        set<int>s;
        vector<vector<int>>ans(2);

          for(int i=0; i<matches.size(); i++)
        {
            s.insert(matches[i][1]);
            s.insert(matches[i][0]);
        }
        
        for(auto it:s){
            mp[it] == 0;
        }

        for(int i=0; i< matches.size(); i++){
            mp[matches[i][1]]++;
        }

         for(auto it:mp)
         {
             if(it.second==0)
             {
                 ans[0].push_back(it.first);
             }
              if(it.second==1)
             {
                 ans[1].push_back(it.first);
             }
         }

        return ans;


    }
};

