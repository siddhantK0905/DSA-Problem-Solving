class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {


        // TC - O(N)  SC - O(N)
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++)
        {
            if(mp.find(nums[i]) != mp.end())
            {
                int index = mp[nums[i]];
                if((i - index ) <= k) return true;
            }
            mp[nums[i]] = i;
        }

       // TC - O(n2)  SC - O(1)
        // for(int j =0; j<nums.size()-1; j++)
        // {
        //     int i = j+1;
        //     while((i-j) <= k && i<nums.size())
        //     {
        //         if(nums[i] == nums[j]) return true;
        //         i++;
        //     }
        // }

        return false;
    }
};
