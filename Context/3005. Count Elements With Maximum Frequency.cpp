class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        int maxi =0;
        for(auto it:mp){
            if(it.second > maxi) maxi = it.second;
        }
        int ans = maxi, flag =0;
        for(auto it:mp){
            if(it.second == maxi ) {
                ans+=maxi;
                flag =1;
            }
        }
        
         if(flag == 1) return ans-maxi;
        return maxi;
    }
};

//TC- O(N)
//SC -O(N)
