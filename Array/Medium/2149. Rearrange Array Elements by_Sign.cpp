class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg;
        vector<int> ans;
        for(int i=0; i< nums.size(); i++)
        {
            if(nums[i] > 0) 
            {
                pos.emplace_back(nums[i]);
            }
            else
            {
                 neg.emplace_back(nums[i]);
            }
        }

        for(int i=0; i< nums.size()/2; i++)
        {
            ans.emplace_back(pos[i]);
            ans.emplace_back(neg[i]);
        }

        return ans;

        //Time Complexity - O(N)
        //Space Complexity - O(N)

    }
};