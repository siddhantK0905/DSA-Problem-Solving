class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mapp;
        for(int i=0; i<nums.size(); i++){
            mapp[nums[i]]++;
        }

        for(auto it:mapp){
            if(it.second > nums.size()/2){
                return it.first;
            }
        }

        return -1;
    }
};
