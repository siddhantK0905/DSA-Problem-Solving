class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;

        for(auto it : arr){
            mp[it]++;
        }

        vector<int> temp;
        for(auto it:mp){
            temp.push_back(it.second);
        }

        sort(temp.begin(), temp.end());

        for(int i=0; i<temp.size(); i++){
            if(k > 0){
                k = k - temp[i];
                temp[i] = 0;
            }
            
        }
        int cnt = 0;
        if(k < 0){
            cnt++;
        }

        for(int i = 0; i<temp.size(); i++){
            if(temp[i] != 0) {
                cnt ++;
            }
        }

        return cnt;
        
    }
};

//TC -O(N log N)
//SC - O(N)
