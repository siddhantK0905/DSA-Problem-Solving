#include<map>
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& v) {
        vector<vector<int>> ans;
        unordered_map<int, int> mp;
        for(auto it: v){
            mp[it]++;
        }
        int count = v.size();

        while(count != 0){
            vector<int> temp;
            for(auto it:mp){
                if(it.second > 0){
                    temp.push_back(it.first);
                    mp[it.first]--;
                    count--;
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};

//TC - O(N^2)
//SC - O(N)
