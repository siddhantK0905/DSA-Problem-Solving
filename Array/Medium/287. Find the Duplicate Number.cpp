class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        //Floyd's Tortoise and Hare (Cycle Detection) algorithm.
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);

        slow = nums[0];
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return fast;


        // TC - O(N)
        //SC - O(1)
    }
};