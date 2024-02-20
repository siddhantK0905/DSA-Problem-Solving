class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size();
        int expectedSum = (n *(n+1))/2 , actualSum = 0;
        for(int i=0; i<nums.size(); i++){
            actualSum += nums[i];
        }

        return expectedSum - actualSum;

    }
};

//TC - O(N)
//SC - O(1)
