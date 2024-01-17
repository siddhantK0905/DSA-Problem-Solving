class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        set<int>st;
        for(int i=0; i<arr.size(); i++){
            mp[arr[i]]++;
        }

        for(auto it: mp){
            st.insert(it.second);
        }

        if(st.size() == mp.size()) return true;

        return false;
    }
};
//TC- O(N)
//SC -O(N)
