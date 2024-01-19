class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;

        getComb(candidates, target,0, ans, ds);

        return ans;
    }

    void getComb(vector<int>& candidates, int target,int ind, vector<vector<int>> &ans,vector<int> &ds){

        //base Condidation 
        if(ind == candidates.size() || target == 0){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }

        // pick the element
        if(candidates[ind] <= target ){
            ds.push_back(candidates[ind]);
            //take the index as it is and reduce the target value by candidates[ind] val
            getComb(candidates, target - candidates[ind], ind, ans, ds);

            ds.pop_back();
        }

        // not pick
        getComb(candidates, target, ind+1, ans, ds );

    }
};

