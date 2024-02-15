class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int size = nums.size();
        long long perimeter =0, sum = 0;
        
        sort(nums.begin(), nums.end());

        for(int i =0; i<size; i++){
            if(nums[i]  < sum)
                perimeter = sum + nums[i];
            
            sum += nums[i];
        }

        return perimeter == 0 ? -1: perimeter;
    }
};

//TC - O(NlogN)
//SC - O(1)
