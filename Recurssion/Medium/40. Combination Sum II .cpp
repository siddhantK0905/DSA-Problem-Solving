class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>ds;
        int sum;
        set<vector<int>> uniqueCombinations;

        sort(candidates.begin(), candidates.end());

        getComb(candidates, target, 0, uniqueCombinations, ds );

        return vector<vector<int>>(uniqueCombinations.begin(), uniqueCombinations.end());
        
    }

    void getComb(vector<int>& candidates, int target, int index, set<vector<int>> & uniqueCombinations, vector<int> & ds){
        
        if(index == candidates.size() || target == 0){
            if(target == 0){
                uniqueCombinations.insert(ds);
            }
            return;
        }


        if(target >= candidates[index]){
            ds.push_back(candidates[index]);
            getComb(candidates, target-candidates[index], index+1,uniqueCombinations, ds);
            ds.pop_back();
        }
        
        int nextDistinctIndex = index + 1;
        while (nextDistinctIndex < candidates.size() && candidates[nextDistinctIndex] == candidates[index]) {
            nextDistinctIndex++;
        }
        getComb(candidates, target, nextDistinctIndex, uniqueCombinations, ds);
    }
};
