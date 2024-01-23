class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> freq (nums.size(), 0);
        vector<int> ds;

        getPermute(nums, ans, freq, ds);

        return ans;
    }

    void getPermute(vector<int>& nums, vector<vector<int>>& ans, vector<int>& freq, vector<int>& ds ){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }

        for(int i=0; i< nums.size(); i++){
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i] = 1;
                getPermute(nums, ans, freq, ds);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
};


// TC - O (N! * N)
// SC- O(N)
