class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        //TC - logN() SC - log N
        std::unordered_map<int, int> store;
        for(int i =0; i< nums.size(); i++)
        {
            if(store.find(target - nums[i]) != store.end())
            {

                return vector<int> {store[target - nums[i]], i};
            }
            else
            {
                store[nums[i]] = i;
            }
        }

    //TC - log(n2)   SC- log(1) 
    //    for(int i =0 ; i < nums.size(); i++)
    //    {
    //     for(int j=i+1; j< nums.size(); j++ )
    //     {
    //         auto sum = nums[i] + nums[j];
    //         if(sum == target )
    //         return vector<int> {i, j};
    //     }
    //    }   
       return vector<int>{};
    }
};
